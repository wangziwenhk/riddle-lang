
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
      "Printf", "LeftBracket", "RightBracket", "LeftCurly", "RightCurly", 
      "Colon", "Semi", "Comma", "Equal", "Assign", "Greater", "Less", "LeftLeft", 
      "RightRight", "Add", "Sub", "Star", "Div", "Mod", "Not", "And", "Or", 
      "Xor", "Dot", "DoubleQuotes", "Quotes", "Endl", "Identifier", "Hexadecimal", 
      "Decimal", "Octal", "Binary", "Float", "IntegerSequence", "HEX_DIGIT", 
      "OCTAL_DIGIT", "BINARY_DIGIT", "DIGIT", "STRING", "ESC", "LINE_COMMENT", 
      "BLOCK_COMMENT", "WHITESPACE"
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
      "'Private'", "'override'", "'printf'", "'('", "')'", "'{'", "'}'", 
      "':'", "';'", "','", "'=='", "'='", "'>'", "'<'", "'<<'", "'>>'", 
      "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'&'", "'|'", "'^'", "'.'", 
      "'\"'", "'''", "'\\n'"
    },
    std::vector<std::string>{
      "", "Var", "Val", "For", "While", "If", "Else", "Func", "Return", 
      "Import", "Package", "Class", "Public", "Protected", "Private", "Override", 
      "Printf", "LeftBracket", "RightBracket", "LeftCurly", "RightCurly", 
      "Colon", "Semi", "Comma", "Equal", "Assign", "Greater", "Less", "LeftLeft", 
      "RightRight", "Add", "Sub", "Star", "Div", "Mod", "Not", "And", "Or", 
      "Xor", "Dot", "DoubleQuotes", "Quotes", "Endl", "Identifier", "Hexadecimal", 
      "Decimal", "Octal", "Binary", "Float", "IntegerSequence", "HEX_DIGIT", 
      "OCTAL_DIGIT", "BINARY_DIGIT", "DIGIT", "STRING", "LINE_COMMENT", 
      "BLOCK_COMMENT", "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,57,379,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,16,1,16,1,17,1,17,1,18,1,18,
  	1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,25,
  	1,25,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,28,1,29,1,29,1,30,1,30,1,31,
  	1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,36,1,37,1,37,1,38,
  	1,38,1,39,1,39,1,40,1,40,1,41,1,41,1,42,1,42,5,42,274,8,42,10,42,12,42,
  	277,9,42,1,43,1,43,1,43,1,43,1,43,5,43,284,8,43,10,43,12,43,287,9,43,
  	1,44,1,44,1,44,5,44,292,8,44,10,44,12,44,295,9,44,3,44,297,8,44,1,45,
  	1,45,1,45,5,45,302,8,45,10,45,12,45,305,9,45,1,46,1,46,1,46,1,46,1,46,
  	5,46,312,8,46,10,46,12,46,315,9,46,1,47,1,47,1,47,1,47,1,48,4,48,322,
  	8,48,11,48,12,48,323,1,49,1,49,1,50,1,50,1,51,1,51,1,52,1,52,1,53,1,53,
  	1,53,5,53,337,8,53,10,53,12,53,340,9,53,1,53,1,53,1,54,1,54,3,54,346,
  	8,54,1,55,1,55,1,55,1,55,5,55,352,8,55,10,55,12,55,355,9,55,1,55,1,55,
  	1,56,1,56,1,56,1,56,5,56,363,8,56,10,56,12,56,366,9,56,1,56,1,56,1,56,
  	1,56,1,56,1,57,4,57,374,8,57,11,57,12,57,375,1,57,1,57,1,364,0,58,1,1,
  	3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,
  	15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,
  	53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,37,75,
  	38,77,39,79,40,81,41,83,42,85,43,87,44,89,45,91,46,93,47,95,48,97,49,
  	99,50,101,51,103,52,105,53,107,54,109,0,111,55,113,56,115,57,1,0,13,3,
  	0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,2,0,49,57,65,70,1,0,
  	49,57,1,0,49,55,2,0,48,57,65,70,1,0,48,55,1,0,48,49,1,0,48,57,4,0,10,
  	10,13,13,34,34,92,92,5,0,34,34,47,47,65,90,92,92,97,122,2,0,10,10,13,
  	13,3,0,9,10,13,13,32,32,389,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,
  	0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,
  	0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,
  	1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,
  	0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,
  	0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,
  	1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,
  	0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,
  	0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,0,93,
  	1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,0,103,1,
  	0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,111,1,0,0,0,0,113,1,0,0,0,0,115,1,
  	0,0,0,1,117,1,0,0,0,3,121,1,0,0,0,5,125,1,0,0,0,7,129,1,0,0,0,9,135,1,
  	0,0,0,11,138,1,0,0,0,13,143,1,0,0,0,15,147,1,0,0,0,17,154,1,0,0,0,19,
  	161,1,0,0,0,21,169,1,0,0,0,23,175,1,0,0,0,25,182,1,0,0,0,27,192,1,0,0,
  	0,29,200,1,0,0,0,31,209,1,0,0,0,33,216,1,0,0,0,35,218,1,0,0,0,37,220,
  	1,0,0,0,39,222,1,0,0,0,41,224,1,0,0,0,43,226,1,0,0,0,45,228,1,0,0,0,47,
  	230,1,0,0,0,49,233,1,0,0,0,51,235,1,0,0,0,53,237,1,0,0,0,55,239,1,0,0,
  	0,57,242,1,0,0,0,59,245,1,0,0,0,61,247,1,0,0,0,63,249,1,0,0,0,65,251,
  	1,0,0,0,67,253,1,0,0,0,69,255,1,0,0,0,71,257,1,0,0,0,73,259,1,0,0,0,75,
  	261,1,0,0,0,77,263,1,0,0,0,79,265,1,0,0,0,81,267,1,0,0,0,83,269,1,0,0,
  	0,85,271,1,0,0,0,87,278,1,0,0,0,89,296,1,0,0,0,91,298,1,0,0,0,93,306,
  	1,0,0,0,95,316,1,0,0,0,97,321,1,0,0,0,99,325,1,0,0,0,101,327,1,0,0,0,
  	103,329,1,0,0,0,105,331,1,0,0,0,107,333,1,0,0,0,109,343,1,0,0,0,111,347,
  	1,0,0,0,113,358,1,0,0,0,115,373,1,0,0,0,117,118,5,118,0,0,118,119,5,97,
  	0,0,119,120,5,114,0,0,120,2,1,0,0,0,121,122,5,118,0,0,122,123,5,97,0,
  	0,123,124,5,108,0,0,124,4,1,0,0,0,125,126,5,102,0,0,126,127,5,111,0,0,
  	127,128,5,114,0,0,128,6,1,0,0,0,129,130,5,119,0,0,130,131,5,104,0,0,131,
  	132,5,105,0,0,132,133,5,108,0,0,133,134,5,101,0,0,134,8,1,0,0,0,135,136,
  	5,105,0,0,136,137,5,102,0,0,137,10,1,0,0,0,138,139,5,101,0,0,139,140,
  	5,108,0,0,140,141,5,115,0,0,141,142,5,101,0,0,142,12,1,0,0,0,143,144,
  	5,102,0,0,144,145,5,117,0,0,145,146,5,110,0,0,146,14,1,0,0,0,147,148,
  	5,114,0,0,148,149,5,101,0,0,149,150,5,116,0,0,150,151,5,117,0,0,151,152,
  	5,114,0,0,152,153,5,110,0,0,153,16,1,0,0,0,154,155,5,105,0,0,155,156,
  	5,109,0,0,156,157,5,112,0,0,157,158,5,111,0,0,158,159,5,114,0,0,159,160,
  	5,116,0,0,160,18,1,0,0,0,161,162,5,112,0,0,162,163,5,97,0,0,163,164,5,
  	99,0,0,164,165,5,107,0,0,165,166,5,97,0,0,166,167,5,103,0,0,167,168,5,
  	101,0,0,168,20,1,0,0,0,169,170,5,99,0,0,170,171,5,108,0,0,171,172,5,97,
  	0,0,172,173,5,115,0,0,173,174,5,115,0,0,174,22,1,0,0,0,175,176,5,112,
  	0,0,176,177,5,117,0,0,177,178,5,98,0,0,178,179,5,108,0,0,179,180,5,105,
  	0,0,180,181,5,99,0,0,181,24,1,0,0,0,182,183,5,112,0,0,183,184,5,114,0,
  	0,184,185,5,111,0,0,185,186,5,116,0,0,186,187,5,101,0,0,187,188,5,99,
  	0,0,188,189,5,116,0,0,189,190,5,101,0,0,190,191,5,100,0,0,191,26,1,0,
  	0,0,192,193,5,80,0,0,193,194,5,114,0,0,194,195,5,105,0,0,195,196,5,118,
  	0,0,196,197,5,97,0,0,197,198,5,116,0,0,198,199,5,101,0,0,199,28,1,0,0,
  	0,200,201,5,111,0,0,201,202,5,118,0,0,202,203,5,101,0,0,203,204,5,114,
  	0,0,204,205,5,114,0,0,205,206,5,105,0,0,206,207,5,100,0,0,207,208,5,101,
  	0,0,208,30,1,0,0,0,209,210,5,112,0,0,210,211,5,114,0,0,211,212,5,105,
  	0,0,212,213,5,110,0,0,213,214,5,116,0,0,214,215,5,102,0,0,215,32,1,0,
  	0,0,216,217,5,40,0,0,217,34,1,0,0,0,218,219,5,41,0,0,219,36,1,0,0,0,220,
  	221,5,123,0,0,221,38,1,0,0,0,222,223,5,125,0,0,223,40,1,0,0,0,224,225,
  	5,58,0,0,225,42,1,0,0,0,226,227,5,59,0,0,227,44,1,0,0,0,228,229,5,44,
  	0,0,229,46,1,0,0,0,230,231,5,61,0,0,231,232,5,61,0,0,232,48,1,0,0,0,233,
  	234,5,61,0,0,234,50,1,0,0,0,235,236,5,62,0,0,236,52,1,0,0,0,237,238,5,
  	60,0,0,238,54,1,0,0,0,239,240,5,60,0,0,240,241,5,60,0,0,241,56,1,0,0,
  	0,242,243,5,62,0,0,243,244,5,62,0,0,244,58,1,0,0,0,245,246,5,43,0,0,246,
  	60,1,0,0,0,247,248,5,45,0,0,248,62,1,0,0,0,249,250,5,42,0,0,250,64,1,
  	0,0,0,251,252,5,47,0,0,252,66,1,0,0,0,253,254,5,37,0,0,254,68,1,0,0,0,
  	255,256,5,33,0,0,256,70,1,0,0,0,257,258,5,38,0,0,258,72,1,0,0,0,259,260,
  	5,124,0,0,260,74,1,0,0,0,261,262,5,94,0,0,262,76,1,0,0,0,263,264,5,46,
  	0,0,264,78,1,0,0,0,265,266,5,34,0,0,266,80,1,0,0,0,267,268,5,39,0,0,268,
  	82,1,0,0,0,269,270,5,10,0,0,270,84,1,0,0,0,271,275,7,0,0,0,272,274,7,
  	1,0,0,273,272,1,0,0,0,274,277,1,0,0,0,275,273,1,0,0,0,275,276,1,0,0,0,
  	276,86,1,0,0,0,277,275,1,0,0,0,278,279,5,48,0,0,279,280,5,120,0,0,280,
  	281,1,0,0,0,281,285,7,2,0,0,282,284,3,99,49,0,283,282,1,0,0,0,284,287,
  	1,0,0,0,285,283,1,0,0,0,285,286,1,0,0,0,286,88,1,0,0,0,287,285,1,0,0,
  	0,288,297,5,48,0,0,289,293,7,3,0,0,290,292,3,105,52,0,291,290,1,0,0,0,
  	292,295,1,0,0,0,293,291,1,0,0,0,293,294,1,0,0,0,294,297,1,0,0,0,295,293,
  	1,0,0,0,296,288,1,0,0,0,296,289,1,0,0,0,297,90,1,0,0,0,298,299,5,48,0,
  	0,299,303,7,4,0,0,300,302,3,101,50,0,301,300,1,0,0,0,302,305,1,0,0,0,
  	303,301,1,0,0,0,303,304,1,0,0,0,304,92,1,0,0,0,305,303,1,0,0,0,306,307,
  	5,48,0,0,307,308,5,98,0,0,308,309,1,0,0,0,309,313,5,49,0,0,310,312,3,
  	103,51,0,311,310,1,0,0,0,312,315,1,0,0,0,313,311,1,0,0,0,313,314,1,0,
  	0,0,314,94,1,0,0,0,315,313,1,0,0,0,316,317,3,89,44,0,317,318,3,77,38,
  	0,318,319,3,97,48,0,319,96,1,0,0,0,320,322,3,105,52,0,321,320,1,0,0,0,
  	322,323,1,0,0,0,323,321,1,0,0,0,323,324,1,0,0,0,324,98,1,0,0,0,325,326,
  	7,5,0,0,326,100,1,0,0,0,327,328,7,6,0,0,328,102,1,0,0,0,329,330,7,7,0,
  	0,330,104,1,0,0,0,331,332,7,8,0,0,332,106,1,0,0,0,333,338,5,34,0,0,334,
  	337,3,109,54,0,335,337,8,9,0,0,336,334,1,0,0,0,336,335,1,0,0,0,337,340,
  	1,0,0,0,338,336,1,0,0,0,338,339,1,0,0,0,339,341,1,0,0,0,340,338,1,0,0,
  	0,341,342,5,34,0,0,342,108,1,0,0,0,343,345,5,92,0,0,344,346,7,10,0,0,
  	345,344,1,0,0,0,346,110,1,0,0,0,347,348,5,47,0,0,348,349,5,47,0,0,349,
  	353,1,0,0,0,350,352,8,11,0,0,351,350,1,0,0,0,352,355,1,0,0,0,353,351,
  	1,0,0,0,353,354,1,0,0,0,354,356,1,0,0,0,355,353,1,0,0,0,356,357,6,55,
  	0,0,357,112,1,0,0,0,358,359,5,47,0,0,359,360,5,42,0,0,360,364,1,0,0,0,
  	361,363,9,0,0,0,362,361,1,0,0,0,363,366,1,0,0,0,364,365,1,0,0,0,364,362,
  	1,0,0,0,365,367,1,0,0,0,366,364,1,0,0,0,367,368,5,42,0,0,368,369,5,47,
  	0,0,369,370,1,0,0,0,370,371,6,56,0,0,371,114,1,0,0,0,372,374,7,12,0,0,
  	373,372,1,0,0,0,374,375,1,0,0,0,375,373,1,0,0,0,375,376,1,0,0,0,376,377,
  	1,0,0,0,377,378,6,57,0,0,378,116,1,0,0,0,14,0,275,285,293,296,303,313,
  	323,336,338,345,353,364,375,1,6,0,0
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
