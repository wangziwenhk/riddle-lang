module;
#include <any>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <vector>
export module IR.GenCode;
export import IR.GenContext;
import Semantics.SemNode;
import Types.Unit;
export namespace Riddle {
    class GenCode final : public SemNodeVisitor {
    protected:
        GenContext &context;
        const Unit &unit;

    public:
        explicit GenCode(GenContext &context, const Unit &unit): context(context), unit(unit) {}
        std::any visitProgram(ProgramNode *node) override {
            context.llvmModule->setModuleIdentifier(unit.getPackName());
            for(const auto i: *node->body) {
                visit(i);
            }
            context.llvmModule->print(llvm::outs(), nullptr);
            return {};
        }

        std::any visitInteger(IntegerLiteralNode *node) override {
            llvm::Value *value = context.builder.getInt32(node->value);
            return value;
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
                if(i->type->llvmType == nullptr) {
                    i->type->llvmType = std::any_cast<llvm::Type *>(visit(i->type));
                }
                paramTypes.push_back(i->type->llvmType);
            }

            const auto funcType = llvm::FunctionType::get(returnType, paramTypes, false);
            const auto func = llvm::Function::Create(funcType, llvm::GlobalValue::ExternalLinkage, name, context.llvmModule.get());

            // 处理函数参数命名
            int index = 0;
            for(auto it = func->arg_begin(); it != func->arg_end(); ++it, ++index) {
                it->setName(node->args.at(index)->name);
            }

            const auto entry = llvm::BasicBlock::Create(context.llvmModule->getContext(), "entry", func);
            context.builder.SetInsertPoint(entry);

            context.push();
            context.pushFunc(func);

            for(const auto i: *node->body) {
                visit(i);
            }

            context.pop();
            context.popFunc();

            verifyFunction(*func);

            return {};
        }

        std::any visitObject(ObjectNode *node) override {
            const auto name = node->name;
            const auto obj = context.getObject(name);
            if(obj->getGenType() != GenObject::Variable) {
                throw std::runtime_error("Object is not a variable");
            }
            const auto var = dynamic_cast<GenVariable *>(obj);
            // todo 添加是否 load 判断
            return var->define->alloca->alloca;
        }

        std::any visitAlloca(AllocaNode *node) override {
            node->type->llvmType = std::any_cast<llvm::Type *>(visitType(node->type));
            llvm::Value *alloca = context.builder.CreateAlloca(node->type->llvmType);
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
            const auto &name = node->name;
            static std::unordered_map<std::string, llvm::Type *> base_types = {
                    {"bool", llvm::Type::getInt1Ty(*context.llvmContext)},
                    {"int", llvm::Type::getInt32Ty(*context.llvmContext)},
                    {"float", llvm::Type::getDoubleTy(*context.llvmContext)},
                    {"double", llvm::Type::getDoubleTy(*context.llvmContext)},
                    {"void", llvm::Type::getVoidTy(*context.llvmContext)},
            };
            // 尝试获取基本类型
            if(base_types.contains(name)) {
                return base_types[name];
            }
            const auto obj = context.getObject(name);
            if(obj->getGenType() != GenObject::Class) {
                throw std::runtime_error("Object doesn't have a class");
            }
            const auto typ = dynamic_cast<GenClass *>(obj);
            return typ->getLLVMType();
        }

        std::any visitIf(IfNode *node) override {
            // 生成 Basic Block
            llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(*context.llvmContext, "if.then", context.getNowFunc());
            llvm::BasicBlock *elseBlock = nullptr;
            if(node->else_body) {
                elseBlock = llvm::BasicBlock::Create(*context.llvmContext, "if.else", context.getNowFunc());
            }
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(*context.llvmContext, "if.exit", context.getNowFunc());

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
            llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(*context.llvmContext, "while.cond");
            llvm::BasicBlock *bodyBlock = llvm::BasicBlock::Create(*context.llvmContext, "while.body");
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(*context.llvmContext, "while.exit");

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
    };
}// namespace Riddle