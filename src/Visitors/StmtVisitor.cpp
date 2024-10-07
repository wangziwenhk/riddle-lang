#include "StmtVisitor.h"
import Types.Statements;
import Managers.StmtManager;

namespace Riddle {
    std::any StmtVisitor::visitProgram(RiddleParser::ProgramContext *ctx) {
        std::vector<BaseStmt *> stmts;
        for(auto i: ctx->children) {
            stmts.push_back(std::any_cast<BaseStmt *>(visit(i)));
        }
        return stmts;
    }
    std::any StmtVisitor::visitStatement_ed(RiddleParser::Statement_edContext *ctx) {
        return visit(ctx->children[0]);
    }

    std::any StmtVisitor::visitInteger(RiddleParser::IntegerContext *ctx) {
        BaseStmt *result = stmt_manager.getConstant(ctx->value);
        return result;
    }
    std::any StmtVisitor::visitFloat(RiddleParser::FloatContext *ctx) {
        BaseStmt *result = stmt_manager.getConstant(ctx->value);
        return result;
    }
    std::any StmtVisitor::visitBoolean(RiddleParser::BooleanContext *ctx) {
        BaseStmt *result = stmt_manager.getConstant(ctx->value);
        return result;
    }
    std::any StmtVisitor::visitNullExpr(RiddleParser::NullExprContext *context) {
        BaseStmt *result = stmt_manager.getNull();
        return result;
    }

    std::any StmtVisitor::visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) {
        const std::string name = ctx->name->getText();
        std::string type;
        if(ctx->type != nullptr) {
            type = ctx->type->getText();
        }
        const auto value = std::any_cast<BaseStmt *>(visit(ctx->value));
        return stmt_manager.getVarDefine(name, type, value);
    }
    std::any StmtVisitor::visitWhileStatement(RiddleParser::WhileStatementContext *ctx) {
        const auto cond = std::any_cast<BaseStmt *>(visit(ctx->runCond));
        const auto body = std::any_cast<BaseStmt *>(visit(ctx->body));
        return stmt_manager.getWhile(cond, body);
    }
    std::any StmtVisitor::visitForStatement(RiddleParser::ForStatementContext *ctx) {
        const auto init = std::any_cast<BaseStmt *>(visit(ctx->init));
        const auto cond = std::any_cast<BaseStmt *>(visit(ctx->termCond));
        const auto changed = std::any_cast<BaseStmt *>(visit(ctx->selfVar));
        const auto body = std::any_cast<BaseStmt *>(visit(ctx->body));
        return stmt_manager.getFor(init, cond, changed, body);
    }


}// namespace Riddle