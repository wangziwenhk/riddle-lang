
// Generated from C:/Users/wangz/CLionProjects/Riddle-Language/RiddleParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "RiddleParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by RiddleParser.
 */
class  RiddleParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by RiddleParser.
   */
    virtual std::any visitProgram(RiddleParser::ProgramContext *context) = 0;

    virtual std::any visitStatement_ed(RiddleParser::Statement_edContext *context) = 0;

    virtual std::any visitStatement(RiddleParser::StatementContext *context) = 0;

    virtual std::any visitPackStatement(RiddleParser::PackStatementContext *context) = 0;

    virtual std::any visitImportStatement(RiddleParser::ImportStatementContext *context) = 0;

    virtual std::any visitVarDefineStatement(RiddleParser::VarDefineStatementContext *context) = 0;

    virtual std::any visitArgsExpr(RiddleParser::ArgsExprContext *context) = 0;

    virtual std::any visitDefineArgs(RiddleParser::DefineArgsContext *context) = 0;

    virtual std::any visitFuncDefine(RiddleParser::FuncDefineContext *context) = 0;

    virtual std::any visitFuncBody(RiddleParser::FuncBodyContext *context) = 0;

    virtual std::any visitForStatement(RiddleParser::ForStatementContext *context) = 0;

    virtual std::any visitWhileStatement(RiddleParser::WhileStatementContext *context) = 0;

    virtual std::any visitIfStatement(RiddleParser::IfStatementContext *context) = 0;

    virtual std::any visitReturnStatement(RiddleParser::ReturnStatementContext *context) = 0;

    virtual std::any visitClassDefine(RiddleParser::ClassDefineContext *context) = 0;

    virtual std::any visitClassBody(RiddleParser::ClassBodyContext *context) = 0;

    virtual std::any visitFuncExpr(RiddleParser::FuncExprContext *context) = 0;

    virtual std::any visitObjectExpr(RiddleParser::ObjectExprContext *context) = 0;

    virtual std::any visitBlendExpr(RiddleParser::BlendExprContext *context) = 0;

    virtual std::any visitSelfSubRightExpr(RiddleParser::SelfSubRightExprContext *context) = 0;

    virtual std::any visitAndAssignExpr(RiddleParser::AndAssignExprContext *context) = 0;

    virtual std::any visitModExpr(RiddleParser::ModExprContext *context) = 0;

    virtual std::any visitCastExpr(RiddleParser::CastExprContext *context) = 0;

    virtual std::any visitLShrExpr(RiddleParser::LShrExprContext *context) = 0;

    virtual std::any visitNegativeExpr(RiddleParser::NegativeExprContext *context) = 0;

    virtual std::any visitNumberExpr(RiddleParser::NumberExprContext *context) = 0;

    virtual std::any visitMulAssignExpr(RiddleParser::MulAssignExprContext *context) = 0;

    virtual std::any visitXorAssignExpr(RiddleParser::XorAssignExprContext *context) = 0;

    virtual std::any visitSubExpr(RiddleParser::SubExprContext *context) = 0;

    virtual std::any visitGreaterEqualExpr(RiddleParser::GreaterEqualExprContext *context) = 0;

    virtual std::any visitAddAssignExpr(RiddleParser::AddAssignExprContext *context) = 0;

    virtual std::any visitOrAssignExpr(RiddleParser::OrAssignExprContext *context) = 0;

    virtual std::any visitBitXorExpr(RiddleParser::BitXorExprContext *context) = 0;

    virtual std::any visitPtrExpr(RiddleParser::PtrExprContext *context) = 0;

    virtual std::any visitStringExpr(RiddleParser::StringExprContext *context) = 0;

    virtual std::any visitGreaterExpr(RiddleParser::GreaterExprContext *context) = 0;

    virtual std::any visitDivAssignExpr(RiddleParser::DivAssignExprContext *context) = 0;

    virtual std::any visitMulExpr(RiddleParser::MulExprContext *context) = 0;

    virtual std::any visitNotEqualExpr(RiddleParser::NotEqualExprContext *context) = 0;

    virtual std::any visitSelfSubLeftExpr(RiddleParser::SelfSubLeftExprContext *context) = 0;

    virtual std::any visitDivExpr(RiddleParser::DivExprContext *context) = 0;

    virtual std::any visitBitAndExpr(RiddleParser::BitAndExprContext *context) = 0;

    virtual std::any visitAssignExpr(RiddleParser::AssignExprContext *context) = 0;

    virtual std::any visitSelfAddRightExpr(RiddleParser::SelfAddRightExprContext *context) = 0;

    virtual std::any visitSubAssignExpr(RiddleParser::SubAssignExprContext *context) = 0;

    virtual std::any visitBracketExpr(RiddleParser::BracketExprContext *context) = 0;

    virtual std::any visitBooleanExpr(RiddleParser::BooleanExprContext *context) = 0;

    virtual std::any visitAShrExpr(RiddleParser::AShrExprContext *context) = 0;

    virtual std::any visitLessExpr(RiddleParser::LessExprContext *context) = 0;

    virtual std::any visitOrExpr(RiddleParser::OrExprContext *context) = 0;

    virtual std::any visitSelfAddLeftExpr(RiddleParser::SelfAddLeftExprContext *context) = 0;

    virtual std::any visitLShrAssignExpr(RiddleParser::LShrAssignExprContext *context) = 0;

    virtual std::any visitLessEqualExpr(RiddleParser::LessEqualExprContext *context) = 0;

    virtual std::any visitAShrAssignExpr(RiddleParser::AShrAssignExprContext *context) = 0;

    virtual std::any visitBitOrExpr(RiddleParser::BitOrExprContext *context) = 0;

    virtual std::any visitNotExpr(RiddleParser::NotExprContext *context) = 0;

    virtual std::any visitAddExpr(RiddleParser::AddExprContext *context) = 0;

    virtual std::any visitShlAssignExpr(RiddleParser::ShlAssignExprContext *context) = 0;

    virtual std::any visitModAssignExpr(RiddleParser::ModAssignExprContext *context) = 0;

    virtual std::any visitPositiveExpr(RiddleParser::PositiveExprContext *context) = 0;

    virtual std::any visitShlExpr(RiddleParser::ShlExprContext *context) = 0;

    virtual std::any visitEqualExpr(RiddleParser::EqualExprContext *context) = 0;

    virtual std::any visitAndExpr(RiddleParser::AndExprContext *context) = 0;

    virtual std::any visitId(RiddleParser::IdContext *context) = 0;

    virtual std::any visitNumber(RiddleParser::NumberContext *context) = 0;

    virtual std::any visitBoolean(RiddleParser::BooleanContext *context) = 0;

    virtual std::any visitString(RiddleParser::StringContext *context) = 0;

    virtual std::any visitFloat(RiddleParser::FloatContext *context) = 0;

    virtual std::any visitInteger(RiddleParser::IntegerContext *context) = 0;

    virtual std::any visitTemplateArg(RiddleParser::TemplateArgContext *context) = 0;

    virtual std::any visitTemplateArgs(RiddleParser::TemplateArgsContext *context) = 0;

    virtual std::any visitTypeName(RiddleParser::TypeNameContext *context) = 0;


};

