
// Generated from C:/Users/wangz/CLionProjects/Riddle-Language/RiddleLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  RiddleLexer : public antlr4::Lexer {
public:
  enum {
    Var = 1, Val = 2, For = 3, While = 4, If = 5, Else = 6, Func = 7, Return = 8, 
    Import = 9, Package = 10, Class = 11, Public = 12, Protected = 13, Private = 14, 
    Override = 15, Printf = 16, LeftBracket = 17, RightBracket = 18, LeftCurly = 19, 
    RightCurly = 20, Colon = 21, Semi = 22, Comma = 23, Equal = 24, Assign = 25, 
    Greater = 26, Less = 27, LeftLeft = 28, RightRight = 29, Add = 30, Sub = 31, 
    Star = 32, Div = 33, Mod = 34, Not = 35, And = 36, Or = 37, Xor = 38, 
    Dot = 39, DoubleQuotes = 40, Quotes = 41, Endl = 42, Identifier = 43, 
    Hexadecimal = 44, Decimal = 45, Octal = 46, Binary = 47, Float = 48, 
    IntegerSequence = 49, HEX_DIGIT = 50, OCTAL_DIGIT = 51, BINARY_DIGIT = 52, 
    DIGIT = 53, STRING = 54, LINE_COMMENT = 55, BLOCK_COMMENT = 56, WHITESPACE = 57
  };

  explicit RiddleLexer(antlr4::CharStream *input);

  ~RiddleLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

