#include "StmtVisitor.h"
import Manager.StmtManager;

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
        BaseStmt *stmt = IRContext.stmtManager.getNone();
        return stmt;
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
        BaseStmt *result = IRContext.stmtManager.getConstant(value.substr(0, value.size() - 1));
        return result;
    }
    std::any StmtVisitor::visitNullExpr(RiddleParser::NullExprContext *ctx) {
        BaseStmt *result = IRContext.stmtManager.getNull();
        return result;
    }


    std::any StmtVisitor::visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) {
        const std::string name = ctx->name->getText();
        std::string type;
        if(ctx->type != nullptr) {
            type = ctx->type->getText();
        }
        const auto value = std::any_cast<BaseStmt *>(visit(ctx->value));
        BaseStmt *stmt = IRContext.stmtManager.getVarDefine(name, type, value);
        return stmt;
    }
    std::any StmtVisitor::visitWhileStatement(RiddleParser::WhileStatementContext *ctx) {
        const auto cond = std::any_cast<BaseStmt *>(visit(ctx->runCond));
        const auto body = std::any_cast<BaseStmt *>(visit(ctx->body));
        BaseStmt *stmt = IRContext.stmtManager.getWhile(cond, body);
        return stmt;
    }
    std::any StmtVisitor::visitForStatement(RiddleParser::ForStatementContext *ctx) {
        BaseStmt *cond = IRContext.stmtManager.getNone();
        BaseStmt *init = IRContext.stmtManager.getNone();
        BaseStmt *change = IRContext.stmtManager.getNone();
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
        const auto val = std::any_cast<BaseStmt *>(visit(ctx->result));
        BaseStmt *stmt = IRContext.stmtManager.getReturn(val);
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
        const auto body = std::any_cast<BaseStmt *>(visit(ctx->body));
        DefineArgListStmt *args = nullptr;
        if(!ctx->args->children.empty()) {
            args = dynamic_cast<DefineArgListStmt *>(std::any_cast<BaseStmt *>(visit(ctx->args)));
        }
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

    std::any StmtVisitor::visitObjectExpr(RiddleParser::ObjectExprContext *ctx) {
        BaseStmt *stmt = IRContext.stmtManager.getObject(ctx->getText());
        return stmt;
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
        const auto lhs = std::any_cast<BaseStmt *>(ctx->left);
        const auto rhs = std::any_cast<BaseStmt *>(ctx->right);
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

}// namespace Riddle