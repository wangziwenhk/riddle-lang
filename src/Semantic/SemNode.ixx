// ReSharper disable CppMemberFunctionMayBeStatic
// ReSharper disable CppDFAMemoryLeak
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

        virtual SemNode *clone() = 0;
    };

    class ProgramNode final : public SemNode {
        std::vector<SemNode *> allocator;

    public:
        std::vector<SemNode *> children;

        ~ProgramNode() override {
            for (const auto &child: allocator) {
                delete child;
            }
            allocator.clear();
            children.clear();
        }

        void addToAllocator(SemNode *node) {
            allocator.emplace_back(node);
        }

        std::any accept(SemVisitor &visitor) override;

        SemNode *clone() override {
            return new ProgramNode(*this);
        }
    };

    class TypeNode;
    class UndefExprNode;

    /**
     * 表示一个值
     */
    class ExprNode : public SemNode {
    protected:
        explicit ExprNode(TypeNode *type): type(type) {
        }

    public:
        TypeNode *type;
    };

    /**
     *
     */
    class TypeNode final : public ExprNode {
    protected:
        explicit TypeNode(std::string name): ExprNode(nullptr), name(std::move(name)) {
        }

    public:
        enum Select {
            Global, ///< 该 Type 需要在作用域中查找
            Local, ///< 该 Type 依赖其他的 Type
            Unknown,
        };

        static constexpr std::string nil = "@nil";
        static constexpr std::string unknown = "@ukn";

        Select select = Unknown;

        static TypeNode *create(ProgramNode *program, const std::string &name) {
            const auto ptr = new TypeNode(name);
            program->addToAllocator(ptr);
            return ptr;
        }

        static TypeNode *createNil(ProgramNode *program) {
            return create(program, nil);
        }

        static TypeNode *createUnknown(ProgramNode *program) {
            return create(program, unknown);
        }

        // ReSharper disable once CppDFANotInitializedField
        std::string name;

        std::any accept(SemVisitor &visitor) override;

        SemNode *clone() override {
            return new TypeNode(*this);
        }
    };

    /**
     * 仅用于表示空对象，和 null 有所不同
     */
    class UndefExprNode final : public ExprNode {
    protected:
        explicit UndefExprNode(TypeNode *type): ExprNode(type) {
        }

    public:
        static UndefExprNode *create(ProgramNode *program) {
            const auto ptr = new UndefExprNode(TypeNode::createNil(program));
            program->addToAllocator(ptr);
            return ptr;
        }

        std::any accept(SemVisitor &visitor) override {
            return {};
        }

        SemNode *clone() override {
            return new UndefExprNode(*this);
        }
    };

    class IntegerNode final : public ExprNode {
    protected:
        explicit IntegerNode(const int value, TypeNode *type): ExprNode(type), value(value) {
        }

    public:
        int value;

        static IntegerNode *create(ProgramNode *program, const int value) {
            const auto ptr = new IntegerNode(value, TypeNode::create(program, "int"));
            program->addToAllocator(ptr);
            return ptr;
        }

        std::any accept(SemVisitor &visitor) override;

        SemNode *clone() override {
            return new IntegerNode(*this);
        }
    };

    class FloatNode final : public ExprNode {
    protected:
        explicit FloatNode(const float value, TypeNode *type): ExprNode(type), value(value) {
        }

    public:
        float value;
        static FloatNode *create(ProgramNode *program, const float value) {
            const auto ptr = new FloatNode(value, TypeNode::create(program, "float"));
            program->addToAllocator(ptr);
            return ptr;
        }

        std::any accept(SemVisitor &visitor) override;

        SemNode *clone() override {
            return new FloatNode(*this);
        }
    };

    class BlockNode final : public ExprNode {
        explicit BlockNode(std::vector<SemNode *> children, TypeNode *type):
            ExprNode(type), children(std::move(children)) {
            this->type = type;
        }

    public:
        std::vector<SemNode *> children;

        static BlockNode *create(ProgramNode *program, const std::vector<SemNode *> &&children = {}) {
            const auto type_ptr = TypeNode::createUnknown(program);
            const auto ptr = new BlockNode(children, type_ptr);
            program->addToAllocator(ptr);
            return ptr;
        }

        std::any accept(SemVisitor &visitor) override;

        SemNode *clone() override {
            return new BlockNode(*this);
        }
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

        SemNode *clone() override {
            return new DeclArgNode(*this);
        }
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

        SemNode *clone() override {
            return new DeclArgListNode(*this);
        }
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

        SemNode *clone() override {
            return new FunctionDecl(*this);
        }
    };

    class ReturnNode final : public SemNode {
    protected:
        explicit ReturnNode(ExprNode *result): result(result) {
        }

    public:
        ExprNode *result;

        static ReturnNode *create(ProgramNode *program, ExprNode *result) {
            const auto ptr = new ReturnNode(result);
            program->addToAllocator(ptr);
            return ptr;
        }

        std::any accept(SemVisitor &visitor) override;

        SemNode *clone() override {
            return new ReturnNode(*this);
        }
    };

    class AllocaNode final : public SemNode {
    protected:
        explicit AllocaNode(TypeNode *type): type(type) {
        }

    public:
        TypeNode *type;

        static AllocaNode *create(ProgramNode *program, TypeNode *type) {
            const auto ptr = new AllocaNode(type);
            program->addToAllocator(ptr);
            return ptr;
        }

        std::any accept(SemVisitor &visitor) override;
        SemNode *clone() override {
            return new AllocaNode(*this);
        }
    };

#undef alloca

    class VarDecl final : public SemNode {
        explicit VarDecl(std::string name, TypeNode *type, AllocaNode *alloca, ExprNode *value):
            value(value), type(type), alloca(alloca), name(std::move(name)) {
        }

    public:
        ExprNode *value;
        TypeNode *type;
        AllocaNode *alloca;
        std::string name;

        static VarDecl *create(ProgramNode *program, const std::string &name, TypeNode *type,
                               ExprNode *value = nullptr) {
            if (!value) {
                value = UndefExprNode::create(program);
            }
            const auto ptr = new VarDecl(name, type, AllocaNode::create(program, type), value);

            program->addToAllocator(ptr);
            return ptr;
        }

        std::any accept(SemVisitor &visitor) override;
        SemNode *clone() override {
            return new VarDecl(*this);
        }
    };

    class SemVisitor {
    protected:
        ~SemVisitor() = default;

    public:
        virtual std::any visit(SemNode *node) {
            return node->accept(*this);
        }

        virtual std::any visitProgram(const ProgramNode *node) {
            for (const auto child: node->children) {
                visit(child);
            }
            return {};
        }

        virtual std::any visitFunctionDecl(const FunctionDecl *node) {
            visit(node->body);
            return {};
        }

        virtual std::any visitType(const TypeNode *node) {
            return {};
        }

        virtual std::any visitBlock(const BlockNode *node) {
            for (const auto child: node->children) {
                visit(child);
            }
            return {};
        }

        virtual std::any visitDeclArgList(const DeclArgListNode *node) {
            for (const auto child: node->children) {
                visit(child);
            }
            return {};
        }

        virtual std::any visitDeclArg(const DeclArgNode *node) {
            return {};
        }

        virtual std::any visitInteger(const IntegerNode *node) {
            return {};
        }

        virtual std::any visitFloat(const FloatNode *node) {
            return {};
        }

        virtual std::any visitReturn(const ReturnNode *node) {
            return {};
        }

        virtual std::any visitVarDecl(const VarDecl *node) {
            visit(node->type);
            if (node->value) {
                visit(node->value);
            }
            return {};
        }

        virtual std::any visitAlloca(const AllocaNode *node) {
            return {};
        }
    };
} // namespace Riddle
