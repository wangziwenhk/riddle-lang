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
        };

    protected:
        SemNodeType semType;

    public:
        explicit SemNode(const SemNodeType type): semType(type) {}
        virtual ~SemNode() = default;

        virtual std::any accept(SemNodeVisitor &visitor);

        [[nodiscard]] virtual bool isLiteral() const {
            return false;
        }

        [[nodiscard]] SemNodeType getSemType() const {
            return semType;
        }
    };

    /// 保存一个代码块
    /// @example
    class BlockNode final : public SemNode {
    public:
        BlockNode(): SemNode(BlockNodeType), body({}) {}
        explicit BlockNode(const std::vector<SemNode *> &vec)
            : SemNode(BlockNodeType) {
            body.reserve(vec.size());
            for(const auto ptr: vec) {
                body.push_back(std::shared_ptr<SemNode>(ptr));
            }
        }

        std::vector<std::shared_ptr<SemNode>> body;

        auto begin() { return body.begin(); }
        auto end() { return body.end(); }
        [[nodiscard]] auto begin() const { return body.cbegin(); }
        [[nodiscard]] auto end() const { return body.cend(); }

        void push_back(SemNode *node) {
            body.push_back(std::shared_ptr<SemNode>(node));
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    /// 表示一个程序根节点
    class ProgramNode final : public SemNode {
    public:
        explicit ProgramNode(BlockNode *body): SemNode(ProgramNodeType), body(body) {}

        std::shared_ptr<BlockNode> body;

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class PackageNode final : public SemNode {
    public:
        std::string packageName;
        explicit PackageNode(std::string packageName): SemNode(ProgramNodeType), packageName(std::move(packageName)) {}

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class TypeNode final : public SemNode {
    public:
        explicit TypeNode(std::string name): SemNode(TypeNodeType), name(std::move(name)) {}

        std::string name;

        std::any accept(SemNodeVisitor &visitor) override;
    };

    /// 保存有值的 Node
    class ExprNode : public SemNode {
    protected:
        std::shared_ptr<TypeNode> type;

    public:
        ExprNode(TypeNode *type, const SemNodeType semType): SemNode(semType), type(type) {}

        [[nodiscard]] TypeNode *getType() const {
            return type.get();
        }
    };

    /// 表示一个二元运算符表达式
    class BinaryOpNode final : public ExprNode {
    public:
        BinaryOpNode(SemNode *left,
                     SemNode *right,
                     std::string op): ExprNode(new TypeNode("@UnKnown"), BinaryOpNodeType),//延后到语义分析决定
                                      left(left), right(right), op(std::move(op)) {}

        std::shared_ptr<SemNode> left;
        std::shared_ptr<SemNode> right;
        std::string op;

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class ArgNode final : public SemNode {
    public:
        ArgNode(std::string name, TypeNode *type): SemNode(ArgNodeType), name(std::move(name)), type(type) {}

        std::string name;
        std::shared_ptr<TypeNode> type;

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class FuncDefineNode final : public SemNode {
    public:
        FuncDefineNode(std::string name,
                       BlockNode *body,
                       TypeNode *returnType,
                       const std::vector<ArgNode *> &args = {}): SemNode(FuncDefineNodeType),
                                                                 name(std::move(name)),
                                                                 body(body),
                                                                 returnType(returnType) {
            for(auto &i: args) {
                this->args.push_back(std::shared_ptr<ArgNode>(i));
            }
        }

        std::string name;
        std::vector<std::shared_ptr<ArgNode>> args;
        std::shared_ptr<BlockNode> body;
        std::shared_ptr<TypeNode> returnType;

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class LiteralNode : public ExprNode {
    public:
        explicit LiteralNode(const SemNodeType semType, TypeNode *type): ExprNode(type, semType) {}

        [[nodiscard]] bool isLiteral() const override {
            return true;
        }

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class IntegerLiteralNode final : public LiteralNode {
    public:
        int value;

        explicit IntegerLiteralNode(const int value): LiteralNode(IntegerLiteralNodeType, new TypeNode("int")), value(value) {}

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class FloatLiteralNode final : public LiteralNode {
    public:
        double value;

        explicit FloatLiteralNode(const double value): LiteralNode(FloatLiteralNodeType, new TypeNode("float")), value(value) {}

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class BoolLiteralNode final : public LiteralNode {
    public:
        bool value;

        explicit BoolLiteralNode(const bool value): LiteralNode(BoolLiteralNodeType, new TypeNode("bool")), value(value) {}

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class StringLiteralNode final : public LiteralNode {
    public:
        std::string value;

        explicit StringLiteralNode(std::string value): LiteralNode(StringLiteralNodeType, new TypeNode("char*")), value(std::move(value)) {}

        std::any accept(SemNodeVisitor &visitor) override;
    };

    class VarDefineNode final : public SemNode {
    public:
        std::string name;
        std::shared_ptr<TypeNode> type;
        std::shared_ptr<SemNode> value;

        VarDefineNode(std::string name,
                      SemNode *value,
                      TypeNode *type): SemNode(VarDefineNodeType),
                                       name(std::move(name)),
                                       type(type),
                                       value(value) {}

        std::any accept(SemNodeVisitor &visitor) override;
    };
#pragma endregion

#pragma region SemNodeVisitor
    /// 访问者接口，后续可以用来做语义检查、类型推导等工作
    class SemNodeVisitor {
    public:
        virtual std::any visit(SemNode* node) {
            return node->accept(*this);
        }
        virtual std::any visitNode(SemNode *node) {
            return node->accept(*this);
        }
        virtual std::any visitProgram(ProgramNode *node) {
            std::any result;
            for(const auto& i: *node->body) {
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
            for(const auto& i: *node) {
                result = i->accept(*this);
            }
            return result;
        }
        virtual std::any visitArgNode(ArgNode *node) {
            return {};
        }
        virtual std::any visitFuncDefine(FuncDefineNode *node) {
            for(const auto &i: node->args) {
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

    inline std::any ArgNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitArgNode(this);
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

    inline std::any VarDefineNode::accept(SemNodeVisitor &visitor) {
        return visitor.visitVarDefine(this);
    }
#pragma endregion
}// namespace Riddle