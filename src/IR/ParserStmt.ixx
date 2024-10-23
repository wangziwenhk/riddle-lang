module;
#include <any>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
export module IR.ParserStmt;
import Types.Statements;
import Manager.ClassManager;
import Manager.VarManager;
import IR.Context;
import IR.Builder;
export namespace Riddle {
    class ParserStmt {
        Builder builder;
        ClassManager classManager;

    public:
        explicit ParserStmt(Context &ctx): builder(ctx), classManager(ctx.llvm_context) {}

        // 获取从语句得到的结果
        std::any accept(BaseStmt *stmt) {// NOLINT(*-no-recursion)
            switch(stmt->getStmtTypeID()) {
                case BaseStmt::StmtTypeID::ProgramStmtID:
                    Program(dynamic_cast<ProgramStmt *>(stmt));
                    return nullptr;

                case BaseStmt::StmtTypeID::IntegerStmtID:
                    return Integer(dynamic_cast<IntegerStmt *>(stmt));

                case BaseStmt::StmtTypeID::DoubleStmtID:
                    return Double(dynamic_cast<DoubleStmt *>(stmt));

                case BaseStmt::StmtTypeID::ObjStmtID:
                    return Object(dynamic_cast<ObjectStmt *>(stmt));

                case BaseStmt::StmtTypeID::FuncDefineStmtID:
                    return FuncDefine(dynamic_cast<FuncDefineStmt *>(stmt));

                case BaseStmt::StmtTypeID::VarDefineStmtID:
                    return VarDefine(dynamic_cast<VarDefineStmt *>(stmt));

                case BaseStmt::StmtTypeID::ReturnStmtID:
                    return Return(dynamic_cast<ReturnStmt *>(stmt));

                case BaseStmt::StmtTypeID::BlockStmtID:
                    return Block(dynamic_cast<BlockStmt *>(stmt));

                case BaseStmt::StmtTypeID::WhileStmtID:
                    return While(dynamic_cast<WhileStmt *>(stmt));

                default:
                    return nullptr;// 未知的 StmtTypeID 类型，返回空值
            }
        }

        llvm::Value *Integer(const IntegerStmt *stmt) {
            llvm::Value *result = builder.getInt32(stmt->getValue());
            return result;
        }

        llvm::Value *Double(const DoubleStmt *stmt) const {
            llvm::Value *result = builder.getDouble(stmt->getValue());
            return result;
        }

        void Program(ProgramStmt *stmt) {// NOLINT(*-no-recursion)
            builder.push();
            for(const auto i: stmt->body) {
                accept(i);
            }
            builder.pop();
            builder.printCode();
        }

        llvm::Function *FuncDefine(const FuncDefineStmt *stmt) {// NOLINT(*-no-recursion)
            const std::string name = stmt->getFuncName();
            llvm::Type *returnType = classManager.getType(stmt->getReturnType());
            const auto args = stmt->getArgs();
            BaseStmt *body = stmt->getBody();
            std::vector<llvm::Type *> argTypes;
            if(stmt->getArgs() != nullptr) {
                argTypes = args->getArgsTypes(classManager);
            }
            auto [funcType, func] = builder.createFuncDefine(name, returnType, argTypes);
            llvm::BasicBlock *entry = builder.createBasicBlock("entry", func);
            builder.setNowBlock(entry);
            builder.push();
            builder.pushParent(func);
            accept(body);
            builder.pop();
            builder.popParent();
            return func;
        }

        llvm::Value *VarDefine(const VarDefineStmt *stmt) {// NOLINT(*-no-recursion)
            llvm::Type *type = classManager.getType(stmt->getType());
            const auto value = std::any_cast<llvm::Value *>(accept(stmt->getValue()));
            const std::string name = stmt->getName();
            return builder.createVariable(type, value, name);
        }

        llvm::Value *Object(const ObjectStmt *stmt) const {
            const std::string name = stmt->getName();
            return builder.getVar(name).var;
        }

        llvm::Value *Return(const ReturnStmt *stmt) {// NOLINT(*-no-recursion)
            const auto result = std::any_cast<llvm::Value *>(accept(stmt->getValue()));
            return builder.createReturn(result);
        }

        llvm::Value *Block(const BlockStmt *stmt) {// NOLINT(*-no-recursion)
            builder.push();
            for(const auto i: stmt->stmts) {
                accept(i);
            }
            builder.pop();
            return nullptr;
        }

        llvm::Value *While(const WhileStmt *stmt) {// NOLINT(*-no-recursion)
            llvm::BasicBlock *condBlock = builder.createBasicBlock("while.cond", builder.getParent());
            llvm::BasicBlock *loopBlock = builder.createBasicBlock("while.loop", builder.getParent());
            llvm::BasicBlock *oldBlock = builder.getNowBlock();

            builder.createJump(condBlock);
            builder.setNowBlock(condBlock);
            const auto cond = std::any_cast<llvm::Value *>(accept(stmt->getCondition()));
            builder.createCondJump(cond, loopBlock, oldBlock);

            builder.push();
            builder.setNowBlock(loopBlock);
            accept(stmt->getBody());
            builder.createJump(condBlock);
            builder.pop();

            builder.setNowBlock(oldBlock);
            return nullptr;
        }

        llvm::Value* For(const ForStmt *stmt) {
            llvm::BasicBlock *condBlock = builder.createBasicBlock("cond", builder.getParent());
            llvm::BasicBlock *selfVarBlock = builder.createBasicBlock("selfVar", builder.getParent());
            llvm::BasicBlock *loopBlock = builder.createBasicBlock("loop", builder.getParent());
            llvm::BasicBlock *oldBlock = builder.getNowBlock();

            if(!stmt->getInit()->isNoneStmt()) {
                accept(stmt->getInit());
            }

            return nullptr;
        }
    };
}// namespace Riddle