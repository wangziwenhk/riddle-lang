
// Generated from C:/Users/wangz/CLionProjects/Riddle-Language/RiddleLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  RiddleLexer : public antlr4::Lexer {
public:
  enum {
        Var = 1,
        Val = 2,
        For = 3,
        While = 4,
        If = 5,
        Else = 6,
        Func = 7,
        Return = 8,
        Import = 9,
        Package = 10,
        Class = 11,
        Public = 12,
        Protected = 13,
        Private = 14,
        Override = 15,
        True = 16,
        False = 17,
        LeftBracket = 18,
        RightBracket = 19,
        LeftSquare = 20,
        RightSquare = 21,
        LeftCurly = 22,
        RightCurly = 23,
        Colon = 24,
        Semi = 25,
        Comma = 26,
        Equal = 27,
        Assign = 28,
        Greater = 29,
        Less = 30,
        LeftLeft = 31,
        RightRight = 32,
        RightRightRight = 33,
        Add = 34,
        Sub = 35,
        Star = 36,
        Div = 37,
        Mod = 38,
        Not = 39,
        And = 40,
        Or = 41,
        Xor = 42,
        Dot = 43,
        DoubleQuotes = 44,
        Quotes = 45,
        Endl = 46,
        Identifier = 47,
        Hexadecimal = 48,
        Decimal = 49,
        Octal = 50,
        Binary = 51,
        Float = 52,
        IntegerSequence = 53,
        HEX_DIGIT = 54,
        OCTAL_DIGIT = 55,
        BINARY_DIGIT = 56,
        DIGIT = 57,
        STRING = 58,
        LINE_COMMENT = 59,
        BLOCK_COMMENT = 60,
        WHITESPACE = 61
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

