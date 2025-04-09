module;
#include <any>
#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>
export module Semantic.SemAnalysis;
import Semantic.SemNode;
export namespace Riddle {
    class SemAnalysis final : public SemVisitor {
    public:
        std::any visitProgram(const ProgramNode *node) override {
            for (const auto i: node->children) {
                visit(i);
            }
            return {};
        }

        std::any visitInteger(const IntegerNode *node) override {
            node->type->select = TypeNode::Global;
            node->type->name = "int";
            return {};
        }

        std::any visitFloat(const FloatNode *node) override {
            node->type->select = TypeNode::Global;
            node->type->name = "float";
            return {};
        }

        std::any visitReturn(const ReturnNode *node) override {
            visit(node->result);
            return {};
        }

        std::any visitType(const TypeNode *node) override {
            return {};
        }

        static void preAlloca(SemNode *node, BlockNode *funcBody) {
            static std::unordered_map<size_t, std::function<void(SemNode *, BlockNode *)>> funcs = {
                    {typeid(BlockNode).hash_code(),
                     [](SemNode *sn, BlockNode *fb) {
                         for (const auto i: dynamic_cast<BlockNode *>(sn)->children) {
                             preAlloca(i, fb);
                         }
                     }},
                    {typeid(VarDecl).hash_code(), [](SemNode *sn, BlockNode *fb) {
                         const auto decl = dynamic_cast<VarDecl *>(sn);
                         fb->children.insert(fb->children.begin(), decl->alloca);
                     }}};

            if (!node) {
                return;
            }
            if (!funcs.contains(typeid(*node).hash_code())) {
                return;
            }
            funcs.at(typeid(*node).hash_code())(node, funcBody);
        }

        std::any visitFunctionDecl(const FunctionDecl *node) override {
            preAlloca(node->body, node->body);
            return {};
        }
    };
} // namespace Riddle
