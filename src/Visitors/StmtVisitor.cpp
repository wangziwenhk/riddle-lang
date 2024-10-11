#include "StmtVisitor.h"
import Types.Statements;
import Managers.StmtManager;

namespace Riddle {
    std::any StmtVisitor::visitProgram(RiddleParser::ProgramContext *ctx) {
        std::vector<BaseStmt *> stmts;
        for(const auto i: ctx->children) {
            stmts.push_back(std::any_cast<BaseStmt *>(visit(i)));
        }
        return IRContext.stmtManager.getProgram(stmts);
    }
    std::any StmtVisitor::visitStatement_ed(RiddleParser::Statement_edContext *ctx) {
        return visit(ctx->children[0]);
    }

    std::any StmtVisitor::visitInteger(RiddleParser::IntegerContext *ctx) {
        BaseStmt *result = IRContext.getStmtManager().getConstant(ctx->value);
        return result;
    }
    std::any StmtVisitor::visitFloat(RiddleParser::FloatContext *ctx) {
        BaseStmt *result = IRContext.getStmtManager().getConstant(ctx->value);
        return result;
    }
    std::any StmtVisitor::visitBoolean(RiddleParser::BooleanContext *ctx) {
        BaseStmt *result = IRContext.getStmtManager().getConstant(ctx->value);
        return result;
    }
    std::any StmtVisitor::visitNullExpr(RiddleParser::NullExprContext *context) {
        BaseStmt *result = IRContext.getStmtManager().getNull();
        return result;
    }

    std::any StmtVisitor::visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) {
        const std::string name = ctx->name->getText();
        std::string type;
        if(ctx->type != nullptr) {
            type = ctx->type->getText();
        }
        const auto value = std::any_cast<BaseStmt *>(visit(ctx->value));
        BaseStmt* stmt = IRContext.getStmtManager().getVarDefine(name, type, value);
        return stmt;
    }
    std::any StmtVisitor::visitWhileStatement(RiddleParser::WhileStatementContext *ctx) {
        const auto cond = std::any_cast<BaseStmt *>(visit(ctx->runCond));
        const auto body = std::any_cast<BaseStmt *>(visit(ctx->body));
        BaseStmt* stmt = IRContext.getStmtManager().getWhile(cond, body);
        return stmt;
    }
    std::any StmtVisitor::visitForStatement(RiddleParser::ForStatementContext *ctx) {
        const auto init = std::any_cast<BaseStmt *>(visit(ctx->init));
        const auto cond = std::any_cast<BaseStmt *>(visit(ctx->termCond));
        const auto changed = std::any_cast<BaseStmt *>(visit(ctx->selfVar));
        const auto body = std::any_cast<BaseStmt *>(visit(ctx->body));
        BaseStmt* stmt = IRContext.getStmtManager().getFor(init, cond, changed, body);
        return stmt;
    }


}// namespace Riddle