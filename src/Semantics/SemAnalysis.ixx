module;
#include <any>
#include <format>
#include <ranges>
#include <stdexcept>
#include <vector>
export module Semantics.SemAnalysis;
import Semantics.SemNode;
import Semantics.SemContext;
export namespace Riddle {
    // 语义分析补全 Unknown 的代码
    class SemAnalysis final : public SemNodeVisitor {
    protected:
        SemContext context;
        ProgramNode *root = nullptr;

    public:
        std::any visitProgram(ProgramNode *node) override {
            context.push();
            root = node;
            for(const auto &i: *node->body) {
                visit(i);
            }
            context.pop();
            return {};
        }

        std::any visitVarDefine(VarDefineNode *node) override {
            const auto obj = new SemVariable(node);
            context.addSemObject(obj);
            if(node->value) {
                visit(node->value);
            }
            if(node->type->isUnknown()) {
                if(node->value != nullptr) {
                    *node->type = *node->value->getType();
                } else {
                    throw std::runtime_error("Null VarDefine");
                }
            } else if(node->value && *node->type != *node->value->getType()) {
                throw std::runtime_error("Type mismatch");
            }
            return {};
        }


        // 处理 Object 的类型
        std::any visitObject(ObjectNode *node) override {
            // 这里仅做类型处理
            if(node->getType()->isUnknown()) {
                const auto obj = context.getSemObject(node->name);
                if(obj == nullptr) {
                    throw std::runtime_error("Null Object");
                }
                if(obj->getSemObjType() != SemObject::Variable) {
                    throw std::runtime_error("Object is not a variable");
                }
                const auto var = dynamic_cast<SemVariable *>(obj);
                if(var->is_arg) {
                    node->isLoad = false;
                }
                *node->getType() = *var->getType();

                return {};
            }
            return {};
        }

        std::any visitClassDefine(ClassDefineNode *node) override {
            if(!node->parentClass.empty()) {
                const auto obj = context.getSemObject(node->parentClass);
                if(obj == nullptr) {
                    throw std::runtime_error("Null ClassDefine");
                }
                if(obj->getSemObjType() != SemObject::Class) {
                    throw std::runtime_error("Object is not a class");
                }
                const SemClass *parentClass = dynamic_cast<SemClass *>(obj);
                // 拷贝成员定义
                node->members.insert(node->members.begin(), parentClass->define->members.begin(), parentClass->define->members.end());
                // 拷贝函数定义
                for(auto i: parentClass->define->functions) {
                    node->functions.insert(i);
                }
            }
            const auto obj = new SemClass(node);
            context.addSemObject(obj);
            context.push();
            for(const auto i: node->members) {
                visit(i);
            }
            context.pushClass(obj);
            for(const auto i: node->functions | std::views::values) {
                visit(i);
            }
            context.popClass();
            context.pop();
            return {};
        }

        static void visitPreAlloca(SemNode *node, const FuncDefineNode *func) {
            switch(node->getSemType()) {
                case SemNode::BlockNodeType: {
                    auto block = dynamic_cast<BlockNode *>(node)->body;
                    for(const auto i: block) {
                        visitPreAlloca(i, func);
                    }
                    return;
                }
                case SemNode::VarDefineNodeType: {
                    const auto var = dynamic_cast<VarDefineNode *>(node);
                    func->body->body.insert(func->body->begin(), var->alloca);
                    return;
                }
                case SemNode::FuncDefineNodeType: {
                    visitPreAlloca(dynamic_cast<FuncDefineNode *>(node)->body, func);
                    return;
                }
                case SemNode::IfNodeType: {
                    const auto it = dynamic_cast<IfNode *>(node);
                    visitPreAlloca(it->condition, func);
                    visitPreAlloca(it->then_body, func);
                    if(it->else_body) {
                        visitPreAlloca(it->else_body, func);
                    }
                    return;
                }
                case SemNode::WhileNodeType: {
                    const auto it = dynamic_cast<WhileNode *>(node);
                    visitPreAlloca(it->condition, func);
                    visitPreAlloca(it->body, func);
                    return;
                }
                case SemNode::BinaryOpNodeType: {
                    const auto it = dynamic_cast<BinaryOpNode *>(node);
                    visitPreAlloca(it->left, func);
                    visitPreAlloca(it->right, func);
                    return;
                }
                case SemNode::ForNodeType: {
                    const auto it = dynamic_cast<ForNode *>(node);
                    visitPreAlloca(it->init, func);
                    visitPreAlloca(it->condition, func);
                    visitPreAlloca(it->increment, func);
                    visitPreAlloca(it->body, func);
                    return;
                }
                default:
                    break;
            }
        }

        std::any visitArg(ArgNode *node) override {
            const auto obj = new SemVariable(node);
            context.addSemObject(obj);
            return {};
        }

        std::any visitFuncDefine(FuncDefineNode *node) override {
            const auto obj = new SemFunction(node);
            context.addSemObject(obj);
            visitPreAlloca(node->body, node);
            if(context.getNowClass()) {
                node->theClass = context.getNowClass()->define;
            }
            context.push();
            context.pushFunc(obj);
            for(const auto i:node->args) {
                visit(i);
            }
            for(const auto i: *node->body) {
                visit(i);
            }
            bool has_return = false;
            for(const auto i:*node->body) {
                if(i->getSemType() == SemNode::ReturnNodeType) {
                    has_return = true;
                }
            }
            if(!has_return) {
                if(!node->returnType->isVoid()) {
                    throw std::runtime_error("Not have Return");
                }
                const auto s = new ReturnNode();
                root->allSemNode.insert(s);
                node->body->push_back(s);
            }
            context.popFunc();
            context.pop();
            return {};
        }

        std::any visitFuncCall(FuncCallNode *node) override {
            const auto obj = context.getSemObject(node->name);
            const auto func = dynamic_cast<SemFunction *>(obj);
            if(func == nullptr) {
                throw std::runtime_error("Null FuncCall");
            }
            if(obj->getSemObjType() != SemObject::Function) {
                throw std::runtime_error("Object is not a function");
            }
            *node->getType() = *func->getReturnType();
            return {};
        }

        std::any visitReturn(ReturnNode *node) override {
            const TypeNode * type = nullptr;
            if(node->value) {
                visit(node->value);
                type = node->value->getType();
            }
            const auto func = context.getNowFunc();
            if(!func->getReturnType()->isVoid() && !type) {
                throw std::runtime_error(std::format("Function return type '{}' does not match operand '{}' inst!",func->getReturnType()->name,"void"));
            }
            else if(type && func->getReturnType()->name!=type->name) {
                throw std::runtime_error(std::format("Function return type '{}' does not match operand '{}' inst!",func->getReturnType()->name,type->name));
            }
            return {};
        }
    };
}// namespace Riddle
