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
            return {};
        }

        std::any visitObject(ObjectNode *node) override {
            if(node->getType()->isUnknown()) {
                const auto obj = context.getSemObject(node->name);
                if(obj->getSemObjType() != SemObject::Variable) {
                    throw std::runtime_error("Object is not a variable");
                }
                const auto var = dynamic_cast<SemVariable *>(obj);
                node->getType()->name = var->getType()->name;
            }
            return {};
        }
    };
}// namespace Riddle
