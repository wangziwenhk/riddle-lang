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
            std::shared_ptr<SemNode> ptr = block;
            return std::move(ptr);
        }

        std::any visitBaseType(RiddleParser::BaseTypeContext *context) override {
            std::shared_ptr<SemNode> ptr = TypeNode::create(context->getText());
            return std::move(ptr);
        }

        std::any visitDefineArgs(RiddleParser::DefineArgsContext *context) override {
            const auto list = ArgDeclListNode::create();
            std::string name;
            std::shared_ptr<TypeNode> type;
            for (const auto i: context->children) {
                if (antlrcpp::is<RiddleParser::IdContext *>(i)) {
                    name = i->getText();
                } else if (antlrcpp::is<RiddleParser::ExpressionContext *>(i)) {
                    type = sem_fit_cast<std::shared_ptr<TypeNode>>(visit(i));
                }
                if (!name.empty() && type) {
                    list->children.emplace_back(ArgDeclNode::create(name, type));
                }
            }
            std::shared_ptr<SemNode> ptr = list;
            return std::move(ptr);
        }

        std::any visitFuncDefine(RiddleParser::FuncDefineContext *context) override {
            const auto name = context->funcName->getText();
            const auto body = sem_fit_cast<std::shared_ptr<BlockNode>>(visit(context->body));
            const auto args = sem_fit_cast<std::shared_ptr<ArgDeclListNode>>(visit(context->args));
            const auto return_type = sem_fit_cast<std::shared_ptr<TypeNode>>(visit(context->returnType));
            const auto funcNode = FuncDeclNode::create(name, return_type, body, args);
            std::shared_ptr<SemNode> ptr = funcNode;
            return std::move(ptr);
        }

        std::any visitBracketExpr(RiddleParser::BracketExprContext *context) override {
            return visit(context->expr);
        }
    };
} // namespace Riddle
