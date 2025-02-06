module;
#include <RiddleParser.h>
#include <RiddleParserBaseVisitor.h>
#include <format>
export module Parsing.GramAnalysis;
import Semantics.SemNode;
import IR.Context;
namespace Riddle {

    template<typename Tp, typename SrcTp, typename Arg>
    requires std::is_same_v<std::decay_t<Arg>, std::any>
    std::shared_ptr<Tp> unpacking(Arg &&src) {
        return std::shared_ptr<Tp>(dynamic_cast<Tp *>(std::any_cast<SrcTp *>(std::forward<Arg>(src))));
    }

    template<typename Tp>
    std::shared_ptr<Tp> toSPtr(Tp *x) {
        return std::shared_ptr<Tp>(x);
    }
}// namespace Riddle
export namespace Riddle {
    class GramAnalysis final : public RiddleParserBaseVisitor {

    public:
        GramAnalysis() = default;

        // 程序根节点
        std::any visitProgram(RiddleParser::ProgramContext *ctx) override {
            const auto body = new BlockNode;
            const auto program = new ProgramNode(body);
            for(const auto i: ctx->children) {
                auto result = visit(i);
                if(result.type() == typeid(nullptr)) {
                    continue;
                }
                if(result.type() != typeid(SemNode *)) {
                    throw std::runtime_error(std::format("GramAnalysis: Result \'{}\' not SemNode", result.type().name()));
                }
                program->body->push_back(std::any_cast<SemNode *>(result));
            }
            return program;
        }

        std::any visitPackStatement(RiddleParser::PackStatementContext *ctx) override {
            SemNode *node = new PackageNode(ctx->packName->getText());
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
            SemNode *integer = new IntegerLiteralNode(ctx->value);
            return integer;
        }

        std::any visitFloat(RiddleParser::FloatContext *ctx) override {
            SemNode *floating = new FloatLiteralNode(ctx->value);
            return floating;
        }

        std::any visitBoolean(RiddleParser::BooleanContext *ctx) override {
            SemNode *boolean = new BoolLiteralNode(ctx->value);
            return boolean;
        }

        std::any visitString(RiddleParser::StringContext *ctx) override {
            auto literal = ctx->getText();
            literal = literal.substr(1, literal.length() - 2);
            std::string result;
            for(int i = 0; i < literal.length(); i++) {
                const char ch = literal.at(i);
                if(ch == '\\') {
                    switch(literal.at(i + 1)) {
                        case 'n':
                            result.push_back('\n');
                            break;
                        case 't':
                            result.push_back('\t');
                            break;
                        case 'r':
                            result.push_back('\r');
                            break;
                        case 'b':
                            result.push_back('\b');
                            break;
                        default:
                            throw std::runtime_error("GramAnalysis: Unexpected character");
                    }
                } else {
                    result.push_back(ch);
                }
            }
            SemNode *node = new StringLiteralNode(result);
            return node;
        }

        std::any visitFuncDefine(RiddleParser::FuncDefineContext *ctx) override {
            const auto name = ctx->funcName->getText();
            const auto body = dynamic_cast<BlockNode *>(std::any_cast<SemNode *>(visit(ctx->body)));
            if(body == nullptr) {
                throw std::runtime_error("GramAnalysis: Result node not BlockNode");
            }
            TypeNode *returnType = nullptr;
            if(ctx->returnType == nullptr) {
                returnType = new TypeNode("void");
            } else {
                returnType = dynamic_cast<TypeNode *>(std::any_cast<SemNode *>(visit(ctx->returnType)));
            }
            if(returnType == nullptr) {
                throw std::runtime_error("GramAnalysis: Result node not Type");
            }

            std::vector<ArgNode *> args;
            if(ctx->args != nullptr) {
                args = std::any_cast<std::vector<ArgNode *>>(visitDefineArgs(ctx->args));
            }
            SemNode *func = new FuncDefineNode(name, body, returnType, args);
            return func;
        }

        std::any visitDefineArgs(RiddleParser::DefineArgsContext *ctx) override {
            std::string name;
            std::shared_ptr<TypeNode> type = nullptr;
            std::vector<ArgNode *> args;
            for(const auto i: ctx->children) {
                if(antlrcpp::is<RiddleParser::IdContext *>(i)) {
                    name = i->getText();
                } else if(antlrcpp::is<RiddleParser::TypeUsedContext *>(i)) {
                    type = unpacking<TypeNode, SemNode>(visit(i));
                }
                if(!name.empty() && type != nullptr) {
                    auto arg = new ArgNode(name, type.get());
                    args.push_back(arg);
                    name.clear();
                    type = nullptr;
                }
            }
            return args;
        }

        std::any visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) override {
            const auto name = ctx->name->getText();
            std::shared_ptr<TypeNode> type = nullptr;
            std::shared_ptr<ExprNode> value = nullptr;
            if(ctx->type) {
                // type = std::shared_ptr<TypeNode>(dynamic_cast<TypeNode *>(std::any_cast<SemNode *>(visit(ctx->type))));
                type = unpacking<TypeNode, SemNode>(visit(ctx->type));
                if(type == nullptr) {
                    throw std::runtime_error("GramAnalysis: Result node not Type");
                }
            }
            if(ctx->value) {
                value = unpacking<ExprNode, SemNode>(visit(ctx->value));
            }
            if(type == nullptr && value != nullptr) {
                type = toSPtr(value->getType());
            }
            SemNode *node = new VarDefineNode(name, value.get(), type.get());
            return node;
        }
    };
}// namespace Riddle