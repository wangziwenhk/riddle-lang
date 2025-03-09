
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
    Virtual = 25, Operator = 26, Template = 27, TypeName = 28, LeftBracket = 29, 
    RightBracket = 30, LeftSquare = 31, RightSquare = 32, LeftCurly = 33, 
    RightCurly = 34, Colon = 35, Semi = 36, Comma = 37, Equal = 38, Assign = 39, 
    Greater = 40, Less = 41, LeftLeft = 42, RightRight = 43, RightRightRight = 44, 
    Add = 45, Sub = 46, Star = 47, Div = 48, Mod = 49, Not = 50, And = 51, 
    Or = 52, Xor = 53, Dot = 54, DoubleQuotes = 55, Quotes = 56, Endl = 57, 
    Identifier = 58, Hexadecimal = 59, Decimal = 60, Octal = 61, Binary = 62, 
    Float = 63, IntegerSequence = 64, HEX_DIGIT = 65, OCTAL_DIGIT = 66, 
    BINARY_DIGIT = 67, DIGIT = 68, STRING = 69, CHAR = 70, LINE_COMMENT = 71, 
    BLOCK_COMMENT = 72, WHITESPACE = 73
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

