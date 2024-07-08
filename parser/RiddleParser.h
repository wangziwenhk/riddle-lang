
// Generated from C:/Users/wangz/CLionProjects/Riddle-Language/RiddleParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  RiddleParser : public antlr4::Parser {
public:
  enum {
    Var = 1, For = 2, While = 3, If = 4, Else = 5, Func = 6, Return = 7, 
    Import = 8, Package = 9, Class = 10, Public = 11, Protected = 12, Private = 13, 
    Override = 14, LeftBracket = 15, RightBracket = 16, LeftCurly = 17, 
    RightCurly = 18, Colon = 19, Semi = 20, Comma = 21, Equal = 22, Assign = 23, 
    Greater = 24, Less = 25, LeftLeft = 26, RightRight = 27, Add = 28, Sub = 29, 
    Star = 30, Div = 31, Mod = 32, Not = 33, And = 34, Or = 35, Xor = 36, 
    Dot = 37, Endl = 38, Identifier = 39, Hexadecimal = 40, Decimal = 41, 
    Octal = 42, Binary = 43, IntegerSequence = 44, HEX_DIGIT = 45, OCTAL_DIGIT = 46, 
    BINARY_DIGIT = 47, DIGIT = 48, LINE_COMMENT = 49, BLOCK_COMMENT = 50, 
    WHITESPACE = 51
  };

  enum {
    RuleProgram = 0, RuleStatment_ed = 1, RuleStatment = 2, RulePackStatment = 3, 
    RuleImportStatment = 4, RuleVarStatment = 5, RuleFuncExpr = 6, RuleArgsExpr = 7, 
    RuleDefineArgs = 8, RuleFuncDefine = 9, RuleForStatment = 10, RuleWhileStatment = 11, 
    RuleIfStatment = 12, RuleReturnStatment = 13, RuleExpression = 14, RuleId = 15, 
    RuleNumber = 16
  };

  explicit RiddleParser(antlr4::TokenStream *input);

  RiddleParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~RiddleParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;




  class ProgramContext;
  class Statment_edContext;
  class StatmentContext;
  class PackStatmentContext;
  class ImportStatmentContext;
  class VarStatmentContext;
  class FuncExprContext;
  class ArgsExprContext;
  class DefineArgsContext;
  class FuncDefineContext;
  class ForStatmentContext;
  class WhileStatmentContext;
  class IfStatmentContext;
  class ReturnStatmentContext;
  class ExpressionContext;
  class IdContext;
  class NumberContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Statment_edContext *> statment_ed();
    Statment_edContext* statment_ed(size_t i);
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  Statment_edContext : public antlr4::ParserRuleContext {
  public:
    Statment_edContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatmentContext *statment();
    antlr4::tree::TerminalNode *Semi();
    antlr4::tree::TerminalNode *Endl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statment_edContext* statment_ed();

  class  StatmentContext : public antlr4::ParserRuleContext {
  public:
    StatmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PackStatmentContext *packStatment();
    ImportStatmentContext *importStatment();
    FuncDefineContext *funcDefine();
    FuncExprContext *funcExpr();
    VarStatmentContext *varStatment();
    ForStatmentContext *forStatment();
    WhileStatmentContext *whileStatment();
    IfStatmentContext *ifStatment();
    ReturnStatmentContext *returnStatment();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *LeftCurly();
    antlr4::tree::TerminalNode *RightCurly();
    std::vector<Statment_edContext *> statment_ed();
    Statment_edContext* statment_ed(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatmentContext* statment();

  class  PackStatmentContext : public antlr4::ParserRuleContext {
  public:
    PackStatmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Package();
    IdContext *id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PackStatmentContext* packStatment();

  class  ImportStatmentContext : public antlr4::ParserRuleContext {
  public:
    ImportStatmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Import();
    IdContext *id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportStatmentContext* importStatment();

  class  VarStatmentContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;
    antlr4::Token *type = nullptr;
    RiddleParser::ExpressionContext *value = nullptr;
    VarStatmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Var();
    antlr4::tree::TerminalNode *Colon();
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    antlr4::tree::TerminalNode *Assign();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarStatmentContext* varStatment();

  class  FuncExprContext : public antlr4::ParserRuleContext {
  public:
    RiddleParser::ArgsExprContext *arge = nullptr;
    FuncExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdContext *id();
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *RightBracket();
    ArgsExprContext *argsExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncExprContext* funcExpr();

  class  ArgsExprContext : public antlr4::ParserRuleContext {
  public:
    ArgsExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgsExprContext* argsExpr();

  class  DefineArgsContext : public antlr4::ParserRuleContext {
  public:
    DefineArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Colon();
    antlr4::tree::TerminalNode* Colon(size_t i);
    std::vector<IdContext *> id();
    IdContext* id(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefineArgsContext* defineArgs();

  class  FuncDefineContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *funcName = nullptr;
    RiddleParser::DefineArgsContext *args = nullptr;
    RiddleParser::IdContext *returnType = nullptr;
    RiddleParser::ProgramContext *body = nullptr;
    FuncDefineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Func();
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *RightBracket();
    antlr4::tree::TerminalNode *LeftCurly();
    antlr4::tree::TerminalNode *RightCurly();
    antlr4::tree::TerminalNode *Identifier();
    DefineArgsContext *defineArgs();
    ProgramContext *program();
    antlr4::tree::TerminalNode *Colon();
    IdContext *id();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncDefineContext* funcDefine();

  class  ForStatmentContext : public antlr4::ParserRuleContext {
  public:
    RiddleParser::VarStatmentContext *init = nullptr;
    RiddleParser::ExpressionContext *termCond = nullptr;
    RiddleParser::StatmentContext *selfVar = nullptr;
    RiddleParser::Statment_edContext *body = nullptr;
    ForStatmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *For();
    antlr4::tree::TerminalNode *LeftBracket();
    std::vector<antlr4::tree::TerminalNode *> Semi();
    antlr4::tree::TerminalNode* Semi(size_t i);
    antlr4::tree::TerminalNode *RightBracket();
    Statment_edContext *statment_ed();
    VarStatmentContext *varStatment();
    ExpressionContext *expression();
    StatmentContext *statment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStatmentContext* forStatment();

  class  WhileStatmentContext : public antlr4::ParserRuleContext {
  public:
    RiddleParser::ExpressionContext *runCond = nullptr;
    RiddleParser::Statment_edContext *body = nullptr;
    WhileStatmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *RightBracket();
    ExpressionContext *expression();
    Statment_edContext *statment_ed();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStatmentContext* whileStatment();

  class  IfStatmentContext : public antlr4::ParserRuleContext {
  public:
    bool hasElse;
    RiddleParser::ExpressionContext *cond = nullptr;
    RiddleParser::Statment_edContext *body = nullptr;
    RiddleParser::Statment_edContext *elseBody = nullptr;
    IfStatmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *RightBracket();
    ExpressionContext *expression();
    std::vector<Statment_edContext *> statment_ed();
    Statment_edContext* statment_ed(size_t i);
    antlr4::tree::TerminalNode *Else();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStatmentContext* ifStatment();

  class  ReturnStatmentContext : public antlr4::ParserRuleContext {
  public:
    ReturnStatmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Return();
    Statment_edContext *statment_ed();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnStatmentContext* returnStatment();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StarExprContext : public ExpressionContext {
  public:
    StarExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Star();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AndAssignExprContext : public ExpressionContext {
  public:
    AndAssignExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *And();
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SelfSubRightExprContext : public ExpressionContext {
  public:
    SelfSubRightExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *expr = nullptr;
    std::vector<antlr4::tree::TerminalNode *> Sub();
    antlr4::tree::TerminalNode* Sub(size_t i);
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ObjectExprContext : public ExpressionContext {
  public:
    ObjectExprContext(ExpressionContext *ctx);

    IdContext *id();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ModExprContext : public ExpressionContext {
  public:
    ModExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Mod();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NegativeExprContext : public ExpressionContext {
  public:
    NegativeExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *expr = nullptr;
    antlr4::tree::TerminalNode *Sub();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberExprContext : public ExpressionContext {
  public:
    NumberExprContext(ExpressionContext *ctx);

    NumberContext *number();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  XorAssignExprContext : public ExpressionContext {
  public:
    XorAssignExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Xor();
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SubExprContext : public ExpressionContext {
  public:
    SubExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Sub();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GreaterEqualExprContext : public ExpressionContext {
  public:
    GreaterEqualExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Greater();
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitXorExprContext : public ExpressionContext {
  public:
    BitXorExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Xor();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddAssignExprContext : public ExpressionContext {
  public:
    AddAssignExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Add();
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OrAssignExprContext : public ExpressionContext {
  public:
    OrAssignExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Or();
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GreaterExprContext : public ExpressionContext {
  public:
    GreaterExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Greater();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DivAssignExprContext : public ExpressionContext {
  public:
    DivAssignExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Div();
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotEqualExprContext : public ExpressionContext {
  public:
    NotEqualExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Not();
    antlr4::tree::TerminalNode *Equal();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SelfSubLeftExprContext : public ExpressionContext {
  public:
    SelfSubLeftExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *expr = nullptr;
    std::vector<antlr4::tree::TerminalNode *> Sub();
    antlr4::tree::TerminalNode* Sub(size_t i);
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DivExprContext : public ExpressionContext {
  public:
    DivExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Div();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitAndExprContext : public ExpressionContext {
  public:
    BitAndExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *And();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignExprContext : public ExpressionContext {
  public:
    AssignExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SelfAddRightExprContext : public ExpressionContext {
  public:
    SelfAddRightExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *expr = nullptr;
    std::vector<antlr4::tree::TerminalNode *> Add();
    antlr4::tree::TerminalNode* Add(size_t i);
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SubAssignExprContext : public ExpressionContext {
  public:
    SubAssignExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Sub();
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StarAssignExprContext : public ExpressionContext {
  public:
    StarAssignExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Star();
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BracketExprContext : public ExpressionContext {
  public:
    BracketExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *expr = nullptr;
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *RightBracket();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LessExprContext : public ExpressionContext {
  public:
    LessExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Less();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OrExprContext : public ExpressionContext {
  public:
    OrExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    std::vector<antlr4::tree::TerminalNode *> Or();
    antlr4::tree::TerminalNode* Or(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LeftLeftAssignExprContext : public ExpressionContext {
  public:
    LeftLeftAssignExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *LeftLeft();
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RightRightAssignExprContext : public ExpressionContext {
  public:
    RightRightAssignExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *RightRight();
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SelfAddLeftExprContext : public ExpressionContext {
  public:
    SelfAddLeftExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *expr = nullptr;
    std::vector<antlr4::tree::TerminalNode *> Add();
    antlr4::tree::TerminalNode* Add(size_t i);
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LessEqualExprContext : public ExpressionContext {
  public:
    LessEqualExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Less();
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LeftLeftExprContext : public ExpressionContext {
  public:
    LeftLeftExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *LeftLeft();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitOrExprContext : public ExpressionContext {
  public:
    BitOrExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Or();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotExprContext : public ExpressionContext {
  public:
    NotExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *expr = nullptr;
    antlr4::tree::TerminalNode *Not();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddExprContext : public ExpressionContext {
  public:
    AddExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Add();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ModAssignExprContext : public ExpressionContext {
  public:
    ModAssignExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Mod();
    antlr4::tree::TerminalNode *Assign();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PositiveExprContext : public ExpressionContext {
  public:
    PositiveExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *expr = nullptr;
    antlr4::tree::TerminalNode *Add();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RightRightExprContext : public ExpressionContext {
  public:
    RightRightExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *RightRight();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EqualExprContext : public ExpressionContext {
  public:
    EqualExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    antlr4::tree::TerminalNode *Equal();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AndExprContext : public ExpressionContext {
  public:
    AndExprContext(ExpressionContext *ctx);

    RiddleParser::ExpressionContext *left = nullptr;
    RiddleParser::ExpressionContext *right = nullptr;
    std::vector<antlr4::tree::TerminalNode *> And();
    antlr4::tree::TerminalNode* And(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  IdContext : public antlr4::ParserRuleContext {
  public:
    IdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Identifier();
    antlr4::tree::TerminalNode* Identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Dot();
    antlr4::tree::TerminalNode* Dot(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdContext* id();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    int value;
    antlr4::Token *decimalToken = nullptr;
    antlr4::Token *hexadecimalToken = nullptr;
    antlr4::Token *binaryToken = nullptr;
    antlr4::Token *octalToken = nullptr;
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Decimal();
    antlr4::tree::TerminalNode *Hexadecimal();
    antlr4::tree::TerminalNode *Binary();
    antlr4::tree::TerminalNode *Octal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

