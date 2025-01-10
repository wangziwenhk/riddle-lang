
// Generated from D:/Code/Riddle-Language-cpp/RiddleLexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  RiddleLexer : public antlr4::Lexer {
public:
  enum {
    Var = 1, Val = 2, For = 3, While = 4, Continue = 5, Break = 6, If = 7, 
    Else = 8, Func = 9, Return = 10, Import = 11, Package = 12, Class = 13, 
    True = 14, False = 15, Null = 16, Try = 17, Catch = 18, Override = 19, 
    Static = 20, Const = 21, Public = 22, Protected = 23, Private = 24, 
    Virtual = 25, LeftBracket = 26, RightBracket = 27, LeftSquare = 28, 
    RightSquare = 29, LeftCurly = 30, RightCurly = 31, Colon = 32, Semi = 33, 
    Comma = 34, Equal = 35, Assign = 36, Greater = 37, Less = 38, LeftLeft = 39, 
    RightRight = 40, RightRightRight = 41, Add = 42, Sub = 43, Star = 44, 
    Div = 45, Mod = 46, Not = 47, And = 48, Or = 49, Xor = 50, Dot = 51, 
    DoubleQuotes = 52, Quotes = 53, Endl = 54, Identifier = 55, Hexadecimal = 56, 
    Decimal = 57, Octal = 58, Binary = 59, Float = 60, IntegerSequence = 61, 
    HEX_DIGIT = 62, OCTAL_DIGIT = 63, BINARY_DIGIT = 64, DIGIT = 65, STRING = 66, 
    LINE_COMMENT = 67, BLOCK_COMMENT = 68, WHITESPACE = 69
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

