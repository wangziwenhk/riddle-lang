module;
#include <llvm/IR/Type.h>
#include <string>
#include <utility>
#include <vector>
export module Types.Statements;
import Type.DefineArg;
import managers.ClassManager;
export namespace Riddle {
    /// @brief 所有语句的基本语句
    class BaseStmt {
    public:
        /// 用于标识语句类型
        enum class StmtTypeID {
            ProgramStmtID,
            VarDefineStmtID, // 变量定义
            FuncDefineStmtID,// 函数定义
            FuncCallStmtID,  // 函数调用
            ForStmtID,       // for 循环
            WhileStmtID,     // while 循环
            BinaryExprStmtID,// 双元运算
            UnaryExprStmtID, // 单元运算
            LabelStmtID,     // Label 表达式
            IfStmtID,        // If 语句
            TryStmtID,       // 错误处理
            ObjStmtID,       // 获取对象
            BlockStmtID,     // 组合语句 {}

            ReturnStmtID,  // 返回语句
            ContinueStmtID,// 跳过当前循环
            BreakStmtID,   // 跳出当前循环

            IntegerStmtID,// int 类型
            FloatStmtID,  // float 类型
            DoubleStmtID, // double 类型
            BoolStmtID,   // bool 类型
            StringStmtID, // string 类型
            NullStmtID,   // Null

            DefineArgStmtID,
            DefineArgListStmtID,
            ArgStmtID,
            ArgListStmtID,

            ClassDefineStmtID,

            NoneStmtID,// 没有任何效果的语句
        };

    protected:
        StmtTypeID StmtID;

    public:
        BaseStmt() = delete;
        explicit BaseStmt(const StmtTypeID stmtTypeID): StmtID(stmtTypeID) {}
        virtual ~BaseStmt() = default;

        virtual bool isConstant() {
            return false;
        }

        [[nodiscard]] inline StmtTypeID getStmtTypeID() const {
            return StmtID;
        }

        [[nodiscard]] inline bool isNoneStmt() const { return StmtID == StmtTypeID::NoneStmtID; }

        [[nodiscard]] virtual inline int BodyCount() const {
            return 0;
        }
    };

    class ProgramStmt final : public BaseStmt {
    public:
        std::vector<BaseStmt *> body;
        explicit ProgramStmt(std::vector<BaseStmt *> body): BaseStmt(StmtTypeID::ProgramStmtID), body{std::move(body)} {}

        [[nodiscard]] int BodyCount() const override {
            return 1;
        }
    };

    /// @brief 是多个语句的组合
    class BlockStmt final : public BaseStmt {
    public:
        std::vector<BaseStmt *> stmts;
        BlockStmt(): BaseStmt(StmtTypeID::BlockStmtID) {}

        [[nodiscard]] int BodyCount() const override {
            return 1;
        }
    };

    /// @brief 存储常量
    class ConstantStmt : public BaseStmt {
    public:
        explicit ConstantStmt(const StmtTypeID TypeID): BaseStmt(TypeID) {}
        bool isConstant() override {
            return true;
        }
    };

    /// @brief 存储int类型数据
    class IntegerStmt final : public ConstantStmt {
    public:
        explicit IntegerStmt(const int value): ConstantStmt(StmtTypeID::IntegerStmtID), value(value) {}
        int value;
    };

    /// @brief 存储 float 数据类型
    class FloatStmt final : public ConstantStmt {
    public:
        explicit FloatStmt(const float value): ConstantStmt(StmtTypeID::FloatStmtID), value(value) {}
        float value;
    };

    /// @brief 存储 Null 数据类型
    class NullStmt final : public ConstantStmt {
    public:
        NullStmt(): ConstantStmt(StmtTypeID::NullStmtID) {}
    };

    /// @brief 存储 double 数据类型
    class DoubleStmt final : public ConstantStmt {
    public:
        explicit DoubleStmt(const double value): ConstantStmt(StmtTypeID::DoubleStmtID), value(value) {}
        double value;
    };

    /// @brief 存储 bool 数据类型
    class BoolStmt final : public ConstantStmt {
    public:
        explicit BoolStmt(const bool value): ConstantStmt(StmtTypeID::BoolStmtID), value(value) {}
        bool value;
    };

    /// @brief 存储 string 数据类型
    class StringStmt final : public ConstantStmt {
    public:
        explicit StringStmt(std::string value): ConstantStmt(StmtTypeID::StringStmtID), value(std::move(value)) {}
        std::string value;
    };

    /// @brief 用于存储变量定义
    class VarDefineStmt final : public BaseStmt {
    public:
        VarDefineStmt(std::string name, std::string type, BaseStmt *value): BaseStmt(StmtTypeID::VarDefineStmtID),
                                                                            name(std::move(name)),
                                                                            type(std::move(type)), value(value) {}

        std::string name;
        std::string type;
        /// 对于一个值，一定可以被解析为一个Statement
        BaseStmt *value;
        /// 是否在函数内部时被优化到entry
    };

    class DefineArgStmt final : public BaseStmt {
    protected:
    public:
        DefineArgStmt(std::string name, std::string type, BaseStmt *value): BaseStmt(StmtTypeID::DefineArgStmtID),
                                                                            name(std::move(name)),
                                                                            type(std::move(type)),
                                                                            value(value) {}
        std::string name;
        std::string type;
        /// 默认值
        BaseStmt *value;
    };

    class DefineArgListStmt final : public BaseStmt {
    public:
        explicit DefineArgListStmt(std::vector<DefineArgStmt *> args): BaseStmt(StmtTypeID::DefineArgListStmtID), args(std::move(args)) {}

        std::vector<DefineArgStmt *> args;
        [[nodiscard]] std::vector<llvm::Type *> getArgsTypes(ClassManager &manager) const {
            std::vector<llvm::Type *> argTypes;
            argTypes.reserve(args.size());
            for(const auto arg: args) {
                argTypes.push_back(manager.getType(arg->type));
            }
            return argTypes;
        }
        [[nodiscard]] std::vector<std::string> getArgsNames() const {
            if(args.empty()) {
                return {};
            }
            std::vector<std::string> names;
            names.reserve(args.size());
            for(const auto i: args) {
                names.push_back(i->name);
            }
            return names;
        }
    };

    /// @brief 用于存储函数定义
    class FuncDefineStmt final : public BaseStmt {
    public:
        FuncDefineStmt(std::string func_name,
                       std::string return_type,
                       BaseStmt *body,
                       DefineArgListStmt *args = nullptr): BaseStmt(StmtTypeID::FuncDefineStmtID),
                                                           func_name(std::move(func_name)),
                                                           return_type(std::move(return_type)),
                                                           args(args), body(body) {}

        std::string func_name;
        std::string return_type;
        DefineArgListStmt *args;
        BaseStmt *body;

        [[nodiscard]] int BodyCount() const override {
            return 1;
        }
    };

    /// @brief 用于存储for循环语句
    class ForStmt final : public BaseStmt {
    public:
        ForStmt(BaseStmt *init,
                BaseStmt *cond,
                BaseStmt *self_change,
                BlockStmt *body): BaseStmt(StmtTypeID::ForStmtID), init(init), condition(cond),
                                  self_change(self_change), body(body) {}

        BaseStmt *init;
        BaseStmt *condition;
        BaseStmt *self_change;
        BlockStmt *body;

        [[nodiscard]] inline int BodyCount() const override {
            return 1;
        }
    };

    /// @brief 用于存储while循环语句
    class WhileStmt final : public BaseStmt {
    public:
        WhileStmt(BaseStmt *cond, BlockStmt *body): BaseStmt(StmtTypeID::WhileStmtID), condition(cond), body(body) {}

        void setBodyStmt(BlockStmt *stmt) {
            body = stmt;
        }

        BaseStmt *condition;
        BlockStmt *body;


        [[nodiscard]] inline int BodyCount() const override {
            return 1;
        }
    };

    /// @brief 用于存储 try 语句
    class TryStmt final : public BaseStmt {
    public:
        TryStmt(BaseStmt *tryBody, BaseStmt *catchBody): BaseStmt(StmtTypeID::TryStmtID), tryBody(tryBody), catchBody(catchBody) {}

        BaseStmt *tryBody;
        BaseStmt *catchBody;

        [[nodiscard]] inline int BodyCount() const override {
            return 2;
        }
    };

    /// @brief 用于存储 if 语句
    class IfStmt final : public BaseStmt {
    public:
        IfStmt(BaseStmt *cond, BaseStmt *thenBody, BaseStmt *elseBody): BaseStmt(StmtTypeID::IfStmtID), condition(cond), thenBody(thenBody), elseBody(elseBody) {}

        BaseStmt *condition;
        BaseStmt *thenBody;
        BaseStmt *elseBody;

        [[nodiscard]] inline int BodyCount() const override {
            return elseBody == nullptr ? 1 : 2;
        }
    };

    class ObjectStmt final : public BaseStmt {
    public:
        explicit ObjectStmt(std::string name): BaseStmt(StmtTypeID::ObjStmtID), name(std::move(name)) {}

        std::string name;
    };

    class ReturnStmt final : public BaseStmt {
    public:
        explicit ReturnStmt(BaseStmt *value): BaseStmt(StmtTypeID::ReturnStmtID), value(value) {}
        BaseStmt *value;
    };

    class ContinueStmt final : public BaseStmt {
    public:
        explicit ContinueStmt(): BaseStmt(StmtTypeID::ContinueStmtID) {}
    };

    class BreakStmt final : public BaseStmt {
    public:
        explicit BreakStmt(): BaseStmt(StmtTypeID::BreakStmtID) {}
    };

    class BinaryExprStmt final : public BaseStmt {
    public:
        BinaryExprStmt(BaseStmt *lhs, BaseStmt *rhs, std::string opt): BaseStmt(StmtTypeID::BinaryExprStmtID), lhs(lhs), rhs(rhs), opt(std::move(opt)) {}

        BaseStmt *lhs;
        BaseStmt *rhs;
        std::string opt;
    };

    class ArgStmt final : public BaseStmt {
    public:
        explicit ArgStmt(BaseStmt *value): BaseStmt(StmtTypeID::ArgStmtID), value(value) {}

        BaseStmt *value;
    };

    class ArgListStmt final : public BaseStmt {
    public:
        explicit ArgListStmt(std::vector<BaseStmt *> args): BaseStmt(StmtTypeID::ArgListStmtID), args(std::move(args)) {}
        std::vector<BaseStmt *> args;
    };

    class FuncCallStmt final : public BaseStmt {
    public:
        explicit FuncCallStmt(std::string name, ArgListStmt *args): BaseStmt(StmtTypeID::FuncCallStmtID), name(std::move(name)), args(args) {}

        std::string name;
        ArgListStmt *args;
    };

    class ClassDefineStmt final : public BaseStmt {
    public:
        explicit ClassDefineStmt(std::string className,
                                 std::vector<VarDefineStmt *> members,
                                 const std::vector<FuncDefineStmt *> &funcDefines): BaseStmt(StmtTypeID::ClassDefineStmtID),
                                                                                    members(std::move(members)),
                                                                                    funcDefines(funcDefines),
                                                                                    name(std::move(className)) {}
        std::vector<VarDefineStmt *> members;
        std::vector<FuncDefineStmt *> funcDefines;
        std::string name;
    };
}// namespace Riddle