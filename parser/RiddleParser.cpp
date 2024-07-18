
// Generated from C:/Users/wangz/CLionProjects/Riddle-Language/RiddleParser.g4 by ANTLR 4.13.1


#include "RiddleParserListener.h"
#include "RiddleParserVisitor.h"

#include "RiddleParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct RiddleParserStaticData final {
  RiddleParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  RiddleParserStaticData(const RiddleParserStaticData&) = delete;
  RiddleParserStaticData(RiddleParserStaticData&&) = delete;
  RiddleParserStaticData& operator=(const RiddleParserStaticData&) = delete;
  RiddleParserStaticData& operator=(RiddleParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag riddleparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
RiddleParserStaticData *riddleparserParserStaticData = nullptr;

void riddleparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (riddleparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(riddleparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<RiddleParserStaticData>(
    std::vector<std::string>{
      "program", "statement_ed", "statement", "packStatement", "importStatement", 
      "varDefineStatement", "funcExpr", "argsExpr", "defineArgs", "funcDefine", 
      "funcBody", "forStatement", "whileStatement", "ifStatement", "returnStatement", 
      "expression", "objectExpr", "id", "number", "string", "float", "integer", 
      "print"
    },
    std::vector<std::string>{
      "", "'var'", "'val'", "'for'", "'while'", "'if'", "'else'", "'fun'", 
      "'return'", "'import'", "'package'", "'class'", "'public'", "'protected'", 
      "'Private'", "'override'", "'print'", "'('", "')'", "'{'", "'}'", 
      "':'", "';'", "','", "'=='", "'='", "'>'", "'<'", "'<<'", "'>>'", 
      "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'&'", "'|'", "'^'", "'.'", 
      "'\"'", "'''", "'\\n'"
    },
    std::vector<std::string>{
      "", "Var", "Val", "For", "While", "If", "Else", "Func", "Return", 
      "Import", "Package", "Class", "Public", "Protected", "Private", "Override", 
      "Print", "LeftBracket", "RightBracket", "LeftCurly", "RightCurly", 
      "Colon", "Semi", "Comma", "Equal", "Assign", "Greater", "Less", "LeftLeft", 
      "RightRight", "Add", "Sub", "Star", "Div", "Mod", "Not", "And", "Or", 
      "Xor", "Dot", "DoubleQuotes", "Quotes", "Endl", "Identifier", "Hexadecimal", 
      "Decimal", "Octal", "Binary", "Float", "IntegerSequence", "HEX_DIGIT", 
      "OCTAL_DIGIT", "BINARY_DIGIT", "DIGIT", "STRING", "LINE_COMMENT", 
      "BLOCK_COMMENT", "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,57,386,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,1,0,5,0,48,8,0,10,0,12,0,51,9,0,1,0,3,0,54,8,0,1,1,1,1,3,
  	1,58,8,1,1,1,3,1,61,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,5,2,76,8,2,10,2,12,2,79,9,2,1,2,3,2,82,8,2,1,3,1,3,1,3,1,4,1,4,
  	1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,104,8,
  	5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,5,7,114,8,7,10,7,12,7,117,9,7,1,7,3,
  	7,120,8,7,1,8,1,8,1,8,1,8,1,8,5,8,127,8,8,10,8,12,8,130,9,8,1,8,1,8,1,
  	8,3,8,135,8,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,144,8,9,1,9,1,9,1,9,1,9,
  	1,10,5,10,151,8,10,10,10,12,10,154,9,10,1,11,1,11,1,11,3,11,159,8,11,
  	1,11,1,11,3,11,163,8,11,1,11,1,11,3,11,167,8,11,1,11,1,11,1,11,1,12,1,
  	12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,194,8,13,1,14,1,14,1,14,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,3,15,286,8,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,5,15,347,8,15,10,15,12,15,350,9,
  	15,1,16,1,16,1,17,1,17,1,17,5,17,357,8,17,10,17,12,17,360,9,17,1,18,1,
  	18,3,18,364,8,18,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,
  	21,1,21,1,21,3,21,379,8,21,1,22,1,22,1,22,1,22,1,22,1,22,0,1,30,23,0,
  	2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,0,0,435,
  	0,53,1,0,0,0,2,55,1,0,0,0,4,81,1,0,0,0,6,83,1,0,0,0,8,86,1,0,0,0,10,103,
  	1,0,0,0,12,105,1,0,0,0,14,119,1,0,0,0,16,134,1,0,0,0,18,136,1,0,0,0,20,
  	152,1,0,0,0,22,155,1,0,0,0,24,171,1,0,0,0,26,193,1,0,0,0,28,195,1,0,0,
  	0,30,285,1,0,0,0,32,351,1,0,0,0,34,353,1,0,0,0,36,363,1,0,0,0,38,365,
  	1,0,0,0,40,367,1,0,0,0,42,378,1,0,0,0,44,380,1,0,0,0,46,48,3,2,1,0,47,
  	46,1,0,0,0,48,51,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,54,1,0,0,0,51,
  	49,1,0,0,0,52,54,5,0,0,1,53,49,1,0,0,0,53,52,1,0,0,0,54,1,1,0,0,0,55,
  	57,3,4,2,0,56,58,5,22,0,0,57,56,1,0,0,0,57,58,1,0,0,0,58,60,1,0,0,0,59,
  	61,5,42,0,0,60,59,1,0,0,0,60,61,1,0,0,0,61,3,1,0,0,0,62,82,3,44,22,0,
  	63,82,3,6,3,0,64,82,3,8,4,0,65,82,3,18,9,0,66,82,3,12,6,0,67,82,3,10,
  	5,0,68,82,3,22,11,0,69,82,3,24,12,0,70,82,3,26,13,0,71,82,3,28,14,0,72,
  	82,3,30,15,0,73,77,5,19,0,0,74,76,3,2,1,0,75,74,1,0,0,0,76,79,1,0,0,0,
  	77,75,1,0,0,0,77,78,1,0,0,0,78,80,1,0,0,0,79,77,1,0,0,0,80,82,5,20,0,
  	0,81,62,1,0,0,0,81,63,1,0,0,0,81,64,1,0,0,0,81,65,1,0,0,0,81,66,1,0,0,
  	0,81,67,1,0,0,0,81,68,1,0,0,0,81,69,1,0,0,0,81,70,1,0,0,0,81,71,1,0,0,
  	0,81,72,1,0,0,0,81,73,1,0,0,0,82,5,1,0,0,0,83,84,5,10,0,0,84,85,3,34,
  	17,0,85,7,1,0,0,0,86,87,5,9,0,0,87,88,3,34,17,0,88,9,1,0,0,0,89,90,5,
  	1,0,0,90,91,5,43,0,0,91,92,5,21,0,0,92,104,5,43,0,0,93,94,5,1,0,0,94,
  	95,5,43,0,0,95,96,5,25,0,0,96,104,3,30,15,0,97,98,5,1,0,0,98,99,5,43,
  	0,0,99,100,5,21,0,0,100,101,5,43,0,0,101,102,5,25,0,0,102,104,3,30,15,
  	0,103,89,1,0,0,0,103,93,1,0,0,0,103,97,1,0,0,0,104,11,1,0,0,0,105,106,
  	3,34,17,0,106,107,5,17,0,0,107,108,3,14,7,0,108,109,5,18,0,0,109,13,1,
  	0,0,0,110,111,3,30,15,0,111,112,5,23,0,0,112,114,1,0,0,0,113,110,1,0,
  	0,0,114,117,1,0,0,0,115,113,1,0,0,0,115,116,1,0,0,0,116,118,1,0,0,0,117,
  	115,1,0,0,0,118,120,3,30,15,0,119,115,1,0,0,0,119,120,1,0,0,0,120,15,
  	1,0,0,0,121,122,5,43,0,0,122,123,5,21,0,0,123,124,3,34,17,0,124,125,5,
  	23,0,0,125,127,1,0,0,0,126,121,1,0,0,0,127,130,1,0,0,0,128,126,1,0,0,
  	0,128,129,1,0,0,0,129,131,1,0,0,0,130,128,1,0,0,0,131,132,5,43,0,0,132,
  	133,5,21,0,0,133,135,3,34,17,0,134,128,1,0,0,0,134,135,1,0,0,0,135,17,
  	1,0,0,0,136,137,5,7,0,0,137,138,5,43,0,0,138,139,5,17,0,0,139,140,3,16,
  	8,0,140,143,5,18,0,0,141,142,5,21,0,0,142,144,3,34,17,0,143,141,1,0,0,
  	0,143,144,1,0,0,0,144,145,1,0,0,0,145,146,5,19,0,0,146,147,3,20,10,0,
  	147,148,5,20,0,0,148,19,1,0,0,0,149,151,3,2,1,0,150,149,1,0,0,0,151,154,
  	1,0,0,0,152,150,1,0,0,0,152,153,1,0,0,0,153,21,1,0,0,0,154,152,1,0,0,
  	0,155,156,5,3,0,0,156,158,5,17,0,0,157,159,3,10,5,0,158,157,1,0,0,0,158,
  	159,1,0,0,0,159,160,1,0,0,0,160,162,5,22,0,0,161,163,3,30,15,0,162,161,
  	1,0,0,0,162,163,1,0,0,0,163,164,1,0,0,0,164,166,5,22,0,0,165,167,3,4,
  	2,0,166,165,1,0,0,0,166,167,1,0,0,0,167,168,1,0,0,0,168,169,5,18,0,0,
  	169,170,3,2,1,0,170,23,1,0,0,0,171,172,5,4,0,0,172,173,5,17,0,0,173,174,
  	3,30,15,0,174,175,5,18,0,0,175,176,3,2,1,0,176,25,1,0,0,0,177,178,5,5,
  	0,0,178,179,5,17,0,0,179,180,3,30,15,0,180,181,5,18,0,0,181,182,3,2,1,
  	0,182,183,6,13,-1,0,183,194,1,0,0,0,184,185,5,5,0,0,185,186,5,17,0,0,
  	186,187,3,30,15,0,187,188,5,18,0,0,188,189,3,2,1,0,189,190,5,6,0,0,190,
  	191,3,2,1,0,191,192,6,13,-1,0,192,194,1,0,0,0,193,177,1,0,0,0,193,184,
  	1,0,0,0,194,27,1,0,0,0,195,196,5,8,0,0,196,197,3,2,1,0,197,29,1,0,0,0,
  	198,199,6,15,-1,0,199,200,5,17,0,0,200,201,3,30,15,0,201,202,5,18,0,0,
  	202,286,1,0,0,0,203,204,5,35,0,0,204,286,3,30,15,40,205,206,5,30,0,0,
  	206,286,3,30,15,39,207,208,5,31,0,0,208,286,3,30,15,38,209,210,5,30,0,
  	0,210,211,5,30,0,0,211,286,3,32,16,0,212,213,3,32,16,0,213,214,5,30,0,
  	0,214,215,5,30,0,0,215,286,1,0,0,0,216,217,5,31,0,0,217,218,5,31,0,0,
  	218,286,3,32,16,0,219,220,3,32,16,0,220,221,5,31,0,0,221,222,5,31,0,0,
  	222,286,1,0,0,0,223,224,3,32,16,0,224,225,5,25,0,0,225,226,3,30,15,15,
  	226,286,1,0,0,0,227,228,3,32,16,0,228,229,5,30,0,0,229,230,5,25,0,0,230,
  	231,3,30,15,14,231,286,1,0,0,0,232,233,3,32,16,0,233,234,5,31,0,0,234,
  	235,5,25,0,0,235,236,3,30,15,13,236,286,1,0,0,0,237,238,3,32,16,0,238,
  	239,5,32,0,0,239,240,5,25,0,0,240,241,3,30,15,12,241,286,1,0,0,0,242,
  	243,3,32,16,0,243,244,5,33,0,0,244,245,5,25,0,0,245,246,3,30,15,11,246,
  	286,1,0,0,0,247,248,3,32,16,0,248,249,5,34,0,0,249,250,5,25,0,0,250,251,
  	3,30,15,10,251,286,1,0,0,0,252,253,3,32,16,0,253,254,5,30,0,0,254,255,
  	5,25,0,0,255,256,3,30,15,9,256,286,1,0,0,0,257,258,3,32,16,0,258,259,
  	5,36,0,0,259,260,5,25,0,0,260,261,3,30,15,8,261,286,1,0,0,0,262,263,3,
  	32,16,0,263,264,5,37,0,0,264,265,5,25,0,0,265,266,3,30,15,7,266,286,1,
  	0,0,0,267,268,3,32,16,0,268,269,5,38,0,0,269,270,5,25,0,0,270,271,3,30,
  	15,6,271,286,1,0,0,0,272,273,3,32,16,0,273,274,5,28,0,0,274,275,5,25,
  	0,0,275,276,3,30,15,5,276,286,1,0,0,0,277,278,3,32,16,0,278,279,5,29,
  	0,0,279,280,5,25,0,0,280,281,3,30,15,4,281,286,1,0,0,0,282,286,3,38,19,
  	0,283,286,3,36,18,0,284,286,3,34,17,0,285,198,1,0,0,0,285,203,1,0,0,0,
  	285,205,1,0,0,0,285,207,1,0,0,0,285,209,1,0,0,0,285,212,1,0,0,0,285,216,
  	1,0,0,0,285,219,1,0,0,0,285,223,1,0,0,0,285,227,1,0,0,0,285,232,1,0,0,
  	0,285,237,1,0,0,0,285,242,1,0,0,0,285,247,1,0,0,0,285,252,1,0,0,0,285,
  	257,1,0,0,0,285,262,1,0,0,0,285,267,1,0,0,0,285,272,1,0,0,0,285,277,1,
  	0,0,0,285,282,1,0,0,0,285,283,1,0,0,0,285,284,1,0,0,0,286,348,1,0,0,0,
  	287,288,10,33,0,0,288,289,5,32,0,0,289,347,3,30,15,34,290,291,10,32,0,
  	0,291,292,5,33,0,0,292,347,3,30,15,33,293,294,10,31,0,0,294,295,5,34,
  	0,0,295,347,3,30,15,32,296,297,10,30,0,0,297,298,5,30,0,0,298,347,3,30,
  	15,31,299,300,10,29,0,0,300,301,5,31,0,0,301,347,3,30,15,30,302,303,10,
  	28,0,0,303,304,5,28,0,0,304,347,3,30,15,29,305,306,10,27,0,0,306,307,
  	5,29,0,0,307,347,3,30,15,28,308,309,10,26,0,0,309,310,5,26,0,0,310,347,
  	3,30,15,27,311,312,10,25,0,0,312,313,5,27,0,0,313,347,3,30,15,26,314,
  	315,10,24,0,0,315,316,5,26,0,0,316,317,5,25,0,0,317,347,3,30,15,25,318,
  	319,10,23,0,0,319,320,5,27,0,0,320,321,5,25,0,0,321,347,3,30,15,24,322,
  	323,10,22,0,0,323,324,5,24,0,0,324,347,3,30,15,23,325,326,10,21,0,0,326,
  	327,5,35,0,0,327,328,5,24,0,0,328,347,3,30,15,22,329,330,10,20,0,0,330,
  	331,5,36,0,0,331,347,3,30,15,21,332,333,10,19,0,0,333,334,5,38,0,0,334,
  	347,3,30,15,20,335,336,10,18,0,0,336,337,5,37,0,0,337,347,3,30,15,19,
  	338,339,10,17,0,0,339,340,5,36,0,0,340,341,5,36,0,0,341,347,3,30,15,18,
  	342,343,10,16,0,0,343,344,5,37,0,0,344,345,5,37,0,0,345,347,3,30,15,17,
  	346,287,1,0,0,0,346,290,1,0,0,0,346,293,1,0,0,0,346,296,1,0,0,0,346,299,
  	1,0,0,0,346,302,1,0,0,0,346,305,1,0,0,0,346,308,1,0,0,0,346,311,1,0,0,
  	0,346,314,1,0,0,0,346,318,1,0,0,0,346,322,1,0,0,0,346,325,1,0,0,0,346,
  	329,1,0,0,0,346,332,1,0,0,0,346,335,1,0,0,0,346,338,1,0,0,0,346,342,1,
  	0,0,0,347,350,1,0,0,0,348,346,1,0,0,0,348,349,1,0,0,0,349,31,1,0,0,0,
  	350,348,1,0,0,0,351,352,3,34,17,0,352,33,1,0,0,0,353,358,5,43,0,0,354,
  	355,5,39,0,0,355,357,5,43,0,0,356,354,1,0,0,0,357,360,1,0,0,0,358,356,
  	1,0,0,0,358,359,1,0,0,0,359,35,1,0,0,0,360,358,1,0,0,0,361,364,3,42,21,
  	0,362,364,3,40,20,0,363,361,1,0,0,0,363,362,1,0,0,0,364,37,1,0,0,0,365,
  	366,5,54,0,0,366,39,1,0,0,0,367,368,5,48,0,0,368,369,6,20,-1,0,369,41,
  	1,0,0,0,370,371,5,45,0,0,371,379,6,21,-1,0,372,373,5,44,0,0,373,379,6,
  	21,-1,0,374,375,5,47,0,0,375,379,6,21,-1,0,376,377,5,46,0,0,377,379,6,
  	21,-1,0,378,370,1,0,0,0,378,372,1,0,0,0,378,374,1,0,0,0,378,376,1,0,0,
  	0,379,43,1,0,0,0,380,381,5,16,0,0,381,382,5,17,0,0,382,383,3,30,15,0,
  	383,384,5,18,0,0,384,45,1,0,0,0,23,49,53,57,60,77,81,103,115,119,128,
  	134,143,152,158,162,166,193,285,346,348,358,363,378
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  riddleparserParserStaticData = staticData.release();
}

}

RiddleParser::RiddleParser(TokenStream *input) : RiddleParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

RiddleParser::RiddleParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  RiddleParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *riddleparserParserStaticData->atn, riddleparserParserStaticData->decisionToDFA, riddleparserParserStaticData->sharedContextCache, options);
}

RiddleParser::~RiddleParser() {
  delete _interpreter;
}

const atn::ATN& RiddleParser::getATN() const {
  return *riddleparserParserStaticData->atn;
}

std::string RiddleParser::getGrammarFileName() const {
  return "RiddleParser.g4";
}

const std::vector<std::string>& RiddleParser::getRuleNames() const {
  return riddleparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& RiddleParser::getVocabulary() const {
  return riddleparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView RiddleParser::getSerializedATN() const {
  return riddleparserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

RiddleParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RiddleParser::Statement_edContext *> RiddleParser::ProgramContext::statement_ed() {
  return getRuleContexts<RiddleParser::Statement_edContext>();
}

RiddleParser::Statement_edContext* RiddleParser::ProgramContext::statement_ed(size_t i) {
  return getRuleContext<RiddleParser::Statement_edContext>(i);
}

tree::TerminalNode* RiddleParser::ProgramContext::EOF() {
  return getToken(RiddleParser::EOF, 0);
}


size_t RiddleParser::ProgramContext::getRuleIndex() const {
  return RiddleParser::RuleProgram;
}

void RiddleParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void RiddleParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any RiddleParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ProgramContext* RiddleParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, RiddleParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(53);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(49);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 18568589951567802) != 0)) {
        setState(46);
        statement_ed();
        setState(51);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(52);
      match(RiddleParser::EOF);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_edContext ------------------------------------------------------------------

RiddleParser::Statement_edContext::Statement_edContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RiddleParser::StatementContext* RiddleParser::Statement_edContext::statement() {
  return getRuleContext<RiddleParser::StatementContext>(0);
}

tree::TerminalNode* RiddleParser::Statement_edContext::Semi() {
  return getToken(RiddleParser::Semi, 0);
}

tree::TerminalNode* RiddleParser::Statement_edContext::Endl() {
  return getToken(RiddleParser::Endl, 0);
}


size_t RiddleParser::Statement_edContext::getRuleIndex() const {
  return RiddleParser::RuleStatement_ed;
}

void RiddleParser::Statement_edContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement_ed(this);
}

void RiddleParser::Statement_edContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement_ed(this);
}


std::any RiddleParser::Statement_edContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitStatement_ed(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::Statement_edContext* RiddleParser::statement_ed() {
  Statement_edContext *_localctx = _tracker.createInstance<Statement_edContext>(_ctx, getState());
  enterRule(_localctx, 2, RiddleParser::RuleStatement_ed);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    statement();
    setState(57);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(56);
      match(RiddleParser::Semi);
      break;
    }

    default:
      break;
    }
    setState(60);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(59);
      match(RiddleParser::Endl);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

RiddleParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RiddleParser::PrintContext* RiddleParser::StatementContext::print() {
  return getRuleContext<RiddleParser::PrintContext>(0);
}

RiddleParser::PackStatementContext* RiddleParser::StatementContext::packStatement() {
  return getRuleContext<RiddleParser::PackStatementContext>(0);
}

RiddleParser::ImportStatementContext* RiddleParser::StatementContext::importStatement() {
  return getRuleContext<RiddleParser::ImportStatementContext>(0);
}

RiddleParser::FuncDefineContext* RiddleParser::StatementContext::funcDefine() {
  return getRuleContext<RiddleParser::FuncDefineContext>(0);
}

RiddleParser::FuncExprContext* RiddleParser::StatementContext::funcExpr() {
  return getRuleContext<RiddleParser::FuncExprContext>(0);
}

RiddleParser::VarDefineStatementContext* RiddleParser::StatementContext::varDefineStatement() {
  return getRuleContext<RiddleParser::VarDefineStatementContext>(0);
}

RiddleParser::ForStatementContext* RiddleParser::StatementContext::forStatement() {
  return getRuleContext<RiddleParser::ForStatementContext>(0);
}

RiddleParser::WhileStatementContext* RiddleParser::StatementContext::whileStatement() {
  return getRuleContext<RiddleParser::WhileStatementContext>(0);
}

RiddleParser::IfStatementContext* RiddleParser::StatementContext::ifStatement() {
  return getRuleContext<RiddleParser::IfStatementContext>(0);
}

RiddleParser::ReturnStatementContext* RiddleParser::StatementContext::returnStatement() {
  return getRuleContext<RiddleParser::ReturnStatementContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::StatementContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

tree::TerminalNode* RiddleParser::StatementContext::LeftCurly() {
  return getToken(RiddleParser::LeftCurly, 0);
}

tree::TerminalNode* RiddleParser::StatementContext::RightCurly() {
  return getToken(RiddleParser::RightCurly, 0);
}

std::vector<RiddleParser::Statement_edContext *> RiddleParser::StatementContext::statement_ed() {
  return getRuleContexts<RiddleParser::Statement_edContext>();
}

RiddleParser::Statement_edContext* RiddleParser::StatementContext::statement_ed(size_t i) {
  return getRuleContext<RiddleParser::Statement_edContext>(i);
}


size_t RiddleParser::StatementContext::getRuleIndex() const {
  return RiddleParser::RuleStatement;
}

void RiddleParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void RiddleParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any RiddleParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::StatementContext* RiddleParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, RiddleParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(81);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(62);
      print();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(63);
      packStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(64);
      importStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(65);
      funcDefine();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(66);
      funcExpr();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(67);
      varDefineStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(68);
      forStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(69);
      whileStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(70);
      ifStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(71);
      returnStatement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(72);
      expression(0);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(73);
      match(RiddleParser::LeftCurly);
      setState(77);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 18568589951567802) != 0)) {
        setState(74);
        statement_ed();
        setState(79);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(80);
      match(RiddleParser::RightCurly);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PackStatementContext ------------------------------------------------------------------

RiddleParser::PackStatementContext::PackStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::PackStatementContext::Package() {
  return getToken(RiddleParser::Package, 0);
}

RiddleParser::IdContext* RiddleParser::PackStatementContext::id() {
  return getRuleContext<RiddleParser::IdContext>(0);
}


size_t RiddleParser::PackStatementContext::getRuleIndex() const {
  return RiddleParser::RulePackStatement;
}

void RiddleParser::PackStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPackStatement(this);
}

void RiddleParser::PackStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPackStatement(this);
}


std::any RiddleParser::PackStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitPackStatement(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::PackStatementContext* RiddleParser::packStatement() {
  PackStatementContext *_localctx = _tracker.createInstance<PackStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, RiddleParser::RulePackStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(RiddleParser::Package);
    setState(84);
    antlrcpp::downCast<PackStatementContext *>(_localctx)->packName = id();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportStatementContext ------------------------------------------------------------------

RiddleParser::ImportStatementContext::ImportStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::ImportStatementContext::Import() {
  return getToken(RiddleParser::Import, 0);
}

RiddleParser::IdContext* RiddleParser::ImportStatementContext::id() {
  return getRuleContext<RiddleParser::IdContext>(0);
}


size_t RiddleParser::ImportStatementContext::getRuleIndex() const {
  return RiddleParser::RuleImportStatement;
}

void RiddleParser::ImportStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportStatement(this);
}

void RiddleParser::ImportStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportStatement(this);
}


std::any RiddleParser::ImportStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitImportStatement(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ImportStatementContext* RiddleParser::importStatement() {
  ImportStatementContext *_localctx = _tracker.createInstance<ImportStatementContext>(_ctx, getState());
  enterRule(_localctx, 8, RiddleParser::RuleImportStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(86);
    match(RiddleParser::Import);
    setState(87);
    antlrcpp::downCast<ImportStatementContext *>(_localctx)->libName = id();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefineStatementContext ------------------------------------------------------------------

RiddleParser::VarDefineStatementContext::VarDefineStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::VarDefineStatementContext::Var() {
  return getToken(RiddleParser::Var, 0);
}

tree::TerminalNode* RiddleParser::VarDefineStatementContext::Colon() {
  return getToken(RiddleParser::Colon, 0);
}

std::vector<tree::TerminalNode *> RiddleParser::VarDefineStatementContext::Identifier() {
  return getTokens(RiddleParser::Identifier);
}

tree::TerminalNode* RiddleParser::VarDefineStatementContext::Identifier(size_t i) {
  return getToken(RiddleParser::Identifier, i);
}

tree::TerminalNode* RiddleParser::VarDefineStatementContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ExpressionContext* RiddleParser::VarDefineStatementContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}


size_t RiddleParser::VarDefineStatementContext::getRuleIndex() const {
  return RiddleParser::RuleVarDefineStatement;
}

void RiddleParser::VarDefineStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefineStatement(this);
}

void RiddleParser::VarDefineStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefineStatement(this);
}


std::any RiddleParser::VarDefineStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitVarDefineStatement(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::VarDefineStatementContext* RiddleParser::varDefineStatement() {
  VarDefineStatementContext *_localctx = _tracker.createInstance<VarDefineStatementContext>(_ctx, getState());
  enterRule(_localctx, 10, RiddleParser::RuleVarDefineStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(103);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(89);
      match(RiddleParser::Var);
      setState(90);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->name = match(RiddleParser::Identifier);
      setState(91);
      match(RiddleParser::Colon);
      setState(92);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->type = match(RiddleParser::Identifier);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(93);
      match(RiddleParser::Var);
      setState(94);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->name = match(RiddleParser::Identifier);
      setState(95);
      match(RiddleParser::Assign);
      setState(96);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->value = expression(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(97);
      match(RiddleParser::Var);
      setState(98);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->name = match(RiddleParser::Identifier);
      setState(99);
      match(RiddleParser::Colon);
      setState(100);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->type = match(RiddleParser::Identifier);
      setState(101);
      match(RiddleParser::Assign);
      setState(102);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->value = expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncExprContext ------------------------------------------------------------------

RiddleParser::FuncExprContext::FuncExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::FuncExprContext::LeftBracket() {
  return getToken(RiddleParser::LeftBracket, 0);
}

tree::TerminalNode* RiddleParser::FuncExprContext::RightBracket() {
  return getToken(RiddleParser::RightBracket, 0);
}

RiddleParser::IdContext* RiddleParser::FuncExprContext::id() {
  return getRuleContext<RiddleParser::IdContext>(0);
}

RiddleParser::ArgsExprContext* RiddleParser::FuncExprContext::argsExpr() {
  return getRuleContext<RiddleParser::ArgsExprContext>(0);
}


size_t RiddleParser::FuncExprContext::getRuleIndex() const {
  return RiddleParser::RuleFuncExpr;
}

void RiddleParser::FuncExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncExpr(this);
}

void RiddleParser::FuncExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncExpr(this);
}


std::any RiddleParser::FuncExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitFuncExpr(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::FuncExprContext* RiddleParser::funcExpr() {
  FuncExprContext *_localctx = _tracker.createInstance<FuncExprContext>(_ctx, getState());
  enterRule(_localctx, 12, RiddleParser::RuleFuncExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    antlrcpp::downCast<FuncExprContext *>(_localctx)->funcName = id();
    setState(106);
    match(RiddleParser::LeftBracket);
    setState(107);
    antlrcpp::downCast<FuncExprContext *>(_localctx)->arge = argsExpr();
    setState(108);
    match(RiddleParser::RightBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsExprContext ------------------------------------------------------------------

RiddleParser::ArgsExprContext::ArgsExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::ArgsExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::ArgsExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> RiddleParser::ArgsExprContext::Comma() {
  return getTokens(RiddleParser::Comma);
}

tree::TerminalNode* RiddleParser::ArgsExprContext::Comma(size_t i) {
  return getToken(RiddleParser::Comma, i);
}


size_t RiddleParser::ArgsExprContext::getRuleIndex() const {
  return RiddleParser::RuleArgsExpr;
}

void RiddleParser::ArgsExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgsExpr(this);
}

void RiddleParser::ArgsExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgsExpr(this);
}


std::any RiddleParser::ArgsExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitArgsExpr(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ArgsExprContext* RiddleParser::argsExpr() {
  ArgsExprContext *_localctx = _tracker.createInstance<ArgsExprContext>(_ctx, getState());
  enterRule(_localctx, 14, RiddleParser::RuleArgsExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(119);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 18568589950976000) != 0)) {
      setState(115);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(110);
          expression(0);
          setState(111);
          match(RiddleParser::Comma); 
        }
        setState(117);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      }
      setState(118);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefineArgsContext ------------------------------------------------------------------

RiddleParser::DefineArgsContext::DefineArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> RiddleParser::DefineArgsContext::Identifier() {
  return getTokens(RiddleParser::Identifier);
}

tree::TerminalNode* RiddleParser::DefineArgsContext::Identifier(size_t i) {
  return getToken(RiddleParser::Identifier, i);
}

std::vector<tree::TerminalNode *> RiddleParser::DefineArgsContext::Colon() {
  return getTokens(RiddleParser::Colon);
}

tree::TerminalNode* RiddleParser::DefineArgsContext::Colon(size_t i) {
  return getToken(RiddleParser::Colon, i);
}

std::vector<RiddleParser::IdContext *> RiddleParser::DefineArgsContext::id() {
  return getRuleContexts<RiddleParser::IdContext>();
}

RiddleParser::IdContext* RiddleParser::DefineArgsContext::id(size_t i) {
  return getRuleContext<RiddleParser::IdContext>(i);
}

std::vector<tree::TerminalNode *> RiddleParser::DefineArgsContext::Comma() {
  return getTokens(RiddleParser::Comma);
}

tree::TerminalNode* RiddleParser::DefineArgsContext::Comma(size_t i) {
  return getToken(RiddleParser::Comma, i);
}


size_t RiddleParser::DefineArgsContext::getRuleIndex() const {
  return RiddleParser::RuleDefineArgs;
}

void RiddleParser::DefineArgsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefineArgs(this);
}

void RiddleParser::DefineArgsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefineArgs(this);
}


std::any RiddleParser::DefineArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitDefineArgs(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::DefineArgsContext* RiddleParser::defineArgs() {
  DefineArgsContext *_localctx = _tracker.createInstance<DefineArgsContext>(_ctx, getState());
  enterRule(_localctx, 16, RiddleParser::RuleDefineArgs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(134);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Identifier) {
      setState(128);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(121);
          match(RiddleParser::Identifier);
          setState(122);
          match(RiddleParser::Colon);
          setState(123);
          id();
          setState(124);
          match(RiddleParser::Comma); 
        }
        setState(130);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }

      setState(131);
      match(RiddleParser::Identifier);
      setState(132);
      match(RiddleParser::Colon);
      setState(133);
      id();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefineContext ------------------------------------------------------------------

RiddleParser::FuncDefineContext::FuncDefineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::FuncDefineContext::Func() {
  return getToken(RiddleParser::Func, 0);
}

tree::TerminalNode* RiddleParser::FuncDefineContext::LeftBracket() {
  return getToken(RiddleParser::LeftBracket, 0);
}

tree::TerminalNode* RiddleParser::FuncDefineContext::RightBracket() {
  return getToken(RiddleParser::RightBracket, 0);
}

tree::TerminalNode* RiddleParser::FuncDefineContext::LeftCurly() {
  return getToken(RiddleParser::LeftCurly, 0);
}

tree::TerminalNode* RiddleParser::FuncDefineContext::RightCurly() {
  return getToken(RiddleParser::RightCurly, 0);
}

tree::TerminalNode* RiddleParser::FuncDefineContext::Identifier() {
  return getToken(RiddleParser::Identifier, 0);
}

RiddleParser::DefineArgsContext* RiddleParser::FuncDefineContext::defineArgs() {
  return getRuleContext<RiddleParser::DefineArgsContext>(0);
}

RiddleParser::FuncBodyContext* RiddleParser::FuncDefineContext::funcBody() {
  return getRuleContext<RiddleParser::FuncBodyContext>(0);
}

tree::TerminalNode* RiddleParser::FuncDefineContext::Colon() {
  return getToken(RiddleParser::Colon, 0);
}

RiddleParser::IdContext* RiddleParser::FuncDefineContext::id() {
  return getRuleContext<RiddleParser::IdContext>(0);
}


size_t RiddleParser::FuncDefineContext::getRuleIndex() const {
  return RiddleParser::RuleFuncDefine;
}

void RiddleParser::FuncDefineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDefine(this);
}

void RiddleParser::FuncDefineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDefine(this);
}


std::any RiddleParser::FuncDefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitFuncDefine(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::FuncDefineContext* RiddleParser::funcDefine() {
  FuncDefineContext *_localctx = _tracker.createInstance<FuncDefineContext>(_ctx, getState());
  enterRule(_localctx, 18, RiddleParser::RuleFuncDefine);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(RiddleParser::Func);
    setState(137);
    antlrcpp::downCast<FuncDefineContext *>(_localctx)->funcName = match(RiddleParser::Identifier);
    setState(138);
    match(RiddleParser::LeftBracket);
    setState(139);
    antlrcpp::downCast<FuncDefineContext *>(_localctx)->args = defineArgs();
    setState(140);
    match(RiddleParser::RightBracket);
    setState(143);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Colon) {
      setState(141);
      match(RiddleParser::Colon);
      setState(142);
      antlrcpp::downCast<FuncDefineContext *>(_localctx)->returnType = id();
    }
    setState(145);
    match(RiddleParser::LeftCurly);
    setState(146);
    antlrcpp::downCast<FuncDefineContext *>(_localctx)->body = funcBody();
    setState(147);
    match(RiddleParser::RightCurly);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncBodyContext ------------------------------------------------------------------

RiddleParser::FuncBodyContext::FuncBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RiddleParser::Statement_edContext *> RiddleParser::FuncBodyContext::statement_ed() {
  return getRuleContexts<RiddleParser::Statement_edContext>();
}

RiddleParser::Statement_edContext* RiddleParser::FuncBodyContext::statement_ed(size_t i) {
  return getRuleContext<RiddleParser::Statement_edContext>(i);
}


size_t RiddleParser::FuncBodyContext::getRuleIndex() const {
  return RiddleParser::RuleFuncBody;
}

void RiddleParser::FuncBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncBody(this);
}

void RiddleParser::FuncBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncBody(this);
}


std::any RiddleParser::FuncBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitFuncBody(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::FuncBodyContext* RiddleParser::funcBody() {
  FuncBodyContext *_localctx = _tracker.createInstance<FuncBodyContext>(_ctx, getState());
  enterRule(_localctx, 20, RiddleParser::RuleFuncBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 18568589951567802) != 0)) {
      setState(149);
      statement_ed();
      setState(154);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

RiddleParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::ForStatementContext::For() {
  return getToken(RiddleParser::For, 0);
}

tree::TerminalNode* RiddleParser::ForStatementContext::LeftBracket() {
  return getToken(RiddleParser::LeftBracket, 0);
}

std::vector<tree::TerminalNode *> RiddleParser::ForStatementContext::Semi() {
  return getTokens(RiddleParser::Semi);
}

tree::TerminalNode* RiddleParser::ForStatementContext::Semi(size_t i) {
  return getToken(RiddleParser::Semi, i);
}

tree::TerminalNode* RiddleParser::ForStatementContext::RightBracket() {
  return getToken(RiddleParser::RightBracket, 0);
}

RiddleParser::Statement_edContext* RiddleParser::ForStatementContext::statement_ed() {
  return getRuleContext<RiddleParser::Statement_edContext>(0);
}

RiddleParser::VarDefineStatementContext* RiddleParser::ForStatementContext::varDefineStatement() {
  return getRuleContext<RiddleParser::VarDefineStatementContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::ForStatementContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::StatementContext* RiddleParser::ForStatementContext::statement() {
  return getRuleContext<RiddleParser::StatementContext>(0);
}


size_t RiddleParser::ForStatementContext::getRuleIndex() const {
  return RiddleParser::RuleForStatement;
}

void RiddleParser::ForStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStatement(this);
}

void RiddleParser::ForStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStatement(this);
}


std::any RiddleParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ForStatementContext* RiddleParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 22, RiddleParser::RuleForStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(RiddleParser::For);
    setState(156);
    match(RiddleParser::LeftBracket);
    setState(158);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Var) {
      setState(157);
      antlrcpp::downCast<ForStatementContext *>(_localctx)->init = varDefineStatement();
    }
    setState(160);
    match(RiddleParser::Semi);
    setState(162);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 18568589950976000) != 0)) {
      setState(161);
      antlrcpp::downCast<ForStatementContext *>(_localctx)->termCond = expression(0);
    }
    setState(164);
    match(RiddleParser::Semi);
    setState(166);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 18568589951567802) != 0)) {
      setState(165);
      antlrcpp::downCast<ForStatementContext *>(_localctx)->selfVar = statement();
    }
    setState(168);
    match(RiddleParser::RightBracket);
    setState(169);
    antlrcpp::downCast<ForStatementContext *>(_localctx)->body = statement_ed();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

RiddleParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::WhileStatementContext::While() {
  return getToken(RiddleParser::While, 0);
}

tree::TerminalNode* RiddleParser::WhileStatementContext::LeftBracket() {
  return getToken(RiddleParser::LeftBracket, 0);
}

tree::TerminalNode* RiddleParser::WhileStatementContext::RightBracket() {
  return getToken(RiddleParser::RightBracket, 0);
}

RiddleParser::ExpressionContext* RiddleParser::WhileStatementContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::Statement_edContext* RiddleParser::WhileStatementContext::statement_ed() {
  return getRuleContext<RiddleParser::Statement_edContext>(0);
}


size_t RiddleParser::WhileStatementContext::getRuleIndex() const {
  return RiddleParser::RuleWhileStatement;
}

void RiddleParser::WhileStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStatement(this);
}

void RiddleParser::WhileStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStatement(this);
}


std::any RiddleParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::WhileStatementContext* RiddleParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 24, RiddleParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(RiddleParser::While);
    setState(172);
    match(RiddleParser::LeftBracket);
    setState(173);
    antlrcpp::downCast<WhileStatementContext *>(_localctx)->runCond = expression(0);
    setState(174);
    match(RiddleParser::RightBracket);
    setState(175);
    antlrcpp::downCast<WhileStatementContext *>(_localctx)->body = statement_ed();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

RiddleParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::IfStatementContext::If() {
  return getToken(RiddleParser::If, 0);
}

tree::TerminalNode* RiddleParser::IfStatementContext::LeftBracket() {
  return getToken(RiddleParser::LeftBracket, 0);
}

tree::TerminalNode* RiddleParser::IfStatementContext::RightBracket() {
  return getToken(RiddleParser::RightBracket, 0);
}

RiddleParser::ExpressionContext* RiddleParser::IfStatementContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

std::vector<RiddleParser::Statement_edContext *> RiddleParser::IfStatementContext::statement_ed() {
  return getRuleContexts<RiddleParser::Statement_edContext>();
}

RiddleParser::Statement_edContext* RiddleParser::IfStatementContext::statement_ed(size_t i) {
  return getRuleContext<RiddleParser::Statement_edContext>(i);
}

tree::TerminalNode* RiddleParser::IfStatementContext::Else() {
  return getToken(RiddleParser::Else, 0);
}


size_t RiddleParser::IfStatementContext::getRuleIndex() const {
  return RiddleParser::RuleIfStatement;
}

void RiddleParser::IfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStatement(this);
}

void RiddleParser::IfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStatement(this);
}


std::any RiddleParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::IfStatementContext* RiddleParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, RiddleParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(193);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(177);
      match(RiddleParser::If);
      setState(178);
      match(RiddleParser::LeftBracket);
      setState(179);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->cond = expression(0);
      setState(180);
      match(RiddleParser::RightBracket);
      setState(181);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->body = statement_ed();
      antlrcpp::downCast<IfStatementContext *>(_localctx)->hasElse = false;
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(184);
      match(RiddleParser::If);
      setState(185);
      match(RiddleParser::LeftBracket);
      setState(186);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->cond = expression(0);
      setState(187);
      match(RiddleParser::RightBracket);
      setState(188);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->body = statement_ed();
      setState(189);
      match(RiddleParser::Else);
      setState(190);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->elseBody = statement_ed();
      antlrcpp::downCast<IfStatementContext *>(_localctx)->hasElse = true;
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

RiddleParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::ReturnStatementContext::Return() {
  return getToken(RiddleParser::Return, 0);
}

RiddleParser::Statement_edContext* RiddleParser::ReturnStatementContext::statement_ed() {
  return getRuleContext<RiddleParser::Statement_edContext>(0);
}


size_t RiddleParser::ReturnStatementContext::getRuleIndex() const {
  return RiddleParser::RuleReturnStatement;
}

void RiddleParser::ReturnStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStatement(this);
}

void RiddleParser::ReturnStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStatement(this);
}


std::any RiddleParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ReturnStatementContext* RiddleParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, RiddleParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    match(RiddleParser::Return);
    setState(196);
    antlrcpp::downCast<ReturnStatementContext *>(_localctx)->result = statement_ed();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

RiddleParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RiddleParser::ExpressionContext::getRuleIndex() const {
  return RiddleParser::RuleExpression;
}

void RiddleParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SelfSubRightExprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> RiddleParser::SelfSubRightExprContext::Sub() {
  return getTokens(RiddleParser::Sub);
}

tree::TerminalNode* RiddleParser::SelfSubRightExprContext::Sub(size_t i) {
  return getToken(RiddleParser::Sub, i);
}

RiddleParser::ObjectExprContext* RiddleParser::SelfSubRightExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::SelfSubRightExprContext::SelfSubRightExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::SelfSubRightExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelfSubRightExpr(this);
}
void RiddleParser::SelfSubRightExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelfSubRightExpr(this);
}

std::any RiddleParser::SelfSubRightExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitSelfSubRightExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::AndAssignExprContext::And() {
  return getToken(RiddleParser::And, 0);
}

tree::TerminalNode* RiddleParser::AndAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ObjectExprContext* RiddleParser::AndAssignExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::AndAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::AndAssignExprContext::AndAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::AndAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndAssignExpr(this);
}
void RiddleParser::AndAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndAssignExpr(this);
}

std::any RiddleParser::AndAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitAndAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StarExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::StarExprContext::Star() {
  return getToken(RiddleParser::Star, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::StarExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::StarExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::StarExprContext::StarExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::StarExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStarExpr(this);
}
void RiddleParser::StarExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStarExpr(this);
}

std::any RiddleParser::StarExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitStarExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ModExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::ModExprContext::Mod() {
  return getToken(RiddleParser::Mod, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::ModExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::ModExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::ModExprContext::ModExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::ModExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModExpr(this);
}
void RiddleParser::ModExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModExpr(this);
}

std::any RiddleParser::ModExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitModExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegativeExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::NegativeExprContext::Sub() {
  return getToken(RiddleParser::Sub, 0);
}

RiddleParser::ExpressionContext* RiddleParser::NegativeExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::NegativeExprContext::NegativeExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::NegativeExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegativeExpr(this);
}
void RiddleParser::NegativeExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegativeExpr(this);
}

std::any RiddleParser::NegativeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitNegativeExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberExprContext ------------------------------------------------------------------

RiddleParser::NumberContext* RiddleParser::NumberExprContext::number() {
  return getRuleContext<RiddleParser::NumberContext>(0);
}

RiddleParser::NumberExprContext::NumberExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::NumberExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberExpr(this);
}
void RiddleParser::NumberExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberExpr(this);
}

std::any RiddleParser::NumberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitNumberExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ObjValExprContext ------------------------------------------------------------------

RiddleParser::IdContext* RiddleParser::ObjValExprContext::id() {
  return getRuleContext<RiddleParser::IdContext>(0);
}

RiddleParser::ObjValExprContext::ObjValExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::ObjValExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjValExpr(this);
}
void RiddleParser::ObjValExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjValExpr(this);
}

std::any RiddleParser::ObjValExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitObjValExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- XorAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::XorAssignExprContext::Xor() {
  return getToken(RiddleParser::Xor, 0);
}

tree::TerminalNode* RiddleParser::XorAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ObjectExprContext* RiddleParser::XorAssignExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::XorAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::XorAssignExprContext::XorAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::XorAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXorAssignExpr(this);
}
void RiddleParser::XorAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXorAssignExpr(this);
}

std::any RiddleParser::XorAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitXorAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::SubExprContext::Sub() {
  return getToken(RiddleParser::Sub, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::SubExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::SubExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::SubExprContext::SubExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::SubExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubExpr(this);
}
void RiddleParser::SubExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubExpr(this);
}

std::any RiddleParser::SubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitSubExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GreaterEqualExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::GreaterEqualExprContext::Greater() {
  return getToken(RiddleParser::Greater, 0);
}

tree::TerminalNode* RiddleParser::GreaterEqualExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::GreaterEqualExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::GreaterEqualExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::GreaterEqualExprContext::GreaterEqualExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::GreaterEqualExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGreaterEqualExpr(this);
}
void RiddleParser::GreaterEqualExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGreaterEqualExpr(this);
}

std::any RiddleParser::GreaterEqualExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitGreaterEqualExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::AddAssignExprContext::Add() {
  return getToken(RiddleParser::Add, 0);
}

tree::TerminalNode* RiddleParser::AddAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ObjectExprContext* RiddleParser::AddAssignExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::AddAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::AddAssignExprContext::AddAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::AddAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddAssignExpr(this);
}
void RiddleParser::AddAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddAssignExpr(this);
}

std::any RiddleParser::AddAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitAddAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::OrAssignExprContext::Or() {
  return getToken(RiddleParser::Or, 0);
}

tree::TerminalNode* RiddleParser::OrAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ObjectExprContext* RiddleParser::OrAssignExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::OrAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::OrAssignExprContext::OrAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::OrAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrAssignExpr(this);
}
void RiddleParser::OrAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrAssignExpr(this);
}

std::any RiddleParser::OrAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitOrAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitXorExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::BitXorExprContext::Xor() {
  return getToken(RiddleParser::Xor, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::BitXorExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::BitXorExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::BitXorExprContext::BitXorExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::BitXorExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitXorExpr(this);
}
void RiddleParser::BitXorExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitXorExpr(this);
}

std::any RiddleParser::BitXorExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitBitXorExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringExprContext ------------------------------------------------------------------

RiddleParser::StringContext* RiddleParser::StringExprContext::string() {
  return getRuleContext<RiddleParser::StringContext>(0);
}

RiddleParser::StringExprContext::StringExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::StringExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringExpr(this);
}
void RiddleParser::StringExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringExpr(this);
}

std::any RiddleParser::StringExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitStringExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GreaterExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::GreaterExprContext::Greater() {
  return getToken(RiddleParser::Greater, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::GreaterExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::GreaterExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::GreaterExprContext::GreaterExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::GreaterExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGreaterExpr(this);
}
void RiddleParser::GreaterExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGreaterExpr(this);
}

std::any RiddleParser::GreaterExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitGreaterExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DivAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::DivAssignExprContext::Div() {
  return getToken(RiddleParser::Div, 0);
}

tree::TerminalNode* RiddleParser::DivAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ObjectExprContext* RiddleParser::DivAssignExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::DivAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::DivAssignExprContext::DivAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::DivAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDivAssignExpr(this);
}
void RiddleParser::DivAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDivAssignExpr(this);
}

std::any RiddleParser::DivAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitDivAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotEqualExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::NotEqualExprContext::Not() {
  return getToken(RiddleParser::Not, 0);
}

tree::TerminalNode* RiddleParser::NotEqualExprContext::Equal() {
  return getToken(RiddleParser::Equal, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::NotEqualExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::NotEqualExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::NotEqualExprContext::NotEqualExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::NotEqualExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotEqualExpr(this);
}
void RiddleParser::NotEqualExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotEqualExpr(this);
}

std::any RiddleParser::NotEqualExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitNotEqualExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SelfSubLeftExprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> RiddleParser::SelfSubLeftExprContext::Sub() {
  return getTokens(RiddleParser::Sub);
}

tree::TerminalNode* RiddleParser::SelfSubLeftExprContext::Sub(size_t i) {
  return getToken(RiddleParser::Sub, i);
}

RiddleParser::ObjectExprContext* RiddleParser::SelfSubLeftExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::SelfSubLeftExprContext::SelfSubLeftExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::SelfSubLeftExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelfSubLeftExpr(this);
}
void RiddleParser::SelfSubLeftExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelfSubLeftExpr(this);
}

std::any RiddleParser::SelfSubLeftExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitSelfSubLeftExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DivExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::DivExprContext::Div() {
  return getToken(RiddleParser::Div, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::DivExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::DivExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::DivExprContext::DivExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::DivExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDivExpr(this);
}
void RiddleParser::DivExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDivExpr(this);
}

std::any RiddleParser::DivExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitDivExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitAndExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::BitAndExprContext::And() {
  return getToken(RiddleParser::And, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::BitAndExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::BitAndExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::BitAndExprContext::BitAndExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::BitAndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitAndExpr(this);
}
void RiddleParser::BitAndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitAndExpr(this);
}

std::any RiddleParser::BitAndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitBitAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::AssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ObjectExprContext* RiddleParser::AssignExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::AssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::AssignExprContext::AssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::AssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignExpr(this);
}
void RiddleParser::AssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignExpr(this);
}

std::any RiddleParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SelfAddRightExprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> RiddleParser::SelfAddRightExprContext::Add() {
  return getTokens(RiddleParser::Add);
}

tree::TerminalNode* RiddleParser::SelfAddRightExprContext::Add(size_t i) {
  return getToken(RiddleParser::Add, i);
}

RiddleParser::ObjectExprContext* RiddleParser::SelfAddRightExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::SelfAddRightExprContext::SelfAddRightExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::SelfAddRightExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelfAddRightExpr(this);
}
void RiddleParser::SelfAddRightExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelfAddRightExpr(this);
}

std::any RiddleParser::SelfAddRightExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitSelfAddRightExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::SubAssignExprContext::Sub() {
  return getToken(RiddleParser::Sub, 0);
}

tree::TerminalNode* RiddleParser::SubAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ObjectExprContext* RiddleParser::SubAssignExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::SubAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::SubAssignExprContext::SubAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::SubAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubAssignExpr(this);
}
void RiddleParser::SubAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubAssignExpr(this);
}

std::any RiddleParser::SubAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitSubAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StarAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::StarAssignExprContext::Star() {
  return getToken(RiddleParser::Star, 0);
}

tree::TerminalNode* RiddleParser::StarAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ObjectExprContext* RiddleParser::StarAssignExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::StarAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::StarAssignExprContext::StarAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::StarAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStarAssignExpr(this);
}
void RiddleParser::StarAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStarAssignExpr(this);
}

std::any RiddleParser::StarAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitStarAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BracketExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::BracketExprContext::LeftBracket() {
  return getToken(RiddleParser::LeftBracket, 0);
}

tree::TerminalNode* RiddleParser::BracketExprContext::RightBracket() {
  return getToken(RiddleParser::RightBracket, 0);
}

RiddleParser::ExpressionContext* RiddleParser::BracketExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::BracketExprContext::BracketExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::BracketExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBracketExpr(this);
}
void RiddleParser::BracketExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBracketExpr(this);
}

std::any RiddleParser::BracketExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitBracketExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LessExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::LessExprContext::Less() {
  return getToken(RiddleParser::Less, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::LessExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::LessExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::LessExprContext::LessExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::LessExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLessExpr(this);
}
void RiddleParser::LessExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLessExpr(this);
}

std::any RiddleParser::LessExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitLessExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> RiddleParser::OrExprContext::Or() {
  return getTokens(RiddleParser::Or);
}

tree::TerminalNode* RiddleParser::OrExprContext::Or(size_t i) {
  return getToken(RiddleParser::Or, i);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::OrExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::OrExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::OrExprContext::OrExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}
void RiddleParser::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}

std::any RiddleParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LeftLeftAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::LeftLeftAssignExprContext::LeftLeft() {
  return getToken(RiddleParser::LeftLeft, 0);
}

tree::TerminalNode* RiddleParser::LeftLeftAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ObjectExprContext* RiddleParser::LeftLeftAssignExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::LeftLeftAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::LeftLeftAssignExprContext::LeftLeftAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::LeftLeftAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeftLeftAssignExpr(this);
}
void RiddleParser::LeftLeftAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeftLeftAssignExpr(this);
}

std::any RiddleParser::LeftLeftAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitLeftLeftAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RightRightAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::RightRightAssignExprContext::RightRight() {
  return getToken(RiddleParser::RightRight, 0);
}

tree::TerminalNode* RiddleParser::RightRightAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ObjectExprContext* RiddleParser::RightRightAssignExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::RightRightAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::RightRightAssignExprContext::RightRightAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::RightRightAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRightRightAssignExpr(this);
}
void RiddleParser::RightRightAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRightRightAssignExpr(this);
}

std::any RiddleParser::RightRightAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitRightRightAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SelfAddLeftExprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> RiddleParser::SelfAddLeftExprContext::Add() {
  return getTokens(RiddleParser::Add);
}

tree::TerminalNode* RiddleParser::SelfAddLeftExprContext::Add(size_t i) {
  return getToken(RiddleParser::Add, i);
}

RiddleParser::ObjectExprContext* RiddleParser::SelfAddLeftExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::SelfAddLeftExprContext::SelfAddLeftExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::SelfAddLeftExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelfAddLeftExpr(this);
}
void RiddleParser::SelfAddLeftExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelfAddLeftExpr(this);
}

std::any RiddleParser::SelfAddLeftExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitSelfAddLeftExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LessEqualExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::LessEqualExprContext::Less() {
  return getToken(RiddleParser::Less, 0);
}

tree::TerminalNode* RiddleParser::LessEqualExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::LessEqualExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::LessEqualExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::LessEqualExprContext::LessEqualExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::LessEqualExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLessEqualExpr(this);
}
void RiddleParser::LessEqualExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLessEqualExpr(this);
}

std::any RiddleParser::LessEqualExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitLessEqualExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LeftLeftExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::LeftLeftExprContext::LeftLeft() {
  return getToken(RiddleParser::LeftLeft, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::LeftLeftExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::LeftLeftExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::LeftLeftExprContext::LeftLeftExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::LeftLeftExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeftLeftExpr(this);
}
void RiddleParser::LeftLeftExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeftLeftExpr(this);
}

std::any RiddleParser::LeftLeftExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitLeftLeftExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitOrExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::BitOrExprContext::Or() {
  return getToken(RiddleParser::Or, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::BitOrExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::BitOrExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::BitOrExprContext::BitOrExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::BitOrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitOrExpr(this);
}
void RiddleParser::BitOrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitOrExpr(this);
}

std::any RiddleParser::BitOrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitBitOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::NotExprContext::Not() {
  return getToken(RiddleParser::Not, 0);
}

RiddleParser::ExpressionContext* RiddleParser::NotExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::NotExprContext::NotExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::NotExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotExpr(this);
}
void RiddleParser::NotExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotExpr(this);
}

std::any RiddleParser::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::AddExprContext::Add() {
  return getToken(RiddleParser::Add, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::AddExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::AddExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::AddExprContext::AddExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::AddExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpr(this);
}
void RiddleParser::AddExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpr(this);
}

std::any RiddleParser::AddExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitAddExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ModAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::ModAssignExprContext::Mod() {
  return getToken(RiddleParser::Mod, 0);
}

tree::TerminalNode* RiddleParser::ModAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ObjectExprContext* RiddleParser::ModAssignExprContext::objectExpr() {
  return getRuleContext<RiddleParser::ObjectExprContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::ModAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::ModAssignExprContext::ModAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::ModAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModAssignExpr(this);
}
void RiddleParser::ModAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModAssignExpr(this);
}

std::any RiddleParser::ModAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitModAssignExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PositiveExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::PositiveExprContext::Add() {
  return getToken(RiddleParser::Add, 0);
}

RiddleParser::ExpressionContext* RiddleParser::PositiveExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::PositiveExprContext::PositiveExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::PositiveExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPositiveExpr(this);
}
void RiddleParser::PositiveExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPositiveExpr(this);
}

std::any RiddleParser::PositiveExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitPositiveExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RightRightExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::RightRightExprContext::RightRight() {
  return getToken(RiddleParser::RightRight, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::RightRightExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::RightRightExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::RightRightExprContext::RightRightExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::RightRightExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRightRightExpr(this);
}
void RiddleParser::RightRightExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRightRightExpr(this);
}

std::any RiddleParser::RightRightExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitRightRightExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::EqualExprContext::Equal() {
  return getToken(RiddleParser::Equal, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::EqualExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::EqualExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::EqualExprContext::EqualExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::EqualExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualExpr(this);
}
void RiddleParser::EqualExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualExpr(this);
}

std::any RiddleParser::EqualExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitEqualExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndExprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> RiddleParser::AndExprContext::And() {
  return getTokens(RiddleParser::And);
}

tree::TerminalNode* RiddleParser::AndExprContext::And(size_t i) {
  return getToken(RiddleParser::And, i);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::AndExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::AndExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::AndExprContext::AndExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}
void RiddleParser::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}

std::any RiddleParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ExpressionContext* RiddleParser::expression() {
   return expression(0);
}

RiddleParser::ExpressionContext* RiddleParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  RiddleParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  RiddleParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, RiddleParser::RuleExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(285);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<BracketExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(199);
      match(RiddleParser::LeftBracket);
      setState(200);
      antlrcpp::downCast<BracketExprContext *>(_localctx)->expr = expression(0);
      setState(201);
      match(RiddleParser::RightBracket);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(203);
      match(RiddleParser::Not);
      setState(204);
      antlrcpp::downCast<NotExprContext *>(_localctx)->expr = expression(40);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<PositiveExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(205);
      match(RiddleParser::Add);
      setState(206);
      antlrcpp::downCast<PositiveExprContext *>(_localctx)->expr = expression(39);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<NegativeExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(207);
      match(RiddleParser::Sub);
      setState(208);
      antlrcpp::downCast<NegativeExprContext *>(_localctx)->expr = expression(38);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<SelfAddLeftExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(209);
      match(RiddleParser::Add);
      setState(210);
      match(RiddleParser::Add);
      setState(211);
      antlrcpp::downCast<SelfAddLeftExprContext *>(_localctx)->expr = objectExpr();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<SelfAddRightExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(212);
      antlrcpp::downCast<SelfAddRightExprContext *>(_localctx)->expr = objectExpr();
      setState(213);
      match(RiddleParser::Add);
      setState(214);
      match(RiddleParser::Add);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<SelfSubLeftExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(216);
      match(RiddleParser::Sub);
      setState(217);
      match(RiddleParser::Sub);
      setState(218);
      antlrcpp::downCast<SelfSubLeftExprContext *>(_localctx)->expr = objectExpr();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<SelfSubRightExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(219);
      antlrcpp::downCast<SelfSubRightExprContext *>(_localctx)->expr = objectExpr();
      setState(220);
      match(RiddleParser::Sub);
      setState(221);
      match(RiddleParser::Sub);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<AssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(223);
      antlrcpp::downCast<AssignExprContext *>(_localctx)->left = objectExpr();
      setState(224);
      match(RiddleParser::Assign);
      setState(225);
      antlrcpp::downCast<AssignExprContext *>(_localctx)->right = expression(15);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<AddAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(227);
      antlrcpp::downCast<AddAssignExprContext *>(_localctx)->left = objectExpr();
      setState(228);
      match(RiddleParser::Add);
      setState(229);
      match(RiddleParser::Assign);
      setState(230);
      antlrcpp::downCast<AddAssignExprContext *>(_localctx)->right = expression(14);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<SubAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(232);
      antlrcpp::downCast<SubAssignExprContext *>(_localctx)->left = objectExpr();
      setState(233);
      match(RiddleParser::Sub);
      setState(234);
      match(RiddleParser::Assign);
      setState(235);
      antlrcpp::downCast<SubAssignExprContext *>(_localctx)->right = expression(13);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<StarAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(237);
      antlrcpp::downCast<StarAssignExprContext *>(_localctx)->left = objectExpr();
      setState(238);
      match(RiddleParser::Star);
      setState(239);
      match(RiddleParser::Assign);
      setState(240);
      antlrcpp::downCast<StarAssignExprContext *>(_localctx)->right = expression(12);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<DivAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(242);
      antlrcpp::downCast<DivAssignExprContext *>(_localctx)->left = objectExpr();
      setState(243);
      match(RiddleParser::Div);
      setState(244);
      match(RiddleParser::Assign);
      setState(245);
      antlrcpp::downCast<DivAssignExprContext *>(_localctx)->right = expression(11);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<ModAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(247);
      antlrcpp::downCast<ModAssignExprContext *>(_localctx)->left = objectExpr();
      setState(248);
      match(RiddleParser::Mod);
      setState(249);
      match(RiddleParser::Assign);
      setState(250);
      antlrcpp::downCast<ModAssignExprContext *>(_localctx)->right = expression(10);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<AddAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(252);
      antlrcpp::downCast<AddAssignExprContext *>(_localctx)->left = objectExpr();
      setState(253);
      match(RiddleParser::Add);
      setState(254);
      match(RiddleParser::Assign);
      setState(255);
      antlrcpp::downCast<AddAssignExprContext *>(_localctx)->right = expression(9);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<AndAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(257);
      antlrcpp::downCast<AndAssignExprContext *>(_localctx)->left = objectExpr();
      setState(258);
      match(RiddleParser::And);
      setState(259);
      match(RiddleParser::Assign);
      setState(260);
      antlrcpp::downCast<AndAssignExprContext *>(_localctx)->right = expression(8);
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<OrAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(262);
      antlrcpp::downCast<OrAssignExprContext *>(_localctx)->left = objectExpr();
      setState(263);
      match(RiddleParser::Or);
      setState(264);
      match(RiddleParser::Assign);
      setState(265);
      antlrcpp::downCast<OrAssignExprContext *>(_localctx)->right = expression(7);
      break;
    }

    case 18: {
      _localctx = _tracker.createInstance<XorAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(267);
      antlrcpp::downCast<XorAssignExprContext *>(_localctx)->left = objectExpr();
      setState(268);
      match(RiddleParser::Xor);
      setState(269);
      match(RiddleParser::Assign);
      setState(270);
      antlrcpp::downCast<XorAssignExprContext *>(_localctx)->right = expression(6);
      break;
    }

    case 19: {
      _localctx = _tracker.createInstance<LeftLeftAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(272);
      antlrcpp::downCast<LeftLeftAssignExprContext *>(_localctx)->left = objectExpr();
      setState(273);
      match(RiddleParser::LeftLeft);
      setState(274);
      match(RiddleParser::Assign);
      setState(275);
      antlrcpp::downCast<LeftLeftAssignExprContext *>(_localctx)->right = expression(5);
      break;
    }

    case 20: {
      _localctx = _tracker.createInstance<RightRightAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(277);
      antlrcpp::downCast<RightRightAssignExprContext *>(_localctx)->left = objectExpr();
      setState(278);
      match(RiddleParser::RightRight);
      setState(279);
      match(RiddleParser::Assign);
      setState(280);
      antlrcpp::downCast<RightRightAssignExprContext *>(_localctx)->right = expression(4);
      break;
    }

    case 21: {
      _localctx = _tracker.createInstance<StringExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(282);
      string();
      break;
    }

    case 22: {
      _localctx = _tracker.createInstance<NumberExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(283);
      number();
      break;
    }

    case 23: {
      _localctx = _tracker.createInstance<ObjValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(284);
      id();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(348);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(346);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<StarExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(287);

          if (!(precpred(_ctx, 33))) throw FailedPredicateException(this, "precpred(_ctx, 33)");
          setState(288);
          match(RiddleParser::Star);
          setState(289);
          antlrcpp::downCast<StarExprContext *>(_localctx)->right = expression(34);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DivExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(290);

          if (!(precpred(_ctx, 32))) throw FailedPredicateException(this, "precpred(_ctx, 32)");
          setState(291);
          match(RiddleParser::Div);
          setState(292);
          antlrcpp::downCast<DivExprContext *>(_localctx)->right = expression(33);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ModExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(293);

          if (!(precpred(_ctx, 31))) throw FailedPredicateException(this, "precpred(_ctx, 31)");
          setState(294);
          match(RiddleParser::Mod);
          setState(295);
          antlrcpp::downCast<ModExprContext *>(_localctx)->right = expression(32);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AddExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(296);

          if (!(precpred(_ctx, 30))) throw FailedPredicateException(this, "precpred(_ctx, 30)");
          setState(297);
          match(RiddleParser::Add);
          setState(298);
          antlrcpp::downCast<AddExprContext *>(_localctx)->right = expression(31);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<SubExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(299);

          if (!(precpred(_ctx, 29))) throw FailedPredicateException(this, "precpred(_ctx, 29)");
          setState(300);
          match(RiddleParser::Sub);
          setState(301);
          antlrcpp::downCast<SubExprContext *>(_localctx)->right = expression(30);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<LeftLeftExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(302);

          if (!(precpred(_ctx, 28))) throw FailedPredicateException(this, "precpred(_ctx, 28)");
          setState(303);
          match(RiddleParser::LeftLeft);
          setState(304);
          antlrcpp::downCast<LeftLeftExprContext *>(_localctx)->right = expression(29);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<RightRightExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(305);

          if (!(precpred(_ctx, 27))) throw FailedPredicateException(this, "precpred(_ctx, 27)");
          setState(306);
          match(RiddleParser::RightRight);
          setState(307);
          antlrcpp::downCast<RightRightExprContext *>(_localctx)->right = expression(28);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<GreaterExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(308);

          if (!(precpred(_ctx, 26))) throw FailedPredicateException(this, "precpred(_ctx, 26)");
          setState(309);
          match(RiddleParser::Greater);
          setState(310);
          antlrcpp::downCast<GreaterExprContext *>(_localctx)->right = expression(27);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<LessExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(311);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(312);
          match(RiddleParser::Less);
          setState(313);
          antlrcpp::downCast<LessExprContext *>(_localctx)->right = expression(26);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<GreaterEqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(314);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(315);
          match(RiddleParser::Greater);
          setState(316);
          match(RiddleParser::Assign);
          setState(317);
          antlrcpp::downCast<GreaterEqualExprContext *>(_localctx)->right = expression(25);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<LessEqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(318);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(319);
          match(RiddleParser::Less);
          setState(320);
          match(RiddleParser::Assign);
          setState(321);
          antlrcpp::downCast<LessEqualExprContext *>(_localctx)->right = expression(24);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<EqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(322);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(323);
          match(RiddleParser::Equal);
          setState(324);
          antlrcpp::downCast<EqualExprContext *>(_localctx)->right = expression(23);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<NotEqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(325);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(326);
          match(RiddleParser::Not);
          setState(327);
          match(RiddleParser::Equal);
          setState(328);
          antlrcpp::downCast<NotEqualExprContext *>(_localctx)->right = expression(22);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<BitAndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(329);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(330);
          match(RiddleParser::And);
          setState(331);
          antlrcpp::downCast<BitAndExprContext *>(_localctx)->right = expression(21);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<BitXorExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(332);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(333);
          match(RiddleParser::Xor);
          setState(334);
          antlrcpp::downCast<BitXorExprContext *>(_localctx)->right = expression(20);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<BitOrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(335);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(336);
          match(RiddleParser::Or);
          setState(337);
          antlrcpp::downCast<BitOrExprContext *>(_localctx)->right = expression(19);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(338);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(339);
          match(RiddleParser::And);
          setState(340);
          match(RiddleParser::And);
          setState(341);
          antlrcpp::downCast<AndExprContext *>(_localctx)->right = expression(18);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(342);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(343);
          match(RiddleParser::Or);
          setState(344);
          match(RiddleParser::Or);
          setState(345);
          antlrcpp::downCast<OrExprContext *>(_localctx)->right = expression(17);
          break;
        }

        default:
          break;
        } 
      }
      setState(350);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ObjectExprContext ------------------------------------------------------------------

RiddleParser::ObjectExprContext::ObjectExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RiddleParser::IdContext* RiddleParser::ObjectExprContext::id() {
  return getRuleContext<RiddleParser::IdContext>(0);
}


size_t RiddleParser::ObjectExprContext::getRuleIndex() const {
  return RiddleParser::RuleObjectExpr;
}

void RiddleParser::ObjectExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjectExpr(this);
}

void RiddleParser::ObjectExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjectExpr(this);
}


std::any RiddleParser::ObjectExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitObjectExpr(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ObjectExprContext* RiddleParser::objectExpr() {
  ObjectExprContext *_localctx = _tracker.createInstance<ObjectExprContext>(_ctx, getState());
  enterRule(_localctx, 32, RiddleParser::RuleObjectExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    id();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdContext ------------------------------------------------------------------

RiddleParser::IdContext::IdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> RiddleParser::IdContext::Identifier() {
  return getTokens(RiddleParser::Identifier);
}

tree::TerminalNode* RiddleParser::IdContext::Identifier(size_t i) {
  return getToken(RiddleParser::Identifier, i);
}

std::vector<tree::TerminalNode *> RiddleParser::IdContext::Dot() {
  return getTokens(RiddleParser::Dot);
}

tree::TerminalNode* RiddleParser::IdContext::Dot(size_t i) {
  return getToken(RiddleParser::Dot, i);
}


size_t RiddleParser::IdContext::getRuleIndex() const {
  return RiddleParser::RuleId;
}

void RiddleParser::IdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId(this);
}

void RiddleParser::IdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId(this);
}


std::any RiddleParser::IdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitId(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::IdContext* RiddleParser::id() {
  IdContext *_localctx = _tracker.createInstance<IdContext>(_ctx, getState());
  enterRule(_localctx, 34, RiddleParser::RuleId);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(353);
    match(RiddleParser::Identifier);
    setState(358);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(354);
        match(RiddleParser::Dot);
        setState(355);
        match(RiddleParser::Identifier); 
      }
      setState(360);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

RiddleParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RiddleParser::IntegerContext* RiddleParser::NumberContext::integer() {
  return getRuleContext<RiddleParser::IntegerContext>(0);
}

RiddleParser::FloatContext* RiddleParser::NumberContext::float_() {
  return getRuleContext<RiddleParser::FloatContext>(0);
}


size_t RiddleParser::NumberContext::getRuleIndex() const {
  return RiddleParser::RuleNumber;
}

void RiddleParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void RiddleParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


std::any RiddleParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::NumberContext* RiddleParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 36, RiddleParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(363);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RiddleParser::Hexadecimal:
      case RiddleParser::Decimal:
      case RiddleParser::Octal:
      case RiddleParser::Binary: {
        enterOuterAlt(_localctx, 1);
        setState(361);
        integer();
        break;
      }

      case RiddleParser::Float: {
        enterOuterAlt(_localctx, 2);
        setState(362);
        float_();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

RiddleParser::StringContext::StringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::StringContext::STRING() {
  return getToken(RiddleParser::STRING, 0);
}


size_t RiddleParser::StringContext::getRuleIndex() const {
  return RiddleParser::RuleString;
}

void RiddleParser::StringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString(this);
}

void RiddleParser::StringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString(this);
}


std::any RiddleParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::StringContext* RiddleParser::string() {
  StringContext *_localctx = _tracker.createInstance<StringContext>(_ctx, getState());
  enterRule(_localctx, 38, RiddleParser::RuleString);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365);
    match(RiddleParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FloatContext ------------------------------------------------------------------

RiddleParser::FloatContext::FloatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::FloatContext::Float() {
  return getToken(RiddleParser::Float, 0);
}


size_t RiddleParser::FloatContext::getRuleIndex() const {
  return RiddleParser::RuleFloat;
}

void RiddleParser::FloatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloat(this);
}

void RiddleParser::FloatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloat(this);
}


std::any RiddleParser::FloatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitFloat(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::FloatContext* RiddleParser::float_() {
  FloatContext *_localctx = _tracker.createInstance<FloatContext>(_ctx, getState());
  enterRule(_localctx, 40, RiddleParser::RuleFloat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    antlrcpp::downCast<FloatContext *>(_localctx)->floatToken = match(RiddleParser::Float);

            antlrcpp::downCast<FloatContext *>(_localctx)->value =  stod((antlrcpp::downCast<FloatContext *>(_localctx)->floatToken != nullptr ? antlrcpp::downCast<FloatContext *>(_localctx)->floatToken->getText() : ""));
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerContext ------------------------------------------------------------------

RiddleParser::IntegerContext::IntegerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::IntegerContext::Decimal() {
  return getToken(RiddleParser::Decimal, 0);
}

tree::TerminalNode* RiddleParser::IntegerContext::Hexadecimal() {
  return getToken(RiddleParser::Hexadecimal, 0);
}

tree::TerminalNode* RiddleParser::IntegerContext::Binary() {
  return getToken(RiddleParser::Binary, 0);
}

tree::TerminalNode* RiddleParser::IntegerContext::Octal() {
  return getToken(RiddleParser::Octal, 0);
}


size_t RiddleParser::IntegerContext::getRuleIndex() const {
  return RiddleParser::RuleInteger;
}

void RiddleParser::IntegerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger(this);
}

void RiddleParser::IntegerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger(this);
}


std::any RiddleParser::IntegerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitInteger(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::IntegerContext* RiddleParser::integer() {
  IntegerContext *_localctx = _tracker.createInstance<IntegerContext>(_ctx, getState());
  enterRule(_localctx, 42, RiddleParser::RuleInteger);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(378);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RiddleParser::Decimal: {
        enterOuterAlt(_localctx, 1);
        setState(370);
        antlrcpp::downCast<IntegerContext *>(_localctx)->decimalToken = match(RiddleParser::Decimal);

                antlrcpp::downCast<IntegerContext *>(_localctx)->value =  stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->decimalToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->decimalToken->getText() : ""));
            
        break;
      }

      case RiddleParser::Hexadecimal: {
        enterOuterAlt(_localctx, 2);
        setState(372);
        antlrcpp::downCast<IntegerContext *>(_localctx)->hexadecimalToken = match(RiddleParser::Hexadecimal);

                antlrcpp::downCast<IntegerContext *>(_localctx)->value =  stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->hexadecimalToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->hexadecimalToken->getText() : "").substr(2),nullptr,16);
            
        break;
      }

      case RiddleParser::Binary: {
        enterOuterAlt(_localctx, 3);
        setState(374);
        antlrcpp::downCast<IntegerContext *>(_localctx)->binaryToken = match(RiddleParser::Binary);

                antlrcpp::downCast<IntegerContext *>(_localctx)->value =  stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->binaryToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->binaryToken->getText() : "").substr(2),nullptr,2);
            
        break;
      }

      case RiddleParser::Octal: {
        enterOuterAlt(_localctx, 4);
        setState(376);
        antlrcpp::downCast<IntegerContext *>(_localctx)->octalToken = match(RiddleParser::Octal);

                antlrcpp::downCast<IntegerContext *>(_localctx)->value =  stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->octalToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->octalToken->getText() : "").substr(2),nullptr,8);
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintContext ------------------------------------------------------------------

RiddleParser::PrintContext::PrintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::PrintContext::Print() {
  return getToken(RiddleParser::Print, 0);
}

tree::TerminalNode* RiddleParser::PrintContext::LeftBracket() {
  return getToken(RiddleParser::LeftBracket, 0);
}

tree::TerminalNode* RiddleParser::PrintContext::RightBracket() {
  return getToken(RiddleParser::RightBracket, 0);
}

RiddleParser::ExpressionContext* RiddleParser::PrintContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}


size_t RiddleParser::PrintContext::getRuleIndex() const {
  return RiddleParser::RulePrint;
}

void RiddleParser::PrintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrint(this);
}

void RiddleParser::PrintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrint(this);
}


std::any RiddleParser::PrintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitPrint(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::PrintContext* RiddleParser::print() {
  PrintContext *_localctx = _tracker.createInstance<PrintContext>(_ctx, getState());
  enterRule(_localctx, 44, RiddleParser::RulePrint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    match(RiddleParser::Print);
    setState(381);
    match(RiddleParser::LeftBracket);
    setState(382);
    antlrcpp::downCast<PrintContext *>(_localctx)->value = expression(0);
    setState(383);
    match(RiddleParser::RightBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool RiddleParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 15: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool RiddleParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 33);
    case 1: return precpred(_ctx, 32);
    case 2: return precpred(_ctx, 31);
    case 3: return precpred(_ctx, 30);
    case 4: return precpred(_ctx, 29);
    case 5: return precpred(_ctx, 28);
    case 6: return precpred(_ctx, 27);
    case 7: return precpred(_ctx, 26);
    case 8: return precpred(_ctx, 25);
    case 9: return precpred(_ctx, 24);
    case 10: return precpred(_ctx, 23);
    case 11: return precpred(_ctx, 22);
    case 12: return precpred(_ctx, 21);
    case 13: return precpred(_ctx, 20);
    case 14: return precpred(_ctx, 19);
    case 15: return precpred(_ctx, 18);
    case 16: return precpred(_ctx, 17);
    case 17: return precpred(_ctx, 16);

  default:
    break;
  }
  return true;
}

void RiddleParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  riddleparserParserInitialize();
#else
  ::antlr4::internal::call_once(riddleparserParserOnceFlag, riddleparserParserInitialize);
#endif
}
