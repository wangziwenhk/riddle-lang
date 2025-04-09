module;
#include <any>
module Semantic.SemNode;
namespace Riddle {
    std::any ProgramNode::accept(SemVisitor &visitor) { // NOLINT(*-make-member-function-const)
        return visitor.visitProgram(this);
    }
    std::any IntegerNode::accept(SemVisitor &visitor) {
        return visitor.visitInteger(this);
    }
    std::any FloatNode::accept(SemVisitor &visitor) {
        return visitor.visitFloat(this);
    }
    std::any TypeNode::accept(SemVisitor &visitor) {
        return visitor.visitType(this);
    }
    std::any BlockNode::accept(SemVisitor &visitor) {
        return visitor.visitBlock(this);
    }
    std::any DeclArgNode::accept(SemVisitor &visitor) {
        return visitor.visitDeclArg(this);
    }
    std::any DeclArgListNode::accept(SemVisitor &visitor) {
        return visitor.visitDeclArgList(this);
    }
    std::any FunctionDecl::accept(SemVisitor &visitor) {
        return visitor.visitFunctionDecl(this);
    }
    std::any ReturnNode::accept(SemVisitor &visitor) {
        return visitor.visitReturn(this);
    }
    std::any AllocaNode::accept(SemVisitor &visitor) {
        return visitor.visitAlloca(this);
    }
    std::any VarDecl::accept(SemVisitor &visitor) {
        return visitor.visitVarDecl(this);
    }
} // namespace Riddle
