module;
#include <any>
#include <memory>
#include <typeindex>
#include <utility>
#include <vector>
export module Semantic.SemNode;
import Semantic.Type;
export namespace Riddle {
    class SemVisitor;
    class SemNode {
    public:
        static size_t staticHashCode() {
            return typeid(SemNode).hash_code();
        }

        virtual size_t hashCode() {
            return typeid(*this).hash_code();
        }

        virtual ~SemNode() = default;
        virtual std::any accept(SemVisitor &visitor) = 0;
    };

    class ProgramNode final : public SemNode {
    public:
        std::vector<std::shared_ptr<SemNode>> children;

        static auto create() {
            return std::make_shared<ProgramNode>();
        }

        std::any accept(SemVisitor &visitor) override;
    };

    class ExprNode : public SemNode {
    public:
        Type type;
    };


    class IntegerNode final : public ExprNode {
    protected:
        explicit IntegerNode(const int value): value(value) {
        }

    public:
        int value;

        static auto create(int value = 0) {
            return std::shared_ptr<IntegerNode>(new IntegerNode(value));
        }

        std::any accept(SemVisitor &visitor) override;
    };

    class FloatNode final : public ExprNode {
    protected:
        explicit FloatNode(const float value): value(value) {
        }

    public:
        float value;

        static auto create(const float value = 0) {
            return std::shared_ptr<FloatNode>(new FloatNode(value));
        }

        std::any accept(SemVisitor &visitor) override;
    };

    class BooleanNode final : public ExprNode {
    protected:
        explicit BooleanNode(const bool value): value(value) {
        }

    public:
        bool value;

        static auto create(const bool value) {
            return std::shared_ptr<BooleanNode>(new BooleanNode(value));
        }

        std::any accept(SemVisitor &visitor) override;
    };

    class CharNode final : public ExprNode {
    protected:
        explicit CharNode(const char value): value(value) {
        }

    public:
        char value;

        static auto create(const char value) {
            return std::shared_ptr<CharNode>(new CharNode(value));
        }

        std::any accept(SemVisitor &visitor) override;
    };

    class BlockNode final : public ExprNode {
    protected:
        explicit BlockNode(std::vector<std::shared_ptr<SemNode>> children): children(std::move(children)) {
        }

    public:
        std::vector<std::shared_ptr<SemNode>> children;

        static auto create(const std::vector<std::shared_ptr<SemNode>> &children = {}) {
            return std::shared_ptr<BlockNode>(new BlockNode(children));
        }

        std::any accept(SemVisitor &visitor) override;
    };

    //todo 添加函数参数
    class FuncDeclNode final : public SemNode {
    protected:
        explicit FuncDeclNode(std::string name, std::shared_ptr<BlockNode> children):
            name(std::move(name)), children(std::move(children)) {
        }

    public:
        std::string name;
        std::shared_ptr<BlockNode> children;

        static auto create(std::string name, std::shared_ptr<BlockNode> children = {}) {
            return std::shared_ptr<FuncDeclNode>(new FuncDeclNode(std::move(name), std::move(children)));
        }

        std::any accept(SemVisitor &visitor) override;
    };

    class SemVisitor {
    protected:
        ~SemVisitor() = default;

    public:
        virtual std::any visit(SemNode *node) {
            return node->accept(*this);
        }
        virtual std::any visitProgram(ProgramNode *node);
        virtual std::any visitInteger(IntegerNode *node);
        virtual std::any visitFloat(FloatNode *node);
        virtual std::any visitBoolean(BooleanNode *node);
        virtual std::any visitChar(CharNode *node);
        virtual std::any visitFuncDecl(FuncDeclNode *node);
        virtual std::any visitBlock(BlockNode *node);
    };
} // namespace Riddle
