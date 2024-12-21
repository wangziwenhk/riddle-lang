#include "StmtVisitor.h"

#include <llvm/IR/DerivedTypes.h>
import managers.StmtManager;

namespace Riddle {
    std::any StmtVisitor::visitProgram(RiddleParser::ProgramContext *ctx) {
        std::vector<BaseStmt *> stmts;
        for(const auto i: ctx->children) {
            auto it = visit(i);
            if(!it.has_value()) {
                throw std::logic_error("result is null");
            }
            const auto stmt = std::any_cast<BaseStmt *>(it);
            // 处理空语句
            if(stmt->getStmtTypeID() == BaseStmt::StmtTypeID::NoneStmtID) {
                continue;
            }
            stmts.push_back(stmt);
        }
        return IRContext.stmtManager.getProgram(stmts);
    }
    std::any StmtVisitor::visitPackStatement(RiddleParser::PackStatementContext *ctx) {
        packageName = ctx->packName->getText();
        IRContext.module.setModuleIdentifier(packageName);
        BaseStmt *stmt = IRContext.stmtManager.getNoneStmt();
        return stmt;
    }
    std::any StmtVisitor::visitStatement(RiddleParser::StatementContext *ctx) {
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
    std::any StmtVisitor::visitStatement_ed(RiddleParser::Statement_edContext *ctx) {
        return visit(ctx->children[0]);
    }

    std::any StmtVisitor::visitInteger(RiddleParser::IntegerContext *ctx) {
        BaseStmt *result = IRContext.stmtManager.getConstant(ctx->value);
        return result;
    }
    std::any StmtVisitor::visitFloat(RiddleParser::FloatContext *ctx) {
        BaseStmt *result = IRContext.stmtManager.getConstant(ctx->value);
        return result;
    }
    std::any StmtVisitor::visitBoolean(RiddleParser::BooleanContext *ctx) {
        BaseStmt *result = IRContext.stmtManager.getConstant(ctx->value);
        return result;
    }
    std::any StmtVisitor::visitString(RiddleParser::StringContext *ctx) {
        const std::string value = ctx->getText();
        BaseStmt *result = IRContext.stmtManager.getConstant(value.substr(1, value.size() - 2));
        return result;
    }
    std::any StmtVisitor::visitNullExpr(RiddleParser::NullExprContext *ctx) {
        BaseStmt *result = IRContext.stmtManager.getNull();
        return result;
    }

    std::any StmtVisitor::visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) {
        if(ctx->name == nullptr) {
            throw std::logic_error("name is null");
            return {};
        }
        const std::string name = ctx->name->getText();
        std::string type;
        if(ctx->type != nullptr) {
            type = ctx->type->getText();
        }
        BaseStmt *value = IRContext.stmtManager.getNoneStmt();
        ;
        if(ctx->value != nullptr) {
            value = std::any_cast<BaseStmt *>(visit(ctx->value));
        }
        BaseStmt *stmt = IRContext.stmtManager.getVarDefine(name, type, value);
        return stmt;
    }
    std::any StmtVisitor::visitIfStatement(RiddleParser::IfStatementContext *ctx) {
        const auto cond = std::any_cast<BaseStmt *>(visit(ctx->cond));
        const auto thenBody = std::any_cast<BaseStmt *>(visit(ctx->body));
        const auto elseBody = std::any_cast<BaseStmt *>(visit(ctx->elseBody));
        BaseStmt *stmt = IRContext.stmtManager.getIf(cond, thenBody, elseBody);
        return stmt;
    }
    std::any StmtVisitor::visitWhileStatement(RiddleParser::WhileStatementContext *ctx) {
        const auto cond = std::any_cast<BaseStmt *>(visit(ctx->runCond));
        const auto body = std::any_cast<BaseStmt *>(visit(ctx->body));
        BaseStmt *stmt = IRContext.stmtManager.getWhile(cond, body);
        return stmt;
    }
    std::any StmtVisitor::visitForStatement(RiddleParser::ForStatementContext *ctx) {
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
    std::any StmtVisitor::visitReturnStatement(RiddleParser::ReturnStatementContext *ctx) {
        BaseStmt *val = nullptr;
        if(ctx->result != nullptr) {
            val = std::any_cast<BaseStmt *>(visit(ctx->result));
        }
        BaseStmt *stmt = IRContext.stmtManager.getReturn(val);
        return stmt;
    }
    std::any StmtVisitor::visitDefineArgs(RiddleParser::DefineArgsContext *ctx) {
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
            value = IRContext.stmtManager.getNoneStmt();
        }
        BaseStmt *stmt = IRContext.stmtManager.getDefineArgList(args);
        return stmt;
    }
    std::any StmtVisitor::visitFuncDefine(RiddleParser::FuncDefineContext *ctx) {
        const auto funcName = ctx->funcName->getText();
        std::string returnType;
        if(ctx->returnType != nullptr) {
            returnType = ctx->returnType->getText();
        } else {
            returnType = "void";
        }
        auto body = std::any_cast<BaseStmt *>(visit(ctx->body));
        DefineArgListStmt *args = nullptr;
        if(!ctx->args->children.empty()) {
            args = dynamic_cast<DefineArgListStmt *>(std::any_cast<BaseStmt *>(visit(ctx->args)));
        }
        auto it = dynamic_cast<BlockStmt *>(body);
        BaseStmt *stmt = IRContext.stmtManager.getFuncDefine(funcName, returnType, body, args);
        return stmt;
    }
    std::any StmtVisitor::visitBodyExpr(RiddleParser::BodyExprContext *ctx) {
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
    std::any StmtVisitor::visitFuncExpr(RiddleParser::FuncExprContext *ctx) {
        const std::string funcName = ctx->funcName->getText();
        const auto args = dynamic_cast<ArgListStmt *>(any_cast<BaseStmt *>(visit(ctx->args)));
        BaseStmt *stmt = IRContext.stmtManager.getFuncCall(funcName, args);
        return stmt;
    }
    std::any StmtVisitor::visitArgsExpr(RiddleParser::ArgsExprContext *ctx) {
        std::vector<BaseStmt *> args;
        for(auto i: ctx->children) {
            args.push_back(std::any_cast<BaseStmt *>(visit(i)));
        }
        BaseStmt *stmt = IRContext.stmtManager.getArgList(args);
        return stmt;
    }

    std::any StmtVisitor::visitObjectExpr(RiddleParser::ObjectExprContext *ctx) {
        BaseStmt *stmt = IRContext.stmtManager.getObject(ctx->getText());
        return stmt;
    }
    std::any StmtVisitor::visitExprPtrParser(RiddleParser::ExprPtrParserContext *ctx) {
        return visit(ctx->children[0]);
    }

    std::any StmtVisitor::visitContinueStatement(RiddleParser::ContinueStatementContext *ctx) {
        BaseStmt *stmt = IRContext.stmtManager.getContinue();
        return stmt;
    }

    std::any StmtVisitor::visitBreakStatement(RiddleParser::BreakStatementContext *ctx) {
        BaseStmt *stmt = IRContext.stmtManager.getBreak();
        return stmt;
    }

    std::any StmtVisitor::visitAssignExpr(RiddleParser::AssignExprContext *ctx) {
        const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
        const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
        BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "=");
        return stmt;
    }

    std::any StmtVisitor::visitAddExpr(RiddleParser::AddExprContext *ctx) {
        const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
        const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
        BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "+");
        return stmt;
    }

    std::any StmtVisitor::visitSubExpr(RiddleParser::SubExprContext *ctx) {
        const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
        const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
        BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "-");
        return stmt;
    }

    std::any StmtVisitor::visitMulExpr(RiddleParser::MulExprContext *ctx) {
        const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
        const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
        BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "*");
        return stmt;
    }

    std::any StmtVisitor::visitDivExpr(RiddleParser::DivExprContext *ctx) {
        const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
        const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
        BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "/");
        return stmt;
    }

    std::any StmtVisitor::visitModExpr(RiddleParser::ModExprContext *ctx) {
        const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
        const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
        BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "%");
        return stmt;
    }

    std::any StmtVisitor::visitBitAndExpr(RiddleParser::BitAndExprContext *ctx) {
        const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
        const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
        BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "&");
        return stmt;
    }

    std::any StmtVisitor::visitBitOrExpr(RiddleParser::BitOrExprContext *ctx) {
        const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
        const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
        BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "|");
        return stmt;
    }

    std::any StmtVisitor::visitBitXorExpr(RiddleParser::BitXorExprContext *ctx) {
        const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
        const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
        BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "^");
        return stmt;
    }

    std::any StmtVisitor::visitEqualExpr(RiddleParser::EqualExprContext *ctx) {
        const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
        const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
        BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "==");
        return stmt;
    }
    std::any StmtVisitor::visitLessExpr(RiddleParser::LessExprContext *ctx) {
        const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
        const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
        BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, "<");
        return stmt;
    }
    std::any StmtVisitor::visitGreaterExpr(RiddleParser::GreaterExprContext *ctx) {
        const auto lhs = std::any_cast<BaseStmt *>(visit(ctx->left));
        const auto rhs = std::any_cast<BaseStmt *>(visit(ctx->right));
        BaseStmt *stmt = IRContext.stmtManager.getBinaryExpr(lhs, rhs, ">");
        return stmt;
    }
    std::any StmtVisitor::visitClassDefine(RiddleParser::ClassDefineContext *ctx) {
        const std::string className = ctx->className->getText();
        const auto t_body = std::any_cast<BaseStmt *>(visit(ctx->body));
        const auto body = dynamic_cast<BlockStmt *>(t_body);

        std::vector<VarDefineStmt *> varDefs;
        std::vector<FuncDefineStmt *> funcDefines;
        for(const auto i: body->stmts) {
            if(i->getStmtTypeID() == BaseStmt::StmtTypeID::VarDefineStmtID) {
                varDefs.push_back(dynamic_cast<VarDefineStmt *>(i));
            } else if(i->getStmtTypeID() == BaseStmt::StmtTypeID::FuncDefineStmtID) {
                funcDefines.push_back(dynamic_cast<FuncDefineStmt *>(i));
            }
        }
        BaseStmt *stmt = IRContext.stmtManager.getClassDefine(className, varDefs, funcDefines);
        return stmt;
    }


}// namespace Riddle