
// Generated from E:/Riddle-Language/RiddleLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  RiddleLexer : public antlr4::Lexer {
public:
  enum {
    Var = 1, Val = 2, For = 3, While = 4, If = 5, Else = 6, Func = 7, Return = 8, 
    Import = 9, Package = 10, Class = 11, Public = 12, Protected = 13, Private = 14, 
    Override = 15, True = 16, False = 17, Static = 18, Const = 19, Null = 20, 
    LeftBracket = 21, RightBracket = 22, LeftSquare = 23, RightSquare = 24, 
    LeftCurly = 25, RightCurly = 26, Colon = 27, Semi = 28, Comma = 29, 
    Equal = 30, Assign = 31, Greater = 32, Less = 33, LeftLeft = 34, RightRight = 35, 
    RightRightRight = 36, Add = 37, Sub = 38, Star = 39, Div = 40, Mod = 41, 
    Not = 42, And = 43, Or = 44, Xor = 45, Dot = 46, DoubleQuotes = 47, 
    Quotes = 48, Endl = 49, Identifier = 50, Hexadecimal = 51, Decimal = 52, 
    Octal = 53, Binary = 54, Float = 55, IntegerSequence = 56, HEX_DIGIT = 57, 
    OCTAL_DIGIT = 58, BINARY_DIGIT = 59, DIGIT = 60, STRING = 61, LINE_COMMENT = 62, 
    BLOCK_COMMENT = 63, WHITESPACE = 64
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

