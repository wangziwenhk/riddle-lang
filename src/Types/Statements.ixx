module;
#include "Tools/GenTools.h"
#include <llvm/IR/Value.h>
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

            NullStmtID,      // 没有任何效果的语句
        };

    protected:
        StmtTypeID StmtID;

    public:
        explicit BaseStmt(const StmtTypeID stmtTypeID): StmtID(stmtTypeID) {}

        [[nodiscard]] inline StmtTypeID getTypeID() const {
            return StmtID;
        }
    };

    class VarDefineStmt : public BaseStmt {
        std::string name;
        std::string type;
        /// 对于一个值，一定可以被解析为一个Statement
        BaseStmt value;

    public:
        VarDefineStmt(std::string name, std::string type, const BaseStmt value): BaseStmt(StmtTypeID::VarDefineStmtID), name(std::move(name)), type(std::move(type)), value(value) {}

        [[nodiscard]] inline std::string getName() const { return name; }
        [[nodiscard]] inline std::string getType() const { return type; }
        [[nodiscard]] inline BaseStmt getValue() const { return value; }
    };

    class FuncDefineStmt : public BaseStmt {
    public:
        class Arg {
            std::string name;
            std::string type;
            std::string default_value;
        };

    protected:
        std::string func_name;
        std::string return_type;
        std::vector<Arg> args;
        std::vector<BaseStmt> body;

    public:
        FuncDefineStmt(std::string func_name, std::string return_type, std::vector<Arg> args = {}): BaseStmt(StmtTypeID::FuncDefineStmtID),
                                                                                                    func_name(std::move(func_name)),
                                                                                                    return_type(std::move(return_type)), args(std::move(args)) {}
        void addStmt(const BaseStmt stmt) {
            body.push_back(stmt);
        }
    };
}// namespace Riddle