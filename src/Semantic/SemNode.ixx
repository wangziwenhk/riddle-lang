module;
#include <any>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Value.h>
#include <memory>
#include <typeindex>
#include <unordered_set>
#include <utility>
#include <vector>
export module Semantic.SemNode;
import Semantic.ValueType;
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
        std::shared_ptr<ValueType> type = ValueType::create();

        llvm::Value *llvm_value = nullptr;
    };

    class IntegerNode final : public ExprNode {
    protected:
        explicit IntegerNode(const int value): value(value) {
        }

    public:
        int value;

        static auto create(const int value = 0) {
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

    class ObjectNode : public ExprNode {
    protected:
        explicit ObjectNode(std::string name): name(std::move(name)) {
        }

    public:
        enum Select {
            Unknown,
            Global,
            Local,
            Base,
        };

        Select select = Unknown;
        std::string name;

        static auto create(const std::string &name) {
            return std::shared_ptr<ObjectNode>(new ObjectNode(name));
        }

        std::any accept(SemVisitor &visitor) override;
    };

    /// 这里仅仅表示 Type 的字面化形式，不做解析处理，依靠 ObjectNode 的相关解析
    /// 其解析获得依靠其 type 中的 类型选择器
    class TypeNode final : public ObjectNode {
    public:
        explicit TypeNode(std::string name): ObjectNode(std::move(name)) {
            while (this->name.back() == '*') {
                pointerSize++;
                this->name.pop_back();
            }
        }

    public:
        static auto create(const std::string &name) {
            return std::make_shared<TypeNode>(name);
        }

        size_t pointerSize = 0;

        std::any accept(SemVisitor &visitor) override;
    };

    class ArgDeclNode final : public SemNode {
    protected:
        explicit ArgDeclNode(std::string name, const std::shared_ptr<TypeNode> &type):
            name(std::move(name)), type(type) {
        }

    public:
        std::string name;
        std::shared_ptr<TypeNode> type;

        static auto create(const std::string &name, const std::shared_ptr<TypeNode> &type) {
            return std::shared_ptr<ArgDeclNode>(new ArgDeclNode(name, type));
        }

        [[nodiscard]] std::shared_ptr<ValueType> getGenType() const {
            return type->type;
        }

        std::any accept(SemVisitor &visitor) override;
    };

    class ArgDeclListNode final : public SemNode {
    protected:
        explicit ArgDeclListNode(const std::vector<std::shared_ptr<ArgDeclNode>> &children): children(children) {
        }

    public:
        std::vector<std::shared_ptr<ArgDeclNode>> children;

        static auto create(const std::vector<std::shared_ptr<ArgDeclNode>> &children = {}) {
            return std::shared_ptr<ArgDeclListNode>(new ArgDeclListNode(children));
        }

        std::any accept(SemVisitor &visitor) override;
    };


    class FuncDeclNode final : public SemNode {
    protected:
        explicit FuncDeclNode(std::string name, const std::shared_ptr<TypeNode> &returnType,
                              std::shared_ptr<BlockNode> children, const std::shared_ptr<ArgDeclListNode> &args):
            name(std::move(name)), children(std::move(children)), args(args), returnType(returnType) {
        }

    public:
        llvm::FunctionType *funcTy = nullptr;
        llvm::Function *func = nullptr;
        std::string name;
        std::shared_ptr<BlockNode> children;
        std::shared_ptr<ArgDeclListNode> args;
        std::shared_ptr<TypeNode> returnType;

        static auto create(std::string name, const std::shared_ptr<TypeNode> &returnType,
                           std::shared_ptr<BlockNode> children, const std::shared_ptr<ArgDeclListNode> &args) {
            return std::shared_ptr<FuncDeclNode>(
                    new FuncDeclNode(std::move(name), returnType, std::move(children), args));
        }

        std::any accept(SemVisitor &visitor) override;
    };

    class VarDeclNode final : public SemNode {
    protected:
        explicit VarDeclNode(std::string name, std::shared_ptr<TypeNode> type, std::shared_ptr<ExprNode> value):
            name(std::move(name)), type(std::move(type)), value(std::move(value)) {
        }

    public:
        std::string name;
        std::shared_ptr<TypeNode> type;
        std::shared_ptr<ExprNode> value;

        static auto create(std::string name, std::shared_ptr<TypeNode> type,
                           std::shared_ptr<ExprNode> value = nullptr) {
            return std::shared_ptr<VarDeclNode>(new VarDeclNode(std::move(name), std::move(type), std::move(value)));
        }

        /// 这里是获取该变量生成的实际类型，来自 Type-> type，当  antlr 中没有该 Type 时将使用 value->type
        [[nodiscard]] std::shared_ptr<ValueType> getGenType() const {
            return type->type;
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
        virtual std::any visitObject(ObjectNode *node);
        virtual std::any visitArgDecl(ArgDeclNode *node);
        virtual std::any visitArgDeclList(ArgDeclListNode *node);
        virtual std::any visitType(TypeNode *node);
        virtual std::any visitVarDecl(VarDeclNode *node);
    };
} // namespace Riddle
