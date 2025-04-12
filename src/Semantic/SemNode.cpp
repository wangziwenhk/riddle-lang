module;
#include <any>
#include <vector>
module Semantic.SemNode;
namespace Riddle {
    std::any ProgramNode::accept(SemVisitor &visitor) {
        return visitor.visitProgram(this);
    }
    std::any IntegerNode::accept(SemVisitor &visitor) {
        return visitor.visitInteger(this);
    }
    std::any FloatNode::accept(SemVisitor &visitor) {
        return visitor.visitFloat(this);
    }
    std::any BooleanNode::accept(SemVisitor &visitor) {
        return visitor.visitBoolean(this);
    }
    std::any CharNode::accept(SemVisitor &visitor) {
        return visitor.visitChar(this);
    }
    std::any BlockNode::accept(SemVisitor &visitor) {
        return visitor.visitBlock(this);
    }
    std::any FuncDeclNode::accept(SemVisitor &visitor) {
        return visitor.visitFuncDecl(this);
    }
    std::any SemVisitor::visitProgram(ProgramNode *node) {
        for (const auto &i: node->children) {
            visit(i.get());
        }
        return {};
    }
    std::any SemVisitor::visitInteger(IntegerNode *node) {
        return {};
    }
    std::any SemVisitor::visitFloat(FloatNode *node) {
        return {};
    }
    std::any SemVisitor::visitBoolean(BooleanNode *node) {
        return {};
    }
    std::any SemVisitor::visitChar(CharNode *node) {
        return {};
    }
    std::any SemVisitor::visitFuncDecl(FuncDeclNode *node) {
        return {};
    }
    std::any SemVisitor::visitBlock(BlockNode *node) {
        for (const auto &i: node->children) {
            visit(i.get());
        }
        return {};
    }
} // namespace Riddle
