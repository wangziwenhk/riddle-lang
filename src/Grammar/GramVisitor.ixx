module;
#include <memory>
#include "RiddleParserBaseVisitor.h"
export module Grammar.GramVisitor;
import Semantic.SemNode;
import Support.Cast;
namespace Riddle {
    template<typename Tp = SemNode *, typename SrcTp = SemNode *>
    Tp sem_fit_cast(const std::any &pack) {
        if constexpr (std::is_same_v<Tp, SrcTp>) {
            return fit_cast<Tp>(pack);
        } else {
            return fit_cast<Tp, SrcTp>(pack);
        }
    }
} // namespace Riddle
export namespace Riddle {
    class GramVisitor final : public RiddleParserBaseVisitor {
    public:
        std::unique_ptr<ProgramNode> root;
        std::any visitProgram(RiddleParser::ProgramContext *context) override {
            root = std::make_unique<ProgramNode>();
            for (const auto i: context->children) {
                auto result = visit(i);
                if (!result.has_value()) {
                    continue;
                }
                root->children.emplace_back(sem_fit_cast(result));
            }
            return root.get();
        }

        std::any visitBaseType(RiddleParser::BaseTypeContext *context) override {
            SemNode* type = TypeNode::create(root.get(),context->getText());
            return type;
        }

        std::any visitDefineArgs(RiddleParser::DefineArgsContext *context) override {
            std::string name;
            TypeNode *type = nullptr;
            const auto list = DeclArgListNode::create(root.get());
            for (const auto child: context->children) {
                if (antlrcpp::is<RiddleParser::IdContext *>(child)) {
                    name = child->getText();
                } else if (antlrcpp::is<RiddleParser::TypeUsedContext *>(child)) {
                    type = sem_fit_cast<TypeNode *>(visit(child));
                }
                if (type != nullptr && !name.empty()) {
                    const auto arg = DeclArgNode::create(root.get(), name, type);
                    name.clear();
                    type = nullptr;
                    list->children.emplace_back(arg);
                }
            }
            SemNode *node = list;
            return node;
        }

        std::any visitFuncDefine(RiddleParser::FuncDefineContext *context) override {
            const std::string name = context->funcName->getText();
            const auto body = sem_fit_cast<BlockNode *>(visit(context->body));
            const auto args = sem_fit_cast<DeclArgListNode *>(visit(context->args));
            SemNode *node = FunctionDecl::create(root.get(), name, body, args);
            //todo 实现更多的参数保存
            return node;
        }

        std::any visitBodyExpr(RiddleParser::BodyExprContext *context) override {
            const auto block = BlockNode::create(root.get());
            block->children.reserve(context->children.size());
            for (const auto i: context->children) {
                const auto result = visit(i);
                if (!result.has_value()) {
                    continue;
                }
                block->children.push_back(sem_fit_cast(result));
            }
            block->children.shrink_to_fit();
            SemNode *node = block;
            return node;
        }
    };
} // namespace Riddle
