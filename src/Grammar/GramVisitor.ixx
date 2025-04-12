module;
#include <memory>
#include "RiddleParserBaseVisitor.h"
export module Grammar.GramVisitor;
import Semantic.SemNode;
import Support.Cast;
namespace Riddle {
    template<typename Tp = std::shared_ptr<SemNode>, typename SrcTp = std::shared_ptr<SemNode>>
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
        std::any visitProgram(RiddleParser::ProgramContext *context) override {
            std::shared_ptr<ProgramNode> program = ProgramNode::create();
            for (const auto i: context->children) {
                const auto &&result = visit(i);
                if (!result.has_value()) {
                    continue;
                }
                program->children.emplace_back(sem_fit_cast(result));
            }
            return std::move(program);
        }

        std::any visitStatement_ed(RiddleParser::Statement_edContext *context) override {
            return visit(context->children[0]);
        }

        std::any visitInteger(RiddleParser::IntegerContext *context) override {
            std::shared_ptr<SemNode> ptr = IntegerNode::create(context->value);
            return std::move(ptr);
        }

        std::any visitFloat(RiddleParser::FloatContext *context) override {
            std::shared_ptr<SemNode> ptr = FloatNode::create(context->value);
            return std::move(ptr);
        }

        std::any visitBoolean(RiddleParser::BooleanContext *context) override {
            std::shared_ptr<SemNode> ptr = BooleanNode::create(context->value);
            return std::move(ptr);
        }

        std::any visitBodyExpr(RiddleParser::BodyExprContext *context) override {
            const auto block = BlockNode::create();
            for (const auto i: context->children) {
                const auto &&result = visit(i);
                if (!result.has_value()) {
                    continue;
                }
                block->children.emplace_back(sem_fit_cast(result));
            }
            std::shared_ptr<SemNode> ptr = std::move(block);
            return ptr;
        }

        std::any visitFuncDefine(RiddleParser::FuncDefineContext *context) override {
            const auto name = context->funcName->getText();
            const auto funcNode = FuncDeclNode::create(name);
            funcNode->children = sem_fit_cast<std::shared_ptr<BlockNode>>(visit(context->body));
            return {};
        }
    };
} // namespace Riddle
