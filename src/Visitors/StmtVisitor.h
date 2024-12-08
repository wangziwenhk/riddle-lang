#ifndef STMTVISITOR_H
#define STMTVISITOR_H

#include <RiddleParserBaseVisitor.h>

import managers.StmtManager;
import IR.Context;
import Types.Statements;

namespace Riddle {
    /// 所有函数的返回值都为BaseStmt
    class StmtVisitor final : public RiddleParserBaseVisitor {
    protected:
        Context &IRContext;
        std::string packageName;
        RiddleParser* parser;

    public:
        explicit StmtVisitor(Context &ctx,RiddleParser* parser): IRContext(ctx), parser(parser) {}
        std::any visitProgram(RiddleParser::ProgramContext *ctx) override;
        std::any visitPackStatement(RiddleParser::PackStatementContext *ctx) override;
        std::any visitStatement(RiddleParser::StatementContext *ctx) override;
        std::any visitStatement_ed(RiddleParser::Statement_edContext *ctx) override;
        std::any visitInteger(RiddleParser::IntegerContext *ctx) override;
        std::any visitFloat(RiddleParser::FloatContext *ctx) override;
        std::any visitBoolean(RiddleParser::BooleanContext *ctx) override;
        std::any visitString(RiddleParser::StringContext *ctx) override;
        std::any visitNullExpr(RiddleParser::NullExprContext *ctx) override;
        std::any visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) override;
        std::any visitWhileStatement(RiddleParser::WhileStatementContext *ctx) override;
        std::any visitForStatement(RiddleParser::ForStatementContext *ctx) override;
        std::any visitReturnStatement(RiddleParser::ReturnStatementContext *ctx) override;
        std::any visitFuncDefine(RiddleParser::FuncDefineContext *ctx) override;
        std::any visitBodyExpr(RiddleParser::BodyExprContext *ctx) override;

        std::any visitObjectExpr(RiddleParser::ObjectExprContext *ctx) override;
        std::any visitExprPtrParser(RiddleParser::ExprPtrParserContext *context) override;

        std::any visitContinueStatement(RiddleParser::ContinueStatementContext *ctx) override;
        std::any visitBreakStatement(RiddleParser::BreakStatementContext *ctx) override;

        // 二元运算符号相关
        // 算数操作

        std::any visitAssignExpr(RiddleParser::AssignExprContext *ctx) override;
        std::any visitAddExpr(RiddleParser::AddExprContext *ctx) override;
        std::any visitSubExpr(RiddleParser::SubExprContext *ctx) override;
        std::any visitMulExpr(RiddleParser::MulExprContext *ctx) override;
        std::any visitDivExpr(RiddleParser::DivExprContext *ctx) override;
        std::any visitModExpr(RiddleParser::ModExprContext *ctx) override;

        // 位运算

        std::any visitBitAndExpr(RiddleParser::BitAndExprContext *ctx) override;
        std::any visitBitOrExpr(RiddleParser::BitOrExprContext *ctx) override;
        std::any visitBitXorExpr(RiddleParser::BitXorExprContext *ctx) override;

        // 逻辑操作
        std::any visitEqualExpr(RiddleParser::EqualExprContext *ctx) override;

        // 类
        std::any visitClassDefine(RiddleParser::ClassDefineContext *ctx) override;
    };

}// namespace Riddle

#endif//STMTVISITOR_H
