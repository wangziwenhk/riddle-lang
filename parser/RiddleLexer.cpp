
// Generated from D:/Code/Riddle-Language-cpp/RiddleLexer.g4 by ANTLR 4.13.2


#include "RiddleLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct RiddleLexerStaticData final {
  RiddleLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  RiddleLexerStaticData(const RiddleLexerStaticData&) = delete;
  RiddleLexerStaticData(RiddleLexerStaticData&&) = delete;
  RiddleLexerStaticData& operator=(const RiddleLexerStaticData&) = delete;
  RiddleLexerStaticData& operator=(RiddleLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag riddlelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<RiddleLexerStaticData> riddlelexerLexerStaticData = nullptr;

void riddlelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (riddlelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(riddlelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<RiddleLexerStaticData>(
    std::vector<std::string>{
      "Var", "Val", "For", "While", "Continue", "Break", "If", "Else", "Func", 
      "Return", "Import", "Package", "Class", "True", "False", "Null", "Try", 
      "Catch", "Override", "Static", "Const", "Public", "Protected", "Private", 
      "Virtual", "LeftBracket", "RightBracket", "LeftSquare", "RightSquare", 
      "LeftCurly", "RightCurly", "Colon", "Semi", "Comma", "Equal", "Assign", 
      "Greater", "Less", "LeftLeft", "RightRight", "RightRightRight", "Add", 
      "Sub", "Star", "Div", "Mod", "Not", "And", "Or", "Xor", "Dot", "DoubleQuotes", 
      "Quotes", "Endl", "Identifier", "Hexadecimal", "Decimal", "Octal", 
      "Binary", "Float", "IntegerSequence", "HEX_DIGIT", "OCTAL_DIGIT", 
      "BINARY_DIGIT", "DIGIT", "STRING", "ESC", "LINE_COMMENT", "BLOCK_COMMENT", 
      "WHITESPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'var'", "'val'", "'for'", "'while'", "'continue'", "'break'", 
      "'if'", "'else'", "'fun'", "'return'", "'import'", "'package'", "'class'", 
      "'true'", "'false'", "'null'", "'try'", "'catch'", "'override'", "'static'", 
      "'const'", "'public'", "'protected'", "'private'", "'virtual'", "'('", 
      "')'", "'['", "']'", "'{'", "'}'", "':'", "';'", "','", "'=='", "'='", 
      "'>'", "'<'", "'<<'", "'>>'", "'>>>'", "'+'", "'-'", "'*'", "'/'", 
      "'%'", "'!'", "'&'", "'|'", "'^'", "'.'", "'\"'", "'''", "'\\n'"
    },
    std::vector<std::string>{
      "", "Var", "Val", "For", "While", "Continue", "Break", "If", "Else", 
      "Func", "Return", "Import", "Package", "Class", "True", "False", "Null", 
      "Try", "Catch", "Override", "Static", "Const", "Public", "Protected", 
      "Private", "Virtual", "LeftBracket", "RightBracket", "LeftSquare", 
      "RightSquare", "LeftCurly", "RightCurly", "Colon", "Semi", "Comma", 
      "Equal", "Assign", "Greater", "Less", "LeftLeft", "RightRight", "RightRightRight", 
      "Add", "Sub", "Star", "Div", "Mod", "Not", "And", "Or", "Xor", "Dot", 
      "DoubleQuotes", "Quotes", "Endl", "Identifier", "Hexadecimal", "Decimal", 
      "Octal", "Binary", "Float", "IntegerSequence", "HEX_DIGIT", "OCTAL_DIGIT", 
      "BINARY_DIGIT", "DIGIT", "STRING", "LINE_COMMENT", "BLOCK_COMMENT", 
      "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,69,466,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,2,68,7,68,2,69,7,69,1,0,
  	1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,
  	1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,17,1,17,
  	1,17,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,24,1,24,
  	1,24,1,24,1,24,1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,1,29,1,29,1,30,
  	1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,36,1,36,
  	1,37,1,37,1,38,1,38,1,38,1,39,1,39,1,39,1,40,1,40,1,40,1,40,1,41,1,41,
  	1,42,1,42,1,43,1,43,1,44,1,44,1,45,1,45,1,46,1,46,1,47,1,47,1,48,1,48,
  	1,49,1,49,1,50,1,50,1,51,1,51,1,52,1,52,1,53,1,53,1,54,1,54,5,54,361,
  	8,54,10,54,12,54,364,9,54,1,55,1,55,1,55,1,55,1,55,5,55,371,8,55,10,55,
  	12,55,374,9,55,1,56,1,56,1,56,5,56,379,8,56,10,56,12,56,382,9,56,3,56,
  	384,8,56,1,57,1,57,1,57,5,57,389,8,57,10,57,12,57,392,9,57,1,58,1,58,
  	1,58,1,58,1,58,5,58,399,8,58,10,58,12,58,402,9,58,1,59,1,59,1,59,1,59,
  	1,60,4,60,409,8,60,11,60,12,60,410,1,61,1,61,1,62,1,62,1,63,1,63,1,64,
  	1,64,1,65,1,65,1,65,5,65,424,8,65,10,65,12,65,427,9,65,1,65,1,65,1,66,
  	1,66,3,66,433,8,66,1,67,1,67,1,67,1,67,5,67,439,8,67,10,67,12,67,442,
  	9,67,1,67,1,67,1,68,1,68,1,68,1,68,5,68,450,8,68,10,68,12,68,453,9,68,
  	1,68,1,68,1,68,1,68,1,68,1,69,4,69,461,8,69,11,69,12,69,462,1,69,1,69,
  	1,451,0,70,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,
  	25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,
  	24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,
  	71,36,73,37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,89,45,91,46,93,
  	47,95,48,97,49,99,50,101,51,103,52,105,53,107,54,109,55,111,56,113,57,
  	115,58,117,59,119,60,121,61,123,62,125,63,127,64,129,65,131,66,133,0,
  	135,67,137,68,139,69,1,0,13,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,
  	95,97,122,2,0,49,57,65,70,1,0,49,57,1,0,49,55,2,0,48,57,65,70,1,0,48,
  	55,1,0,48,49,1,0,48,57,4,0,10,10,13,13,34,34,92,92,5,0,34,34,47,47,65,
  	90,92,92,97,122,2,0,10,10,13,13,3,0,9,10,13,13,32,32,476,0,1,1,0,0,0,
  	0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,
  	0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,
  	0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,
  	1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,
  	0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,
  	0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,
  	1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,
  	0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,
  	0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,
  	1,0,0,0,0,101,1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,
  	1,0,0,0,0,111,1,0,0,0,0,113,1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,
  	1,0,0,0,0,121,1,0,0,0,0,123,1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,129,
  	1,0,0,0,0,131,1,0,0,0,0,135,1,0,0,0,0,137,1,0,0,0,0,139,1,0,0,0,1,141,
  	1,0,0,0,3,145,1,0,0,0,5,149,1,0,0,0,7,153,1,0,0,0,9,159,1,0,0,0,11,168,
  	1,0,0,0,13,174,1,0,0,0,15,177,1,0,0,0,17,182,1,0,0,0,19,186,1,0,0,0,21,
  	193,1,0,0,0,23,200,1,0,0,0,25,208,1,0,0,0,27,214,1,0,0,0,29,219,1,0,0,
  	0,31,225,1,0,0,0,33,230,1,0,0,0,35,234,1,0,0,0,37,240,1,0,0,0,39,249,
  	1,0,0,0,41,256,1,0,0,0,43,262,1,0,0,0,45,269,1,0,0,0,47,279,1,0,0,0,49,
  	287,1,0,0,0,51,295,1,0,0,0,53,297,1,0,0,0,55,299,1,0,0,0,57,301,1,0,0,
  	0,59,303,1,0,0,0,61,305,1,0,0,0,63,307,1,0,0,0,65,309,1,0,0,0,67,311,
  	1,0,0,0,69,313,1,0,0,0,71,316,1,0,0,0,73,318,1,0,0,0,75,320,1,0,0,0,77,
  	322,1,0,0,0,79,325,1,0,0,0,81,328,1,0,0,0,83,332,1,0,0,0,85,334,1,0,0,
  	0,87,336,1,0,0,0,89,338,1,0,0,0,91,340,1,0,0,0,93,342,1,0,0,0,95,344,
  	1,0,0,0,97,346,1,0,0,0,99,348,1,0,0,0,101,350,1,0,0,0,103,352,1,0,0,0,
  	105,354,1,0,0,0,107,356,1,0,0,0,109,358,1,0,0,0,111,365,1,0,0,0,113,383,
  	1,0,0,0,115,385,1,0,0,0,117,393,1,0,0,0,119,403,1,0,0,0,121,408,1,0,0,
  	0,123,412,1,0,0,0,125,414,1,0,0,0,127,416,1,0,0,0,129,418,1,0,0,0,131,
  	420,1,0,0,0,133,430,1,0,0,0,135,434,1,0,0,0,137,445,1,0,0,0,139,460,1,
  	0,0,0,141,142,5,118,0,0,142,143,5,97,0,0,143,144,5,114,0,0,144,2,1,0,
  	0,0,145,146,5,118,0,0,146,147,5,97,0,0,147,148,5,108,0,0,148,4,1,0,0,
  	0,149,150,5,102,0,0,150,151,5,111,0,0,151,152,5,114,0,0,152,6,1,0,0,0,
  	153,154,5,119,0,0,154,155,5,104,0,0,155,156,5,105,0,0,156,157,5,108,0,
  	0,157,158,5,101,0,0,158,8,1,0,0,0,159,160,5,99,0,0,160,161,5,111,0,0,
  	161,162,5,110,0,0,162,163,5,116,0,0,163,164,5,105,0,0,164,165,5,110,0,
  	0,165,166,5,117,0,0,166,167,5,101,0,0,167,10,1,0,0,0,168,169,5,98,0,0,
  	169,170,5,114,0,0,170,171,5,101,0,0,171,172,5,97,0,0,172,173,5,107,0,
  	0,173,12,1,0,0,0,174,175,5,105,0,0,175,176,5,102,0,0,176,14,1,0,0,0,177,
  	178,5,101,0,0,178,179,5,108,0,0,179,180,5,115,0,0,180,181,5,101,0,0,181,
  	16,1,0,0,0,182,183,5,102,0,0,183,184,5,117,0,0,184,185,5,110,0,0,185,
  	18,1,0,0,0,186,187,5,114,0,0,187,188,5,101,0,0,188,189,5,116,0,0,189,
  	190,5,117,0,0,190,191,5,114,0,0,191,192,5,110,0,0,192,20,1,0,0,0,193,
  	194,5,105,0,0,194,195,5,109,0,0,195,196,5,112,0,0,196,197,5,111,0,0,197,
  	198,5,114,0,0,198,199,5,116,0,0,199,22,1,0,0,0,200,201,5,112,0,0,201,
  	202,5,97,0,0,202,203,5,99,0,0,203,204,5,107,0,0,204,205,5,97,0,0,205,
  	206,5,103,0,0,206,207,5,101,0,0,207,24,1,0,0,0,208,209,5,99,0,0,209,210,
  	5,108,0,0,210,211,5,97,0,0,211,212,5,115,0,0,212,213,5,115,0,0,213,26,
  	1,0,0,0,214,215,5,116,0,0,215,216,5,114,0,0,216,217,5,117,0,0,217,218,
  	5,101,0,0,218,28,1,0,0,0,219,220,5,102,0,0,220,221,5,97,0,0,221,222,5,
  	108,0,0,222,223,5,115,0,0,223,224,5,101,0,0,224,30,1,0,0,0,225,226,5,
  	110,0,0,226,227,5,117,0,0,227,228,5,108,0,0,228,229,5,108,0,0,229,32,
  	1,0,0,0,230,231,5,116,0,0,231,232,5,114,0,0,232,233,5,121,0,0,233,34,
  	1,0,0,0,234,235,5,99,0,0,235,236,5,97,0,0,236,237,5,116,0,0,237,238,5,
  	99,0,0,238,239,5,104,0,0,239,36,1,0,0,0,240,241,5,111,0,0,241,242,5,118,
  	0,0,242,243,5,101,0,0,243,244,5,114,0,0,244,245,5,114,0,0,245,246,5,105,
  	0,0,246,247,5,100,0,0,247,248,5,101,0,0,248,38,1,0,0,0,249,250,5,115,
  	0,0,250,251,5,116,0,0,251,252,5,97,0,0,252,253,5,116,0,0,253,254,5,105,
  	0,0,254,255,5,99,0,0,255,40,1,0,0,0,256,257,5,99,0,0,257,258,5,111,0,
  	0,258,259,5,110,0,0,259,260,5,115,0,0,260,261,5,116,0,0,261,42,1,0,0,
  	0,262,263,5,112,0,0,263,264,5,117,0,0,264,265,5,98,0,0,265,266,5,108,
  	0,0,266,267,5,105,0,0,267,268,5,99,0,0,268,44,1,0,0,0,269,270,5,112,0,
  	0,270,271,5,114,0,0,271,272,5,111,0,0,272,273,5,116,0,0,273,274,5,101,
  	0,0,274,275,5,99,0,0,275,276,5,116,0,0,276,277,5,101,0,0,277,278,5,100,
  	0,0,278,46,1,0,0,0,279,280,5,112,0,0,280,281,5,114,0,0,281,282,5,105,
  	0,0,282,283,5,118,0,0,283,284,5,97,0,0,284,285,5,116,0,0,285,286,5,101,
  	0,0,286,48,1,0,0,0,287,288,5,118,0,0,288,289,5,105,0,0,289,290,5,114,
  	0,0,290,291,5,116,0,0,291,292,5,117,0,0,292,293,5,97,0,0,293,294,5,108,
  	0,0,294,50,1,0,0,0,295,296,5,40,0,0,296,52,1,0,0,0,297,298,5,41,0,0,298,
  	54,1,0,0,0,299,300,5,91,0,0,300,56,1,0,0,0,301,302,5,93,0,0,302,58,1,
  	0,0,0,303,304,5,123,0,0,304,60,1,0,0,0,305,306,5,125,0,0,306,62,1,0,0,
  	0,307,308,5,58,0,0,308,64,1,0,0,0,309,310,5,59,0,0,310,66,1,0,0,0,311,
  	312,5,44,0,0,312,68,1,0,0,0,313,314,5,61,0,0,314,315,5,61,0,0,315,70,
  	1,0,0,0,316,317,5,61,0,0,317,72,1,0,0,0,318,319,5,62,0,0,319,74,1,0,0,
  	0,320,321,5,60,0,0,321,76,1,0,0,0,322,323,5,60,0,0,323,324,5,60,0,0,324,
  	78,1,0,0,0,325,326,5,62,0,0,326,327,5,62,0,0,327,80,1,0,0,0,328,329,5,
  	62,0,0,329,330,5,62,0,0,330,331,5,62,0,0,331,82,1,0,0,0,332,333,5,43,
  	0,0,333,84,1,0,0,0,334,335,5,45,0,0,335,86,1,0,0,0,336,337,5,42,0,0,337,
  	88,1,0,0,0,338,339,5,47,0,0,339,90,1,0,0,0,340,341,5,37,0,0,341,92,1,
  	0,0,0,342,343,5,33,0,0,343,94,1,0,0,0,344,345,5,38,0,0,345,96,1,0,0,0,
  	346,347,5,124,0,0,347,98,1,0,0,0,348,349,5,94,0,0,349,100,1,0,0,0,350,
  	351,5,46,0,0,351,102,1,0,0,0,352,353,5,34,0,0,353,104,1,0,0,0,354,355,
  	5,39,0,0,355,106,1,0,0,0,356,357,5,10,0,0,357,108,1,0,0,0,358,362,7,0,
  	0,0,359,361,7,1,0,0,360,359,1,0,0,0,361,364,1,0,0,0,362,360,1,0,0,0,362,
  	363,1,0,0,0,363,110,1,0,0,0,364,362,1,0,0,0,365,366,5,48,0,0,366,367,
  	5,120,0,0,367,368,1,0,0,0,368,372,7,2,0,0,369,371,3,123,61,0,370,369,
  	1,0,0,0,371,374,1,0,0,0,372,370,1,0,0,0,372,373,1,0,0,0,373,112,1,0,0,
  	0,374,372,1,0,0,0,375,384,5,48,0,0,376,380,7,3,0,0,377,379,3,129,64,0,
  	378,377,1,0,0,0,379,382,1,0,0,0,380,378,1,0,0,0,380,381,1,0,0,0,381,384,
  	1,0,0,0,382,380,1,0,0,0,383,375,1,0,0,0,383,376,1,0,0,0,384,114,1,0,0,
  	0,385,386,5,48,0,0,386,390,7,4,0,0,387,389,3,125,62,0,388,387,1,0,0,0,
  	389,392,1,0,0,0,390,388,1,0,0,0,390,391,1,0,0,0,391,116,1,0,0,0,392,390,
  	1,0,0,0,393,394,5,48,0,0,394,395,5,98,0,0,395,396,1,0,0,0,396,400,5,49,
  	0,0,397,399,3,127,63,0,398,397,1,0,0,0,399,402,1,0,0,0,400,398,1,0,0,
  	0,400,401,1,0,0,0,401,118,1,0,0,0,402,400,1,0,0,0,403,404,3,113,56,0,
  	404,405,3,101,50,0,405,406,3,121,60,0,406,120,1,0,0,0,407,409,3,129,64,
  	0,408,407,1,0,0,0,409,410,1,0,0,0,410,408,1,0,0,0,410,411,1,0,0,0,411,
  	122,1,0,0,0,412,413,7,5,0,0,413,124,1,0,0,0,414,415,7,6,0,0,415,126,1,
  	0,0,0,416,417,7,7,0,0,417,128,1,0,0,0,418,419,7,8,0,0,419,130,1,0,0,0,
  	420,425,5,34,0,0,421,424,3,133,66,0,422,424,8,9,0,0,423,421,1,0,0,0,423,
  	422,1,0,0,0,424,427,1,0,0,0,425,423,1,0,0,0,425,426,1,0,0,0,426,428,1,
  	0,0,0,427,425,1,0,0,0,428,429,5,34,0,0,429,132,1,0,0,0,430,432,5,92,0,
  	0,431,433,7,10,0,0,432,431,1,0,0,0,433,134,1,0,0,0,434,435,5,47,0,0,435,
  	436,5,47,0,0,436,440,1,0,0,0,437,439,8,11,0,0,438,437,1,0,0,0,439,442,
  	1,0,0,0,440,438,1,0,0,0,440,441,1,0,0,0,441,443,1,0,0,0,442,440,1,0,0,
  	0,443,444,6,67,0,0,444,136,1,0,0,0,445,446,5,47,0,0,446,447,5,42,0,0,
  	447,451,1,0,0,0,448,450,9,0,0,0,449,448,1,0,0,0,450,453,1,0,0,0,451,452,
  	1,0,0,0,451,449,1,0,0,0,452,454,1,0,0,0,453,451,1,0,0,0,454,455,5,42,
  	0,0,455,456,5,47,0,0,456,457,1,0,0,0,457,458,6,68,0,0,458,138,1,0,0,0,
  	459,461,7,12,0,0,460,459,1,0,0,0,461,462,1,0,0,0,462,460,1,0,0,0,462,
  	463,1,0,0,0,463,464,1,0,0,0,464,465,6,69,0,0,465,140,1,0,0,0,14,0,362,
  	372,380,383,390,400,410,423,425,432,440,451,462,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  riddlelexerLexerStaticData = std::move(staticData);
}

}

RiddleLexer::RiddleLexer(CharStream *input) : Lexer(input) {
  RiddleLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *riddlelexerLexerStaticData->atn, riddlelexerLexerStaticData->decisionToDFA, riddlelexerLexerStaticData->sharedContextCache);
}

RiddleLexer::~RiddleLexer() {
  delete _interpreter;
}

std::string RiddleLexer::getGrammarFileName() const {
  return "RiddleLexer.g4";
}

const std::vector<std::string>& RiddleLexer::getRuleNames() const {
  return riddlelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& RiddleLexer::getChannelNames() const {
  return riddlelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& RiddleLexer::getModeNames() const {
  return riddlelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& RiddleLexer::getVocabulary() const {
  return riddlelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView RiddleLexer::getSerializedATN() const {
  return riddlelexerLexerStaticData->serializedATN;
}

const atn::ATN& RiddleLexer::getATN() const {
  return *riddlelexerLexerStaticData->atn;
}




void RiddleLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  riddlelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(riddlelexerLexerOnceFlag, riddlelexerLexerInitialize);
#endif
}
