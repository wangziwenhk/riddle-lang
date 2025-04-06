module;
#include <any>
#include <string>
#include <utility>
#include <vector>
export module Semantic.SemNode;
export namespace Riddle {
    class SemVisitor;
    class SemNode {
    public:
        virtual ~SemNode() = default;

        virtual std::any accept(SemVisitor &visitor) = 0;
    };

    class ProgramNode final : public SemNode {
        std::vector<SemNode *> allocator;

    public:
        std::vector<SemNode *> children;

        ~ProgramNode() override {
            for (const auto &child: allocator) {
                delete child;
            }
        }

        void addToAllocator(SemNode *node) {
            allocator.emplace_back(node);
        }

        std::any accept(SemVisitor &visitor) override;
    };

    class TypeNode;

    /**
     * 表示一个值
     */
    class ExprNode : public SemNode {
    public:
        TypeNode *type;
    };

    /**
     *
     */
    class TypeNode final : public ExprNode {
    public:
        std::string name;
    };

    /**
     * 函数声明
     */
    class FunctionDecl final : public SemNode {
    protected:
        explicit FunctionDecl(std::string name): name(std::move(name)) {
        }

    public:
        std::string name;

        static FunctionDecl *create(ProgramNode *program, std::string name) {
            const auto node = new FunctionDecl(std::move(name));
            program->addToAllocator(node);
            return node;
        }

        std::any accept(SemVisitor &visitor) override;
    };

    class SemVisitor {
    public:
        std::any visit(SemNode *node) {
            return node->accept(*this);
        }

        std::any visitProgram(const ProgramNode *node) {
            for (const auto child: node->children) {
                visit(child);
            }
            return {};
        }

        std::any visitFunctionDecl(const FunctionDecl *node) {
            return {};
        }
    };
} // namespace Riddle
