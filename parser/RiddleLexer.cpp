
// Generated from C:/Users/wangz/CLionProjects/Riddle-Language/RiddleLexer.g4 by ANTLR 4.13.1


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
RiddleLexerStaticData *riddlelexerLexerStaticData = nullptr;

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
      "Var", "Val", "For", "While", "If", "Else", "Func", "Return", "Import", 
      "Package", "Class", "Public", "Protected", "Private", "Override", 
      "Printf", "True", "False", "LeftBracket", "RightBracket", "LeftCurly", 
      "RightCurly", "Colon", "Semi", "Comma", "Equal", "Assign", "Greater", 
      "Less", "LeftLeft", "RightRight", "Add", "Sub", "Star", "Div", "Mod", 
      "Not", "And", "Or", "Xor", "Dot", "DoubleQuotes", "Quotes", "Endl", 
      "Identifier", "Hexadecimal", "Decimal", "Octal", "Binary", "Float", 
      "IntegerSequence", "HEX_DIGIT", "OCTAL_DIGIT", "BINARY_DIGIT", "DIGIT", 
      "STRING", "ESC", "LINE_COMMENT", "BLOCK_COMMENT", "WHITESPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'var'", "'val'", "'for'", "'while'", "'if'", "'else'", "'fun'", 
      "'return'", "'import'", "'package'", "'class'", "'public'", "'protected'", 
      "'Private'", "'override'", "'printf'", "'true'", "'false'", "'('", 
      "')'", "'{'", "'}'", "':'", "';'", "','", "'=='", "'='", "'>'", "'<'", 
      "'<<'", "'>>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'&'", "'|'", 
      "'^'", "'.'", "'\"'", "'''", "'\\n'"
    },
    std::vector<std::string>{
      "", "Var", "Val", "For", "While", "If", "Else", "Func", "Return", 
      "Import", "Package", "Class", "Public", "Protected", "Private", "Override", 
      "Printf", "True", "False", "LeftBracket", "RightBracket", "LeftCurly", 
      "RightCurly", "Colon", "Semi", "Comma", "Equal", "Assign", "Greater", 
      "Less", "LeftLeft", "RightRight", "Add", "Sub", "Star", "Div", "Mod", 
      "Not", "And", "Or", "Xor", "Dot", "DoubleQuotes", "Quotes", "Endl", 
      "Identifier", "Hexadecimal", "Decimal", "Octal", "Binary", "Float", 
      "IntegerSequence", "HEX_DIGIT", "OCTAL_DIGIT", "BINARY_DIGIT", "DIGIT", 
      "STRING", "LINE_COMMENT", "BLOCK_COMMENT", "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,59,394,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,
  	2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,
  	1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,
  	8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,
  	1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,18,1,18,1,19,1,19,1,20,
  	1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,26,1,26,
  	1,27,1,27,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,30,1,31,1,31,1,32,1,32,
  	1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,36,1,37,1,37,1,38,1,38,1,39,1,39,
  	1,40,1,40,1,41,1,41,1,42,1,42,1,43,1,43,1,44,1,44,5,44,289,8,44,10,44,
  	12,44,292,9,44,1,45,1,45,1,45,1,45,1,45,5,45,299,8,45,10,45,12,45,302,
  	9,45,1,46,1,46,1,46,5,46,307,8,46,10,46,12,46,310,9,46,3,46,312,8,46,
  	1,47,1,47,1,47,5,47,317,8,47,10,47,12,47,320,9,47,1,48,1,48,1,48,1,48,
  	1,48,5,48,327,8,48,10,48,12,48,330,9,48,1,49,1,49,1,49,1,49,1,50,4,50,
  	337,8,50,11,50,12,50,338,1,51,1,51,1,52,1,52,1,53,1,53,1,54,1,54,1,55,
  	1,55,1,55,5,55,352,8,55,10,55,12,55,355,9,55,1,55,1,55,1,56,1,56,3,56,
  	361,8,56,1,57,1,57,1,57,1,57,5,57,367,8,57,10,57,12,57,370,9,57,1,57,
  	1,57,1,58,1,58,1,58,1,58,5,58,378,8,58,10,58,12,58,381,9,58,1,58,1,58,
  	1,58,1,58,1,58,1,59,4,59,389,8,59,11,59,12,59,390,1,59,1,59,1,379,0,60,
  	1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,
  	29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,
  	26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,37,
  	75,38,77,39,79,40,81,41,83,42,85,43,87,44,89,45,91,46,93,47,95,48,97,
  	49,99,50,101,51,103,52,105,53,107,54,109,55,111,56,113,0,115,57,117,58,
  	119,59,1,0,13,3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,2,0,
  	49,57,65,70,1,0,49,57,1,0,49,55,2,0,48,57,65,70,1,0,48,55,1,0,48,49,1,
  	0,48,57,4,0,10,10,13,13,34,34,92,92,5,0,34,34,47,47,65,90,92,92,97,122,
  	2,0,10,10,13,13,3,0,9,10,13,13,32,32,404,0,1,1,0,0,0,0,3,1,0,0,0,0,5,
  	1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,
  	0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,
  	27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,
  	0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,
  	0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,
  	59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,
  	0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,
  	0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,
  	91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,
  	1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,
  	1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,1,121,1,0,0,0,3,125,
  	1,0,0,0,5,129,1,0,0,0,7,133,1,0,0,0,9,139,1,0,0,0,11,142,1,0,0,0,13,147,
  	1,0,0,0,15,151,1,0,0,0,17,158,1,0,0,0,19,165,1,0,0,0,21,173,1,0,0,0,23,
  	179,1,0,0,0,25,186,1,0,0,0,27,196,1,0,0,0,29,204,1,0,0,0,31,213,1,0,0,
  	0,33,220,1,0,0,0,35,225,1,0,0,0,37,231,1,0,0,0,39,233,1,0,0,0,41,235,
  	1,0,0,0,43,237,1,0,0,0,45,239,1,0,0,0,47,241,1,0,0,0,49,243,1,0,0,0,51,
  	245,1,0,0,0,53,248,1,0,0,0,55,250,1,0,0,0,57,252,1,0,0,0,59,254,1,0,0,
  	0,61,257,1,0,0,0,63,260,1,0,0,0,65,262,1,0,0,0,67,264,1,0,0,0,69,266,
  	1,0,0,0,71,268,1,0,0,0,73,270,1,0,0,0,75,272,1,0,0,0,77,274,1,0,0,0,79,
  	276,1,0,0,0,81,278,1,0,0,0,83,280,1,0,0,0,85,282,1,0,0,0,87,284,1,0,0,
  	0,89,286,1,0,0,0,91,293,1,0,0,0,93,311,1,0,0,0,95,313,1,0,0,0,97,321,
  	1,0,0,0,99,331,1,0,0,0,101,336,1,0,0,0,103,340,1,0,0,0,105,342,1,0,0,
  	0,107,344,1,0,0,0,109,346,1,0,0,0,111,348,1,0,0,0,113,358,1,0,0,0,115,
  	362,1,0,0,0,117,373,1,0,0,0,119,388,1,0,0,0,121,122,5,118,0,0,122,123,
  	5,97,0,0,123,124,5,114,0,0,124,2,1,0,0,0,125,126,5,118,0,0,126,127,5,
  	97,0,0,127,128,5,108,0,0,128,4,1,0,0,0,129,130,5,102,0,0,130,131,5,111,
  	0,0,131,132,5,114,0,0,132,6,1,0,0,0,133,134,5,119,0,0,134,135,5,104,0,
  	0,135,136,5,105,0,0,136,137,5,108,0,0,137,138,5,101,0,0,138,8,1,0,0,0,
  	139,140,5,105,0,0,140,141,5,102,0,0,141,10,1,0,0,0,142,143,5,101,0,0,
  	143,144,5,108,0,0,144,145,5,115,0,0,145,146,5,101,0,0,146,12,1,0,0,0,
  	147,148,5,102,0,0,148,149,5,117,0,0,149,150,5,110,0,0,150,14,1,0,0,0,
  	151,152,5,114,0,0,152,153,5,101,0,0,153,154,5,116,0,0,154,155,5,117,0,
  	0,155,156,5,114,0,0,156,157,5,110,0,0,157,16,1,0,0,0,158,159,5,105,0,
  	0,159,160,5,109,0,0,160,161,5,112,0,0,161,162,5,111,0,0,162,163,5,114,
  	0,0,163,164,5,116,0,0,164,18,1,0,0,0,165,166,5,112,0,0,166,167,5,97,0,
  	0,167,168,5,99,0,0,168,169,5,107,0,0,169,170,5,97,0,0,170,171,5,103,0,
  	0,171,172,5,101,0,0,172,20,1,0,0,0,173,174,5,99,0,0,174,175,5,108,0,0,
  	175,176,5,97,0,0,176,177,5,115,0,0,177,178,5,115,0,0,178,22,1,0,0,0,179,
  	180,5,112,0,0,180,181,5,117,0,0,181,182,5,98,0,0,182,183,5,108,0,0,183,
  	184,5,105,0,0,184,185,5,99,0,0,185,24,1,0,0,0,186,187,5,112,0,0,187,188,
  	5,114,0,0,188,189,5,111,0,0,189,190,5,116,0,0,190,191,5,101,0,0,191,192,
  	5,99,0,0,192,193,5,116,0,0,193,194,5,101,0,0,194,195,5,100,0,0,195,26,
  	1,0,0,0,196,197,5,80,0,0,197,198,5,114,0,0,198,199,5,105,0,0,199,200,
  	5,118,0,0,200,201,5,97,0,0,201,202,5,116,0,0,202,203,5,101,0,0,203,28,
  	1,0,0,0,204,205,5,111,0,0,205,206,5,118,0,0,206,207,5,101,0,0,207,208,
  	5,114,0,0,208,209,5,114,0,0,209,210,5,105,0,0,210,211,5,100,0,0,211,212,
  	5,101,0,0,212,30,1,0,0,0,213,214,5,112,0,0,214,215,5,114,0,0,215,216,
  	5,105,0,0,216,217,5,110,0,0,217,218,5,116,0,0,218,219,5,102,0,0,219,32,
  	1,0,0,0,220,221,5,116,0,0,221,222,5,114,0,0,222,223,5,117,0,0,223,224,
  	5,101,0,0,224,34,1,0,0,0,225,226,5,102,0,0,226,227,5,97,0,0,227,228,5,
  	108,0,0,228,229,5,115,0,0,229,230,5,101,0,0,230,36,1,0,0,0,231,232,5,
  	40,0,0,232,38,1,0,0,0,233,234,5,41,0,0,234,40,1,0,0,0,235,236,5,123,0,
  	0,236,42,1,0,0,0,237,238,5,125,0,0,238,44,1,0,0,0,239,240,5,58,0,0,240,
  	46,1,0,0,0,241,242,5,59,0,0,242,48,1,0,0,0,243,244,5,44,0,0,244,50,1,
  	0,0,0,245,246,5,61,0,0,246,247,5,61,0,0,247,52,1,0,0,0,248,249,5,61,0,
  	0,249,54,1,0,0,0,250,251,5,62,0,0,251,56,1,0,0,0,252,253,5,60,0,0,253,
  	58,1,0,0,0,254,255,5,60,0,0,255,256,5,60,0,0,256,60,1,0,0,0,257,258,5,
  	62,0,0,258,259,5,62,0,0,259,62,1,0,0,0,260,261,5,43,0,0,261,64,1,0,0,
  	0,262,263,5,45,0,0,263,66,1,0,0,0,264,265,5,42,0,0,265,68,1,0,0,0,266,
  	267,5,47,0,0,267,70,1,0,0,0,268,269,5,37,0,0,269,72,1,0,0,0,270,271,5,
  	33,0,0,271,74,1,0,0,0,272,273,5,38,0,0,273,76,1,0,0,0,274,275,5,124,0,
  	0,275,78,1,0,0,0,276,277,5,94,0,0,277,80,1,0,0,0,278,279,5,46,0,0,279,
  	82,1,0,0,0,280,281,5,34,0,0,281,84,1,0,0,0,282,283,5,39,0,0,283,86,1,
  	0,0,0,284,285,5,10,0,0,285,88,1,0,0,0,286,290,7,0,0,0,287,289,7,1,0,0,
  	288,287,1,0,0,0,289,292,1,0,0,0,290,288,1,0,0,0,290,291,1,0,0,0,291,90,
  	1,0,0,0,292,290,1,0,0,0,293,294,5,48,0,0,294,295,5,120,0,0,295,296,1,
  	0,0,0,296,300,7,2,0,0,297,299,3,103,51,0,298,297,1,0,0,0,299,302,1,0,
  	0,0,300,298,1,0,0,0,300,301,1,0,0,0,301,92,1,0,0,0,302,300,1,0,0,0,303,
  	312,5,48,0,0,304,308,7,3,0,0,305,307,3,109,54,0,306,305,1,0,0,0,307,310,
  	1,0,0,0,308,306,1,0,0,0,308,309,1,0,0,0,309,312,1,0,0,0,310,308,1,0,0,
  	0,311,303,1,0,0,0,311,304,1,0,0,0,312,94,1,0,0,0,313,314,5,48,0,0,314,
  	318,7,4,0,0,315,317,3,105,52,0,316,315,1,0,0,0,317,320,1,0,0,0,318,316,
  	1,0,0,0,318,319,1,0,0,0,319,96,1,0,0,0,320,318,1,0,0,0,321,322,5,48,0,
  	0,322,323,5,98,0,0,323,324,1,0,0,0,324,328,5,49,0,0,325,327,3,107,53,
  	0,326,325,1,0,0,0,327,330,1,0,0,0,328,326,1,0,0,0,328,329,1,0,0,0,329,
  	98,1,0,0,0,330,328,1,0,0,0,331,332,3,93,46,0,332,333,3,81,40,0,333,334,
  	3,101,50,0,334,100,1,0,0,0,335,337,3,109,54,0,336,335,1,0,0,0,337,338,
  	1,0,0,0,338,336,1,0,0,0,338,339,1,0,0,0,339,102,1,0,0,0,340,341,7,5,0,
  	0,341,104,1,0,0,0,342,343,7,6,0,0,343,106,1,0,0,0,344,345,7,7,0,0,345,
  	108,1,0,0,0,346,347,7,8,0,0,347,110,1,0,0,0,348,353,5,34,0,0,349,352,
  	3,113,56,0,350,352,8,9,0,0,351,349,1,0,0,0,351,350,1,0,0,0,352,355,1,
  	0,0,0,353,351,1,0,0,0,353,354,1,0,0,0,354,356,1,0,0,0,355,353,1,0,0,0,
  	356,357,5,34,0,0,357,112,1,0,0,0,358,360,5,92,0,0,359,361,7,10,0,0,360,
  	359,1,0,0,0,361,114,1,0,0,0,362,363,5,47,0,0,363,364,5,47,0,0,364,368,
  	1,0,0,0,365,367,8,11,0,0,366,365,1,0,0,0,367,370,1,0,0,0,368,366,1,0,
  	0,0,368,369,1,0,0,0,369,371,1,0,0,0,370,368,1,0,0,0,371,372,6,57,0,0,
  	372,116,1,0,0,0,373,374,5,47,0,0,374,375,5,42,0,0,375,379,1,0,0,0,376,
  	378,9,0,0,0,377,376,1,0,0,0,378,381,1,0,0,0,379,380,1,0,0,0,379,377,1,
  	0,0,0,380,382,1,0,0,0,381,379,1,0,0,0,382,383,5,42,0,0,383,384,5,47,0,
  	0,384,385,1,0,0,0,385,386,6,58,0,0,386,118,1,0,0,0,387,389,7,12,0,0,388,
  	387,1,0,0,0,389,390,1,0,0,0,390,388,1,0,0,0,390,391,1,0,0,0,391,392,1,
  	0,0,0,392,393,6,59,0,0,393,120,1,0,0,0,14,0,290,300,308,311,318,328,338,
  	351,353,360,368,379,390,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  riddlelexerLexerStaticData = staticData.release();
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
