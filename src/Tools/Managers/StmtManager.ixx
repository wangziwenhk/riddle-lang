module;
#include <string>
#include <vector>
export module Managers.StmtManager;

import Types.Statements;

export namespace Riddle {
    class StmtManager {
        std::vector<BaseStmt *> stmts;

    public:
        ~StmtManager() {
            for(const auto stmt: stmts) {
                delete stmt;
            }
        }
        IntegerStmt *getConstant(const int value) {
            const auto ptr = new IntegerStmt(value);
            stmts.push_back(ptr);
            return ptr;
        }
        DoubleStmt *getConstant(const double value) {
            const auto ptr = new DoubleStmt(value);
            stmts.push_back(ptr);
            return ptr;
        }
        FloatStmt *getConstant(const float value) {
            const auto ptr = new FloatStmt(value);
            stmts.push_back(ptr);
            return ptr;
        }
        BoolStmt *getConstant(const bool value) {
            const auto ptr = new BoolStmt(value);
            stmts.push_back(ptr);
            return ptr;
        }
        StringStmt *getConstant(const std::string &value) {
            const auto ptr = new StringStmt(value);
            stmts.push_back(ptr);
            return ptr;
        }
        NullStmt *getNull() {
            const auto ptr = new NullStmt();
            stmts.push_back(ptr);
            return ptr;
        }
        VarDefineStmt *getVarDefine(const std::string &name, const std::string &type, BaseStmt *value) {
            const auto ptr = new VarDefineStmt(name, type, value);
            stmts.push_back(ptr);
            return ptr;
        }
        WhileStmt *getWhile(BaseStmt *condition, BaseStmt *body) {
            const auto ptr = new WhileStmt(condition, body);
            stmts.push_back(ptr);
            return ptr;
        }
        ForStmt *getFor(BaseStmt *init, BaseStmt *condition, BaseStmt *changed, BaseStmt *body) {
            const auto ptr = new ForStmt(init, condition, changed, body);
            stmts.push_back(ptr);
            return ptr;
        }

        ProgramStmt *getProgram(const std::vector<BaseStmt *> &stmtList) {
            const auto ptr = new ProgramStmt(stmtList);
            stmts.push_back(ptr);
            return ptr;
        }

        ReturnStmt *getReturn(BaseStmt *stmt = nullptr) {
            const auto ptr = new ReturnStmt(stmt);
            stmts.push_back(ptr);
            return ptr;
        }

        FuncDefineStmt *getFuncDefine(const std::string &name, const std::string &return_type, BaseStmt *body, DefineArgListStmt *args = nullptr) {
            const auto ptr = new FuncDefineStmt(name, return_type, body, args);
            stmts.push_back(ptr);
            return ptr;
        }

        BaseStmt *getNoneStmt() {
            const auto ptr = new BaseStmt(BaseStmt::StmtTypeID::NoneStmtID);
            stmts.push_back(ptr);
            return ptr;
        }
    };
}// namespace Riddle