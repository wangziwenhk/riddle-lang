module;
#include <any>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <ranges>
#include <vector>
export module Gen.GenCode;
export import Gen.GenContext;
import Semantics.SemNode;
import Support.Unit;
namespace Riddle {
    template<typename T, typename SrcT = GenObject>
    T *unpacking(std::any value) {
        return dynamic_cast<T *>(std::any_cast<SrcT *>(value));
    }
} // namespace Riddle
export namespace Riddle {
    class GenCode final : public SemNodeVisitor {
        auto parserType(TypeNode *node) {
            return std::any_cast<llvm::Type *>(visitType(node));
        }

    protected:
        GenContext &context;
        Unit &unit;

    public:
        explicit GenCode(GenContext &context, Unit &unit): context(context), unit(unit) {
        }

        std::any visitProgram(ProgramNode *node) override {
            context.llvmModule->setModuleIdentifier(unit.getPackName());
            for (auto i: context.getAllObjects() | std::views::values) {
                if (i.top()->getGenType() == GenObject::Module) {
                    const auto module = dynamic_cast<GenModule *>(i.top());
                    for (const auto j: module->getAllObjects() | std::views::values) {
                        if (j->getGenType() == GenObject::Class) {
                            const auto theClass = dynamic_cast<GenClass *>(j);
                            visit(theClass->define);
                        }
                        else if (j->getGenType() == GenObject::Function) {
                            const auto theFunction = dynamic_cast<GenFunction *>(j);
                            visit(theFunction->define);
                        }
                    }
                }
            }
            for (const auto i: *node->body) {
                visit(i);
            }
            context.llvmModule->print(llvm::outs(), nullptr);
            return {};
        }

        std::any visitBoolean(BoolLiteralNode *node) override {
            llvm::Value *value = context.builder->getInt1(node->value);
            return value;
        }

        std::any visitInteger(IntegerLiteralNode *node) override {
            llvm::Value *value = context.builder->getInt32(node->value);
            return value;
        }

        std::any visitFloat(FloatLiteralNode *node) override {
            llvm::Value *value =
                    llvm::ConstantFP::get(llvm::Type::getDoubleTy(context.llvmModule->getContext()), node->value);
            return value;
        }

        std::any visitString(StringLiteralNode *node) override {
            llvm::Value *value = context.builder->CreateGlobalString(node->value);
            return value;
        }

        std::any visitArg(ArgNode *node) override {
            const auto obj = new GenVariable(node);
            context.addObject(obj);
            obj->type->llvmType = parserType(obj->type);
            return {};
        }

        std::any visitFuncDefine(FuncDefineNode *node) override {
            const auto name = node->name;
            if (node->returnType->llvmType == nullptr) {
                node->returnType->llvmType = std::any_cast<llvm::Type *>(visit(node->returnType));
            }
            const auto returnType = node->returnType->llvmType;

            // 处理函数参数
            std::vector<llvm::Type *> paramTypes;
            paramTypes.reserve(node->args.size());
            for (const auto i: node->args) {
                paramTypes.push_back(parserType(i->type));
            }
            if (node->theClass) {
                paramTypes.front() = llvm::PointerType::get(paramTypes.front(), 0);
            }

            const auto funcType = llvm::FunctionType::get(returnType, paramTypes, false);
            const auto func =
                    llvm::Function::Create(funcType, llvm::GlobalValue::ExternalLinkage, name, context.llvmModule);

            node->llvmFunction = func;

            // 处理函数参数命名
            int index = 0;
            for (auto it = func->arg_begin(); it != func->arg_end(); ++it, ++index) {
                it->setName(node->args.at(index)->name);
            }

            const auto obj = new GenFunction(node);
            context.addObject(obj);
            if (node->theClass) {
                obj->is_weak = true;
            }

            if (node->body) {
                const auto entry = llvm::BasicBlock::Create(context.llvmModule->getContext(), "entry", func);
                context.builder->SetInsertPoint(entry);

                context.push();
                context.pushFunc(obj);

                auto args = func->arg_begin();
                for (const auto &arg: node->args) {
                    arg->alloca->alloca = args;
                    args++;
                    visit(arg);
                }

                for (const auto i: *node->body) {
                    visit(i);
                }

                context.pop();
                context.popFunc();

                if (verifyFunction(*func, &llvm::errs())) {
                    // func->eraseFromParent();
                    return {};
                }
            }

            GenObject *result = obj;
            return result;
        }

        std::any visitObject(ObjectNode *node) override {
            const auto name = node->getName();
            const auto obj = context.getObject(name);
            if (obj->getGenType() != GenObject::Variable) {
                throw std::runtime_error("Object is not a variable");
            }
            const auto type = parserType(node->getType());
            const auto var = dynamic_cast<GenVariable *>(obj);
            llvm::Value *result = var->alloca->alloca;
            if (node->isLoad) {
                result = context.builder->CreateLoad(type, result);
            }
            return result;
        }

        std::any visitAlloca(AllocaNode *node) override {
            auto type = parserType(node->type);
            llvm::Value *alloca = context.builder->CreateAlloca(type);
            node->alloca = alloca;
            return {};
        }

        std::any visitVarDefine(VarDefineNode *node) override {
            const auto name = node->name;
            // 已经预先分配空间
            const auto obj = new GenVariable(node);
            context.addObject(obj);
            if (node->isGlobal) {
                const auto value = std::any_cast<llvm::Value *>(visit(node->value));
                const auto cst = llvm::dyn_cast<llvm::Constant>(value);
                const auto var = new llvm::GlobalVariable(*context.llvmModule, parserType(node->type), false,
                                                          llvm::GlobalValue::ExternalLinkage, cst, name);
                node->alloca->alloca = var;
                return {};
            }
            if (node->value) {
                if (!node->alloca) {
                    throw std::runtime_error("Variable does not have alloca");
                }
                auto value = std::any_cast<llvm::Value *>(visit(node->value));
                value = context.builder->CreateTrunc(value, parserType(node->type));
                context.builder->CreateStore(value, node->alloca->alloca);
            }
            return {};
        }

        std::any visitType(TypeNode *node) override {
            if (node->llvmType) {
                return node->llvmType;
            }
            const auto &name = node->name;
            static std::unordered_map<std::string, llvm::Type *> base_types = {
                {"bool", llvm::Type::getInt1Ty(*context.llvmContext)},
                {"int", llvm::Type::getInt32Ty(*context.llvmContext)},
                {"long", llvm::Type::getInt64Ty(*context.llvmContext)},
                {"short", llvm::Type::getInt16Ty(*context.llvmContext)},
                {"char", llvm::Type::getInt8Ty(*context.llvmContext)},
                {"float", llvm::Type::getDoubleTy(*context.llvmContext)},
                {"double", llvm::Type::getDoubleTy(*context.llvmContext)},
                {"void", llvm::Type::getVoidTy(*context.llvmContext)},
                {"char*", llvm::PointerType::get(llvm::Type::getInt8Ty(*context.llvmContext), 0)},
            };
            // 尝试获取基本类型
            if (base_types.contains(name)) {
                return base_types[name];
            }
            const auto obj = context.getObject(name);
            if (obj->getGenType() != GenObject::Class) {
                throw std::runtime_error("Object doesn't have a class");
            }
            const auto typ = dynamic_cast<GenClass *>(obj);
            node->llvmType = typ->getLLVMType();
            return typ->getLLVMType();
        }

        std::any visitIf(IfNode *node) override {
            // 生成 Basic Block
            llvm::BasicBlock *thenBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "if.then", context.getNowFunc()->getLLVMFunction());
            llvm::BasicBlock *elseBlock = nullptr;
            if (node->else_body) {
                elseBlock =
                        llvm::BasicBlock::Create(*context.llvmContext, "if.else",
                                                 context.getNowFunc()->getLLVMFunction());
            }
            llvm::BasicBlock *exitBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "if.exit", context.getNowFunc()->getLLVMFunction());

            const auto condition = std::any_cast<llvm::Value *>(visit(node->condition));
            if (node->else_body) {
                context.builder->CreateCondBr(condition, thenBlock, elseBlock);
            } else {
                context.builder->CreateCondBr(condition, thenBlock, exitBlock);
            }

            // then块的语句执行
            context.builder->SetInsertPoint(thenBlock);
            context.push();
            visit(node->then_body);
            context.builder->CreateBr(exitBlock);
            context.pop();

            if (node->else_body) {
                context.builder->SetInsertPoint(elseBlock);
                context.push();
                visit(node->else_body);
                context.builder->CreateBr(exitBlock);
                context.pop();
            }

            context.builder->SetInsertPoint(exitBlock);

            return {};
        }

        std::any visitWhile(WhileNode *node) override {
            llvm::BasicBlock *condBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "while.cond",
                                             context.getNowFunc()->getLLVMFunction());
            llvm::BasicBlock *bodyBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "while.body",
                                             context.getNowFunc()->getLLVMFunction());
            llvm::BasicBlock *exitBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "while.exit",
                                             context.getNowFunc()->getLLVMFunction());

            context.builder->CreateBr(condBlock);
            context.builder->SetInsertPoint(condBlock);

            const auto cond = std::any_cast<llvm::Value *>(visit(node->condition));
            context.builder->CreateCondBr(cond, bodyBlock, exitBlock);

            context.push();
            context.builder->SetInsertPoint(bodyBlock);
            visit(node->body);
            context.builder->CreateBr(condBlock);
            context.pop();

            context.builder->SetInsertPoint(exitBlock);
            return {};
        }

        std::any visitFor(ForNode *node) override {
            llvm::BasicBlock *condBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "for.cond", context.getNowFunc()->getLLVMFunction());
            llvm::BasicBlock *bodyBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "for.body", context.getNowFunc()->getLLVMFunction());
            llvm::BasicBlock *exitBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "for.exit", context.getNowFunc()->getLLVMFunction());

            context.push();
            // 预先 init
            visit(node->init);
            context.builder->CreateBr(condBlock);

            context.builder->SetInsertPoint(condBlock);
            const auto cond = std::any_cast<llvm::Value *>(visit(node->condition));
            context.builder->CreateCondBr(cond, bodyBlock, exitBlock);

            context.builder->SetInsertPoint(bodyBlock);
            visit(node->body);
            visit(node->increment);
            context.builder->CreateBr(condBlock);

            context.pop();
            return {};
        }

        std::any visitFuncCall(FuncCallNode *node) override {
            const auto name = node->getName();
            GenObject *obj = nullptr;
            if (!node->g_obj) {
                obj = context.getObject(name);
            } else {
                obj = static_cast<GenObject *>(node->g_obj);
            }
            if (obj->getGenType() != GenObject::Function) {
                throw std::runtime_error("Object doesn't have a function");
            }
            const auto func = dynamic_cast<GenFunction *>(obj);
            std::vector<llvm::Value *> argValues;
            argValues.reserve(node->args.size());
            for (const auto arg: node->args) {
                auto it = visit(arg);
                if (!it.has_value()) {
                    throw std::runtime_error("Argument Error");
                }
                auto result = std::any_cast<llvm::Value *>(it);
                argValues.push_back(result);
            }
            llvm::Value *result = context.builder->CreateCall(func->getLLVMFunction(), argValues);
            return result;
        }

        std::any visitClassDefine(ClassDefineNode *node) override {
            const auto obj = new GenClass(node);
            context.addObject(obj);
            if (node->llvmType) {
                obj->type = llvm::dyn_cast<llvm::StructType>(node->llvmType);
                return {};
            }
            node->llvmType = obj->type = llvm::StructType::create(*context.llvmContext, {}, node->buildName, false);
            // 获取memberType
            std::vector<llvm::Type *> memberTypes;
            memberTypes.reserve(node->members.size());
            for (const auto i: node->members) {
                memberTypes.push_back(parserType(i->type));
            }
            // 保证对象地址存在
            if (memberTypes.empty()) {
                memberTypes.emplace_back(llvm::Type::getInt1Ty(*context.llvmContext));
            }
            obj->type->setBody(memberTypes);
            context.push();
            for (const auto i: node->functions) {
                const auto func = unpacking<GenFunction>(visit(i));
                obj->addFunc(func);
            }
            context.pop();
            return {};
        }

        std::any visitReturn(ReturnNode *node) override {
            if (node->value) {
                const auto result = std::any_cast<llvm::Value *>(visit(node->value));
                context.builder->CreateRet(result);
            } else {
                context.builder->CreateRetVoid();
            }
            return {};
        }


        std::any visitBlend(BlendNode *node) override {
            switch (node->blend_type) {
                case BlendNode::Member: {
                    const auto parent = std::any_cast<llvm::Value *>(visit(node->parent));
                    const auto theClass = dynamic_cast<GenClass *>(context.getObject(node->parent->getType()->name));
                    if (!theClass) {
                        throw std::runtime_error("Parent Not a class");
                    }

                    theClass->define->build();
                    const auto child = dynamic_cast<ObjectNode *>(node->child);
                    const auto [member, index] = theClass->define->getMember(child->getName());
                    llvm::Value *result;
                    const auto parentType = parserType(node->parent->getType());

                    if (parent->getType()->isPointerTy()) {
                        result = context.builder->CreateStructGEP(parentType, parent, index);
                    } else {
                        result = context.builder->CreateExtractValue(parent, index);
                    }

                    if (node->isLoad && result->getType()->isPointerTy()) {
                        result = context.builder->CreateLoad(parserType(member->type), result);
                    }

                    return result;
                }
                case BlendNode::Method: {
                    const auto theClass = dynamic_cast<GenClass *>(context.getObject(node->parent->getType()->name));
                    if (!theClass) {
                        throw std::runtime_error("Parent Not a class");
                    }

                    theClass->define->build();
                    const auto child = dynamic_cast<FuncCallNode *>(node->child);
                    child->args.insert(child->args.begin(), node->parent);
                    child->g_obj = theClass->getFunc(child->getName());
                    return visit(child);
                }
                case BlendNode::Module: {
                    const GenModule *theModule = nullptr;
                    if (node->parent->getSemType() == SemNode::BlendNodeType) {
                        visit(node->parent);
                        theModule = static_cast<GenModule *>(node->parent->g_obj);
                    } else {
                        theModule = dynamic_cast<GenModule *>(context.getObject(node->parent->getName()));
                    }
                    if (!theModule) {
                        throw std::runtime_error("Parent Not a class");
                    }

                    const auto obj = theModule->getObject(node->child->getName());

                    switch (obj->getGenType()) {
                        case GenObject::Variable: {
                            const auto var = dynamic_cast<GenVariable *>(obj);
                            node->getType()->llvmType = parserType(var->type);
                            llvm::Value *result = var->alloca->alloca;
                            result = context.builder->CreateLoad(node->getType()->llvmType, result);
                            return result;
                        }
                        case GenObject::Function: {
                            const auto func = dynamic_cast<GenFunction *>(obj);
                            node->getType()->llvmType = func->define->returnType->llvmType;
                            const auto child = dynamic_cast<FuncCallNode *>(node->child);
                            child->g_obj = theModule->getObject(child->getName());
                            return visit(node->child);
                        }
                        case GenObject::Module: {
                            const auto m = dynamic_cast<GenModule *>(obj);
                            node->g_obj = m;
                            return m;
                        }
                        default: {
                            break;
                        }
                    }
                }
                default:
                    break;
            }
            return {};
        }

        std::any visitBinaryOp(BinaryOpNode *node) override {
            const auto left = std::any_cast<llvm::Value *>(visit(node->left));
            const auto right = std::any_cast<llvm::Value *>(visit(node->right));
            const std::string leftT = node->left->getType()->name;
            const std::string rightT = node->right->getType()->name;
            const auto opFunc = context.getOperator(leftT, rightT, node->op);
            return opFunc(left, right, *context.builder);
        }
    };
} // namespace Riddle
