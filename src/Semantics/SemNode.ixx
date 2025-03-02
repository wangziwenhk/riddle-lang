module;
#include <any>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <ranges>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
export module Semantics.SemNode;
import Config.BasicType;
export import Semantics.Modifier;
export namespace Riddle {
    class ClassDefineNode;
    class AllocaNode;
    class SemNodeVisitor;
#pragma region SemNode
    /// 表示一个语义树的节点
    class SemNode {
    public:
        // 存储节点类型用于 RTTI
        enum SemNodeType {
            ProgramNodeType,
            FuncDefineNodeType,
            ArgNodeType,
            BlockNodeType,

            IntegerLiteralNodeType,
            FloatLiteralNodeType,
            BoolLiteralNodeType,
            StringLiteralNodeType,

            TypeNodeType,
            BinaryOpNodeType,
            VarDefineNodeType,
            ObjectNodeType,
            FuncCallNodeType,
            AllocaNodeType,
            IfNodeType,
            WhileNodeType,
            ForNodeType,
            ReturnNodeType,

            ClassDefineNodeType,
            BlendNodeType,
        };

    protected:
        SemNodeType semType;

    public:
        explicit SemNode(const SemNodeType type): semType(type) {
        }

        virtual ~SemNode() = default;

        virtual std::any accept(SemNodeVisitor &visitor);

        [[nodiscard]] virtual bool isLiteral() const {
            return false;
        }

        [[nodiscard]] SemNodeType getSemType() const {
            return semType;
        }

        [[nodiscard]] virtual bool isAlloca() const {
            return false;
        }

        [[nodiscard]] virtual AllocaNode *getAlloca() {
            return nullptr;
        }
    };

    /// 保存一个代码块
    /// @example
    class BlockNode final : public SemNode {
    public:
        BlockNode(): SemNode(BlockNodeType), body({}) {
        }

        explicit BlockNode(const std::vector<SemNode *> &vec): SemNode(BlockNodeType), body(vec) {
        }

        std::vector<SemNode *> body;

        auto begin() {
            return body.begin();
        }

        auto end() {
            return body.end();
        }

        [[nodiscard]] auto begin() const {
            return body.cbegin();
        }

        [[nodiscard]] auto end() const {
            return body.cend();
        }

        void push_back(SemNode *node) {
            body.push_back(node);
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    /// 表示一个程序根节点
    class ProgramNode final : public SemNode {
    public:
        explicit ProgramNode(BlockNode *body): SemNode(ProgramNodeType), body(body) {
        }

        ~ProgramNode() override {
            body = nullptr;
            for (const auto i: allSemNode) {
                delete i;
            }
        }

        BlockNode *body;

        std::unordered_set<SemNode *> allSemNode;

        std::any accept(SemNodeVisitor &visitor) override;

        void addSemNode(SemNode *node) noexcept {
            allSemNode.insert(node);
        }

        void deleteSemNode(SemNode *node) noexcept {
            allSemNode.erase(node);
        }
    };

    class PackageNode final : public SemNode {
    public:
        std::string packageName;

        explicit PackageNode(std::string packageName): SemNode(ProgramNodeType), packageName(std::move(packageName)) {
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class TypeNode : public SemNode {
    public:
        static constexpr std::string unknown = "@unknown";
        static constexpr std::string Void = "void";

        explicit TypeNode(std::string name, const SemNodeType type_id = TypeNodeType): SemNode(type_id),
            name(std::move(name)) {
        }

        std::string name;
        llvm::Type *llvmType = nullptr;

        std::any accept(SemNodeVisitor &visitor) override;

        [[nodiscard]] bool isUnknown() const {
            return name == unknown;
        }

        [[nodiscard]] bool isVoid() const {
            return name == Void;
        }

        bool operator==(const TypeNode &node) const {
            return name == node.name;
        }

        [[nodiscard]] bool isClass() const {
            if (BasicType::set.contains(name)) {
                return false;
            }
            return true;
        }
    };

    /// 保存有值的 Node
    class ExprNode : public SemNode {
    protected:
        TypeNode *type;
        std::string name;

    public:
        ExprNode(TypeNode *type, const SemNodeType semType, std::string name): SemNode(semType), type(type),
                                                                               name(std::move(name)) {
        }

        TypeNode *&getType() {
            return type;
        }

        std::string getName() {
            return name;
        }
    };

    /// 表示一个二元运算符表达式
    class BinaryOpNode final : public ExprNode {
    public:
        BinaryOpNode(ExprNode *left, ExprNode *right, std::string op): ExprNode(new TypeNode(TypeNode::unknown),
                                                                           BinaryOpNodeType, ""), //延后到语义分析决定
                                                                       left(left), right(right), op(std::move(op)) {
        }

        ExprNode *left;
        ExprNode *right;
        std::string op;

        [[nodiscard]] bool isAssignOp() const {
            static std::unordered_set<std::string> ops = {
                "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="
            };
            return ops.contains(op);
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class ArgNode final : public SemNode {
    public:
        ArgNode(std::string name, TypeNode *type, AllocaNode *alloca): SemNode(ArgNodeType), name(std::move(name)),
                                                                       type(type) {
            this->alloca = alloca;
        }

        AllocaNode *alloca;

        std::string name;
        TypeNode *type;

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class FuncDefineNode final : public SemNode {
    public:
        FuncDefineNode(std::string name, TypeNode *returnType, BlockNode *body, const Modifier modifier,
                       const std::vector<ArgNode *> &args = {}): SemNode(FuncDefineNodeType), modifier(modifier),
                                                                 name(std::move(name)), body(body),
                                                                 returnType(returnType) {
            for (auto &i: args) {
                this->args.push_back(i);
            }
        }

        Modifier modifier;
        std::string name;
        std::vector<ArgNode *> args;
        BlockNode *body;
        TypeNode *returnType;
        llvm::Function *llvmFunction = nullptr;
        ClassDefineNode *theClass = nullptr;

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class ReturnNode final : public SemNode {
    public:
        ExprNode *value;

        ReturnNode(): SemNode(ReturnNodeType), value(nullptr) {
        }

        explicit ReturnNode(ExprNode *value): SemNode(ReturnNodeType), value(value) {
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class LiteralNode : public ExprNode {
    public:
        explicit LiteralNode(const SemNodeType semType, TypeNode *type): ExprNode(type, semType, "") {
        }

        [[nodiscard]] bool isLiteral() const override {
            return true;
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class IntegerLiteralNode final : public LiteralNode {
    public:
        int value;

        explicit IntegerLiteralNode(const int value, ProgramNode *root): LiteralNode(IntegerLiteralNodeType,
                                                                             new TypeNode("int")), value(value) {
            root->addSemNode(type);
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class FloatLiteralNode final : public LiteralNode {
    public:
        double value;

        explicit FloatLiteralNode(const double value, ProgramNode *root): LiteralNode(FloatLiteralNodeType,
                                                                              new TypeNode("float")), value(value) {
            root->addSemNode(type);
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class BoolLiteralNode final : public LiteralNode {
    public:
        bool value;

        explicit BoolLiteralNode(const bool value, ProgramNode *root): LiteralNode(BoolLiteralNodeType,
                                                                           new TypeNode("bool")), value(value) {
            root->addSemNode(type);
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class StringLiteralNode final : public LiteralNode {
    public:
        std::string value;

        explicit StringLiteralNode(std::string value, ProgramNode *root): LiteralNode(StringLiteralNodeType,
                                                                              new TypeNode("char*")),
                                                                          value(std::move(value)) {
            root->addSemNode(type);
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class AllocaNode final : public SemNode {
    public:
        TypeNode *type;
        llvm::Value *alloca = nullptr;

        explicit AllocaNode(TypeNode *type): SemNode(AllocaNodeType), type(type) {
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class VarDefineNode final : public SemNode {
    public:
        std::string name;
        TypeNode *type;
        ExprNode *value;
        AllocaNode *alloca;
        bool isGlobal = false;

        VarDefineNode(std::string name, ExprNode *value, TypeNode *type,
                      AllocaNode *alloca): SemNode(VarDefineNodeType), name(std::move(name)), type(type), value(value) {
            this->alloca = alloca;
        }

        std::any accept(SemNodeVisitor &visitor) override;

        [[nodiscard]] bool isAlloca() const override {
            return alloca != nullptr;
        }

        [[nodiscard]] AllocaNode *getAlloca() override {
            return alloca;
        }
    };

    class ObjectNode final : public ExprNode {
    public:
        void *s_obj = nullptr;
        void *g_obj = nullptr;
        bool isLoad = false;

        explicit ObjectNode(std::string name, TypeNode *type): ExprNode(type, ObjectNodeType, std::move(name)) {
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class FuncCallNode final : public ExprNode {
    public:
        std::vector<ExprNode *> args;

        explicit FuncCallNode(ProgramNode *root, std::string name, std::vector<ExprNode *> args = {}): ExprNode(
                new TypeNode(TypeNode::unknown), FuncCallNodeType, std::move(name)), args(std::move(args)) {
            root->addSemNode(type);
        }

        void *s_obj = nullptr;
        void *g_obj = nullptr;

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class IfNode final : public SemNode {
    public:
        ExprNode *condition;
        SemNode *then_body;
        SemNode *else_body;

        IfNode(ExprNode *condition, SemNode *then_body, SemNode *else_body): SemNode(IfNodeType), condition(condition),
                                                                             then_body(then_body),
                                                                             else_body(else_body) {
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class WhileNode final : public SemNode {
    public:
        ExprNode *condition;
        SemNode *body;

        WhileNode(ExprNode *condition, SemNode *body): SemNode(WhileNodeType), condition(condition), body(body) {
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class ForNode final : public SemNode {
    public:
        SemNode *init;
        ExprNode *condition;
        SemNode *increment;
        SemNode *body;

        ForNode(SemNode *init, ExprNode *cond, SemNode *incr, SemNode *body): SemNode(ForNodeType), init(init),
                                                                              condition(cond), increment(incr),
                                                                              body(body) {
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class ClassDefineNode final : public TypeNode {
        std::unordered_map<std::string, std::pair<VarDefineNode *, size_t> > member_map;
        std::unordered_map<std::string, FuncDefineNode *> function_map;

    public:
        std::string parentClass;
        std::vector<VarDefineNode *> members;
        std::vector<FuncDefineNode *> functions;

        explicit ClassDefineNode(const std::string &name): TypeNode(name, ClassDefineNodeType) {
        }

        void build() {
            if (member_map.size()!=members.size()) {
                member_map.clear();
                size_t count = 0;
                for (auto i: members) {
                    member_map.insert({i->name, {i, count++}});
                }
            }
            if (function_map.size()!=functions.size()) {
                function_map.clear();
                for (auto i: functions) {
                    function_map.insert({i->name, i});
                }
            }
        }

        std::pair<VarDefineNode *, size_t> getMember(const std::string &name) {
            const auto it = member_map.find(name);
            if (it == member_map.end()) {
                throw std::runtime_error("Member not found");
            }
            return it->second;
        }

        FuncDefineNode *&getFunction(const std::string &name) {
            const auto it = function_map.find(name);
            if (it == function_map.end()) {
                throw std::runtime_error("Function not found");
            }
            return it->second;
        }

        bool hasFunction(const std::string &name) const {
            return function_map.contains(name);
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class BlendNode final : public ExprNode {
    public:
        enum BlendType { Member, Module, Method, Unknown };

        BlendType blend_type;
        bool isLoad = false;
        ExprNode *parent;
        ExprNode *child;

        BlendNode(ExprNode *parent, ExprNode *child, ProgramNode *root,
                  const BlendType blend_type): ExprNode(new TypeNode(TypeNode::unknown), BlendNodeType, ""),
                                               blend_type(blend_type), parent(parent),
                                               child(child) {
            root->addSemNode(type);
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };
#pragma endregion

#pragma region SemNodeVisitor
    /// 访问者接口，后续可以用来做语义检查、类型推导等工作
    class SemNodeVisitor {
    public:
        virtual std::any visit(SemNode *node) {
            return node->accept(*this);
        }

        virtual std::any visitNode(SemNode *node) {
            return node->accept(*this);
        }

        virtual std::any visitProgram(ProgramNode *node) {
            std::any result;
            for (const auto &i: *node->body) {
                result = i->accept(*this);
            }
            return result;
        }

        virtual std::any visitBinaryOp(BinaryOpNode *node) {
            node->left->accept(*this);
            return node->right->accept(*this);
        }

        virtual std::any visitBlock(BlockNode *node) {
            std::any result;
            for (const auto &i: *node) {
                result = i->accept(*this);
            }
            return result;
        }

        virtual std::any visitArg(ArgNode *node) {
            return {};
        }

        virtual std::any visitFuncDefine(FuncDefineNode *node) {
            for (const auto &i: node->args) {
                i->accept(*this);
            }
            std::any result = node->body->accept(*this);
            return result;
        }

        virtual std::any visitPackage(PackageNode *node) {
            return {};
        }

        virtual std::any visitInteger(IntegerLiteralNode *node) {
            return {};
        }

        virtual std::any visitFloat(FloatLiteralNode *node) {
            return {};
        }

        virtual std::any visitBoolean(BoolLiteralNode *node) {
            return {};
        }

        virtual std::any visitString(StringLiteralNode *node) {
            return {};
        }

        virtual std::any visitVarDefine(VarDefineNode *node) {
            node->type->accept(*this);
            return node->value->accept(*this);
        }

        virtual std::any visitType(TypeNode *node) {
            return {};
        }

        virtual std::any visitObject(ObjectNode *node) {
            return {};
        }

        virtual std::any visitFuncCall(FuncCallNode *node) {
            for (const auto i: node->args) {
                i->accept(*this);
            }
            return {};
        }

        virtual std::any visitAlloca(AllocaNode *node) {
            return {};
        }

        virtual std::any visitIf(IfNode *node) {
            node->condition->accept(*this);
            node->then_body->accept(*this);
            if (node->else_body) {
                node->else_body->accept(*this);
            }
            return {};
        }

        virtual std::any visitWhile(WhileNode *node) {
            node->condition->accept(*this);
            node->body->accept(*this);
            return {};
        }

        virtual std::any visitFor(ForNode *node) {
            node->init->accept(*this);
            node->condition->accept(*this);
            node->increment->accept(*this);
            node->body->accept(*this);
            return {};
        }

        virtual std::any visitClassDefine(ClassDefineNode *node) {
            for (const auto i: node->members) {
                i->accept(*this);
            }
            for (const auto i: node->functions) {
                i->accept(*this);
            }
            return {};
        }

        virtual std::any visitReturn(ReturnNode *node) {
            if (node->value) node->value->accept(*this);
            return {};
        }

        virtual std::any visitBlend(BlendNode *node) {
            node->parent->accept(*this);
            node->child->accept(*this);
            return {};
        }

        virtual ~SemNodeVisitor() = default;
    };
#pragma endregion

#pragma region SemNodeAcceptImpl
    // 为各个节点实现 accept 方法
    inline std::any SemNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitNode(this);
    }

    inline std::any ProgramNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitProgram(this);
    }

    inline std::any BinaryOpNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitBinaryOp(this);
    }

    inline std::any BlockNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitBlock(this);
    }

    inline std::any FuncDefineNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitFuncDefine(this);
    }

    std::any ReturnNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitReturn(this);
    }

    inline std::any ArgNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitArg(this);
    }

    inline std::any PackageNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitPackage(this);
    }

    std::any TypeNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitType(this);
    }

    inline std::any LiteralNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitNode(this);
    }

    inline std::any IntegerLiteralNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitInteger(this);
    }

    inline std::any FloatLiteralNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitFloat(this);
    }

    inline std::any BoolLiteralNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitBoolean(this);
    }

    inline std::any StringLiteralNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitString(this);
    }

    std::any AllocaNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitAlloca(this);
    }

    inline std::any VarDefineNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitVarDefine(this);
    }

    inline std::any ObjectNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitObject(this);
    }

    inline std::any FuncCallNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitFuncCall(this);
    }

    std::any IfNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitIf(this);
    }

    std::any WhileNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitWhile(this);
    }

    std::any ForNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitFor(this);
    }

    std::any ClassDefineNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitClassDefine(this);
    }

    std::any BlendNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitBlend(this);
    }
#pragma endregion
} // namespace Riddle
