module;
module Semantic.SemNode;
namespace Riddle {
    std::any ProgramNode::accept(SemVisitor &visitor) { // NOLINT(*-make-member-function-const)
        return visitor.visitProgram(this);
    }
    std::any FunctionDecl::accept(SemVisitor &visitor) {
        return visitor.visitFunctionDecl(this);
    }
} // namespace Riddle
