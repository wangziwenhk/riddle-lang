module;
#include <RiddleParserBaseVisitor.h>
#include <array>
#include <llvm/Support/Casting.h>
export module Visitors.StmtVisitor;
import Manager.StmtManager;
import IR.Context;
import IR.Statements;
import Type.Modifier;

export namespace Riddle {
    /// 所有函数的返回值都为BaseStmt
    class StmtVisitor final : public RiddleParserBaseVisitor {
    protected:
        Context &IRContext;
        std::string packageName;
        RiddleParser *parser;
        size_t deep = 0;
        std::stack<std::string> parentClass;

    public:
        explicit StmtVisitor(Context &ctx, RiddleParser *parser): IRContext(ctx), parser(parser) {}
        std::any visitProgram(RiddleParser::ProgramContext *ctx) override {
            std::vector<BaseStmt *> stmts;
            for(const auto i: ctx->children) {
                auto it = visit(i);
                if(!it.has_value()) {
                    throw std::logic_error("result is null");
                }
                const auto stmt = std::any_cast<BaseStmt *>(it);
                // 处理空语句
                if(stmt->isNoneStmt()) {
                    continue;
                }
                stmts.push_back(stmt);
            }
            return IRContext.stmtManager.getProgram(stmts);
        }

        std::any visitPackStatement(RiddleParser::PackStatementContext *ctx) override {
            packageName = ctx->packName->getText();
            IRContext.module->setModuleIdentifier(packageName);
            BaseStmt *stmt = IRContext.stmtManager.getNoneStmt();
            return stmt;
        }
        std::any visitImportStatement(RiddleParser::ImportStatementContext *context) override {
            BaseStmt *stmt = IRContext.stmtManager.getNoneStmt();
            return stmt;
        }

        std::any visitStatement(RiddleParser::StatementContext *ctx) override {
            try {
                return RiddleParserBaseVisitor::visitStatement(ctx);
            } catch(std::exception &e) {
                const auto it = dynamic_cast<antlr4::RuleContext *>(ctx->children[0]);
                std::cerr << "Parser Error for Rule \'" << parser->getRuleNames()[it->getRuleIndex()] << "\'" << std::endl;
                std::cerr << "\t" << ctx->getText() << std::endl;
                std::cerr << e.what() << std::endl
                          << std::endl;
                return IRContext.stmtManager.getNoneStmt();
            }
        }
        std::any visitStatement_ed(RiddleParser::Statement_edContext *ctx) override {
            return visit(ctx->children[0]);
        }
        std::any visitInteger(RiddleParser::IntegerContext *ctx) override {
            BaseStmt *result = IRContext.stmtManager.getConstant(ctx->value);
            return result;
        }
        std::any visitFloat(RiddleParser::FloatContext *ctx) override {
            BaseStmt *result = IRContext.stmtManager.getConstant(ctx->value);
            return result;
        }

        std::any visitBoolean(RiddleParser::BooleanContext *ctx) override {
            BaseStmt *result = IRContext.stmtManager.getConstant(ctx->value);
            return result;
        }

        std::any visitString(RiddleParser::StringContext *ctx) override {
            const std::string value = ctx->getText();
            BaseStmt *result = IRContext.stmtManager.getConstant(value.substr(1, value.size() - 2));
            return result;
        }

        std::any visitNullExpr(RiddleParser::NullExprContext *ctx) override {
            BaseStmt *result = IRContext.stmtManager.getNull();
            return result;
        }

        std::any visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) override {
            if(ctx->name == nullptr) {
                throw std::logic_error("name is null");
            }
            const std::string name = ctx->name->getText();
            TypeStmt *type = nullptr;
            if(ctx->type != nullptr) {
                type = dynamic_cast<TypeStmt *>(std::any_cast<BaseStmt *>(visit(ctx->type)));
            }
            BaseStmt *value = IRContext.stmtManager.getNoneStmt();
            if(ctx->value != nullptr) {
                value = std::any_cast<BaseStmt *>(visit(ctx->value));
            }
            BaseStmt *stmt = IRContext.stmtManager.getVarDefine(name, type, value);
            return stmt;
        }

        std::any visitIfStatement(RiddleParser::IfStatementContext *ctx) override {
            const auto cond = std::any_cast<BaseStmt *>(visit(ctx->cond));
            const auto thenBody = std::any_cast<BaseStmt *>(visit(ctx->body));
            const auto elseBody = std::any_cast<BaseStmt *>(visit(ctx->elseBody));
            BaseStmt *stmt = IRContext.stmtManager.getIf(cond, thenBody, elseBody);
            return stmt;
        }

        std::any visitWhileStatement(RiddleParser::WhileStatementContext *ctx) override {
            const auto cond = std::any_cast<BaseStmt *>(visit(ctx->runCond));
            const auto body = std::any_cast<BaseStmt *>(visit(ctx->body));
            BaseStmt *stmt = IRContext.stmtManager.getWhile(cond, body);
            return stmt;
        }

        std::any visitForStatement(RiddleParser::ForStatementContext *ctx) override {
            BaseStmt *cond = IRContext.stmtManager.getNoneStmt();
            BaseStmt *init = IRContext.stmtManager.getNoneStmt();
            BaseStmt *change = IRContext.stmtManager.getNoneStmt();
            if(ctx->init != nullptr) {
                init = std::any_cast<BaseStmt *>(visit(ctx->init));
            }
            if(ctx->termCond != nullptr) {
                cond = std::any_cast<BaseStmt *>(visit(ctx->termCond));
            }
            if(ctx->selfVar != nullptr) {
                change = std::any_cast<BaseStmt *>(visit(ctx->selfVar));
            }
            const auto body = std::any_cast<BaseStmt *>(visit(ctx->body));
            BaseStmt *stmt = IRContext.stmtManager.getFor(init, cond, change, body);
            return stmt;
        }

        std::any visitReturnStatement(RiddleParser::ReturnStatementContext *ctx) override {
            BaseStmt *val = nullptr;
            if(ctx->result != nullptr) {
                val = std::any_cast<BaseStmt *>(visit(ctx->result));
            }
            BaseStmt *stmt = IRContext.stmtManager.getReturn(val);
            return stmt;
        }

        std::any visitDefineArgs(RiddleParser::DefineArgsContext *ctx) override {
            std::string name;
            std::string type;
            BaseStmt *value = IRContext.stmtManager.getNoneStmt();

            DefineArgStmt *defineArg = nullptr;
            std::vector<DefineArgStmt *> args;

            for(auto i: ctx->children) {
                if(i->getText() == ",") {
                    defineArg = IRContext.stmtManager.getDefineArg(name, type, value);
                    args.push_back(defineArg);
                    name.clear();
                    type.clear();
                    value = IRContext.stmtManager.getNoneStmt();
                } else if(i->getText() == ":") {
                    continue;
                } else if(name.empty()) {
                    name = i->getText();
                } else if(type.empty()) {
                    type = i->getText();
                } else {
                    throw std::logic_error("unknown type");
                }
            }
            if(!name.empty()) {
                defineArg = IRContext.stmtManager.getDefineArg(name, type, value);
                args.push_back(defineArg);
                name.clear();
                type.clear();
            }
            BaseStmt *stmt = IRContext.stmtManager.getDefineArgList(args);
            return stmt;
        }

        std::any visitFuncDefine(RiddleParser::FuncDefineContext *ctx) override {
            const auto funcName = ctx->funcName->getText();
            const auto mod = std::any_cast<Modifier>(visit(ctx->mod));
            TmplDefineStmt* tmpl = nullptr;
            if(ctx->tmpl != nullptr) {
                const auto t_tmpl = std::any_cast<BaseStmt *>(visit(ctx->tmpl));
                tmpl = dynamic_cast<TmplDefineStmt *>(t_tmpl);
            }
            auto returnType = new TypeStmt("void");
            if(ctx->returnType != nullptr) {
                returnType = dynamic_cast<TypeStmt *>(std::any_cast<BaseStmt *>(visit(ctx->returnType)));
            }
            const auto body = std::any_cast<BaseStmt *>(visit(ctx->body));
            DefineArgListStmt *args = nullptr;
            if(!ctx->args->children.empty()) {
                args = dynamic_cast<DefineArgListStmt *>(std::any_cast<BaseStmt *>(visit(ctx->args)));
            }
            FuncDefineStmt *stmt = IRContext.stmtManager.getFuncDefine(funcName, returnType, body, tmpl, mod, args);
            if(!parentClass.empty()) {
                stmt->theClass = parentClass.top();
            }
            BaseStmt *result = stmt;
            return result;
        }

        std::any visitBodyExpr(RiddleParser::BodyExprContext *ctx) override {
            std::vector<BaseStmt *> stmts;
            stmts.reserve(ctx->children.size());
            for(const auto i: std::ranges::subrange(ctx->children.begin() + 1, ctx->children.end() - 1)) {
                try {
                    auto it = std::any_cast<BaseStmt *>(visit(i));
                    stmts.push_back(std::any_cast<BaseStmt *>(it));
                } catch(...) {
                    // 也有可能是没实现这个方法
                    throw std::logic_error("Error in visiting body expression: \"" + i->getText() + "\"");
                }
            }
            BaseStmt *body = IRContext.stmtManager.getBlock(stmts);
            return body;
        }

        std::any visitFuncExpr(RiddleParser::FuncExprContext *ctx) override {
            const std::string funcName = ctx->funcName->getText();
            const auto args = dynamic_cast<ArgListStmt *>(any_cast<BaseStmt *>(visit(ctx->args)));
            BaseStmt *stmt = IRContext.stmtManager.getFuncCall(funcName, args);
            return stmt;
        }
        std::any visitArgsExpr(RiddleParser::ArgsExprContext *ctx) override {
            std::vector<BaseStmt *> args;
            args.reserve(ctx->children.size());
            for(const auto i: ctx->children) {
                if(antlrcpp::is<antlr4::tree::TerminalNode *>(i)) {
                    continue;
                }
                auto it = visit(i);
                args.push_back(std::any_cast<BaseStmt *>(it));
            }
            BaseStmt *stmt = IRContext.stmtManager.getArgList(args);
            return stmt;
        }

        std::any visitObjectExpr(RiddleParser::ObjectExprContext *ctx) override {
            bool isLoaded = false;
            if(antlrcpp::is<RiddleParser::PtrExprContext *>(ctx->parent)) {
                isLoaded = true;
            }
            BaseStmt *stmt = IRContext.stmtManager.getObject(ctx->getText(), isLoaded);
            return stmt;
        }

        std::any visitExprPtrParser(RiddleParser::ExprPtrParserContext *ctx) override {
            return visit(ctx->children[0]);
        }

        std::any visitContinueStatement(RiddleParser::ContinueStatementContext *ctx) override {
            BaseStmt *stmt = IRContext.stmtManager.getContinue();
            return stmt;
        }

        std::any visitBreakStatement(RiddleParser::BreakStatementContext *ctx) override {
            BaseStmt *stmt = IRContext.stmtManager.getBreak();
            return stmt;
        }

        // 二元运算符号相关
        // 算数操作

        std::any visitAssignExpr(RiddleParser::AssignExprContext *ctx) override {
            const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
            const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
            BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "=");
            return stmt;
        }

        std::any visitAddExpr(RiddleParser::AddExprContext *ctx) override {
            const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
            const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
            BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "+");
            return stmt;
        }

        std::any visitSubExpr(RiddleParser::SubExprContext *ctx) override {
            const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
            const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
            BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "-");
            return stmt;
        }

        std::any visitMulExpr(RiddleParser::MulExprContext *ctx) override {
            const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
            const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
            BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "*");
            return stmt;
        }

        std::any visitDivExpr(RiddleParser::DivExprContext *ctx) override {
            const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
            const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
            BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "/");
            return stmt;
        }

        std::any visitModExpr(RiddleParser::ModExprContext *ctx) override {
            const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
            const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
            BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "%");
            return stmt;
        }
        // 位运算

        std::any visitBitAndExpr(RiddleParser::BitAndExprContext *ctx) override {
            const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
            const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
            BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "&");
            return stmt;
        }

        std::any visitBitOrExpr(RiddleParser::BitOrExprContext *ctx) override {
            const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
            const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
            BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "|");
            return stmt;
        }

        std::any visitBitXorExpr(RiddleParser::BitXorExprContext *ctx) override {
            const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
            const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
            BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "^");
            return stmt;
        }
        // 逻辑操作
        std::any visitEqualExpr(RiddleParser::EqualExprContext *ctx) override {
            const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
            const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
            BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "==");
            return stmt;
        }

        std::any visitLessExpr(RiddleParser::LessExprContext *ctx) override {
            const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
            const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
            BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "<");
            return stmt;
        }

        std::any visitGreaterExpr(RiddleParser::GreaterExprContext *ctx) override {
            const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
            const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
            BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, ">");
            return stmt;
        }

        // 类
        std::any visitClassDefine(RiddleParser::ClassDefineContext *ctx) override {
            const std::string className = ctx->className->getText();
            parentClass.push(className);
            const auto t_body = std::any_cast<BaseStmt *>(visit(ctx->body));
            const auto body = dynamic_cast<BlockStmt *>(t_body);
            const auto t_tmplDef = std::any_cast<BaseStmt *>(visit(ctx->tmpl));
            const auto tmplDef = dynamic_cast<TmplDefineStmt *>(t_tmplDef);
            parentClass.pop();

            std::vector<VarDefineStmt *> varDefs;
            std::vector<FuncDefineStmt *> funcDefines;

            for(const auto i: body->stmts) {
                if(i->getStmtTypeID() == BaseStmt::StmtTypeID::VarDefineStmtID) {
                    varDefs.push_back(dynamic_cast<VarDefineStmt *>(i));
                } else if(i->getStmtTypeID() == BaseStmt::StmtTypeID::FuncDefineStmtID) {
                    funcDefines.push_back(dynamic_cast<FuncDefineStmt *>(i));
                }
            }
            std::string parentClassName;
            if(ctx->parentClass) {
                parentClassName = ctx->parentClass->getText();
            }
            BaseStmt *stmt = IRContext.stmtManager.getClassDefine(className, varDefs, funcDefines, tmplDef, parentClassName);
            return stmt;
        }

        std::any visitBlendExpr(RiddleParser::BlendExprContext *ctx) override {
            const auto parent = std::any_cast<BaseStmt *>(visit(ctx->parents));
            const auto child = std::any_cast<BaseStmt *>(visit(ctx->child));
            BaseStmt *result = nullptr;
            if(child->getStmtTypeID() == BaseStmt::StmtTypeID::FuncCallStmtID) {
                result = IRContext.stmtManager.getMethodCall(parent, dynamic_cast<FuncCallStmt *>(child));
            } else if(child->getStmtTypeID() == BaseStmt::StmtTypeID::ObjStmtID) {
                bool isLoaded = false;
                // 这里这个parent是节点的parent而不是该表达式的parent
                if(antlrcpp::is<RiddleParser::PtrExprContext *>(ctx->parent)) {
                    isLoaded = true;
                }
                result = IRContext.stmtManager.getMemberExpr(parent, dynamic_cast<ObjectStmt *>(child), isLoaded);
            } else {
                throw std::logic_error("visitBlendExpr: Parent Node Type Error");
            }
            return result;
        }

        // 修饰符
        std::any visitModifier(RiddleParser::ModifierContext *ctx) override {
            const std::string name = ctx->getText();
            static constexpr std::array modifierMap = {// C++17 起可推导大小
                                                       std::pair{"public", Modifier::Public},
                                                       std::pair{"private", Modifier::Private},
                                                       std::pair{"protected", Modifier::Protected},
                                                       std::pair{"virtual", Modifier::Virtual},
                                                       std::pair{"static", Modifier::Static},
                                                       std::pair{"const", Modifier::Const}};

            const auto it = std::ranges::find_if(modifierMap, [&name](const auto &pair) { return pair.first == name; });

            if(it != modifierMap.end()) {
                return it->second;
            }
            throw std::logic_error("StmtVisitor::visitModifier: Unknown Modifier");
        }

        std::any visitModifierList(RiddleParser::ModifierListContext *ctx) override {
            Modifier mod;
            for(const auto i: ctx->children) {
                const auto result = std::any_cast<Modifier::ModifierType>(visit(i));
                mod.addModifier(result);
            }
            return mod;
        }

        std::any visitTmplDefineArg(RiddleParser::TmplDefineArgContext *ctx) override {
            const std::string name = ctx->name->getText();
            if(antlrcpp::is<antlr4::tree::TerminalNode*>(ctx->children[0])) {
                BaseStmt* result = IRContext.stmtManager.getTmplDefineArg(TmplDefineArgStmt::TypeNameID,name);
                return result;
            }
            throw std::logic_error("StmtVisitor::visitTmplDefineArg: Unknown Template");
        }

        std::any visitTmpleDefine(RiddleParser::TmpleDefineContext *ctx) override {
            std::vector<TmplDefineArgStmt *> args;
            for(const auto i: ctx->children) {
                if(!antlrcpp::is<antlr4::tree::TerminalNode*>(i)) {
                    args.push_back(dynamic_cast<TmplDefineArgStmt *>(std::any_cast<BaseStmt *>(visit(i))));
                }
            }
            BaseStmt *stmt = IRContext.stmtManager.getTmplDefineStmt(args);
            return stmt;
        }

        std::any visitBaseType(RiddleParser::BaseTypeContext *ctx) override {
            const std::string name = ctx->name->getText();
            BaseStmt *result = IRContext.stmtManager.getTypeStmt(name);
            return result;
        }

        std::any visitTmplType(RiddleParser::TmplTypeContext *ctx) override {
            const std::string name = ctx->name->getText();
            const auto TmplArgs = std::any_cast<std::vector<BaseStmt *>>(visit(ctx->tmpl));
            BaseStmt *result = IRContext.stmtManager.getTmplTypeStmt(name, TmplArgs);
            return result;
        }
    };

}// namespace Riddle
