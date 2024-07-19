
// Generated from C:/Users/wangz/CLionProjects/Riddle-Language/RiddleLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  RiddleLexer : public antlr4::Lexer {
public:
  enum {
    Var = 1, Val = 2, For = 3, While = 4, If = 5, Else = 6, Func = 7, Return = 8, 
    Import = 9, Package = 10, Class = 11, Public = 12, Protected = 13, Private = 14, 
    Override = 15, Printf = 16, True = 17, False = 18, LeftBracket = 19, 
    RightBracket = 20, LeftCurly = 21, RightCurly = 22, Colon = 23, Semi = 24, 
    Comma = 25, Equal = 26, Assign = 27, Greater = 28, Less = 29, LeftLeft = 30, 
    RightRight = 31, Add = 32, Sub = 33, Star = 34, Div = 35, Mod = 36, 
    Not = 37, And = 38, Or = 39, Xor = 40, Dot = 41, DoubleQuotes = 42, 
    Quotes = 43, Endl = 44, Identifier = 45, Hexadecimal = 46, Decimal = 47, 
    Octal = 48, Binary = 49, Float = 50, IntegerSequence = 51, HEX_DIGIT = 52, 
    OCTAL_DIGIT = 53, BINARY_DIGIT = 54, DIGIT = 55, STRING = 56, LINE_COMMENT = 57, 
    BLOCK_COMMENT = 58, WHITESPACE = 59
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

