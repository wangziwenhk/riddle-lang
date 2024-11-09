
// Generated from E:/Riddle-Language/RiddleLexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  RiddleLexer : public antlr4::Lexer {
public:
  enum {
    Var = 1, Val = 2, For = 3, While = 4, Continue = 5, Break = 6, If = 7, 
    Else = 8, Func = 9, Return = 10, Import = 11, Package = 12, Class = 13, 
    Public = 14, Protected = 15, Private = 16, Override = 17, True = 18, 
    False = 19, Static = 20, Const = 21, Null = 22, Try = 23, Catch = 24, 
    LeftBracket = 25, RightBracket = 26, LeftSquare = 27, RightSquare = 28, 
    LeftCurly = 29, RightCurly = 30, Colon = 31, Semi = 32, Comma = 33, 
    Equal = 34, Assign = 35, Greater = 36, Less = 37, LeftLeft = 38, RightRight = 39, 
    RightRightRight = 40, Add = 41, Sub = 42, Star = 43, Div = 44, Mod = 45, 
    Not = 46, And = 47, Or = 48, Xor = 49, Dot = 50, DoubleQuotes = 51, 
    Quotes = 52, Endl = 53, Identifier = 54, Hexadecimal = 55, Decimal = 56, 
    Octal = 57, Binary = 58, Float = 59, IntegerSequence = 60, HEX_DIGIT = 61, 
    OCTAL_DIGIT = 62, BINARY_DIGIT = 63, DIGIT = 64, STRING = 65, LINE_COMMENT = 66, 
    BLOCK_COMMENT = 67, WHITESPACE = 68
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

