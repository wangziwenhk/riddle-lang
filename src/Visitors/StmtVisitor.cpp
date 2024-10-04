#include "StmtVisitor.h"

import Types.Statements;

namespace Riddle {
    std::any StmtVisitor::visitStatement_ed(RiddleParser::Statement_edContext *ctx) {
        return visit(ctx->children[0]);
    }

    std::any StmtVisitor::visitInteger(RiddleParser::IntegerContext *ctx) {
        auto result = IntegerStmt(ctx->value);
        return result;
    }
    std::any StmtVisitor::visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) {
        const std::string name = ctx->name->getText();
        return {};
    }

}// namespace Riddle