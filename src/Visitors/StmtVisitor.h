    #ifndef STMTVISITOR_H
#define STMTVISITOR_H

#include <RiddleParserBaseVisitor.h>

import Managers.StmtManager;

namespace Riddle {
    /// 所有函数的返回值都为BaseStmt
    class StmtVisitor final : RiddleParserBaseVisitor {
        StmtManager stmt_manager{};

    public:
        std::any visitProgram(RiddleParser::ProgramContext *ctx) override;
        std::any visitStatement_ed(RiddleParser::Statement_edContext *ctx) override;
        std::any visitInteger(RiddleParser::IntegerContext *ctx) override;
        std::any visitFloat(RiddleParser::FloatContext *ctx) override;
        std::any visitBoolean(RiddleParser::BooleanContext *ctx) override;
        std::any visitNullExpr(RiddleParser::NullExprContext *context) override;
        std::any visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) override;
    };

}// namespace Riddle

#endif//STMTVISITOR_H
