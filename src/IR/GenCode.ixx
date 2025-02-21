module;
#include <any>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <ranges>
#include <vector>
export module IR.GenCode;
export import IR.GenContext;
import Semantics.SemNode;
import Support.Unit;
namespace Riddle {
    template<typename T, typename SrcT = GenObject>
    T *unpacking(std::any value) {
        return dynamic_cast<T *>(std::any_cast<SrcT *>(value));
    }
}// namespace Riddle
export namespace Riddle {
    class GenCode final : public SemNodeVisitor {
        auto parserType(TypeNode *node) {
            return std::any_cast<llvm::Type *>(visitType(node));
        }

    protected:
        GenContext &context;
        const Unit &unit;

    public:
        explicit GenCode(GenContext &context, const Unit &unit): context(context), unit(unit) {}
        std::any visitProgram(ProgramNode *node) override {
            context.llvmModule->setModuleIdentifier(unit.getPackName());
            context.push();
            for(const auto i: *node->body) {
                visit(i);
            }
            context.pop();
            context.llvmModule->print(llvm::outs(), nullptr);
            return {};
        }

        std::any visitBoolean(BoolLiteralNode *node) override {
            llvm::Value *value = context.builder.getInt1(node->value);
            return value;
        }

        std::any visitInteger(IntegerLiteralNode *node) override {
            llvm::Value *value = context.builder.getInt32(node->value);
            return value;
        }

        std::any visitFloat(FloatLiteralNode *node) override {
            llvm::Value *value = llvm::ConstantFP::get(llvm::Type::getDoubleTy(context.llvmModule->getContext()), node->value);
            return value;
        }

        std::any visitString(StringLiteralNode *node) override {
            llvm::Value *value = context.builder.CreateGlobalStringPtr(node->value);
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
            if(node->returnType->llvmType == nullptr) {
                node->returnType->llvmType = std::any_cast<llvm::Type *>(visit(node->returnType));
            }
            const auto returnType = node->returnType->llvmType;

            // 处理函数参数
            std::vector<llvm::Type *> paramTypes;
            for(const auto i: node->args) {
                paramTypes.push_back(parserType(i->type));
            }

            const auto funcType = llvm::FunctionType::get(returnType, paramTypes, false);
            const auto func = llvm::Function::Create(funcType, llvm::GlobalValue::ExternalLinkage, name, context.llvmModule.get());

            // 处理函数参数命名
            int index = 0;
            for(auto it = func->arg_begin(); it != func->arg_end(); ++it, ++index) {
                it->setName(node->args.at(index)->name);
            }

            const auto obj = new GenFunction(node, func);
            if(node->theClass) {
                obj->is_weak = true;
            }
            context.addObject(obj);

            const auto entry = llvm::BasicBlock::Create(context.llvmModule->getContext(), "entry", func);
            context.builder.SetInsertPoint(entry);

            context.push();
            context.pushFunc(obj);

            auto args = func->arg_begin();
            for(const auto & arg : node->args) {
                arg->alloca->alloca = args;
                args++;
                visit(arg);
            }

            for(const auto i: *node->body) {
                visit(i);
            }

            context.pop();
            context.popFunc();

            if(verifyFunction(*func, &llvm::errs())) {
                func->eraseFromParent();

                return {};
            }

            GenObject *result = obj;
            return result;
        }

        std::any visitObject(ObjectNode *node) override {
            const auto name = node->name;
            const auto obj = context.getObject(name);
            if(obj->getGenType() != GenObject::Variable) {
                throw std::runtime_error("Object is not a variable");
            }
            const auto type = parserType(node->getType());
            const auto var = dynamic_cast<GenVariable *>(obj);
            llvm::Value *result = var->alloca;
            if(node->isLoad) {
                const auto load = context.builder.CreateLoad(type, result);
                result = load;
            }
            return result;
        }

        std::any visitAlloca(AllocaNode *node) override {
            llvm::Value *alloca = context.builder.CreateAlloca(parserType(node->type));
            node->alloca = alloca;
            return {};
        }

        std::any visitVarDefine(VarDefineNode *node) override {
            const auto name = node->name;
            // 已经预先分配空间
            const auto obj = new GenVariable(node);
            context.addObject(obj);
            if(node->value) {
                if(!node->alloca) {
                    throw std::runtime_error("Variable does not have alloca");
                }
                const auto value = std::any_cast<llvm::Value *>(visit(node->value));
                context.builder.CreateStore(value, node->alloca->alloca);
            }
            return {};
        }

        std::any visitType(TypeNode *node) override {
            if(node->llvmType) {
                return node->llvmType;
            }
            const auto &name = node->name;
            static std::unordered_map<std::string, llvm::Type *> base_types = {
                    {"bool", llvm::Type::getInt1Ty(*context.llvmContext)},
                    {"int", llvm::Type::getInt32Ty(*context.llvmContext)},
                    {"float", llvm::Type::getDoubleTy(*context.llvmContext)},
                    {"double", llvm::Type::getDoubleTy(*context.llvmContext)},
                    {"void", llvm::Type::getVoidTy(*context.llvmContext)},
                    {"char*", llvm::Type::getInt8Ty(*context.llvmContext)->getPointerTo()}};
            // 尝试获取基本类型
            if(base_types.contains(name)) {
                return base_types[name];
            }
            const auto obj = context.getObject(name);
            if(obj->getGenType() != GenObject::Class) {
                throw std::runtime_error("Object doesn't have a class");
            }
            const auto typ = dynamic_cast<GenClass *>(obj);
            node->llvmType = typ->getLLVMType();
            return typ->getLLVMType();
        }

        std::any visitIf(IfNode *node) override {
            // 生成 Basic Block
            llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(*context.llvmContext, "if.then", context.getNowFunc()->llvmFunction);
            llvm::BasicBlock *elseBlock = nullptr;
            if(node->else_body) {
                elseBlock = llvm::BasicBlock::Create(*context.llvmContext, "if.else", context.getNowFunc()->llvmFunction);
            }
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(*context.llvmContext, "if.exit", context.getNowFunc()->llvmFunction);

            const auto condition = std::any_cast<llvm::Value *>(visit(node->condition));
            if(node->else_body) {
                context.builder.CreateCondBr(condition, thenBlock, elseBlock);
            } else {
                context.builder.CreateCondBr(condition, thenBlock, exitBlock);
            }

            // then块的语句执行
            context.builder.SetInsertPoint(thenBlock);
            context.push();
            visit(node->then_body);
            context.builder.CreateBr(exitBlock);
            context.pop();

            if(node->else_body) {
                context.builder.SetInsertPoint(elseBlock);
                context.push();
                visit(node->else_body);
                context.builder.CreateBr(exitBlock);
                context.pop();
            }

            context.builder.SetInsertPoint(exitBlock);

            return {};
        }

        std::any visitWhile(WhileNode *node) override {
            llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(*context.llvmContext, "while.cond", context.getNowFunc()->llvmFunction);
            llvm::BasicBlock *bodyBlock = llvm::BasicBlock::Create(*context.llvmContext, "while.body", context.getNowFunc()->llvmFunction);
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(*context.llvmContext, "while.exit", context.getNowFunc()->llvmFunction);

            context.builder.CreateBr(condBlock);
            context.builder.SetInsertPoint(condBlock);

            const auto cond = std::any_cast<llvm::Value *>(visit(node->condition));
            context.builder.CreateCondBr(cond, bodyBlock, exitBlock);

            context.push();
            context.builder.SetInsertPoint(bodyBlock);
            visit(node->body);
            context.builder.CreateBr(condBlock);
            context.pop();

            context.builder.SetInsertPoint(exitBlock);
            return {};
        }

        std::any visitFor(ForNode *node) override {
            llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(*context.llvmContext, "for.cond", context.getNowFunc()->llvmFunction);
            llvm::BasicBlock *bodyBlock = llvm::BasicBlock::Create(*context.llvmContext, "for.body", context.getNowFunc()->llvmFunction);
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(*context.llvmContext, "for.exit", context.getNowFunc()->llvmFunction);

            context.push();
            // 预先 init
            visit(node->init);
            context.builder.CreateBr(condBlock);

            context.builder.SetInsertPoint(condBlock);
            const auto cond = std::any_cast<llvm::Value *>(visit(node->condition));
            context.builder.CreateCondBr(cond, bodyBlock, exitBlock);

            context.builder.SetInsertPoint(bodyBlock);
            visit(node->body);
            visit(node->increment);
            context.builder.CreateBr(condBlock);

            context.pop();
            return {};
        }

        std::any visitFuncCall(FuncCallNode *node) override {
            const auto name = node->name;
            const auto obj = context.getObject(name);
            if(obj->getGenType() != GenObject::Function) {
                throw std::runtime_error("Object doesn't have a function");
            }
            const auto func = dynamic_cast<GenFunction *>(obj);
            std::vector<llvm::Value *> argValues;
            argValues.reserve(node->args.size());
            for(const auto arg: node->args) {
                auto result = std::any_cast<llvm::Value *>(visit(arg));
                argValues.push_back(result);
            }
            llvm::Value *result = context.builder.CreateCall(func->llvmFunction, argValues);
            return result;
        }

        std::any visitClassDefine(ClassDefineNode *node) override {
            const auto name = node->name;
            const auto obj = new GenClass(node);
            obj->type = llvm::StructType::get(*context.llvmContext, false);
            obj->type->setName(node->name);
            context.addObject(obj);
            // 获取memberType
            std::vector<llvm::Type *> memberTypes;
            for(const auto i: node->members) {
                memberTypes.push_back(parserType(i->type));
            }
            obj->type->setBody(memberTypes);
            context.push();
            for(const auto i: node->functions | std::views::values) {
                const auto func = unpacking<GenFunction>(visit(i));
                obj->addFunc(func);
            }
            context.pop();
            return {};
        }

        std::any visitReturn(ReturnNode *node) override {
            if(node->value) {
                const auto result = std::any_cast<llvm::Value*>(visit(node->value));
                context.builder.CreateRet(result);
            }
            else {
                context.builder.CreateRetVoid();
            }
            return {};
        }
    };
}// namespace Riddle