
// Generated from D:/Code/riddle-lang/RiddleLexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  RiddleLexer : public antlr4::Lexer {
public:
  enum {
    Var = 1, Val = 2, For = 3, While = 4, Continue = 5, Break = 6, If = 7, 
    Else = 8, Func = 9, Return = 10, Import = 11, Package = 12, Class = 13, 
    True = 14, False = 15, Null = 16, Try = 17, Catch = 18, Override = 19, 
    Static = 20, Const = 21, Public = 22, Protected = 23, Private = 24, 
    Virtual = 25, Operator = 26, Template = 27, TypeName = 28, Int_ = 29, 
    Float_ = 30, Double_ = 31, Short_ = 32, Long_ = 33, Char_ = 34, LeftBracket = 35, 
    RightBracket = 36, LeftSquare = 37, RightSquare = 38, LeftCurly = 39, 
    RightCurly = 40, Colon = 41, Semi = 42, Comma = 43, Equal = 44, Assign = 45, 
    Greater = 46, Less = 47, LeftLeft = 48, RightRight = 49, RightRightRight = 50, 
    Add = 51, Sub = 52, Star = 53, Div = 54, Mod = 55, Not = 56, And = 57, 
    Or = 58, Xor = 59, Dot = 60, DoubleQuotes = 61, Quotes = 62, Endl = 63, 
    Identifier = 64, Hexadecimal = 65, Decimal = 66, Octal = 67, Binary = 68, 
    Float = 69, IntegerSequence = 70, HEX_DIGIT = 71, OCTAL_DIGIT = 72, 
    BINARY_DIGIT = 73, DIGIT = 74, STRING = 75, CHAR = 76, LINE_COMMENT = 77, 
    BLOCK_COMMENT = 78, WHITESPACE = 79
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

