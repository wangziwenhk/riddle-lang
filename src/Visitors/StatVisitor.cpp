#include "StatVisitor.h"

namespace Riddle {
    std::any StatVisitor::visitStatement_ed(RiddleParser::Statement_edContext *ctx) {
        return visit(ctx->children[0]);
    }

    std::any StatVisitor::visitInteger(RiddleParser::IntegerContext *ctx) {
        return ctx->value;
    }
    std::any StatVisitor::visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) {
        const std::string name = ctx->name->getText();
        return {};
    }

}// namespace Riddle