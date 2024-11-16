module;
#include <any>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <stack>
export module IR.ParserStmt;
import Types.Statements;
import Manager.ClassManager;
import Manager.VarManager;
import Manager.OpManager;
import IR.Context;
import IR.Builder;
export namespace Riddle {
    class ParserStmt {
        Builder builder;
        ClassManager classManager;
        std::stack<llvm::BasicBlock *> breakBlocks;
        std::stack<llvm::BasicBlock *> continueBlocks;

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

                case BaseStmt::StmtTypeID::BoolStmtID:
                    return Boolean(dynamic_cast<BoolStmt *>(stmt));

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

                case BaseStmt::StmtTypeID::ForStmtID:
                    return For(dynamic_cast<ForStmt *>(stmt));

                case BaseStmt::StmtTypeID::ContinueStmtID:
                    return Continue();

                case BaseStmt::StmtTypeID::BreakStmtID:
                    return Break();

                case BaseStmt::StmtTypeID::BinaryExprStmtID:
                    return BinaryExpr(dynamic_cast<BinaryExprStmt *>(stmt));

                // 未知的 StmtTypeID 类型或未实现的类型
                default:
                    throw std::logic_error("Unhandled StmtTypeID");
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

        llvm::Value* Boolean(const BoolStmt *stmt) {
            llvm::Value *result = builder.getBool(stmt->getValue());
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

        /// @brief 定义一个函数的具体实现，根据给定的函数定义语句创建LLVM函数
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

            // 预处理 varDefine
            std::function<void(BaseStmt *)> pre_varDefine = [&](BaseStmt *s) {
                // 立刻分配空间
                if(const auto it = dynamic_cast<VarDefineStmt *>(s)) {
                    it->isStore = false;
                    accept(it);
                    return;
                }
                if(s->BodyCount() == 1) {
                    if(const auto it = dynamic_cast<ForStmt *>(s)) {
                        pre_varDefine(it->getBody());
                    }
                    if(const auto it = dynamic_cast<WhileStmt *>(s)) {
                        pre_varDefine(it->getBody());
                    }
                    if(const auto it = dynamic_cast<BlockStmt *>(s)) {
                        for(const auto i: it->stmts) {
                            pre_varDefine(i);
                        }
                        for(int i = 0; i < it->stmts.size(); i++) {
                            if(const auto t = dynamic_cast<VarDefineStmt *>(it->stmts[i])) {
                                it->stmts[i] = builder.getStmtManager().getBinaryExpr(builder.getStmtManager().getObject(t->getName()), t->getValue(), "=");
                                i--;
                            }
                        }
                    }
                    if(const auto it = dynamic_cast<IfStmt *>(s)) {
                        pre_varDefine(it->getThenBody());
                    }
                } else if(s->BodyCount() == 2) {
                    if(const auto it = dynamic_cast<IfStmt *>(s)) {
                        pre_varDefine(it->getThenBody());
                        pre_varDefine(it->getElseBody());
                    }
                }
            };

            builder.push();
            builder.pushParent(func);

            pre_varDefine(body);

            accept(body);
            builder.pop();
            builder.popParent();
            return func;
        }


        llvm::Value *VarDefine(const VarDefineStmt *stmt) {// NOLINT(*-no-recursion)
            const auto value = std::any_cast<llvm::Value *>(accept(stmt->getValue()));
            const std::string name = stmt->getName();
            llvm::Type *type = nullptr;
            if(stmt->getType().empty()) {
                type = value->getType();
            } else {
                type = classManager.getType(stmt->getType());
            }
            if(stmt->isStore) {
                return builder.createVariable(type, value, name);
            }
            else {
                return builder.createVariable(type, nullptr, name);
            }
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
            llvm::BasicBlock *exitBlock = builder.createBasicBlock("while.exit", builder.getParent());

            builder.createJump(condBlock);
            builder.setNowBlock(condBlock);
            // cond 是必须要求的
            const auto cond = std::any_cast<llvm::Value *>(accept(stmt->getCondition()));
            builder.createCondJump(cond, loopBlock, exitBlock);

            breakBlocks.push(exitBlock);
            continueBlocks.push(condBlock);

            builder.push();
            builder.setNowBlock(loopBlock);
            accept(stmt->getBody());
            builder.createJump(condBlock);
            builder.pop();

            breakBlocks.pop();
            continueBlocks.pop();

            builder.setNowBlock(exitBlock);
            return nullptr;
        }

        llvm::Value *For(const ForStmt *stmt) {
            llvm::BasicBlock *condBlock = builder.createBasicBlock("for.cond", builder.getParent());
            llvm::BasicBlock *loopBlock = builder.createBasicBlock("for.loop", builder.getParent());
            llvm::BasicBlock *exitBlock = builder.createBasicBlock("for.exit", builder.getParent());

            if(!stmt->getInit()->isNoneStmt()) {
                accept(stmt->getInit());
            }

            builder.push();

            if(!stmt->getInit()->isNoneStmt()) {
                accept(stmt->getInit());
            }

            builder.createJump(condBlock);
            builder.setNowBlock(condBlock);
            // 如果没有 Cond 那么一直运行
            llvm::Value *cond = builder.getBool(true);
            if(!stmt->getCondition()->isNoneStmt()) {
                cond = std::any_cast<llvm::Value *>(accept(stmt->getCondition()));
            }

            builder.createCondJump(cond, loopBlock, exitBlock);

            // 设置当前 break 和 continue 执行的对象
            breakBlocks.push(exitBlock);
            continueBlocks.push(condBlock);

            builder.setNowBlock(loopBlock);
            if(!stmt->getSelfChange()->isNoneStmt()) {
                accept(stmt->getSelfChange());
            }
            accept(stmt->getBody());
            builder.createJump(condBlock);

            builder.setNowBlock(exitBlock);

            builder.pop();

            breakBlocks.pop();
            continueBlocks.pop();

            return nullptr;
        }

        llvm::Value *Break() {
            builder.createJump(breakBlocks.top());
            return nullptr;
        }

        llvm::Value *Continue() {
            builder.createJump(continueBlocks.top());
            return nullptr;
        }

        llvm::Value *BinaryExpr(const BinaryExprStmt *stmt) {
            auto lhs = std::any_cast<llvm::Value *>(accept(stmt->getLHS()));
            auto rhs = std::any_cast<llvm::Value *>(accept(stmt->getRHS()));
            auto op = stmt->getOpt();
            // 由于可能的运算符的数量过多，我们使用一个Manager来控制
            llvm::Value *result = builder.getOpManager().getOpFunc(OpGroup{lhs->getType(), rhs->getType(), op})(builder.getLLVMBuilder(),lhs,rhs);

            return result;
        }
    };
}// namespace Riddle