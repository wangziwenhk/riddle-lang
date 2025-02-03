
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
    Virtual = 25, Template = 26, TypeName = 27, LeftBracket = 28, RightBracket = 29, 
    LeftSquare = 30, RightSquare = 31, LeftCurly = 32, RightCurly = 33, 
    Colon = 34, Semi = 35, Comma = 36, Equal = 37, Assign = 38, Greater = 39, 
    Less = 40, LeftLeft = 41, RightRight = 42, RightRightRight = 43, Add = 44, 
    Sub = 45, Star = 46, Div = 47, Mod = 48, Not = 49, And = 50, Or = 51, 
    Xor = 52, Dot = 53, DoubleQuotes = 54, Quotes = 55, Endl = 56, Identifier = 57, 
    Hexadecimal = 58, Decimal = 59, Octal = 60, Binary = 61, Float = 62, 
    IntegerSequence = 63, HEX_DIGIT = 64, OCTAL_DIGIT = 65, BINARY_DIGIT = 66, 
    DIGIT = 67, STRING = 68, LINE_COMMENT = 69, BLOCK_COMMENT = 70, WHITESPACE = 71
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

