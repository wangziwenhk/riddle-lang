module;
#include <RiddleParser.h>
#include <RiddleParserBaseVisitor.h>
#include <format>
export module Parsing.GramAnalysis;
import Semantics.SemNode;
import Semantics.Modifier;
namespace Riddle {
    template<typename Tp, typename SrcTp = SemNode, typename Arg>
        requires std::is_same_v<std::decay_t<Arg>, std::any>
    Tp *unpacking(Arg &&src) {
        return dynamic_cast<Tp *>(std::any_cast<SrcTp *>(std::forward<Arg>(src)));
    }

    template<typename Tp>
    std::shared_ptr<Tp> toSPtr(Tp *x) {
        return std::shared_ptr<Tp>(x);
    }
} // namespace Riddle
export namespace Riddle {
    class GramAnalysis final : public RiddleParserBaseVisitor {
    public:
        GramAnalysis() = default;

        ProgramNode *root = nullptr;

        // 程序根节点
        std::any visitProgram(RiddleParser::ProgramContext *ctx) override {
            const auto body = new BlockNode;
            const auto program = new ProgramNode(body);
            root = program;
            root->addSemNode(body);
            for (const auto i: ctx->children) {
                auto result = visit(i);
                if (!result.has_value() || result.type() == typeid(nullptr)) {
                    continue;
                }
                if (result.type() != typeid(SemNode *)) {
                    throw std::runtime_error(
                        std::format("GramAnalysis: Result \'{}\' not SemNode", result.type().name()));
                }
                program->body->push_back(std::any_cast<SemNode *>(result));
            }
            return program;
        }

        std::any visitPackStatement(RiddleParser::PackStatementContext *ctx) override {
            SemNode *node = new PackageNode(ctx->packName->getText());
            root->addSemNode(node);
            return node;
        }

        std::any visitStatement_ed(RiddleParser::Statement_edContext *ctx) override {
            if (antlrcpp::is<antlr4::tree::TerminalNode *>(ctx->children[0])) {
                return {};
            }
            return visit(ctx->children[0]);
        }

        std::any visitBodyExpr(RiddleParser::BodyExprContext *ctx) override {
            const auto block = new BlockNode;
            root->addSemNode(block);
            for (const auto i: ctx->children) {
                auto result = visit(i);
                if (!result.has_value()) {
                    continue;
                }
                if (result.type() != typeid(SemNode *)) {
                    throw std::runtime_error("GramAnalysis: Result not SemNode");
                }
                block->push_back(std::any_cast<SemNode *>(result));
            }
            // 转换防止 any_cast 不认
            SemNode *result = block;
            return result;
        }

        std::any visitInteger(RiddleParser::IntegerContext *ctx) override {
            SemNode *integer = new IntegerLiteralNode(ctx->value, root);
            root->addSemNode(integer);
            return integer;
        }

        std::any visitFloat(RiddleParser::FloatContext *ctx) override {
            SemNode *floating = new FloatLiteralNode(ctx->value, root);
            root->addSemNode(floating);
            return floating;
        }

        std::any visitBoolean(RiddleParser::BooleanContext *ctx) override {
            SemNode *boolean = new BoolLiteralNode(ctx->value, root);
            root->addSemNode(boolean);
            return boolean;
        }

        static char ParserChar(const char ch) {
            switch (ch) {
                case 'n':
                    return '\n';
                case 't':
                    return '\t';
                case 'r':
                    return '\r';
                case 'b':
                    return '\b';
                default:
                    throw std::runtime_error("GramAnalysis: Unexpected character");
            }
        }

        std::any visitStringExpr(RiddleParser::StringExprContext *ctx) override {
            auto literal = ctx->getText();
            literal = literal.substr(1, literal.length() - 2);
            std::string result;
            for (int i = 0; i < literal.length(); i++) {
                const char ch = literal.at(i);
                if (ch == '\\') {
                    result.push_back(ParserChar(literal.at(i + 1)));
                } else {
                    result.push_back(ch);
                }
            }
            SemNode *node = new StringLiteralNode(result, root);
            root->addSemNode(node);
            return node;
        }

        std::any visitCharExpr(RiddleParser::CharExprContext *context) override {
            auto literal = context->getText();
            literal = literal.substr(1, literal.length() - 2);
            char result;
            if (literal.at(0) == '\\') {
                result = ParserChar(literal.at(literal.length() - 1));
            }
            else {
                result = literal.at(0);
            }
            SemNode* node = new IntegerLiteralNode(result, root);
            root->addSemNode(node);
            return node;
        }

#pragma region Operators
#define opDefFunc(op) const auto left = unpacking<ExprNode>(visit(ctx->left));  \
        const auto right = unpacking<ExprNode>(visit(ctx->right));          \
        SemNode *node = new BinaryOpNode(left, right, op);                \
        root->addSemNode(node);                                             \
        return node;


        std::any visitAddExpr(RiddleParser::AddExprContext *ctx) override {
            opDefFunc("+")
        }

        std::any visitSubExpr(RiddleParser::SubExprContext *ctx) override {
            opDefFunc("-")
        }

        std::any visitMulExpr(RiddleParser::MulExprContext *ctx) override {
            opDefFunc("*")
        }

        std::any visitDivExpr(RiddleParser::DivExprContext *ctx) override {
            opDefFunc("/")
        }

        std::any visitBitXorExpr(RiddleParser::BitXorExprContext *ctx) override {
            opDefFunc("^")
        }

        std::any visitBitAndExpr(RiddleParser::BitAndExprContext *ctx) override {
            opDefFunc("&")
        }

        std::any visitBitOrExpr(RiddleParser::BitOrExprContext *ctx) override {
            opDefFunc("|")
        }

        std::any visitAddAssignExpr(RiddleParser::AddAssignExprContext *ctx) override {
            opDefFunc("+=")
        }

        std::any visitSubAssignExpr(RiddleParser::SubAssignExprContext *ctx) override {
            opDefFunc("-=")
        }

        std::any visitDivAssignExpr(RiddleParser::DivAssignExprContext *ctx) override {
            opDefFunc("/=")
        }

        std::any visitMulAssignExpr(RiddleParser::MulAssignExprContext *ctx) override {
            opDefFunc("*=")
        }

        std::any visitLessExpr(RiddleParser::LessExprContext *ctx) override {
            opDefFunc("<")
        }

        std::any visitLessEqualExpr(RiddleParser::LessEqualExprContext *ctx) override {
            opDefFunc("<=")
        }

        std::any visitGreaterExpr(RiddleParser::GreaterExprContext *ctx) override {
            opDefFunc(">")
        }

        std::any visitGreaterEqualExpr(RiddleParser::GreaterEqualExprContext *ctx) override {
            opDefFunc(">=")
        }

        std::any visitEqualExpr(RiddleParser::EqualExprContext *ctx) override {
            opDefFunc("==")
        }

        std::any visitAssignExpr(RiddleParser::AssignExprContext *ctx) override {
            opDefFunc("=")
        }
#pragma endregion

        std::any visitFuncDefine(RiddleParser::FuncDefineContext *ctx) override {
            Modifier mod;
            if (ctx->mod) {
                mod = std::any_cast<Modifier>(visitModifierList(ctx->mod));
            }
            const auto name = ctx->funcName->getText();
            BlockNode *body = nullptr;
            if (ctx->body) {
                body = dynamic_cast<BlockNode *>(std::any_cast<SemNode *>(visit(ctx->body)));
            }
            TypeNode *returnType = nullptr;
            if (ctx->returnType == nullptr) {
                returnType = new TypeNode("void");
                root->addSemNode(returnType);
            } else {
                returnType = dynamic_cast<TypeNode *>(std::any_cast<SemNode *>(visit(ctx->returnType)));
            }
            if (returnType == nullptr) {
                throw std::runtime_error("GramAnalysis: Result node not Type");
            }

            std::vector<ArgNode *> args;
            if (ctx->args != nullptr) {
                args = std::any_cast<std::vector<ArgNode *> >(visitDefineArgs(ctx->args));
            }
            SemNode *func = new FuncDefineNode(name, returnType, body, mod, args);
            root->addSemNode(func);
            return func;
        }

        std::any visitBaseType(RiddleParser::BaseTypeContext *ctx) override {
            const auto name = ctx->name->getText();
            SemNode *node = new TypeNode(name);
            root->addSemNode(node);
            return node;
        }

        std::any visitDefineArgs(RiddleParser::DefineArgsContext *ctx) override {
            std::string name;
            TypeNode *type = nullptr;
            std::vector<ArgNode *> args;
            for (const auto i: ctx->children) {
                if (antlrcpp::is<RiddleParser::IdContext *>(i)) {
                    name = i->getText();
                } else if (antlrcpp::is<RiddleParser::TypeUsedContext *>(i)) {
                    type = unpacking<TypeNode>(visit(i));
                }
                if (!name.empty() && type != nullptr) {
                    const auto alloca = new AllocaNode(type);
                    root->addSemNode(alloca);
                    auto arg = new ArgNode(name, type, alloca);
                    args.push_back(arg);
                    name.clear();
                    type = nullptr;
                }
            }
            return args;
        }

        std::any visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) override {
            const auto name = ctx->name->getText();
            TypeNode *type = nullptr;
            ExprNode *value = nullptr;
            if (ctx->type) {
                type = unpacking<TypeNode>(visit(ctx->type));
                if (!type) {
                    throw std::runtime_error("GramAnalysis: Result node not Type");
                }
            }
            if (ctx->value) {
                value = unpacking<ExprNode>(visit(ctx->value));
            }
            if (!type && value) {
                type = value->getType();
            }
            const auto alloca = new AllocaNode(type);
            root->addSemNode(alloca);
            SemNode *node = new VarDefineNode(name, value, type, alloca);
            root->addSemNode(node);
            return node;
        }

        std::any visitReturnStatement(RiddleParser::ReturnStatementContext *ctx) override {
            SemNode *node;
            if (ctx->result) {
                const auto value = unpacking<ExprNode>(visit(ctx->result));
                node = new ReturnNode(value);
            } else {
                node = new ReturnNode();
            }
            root->addSemNode(node);
            return node;
        }

        std::any visitObjectExpr(RiddleParser::ObjectExprContext *ctx) override {
            const std::string name = ctx->getText();
            const auto type = new TypeNode(TypeNode::unknown);
            root->addSemNode(type);
            const auto object = new ObjectNode(name, type);
            if (antlrcpp::is<RiddleParser::PtrExprContext *>(ctx->parent)) {
                object->isLoad = true;
            }
            root->addSemNode(object);
            SemNode *node = object;
            return node;
        }

        std::any visitArgsExpr(RiddleParser::ArgsExprContext *ctx) override {
            std::vector<ExprNode *> args;
            args.reserve((ctx->children.size() >> 1) + 1);
            for (const auto i: ctx->children) {
                auto t = visit(i);
                if (!t.has_value()) {
                    continue;
                }
                auto it = unpacking<ExprNode>(t);
                args.emplace_back(it);
            }
            return args;
        }

        std::any visitFuncExpr(RiddleParser::FuncExprContext *context) override {
            const auto name = context->funcName->getText();
            const auto args = std::any_cast<std::vector<ExprNode *> >(visit(context->args));
            SemNode *node = new FuncCallNode(root, name, args);
            root->addSemNode(node);
            return node;
        }

        std::any visitIfStatement(RiddleParser::IfStatementContext *ctx) override {
            const auto cond = unpacking<ExprNode>(visit(ctx->cond));
            const auto thenBody = std::any_cast<SemNode *>(visit(ctx->body));
            SemNode *elseBody = nullptr;
            if (ctx->elseBody != nullptr) {
                elseBody = std::any_cast<SemNode *>(visit(ctx->elseBody));
            }
            SemNode *node = new IfNode(cond, thenBody, elseBody);
            return node;
        }

        std::any visitWhileStatement(RiddleParser::WhileStatementContext *context) override {
            const auto cond = unpacking<ExprNode>(visit(context->cond));
            const auto body = std::any_cast<SemNode *>(visit(context->body));
            SemNode *node = new WhileNode(cond, body);
            root->addSemNode(node);
            return node;
        }

        std::any visitForStatement(RiddleParser::ForStatementContext *ctx) override {
            const auto init = std::any_cast<SemNode *>(visit(ctx->init));
            const auto cond = unpacking<ExprNode>(visit(ctx->cond));
            const auto incr = std::any_cast<SemNode *>(visit(ctx->incr));
            const auto body = std::any_cast<SemNode *>(visit(ctx->body));
            SemNode *node = new ForNode(init, cond, incr, body);
            root->addSemNode(node);
            return node;
        }

        std::any visitImportStatement(RiddleParser::ImportStatementContext *ctx) override {
            if (ctx->depth() != 4) {
                throw std::runtime_error("GramAnalysis: Import Size Error");
            }
            return {};
        }

        std::any visitClassDefine(RiddleParser::ClassDefineContext *ctx) override {
            const auto define = new ClassDefineNode(ctx->className->getText());
            if (ctx->parentClass) {
                define->parentClass = ctx->parentClass->getText();
            }
            for (const auto i: ctx->body->children) {
                auto v = visit(i);
                if (!v.has_value()) continue;
                const auto result = std::any_cast<SemNode *>(v);
                if (result->getSemType() == SemNode::VarDefineNodeType) {
                    define->members.push_back(dynamic_cast<VarDefineNode *>(result));
                } else if (result->getSemType() == SemNode::FuncDefineNodeType) {
                    const auto func = dynamic_cast<FuncDefineNode *>(result);
                    if (define->hasFunction(func->name)) {
                        throw std::runtime_error(std::format("GramAnalysis: Function {} already exists", func->name));
                    }
                    define->functions.push_back(func);
                }
            }
            SemNode *node = define;
            root->addSemNode(node);
            return node;
        }

        std::any visitBlendExpr(RiddleParser::BlendExprContext *ctx) override {
            const auto parent = unpacking<ExprNode>(visit(ctx->parentNode));
            const auto child = unpacking<ExprNode>(visit(ctx->childNode));
            const auto node = new BlendNode(parent, child, root, BlendNode::Unknown);
            root->addSemNode(node);
            if (antlrcpp::is<RiddleParser::PtrExprContext *>(ctx->parent)) {
                node->isLoad = true;
            }
            SemNode *result = node;
            return result;
        }

        std::any visitModifier(RiddleParser::ModifierContext *ctx) override {
            return Modifier::getPrimitiveType(ctx->getText());
        }

        std::any visitModifierList(RiddleParser::ModifierListContext *ctx) override {
            Modifier modifier;
            for (const auto i: ctx->children) {
                const auto mod = std::any_cast<Modifier::ModifierType>(visit(i));
                modifier.set(mod, true);
            }
            return modifier;
        }
    };
} // namespace Riddle
