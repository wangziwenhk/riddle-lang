module;
#include <string>
#include <utility>
#include <vector>
export module Semantics.SemNode;
export namespace Riddle {
    /// 表示一个语义节点的的最终结果类型
    class ExprType {
    public:
        enum ExprTypeID {
            /// base type
            IntegerTyID,
            FloatTyID,
            DoubleTyID,
            BooleanTyID,
            VoidTyID,

            /// 类类型
            ClassTyID,
        };

    };
    /// 表示一个语义树的节点
    class SemNode {
    public:
        // 存储节点类型用于 RTTI
        enum SemNodeType {
            ProgramNodeType,

            // 表达式
            BinaryOpNodeType,
        };

    protected:
        SemNodeType type;

    public:
        explicit SemNode(const SemNodeType type): type(type) {}
    };

    /// 表示一个程序根节点
    class ProgramNode final : public SemNode {
    protected:
        std::vector<SemNodeType *> body;

    public:
        ProgramNode(): SemNode(ProgramNodeType), body({}) {}
        explicit ProgramNode(const std::vector<SemNodeType *> &body): SemNode(ProgramNodeType), body(body) {}

        void push_back(SemNodeType *node) {
            body.push_back(node);
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
    };

    /// 表示一个二元运算符表达式
    class BinaryOpNode final : public SemNode {
    protected:
        SemNode *left;
        SemNode *right;
        std::string op;

    public:
        BinaryOpNode(SemNode *left, SemNode *right, std::string op): SemNode(BinaryOpNodeType), left(left), right(right), op(std::move(op)) {}

        [[nodiscard]] SemNode *getLeft() const { return left; }
        [[nodiscard]] SemNode *getRight() const { return right; }
        [[nodiscard]] std::string getOp() const { return op; }
    };
}// namespace Riddle