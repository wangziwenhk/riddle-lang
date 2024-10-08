
// Generated from E:/Riddle-Language/RiddleLexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  RiddleLexer : public antlr4::Lexer {
public:
  enum {
    Var = 1, Val = 2, For = 3, While = 4, If = 5, Else = 6, Func = 7, Return = 8, 
    Import = 9, Package = 10, Class = 11, Public = 12, Protected = 13, Private = 14, 
    Override = 15, True = 16, False = 17, Static = 18, Const = 19, Null = 20, 
    Try = 21, Catch = 22, LeftBracket = 23, RightBracket = 24, LeftSquare = 25, 
    RightSquare = 26, LeftCurly = 27, RightCurly = 28, Colon = 29, Semi = 30, 
    Comma = 31, Equal = 32, Assign = 33, Greater = 34, Less = 35, LeftLeft = 36, 
    RightRight = 37, RightRightRight = 38, Add = 39, Sub = 40, Star = 41, 
    Div = 42, Mod = 43, Not = 44, And = 45, Or = 46, Xor = 47, Dot = 48, 
    DoubleQuotes = 49, Quotes = 50, Endl = 51, Identifier = 52, Hexadecimal = 53, 
    Decimal = 54, Octal = 55, Binary = 56, Float = 57, IntegerSequence = 58, 
    HEX_DIGIT = 59, OCTAL_DIGIT = 60, BINARY_DIGIT = 61, DIGIT = 62, STRING = 63, 
    LINE_COMMENT = 64, BLOCK_COMMENT = 65, WHITESPACE = 66
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

