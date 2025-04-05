
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
    Float_ = 30, Double_ = 31, Short_ = 32, Long_ = 33, Char_ = 34, Void_ = 35, 
    LeftBracket = 36, RightBracket = 37, LeftSquare = 38, RightSquare = 39, 
    LeftCurly = 40, RightCurly = 41, Colon = 42, Semi = 43, Comma = 44, 
    Equal = 45, Assign = 46, Greater = 47, Less = 48, LeftLeft = 49, RightRight = 50, 
    RightRightRight = 51, Add = 52, Sub = 53, Star = 54, Div = 55, Mod = 56, 
    Not = 57, And = 58, Or = 59, Xor = 60, Dot = 61, DoubleQuotes = 62, 
    Quotes = 63, Endl = 64, Identifier = 65, Hexadecimal = 66, Decimal = 67, 
    Octal = 68, Binary = 69, Float = 70, IntegerSequence = 71, HEX_DIGIT = 72, 
    OCTAL_DIGIT = 73, BINARY_DIGIT = 74, DIGIT = 75, STRING = 76, CHAR = 77, 
    LINE_COMMENT = 78, BLOCK_COMMENT = 79, WHITESPACE = 80
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

