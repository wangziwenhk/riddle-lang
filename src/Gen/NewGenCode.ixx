module;
#include <any>
#include <llvm/IR/IRBuilder.h>
export module Gen.NewGenCode;
import Semantics.SemNode;
import Gen.NewGenContext;
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

        /**
         * 解析 FuncCall 的参数类型
         * @param node node
         * @return None
         */
        std::any visitArg(ArgNode *node) override {
            return {};
        }

        std::any visitFuncDefine(FuncDefineNode *node) override {
            std::string_view name = node->name;
            return {};
        }

        std::any visitReturn(ReturnNode *node) override {
            if (node->value) {
                const auto result = std::any_cast<llvm::Value *>(visit(node->value));
                builder.CreateRet(result);
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
                elseBlock = llvm::BasicBlock::Create(*context.llvmContext, "if.else",
                                                     node->parentFunc->llvmFunction);
            }
            llvm::BasicBlock *exitBlock =
                    llvm::BasicBlock::Create(*context.llvmContext, "if.exit", node->parentFunc->llvmFunction);

            const auto condition = std::any_cast<llvm::Value *>(visit(node->condition));
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
            llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(*context.llvmContext, "while.cond",
                                                                   node->parentFunc->llvmFunction);
            llvm::BasicBlock *bodyBlock = llvm::BasicBlock::Create(*context.llvmContext, "while.body",
                                                                   node->parentFunc->llvmFunction);
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(*context.llvmContext, "while.exit",
                                                                   node->parentFunc->llvmFunction);

            builder.CreateBr(condBlock);
            builder.SetInsertPoint(condBlock);

            const auto cond = std::any_cast<llvm::Value *>(visit(node->condition));
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

            context.push();
            // 预先 init
            visit(node->init);
            builder.CreateBr(condBlock);

            builder.SetInsertPoint(condBlock);
            const auto cond = std::any_cast<llvm::Value *>(visit(node->condition));
            builder.CreateCondBr(cond, bodyBlock, exitBlock);

            builder.SetInsertPoint(bodyBlock);
            visit(node->body);
            visit(node->increment);
            builder.CreateBr(condBlock);

            context.pop();
            builder.SetInsertPoint(exitBlock);
            return {};
        }
    };
} // namespace Riddle
