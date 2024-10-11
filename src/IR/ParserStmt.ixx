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
        VarManager varManager;

    public:
        explicit ParserStmt(Context &ctx): builder(ctx), classManager(ctx.llvm_context) {}

        // 获取从语句得到的结果
        std::any accept(BaseStmt *stmt) {
            if(stmt->getStmtTypeID() == BaseStmt::StmtTypeID::ProgramStmtID) {
                Program(static_cast<ProgramStmt *>(stmt));
                return nullptr;
            } else if(stmt->getStmtTypeID() == BaseStmt::StmtTypeID::IntegerStmtID) {
                return Integer(static_cast<IntegerStmt *>(stmt));
            } else if(stmt->getStmtTypeID() == BaseStmt::StmtTypeID::DoubleStmtID) {
                return Double(static_cast<DoubleStmt *>(stmt));
            } else if(stmt->getStmtTypeID() == BaseStmt::StmtTypeID::ObjStmtID) {
                return Object(static_cast<ObjectStmt *>(stmt));
            } else if(stmt->getStmtTypeID() == BaseStmt::StmtTypeID::FuncDefineStmtID) {
                return FuncDefine(static_cast<FuncDefineStmt *>(stmt));
            } else if(stmt->getStmtTypeID() == BaseStmt::StmtTypeID::VarDefineStmtID) {
                return VarDefine(static_cast<VarDefineStmt *>(stmt));
            } else if(stmt->getStmtTypeID() == BaseStmt::StmtTypeID::ReturnStmtID) {
                Return(static_cast<ReturnStmt *>(stmt));
                return nullptr;
            }
            return nullptr;
        }

        llvm::Value *Integer(const IntegerStmt *stmt) {
            return builder.getInt32(stmt->getValue());
        }

        llvm::Value *Double(const DoubleStmt *stmt) const {
            return builder.getDouble(stmt->getValue());
        }

        void Program(ProgramStmt *stmt) {
            for(const auto i: stmt->body) {
                accept(i);
            }
        }

        llvm::Function *FuncDefine(const FuncDefineStmt *stmt) {
            const std::string name = stmt->getFuncName();
            llvm::Type *returnType = classManager.getType(stmt->getReturnType());
            const auto args = stmt->getArgs();
            BaseStmt *body = stmt->getBody();
            auto [funcType, func] = builder.createFuncDefine(name, returnType, args->getArgsTypes(classManager));
            llvm::BasicBlock *entry = builder.createBasicBlock("entry", func);
            builder.setBlock(entry);
            accept(body);
            return func;
        }

        llvm::Value *VarDefine(const VarDefineStmt *stmt) {
            llvm::Type *type = classManager.getType(stmt->getType());
            const auto value = std::any_cast<llvm::Value *>(accept(stmt->getValue()));
            const std::string name = stmt->getName();
            return builder.createVariable(type, value, name);
        }

        llvm::Value *Object(const ObjectStmt *stmt) {
            const std::string name = stmt->getName();
            return varManager.getVar(name).var;
        }

        void Return(const ReturnStmt *stmt) {
            accept(stmt->getValue());
        }
    };
}// namespace Riddle