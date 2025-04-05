module;
#include <any>
#include <llvm/IR/IRBuilder.h>
export module Gen.NewGenCode;
import Semantics.SemNode;
import Gen.NewGenContext;
namespace Riddle {
    template<typename Tp>
    Tp node_cast(const std::any &value) {
        if (!value.has_value()) {
            throw std::runtime_error("Null Value");
        }
        try {
            return std::any_cast<Tp>(value);
        } catch (const std::bad_any_cast &e) {
            throw std::runtime_error("Bad Value: " + std::string(e.what()));
        }
    }

    template<typename Tp>
    Tp obj_cast(const std::any &value) {
        return dynamic_cast<Tp>(node_cast<NewGenObject *>(value));
    }
} // namespace Riddle
export namespace Riddle {
    /**
     * 一个通过解析 SemNode 来生成 LLVM IR 代码的类。该类不保存任何状态。
     */
    class NewGenCode final : public SemNodeVisitor {
    public:
        NewGenContext &context;
        llvm::IRBuilder<> &builder;

        explicit NewGenCode(NewGenContext &ctx): context(ctx), builder(ctx.builder) {
        }

        std::any visitProgram(ProgramNode *node) override {
            for (const auto i: *node->body) {
                visit(i);
            }
            return {};
        }

        std::any visitInteger(IntegerLiteralNode *node) override {
            NewGenObject *obj = NewGenInteger::create(context, node->value);
            return obj;
        }

        std::any visitType(TypeNode *node) override {
            llvm::Type *type = nullptr;

            bool isBaseType = false;
            if (node->isBaseType()) {
                type = context.getBaseType(node->name);
                isBaseType = true;
            }

            // todo 从作用域获取


            // if (type == nullptr) {
            //     throw std::runtime_error("Bad Type");
            // }

            // 处理指针
            for (size_t i = 0; i < node->pointSize; i++) {
                type = llvm::PointerType::get(type, 0);
            }

            NewGenObject *obj = nullptr;
            if (isBaseType) {
                obj = NewGenBaseType::create(context, type);
            } else {
                if (!type->isStructTy()) {
                    throw std::runtime_error("Invalid Type");
                }
                obj = NewGenClassType::create(context, llvm::dyn_cast<llvm::StructType>(type));
            }
            return obj;
        }

        /**
         * 解析 FuncCall 的参数类型
         * @param node node
         * @return None
         */
        std::any visitArg(ArgNode *node) override {
            return {};
        }

        std::any visitFuncDefine(FuncDefineNode *node) override {
            const auto return_type = obj_cast<NewGenType *>(visitType(node->returnType))->getLLVMType();
            // todo 实现函数参数

            constexpr auto link_type = llvm::Function::ExternalLinkage;

            const auto func_type = llvm::FunctionType::get(return_type, {}, false);
            const auto func = llvm::Function::Create(func_type, link_type, node->name, context.llvmModule.get());

            node->llvmFunction = func;

            // 解析 body
            if (!node->body) {
                return {};
            }

            const auto entry = llvm::BasicBlock::Create(*context.llvmContext, "entry", func);
            builder.SetInsertPoint(entry);

            context.push();
            for (const auto i: *node->body) {
                visit(i);
            }
            context.pop();

            return {};
        }

        std::any visitReturn(ReturnNode *node) override {
            if (node->value) {
                const auto result = obj_cast<NewGenInteger *>(visit(node->value));
                builder.CreateRet(result->getLLVMValue());
            } else {
                builder.CreateRetVoid();
            }
            return {};
        }

        std::any visitIf(IfNode *node) override {
            // 生成 Basic Block
            llvm::BasicBlock *thenBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "if.then", node->parentFunc->llvmFunction);
            llvm::BasicBlock *elseBlock = nullptr;
            if (node->else_body) {
                elseBlock = llvm::BasicBlock::Create(*context.llvmContext, "if.else", node->parentFunc->llvmFunction);
            }
            llvm::BasicBlock *exitBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "if.exit", node->parentFunc->llvmFunction);

            const auto condition = obj_cast<NewGenValue *>(visit(node->condition))->getLLVMValue();
            if (node->else_body) {
                builder.CreateCondBr(condition, thenBlock, elseBlock);
            } else {
                builder.CreateCondBr(condition, thenBlock, exitBlock);
            }

            // then块的语句执行
            builder.SetInsertPoint(thenBlock);
            context.push();
            visit(node->then_body);
            builder.CreateBr(exitBlock);
            context.pop();

            if (node->else_body) {
                builder.SetInsertPoint(elseBlock);
                context.push();
                visit(node->else_body);
                builder.CreateBr(exitBlock);
                context.pop();
            }

            builder.SetInsertPoint(exitBlock);

            return {};
        }

        std::any visitWhile(WhileNode *node) override {
            llvm::BasicBlock *condBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "while.cond", node->parentFunc->llvmFunction);
            llvm::BasicBlock *bodyBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "while.body", node->parentFunc->llvmFunction);
            llvm::BasicBlock *exitBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "while.exit", node->parentFunc->llvmFunction);

            node->condBlock = condBlock;
            node->exitBlock = exitBlock;

            builder.CreateBr(condBlock);
            builder.SetInsertPoint(condBlock);

            const auto cond = obj_cast<NewGenValue *>(visit(node->condition))->getLLVMValue();
            builder.CreateCondBr(cond, bodyBlock, exitBlock);

            context.push();
            builder.SetInsertPoint(bodyBlock);
            visit(node->body);
            builder.CreateBr(condBlock);
            context.pop();

            builder.SetInsertPoint(exitBlock);
            return {};
        }

        std::any visitFor(ForNode *node) override {
            llvm::BasicBlock *condBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "for.cond", node->parentFunc->llvmFunction);
            llvm::BasicBlock *bodyBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "for.body", node->parentFunc->llvmFunction);
            llvm::BasicBlock *exitBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "for.exit", node->parentFunc->llvmFunction);

            node->condBlock = condBlock;
            node->exitBlock = exitBlock;

            context.push();
            // 预先 init
            visit(node->init);
            builder.CreateBr(condBlock);

            builder.SetInsertPoint(condBlock);
            const auto cond = obj_cast<NewGenValue *>(visit(node->condition))->getLLVMValue();
            builder.CreateCondBr(cond, bodyBlock, exitBlock);

            builder.SetInsertPoint(bodyBlock);
            visit(node->body);
            visit(node->increment);
            builder.CreateBr(condBlock);

            context.pop();
            builder.SetInsertPoint(exitBlock);
            return {};
        }

        std::any visitBreak(BreakNode *node) override {
            builder.CreateBr(node->loopControl->exitBlock);
            return {};
        }

        std::any visitContinue(ContinueNode *node) override {
            builder.CreateBr(node->loopControl->condBlock);
            return {};
        }
    };
} // namespace Riddle
