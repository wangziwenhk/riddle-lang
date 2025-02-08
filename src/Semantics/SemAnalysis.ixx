module;
#include <any>
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

    public:
        std::any visitProgram(ProgramNode *node) override {
            context.push();
            for(const auto &i: *node->body) {
                visit(i);
            }
            context.pop();
            return {};
        }

        std::any visitVarDefine(VarDefineNode *node) override {
            const auto obj = new SemVariable(node);
            context.addSemObject(obj);
            visit(node->value);
            if(node->type->isUnknown()) {
                if(node->value != nullptr) {
                    node->type = node->value->getType();
                } else {
                    throw std::runtime_error("Null VarDefine");
                }
            } else if(*node->type != *node->value->getType()) {
                throw std::runtime_error("Type mismatch");
            }
            return {};
        }


        // 处理 Object 的类型
        std::any visitObject(ObjectNode *node) override {
            // 这里仅做类型处理
            if(node->getType()->isUnknown()) {
                const auto obj = context.getSemObject(node->name);
                if(obj->getSemObjType() != SemObject::Variable) {
                    throw std::runtime_error("Object is not a variable");
                }
                const auto var = dynamic_cast<SemVariable *>(obj);
                *node->getType() = *var->getType();
                return {};
            }
            return {};
        }

        static std::any visitPreAlloca(SemNode *node, const FuncDefineNode *func) {
            switch(node->getSemType()) {
                case SemNode::BlockNodeType: {
                    for(const auto &i: *dynamic_cast<BlockNode*>(node)) {
                        visitPreAlloca(i,func);
                    }
                    break;
                }
                case SemNode::VarDefineNodeType: {
                    const auto var = dynamic_cast<VarDefineNode*>(node);
                    func->body->body.insert(func->body->begin(),var->alloca);
                    break;
                }
                default:
                    break;
                // todo 支持完整的body
            }
            return {};
        }

        std::any visitFuncDefine(FuncDefineNode *node) override {
            const auto obj = new SemFunction(node);
            context.addSemObject(obj);
            visitPreAlloca(node->body, node);
            context.push();
            for(const auto i: *node->body) {
                visit(i);
            }
            context.pop();
            return {};
        }

        std::any visitFuncCall(FuncCallNode *node) override {
            const auto obj = context.getSemObject(node->name);
            const auto func = dynamic_cast<SemFunction *>(obj);
            if(obj->getSemObjType() != SemObject::Function) {
                throw std::runtime_error("Object is not a function");
            }
            *node->getType() = *func->getReturnType();
            return {};
        }
    };
}// namespace Riddle
