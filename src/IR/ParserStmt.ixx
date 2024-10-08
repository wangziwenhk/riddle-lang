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
        ParserStmt(Context &ctx): classManager(ctx.llvm_context), builder(ctx) {}

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
    };
}// namespace Riddle