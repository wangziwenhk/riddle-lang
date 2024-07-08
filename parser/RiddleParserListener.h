
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

  virtual void enterStatment_ed(RiddleParser::Statment_edContext *ctx) = 0;
  virtual void exitStatment_ed(RiddleParser::Statment_edContext *ctx) = 0;

  virtual void enterStatment(RiddleParser::StatmentContext *ctx) = 0;
  virtual void exitStatment(RiddleParser::StatmentContext *ctx) = 0;

  virtual void enterPackStatment(RiddleParser::PackStatmentContext *ctx) = 0;
  virtual void exitPackStatment(RiddleParser::PackStatmentContext *ctx) = 0;

  virtual void enterImportStatment(RiddleParser::ImportStatmentContext *ctx) = 0;
  virtual void exitImportStatment(RiddleParser::ImportStatmentContext *ctx) = 0;

  virtual void enterVarStatment(RiddleParser::VarStatmentContext *ctx) = 0;
  virtual void exitVarStatment(RiddleParser::VarStatmentContext *ctx) = 0;

  virtual void enterFuncExpr(RiddleParser::FuncExprContext *ctx) = 0;
  virtual void exitFuncExpr(RiddleParser::FuncExprContext *ctx) = 0;

  virtual void enterArgsExpr(RiddleParser::ArgsExprContext *ctx) = 0;
  virtual void exitArgsExpr(RiddleParser::ArgsExprContext *ctx) = 0;

  virtual void enterDefineArgs(RiddleParser::DefineArgsContext *ctx) = 0;
  virtual void exitDefineArgs(RiddleParser::DefineArgsContext *ctx) = 0;

  virtual void enterFuncDefine(RiddleParser::FuncDefineContext *ctx) = 0;
  virtual void exitFuncDefine(RiddleParser::FuncDefineContext *ctx) = 0;

  virtual void enterForStatment(RiddleParser::ForStatmentContext *ctx) = 0;
  virtual void exitForStatment(RiddleParser::ForStatmentContext *ctx) = 0;

  virtual void enterWhileStatment(RiddleParser::WhileStatmentContext *ctx) = 0;
  virtual void exitWhileStatment(RiddleParser::WhileStatmentContext *ctx) = 0;

  virtual void enterIfStatment(RiddleParser::IfStatmentContext *ctx) = 0;
  virtual void exitIfStatment(RiddleParser::IfStatmentContext *ctx) = 0;

  virtual void enterReturnStatment(RiddleParser::ReturnStatmentContext *ctx) = 0;
  virtual void exitReturnStatment(RiddleParser::ReturnStatmentContext *ctx) = 0;

  virtual void enterStarExpr(RiddleParser::StarExprContext *ctx) = 0;
  virtual void exitStarExpr(RiddleParser::StarExprContext *ctx) = 0;

  virtual void enterAndAssignExpr(RiddleParser::AndAssignExprContext *ctx) = 0;
  virtual void exitAndAssignExpr(RiddleParser::AndAssignExprContext *ctx) = 0;

  virtual void enterSelfSubRightExpr(RiddleParser::SelfSubRightExprContext *ctx) = 0;
  virtual void exitSelfSubRightExpr(RiddleParser::SelfSubRightExprContext *ctx) = 0;

  virtual void enterObjectExpr(RiddleParser::ObjectExprContext *ctx) = 0;
  virtual void exitObjectExpr(RiddleParser::ObjectExprContext *ctx) = 0;

  virtual void enterModExpr(RiddleParser::ModExprContext *ctx) = 0;
  virtual void exitModExpr(RiddleParser::ModExprContext *ctx) = 0;

  virtual void enterNegativeExpr(RiddleParser::NegativeExprContext *ctx) = 0;
  virtual void exitNegativeExpr(RiddleParser::NegativeExprContext *ctx) = 0;

  virtual void enterNumberExpr(RiddleParser::NumberExprContext *ctx) = 0;
  virtual void exitNumberExpr(RiddleParser::NumberExprContext *ctx) = 0;

  virtual void enterXorAssignExpr(RiddleParser::XorAssignExprContext *ctx) = 0;
  virtual void exitXorAssignExpr(RiddleParser::XorAssignExprContext *ctx) = 0;

  virtual void enterSubExpr(RiddleParser::SubExprContext *ctx) = 0;
  virtual void exitSubExpr(RiddleParser::SubExprContext *ctx) = 0;

  virtual void enterGreaterEqualExpr(RiddleParser::GreaterEqualExprContext *ctx) = 0;
  virtual void exitGreaterEqualExpr(RiddleParser::GreaterEqualExprContext *ctx) = 0;

  virtual void enterBitXorExpr(RiddleParser::BitXorExprContext *ctx) = 0;
  virtual void exitBitXorExpr(RiddleParser::BitXorExprContext *ctx) = 0;

  virtual void enterAddAssignExpr(RiddleParser::AddAssignExprContext *ctx) = 0;
  virtual void exitAddAssignExpr(RiddleParser::AddAssignExprContext *ctx) = 0;

  virtual void enterOrAssignExpr(RiddleParser::OrAssignExprContext *ctx) = 0;
  virtual void exitOrAssignExpr(RiddleParser::OrAssignExprContext *ctx) = 0;

  virtual void enterGreaterExpr(RiddleParser::GreaterExprContext *ctx) = 0;
  virtual void exitGreaterExpr(RiddleParser::GreaterExprContext *ctx) = 0;

  virtual void enterDivAssignExpr(RiddleParser::DivAssignExprContext *ctx) = 0;
  virtual void exitDivAssignExpr(RiddleParser::DivAssignExprContext *ctx) = 0;

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

  virtual void enterStarAssignExpr(RiddleParser::StarAssignExprContext *ctx) = 0;
  virtual void exitStarAssignExpr(RiddleParser::StarAssignExprContext *ctx) = 0;

  virtual void enterBracketExpr(RiddleParser::BracketExprContext *ctx) = 0;
  virtual void exitBracketExpr(RiddleParser::BracketExprContext *ctx) = 0;

  virtual void enterLessExpr(RiddleParser::LessExprContext *ctx) = 0;
  virtual void exitLessExpr(RiddleParser::LessExprContext *ctx) = 0;

  virtual void enterOrExpr(RiddleParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(RiddleParser::OrExprContext *ctx) = 0;

  virtual void enterLeftLeftAssignExpr(RiddleParser::LeftLeftAssignExprContext *ctx) = 0;
  virtual void exitLeftLeftAssignExpr(RiddleParser::LeftLeftAssignExprContext *ctx) = 0;

  virtual void enterRightRightAssignExpr(RiddleParser::RightRightAssignExprContext *ctx) = 0;
  virtual void exitRightRightAssignExpr(RiddleParser::RightRightAssignExprContext *ctx) = 0;

  virtual void enterSelfAddLeftExpr(RiddleParser::SelfAddLeftExprContext *ctx) = 0;
  virtual void exitSelfAddLeftExpr(RiddleParser::SelfAddLeftExprContext *ctx) = 0;

  virtual void enterLessEqualExpr(RiddleParser::LessEqualExprContext *ctx) = 0;
  virtual void exitLessEqualExpr(RiddleParser::LessEqualExprContext *ctx) = 0;

  virtual void enterLeftLeftExpr(RiddleParser::LeftLeftExprContext *ctx) = 0;
  virtual void exitLeftLeftExpr(RiddleParser::LeftLeftExprContext *ctx) = 0;

  virtual void enterBitOrExpr(RiddleParser::BitOrExprContext *ctx) = 0;
  virtual void exitBitOrExpr(RiddleParser::BitOrExprContext *ctx) = 0;

  virtual void enterNotExpr(RiddleParser::NotExprContext *ctx) = 0;
  virtual void exitNotExpr(RiddleParser::NotExprContext *ctx) = 0;

  virtual void enterAddExpr(RiddleParser::AddExprContext *ctx) = 0;
  virtual void exitAddExpr(RiddleParser::AddExprContext *ctx) = 0;

  virtual void enterModAssignExpr(RiddleParser::ModAssignExprContext *ctx) = 0;
  virtual void exitModAssignExpr(RiddleParser::ModAssignExprContext *ctx) = 0;

  virtual void enterPositiveExpr(RiddleParser::PositiveExprContext *ctx) = 0;
  virtual void exitPositiveExpr(RiddleParser::PositiveExprContext *ctx) = 0;

  virtual void enterRightRightExpr(RiddleParser::RightRightExprContext *ctx) = 0;
  virtual void exitRightRightExpr(RiddleParser::RightRightExprContext *ctx) = 0;

  virtual void enterEqualExpr(RiddleParser::EqualExprContext *ctx) = 0;
  virtual void exitEqualExpr(RiddleParser::EqualExprContext *ctx) = 0;

  virtual void enterAndExpr(RiddleParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(RiddleParser::AndExprContext *ctx) = 0;

  virtual void enterId(RiddleParser::IdContext *ctx) = 0;
  virtual void exitId(RiddleParser::IdContext *ctx) = 0;

  virtual void enterNumber(RiddleParser::NumberContext *ctx) = 0;
  virtual void exitNumber(RiddleParser::NumberContext *ctx) = 0;


};

