module;
#include <any>
#include <vector>
export module Semantic.SemAnalysis;
import Semantic.SemNode;
import Semantic.ValueType;
import Semantic.SemContext;
import Config.BaseType;
export namespace Riddle {
    class SemAnalysis final : public SemVisitor {
    protected:
        SemContext context{};

    public:
        std::any visitProgram(ProgramNode *node) override {
            for (const auto &i: node->children) {
                visit(i.get());
            }
            return {};
        }

        std::any visitInteger(IntegerNode *node) override {
            node->type->name = "int";
            return {};
        }

        std::any visitFloat(FloatNode *node) override {
            node->type->name = "float";
            return {};
        }

        std::any visitBoolean(BooleanNode *node) override {
            node->type->name = "bool";
            return {};
        }

        std::any visitChar(CharNode *node) override {
            node->type->name = "char";
            return {};
        }

        std::any visitType(TypeNode *node) override {
            visitObject(node);
            node->type->pointerSize = node->pointerSize;
            return {};
        }


        std::any visitObject(ObjectNode *node) override {
            if (node->name.empty() || node->select != ObjectNode::Unknown) {
                return {};
            }
            if (isBaseType(node->name)) {
                node->select = ObjectNode::Base;
                return {};
            }
            const auto obj = context.getObject(node->name);
            // 提升到 type
            if (obj->id == SemObject::Type) {
                // 取消提升
                if (typeid(*node) == typeid(TypeNode)) {
                    return {};
                }
                node = new (node) TypeNode(node->name);
            }
            return {};
        }

        std::any visitVarDecl(VarDeclNode *node) override {
            if (node->value) {
                visit(node->value.get());
            }
            visit(node->type.get());
            context.addObject(SemVariable::create(node->name, node));
            return {};
        }

        std::any visitArgDeclList(ArgDeclListNode *node) override {
            for (const auto &i: node->children) {
                visit(i.get());
            }
            return {};
        }

        std::any visitFuncDecl(FuncDeclNode *node) override {
            visit(node->returnType.get());
            visit(node->args.get());
            context.push();
            visit(node->children.get());
            context.pop();
            return {};
        }
    };
} // namespace Riddle
