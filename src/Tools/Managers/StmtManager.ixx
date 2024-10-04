module;
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
        BaseStmt *getConstant(const int value) {
            const auto ptr = new IntegerStmt(value);
            stmts.push_back(ptr);
            return ptr;
        }
        BaseStmt *getConstant(const double value) {
            const auto ptr = new DoubleStmt(value);
            stmts.push_back(ptr);
            return ptr;
        }
        BaseStmt *getConstant(const float value) {
            const auto ptr = new FloatStmt(value);
            stmts.push_back(ptr);
            return ptr;
        }
        BaseStmt *getConstant(const bool value) {
            const auto ptr = new BoolStmt(value);
            stmts.push_back(ptr);
            return ptr;
        }
        BaseStmt *getNull() {
            const auto ptr = new NullStmt();
            stmts.push_back(ptr);
            return ptr;
        }
    };
}// namespace Riddle