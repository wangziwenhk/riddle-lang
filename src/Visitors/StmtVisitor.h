#ifndef STATVISITOR_H
#define STATVISITOR_H

#include <RiddleParserBaseVisitor.h>

namespace Riddle {

    class StmtVisitor final : RiddleParserBaseVisitor{
        std::any visitStatement_ed(RiddleParser::Statement_edContext *ctx) override;
        std::any visitInteger(RiddleParser::IntegerContext *ctx) override;
        std::any visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) override;
    };

}// namespace Riddle

#endif//STATVISITOR_H
