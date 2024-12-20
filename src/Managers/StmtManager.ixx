module;
#include <string>
#include <utility>
#include <vector>
export module managers.StmtManager;

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
            BlockStmt *_body = nullptr;
            try {
                _body = dynamic_cast<BlockStmt *>(body);
            } catch(...) {
                _body = this->getBlock({body});
            }
            const auto ptr = new WhileStmt(condition, _body);
            stmts.push_back(ptr);
            return ptr;
        }
        ForStmt *getFor(BaseStmt *init, BaseStmt *condition, BaseStmt *changed, BaseStmt *body) {
            BlockStmt *_body = nullptr;
            try {
                _body = dynamic_cast<BlockStmt *>(body);
            } catch(...) {
                _body = this->getBlock({body});
            }
            const auto ptr = new ForStmt(init, condition, changed, _body);
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

        /// @brief 获取一个无作用的语句
        BaseStmt *getNoneStmt() {
            const auto ptr = new BaseStmt(BaseStmt::StmtTypeID::NoneStmtID);
            stmts.push_back(ptr);
            return ptr;
        }

        BlockStmt *getBlock(std::vector<BaseStmt *> stmt_list) {
            const auto ptr = new BlockStmt();
            ptr->stmts = std::move(stmt_list);
            stmts.push_back(ptr);
            return ptr;
        }

        ObjectStmt *getObject(const std::string &name) {
            const auto ptr = new ObjectStmt(name);
            stmts.push_back(ptr);
            return ptr;
        }

        ContinueStmt *getContinue() {
            const auto ptr = new ContinueStmt();
            stmts.push_back(ptr);
            return ptr;
        }

        BreakStmt *getBreak() {
            const auto ptr = new BreakStmt();
            stmts.push_back(ptr);
            return ptr;
        }

        BinaryExprStmt *getBinaryExpr(BaseStmt *lhs, BaseStmt *rhs, const std::string &opt) {
            const auto ptr = new BinaryExprStmt(lhs, rhs, opt);
            stmts.push_back(ptr);
            return ptr;
        }

        ArgListStmt *getArgList(std::vector<BaseStmt *> stmtList) {
            const auto ptr = new ArgListStmt(std::move(stmtList));
            stmts.push_back(ptr);
            return ptr;
        }

        FuncCallStmt *getFuncCall(const std::string &funcName, ArgListStmt *args) {
            const auto ptr = new FuncCallStmt(funcName, args);
            stmts.push_back(ptr);
            return ptr;
        }

        DefineArgStmt *getDefineArg(const std::string &name, const std::string &type, BaseStmt *value) {
            const auto ptr = new DefineArgStmt(name, type, value);
            stmts.push_back(ptr);
            return ptr;
        }

        DefineArgListStmt *getDefineArgList(const std::vector<DefineArgStmt *> &stmtList) {
            const auto ptr = new DefineArgListStmt(stmtList);
            stmts.push_back(ptr);
            return ptr;
        }

        IfStmt *getIf(BaseStmt *condition, BaseStmt *thenBody, BaseStmt *elseBody) {
            const auto ptr = new IfStmt(condition, thenBody, elseBody);
            stmts.push_back(ptr);
            return ptr;
        }

        ClassDefineStmt *getClassDefine(const std::string &name,std::vector<VarDefineStmt*>varDefs) {
            const auto ptr = new ClassDefineStmt(name, std::move(varDefs));
            stmts.push_back(ptr);
            return ptr;
        }
    };
}// namespace Riddle