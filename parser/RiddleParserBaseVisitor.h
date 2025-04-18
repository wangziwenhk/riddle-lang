
// Generated from D:/Code/riddle-lang/RiddleParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "RiddleParserVisitor.h"


/**
 * This class provides an empty implementation of RiddleParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  RiddleParserBaseVisitor : public RiddleParserVisitor {
public:

  virtual std::any visitProgram(RiddleParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNull_cnt(RiddleParser::Null_cntContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement_ed(RiddleParser::Statement_edContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(RiddleParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBodyExpr(RiddleParser::BodyExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPackStatement(RiddleParser::PackStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportStatement(RiddleParser::ImportStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgsExpr(RiddleParser::ArgsExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefineArgs(RiddleParser::DefineArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDefine(RiddleParser::FuncDefineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStatement(RiddleParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStatement(RiddleParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStatement(RiddleParser::ContinueStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStatement(RiddleParser::BreakStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(RiddleParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(RiddleParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassDefine(RiddleParser::ClassDefineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTryExpr(RiddleParser::TryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCatchExpr(RiddleParser::CatchExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncExpr(RiddleParser::FuncExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObjectExpr(RiddleParser::ObjectExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlendExpr(RiddleParser::BlendExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprPtrParser(RiddleParser::ExprPtrParserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelfSubRightExpr(RiddleParser::SelfSubRightExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndAssignExpr(RiddleParser::AndAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoadExpr(RiddleParser::LoadExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullExpr(RiddleParser::NullExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModExpr(RiddleParser::ModExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCastExpr(RiddleParser::CastExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLShrExpr(RiddleParser::LShrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNegativeExpr(RiddleParser::NegativeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberExpr(RiddleParser::NumberExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulAssignExpr(RiddleParser::MulAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXorAssignExpr(RiddleParser::XorAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubExpr(RiddleParser::SubExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGreaterEqualExpr(RiddleParser::GreaterEqualExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddAssignExpr(RiddleParser::AddAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrAssignExpr(RiddleParser::OrAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitXorExpr(RiddleParser::BitXorExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPtrExpr(RiddleParser::PtrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringExpr(RiddleParser::StringExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGreaterExpr(RiddleParser::GreaterExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDivAssignExpr(RiddleParser::DivAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulExpr(RiddleParser::MulExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotEqualExpr(RiddleParser::NotEqualExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelfSubLeftExpr(RiddleParser::SelfSubLeftExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDivExpr(RiddleParser::DivExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitAndExpr(RiddleParser::BitAndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignExpr(RiddleParser::AssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelfAddRightExpr(RiddleParser::SelfAddRightExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubAssignExpr(RiddleParser::SubAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharExpr(RiddleParser::CharExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBracketExpr(RiddleParser::BracketExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanExpr(RiddleParser::BooleanExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAShrExpr(RiddleParser::AShrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLessExpr(RiddleParser::LessExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(RiddleParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelfAddLeftExpr(RiddleParser::SelfAddLeftExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLShrAssignExpr(RiddleParser::LShrAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLessEqualExpr(RiddleParser::LessEqualExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAShrAssignExpr(RiddleParser::AShrAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitOrExpr(RiddleParser::BitOrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExpr(RiddleParser::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddExpr(RiddleParser::AddExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShlAssignExpr(RiddleParser::ShlAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModAssignExpr(RiddleParser::ModAssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPositiveExpr(RiddleParser::PositiveExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShlExpr(RiddleParser::ShlExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualExpr(RiddleParser::EqualExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(RiddleParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprBlend(RiddleParser::ExprBlendContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitId(RiddleParser::IdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModifier(RiddleParser::ModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitModifierList(RiddleParser::ModifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(RiddleParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolean(RiddleParser::BooleanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloat(RiddleParser::FloatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInteger(RiddleParser::IntegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTmpleDefine(RiddleParser::TmpleDefineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTmplDefineArg(RiddleParser::TmplDefineArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTmplUsed(RiddleParser::TmplUsedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTmplArg(RiddleParser::TmplArgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTmplArgList(RiddleParser::TmplArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayType(RiddleParser::ArrayTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTmplType(RiddleParser::TmplTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBaseType(RiddleParser::BaseTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProperty(RiddleParser::PropertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyItem(RiddleParser::PropertyItemContext *ctx) override {
    return visitChildren(ctx);
  }


};

