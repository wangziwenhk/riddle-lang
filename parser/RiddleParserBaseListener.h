
// Generated from D:/Code/riddle-lang/RiddleParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "RiddleParserListener.h"


/**
 * This class provides an empty implementation of RiddleParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  RiddleParserBaseListener : public RiddleParserListener {
public:

  virtual void enterProgram(RiddleParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(RiddleParser::ProgramContext * /*ctx*/) override { }

  virtual void enterNull_cnt(RiddleParser::Null_cntContext * /*ctx*/) override { }
  virtual void exitNull_cnt(RiddleParser::Null_cntContext * /*ctx*/) override { }

  virtual void enterStatement_ed(RiddleParser::Statement_edContext * /*ctx*/) override { }
  virtual void exitStatement_ed(RiddleParser::Statement_edContext * /*ctx*/) override { }

  virtual void enterStatement(RiddleParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(RiddleParser::StatementContext * /*ctx*/) override { }

  virtual void enterBodyExpr(RiddleParser::BodyExprContext * /*ctx*/) override { }
  virtual void exitBodyExpr(RiddleParser::BodyExprContext * /*ctx*/) override { }

  virtual void enterPackStatement(RiddleParser::PackStatementContext * /*ctx*/) override { }
  virtual void exitPackStatement(RiddleParser::PackStatementContext * /*ctx*/) override { }

  virtual void enterImportStatement(RiddleParser::ImportStatementContext * /*ctx*/) override { }
  virtual void exitImportStatement(RiddleParser::ImportStatementContext * /*ctx*/) override { }

  virtual void enterVarDefineStatement(RiddleParser::VarDefineStatementContext * /*ctx*/) override { }
  virtual void exitVarDefineStatement(RiddleParser::VarDefineStatementContext * /*ctx*/) override { }

  virtual void enterArgsExpr(RiddleParser::ArgsExprContext * /*ctx*/) override { }
  virtual void exitArgsExpr(RiddleParser::ArgsExprContext * /*ctx*/) override { }

  virtual void enterDefineArgs(RiddleParser::DefineArgsContext * /*ctx*/) override { }
  virtual void exitDefineArgs(RiddleParser::DefineArgsContext * /*ctx*/) override { }

  virtual void enterFuncDefine(RiddleParser::FuncDefineContext * /*ctx*/) override { }
  virtual void exitFuncDefine(RiddleParser::FuncDefineContext * /*ctx*/) override { }

  virtual void enterForStatement(RiddleParser::ForStatementContext * /*ctx*/) override { }
  virtual void exitForStatement(RiddleParser::ForStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(RiddleParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(RiddleParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterContinueStatement(RiddleParser::ContinueStatementContext * /*ctx*/) override { }
  virtual void exitContinueStatement(RiddleParser::ContinueStatementContext * /*ctx*/) override { }

  virtual void enterBreakStatement(RiddleParser::BreakStatementContext * /*ctx*/) override { }
  virtual void exitBreakStatement(RiddleParser::BreakStatementContext * /*ctx*/) override { }

  virtual void enterIfStatement(RiddleParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(RiddleParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterReturnStatement(RiddleParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(RiddleParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterClassDefine(RiddleParser::ClassDefineContext * /*ctx*/) override { }
  virtual void exitClassDefine(RiddleParser::ClassDefineContext * /*ctx*/) override { }

  virtual void enterTryExpr(RiddleParser::TryExprContext * /*ctx*/) override { }
  virtual void exitTryExpr(RiddleParser::TryExprContext * /*ctx*/) override { }

  virtual void enterCatchExpr(RiddleParser::CatchExprContext * /*ctx*/) override { }
  virtual void exitCatchExpr(RiddleParser::CatchExprContext * /*ctx*/) override { }

  virtual void enterFuncExpr(RiddleParser::FuncExprContext * /*ctx*/) override { }
  virtual void exitFuncExpr(RiddleParser::FuncExprContext * /*ctx*/) override { }

  virtual void enterObjectExpr(RiddleParser::ObjectExprContext * /*ctx*/) override { }
  virtual void exitObjectExpr(RiddleParser::ObjectExprContext * /*ctx*/) override { }

  virtual void enterBlendExpr(RiddleParser::BlendExprContext * /*ctx*/) override { }
  virtual void exitBlendExpr(RiddleParser::BlendExprContext * /*ctx*/) override { }

  virtual void enterExprPtrParser(RiddleParser::ExprPtrParserContext * /*ctx*/) override { }
  virtual void exitExprPtrParser(RiddleParser::ExprPtrParserContext * /*ctx*/) override { }

  virtual void enterSelfSubRightExpr(RiddleParser::SelfSubRightExprContext * /*ctx*/) override { }
  virtual void exitSelfSubRightExpr(RiddleParser::SelfSubRightExprContext * /*ctx*/) override { }

  virtual void enterAndAssignExpr(RiddleParser::AndAssignExprContext * /*ctx*/) override { }
  virtual void exitAndAssignExpr(RiddleParser::AndAssignExprContext * /*ctx*/) override { }

  virtual void enterLoadExpr(RiddleParser::LoadExprContext * /*ctx*/) override { }
  virtual void exitLoadExpr(RiddleParser::LoadExprContext * /*ctx*/) override { }

  virtual void enterNullExpr(RiddleParser::NullExprContext * /*ctx*/) override { }
  virtual void exitNullExpr(RiddleParser::NullExprContext * /*ctx*/) override { }

  virtual void enterModExpr(RiddleParser::ModExprContext * /*ctx*/) override { }
  virtual void exitModExpr(RiddleParser::ModExprContext * /*ctx*/) override { }

  virtual void enterCastExpr(RiddleParser::CastExprContext * /*ctx*/) override { }
  virtual void exitCastExpr(RiddleParser::CastExprContext * /*ctx*/) override { }

  virtual void enterLShrExpr(RiddleParser::LShrExprContext * /*ctx*/) override { }
  virtual void exitLShrExpr(RiddleParser::LShrExprContext * /*ctx*/) override { }

  virtual void enterNegativeExpr(RiddleParser::NegativeExprContext * /*ctx*/) override { }
  virtual void exitNegativeExpr(RiddleParser::NegativeExprContext * /*ctx*/) override { }

  virtual void enterNumberExpr(RiddleParser::NumberExprContext * /*ctx*/) override { }
  virtual void exitNumberExpr(RiddleParser::NumberExprContext * /*ctx*/) override { }

  virtual void enterMulAssignExpr(RiddleParser::MulAssignExprContext * /*ctx*/) override { }
  virtual void exitMulAssignExpr(RiddleParser::MulAssignExprContext * /*ctx*/) override { }

  virtual void enterXorAssignExpr(RiddleParser::XorAssignExprContext * /*ctx*/) override { }
  virtual void exitXorAssignExpr(RiddleParser::XorAssignExprContext * /*ctx*/) override { }

  virtual void enterSubExpr(RiddleParser::SubExprContext * /*ctx*/) override { }
  virtual void exitSubExpr(RiddleParser::SubExprContext * /*ctx*/) override { }

  virtual void enterGreaterEqualExpr(RiddleParser::GreaterEqualExprContext * /*ctx*/) override { }
  virtual void exitGreaterEqualExpr(RiddleParser::GreaterEqualExprContext * /*ctx*/) override { }

  virtual void enterAddAssignExpr(RiddleParser::AddAssignExprContext * /*ctx*/) override { }
  virtual void exitAddAssignExpr(RiddleParser::AddAssignExprContext * /*ctx*/) override { }

  virtual void enterOrAssignExpr(RiddleParser::OrAssignExprContext * /*ctx*/) override { }
  virtual void exitOrAssignExpr(RiddleParser::OrAssignExprContext * /*ctx*/) override { }

  virtual void enterBitXorExpr(RiddleParser::BitXorExprContext * /*ctx*/) override { }
  virtual void exitBitXorExpr(RiddleParser::BitXorExprContext * /*ctx*/) override { }

  virtual void enterPtrExpr(RiddleParser::PtrExprContext * /*ctx*/) override { }
  virtual void exitPtrExpr(RiddleParser::PtrExprContext * /*ctx*/) override { }

  virtual void enterStringExpr(RiddleParser::StringExprContext * /*ctx*/) override { }
  virtual void exitStringExpr(RiddleParser::StringExprContext * /*ctx*/) override { }

  virtual void enterGreaterExpr(RiddleParser::GreaterExprContext * /*ctx*/) override { }
  virtual void exitGreaterExpr(RiddleParser::GreaterExprContext * /*ctx*/) override { }

  virtual void enterDivAssignExpr(RiddleParser::DivAssignExprContext * /*ctx*/) override { }
  virtual void exitDivAssignExpr(RiddleParser::DivAssignExprContext * /*ctx*/) override { }

  virtual void enterMulExpr(RiddleParser::MulExprContext * /*ctx*/) override { }
  virtual void exitMulExpr(RiddleParser::MulExprContext * /*ctx*/) override { }

  virtual void enterNotEqualExpr(RiddleParser::NotEqualExprContext * /*ctx*/) override { }
  virtual void exitNotEqualExpr(RiddleParser::NotEqualExprContext * /*ctx*/) override { }

  virtual void enterSelfSubLeftExpr(RiddleParser::SelfSubLeftExprContext * /*ctx*/) override { }
  virtual void exitSelfSubLeftExpr(RiddleParser::SelfSubLeftExprContext * /*ctx*/) override { }

  virtual void enterDivExpr(RiddleParser::DivExprContext * /*ctx*/) override { }
  virtual void exitDivExpr(RiddleParser::DivExprContext * /*ctx*/) override { }

  virtual void enterBitAndExpr(RiddleParser::BitAndExprContext * /*ctx*/) override { }
  virtual void exitBitAndExpr(RiddleParser::BitAndExprContext * /*ctx*/) override { }

  virtual void enterAssignExpr(RiddleParser::AssignExprContext * /*ctx*/) override { }
  virtual void exitAssignExpr(RiddleParser::AssignExprContext * /*ctx*/) override { }

  virtual void enterSelfAddRightExpr(RiddleParser::SelfAddRightExprContext * /*ctx*/) override { }
  virtual void exitSelfAddRightExpr(RiddleParser::SelfAddRightExprContext * /*ctx*/) override { }

  virtual void enterSubAssignExpr(RiddleParser::SubAssignExprContext * /*ctx*/) override { }
  virtual void exitSubAssignExpr(RiddleParser::SubAssignExprContext * /*ctx*/) override { }

  virtual void enterCharExpr(RiddleParser::CharExprContext * /*ctx*/) override { }
  virtual void exitCharExpr(RiddleParser::CharExprContext * /*ctx*/) override { }

  virtual void enterBracketExpr(RiddleParser::BracketExprContext * /*ctx*/) override { }
  virtual void exitBracketExpr(RiddleParser::BracketExprContext * /*ctx*/) override { }

  virtual void enterBooleanExpr(RiddleParser::BooleanExprContext * /*ctx*/) override { }
  virtual void exitBooleanExpr(RiddleParser::BooleanExprContext * /*ctx*/) override { }

  virtual void enterAShrExpr(RiddleParser::AShrExprContext * /*ctx*/) override { }
  virtual void exitAShrExpr(RiddleParser::AShrExprContext * /*ctx*/) override { }

  virtual void enterLessExpr(RiddleParser::LessExprContext * /*ctx*/) override { }
  virtual void exitLessExpr(RiddleParser::LessExprContext * /*ctx*/) override { }

  virtual void enterOrExpr(RiddleParser::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(RiddleParser::OrExprContext * /*ctx*/) override { }

  virtual void enterSelfAddLeftExpr(RiddleParser::SelfAddLeftExprContext * /*ctx*/) override { }
  virtual void exitSelfAddLeftExpr(RiddleParser::SelfAddLeftExprContext * /*ctx*/) override { }

  virtual void enterLShrAssignExpr(RiddleParser::LShrAssignExprContext * /*ctx*/) override { }
  virtual void exitLShrAssignExpr(RiddleParser::LShrAssignExprContext * /*ctx*/) override { }

  virtual void enterLessEqualExpr(RiddleParser::LessEqualExprContext * /*ctx*/) override { }
  virtual void exitLessEqualExpr(RiddleParser::LessEqualExprContext * /*ctx*/) override { }

  virtual void enterAShrAssignExpr(RiddleParser::AShrAssignExprContext * /*ctx*/) override { }
  virtual void exitAShrAssignExpr(RiddleParser::AShrAssignExprContext * /*ctx*/) override { }

  virtual void enterBitOrExpr(RiddleParser::BitOrExprContext * /*ctx*/) override { }
  virtual void exitBitOrExpr(RiddleParser::BitOrExprContext * /*ctx*/) override { }

  virtual void enterNotExpr(RiddleParser::NotExprContext * /*ctx*/) override { }
  virtual void exitNotExpr(RiddleParser::NotExprContext * /*ctx*/) override { }

  virtual void enterAddExpr(RiddleParser::AddExprContext * /*ctx*/) override { }
  virtual void exitAddExpr(RiddleParser::AddExprContext * /*ctx*/) override { }

  virtual void enterShlAssignExpr(RiddleParser::ShlAssignExprContext * /*ctx*/) override { }
  virtual void exitShlAssignExpr(RiddleParser::ShlAssignExprContext * /*ctx*/) override { }

  virtual void enterModAssignExpr(RiddleParser::ModAssignExprContext * /*ctx*/) override { }
  virtual void exitModAssignExpr(RiddleParser::ModAssignExprContext * /*ctx*/) override { }

  virtual void enterPositiveExpr(RiddleParser::PositiveExprContext * /*ctx*/) override { }
  virtual void exitPositiveExpr(RiddleParser::PositiveExprContext * /*ctx*/) override { }

  virtual void enterShlExpr(RiddleParser::ShlExprContext * /*ctx*/) override { }
  virtual void exitShlExpr(RiddleParser::ShlExprContext * /*ctx*/) override { }

  virtual void enterEqualExpr(RiddleParser::EqualExprContext * /*ctx*/) override { }
  virtual void exitEqualExpr(RiddleParser::EqualExprContext * /*ctx*/) override { }

  virtual void enterAndExpr(RiddleParser::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(RiddleParser::AndExprContext * /*ctx*/) override { }

  virtual void enterExprBlend(RiddleParser::ExprBlendContext * /*ctx*/) override { }
  virtual void exitExprBlend(RiddleParser::ExprBlendContext * /*ctx*/) override { }

  virtual void enterId(RiddleParser::IdContext * /*ctx*/) override { }
  virtual void exitId(RiddleParser::IdContext * /*ctx*/) override { }

  virtual void enterModifier(RiddleParser::ModifierContext * /*ctx*/) override { }
  virtual void exitModifier(RiddleParser::ModifierContext * /*ctx*/) override { }

  virtual void enterModifierList(RiddleParser::ModifierListContext * /*ctx*/) override { }
  virtual void exitModifierList(RiddleParser::ModifierListContext * /*ctx*/) override { }

  virtual void enterNumber(RiddleParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(RiddleParser::NumberContext * /*ctx*/) override { }

  virtual void enterBoolean(RiddleParser::BooleanContext * /*ctx*/) override { }
  virtual void exitBoolean(RiddleParser::BooleanContext * /*ctx*/) override { }

  virtual void enterFloat(RiddleParser::FloatContext * /*ctx*/) override { }
  virtual void exitFloat(RiddleParser::FloatContext * /*ctx*/) override { }

  virtual void enterInteger(RiddleParser::IntegerContext * /*ctx*/) override { }
  virtual void exitInteger(RiddleParser::IntegerContext * /*ctx*/) override { }

  virtual void enterTmpleDefine(RiddleParser::TmpleDefineContext * /*ctx*/) override { }
  virtual void exitTmpleDefine(RiddleParser::TmpleDefineContext * /*ctx*/) override { }

  virtual void enterTmplDefineArg(RiddleParser::TmplDefineArgContext * /*ctx*/) override { }
  virtual void exitTmplDefineArg(RiddleParser::TmplDefineArgContext * /*ctx*/) override { }

  virtual void enterTmplUsed(RiddleParser::TmplUsedContext * /*ctx*/) override { }
  virtual void exitTmplUsed(RiddleParser::TmplUsedContext * /*ctx*/) override { }

  virtual void enterTmplArg(RiddleParser::TmplArgContext * /*ctx*/) override { }
  virtual void exitTmplArg(RiddleParser::TmplArgContext * /*ctx*/) override { }

  virtual void enterTmplArgList(RiddleParser::TmplArgListContext * /*ctx*/) override { }
  virtual void exitTmplArgList(RiddleParser::TmplArgListContext * /*ctx*/) override { }

  virtual void enterArrayType(RiddleParser::ArrayTypeContext * /*ctx*/) override { }
  virtual void exitArrayType(RiddleParser::ArrayTypeContext * /*ctx*/) override { }

  virtual void enterTmplType(RiddleParser::TmplTypeContext * /*ctx*/) override { }
  virtual void exitTmplType(RiddleParser::TmplTypeContext * /*ctx*/) override { }

  virtual void enterBaseType(RiddleParser::BaseTypeContext * /*ctx*/) override { }
  virtual void exitBaseType(RiddleParser::BaseTypeContext * /*ctx*/) override { }

  virtual void enterProperty(RiddleParser::PropertyContext * /*ctx*/) override { }
  virtual void exitProperty(RiddleParser::PropertyContext * /*ctx*/) override { }

  virtual void enterPropertyItem(RiddleParser::PropertyItemContext * /*ctx*/) override { }
  virtual void exitPropertyItem(RiddleParser::PropertyItemContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

