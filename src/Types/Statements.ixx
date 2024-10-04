module;
#include "Tools/GenTools.h"
#include <utility>
export module Statements;
namespace Riddle {
    /// @brief 所有语句的基本语句
    class BaseStmt {
    public:
        /// 用于标识语句类型
        enum class StmtTypeID {
            VarDefineStmtID, // 变量定义
            FuncDefineStmtID,// 函数定义
            ForStmtID,       // for 循环
            WhileStmtID,     // while 循环
            BinaryOpStmtID,  // 双元运算
            UnaryOpStmtID,   // 单元运算
            LabelStmtID,     // Label 表达式
            ReturnStmtID,    // 返回语句
            IfStmtID,        // If 语句
            TryStmtID,       // 错误处理
            ObjStmtID,       // 获取对象
            ConstantStmtID,  // 常量
            BlockStmtID,     // 组合语句 {}

            NullStmtID,// 没有任何效果的语句
        };

    protected:
        StmtTypeID StmtID;

    public:
        BaseStmt(): StmtID(StmtTypeID::NullStmtID) {}
        explicit BaseStmt(const StmtTypeID stmtTypeID): StmtID(stmtTypeID) {}

        [[nodiscard]] inline StmtTypeID getTypeID() const {
            return StmtID;
        }
    };

    /// @brief 是多个语句的组合
    class BlockStmt : public BaseStmt {
    public:
        std::vector<BaseStmt> stmts;
        BlockStmt(): BaseStmt(StmtTypeID::BlockStmtID) {}
    };


    // todo 实现多个变量定义

    /// @brief 用于存储变量定义
    class VarDefineStmt : public BaseStmt {
        std::string name;
        std::string type;
        /// 对于一个值，一定可以被解析为一个Statement
        BaseStmt value;

    public:
        VarDefineStmt(std::string name, std::string type, const BaseStmt value): BaseStmt(StmtTypeID::VarDefineStmtID),
                                                                                 name(std::move(name)),
                                                                                 type(std::move(type)), value(value) {}

        [[nodiscard]] inline std::string getName() const { return name; }
        [[nodiscard]] inline std::string getType() const { return type; }
        [[nodiscard]] inline BaseStmt getValue() const { return value; }
    };

    /// @brief 用于存储函数定义
    class FuncDefineStmt : public BaseStmt {
    public:
        class DefineArg {
            std::string name;
            std::string type;
            std::string default_value;
        };

    protected:
        std::string func_name;
        std::string return_type;
        std::vector<DefineArg> args;
        BaseStmt body;

    public:
        FuncDefineStmt(std::string func_name,
                       std::string return_type,
                       std::vector<DefineArg> args = {},
                       const BaseStmt body = BaseStmt()): BaseStmt(StmtTypeID::FuncDefineStmtID),
                                                          func_name(std::move(func_name)),
                                                          return_type(std::move(return_type)), args(std::move(args)) {}
        /// 设置函数体
        void setBodyStmts(const BaseStmt stmts) {
            body = stmts;
        }

        [[nodiscard]] inline std::string getFuncName() const { return func_name; }
        [[nodiscard]] inline std::string getReturnType() const { return return_type; }
        [[nodiscard]] inline std::vector<DefineArg> getArgs() const { return args; }
        [[nodiscard]] inline BaseStmt getBody() const { return body; }
    };

    /// @brief 用于存储for循环语句
    class ForStmt : public BaseStmt {
    protected:
        BaseStmt init;
        BaseStmt condition;
        BaseStmt self_change;
        BaseStmt body;

    public:
        ForStmt(const BaseStmt init,
                const BaseStmt cond,
                const BaseStmt self_change,
                const BaseStmt body = BaseStmt()): BaseStmt(StmtTypeID::ForStmtID), init(init), condition(cond),
                                                   self_change(self_change), body(body) {}

        /// 设置循环体
        void setBodyStmt(const BaseStmt stmt) {
            body = stmt;
        }

        [[nodiscard]] inline BaseStmt getInit() const { return init; }
        [[nodiscard]] inline BaseStmt getCondition() const { return condition; }
        [[nodiscard]] inline BaseStmt getSelfChange() const { return self_change; }
        [[nodiscard]] inline BaseStmt getBody() const { return body; }
    };

    /// @brief 用于存储while循环语句
    class WhileStmt : public BaseStmt {
    protected:
        BaseStmt condition;
        BaseStmt body;

    public:
        WhileStmt(const BaseStmt cond, const BaseStmt body): condition(cond), body(body) {}

        void setBodyStmt(const BaseStmt stmt) {
            body = stmt;
        }

        [[nodiscard]] inline BaseStmt getCondition() const { return condition; }
        [[nodiscard]] inline BaseStmt getBody() const { return body; }
    };
}// namespace Riddle