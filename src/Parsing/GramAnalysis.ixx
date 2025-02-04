module;
#include <RiddleParser.h>
#include <RiddleParserBaseVisitor.h>
export module Parsing.GramAnalysis;
import Semantics.SemNode;
import IR.Context;
export namespace Riddle {
    class GramAnalysis final : public RiddleParserBaseVisitor {
        Context *IRContext;

    public:
        explicit GramAnalysis(Context *ctx): IRContext(ctx) {}

        // 程序根节点
        std::any visitProgram(RiddleParser::ProgramContext *ctx) override {
            const auto body = new BlockNode;
            IRContext->semManager.addToAllocator(body);
            const auto program = new ProgramNode(body);
            IRContext->semManager.addToAllocator(program);
            for(const auto i: ctx->children) {
                auto result = visit(i);
                if(result.type() == typeid(nullptr)) {
                    continue;
                }
                if(result.type() != typeid(SemNode *)) {
                    throw std::runtime_error("GramAnalysis: Result not SemNode");
                }
                program->getBody()->push_back(std::any_cast<SemNode *>(result));
            }
            return program;
        }

        std::any visitPackStatement(RiddleParser::PackStatementContext *ctx) override {
            SemNode *node = new PackageNode(ctx->packName->getText());
            IRContext->semManager.addToAllocator(node);
            return node;
        }

        std::any visitStatement_ed(RiddleParser::Statement_edContext *ctx) override {
            if(antlrcpp::is<antlr4::tree::TerminalNode *>(ctx->children[0])) {
                return {};
            }
            return visit(ctx->children[0]);
        }

        std::any visitBodyExpr(RiddleParser::BodyExprContext *ctx) override {
            const auto block = new BlockNode;
            IRContext->semManager.addToAllocator(block);
            for(const auto i: ctx->children) {
                auto result = visit(i);
                if(!result.has_value()) {
                    continue;
                }
                if(result.type() != typeid(SemNode *)) {
                    throw std::runtime_error("GramAnalysis: Result not SemNode");
                }
                block->push_back(std::any_cast<SemNode *>(result));
            }
            // 转换防止 any_cast 不认
            SemNode *result = block;
            return result;
        }

        std::any visitInteger(RiddleParser::IntegerContext *ctx) override {
            const auto integer = new IntegerLiteralNode(ctx->value);
            IRContext->semManager.addToAllocator(integer);
            return integer;
        }

        std::any visitFloat(RiddleParser::FloatContext *ctx) override {
            const auto floating = new FloatLiteralNode(ctx->value);
            IRContext->semManager.addToAllocator(floating);
            return floating;
        }
    };
}// namespace Riddle