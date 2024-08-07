
// Generated from C:/Users/wangz/CLionProjects/Riddle-Language/RiddleLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  RiddleLexer : public antlr4::Lexer {
public:
  enum {
    Var = 1, Val = 2, For = 3, While = 4, If = 5, Else = 6, Func = 7, Return = 8, 
    Import = 9, Package = 10, Class = 11, Public = 12, Protected = 13, Private = 14, 
    Override = 15, True = 16, False = 17, Static = 18, Const = 19, LeftBracket = 20, 
    RightBracket = 21, LeftSquare = 22, RightSquare = 23, LeftCurly = 24, 
    RightCurly = 25, Colon = 26, Semi = 27, Comma = 28, Equal = 29, Assign = 30, 
    Greater = 31, Less = 32, LeftLeft = 33, RightRight = 34, RightRightRight = 35, 
    Add = 36, Sub = 37, Star = 38, Div = 39, Mod = 40, Not = 41, And = 42, 
    Or = 43, Xor = 44, Dot = 45, DoubleQuotes = 46, Quotes = 47, Endl = 48, 
    Identifier = 49, Hexadecimal = 50, Decimal = 51, Octal = 52, Binary = 53, 
    Float = 54, IntegerSequence = 55, HEX_DIGIT = 56, OCTAL_DIGIT = 57, 
    BINARY_DIGIT = 58, DIGIT = 59, STRING = 60, LINE_COMMENT = 61, BLOCK_COMMENT = 62, 
    WHITESPACE = 63
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

