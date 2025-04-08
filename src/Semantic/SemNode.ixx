module;
#include <any>
#include <llvm/IR/Type.h>
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
        TypeNode *type{};
    };

    /**
     *
     */
    class TypeNode final : public ExprNode {
    protected:
        explicit TypeNode(std::string name): name(std::move(name)) {
        }

    public:
        enum Select {
            Global, ///< 该 Type 需要在作用域中查找
            Local, ///< 该 Type 依赖其他的 Type
            Unknown,
        };

        Select select = Unknown;

        static TypeNode *create(ProgramNode *program, const std::string &name) {
            const auto ptr = new TypeNode(name);
            program->addToAllocator(ptr);
            return ptr;
        }

        // ReSharper disable once CppDFANotInitializedField
        std::string name;

        std::any accept(SemVisitor &visitor) override;
    };

    class BlockNode final : public ExprNode {
        explicit BlockNode(std::vector<SemNode *> children): children(std::move(children)) {
        }

    public:
        std::vector<SemNode *> children;

        static BlockNode *create(ProgramNode *program, const std::vector<SemNode *> &&children = {}) {
            const auto ptr = new BlockNode(children);
            program->addToAllocator(ptr);
            return ptr;
        }

        std::any accept(SemVisitor &visitor) override;
    };

    class DeclArgNode final : public SemNode {
    protected:
        DeclArgNode(std::string name, TypeNode *type): name(std::move(name)), type(type) {
        }

    public:
        std::string name;
        TypeNode *type;

        static DeclArgNode *create(ProgramNode *program, const std::string &name, TypeNode *type) {
            const auto ptr = new DeclArgNode(name, type);
            program->addToAllocator(ptr);
            return ptr;
        }

        std::any accept(SemVisitor &visitor) override;
    };

    class DeclArgListNode final : public SemNode {
    protected:
        explicit DeclArgListNode(std::vector<DeclArgNode *> children = {}): children(std::move(children)) {
        }

    public:
        std::vector<DeclArgNode *> children;

        static DeclArgListNode *create(ProgramNode *program, const std::vector<DeclArgNode *> &&children = {}) {
            const auto ptr = new DeclArgListNode(children);
            program->addToAllocator(ptr);
            return ptr;
        }

        std::any accept(SemVisitor &visitor) override;
    };

    /**
     * 函数声明
     */
    class FunctionDecl final : public SemNode {
    protected:
        explicit FunctionDecl(std::string name, BlockNode *body, DeclArgListNode *args):
            name(std::move(name)), body(body), args(args) {
        }

    public:
        // ReSharper disable once CppDFANotInitializedField
        std::string name;
        BlockNode *body;
        DeclArgListNode *args;

        static FunctionDecl *create(ProgramNode *program, const std::string_view name, BlockNode *body,
                                    DeclArgListNode *args) {
            const auto node = new FunctionDecl(name.data(), body, args);
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
            visit(node->body);
            return {};
        }

        std::any visitType(const TypeNode *node) {
            return {};
        }

        std::any visitBlock(const BlockNode *node) {
            for (const auto child: node->children) {
                visit(child);
            }
            return {};
        }

        std::any visitDeclArgList(const DeclArgListNode *node) {
            for (const auto child: node->children) {
                visit(child);
            }
            return {};
        }

        std::any visitDeclArg(const DeclArgNode *node) {
            return {};
        }
    };
} // namespace Riddle
