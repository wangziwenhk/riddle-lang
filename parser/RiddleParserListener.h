
// Generated from C:/Users/wangz/CLionProjects/Riddle-Language/RiddleParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "RiddleParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by RiddleParser.
 */
class  RiddleParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(RiddleParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(RiddleParser::ProgramContext *ctx) = 0;

  virtual void enterStatement_ed(RiddleParser::Statement_edContext *ctx) = 0;
  virtual void exitStatement_ed(RiddleParser::Statement_edContext *ctx) = 0;

  virtual void enterStatement(RiddleParser::StatementContext *ctx) = 0;
  virtual void exitStatement(RiddleParser::StatementContext *ctx) = 0;

  virtual void enterPackStatement(RiddleParser::PackStatementContext *ctx) = 0;
  virtual void exitPackStatement(RiddleParser::PackStatementContext *ctx) = 0;

  virtual void enterImportStatement(RiddleParser::ImportStatementContext *ctx) = 0;
  virtual void exitImportStatement(RiddleParser::ImportStatementContext *ctx) = 0;

  virtual void enterVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) = 0;
  virtual void exitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) = 0;

  virtual void enterArgsExpr(RiddleParser::ArgsExprContext *ctx) = 0;
  virtual void exitArgsExpr(RiddleParser::ArgsExprContext *ctx) = 0;

  virtual void enterDefineArgs(RiddleParser::DefineArgsContext *ctx) = 0;
  virtual void exitDefineArgs(RiddleParser::DefineArgsContext *ctx) = 0;

  virtual void enterFuncDefine(RiddleParser::FuncDefineContext *ctx) = 0;
  virtual void exitFuncDefine(RiddleParser::FuncDefineContext *ctx) = 0;

  virtual void enterFuncBody(RiddleParser::FuncBodyContext *ctx) = 0;
  virtual void exitFuncBody(RiddleParser::FuncBodyContext *ctx) = 0;

  virtual void enterForStatement(RiddleParser::ForStatementContext *ctx) = 0;
  virtual void exitForStatement(RiddleParser::ForStatementContext *ctx) = 0;

  virtual void enterWhileStatement(RiddleParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(RiddleParser::WhileStatementContext *ctx) = 0;

  virtual void enterIfStatement(RiddleParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(RiddleParser::IfStatementContext *ctx) = 0;

  virtual void enterReturnStatement(RiddleParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(RiddleParser::ReturnStatementContext *ctx) = 0;

  virtual void enterClassDefine(RiddleParser::ClassDefineContext *ctx) = 0;
  virtual void exitClassDefine(RiddleParser::ClassDefineContext *ctx) = 0;

  virtual void enterClassBody(RiddleParser::ClassBodyContext *ctx) = 0;
  virtual void exitClassBody(RiddleParser::ClassBodyContext *ctx) = 0;

  virtual void enterFuncExpr(RiddleParser::FuncExprContext *ctx) = 0;
  virtual void exitFuncExpr(RiddleParser::FuncExprContext *ctx) = 0;

  virtual void enterObjectExpr(RiddleParser::ObjectExprContext *ctx) = 0;
  virtual void exitObjectExpr(RiddleParser::ObjectExprContext *ctx) = 0;

  virtual void enterSelfSubRightExpr(RiddleParser::SelfSubRightExprContext *ctx) = 0;
  virtual void exitSelfSubRightExpr(RiddleParser::SelfSubRightExprContext *ctx) = 0;

  virtual void enterAndAssignExpr(RiddleParser::AndAssignExprContext *ctx) = 0;
  virtual void exitAndAssignExpr(RiddleParser::AndAssignExprContext *ctx) = 0;

  virtual void enterModExpr(RiddleParser::ModExprContext *ctx) = 0;
  virtual void exitModExpr(RiddleParser::ModExprContext *ctx) = 0;

  virtual void enterCastExpr(RiddleParser::CastExprContext *ctx) = 0;
  virtual void exitCastExpr(RiddleParser::CastExprContext *ctx) = 0;

  virtual void enterLShrExpr(RiddleParser::LShrExprContext *ctx) = 0;
  virtual void exitLShrExpr(RiddleParser::LShrExprContext *ctx) = 0;

  virtual void enterNegativeExpr(RiddleParser::NegativeExprContext *ctx) = 0;
  virtual void exitNegativeExpr(RiddleParser::NegativeExprContext *ctx) = 0;

  virtual void enterNumberExpr(RiddleParser::NumberExprContext *ctx) = 0;
  virtual void exitNumberExpr(RiddleParser::NumberExprContext *ctx) = 0;

  virtual void enterObjValExpr(RiddleParser::ObjValExprContext *ctx) = 0;
  virtual void exitObjValExpr(RiddleParser::ObjValExprContext *ctx) = 0;

  virtual void enterMulAssignExpr(RiddleParser::MulAssignExprContext *ctx) = 0;
  virtual void exitMulAssignExpr(RiddleParser::MulAssignExprContext *ctx) = 0;

  virtual void enterXorAssignExpr(RiddleParser::XorAssignExprContext *ctx) = 0;
  virtual void exitXorAssignExpr(RiddleParser::XorAssignExprContext *ctx) = 0;

  virtual void enterSubExpr(RiddleParser::SubExprContext *ctx) = 0;
  virtual void exitSubExpr(RiddleParser::SubExprContext *ctx) = 0;

  virtual void enterGreaterEqualExpr(RiddleParser::GreaterEqualExprContext *ctx) = 0;
  virtual void exitGreaterEqualExpr(RiddleParser::GreaterEqualExprContext *ctx) = 0;

  virtual void enterAddAssignExpr(RiddleParser::AddAssignExprContext *ctx) = 0;
  virtual void exitAddAssignExpr(RiddleParser::AddAssignExprContext *ctx) = 0;

  virtual void enterOrAssignExpr(RiddleParser::OrAssignExprContext *ctx) = 0;
  virtual void exitOrAssignExpr(RiddleParser::OrAssignExprContext *ctx) = 0;

  virtual void enterBitXorExpr(RiddleParser::BitXorExprContext *ctx) = 0;
  virtual void exitBitXorExpr(RiddleParser::BitXorExprContext *ctx) = 0;

  virtual void enterPtrExpr(RiddleParser::PtrExprContext *ctx) = 0;
  virtual void exitPtrExpr(RiddleParser::PtrExprContext *ctx) = 0;

  virtual void enterStringExpr(RiddleParser::StringExprContext *ctx) = 0;
  virtual void exitStringExpr(RiddleParser::StringExprContext *ctx) = 0;

  virtual void enterGreaterExpr(RiddleParser::GreaterExprContext *ctx) = 0;
  virtual void exitGreaterExpr(RiddleParser::GreaterExprContext *ctx) = 0;

  virtual void enterDivAssignExpr(RiddleParser::DivAssignExprContext *ctx) = 0;
  virtual void exitDivAssignExpr(RiddleParser::DivAssignExprContext *ctx) = 0;

  virtual void enterMulExpr(RiddleParser::MulExprContext *ctx) = 0;
  virtual void exitMulExpr(RiddleParser::MulExprContext *ctx) = 0;

  virtual void enterNotEqualExpr(RiddleParser::NotEqualExprContext *ctx) = 0;
  virtual void exitNotEqualExpr(RiddleParser::NotEqualExprContext *ctx) = 0;

  virtual void enterSelfSubLeftExpr(RiddleParser::SelfSubLeftExprContext *ctx) = 0;
  virtual void exitSelfSubLeftExpr(RiddleParser::SelfSubLeftExprContext *ctx) = 0;

  virtual void enterDivExpr(RiddleParser::DivExprContext *ctx) = 0;
  virtual void exitDivExpr(RiddleParser::DivExprContext *ctx) = 0;

  virtual void enterBitAndExpr(RiddleParser::BitAndExprContext *ctx) = 0;
  virtual void exitBitAndExpr(RiddleParser::BitAndExprContext *ctx) = 0;

  virtual void enterAssignExpr(RiddleParser::AssignExprContext *ctx) = 0;
  virtual void exitAssignExpr(RiddleParser::AssignExprContext *ctx) = 0;

  virtual void enterSelfAddRightExpr(RiddleParser::SelfAddRightExprContext *ctx) = 0;
  virtual void exitSelfAddRightExpr(RiddleParser::SelfAddRightExprContext *ctx) = 0;

  virtual void enterSubAssignExpr(RiddleParser::SubAssignExprContext *ctx) = 0;
  virtual void exitSubAssignExpr(RiddleParser::SubAssignExprContext *ctx) = 0;

  virtual void enterBracketExpr(RiddleParser::BracketExprContext *ctx) = 0;
  virtual void exitBracketExpr(RiddleParser::BracketExprContext *ctx) = 0;

  virtual void enterBooleanExpr(RiddleParser::BooleanExprContext *ctx) = 0;
  virtual void exitBooleanExpr(RiddleParser::BooleanExprContext *ctx) = 0;

  virtual void enterAShrExpr(RiddleParser::AShrExprContext *ctx) = 0;
  virtual void exitAShrExpr(RiddleParser::AShrExprContext *ctx) = 0;

  virtual void enterLessExpr(RiddleParser::LessExprContext *ctx) = 0;
  virtual void exitLessExpr(RiddleParser::LessExprContext *ctx) = 0;

  virtual void enterOrExpr(RiddleParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(RiddleParser::OrExprContext *ctx) = 0;

  virtual void enterSelfAddLeftExpr(RiddleParser::SelfAddLeftExprContext *ctx) = 0;
  virtual void exitSelfAddLeftExpr(RiddleParser::SelfAddLeftExprContext *ctx) = 0;

  virtual void enterLShrAssignExpr(RiddleParser::LShrAssignExprContext *ctx) = 0;
  virtual void exitLShrAssignExpr(RiddleParser::LShrAssignExprContext *ctx) = 0;

  virtual void enterLessEqualExpr(RiddleParser::LessEqualExprContext *ctx) = 0;
  virtual void exitLessEqualExpr(RiddleParser::LessEqualExprContext *ctx) = 0;

  virtual void enterAShrAssignExpr(RiddleParser::AShrAssignExprContext *ctx) = 0;
  virtual void exitAShrAssignExpr(RiddleParser::AShrAssignExprContext *ctx) = 0;

  virtual void enterBitOrExpr(RiddleParser::BitOrExprContext *ctx) = 0;
  virtual void exitBitOrExpr(RiddleParser::BitOrExprContext *ctx) = 0;

  virtual void enterNotExpr(RiddleParser::NotExprContext *ctx) = 0;
  virtual void exitNotExpr(RiddleParser::NotExprContext *ctx) = 0;

  virtual void enterAddExpr(RiddleParser::AddExprContext *ctx) = 0;
  virtual void exitAddExpr(RiddleParser::AddExprContext *ctx) = 0;

  virtual void enterShlAssignExpr(RiddleParser::ShlAssignExprContext *ctx) = 0;
  virtual void exitShlAssignExpr(RiddleParser::ShlAssignExprContext *ctx) = 0;

  virtual void enterModAssignExpr(RiddleParser::ModAssignExprContext *ctx) = 0;
  virtual void exitModAssignExpr(RiddleParser::ModAssignExprContext *ctx) = 0;

  virtual void enterPositiveExpr(RiddleParser::PositiveExprContext *ctx) = 0;
  virtual void exitPositiveExpr(RiddleParser::PositiveExprContext *ctx) = 0;

  virtual void enterShlExpr(RiddleParser::ShlExprContext *ctx) = 0;
  virtual void exitShlExpr(RiddleParser::ShlExprContext *ctx) = 0;

  virtual void enterEqualExpr(RiddleParser::EqualExprContext *ctx) = 0;
  virtual void exitEqualExpr(RiddleParser::EqualExprContext *ctx) = 0;

  virtual void enterAndExpr(RiddleParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(RiddleParser::AndExprContext *ctx) = 0;

  virtual void enterId(RiddleParser::IdContext *ctx) = 0;
  virtual void exitId(RiddleParser::IdContext *ctx) = 0;

  virtual void enterNumber(RiddleParser::NumberContext *ctx) = 0;
  virtual void exitNumber(RiddleParser::NumberContext *ctx) = 0;

  virtual void enterBoolean(RiddleParser::BooleanContext *ctx) = 0;
  virtual void exitBoolean(RiddleParser::BooleanContext *ctx) = 0;

  virtual void enterString(RiddleParser::StringContext *ctx) = 0;
  virtual void exitString(RiddleParser::StringContext *ctx) = 0;

  virtual void enterFloat(RiddleParser::FloatContext *ctx) = 0;
  virtual void exitFloat(RiddleParser::FloatContext *ctx) = 0;

  virtual void enterInteger(RiddleParser::IntegerContext *ctx) = 0;
  virtual void exitInteger(RiddleParser::IntegerContext *ctx) = 0;

  virtual void enterTemplateArg(RiddleParser::TemplateArgContext *ctx) = 0;
  virtual void exitTemplateArg(RiddleParser::TemplateArgContext *ctx) = 0;

  virtual void enterTemplateArgs(RiddleParser::TemplateArgsContext *ctx) = 0;
  virtual void exitTemplateArgs(RiddleParser::TemplateArgsContext *ctx) = 0;

  virtual void enterTypeName(RiddleParser::TypeNameContext *ctx) = 0;
  virtual void exitTypeName(RiddleParser::TypeNameContext *ctx) = 0;


};

