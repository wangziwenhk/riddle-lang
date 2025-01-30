module;
#include <llvm/IR/Instructions.h>
#include <string>
#include <utility>
#include <vector>
export module IR.Statements;
import Type.DefineArg;
import Type.Modifier;
export import Type.Identifier;
export namespace Riddle {
    /// @brief 所有语句的基本语句
    class BaseStmt {
    public:
        /// 用于标识语句类型
        enum StmtTypeID : int {
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

            IntegerStmtID,      // int 类型
            FloatStmtID,        // float 类型
            DoubleStmtID,       // double 类型
            BoolStmtID,         // bool 类型
            StringLiteralStmtID,// string 类型
            NullStmtID,         // Null

            DefineArgStmtID,
            DefineArgListStmtID,
            ArgStmtID,
            ArgListStmtID,

            ClassDefineStmtID,
            MethodCallStmtID,
            MemberExprStmtID,

            NoneStmtID,// 没有任何效果的语句
        };

    protected:
        StmtTypeID StmtID;

        // 表示当前是否只推断类型
        bool isBuild = true;

    public:
        BaseStmt() = delete;
        explicit BaseStmt(const StmtTypeID stmtTypeID): StmtID(stmtTypeID) {}
        virtual ~BaseStmt() = default;

        [[nodiscard]] virtual bool isConstant() const {
            return false;
        }

        [[nodiscard]] inline StmtTypeID getStmtTypeID() const {
            return StmtID;
        }

        [[nodiscard]] inline bool isNoneStmt() const {
            return StmtID == NoneStmtID;
        }

        [[nodiscard]] virtual inline int BodyCount() const {
            return 0;
        }

        [[nodiscard]] bool getIsBuild() const {
            return isBuild;
        }

        virtual void setIsBuild(const bool is_build) {
            this->isBuild = is_build;
        }
    };

    class ProgramStmt final : public BaseStmt {
    public:
        std::vector<BaseStmt *> body;
        explicit ProgramStmt(std::vector<BaseStmt *> body): BaseStmt(ProgramStmtID), body{std::move(body)} {}

        [[nodiscard]] int BodyCount() const override {
            return 1;
        }
    };

    /// @brief 是多个语句的组合
    class BlockStmt final : public BaseStmt {
    public:
        std::vector<BaseStmt *> stmts;
        BlockStmt(): BaseStmt(BlockStmtID) {}

        [[nodiscard]] int BodyCount() const override {
            return 1;
        }
    };

    /// @brief 存储常量
    class ConstantStmt : public BaseStmt {
    public:
        explicit ConstantStmt(const StmtTypeID TypeID): BaseStmt(TypeID) {}
        [[nodiscard]] bool isConstant() const override {
            return true;
        }
    };

    /// @brief 存储int类型数据
    class IntegerStmt final : public ConstantStmt {
    public:
        explicit IntegerStmt(const int value): ConstantStmt(IntegerStmtID), value(value) {}
        int value;
    };

    /// @brief 存储 float 数据类型
    class FloatStmt final : public ConstantStmt {
    public:
        explicit FloatStmt(const float value): ConstantStmt(FloatStmtID), value(value) {}
        float value;
    };

    /// @brief 存储 Null 数据类型
    class NullStmt final : public ConstantStmt {
    public:
        NullStmt(): ConstantStmt(NullStmtID) {}
    };

    /// @brief 存储 double 数据类型
    class DoubleStmt final : public ConstantStmt {
    public:
        explicit DoubleStmt(const double value): ConstantStmt(DoubleStmtID), value(value) {}
        double value;
    };

    /// @brief 存储 bool 数据类型
    class BoolStmt final : public ConstantStmt {
    public:
        explicit BoolStmt(const bool value): ConstantStmt(BoolStmtID), value(value) {}
        bool value;
    };

    /// @brief 存储 string 数据类型
    class StringLiteralStmt final : public ConstantStmt {
    public:
        explicit StringLiteralStmt(std::string value): ConstantStmt(StringLiteralStmtID), value(std::move(value)) {}
        std::string value;
    };

    /// @brief 用于存储变量定义
    class VarDefineStmt final : public BaseStmt {
    public:
        VarDefineStmt(std::string name, const std::string &type, BaseStmt *value): BaseStmt(VarDefineStmtID),
                                                                                   name(std::move(name)),
                                                                                   type(type), value(value) {}

        std::string name;
        Identifier type;
        /// 对于一个值，一定可以被解析为一个Statement
        BaseStmt *value;
        /// 是否在函数内部时被优化到entry

        bool isAlloca = false;
        llvm::Value *alloca = nullptr;

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            value->setIsBuild(is_build);
        }
    };

    class DefineArgStmt final : public BaseStmt {
    public:
        DefineArgStmt(std::string name, const std::string &type, BaseStmt *value): BaseStmt(DefineArgStmtID),
                                                                                   name(std::move(name)),
                                                                                   type(type),
                                                                                   value(value) {}
        std::string name;
        Identifier type;
        /// 默认值
        BaseStmt *value;

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            value->setIsBuild(is_build);
        }
    };

    class DefineArgListStmt final : public BaseStmt {
    public:
        explicit DefineArgListStmt(std::vector<DefineArgStmt *> args): BaseStmt(DefineArgListStmtID), args(std::move(args)) {}

        std::vector<DefineArgStmt *> args;

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

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            for(const auto i: args) {
                i->setIsBuild(is_build);
            }
        }
    };

    /// @brief 用于存储函数定义
    class FuncDefineStmt final : public BaseStmt {
    public:
        FuncDefineStmt(std::string func_name,
                       const std::string &return_type,
                       BaseStmt *body,
                       const Modifier mod = {},
                       DefineArgListStmt *args = nullptr): BaseStmt(FuncDefineStmtID),
                                                           modifier(mod),
                                                           func_name(std::move(func_name)),
                                                           return_type(return_type), args(args), body(body) {}

        Modifier modifier;
        std::string func_name;
        Identifier return_type;
        DefineArgListStmt *args = nullptr;
        BaseStmt *body = nullptr;
        std::string theClass;

        [[nodiscard]] int BodyCount() const override {
            return 1;
        }

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            body->setIsBuild(is_build);
            args->setIsBuild(is_build);
        }
    };

    /// @brief 用于存储for循环语句
    class ForStmt final : public BaseStmt {
    public:
        ForStmt(BaseStmt *init,
                BaseStmt *cond,
                BaseStmt *self_change,
                BlockStmt *body): BaseStmt(ForStmtID), init(init), condition(cond),
                                  self_change(self_change), body(body) {}

        BaseStmt *init;
        BaseStmt *condition;
        BaseStmt *self_change;
        BlockStmt *body;

        [[nodiscard]] inline int BodyCount() const override {
            return 1;
        }

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            init->setIsBuild(is_build);
            condition->setIsBuild(is_build);
            self_change->setIsBuild(is_build);
            body->setIsBuild(is_build);
        }
    };

    /// @brief 用于存储while循环语句
    class WhileStmt final : public BaseStmt {
    public:
        WhileStmt(BaseStmt *cond, BlockStmt *body): BaseStmt(WhileStmtID), condition(cond), body(body) {}

        void setBodyStmt(BlockStmt *stmt) {
            body = stmt;
        }

        BaseStmt *condition;
        BlockStmt *body;


        [[nodiscard]] inline int BodyCount() const override {
            return 1;
        }

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            condition->setIsBuild(is_build);
            body->setIsBuild(is_build);
        }
    };

    /// @brief 用于存储 try 语句
    class TryStmt final : public BaseStmt {
    public:
        TryStmt(BaseStmt *tryBody, BaseStmt *catchBody): BaseStmt(TryStmtID), tryBody(tryBody), catchBody(catchBody) {}

        BaseStmt *tryBody;
        BaseStmt *catchBody;

        [[nodiscard]] inline int BodyCount() const override {
            return 2;
        }

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            tryBody->setIsBuild(is_build);
            catchBody->setIsBuild(is_build);
        }
    };

    /// @brief 用于存储 if 语句
    class IfStmt final : public BaseStmt {
    public:
        IfStmt(BaseStmt *cond, BaseStmt *thenBody, BaseStmt *elseBody): BaseStmt(IfStmtID), condition(cond), thenBody(thenBody), elseBody(elseBody) {}

        BaseStmt *condition;
        BaseStmt *thenBody;
        BaseStmt *elseBody;

        [[nodiscard]] inline int BodyCount() const override {
            return elseBody == nullptr ? 1 : 2;
        }

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            condition->setIsBuild(is_build);
            thenBody->setIsBuild(is_build);
            elseBody->setIsBuild(is_build);
        }
    };

    class ObjectStmt final : public BaseStmt {
    public:
        explicit ObjectStmt(std::string name, const bool isLoaded = false): BaseStmt(ObjStmtID), name(std::move(name)), isLoaded(isLoaded) {}

        std::string name;
        bool isLoaded = false;

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
        }
    };

    class ReturnStmt final : public BaseStmt {
    public:
        explicit ReturnStmt(BaseStmt *value): BaseStmt(ReturnStmtID), value(value) {}
        BaseStmt *value;

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            value->setIsBuild(is_build);
        }
    };

    class ContinueStmt final : public BaseStmt {
    public:
        explicit ContinueStmt(): BaseStmt(ContinueStmtID) {}
    };

    class BreakStmt final : public BaseStmt {
    public:
        explicit BreakStmt(): BaseStmt(BreakStmtID) {}
    };

    class BinaryExprStmt final : public BaseStmt {
    public:
        BinaryExprStmt(BaseStmt *lhs, BaseStmt *rhs, std::string opt): BaseStmt(BinaryExprStmtID), lhs(lhs), rhs(rhs), opt(std::move(opt)) {}

        BaseStmt *lhs;
        BaseStmt *rhs;
        std::string opt;

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            lhs->setIsBuild(is_build);
            rhs->setIsBuild(is_build);
        }
    };

    class ArgStmt final : public BaseStmt {
    public:
        explicit ArgStmt(BaseStmt *value): BaseStmt(ArgStmtID), value(value) {}

        BaseStmt *value;

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            value->setIsBuild(is_build);
        }
    };

    class ArgListStmt final : public BaseStmt {
    public:
        explicit ArgListStmt(std::vector<BaseStmt *> args): BaseStmt(ArgListStmtID), args(std::move(args)) {}
        std::vector<BaseStmt *> args;

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            for(const auto arg: args) {
                arg->setIsBuild(is_build);
            }
        }
    };

    class FuncCallStmt final : public BaseStmt {
    public:
        explicit FuncCallStmt(std::string name, ArgListStmt *args): BaseStmt(FuncCallStmtID), name(std::move(name)), args(args) {}

        std::string name;
        ArgListStmt *args;

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            for(const auto arg: args->args) {
                arg->setIsBuild(is_build);
            }
        }
    };

    class ClassDefineStmt final : public BaseStmt {
    public:
        explicit ClassDefineStmt(std::string className,
                                 std::vector<VarDefineStmt *> members,
                                 const std::vector<FuncDefineStmt *> &funcDefines,
                                 const std::string &parentClass = ""): BaseStmt(ClassDefineStmtID),
                                                                       members(std::move(members)),
                                                                       funcDefines(funcDefines),
                                                                       parentClass(parentClass),
                                                                       name(std::move(className)) {}
        std::vector<VarDefineStmt *> members;
        std::vector<FuncDefineStmt *> funcDefines;
        Identifier parentClass;
        std::string name;

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            for(const auto var: members) {
                var->setIsBuild(is_build);
            }
            for(const auto func: funcDefines) {
                func->setIsBuild(is_build);
            }
        }
    };

    class MethodCallStmt final : public BaseStmt {
    public:
        MethodCallStmt(BaseStmt *obj, FuncCallStmt *call): BaseStmt(MethodCallStmtID), object(obj), call(call) {}

        BaseStmt *object;
        FuncCallStmt *call;

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            object->setIsBuild(is_build);
            call->setIsBuild(is_build);
        }
    };

    class MemberExprStmt final : public BaseStmt {
    public:
        MemberExprStmt(BaseStmt *parent,
                       ObjectStmt *child,
                       const bool isLoaded = false): BaseStmt(MemberExprStmtID),
                                                     parent(parent), child(child),
                                                     isLoaded(isLoaded) {}
        BaseStmt *parent;
        ObjectStmt *child;
        bool isLoaded;

        void setIsBuild(const bool is_build) override {
            BaseStmt::setIsBuild(is_build);
            parent->setIsBuild(is_build);
            child->setIsBuild(is_build);
        }
    };

    template<typename T>
    bool isSameStmt(const BaseStmt *stmt) {
        return dynamic_cast<const T *>(stmt) != nullptr;
    }
}// namespace Riddle