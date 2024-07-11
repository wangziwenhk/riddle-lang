
// Generated from C:/Users/wangz/CLionProjects/Riddle-Language/RiddleLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  RiddleLexer : public antlr4::Lexer {
public:
  enum {
    Var = 1, Val = 2, For = 3, While = 4, If = 5, Else = 6, Func = 7, Return = 8, 
    Import = 9, Package = 10, Class = 11, Public = 12, Protected = 13, Private = 14, 
    Override = 15, LeftBracket = 16, RightBracket = 17, LeftCurly = 18, 
    RightCurly = 19, Colon = 20, Semi = 21, Comma = 22, Equal = 23, Assign = 24, 
    Greater = 25, Less = 26, LeftLeft = 27, RightRight = 28, Add = 29, Sub = 30, 
    Star = 31, Div = 32, Mod = 33, Not = 34, And = 35, Or = 36, Xor = 37, 
    Dot = 38, DoubleQuotes = 39, Quotes = 40, Endl = 41, Identifier = 42, 
    Hexadecimal = 43, Decimal = 44, Octal = 45, Binary = 46, Float = 47, 
    IntegerSequence = 48, HEX_DIGIT = 49, OCTAL_DIGIT = 50, BINARY_DIGIT = 51, 
    DIGIT = 52, STRING = 53, LINE_COMMENT = 54, BLOCK_COMMENT = 55, WHITESPACE = 56
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

