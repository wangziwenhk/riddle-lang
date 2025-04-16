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
    std::any ObjectNode::accept(SemVisitor &visitor) {
        return visitor.visitObject(this);
    }
    std::any TypeNode::accept(SemVisitor &visitor) {
        return visitor.visitType(this);
    }
    std::any ArgDeclNode::accept(SemVisitor &visitor) {
        return visitor.visitArgDecl(this);
    }
    std::any ArgDeclListNode::accept(SemVisitor &visitor) {
        return visitor.visitArgDeclList(this);
    }
    std::any FuncDeclNode::accept(SemVisitor &visitor) {
        return visitor.visitFuncDecl(this);
    }
    std::any VarDeclNode::accept(SemVisitor &visitor) {
        return visitor.visitVarDecl(this);
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
    std::any SemVisitor::visitObject(ObjectNode *node) {
        return {};
    }
    std::any SemVisitor::visitArgDecl(ArgDeclNode *node) {
        return {};
    }
    std::any SemVisitor::visitArgDeclList(ArgDeclListNode *node) {
        for (const auto &i: node->children) {
            visit(i.get());
        }
        return {};
    }
    std::any SemVisitor::visitType(TypeNode *node) {
        return {};
    }
    std::any SemVisitor::visitVarDecl(VarDeclNode *node) {
        return {};
    }


} // namespace Riddle
