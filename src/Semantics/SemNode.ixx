module;
#include <any>
#include <llvm/IR/Type.h>
#include <string>
#include <utility>
#include <vector>
export module Semantics.SemNode;
export namespace Riddle {
    class SemNodeVisitor;
#pragma region SemNode
    /// 表示一个语义树的节点
    class SemNode {
    public:
        // 存储节点类型用于 RTTI
        enum SemNodeType {
            ProgramNodeType,
            BinaryOpNodeType,
            FuncDefineNodeType,
            ArgNodeType,
            BlockNodeType,
            TypeType,

            IntegerLiteralNodeType,
            FloatLiteralNodeType,
        };

    protected:
        SemNodeType type;

    public:
        explicit SemNode(const SemNodeType type): type(type) {}
        virtual ~SemNode() = default;

        virtual std::any accept(SemNodeVisitor &visitor);

        [[nodiscard]] virtual bool isLiteral() const {
            return false;
        }
    };

    /// 保存一个代码块
    /// @example
    class BlockNode final : public SemNode {
    protected:
        std::vector<SemNode *> body;

    public:
        BlockNode(): SemNode(BlockNodeType), body({}) {}
        explicit BlockNode(const std::vector<SemNode *> &body): SemNode(BlockNodeType), body(body) {}

        std::vector<SemNode *> &getBody() {
            return body;
        }

        auto begin() { return body.begin(); }
        auto end() { return body.end(); }
        [[nodiscard]] auto begin() const { return body.cbegin(); }
        [[nodiscard]] auto end() const { return body.cend(); }

        [[nodiscard]] size_t size() const { return body.size(); }
        [[nodiscard]] bool empty() const { return body.empty(); }

        auto &operator[](const std::size_t i) { return body[i]; }
        const auto &operator[](const std::size_t i) const { return body[i]; }

        void clear() { body.clear(); }

        void push_back(SemNode *node) {
            body.push_back(node);
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    /// 表示一个程序根节点
    class ProgramNode final : public SemNode {
    protected:
        BlockNode *body;

    public:
        explicit ProgramNode(BlockNode *body): SemNode(ProgramNodeType), body(body) {}

        [[nodiscard]] BlockNode *getBody() const { return body; }
        std::any accept(SemNodeVisitor &visitor) override;
    };

    class PackageNode final : public SemNode {
    public:
        std::string packageName;
        explicit PackageNode(std::string packageName): SemNode(ProgramNodeType), packageName(std::move(packageName)) {}

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class Type final : public SemNode {
    protected:
        std::string name;

    public:
        explicit Type(std::string name): SemNode(TypeType), name(std::move(name)) {}
    };

    /// 表示一个二元运算符表达式
    class BinaryOpNode final : public SemNode {
    protected:
        SemNode *left;
        SemNode *right;
        std::string op;

    public:
        BinaryOpNode(SemNode *left, SemNode *right, std::string op): SemNode(BinaryOpNodeType), left(left), right(right), op(std::move(op)) {}

        SemNode *&getLeft() { return left; }
        SemNode *&getRight() { return right; }
        std::string &getOp() { return op; }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class ArgNode final : public SemNode {
    protected:
        std::string name;
        Type *type;

    public:
        ArgNode(std::string name, Type *type): SemNode(ArgNodeType), name(std::move(name)), type(type) {}

        std::string &getName() { return name; }
        Type *&getType() { return type; }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class FuncDefineNode final : public SemNode {
    protected:
        std::string name;
        std::vector<ArgNode *> args;
        BlockNode *body;
        Type *returnType;

    public:
        FuncDefineNode(std::string name,
                       BlockNode *body,
                       Type *returnType,
                       std::vector<ArgNode *> args = {}): SemNode(FuncDefineNodeType),
                                                          name(std::move(name)),
                                                          args(std::move(args)),
                                                          body(body),
                                                          returnType(returnType) {}

        std::string &getName() { return name; }
        std::vector<ArgNode *> &getArgs() { return args; }
        BlockNode *&getBody() { return body; }
        Type *&getReturnType() { return returnType; }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class LiteralNode : public SemNode {
    public:
        explicit LiteralNode(const SemNodeType type): SemNode(type) {}

        [[nodiscard]] bool isLiteral() const override {
            return true;
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class IntegerLiteralNode final : public LiteralNode {
    protected:
        int value;

    public:
        IntegerLiteralNode(): LiteralNode(IntegerLiteralNodeType), value(0) {}
        explicit IntegerLiteralNode(const int value): LiteralNode(IntegerLiteralNodeType), value(value) {}

        [[nodiscard]] int getValue() const { return value; }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class FloatLiteralNode final : public LiteralNode {
    protected:
        double value;

    public:
        FloatLiteralNode(): LiteralNode(FloatLiteralNodeType), value(0) {}
        explicit FloatLiteralNode(const double value): LiteralNode(FloatLiteralNodeType), value(value) {}

        [[nodiscard]] double getValue() const { return value; }

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
        virtual std::any visit(ProgramNode *node) {
            std::any result;
            for(const auto i: *node->getBody()) {
                result = i->accept(*this);
            }
            return result;
        }
        virtual std::any visit(BinaryOpNode *node) {
            node->getLeft()->accept(*this);
            return node->getRight()->accept(*this);
        }
        virtual std::any visit(BlockNode *node) {
            std::any result;
            for(const auto i: *node) {
                result = i->accept(*this);
            }
            return result;
        }
        virtual std::any visit(ArgNode *node) {
            return {};
        }
        virtual std::any visit(FuncDefineNode *node) {
            for(const auto i: node->getArgs()) {
                i->accept(*this);
            }
            std::any result = node->getBody()->accept(*this);
            return result;
        }
        virtual std::any visit(PackageNode *node) {
            return {};
        }
        virtual std::any visit(IntegerLiteralNode *node) {
            return {};
        }
        virtual ~SemNodeVisitor() = default;
    };
#pragma endregion

#pragma region SemNodeAcceptImpl
    // 为各个节点实现 accept 方法
    inline std::any SemNode::accept(SemNodeVisitor &visitor) {
        return visitor.visit(this);
    }

    inline std::any ProgramNode::accept(SemNodeVisitor &visitor) {
        return visitor.visit(this);
    }

    inline std::any BinaryOpNode::accept(SemNodeVisitor &visitor) {
        return visitor.visit(this);
    }

    inline std::any BlockNode::accept(SemNodeVisitor &visitor) {
        return visitor.visit(this);
    }

    inline std::any FuncDefineNode::accept(SemNodeVisitor &visitor) {
        return visitor.visit(this);
    }

    inline std::any ArgNode::accept(SemNodeVisitor &visitor) {
        return visitor.visit(this);
    }

    inline std::any PackageNode::accept(SemNodeVisitor &visitor) {
        return visitor.visit(this);
    }

    inline std::any LiteralNode::accept(SemNodeVisitor &visitor) {
        return visitor.visit(this);
    }

    inline std::any IntegerLiteralNode::accept(SemNodeVisitor &visitor) {
        return visitor.visit(this);
    }

    inline std::any FloatLiteralNode::accept(SemNodeVisitor &visitor) {
        return visitor.visit(this);
    }

#pragma endregion
}// namespace Riddle