#ifndef STMTVISITOR_H
#define STMTVISITOR_H

#include <RiddleParserBaseVisitor.h>

import Managers.StmtManager;
import IR.Context;
namespace Riddle {
    /// 所有函数的返回值都为BaseStmt
    class StmtVisitor final : public RiddleParserBaseVisitor {
        Context &IRContext;

    public:
        explicit StmtVisitor(Context &ctx): IRContext(ctx) {}
        std::any visitProgram(RiddleParser::ProgramContext *ctx) override;
        std::any visitStatement_ed(RiddleParser::Statement_edContext *ctx) override;
        std::any visitInteger(RiddleParser::IntegerContext *ctx) override;
        std::any visitFloat(RiddleParser::FloatContext *ctx) override;
        std::any visitBoolean(RiddleParser::BooleanContext *ctx) override;
        std::any visitNullExpr(RiddleParser::NullExprContext *context) override;
        std::any visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) override;
        std::any visitWhileStatement(RiddleParser::WhileStatementContext *ctx) override;
        std::any visitForStatement(RiddleParser::ForStatementContext *ctx) override;
    };

}// namespace Riddle

#endif//STMTVISITOR_H
