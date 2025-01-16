
// Generated from D:/Code/Riddle-Language-cpp/RiddleParser.g4 by ANTLR 4.13.2


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
std::unique_ptr<RiddleParserStaticData> riddleparserParserStaticData = nullptr;

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
      "program", "null_cnt", "statement_ed", "statement", "bodyExpr", "packStatement", 
      "importStatement", "varDefineStatement", "argsExpr", "defineArgs", 
      "funcDefine", "forStatement", "whileStatement", "continueStatement", 
      "breakStatement", "ifStatement", "returnStatement", "classDefine", 
      "tryExpr", "catchExpr", "exprPtr", "exprPtrParser", "expression", 
      "id", "modifier", "modifierList", "number", "boolean", "string", "float", 
      "integer", "templateArg", "templateArgs", "typeName"
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
  	4,1,69,504,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,1,0,5,0,70,8,0,10,
  	0,12,0,73,9,0,1,0,3,0,76,8,0,1,1,1,1,1,2,1,2,3,2,82,8,2,1,2,3,2,85,8,
  	2,1,2,1,2,3,2,89,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,3,3,105,8,3,1,4,1,4,5,4,109,8,4,10,4,12,4,112,9,4,1,4,1,4,1,5,
  	1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,3,7,137,8,7,1,8,1,8,1,8,5,8,142,8,8,10,8,12,8,145,9,8,1,8,3,
  	8,148,8,8,1,9,1,9,1,9,1,9,1,9,5,9,155,8,9,10,9,12,9,158,9,9,1,9,1,9,1,
  	9,3,9,163,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,174,8,
  	10,1,10,1,10,1,11,1,11,1,11,3,11,181,8,11,1,11,1,11,3,11,185,8,11,1,11,
  	1,11,3,11,189,8,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,13,
  	1,13,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,3,15,220,8,15,1,16,1,16,3,16,224,8,16,1,17,1,
  	17,1,17,1,17,3,17,230,8,17,1,17,1,17,1,18,1,18,1,18,3,18,237,8,18,1,18,
  	1,18,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,3,20,
  	253,8,20,1,20,1,20,1,20,5,20,258,8,20,10,20,12,20,261,9,20,1,21,1,21,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,3,22,366,8,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,5,22,430,
  	8,22,10,22,12,22,433,9,22,1,23,1,23,1,24,1,24,1,25,5,25,440,8,25,10,25,
  	12,25,443,9,25,1,26,1,26,3,26,447,8,26,1,27,1,27,1,27,1,27,3,27,453,8,
  	27,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,3,
  	30,468,8,30,1,31,1,31,3,31,472,8,31,1,32,1,32,1,32,5,32,477,8,32,10,32,
  	12,32,480,9,32,1,32,3,32,483,8,32,1,33,1,33,1,33,1,33,1,33,1,33,1,33,
  	3,33,492,8,33,1,33,1,33,1,33,1,33,1,33,5,33,499,8,33,10,33,12,33,502,
  	9,33,1,33,0,3,40,44,66,34,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,0,2,2,0,33,33,54,
  	54,1,0,22,24,561,0,75,1,0,0,0,2,77,1,0,0,0,4,88,1,0,0,0,6,104,1,0,0,0,
  	8,106,1,0,0,0,10,115,1,0,0,0,12,118,1,0,0,0,14,136,1,0,0,0,16,147,1,0,
  	0,0,18,162,1,0,0,0,20,164,1,0,0,0,22,177,1,0,0,0,24,193,1,0,0,0,26,199,
  	1,0,0,0,28,201,1,0,0,0,30,219,1,0,0,0,32,221,1,0,0,0,34,225,1,0,0,0,36,
  	233,1,0,0,0,38,240,1,0,0,0,40,252,1,0,0,0,42,262,1,0,0,0,44,365,1,0,0,
  	0,46,434,1,0,0,0,48,436,1,0,0,0,50,441,1,0,0,0,52,446,1,0,0,0,54,452,
  	1,0,0,0,56,454,1,0,0,0,58,456,1,0,0,0,60,467,1,0,0,0,62,471,1,0,0,0,64,
  	482,1,0,0,0,66,491,1,0,0,0,68,70,3,4,2,0,69,68,1,0,0,0,70,73,1,0,0,0,
  	71,69,1,0,0,0,71,72,1,0,0,0,72,76,1,0,0,0,73,71,1,0,0,0,74,76,5,0,0,1,
  	75,71,1,0,0,0,75,74,1,0,0,0,76,1,1,0,0,0,77,78,7,0,0,0,78,3,1,0,0,0,79,
  	81,3,6,3,0,80,82,5,33,0,0,81,80,1,0,0,0,81,82,1,0,0,0,82,84,1,0,0,0,83,
  	85,5,54,0,0,84,83,1,0,0,0,84,85,1,0,0,0,85,89,1,0,0,0,86,89,5,33,0,0,
  	87,89,5,54,0,0,88,79,1,0,0,0,88,86,1,0,0,0,88,87,1,0,0,0,89,5,1,0,0,0,
  	90,105,3,10,5,0,91,105,3,12,6,0,92,105,3,34,17,0,93,105,3,20,10,0,94,
  	105,3,14,7,0,95,105,3,22,11,0,96,105,3,24,12,0,97,105,3,30,15,0,98,105,
  	3,32,16,0,99,105,3,26,13,0,100,105,3,28,14,0,101,105,3,36,18,0,102,105,
  	3,44,22,0,103,105,3,8,4,0,104,90,1,0,0,0,104,91,1,0,0,0,104,92,1,0,0,
  	0,104,93,1,0,0,0,104,94,1,0,0,0,104,95,1,0,0,0,104,96,1,0,0,0,104,97,
  	1,0,0,0,104,98,1,0,0,0,104,99,1,0,0,0,104,100,1,0,0,0,104,101,1,0,0,0,
  	104,102,1,0,0,0,104,103,1,0,0,0,105,7,1,0,0,0,106,110,5,30,0,0,107,109,
  	3,4,2,0,108,107,1,0,0,0,109,112,1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,
  	0,111,113,1,0,0,0,112,110,1,0,0,0,113,114,5,31,0,0,114,9,1,0,0,0,115,
  	116,5,12,0,0,116,117,3,46,23,0,117,11,1,0,0,0,118,119,5,11,0,0,119,120,
  	3,46,23,0,120,13,1,0,0,0,121,122,5,1,0,0,122,123,5,55,0,0,123,124,5,32,
  	0,0,124,137,3,66,33,0,125,126,5,1,0,0,126,127,5,55,0,0,127,128,5,36,0,
  	0,128,137,3,44,22,0,129,130,5,1,0,0,130,131,5,55,0,0,131,132,5,32,0,0,
  	132,133,3,66,33,0,133,134,5,36,0,0,134,135,3,44,22,0,135,137,1,0,0,0,
  	136,121,1,0,0,0,136,125,1,0,0,0,136,129,1,0,0,0,137,15,1,0,0,0,138,139,
  	3,44,22,0,139,140,5,34,0,0,140,142,1,0,0,0,141,138,1,0,0,0,142,145,1,
  	0,0,0,143,141,1,0,0,0,143,144,1,0,0,0,144,146,1,0,0,0,145,143,1,0,0,0,
  	146,148,3,44,22,0,147,143,1,0,0,0,147,148,1,0,0,0,148,17,1,0,0,0,149,
  	150,5,55,0,0,150,151,5,32,0,0,151,152,3,66,33,0,152,153,5,34,0,0,153,
  	155,1,0,0,0,154,149,1,0,0,0,155,158,1,0,0,0,156,154,1,0,0,0,156,157,1,
  	0,0,0,157,159,1,0,0,0,158,156,1,0,0,0,159,160,5,55,0,0,160,161,5,32,0,
  	0,161,163,3,66,33,0,162,156,1,0,0,0,162,163,1,0,0,0,163,19,1,0,0,0,164,
  	165,3,50,25,0,165,166,5,9,0,0,166,167,5,55,0,0,167,168,5,26,0,0,168,169,
  	3,18,9,0,169,173,5,27,0,0,170,171,5,43,0,0,171,172,5,37,0,0,172,174,3,
  	66,33,0,173,170,1,0,0,0,173,174,1,0,0,0,174,175,1,0,0,0,175,176,3,8,4,
  	0,176,21,1,0,0,0,177,178,5,3,0,0,178,180,5,26,0,0,179,181,3,6,3,0,180,
  	179,1,0,0,0,180,181,1,0,0,0,181,182,1,0,0,0,182,184,5,33,0,0,183,185,
  	3,6,3,0,184,183,1,0,0,0,184,185,1,0,0,0,185,186,1,0,0,0,186,188,5,33,
  	0,0,187,189,3,6,3,0,188,187,1,0,0,0,188,189,1,0,0,0,189,190,1,0,0,0,190,
  	191,5,27,0,0,191,192,3,4,2,0,192,23,1,0,0,0,193,194,5,4,0,0,194,195,5,
  	26,0,0,195,196,3,44,22,0,196,197,5,27,0,0,197,198,3,4,2,0,198,25,1,0,
  	0,0,199,200,5,5,0,0,200,27,1,0,0,0,201,202,5,6,0,0,202,29,1,0,0,0,203,
  	204,5,7,0,0,204,205,5,26,0,0,205,206,3,44,22,0,206,207,5,27,0,0,207,208,
  	3,4,2,0,208,209,6,15,-1,0,209,220,1,0,0,0,210,211,5,7,0,0,211,212,5,26,
  	0,0,212,213,3,44,22,0,213,214,5,27,0,0,214,215,3,4,2,0,215,216,5,8,0,
  	0,216,217,3,4,2,0,217,218,6,15,-1,0,218,220,1,0,0,0,219,203,1,0,0,0,219,
  	210,1,0,0,0,220,31,1,0,0,0,221,223,5,10,0,0,222,224,3,6,3,0,223,222,1,
  	0,0,0,223,224,1,0,0,0,224,33,1,0,0,0,225,226,5,13,0,0,226,229,3,46,23,
  	0,227,228,5,32,0,0,228,230,3,46,23,0,229,227,1,0,0,0,229,230,1,0,0,0,
  	230,231,1,0,0,0,231,232,3,8,4,0,232,35,1,0,0,0,233,234,5,17,0,0,234,236,
  	3,8,4,0,235,237,3,2,1,0,236,235,1,0,0,0,236,237,1,0,0,0,237,238,1,0,0,
  	0,238,239,3,38,19,0,239,37,1,0,0,0,240,241,5,18,0,0,241,242,5,26,0,0,
  	242,243,3,14,7,0,243,244,5,27,0,0,244,39,1,0,0,0,245,246,6,20,-1,0,246,
  	247,5,55,0,0,247,248,5,26,0,0,248,249,3,16,8,0,249,250,5,27,0,0,250,253,
  	1,0,0,0,251,253,5,55,0,0,252,245,1,0,0,0,252,251,1,0,0,0,253,259,1,0,
  	0,0,254,255,10,1,0,0,255,256,5,51,0,0,256,258,3,40,20,2,257,254,1,0,0,
  	0,258,261,1,0,0,0,259,257,1,0,0,0,259,260,1,0,0,0,260,41,1,0,0,0,261,
  	259,1,0,0,0,262,263,3,40,20,0,263,43,1,0,0,0,264,265,6,22,-1,0,265,266,
  	5,38,0,0,266,267,3,66,33,0,267,268,5,37,0,0,268,269,5,26,0,0,269,270,
  	3,42,21,0,270,271,5,27,0,0,271,366,1,0,0,0,272,273,5,26,0,0,273,274,3,
  	44,22,0,274,275,5,27,0,0,275,366,1,0,0,0,276,277,5,47,0,0,277,366,3,44,
  	22,44,278,279,5,42,0,0,279,366,3,44,22,43,280,281,5,43,0,0,281,366,3,
  	44,22,42,282,283,5,42,0,0,283,284,5,42,0,0,284,366,3,42,21,0,285,286,
  	3,42,21,0,286,287,5,42,0,0,287,288,5,42,0,0,288,366,1,0,0,0,289,290,5,
  	43,0,0,290,291,5,43,0,0,291,366,3,42,21,0,292,293,3,42,21,0,293,294,5,
  	43,0,0,294,295,5,43,0,0,295,366,1,0,0,0,296,366,3,40,20,0,297,298,3,42,
  	21,0,298,299,5,36,0,0,299,300,3,44,22,17,300,366,1,0,0,0,301,302,3,42,
  	21,0,302,303,5,42,0,0,303,304,5,36,0,0,304,305,3,44,22,16,305,366,1,0,
  	0,0,306,307,3,42,21,0,307,308,5,43,0,0,308,309,5,36,0,0,309,310,3,44,
  	22,15,310,366,1,0,0,0,311,312,3,42,21,0,312,313,5,44,0,0,313,314,5,36,
  	0,0,314,315,3,44,22,14,315,366,1,0,0,0,316,317,3,42,21,0,317,318,5,45,
  	0,0,318,319,5,36,0,0,319,320,3,44,22,13,320,366,1,0,0,0,321,322,3,42,
  	21,0,322,323,5,46,0,0,323,324,5,36,0,0,324,325,3,44,22,12,325,366,1,0,
  	0,0,326,327,3,42,21,0,327,328,5,42,0,0,328,329,5,36,0,0,329,330,3,44,
  	22,11,330,366,1,0,0,0,331,332,3,42,21,0,332,333,5,48,0,0,333,334,5,36,
  	0,0,334,335,3,44,22,10,335,366,1,0,0,0,336,337,3,42,21,0,337,338,5,49,
  	0,0,338,339,5,36,0,0,339,340,3,44,22,9,340,366,1,0,0,0,341,342,3,42,21,
  	0,342,343,5,50,0,0,343,344,5,36,0,0,344,345,3,44,22,8,345,366,1,0,0,0,
  	346,347,3,42,21,0,347,348,5,39,0,0,348,349,5,36,0,0,349,350,3,44,22,7,
  	350,366,1,0,0,0,351,352,3,42,21,0,352,353,5,40,0,0,353,354,5,36,0,0,354,
  	355,3,44,22,6,355,366,1,0,0,0,356,357,3,42,21,0,357,358,5,41,0,0,358,
  	359,5,36,0,0,359,360,3,44,22,5,360,366,1,0,0,0,361,366,3,56,28,0,362,
  	366,3,52,26,0,363,366,3,54,27,0,364,366,5,16,0,0,365,264,1,0,0,0,365,
  	272,1,0,0,0,365,276,1,0,0,0,365,278,1,0,0,0,365,280,1,0,0,0,365,282,1,
  	0,0,0,365,285,1,0,0,0,365,289,1,0,0,0,365,292,1,0,0,0,365,296,1,0,0,0,
  	365,297,1,0,0,0,365,301,1,0,0,0,365,306,1,0,0,0,365,311,1,0,0,0,365,316,
  	1,0,0,0,365,321,1,0,0,0,365,326,1,0,0,0,365,331,1,0,0,0,365,336,1,0,0,
  	0,365,341,1,0,0,0,365,346,1,0,0,0,365,351,1,0,0,0,365,356,1,0,0,0,365,
  	361,1,0,0,0,365,362,1,0,0,0,365,363,1,0,0,0,365,364,1,0,0,0,366,431,1,
  	0,0,0,367,368,10,36,0,0,368,369,5,44,0,0,369,430,3,44,22,37,370,371,10,
  	35,0,0,371,372,5,45,0,0,372,430,3,44,22,36,373,374,10,34,0,0,374,375,
  	5,46,0,0,375,430,3,44,22,35,376,377,10,33,0,0,377,378,5,42,0,0,378,430,
  	3,44,22,34,379,380,10,32,0,0,380,381,5,43,0,0,381,430,3,44,22,33,382,
  	383,10,31,0,0,383,384,5,39,0,0,384,430,3,44,22,32,385,386,10,30,0,0,386,
  	387,5,40,0,0,387,430,3,44,22,31,388,389,10,29,0,0,389,390,5,41,0,0,390,
  	430,3,44,22,30,391,392,10,28,0,0,392,393,5,37,0,0,393,430,3,44,22,29,
  	394,395,10,27,0,0,395,396,5,38,0,0,396,430,3,44,22,28,397,398,10,26,0,
  	0,398,399,5,37,0,0,399,400,5,36,0,0,400,430,3,44,22,27,401,402,10,25,
  	0,0,402,403,5,38,0,0,403,404,5,36,0,0,404,430,3,44,22,26,405,406,10,24,
  	0,0,406,407,5,35,0,0,407,430,3,44,22,25,408,409,10,23,0,0,409,410,5,47,
  	0,0,410,411,5,36,0,0,411,430,3,44,22,24,412,413,10,22,0,0,413,414,5,48,
  	0,0,414,430,3,44,22,23,415,416,10,21,0,0,416,417,5,50,0,0,417,430,3,44,
  	22,22,418,419,10,20,0,0,419,420,5,49,0,0,420,430,3,44,22,21,421,422,10,
  	19,0,0,422,423,5,48,0,0,423,424,5,48,0,0,424,430,3,44,22,20,425,426,10,
  	18,0,0,426,427,5,49,0,0,427,428,5,49,0,0,428,430,3,44,22,19,429,367,1,
  	0,0,0,429,370,1,0,0,0,429,373,1,0,0,0,429,376,1,0,0,0,429,379,1,0,0,0,
  	429,382,1,0,0,0,429,385,1,0,0,0,429,388,1,0,0,0,429,391,1,0,0,0,429,394,
  	1,0,0,0,429,397,1,0,0,0,429,401,1,0,0,0,429,405,1,0,0,0,429,408,1,0,0,
  	0,429,412,1,0,0,0,429,415,1,0,0,0,429,418,1,0,0,0,429,421,1,0,0,0,429,
  	425,1,0,0,0,430,433,1,0,0,0,431,429,1,0,0,0,431,432,1,0,0,0,432,45,1,
  	0,0,0,433,431,1,0,0,0,434,435,5,55,0,0,435,47,1,0,0,0,436,437,7,1,0,0,
  	437,49,1,0,0,0,438,440,3,48,24,0,439,438,1,0,0,0,440,443,1,0,0,0,441,
  	439,1,0,0,0,441,442,1,0,0,0,442,51,1,0,0,0,443,441,1,0,0,0,444,447,3,
  	60,30,0,445,447,3,58,29,0,446,444,1,0,0,0,446,445,1,0,0,0,447,53,1,0,
  	0,0,448,449,5,14,0,0,449,453,6,27,-1,0,450,451,5,15,0,0,451,453,6,27,
  	-1,0,452,448,1,0,0,0,452,450,1,0,0,0,453,55,1,0,0,0,454,455,5,66,0,0,
  	455,57,1,0,0,0,456,457,5,60,0,0,457,458,6,29,-1,0,458,59,1,0,0,0,459,
  	460,5,57,0,0,460,468,6,30,-1,0,461,462,5,56,0,0,462,468,6,30,-1,0,463,
  	464,5,59,0,0,464,468,6,30,-1,0,465,466,5,58,0,0,466,468,6,30,-1,0,467,
  	459,1,0,0,0,467,461,1,0,0,0,467,463,1,0,0,0,467,465,1,0,0,0,468,61,1,
  	0,0,0,469,472,3,44,22,0,470,472,3,66,33,0,471,469,1,0,0,0,471,470,1,0,
  	0,0,472,63,1,0,0,0,473,474,3,62,31,0,474,475,5,34,0,0,475,477,1,0,0,0,
  	476,473,1,0,0,0,477,480,1,0,0,0,478,476,1,0,0,0,478,479,1,0,0,0,479,481,
  	1,0,0,0,480,478,1,0,0,0,481,483,3,62,31,0,482,478,1,0,0,0,482,483,1,0,
  	0,0,483,65,1,0,0,0,484,485,6,33,-1,0,485,492,3,46,23,0,486,487,3,46,23,
  	0,487,488,5,38,0,0,488,489,3,64,32,0,489,490,5,37,0,0,490,492,1,0,0,0,
  	491,484,1,0,0,0,491,486,1,0,0,0,492,500,1,0,0,0,493,494,10,1,0,0,494,
  	495,5,28,0,0,495,496,3,44,22,0,496,497,5,29,0,0,497,499,1,0,0,0,498,493,
  	1,0,0,0,499,502,1,0,0,0,500,498,1,0,0,0,500,501,1,0,0,0,501,67,1,0,0,
  	0,502,500,1,0,0,0,34,71,75,81,84,88,104,110,136,143,147,156,162,173,180,
  	184,188,219,223,229,236,252,259,365,429,431,441,446,452,467,471,478,482,
  	491,500
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  riddleparserParserStaticData = std::move(staticData);
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
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 2287982826970414842) != 0) || _la == RiddleParser::STRING) {
        setState(68);
        statement_ed();
        setState(73);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(74);
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

//----------------- Null_cntContext ------------------------------------------------------------------

RiddleParser::Null_cntContext::Null_cntContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::Null_cntContext::Semi() {
  return getToken(RiddleParser::Semi, 0);
}

tree::TerminalNode* RiddleParser::Null_cntContext::Endl() {
  return getToken(RiddleParser::Endl, 0);
}


size_t RiddleParser::Null_cntContext::getRuleIndex() const {
  return RiddleParser::RuleNull_cnt;
}

void RiddleParser::Null_cntContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNull_cnt(this);
}

void RiddleParser::Null_cntContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNull_cnt(this);
}


std::any RiddleParser::Null_cntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitNull_cnt(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::Null_cntContext* RiddleParser::null_cnt() {
  Null_cntContext *_localctx = _tracker.createInstance<Null_cntContext>(_ctx, getState());
  enterRule(_localctx, 2, RiddleParser::RuleNull_cnt);
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
    setState(77);
    _la = _input->LA(1);
    if (!(_la == RiddleParser::Semi

    || _la == RiddleParser::Endl)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
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
  enterRule(_localctx, 4, RiddleParser::RuleStatement_ed);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(88);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RiddleParser::Var:
      case RiddleParser::For:
      case RiddleParser::While:
      case RiddleParser::Continue:
      case RiddleParser::Break:
      case RiddleParser::If:
      case RiddleParser::Func:
      case RiddleParser::Return:
      case RiddleParser::Import:
      case RiddleParser::Package:
      case RiddleParser::Class:
      case RiddleParser::True:
      case RiddleParser::False:
      case RiddleParser::Null:
      case RiddleParser::Try:
      case RiddleParser::Public:
      case RiddleParser::Protected:
      case RiddleParser::Private:
      case RiddleParser::LeftBracket:
      case RiddleParser::LeftCurly:
      case RiddleParser::Less:
      case RiddleParser::Add:
      case RiddleParser::Sub:
      case RiddleParser::Not:
      case RiddleParser::Identifier:
      case RiddleParser::Hexadecimal:
      case RiddleParser::Decimal:
      case RiddleParser::Octal:
      case RiddleParser::Binary:
      case RiddleParser::Float:
      case RiddleParser::STRING: {
        enterOuterAlt(_localctx, 1);
        setState(79);
        statement();
        setState(81);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          setState(80);
          match(RiddleParser::Semi);
          break;
        }

        default:
          break;
        }
        setState(84);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          setState(83);
          match(RiddleParser::Endl);
          break;
        }

        default:
          break;
        }
        break;
      }

      case RiddleParser::Semi: {
        enterOuterAlt(_localctx, 2);
        setState(86);
        match(RiddleParser::Semi);
        break;
      }

      case RiddleParser::Endl: {
        enterOuterAlt(_localctx, 3);
        setState(87);
        match(RiddleParser::Endl);
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

//----------------- StatementContext ------------------------------------------------------------------

RiddleParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RiddleParser::PackStatementContext* RiddleParser::StatementContext::packStatement() {
  return getRuleContext<RiddleParser::PackStatementContext>(0);
}

RiddleParser::ImportStatementContext* RiddleParser::StatementContext::importStatement() {
  return getRuleContext<RiddleParser::ImportStatementContext>(0);
}

RiddleParser::ClassDefineContext* RiddleParser::StatementContext::classDefine() {
  return getRuleContext<RiddleParser::ClassDefineContext>(0);
}

RiddleParser::FuncDefineContext* RiddleParser::StatementContext::funcDefine() {
  return getRuleContext<RiddleParser::FuncDefineContext>(0);
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

RiddleParser::ContinueStatementContext* RiddleParser::StatementContext::continueStatement() {
  return getRuleContext<RiddleParser::ContinueStatementContext>(0);
}

RiddleParser::BreakStatementContext* RiddleParser::StatementContext::breakStatement() {
  return getRuleContext<RiddleParser::BreakStatementContext>(0);
}

RiddleParser::TryExprContext* RiddleParser::StatementContext::tryExpr() {
  return getRuleContext<RiddleParser::TryExprContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::StatementContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::BodyExprContext* RiddleParser::StatementContext::bodyExpr() {
  return getRuleContext<RiddleParser::BodyExprContext>(0);
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
  enterRule(_localctx, 6, RiddleParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(104);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RiddleParser::Package: {
        enterOuterAlt(_localctx, 1);
        setState(90);
        packStatement();
        break;
      }

      case RiddleParser::Import: {
        enterOuterAlt(_localctx, 2);
        setState(91);
        importStatement();
        break;
      }

      case RiddleParser::Class: {
        enterOuterAlt(_localctx, 3);
        setState(92);
        classDefine();
        break;
      }

      case RiddleParser::Func:
      case RiddleParser::Public:
      case RiddleParser::Protected:
      case RiddleParser::Private: {
        enterOuterAlt(_localctx, 4);
        setState(93);
        funcDefine();
        break;
      }

      case RiddleParser::Var: {
        enterOuterAlt(_localctx, 5);
        setState(94);
        varDefineStatement();
        break;
      }

      case RiddleParser::For: {
        enterOuterAlt(_localctx, 6);
        setState(95);
        forStatement();
        break;
      }

      case RiddleParser::While: {
        enterOuterAlt(_localctx, 7);
        setState(96);
        whileStatement();
        break;
      }

      case RiddleParser::If: {
        enterOuterAlt(_localctx, 8);
        setState(97);
        ifStatement();
        break;
      }

      case RiddleParser::Return: {
        enterOuterAlt(_localctx, 9);
        setState(98);
        returnStatement();
        break;
      }

      case RiddleParser::Continue: {
        enterOuterAlt(_localctx, 10);
        setState(99);
        continueStatement();
        break;
      }

      case RiddleParser::Break: {
        enterOuterAlt(_localctx, 11);
        setState(100);
        breakStatement();
        break;
      }

      case RiddleParser::Try: {
        enterOuterAlt(_localctx, 12);
        setState(101);
        tryExpr();
        break;
      }

      case RiddleParser::True:
      case RiddleParser::False:
      case RiddleParser::Null:
      case RiddleParser::LeftBracket:
      case RiddleParser::Less:
      case RiddleParser::Add:
      case RiddleParser::Sub:
      case RiddleParser::Not:
      case RiddleParser::Identifier:
      case RiddleParser::Hexadecimal:
      case RiddleParser::Decimal:
      case RiddleParser::Octal:
      case RiddleParser::Binary:
      case RiddleParser::Float:
      case RiddleParser::STRING: {
        enterOuterAlt(_localctx, 13);
        setState(102);
        expression(0);
        break;
      }

      case RiddleParser::LeftCurly: {
        enterOuterAlt(_localctx, 14);
        setState(103);
        bodyExpr();
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

//----------------- BodyExprContext ------------------------------------------------------------------

RiddleParser::BodyExprContext::BodyExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::BodyExprContext::LeftCurly() {
  return getToken(RiddleParser::LeftCurly, 0);
}

tree::TerminalNode* RiddleParser::BodyExprContext::RightCurly() {
  return getToken(RiddleParser::RightCurly, 0);
}

std::vector<RiddleParser::Statement_edContext *> RiddleParser::BodyExprContext::statement_ed() {
  return getRuleContexts<RiddleParser::Statement_edContext>();
}

RiddleParser::Statement_edContext* RiddleParser::BodyExprContext::statement_ed(size_t i) {
  return getRuleContext<RiddleParser::Statement_edContext>(i);
}


size_t RiddleParser::BodyExprContext::getRuleIndex() const {
  return RiddleParser::RuleBodyExpr;
}

void RiddleParser::BodyExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBodyExpr(this);
}

void RiddleParser::BodyExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBodyExpr(this);
}


std::any RiddleParser::BodyExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitBodyExpr(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::BodyExprContext* RiddleParser::bodyExpr() {
  BodyExprContext *_localctx = _tracker.createInstance<BodyExprContext>(_ctx, getState());
  enterRule(_localctx, 8, RiddleParser::RuleBodyExpr);
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
    setState(106);
    match(RiddleParser::LeftCurly);
    setState(110);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2287982826970414842) != 0) || _la == RiddleParser::STRING) {
      setState(107);
      statement_ed();
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(113);
    match(RiddleParser::RightCurly);
   
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
  enterRule(_localctx, 10, RiddleParser::RulePackStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(RiddleParser::Package);
    setState(116);
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
  enterRule(_localctx, 12, RiddleParser::RuleImportStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(RiddleParser::Import);
    setState(119);
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

tree::TerminalNode* RiddleParser::VarDefineStatementContext::Identifier() {
  return getToken(RiddleParser::Identifier, 0);
}

RiddleParser::TypeNameContext* RiddleParser::VarDefineStatementContext::typeName() {
  return getRuleContext<RiddleParser::TypeNameContext>(0);
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
  enterRule(_localctx, 14, RiddleParser::RuleVarDefineStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(136);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(121);
      match(RiddleParser::Var);
      setState(122);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->name = match(RiddleParser::Identifier);
      setState(123);
      match(RiddleParser::Colon);
      setState(124);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->type = typeName(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(125);
      match(RiddleParser::Var);
      setState(126);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->name = match(RiddleParser::Identifier);
      setState(127);
      match(RiddleParser::Assign);
      setState(128);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->value = expression(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(129);
      match(RiddleParser::Var);
      setState(130);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->name = match(RiddleParser::Identifier);
      setState(131);
      match(RiddleParser::Colon);
      setState(132);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->type = typeName(0);
      setState(133);
      match(RiddleParser::Assign);
      setState(134);
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
  enterRule(_localctx, 16, RiddleParser::RuleArgsExpr);
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
    setState(147);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 14) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 14)) & 4642147504492551) != 0)) {
      setState(143);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(138);
          expression(0);
          setState(139);
          match(RiddleParser::Comma); 
        }
        setState(145);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      }
      setState(146);
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

std::vector<RiddleParser::TypeNameContext *> RiddleParser::DefineArgsContext::typeName() {
  return getRuleContexts<RiddleParser::TypeNameContext>();
}

RiddleParser::TypeNameContext* RiddleParser::DefineArgsContext::typeName(size_t i) {
  return getRuleContext<RiddleParser::TypeNameContext>(i);
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
  enterRule(_localctx, 18, RiddleParser::RuleDefineArgs);
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
    setState(162);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Identifier) {
      setState(156);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(149);
          match(RiddleParser::Identifier);
          setState(150);
          match(RiddleParser::Colon);
          setState(151);
          typeName(0);
          setState(152);
          match(RiddleParser::Comma); 
        }
        setState(158);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      }

      setState(159);
      match(RiddleParser::Identifier);
      setState(160);
      match(RiddleParser::Colon);
      setState(161);
      typeName(0);
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

RiddleParser::ModifierListContext* RiddleParser::FuncDefineContext::modifierList() {
  return getRuleContext<RiddleParser::ModifierListContext>(0);
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

tree::TerminalNode* RiddleParser::FuncDefineContext::Identifier() {
  return getToken(RiddleParser::Identifier, 0);
}

RiddleParser::DefineArgsContext* RiddleParser::FuncDefineContext::defineArgs() {
  return getRuleContext<RiddleParser::DefineArgsContext>(0);
}

RiddleParser::BodyExprContext* RiddleParser::FuncDefineContext::bodyExpr() {
  return getRuleContext<RiddleParser::BodyExprContext>(0);
}

tree::TerminalNode* RiddleParser::FuncDefineContext::Sub() {
  return getToken(RiddleParser::Sub, 0);
}

tree::TerminalNode* RiddleParser::FuncDefineContext::Greater() {
  return getToken(RiddleParser::Greater, 0);
}

RiddleParser::TypeNameContext* RiddleParser::FuncDefineContext::typeName() {
  return getRuleContext<RiddleParser::TypeNameContext>(0);
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
  enterRule(_localctx, 20, RiddleParser::RuleFuncDefine);
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
    setState(164);
    modifierList();
    setState(165);
    match(RiddleParser::Func);
    setState(166);
    antlrcpp::downCast<FuncDefineContext *>(_localctx)->funcName = match(RiddleParser::Identifier);
    setState(167);
    match(RiddleParser::LeftBracket);
    setState(168);
    antlrcpp::downCast<FuncDefineContext *>(_localctx)->args = defineArgs();
    setState(169);
    match(RiddleParser::RightBracket);
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Sub) {
      setState(170);
      match(RiddleParser::Sub);
      setState(171);
      match(RiddleParser::Greater);
      setState(172);
      antlrcpp::downCast<FuncDefineContext *>(_localctx)->returnType = typeName(0);
    }
    setState(175);
    antlrcpp::downCast<FuncDefineContext *>(_localctx)->body = bodyExpr();
   
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

std::vector<RiddleParser::StatementContext *> RiddleParser::ForStatementContext::statement() {
  return getRuleContexts<RiddleParser::StatementContext>();
}

RiddleParser::StatementContext* RiddleParser::ForStatementContext::statement(size_t i) {
  return getRuleContext<RiddleParser::StatementContext>(i);
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
    setState(177);
    match(RiddleParser::For);
    setState(178);
    match(RiddleParser::LeftBracket);
    setState(180);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2269968419870998266) != 0) || _la == RiddleParser::STRING) {
      setState(179);
      antlrcpp::downCast<ForStatementContext *>(_localctx)->init = statement();
    }
    setState(182);
    match(RiddleParser::Semi);
    setState(184);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2269968419870998266) != 0) || _la == RiddleParser::STRING) {
      setState(183);
      antlrcpp::downCast<ForStatementContext *>(_localctx)->termCond = statement();
    }
    setState(186);
    match(RiddleParser::Semi);
    setState(188);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2269968419870998266) != 0) || _la == RiddleParser::STRING) {
      setState(187);
      antlrcpp::downCast<ForStatementContext *>(_localctx)->selfVar = statement();
    }
    setState(190);
    match(RiddleParser::RightBracket);
    setState(191);
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
    setState(193);
    match(RiddleParser::While);
    setState(194);
    match(RiddleParser::LeftBracket);
    setState(195);
    antlrcpp::downCast<WhileStatementContext *>(_localctx)->runCond = expression(0);
    setState(196);
    match(RiddleParser::RightBracket);
    setState(197);
    antlrcpp::downCast<WhileStatementContext *>(_localctx)->body = statement_ed();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStatementContext ------------------------------------------------------------------

RiddleParser::ContinueStatementContext::ContinueStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::ContinueStatementContext::Continue() {
  return getToken(RiddleParser::Continue, 0);
}


size_t RiddleParser::ContinueStatementContext::getRuleIndex() const {
  return RiddleParser::RuleContinueStatement;
}

void RiddleParser::ContinueStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStatement(this);
}

void RiddleParser::ContinueStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStatement(this);
}


std::any RiddleParser::ContinueStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitContinueStatement(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ContinueStatementContext* RiddleParser::continueStatement() {
  ContinueStatementContext *_localctx = _tracker.createInstance<ContinueStatementContext>(_ctx, getState());
  enterRule(_localctx, 26, RiddleParser::RuleContinueStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(RiddleParser::Continue);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStatementContext ------------------------------------------------------------------

RiddleParser::BreakStatementContext::BreakStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::BreakStatementContext::Break() {
  return getToken(RiddleParser::Break, 0);
}


size_t RiddleParser::BreakStatementContext::getRuleIndex() const {
  return RiddleParser::RuleBreakStatement;
}

void RiddleParser::BreakStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStatement(this);
}

void RiddleParser::BreakStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStatement(this);
}


std::any RiddleParser::BreakStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitBreakStatement(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::BreakStatementContext* RiddleParser::breakStatement() {
  BreakStatementContext *_localctx = _tracker.createInstance<BreakStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, RiddleParser::RuleBreakStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(RiddleParser::Break);
   
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
  enterRule(_localctx, 30, RiddleParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(219);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(203);
      match(RiddleParser::If);
      setState(204);
      match(RiddleParser::LeftBracket);
      setState(205);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->cond = expression(0);
      setState(206);
      match(RiddleParser::RightBracket);
      setState(207);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->body = statement_ed();
      antlrcpp::downCast<IfStatementContext *>(_localctx)->hasElse = false;
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(210);
      match(RiddleParser::If);
      setState(211);
      match(RiddleParser::LeftBracket);
      setState(212);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->cond = expression(0);
      setState(213);
      match(RiddleParser::RightBracket);
      setState(214);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->body = statement_ed();
      setState(215);
      match(RiddleParser::Else);
      setState(216);
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

RiddleParser::StatementContext* RiddleParser::ReturnStatementContext::statement() {
  return getRuleContext<RiddleParser::StatementContext>(0);
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
  enterRule(_localctx, 32, RiddleParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    match(RiddleParser::Return);
    setState(223);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(222);
      antlrcpp::downCast<ReturnStatementContext *>(_localctx)->result = statement();
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

//----------------- ClassDefineContext ------------------------------------------------------------------

RiddleParser::ClassDefineContext::ClassDefineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::ClassDefineContext::Class() {
  return getToken(RiddleParser::Class, 0);
}

std::vector<RiddleParser::IdContext *> RiddleParser::ClassDefineContext::id() {
  return getRuleContexts<RiddleParser::IdContext>();
}

RiddleParser::IdContext* RiddleParser::ClassDefineContext::id(size_t i) {
  return getRuleContext<RiddleParser::IdContext>(i);
}

RiddleParser::BodyExprContext* RiddleParser::ClassDefineContext::bodyExpr() {
  return getRuleContext<RiddleParser::BodyExprContext>(0);
}

tree::TerminalNode* RiddleParser::ClassDefineContext::Colon() {
  return getToken(RiddleParser::Colon, 0);
}


size_t RiddleParser::ClassDefineContext::getRuleIndex() const {
  return RiddleParser::RuleClassDefine;
}

void RiddleParser::ClassDefineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassDefine(this);
}

void RiddleParser::ClassDefineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassDefine(this);
}


std::any RiddleParser::ClassDefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitClassDefine(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ClassDefineContext* RiddleParser::classDefine() {
  ClassDefineContext *_localctx = _tracker.createInstance<ClassDefineContext>(_ctx, getState());
  enterRule(_localctx, 34, RiddleParser::RuleClassDefine);
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
    setState(225);
    match(RiddleParser::Class);
    setState(226);
    antlrcpp::downCast<ClassDefineContext *>(_localctx)->className = id();
    setState(229);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Colon) {
      setState(227);
      match(RiddleParser::Colon);
      setState(228);
      antlrcpp::downCast<ClassDefineContext *>(_localctx)->parentClass = id();
    }
    setState(231);
    antlrcpp::downCast<ClassDefineContext *>(_localctx)->body = bodyExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TryExprContext ------------------------------------------------------------------

RiddleParser::TryExprContext::TryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::TryExprContext::Try() {
  return getToken(RiddleParser::Try, 0);
}

RiddleParser::CatchExprContext* RiddleParser::TryExprContext::catchExpr() {
  return getRuleContext<RiddleParser::CatchExprContext>(0);
}

RiddleParser::BodyExprContext* RiddleParser::TryExprContext::bodyExpr() {
  return getRuleContext<RiddleParser::BodyExprContext>(0);
}

RiddleParser::Null_cntContext* RiddleParser::TryExprContext::null_cnt() {
  return getRuleContext<RiddleParser::Null_cntContext>(0);
}


size_t RiddleParser::TryExprContext::getRuleIndex() const {
  return RiddleParser::RuleTryExpr;
}

void RiddleParser::TryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTryExpr(this);
}

void RiddleParser::TryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTryExpr(this);
}


std::any RiddleParser::TryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitTryExpr(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::TryExprContext* RiddleParser::tryExpr() {
  TryExprContext *_localctx = _tracker.createInstance<TryExprContext>(_ctx, getState());
  enterRule(_localctx, 36, RiddleParser::RuleTryExpr);
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
    setState(233);
    match(RiddleParser::Try);
    setState(234);
    antlrcpp::downCast<TryExprContext *>(_localctx)->tryBody = bodyExpr();
    setState(236);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Semi

    || _la == RiddleParser::Endl) {
      setState(235);
      null_cnt();
    }
    setState(238);
    catchExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatchExprContext ------------------------------------------------------------------

RiddleParser::CatchExprContext::CatchExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::CatchExprContext::Catch() {
  return getToken(RiddleParser::Catch, 0);
}

tree::TerminalNode* RiddleParser::CatchExprContext::LeftBracket() {
  return getToken(RiddleParser::LeftBracket, 0);
}

RiddleParser::VarDefineStatementContext* RiddleParser::CatchExprContext::varDefineStatement() {
  return getRuleContext<RiddleParser::VarDefineStatementContext>(0);
}

tree::TerminalNode* RiddleParser::CatchExprContext::RightBracket() {
  return getToken(RiddleParser::RightBracket, 0);
}


size_t RiddleParser::CatchExprContext::getRuleIndex() const {
  return RiddleParser::RuleCatchExpr;
}

void RiddleParser::CatchExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCatchExpr(this);
}

void RiddleParser::CatchExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCatchExpr(this);
}


std::any RiddleParser::CatchExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitCatchExpr(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::CatchExprContext* RiddleParser::catchExpr() {
  CatchExprContext *_localctx = _tracker.createInstance<CatchExprContext>(_ctx, getState());
  enterRule(_localctx, 38, RiddleParser::RuleCatchExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    match(RiddleParser::Catch);
    setState(241);
    match(RiddleParser::LeftBracket);
    setState(242);
    varDefineStatement();
    setState(243);
    match(RiddleParser::RightBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprPtrContext ------------------------------------------------------------------

RiddleParser::ExprPtrContext::ExprPtrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RiddleParser::ExprPtrContext::getRuleIndex() const {
  return RiddleParser::RuleExprPtr;
}

void RiddleParser::ExprPtrContext::copyFrom(ExprPtrContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FuncExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::FuncExprContext::LeftBracket() {
  return getToken(RiddleParser::LeftBracket, 0);
}

tree::TerminalNode* RiddleParser::FuncExprContext::RightBracket() {
  return getToken(RiddleParser::RightBracket, 0);
}

tree::TerminalNode* RiddleParser::FuncExprContext::Identifier() {
  return getToken(RiddleParser::Identifier, 0);
}

RiddleParser::ArgsExprContext* RiddleParser::FuncExprContext::argsExpr() {
  return getRuleContext<RiddleParser::ArgsExprContext>(0);
}

RiddleParser::FuncExprContext::FuncExprContext(ExprPtrContext *ctx) { copyFrom(ctx); }

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
//----------------- ObjectExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::ObjectExprContext::Identifier() {
  return getToken(RiddleParser::Identifier, 0);
}

RiddleParser::ObjectExprContext::ObjectExprContext(ExprPtrContext *ctx) { copyFrom(ctx); }

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
//----------------- BlendExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::BlendExprContext::Dot() {
  return getToken(RiddleParser::Dot, 0);
}

std::vector<RiddleParser::ExprPtrContext *> RiddleParser::BlendExprContext::exprPtr() {
  return getRuleContexts<RiddleParser::ExprPtrContext>();
}

RiddleParser::ExprPtrContext* RiddleParser::BlendExprContext::exprPtr(size_t i) {
  return getRuleContext<RiddleParser::ExprPtrContext>(i);
}

RiddleParser::BlendExprContext::BlendExprContext(ExprPtrContext *ctx) { copyFrom(ctx); }

void RiddleParser::BlendExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlendExpr(this);
}
void RiddleParser::BlendExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlendExpr(this);
}

std::any RiddleParser::BlendExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitBlendExpr(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ExprPtrContext* RiddleParser::exprPtr() {
   return exprPtr(0);
}

RiddleParser::ExprPtrContext* RiddleParser::exprPtr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  RiddleParser::ExprPtrContext *_localctx = _tracker.createInstance<ExprPtrContext>(_ctx, parentState);
  RiddleParser::ExprPtrContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, RiddleParser::RuleExprPtr, precedence);

    

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
    setState(252);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<FuncExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(246);
      antlrcpp::downCast<FuncExprContext *>(_localctx)->funcName = match(RiddleParser::Identifier);
      setState(247);
      match(RiddleParser::LeftBracket);
      setState(248);
      antlrcpp::downCast<FuncExprContext *>(_localctx)->args = argsExpr();
      setState(249);
      match(RiddleParser::RightBracket);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ObjectExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(251);
      match(RiddleParser::Identifier);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(259);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<BlendExprContext>(_tracker.createInstance<ExprPtrContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->parents = previousContext;
        pushNewRecursionContext(newContext, startState, RuleExprPtr);
        setState(254);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(255);
        match(RiddleParser::Dot);
        setState(256);
        antlrcpp::downCast<BlendExprContext *>(_localctx)->child = exprPtr(2); 
      }
      setState(261);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExprPtrParserContext ------------------------------------------------------------------

RiddleParser::ExprPtrParserContext::ExprPtrParserContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RiddleParser::ExprPtrContext* RiddleParser::ExprPtrParserContext::exprPtr() {
  return getRuleContext<RiddleParser::ExprPtrContext>(0);
}


size_t RiddleParser::ExprPtrParserContext::getRuleIndex() const {
  return RiddleParser::RuleExprPtrParser;
}

void RiddleParser::ExprPtrParserContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprPtrParser(this);
}

void RiddleParser::ExprPtrParserContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprPtrParser(this);
}


std::any RiddleParser::ExprPtrParserContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitExprPtrParser(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ExprPtrParserContext* RiddleParser::exprPtrParser() {
  ExprPtrParserContext *_localctx = _tracker.createInstance<ExprPtrParserContext>(_ctx, getState());
  enterRule(_localctx, 42, RiddleParser::RuleExprPtrParser);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    exprPtr(0);
   
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

RiddleParser::ExprPtrParserContext* RiddleParser::SelfSubRightExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
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

RiddleParser::ExprPtrParserContext* RiddleParser::AndAssignExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
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
//----------------- NullExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::NullExprContext::Null() {
  return getToken(RiddleParser::Null, 0);
}

RiddleParser::NullExprContext::NullExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::NullExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNullExpr(this);
}
void RiddleParser::NullExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNullExpr(this);
}

std::any RiddleParser::NullExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitNullExpr(this);
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
//----------------- CastExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::CastExprContext::Less() {
  return getToken(RiddleParser::Less, 0);
}

tree::TerminalNode* RiddleParser::CastExprContext::Greater() {
  return getToken(RiddleParser::Greater, 0);
}

tree::TerminalNode* RiddleParser::CastExprContext::LeftBracket() {
  return getToken(RiddleParser::LeftBracket, 0);
}

tree::TerminalNode* RiddleParser::CastExprContext::RightBracket() {
  return getToken(RiddleParser::RightBracket, 0);
}

RiddleParser::TypeNameContext* RiddleParser::CastExprContext::typeName() {
  return getRuleContext<RiddleParser::TypeNameContext>(0);
}

RiddleParser::ExprPtrParserContext* RiddleParser::CastExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
}

RiddleParser::CastExprContext::CastExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::CastExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCastExpr(this);
}
void RiddleParser::CastExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCastExpr(this);
}

std::any RiddleParser::CastExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitCastExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LShrExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::LShrExprContext::RightRightRight() {
  return getToken(RiddleParser::RightRightRight, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::LShrExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::LShrExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::LShrExprContext::LShrExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::LShrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLShrExpr(this);
}
void RiddleParser::LShrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLShrExpr(this);
}

std::any RiddleParser::LShrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitLShrExpr(this);
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
//----------------- MulAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::MulAssignExprContext::Star() {
  return getToken(RiddleParser::Star, 0);
}

tree::TerminalNode* RiddleParser::MulAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ExprPtrParserContext* RiddleParser::MulAssignExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::MulAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::MulAssignExprContext::MulAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::MulAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulAssignExpr(this);
}
void RiddleParser::MulAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulAssignExpr(this);
}

std::any RiddleParser::MulAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitMulAssignExpr(this);
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

RiddleParser::ExprPtrParserContext* RiddleParser::XorAssignExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
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

RiddleParser::ExprPtrParserContext* RiddleParser::AddAssignExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
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

RiddleParser::ExprPtrParserContext* RiddleParser::OrAssignExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
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
//----------------- PtrExprContext ------------------------------------------------------------------

RiddleParser::ExprPtrContext* RiddleParser::PtrExprContext::exprPtr() {
  return getRuleContext<RiddleParser::ExprPtrContext>(0);
}

RiddleParser::PtrExprContext::PtrExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::PtrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPtrExpr(this);
}
void RiddleParser::PtrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPtrExpr(this);
}

std::any RiddleParser::PtrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitPtrExpr(this);
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

RiddleParser::ExprPtrParserContext* RiddleParser::DivAssignExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
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
//----------------- MulExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::MulExprContext::Star() {
  return getToken(RiddleParser::Star, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::MulExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::MulExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::MulExprContext::MulExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::MulExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExpr(this);
}
void RiddleParser::MulExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExpr(this);
}

std::any RiddleParser::MulExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitMulExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotEqualExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::NotEqualExprContext::Not() {
  return getToken(RiddleParser::Not, 0);
}

tree::TerminalNode* RiddleParser::NotEqualExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
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

RiddleParser::ExprPtrParserContext* RiddleParser::SelfSubLeftExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
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

RiddleParser::ExprPtrParserContext* RiddleParser::AssignExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
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

RiddleParser::ExprPtrParserContext* RiddleParser::SelfAddRightExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
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

RiddleParser::ExprPtrParserContext* RiddleParser::SubAssignExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
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
//----------------- BooleanExprContext ------------------------------------------------------------------

RiddleParser::BooleanContext* RiddleParser::BooleanExprContext::boolean() {
  return getRuleContext<RiddleParser::BooleanContext>(0);
}

RiddleParser::BooleanExprContext::BooleanExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::BooleanExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanExpr(this);
}
void RiddleParser::BooleanExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanExpr(this);
}

std::any RiddleParser::BooleanExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitBooleanExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AShrExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::AShrExprContext::RightRight() {
  return getToken(RiddleParser::RightRight, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::AShrExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::AShrExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::AShrExprContext::AShrExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::AShrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAShrExpr(this);
}
void RiddleParser::AShrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAShrExpr(this);
}

std::any RiddleParser::AShrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitAShrExpr(this);
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
//----------------- SelfAddLeftExprContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> RiddleParser::SelfAddLeftExprContext::Add() {
  return getTokens(RiddleParser::Add);
}

tree::TerminalNode* RiddleParser::SelfAddLeftExprContext::Add(size_t i) {
  return getToken(RiddleParser::Add, i);
}

RiddleParser::ExprPtrParserContext* RiddleParser::SelfAddLeftExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
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
//----------------- LShrAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::LShrAssignExprContext::RightRightRight() {
  return getToken(RiddleParser::RightRightRight, 0);
}

tree::TerminalNode* RiddleParser::LShrAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ExprPtrParserContext* RiddleParser::LShrAssignExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::LShrAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::LShrAssignExprContext::LShrAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::LShrAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLShrAssignExpr(this);
}
void RiddleParser::LShrAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLShrAssignExpr(this);
}

std::any RiddleParser::LShrAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitLShrAssignExpr(this);
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
//----------------- AShrAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::AShrAssignExprContext::RightRight() {
  return getToken(RiddleParser::RightRight, 0);
}

tree::TerminalNode* RiddleParser::AShrAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ExprPtrParserContext* RiddleParser::AShrAssignExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::AShrAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::AShrAssignExprContext::AShrAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::AShrAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAShrAssignExpr(this);
}
void RiddleParser::AShrAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAShrAssignExpr(this);
}

std::any RiddleParser::AShrAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitAShrAssignExpr(this);
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
//----------------- ShlAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::ShlAssignExprContext::LeftLeft() {
  return getToken(RiddleParser::LeftLeft, 0);
}

tree::TerminalNode* RiddleParser::ShlAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ExprPtrParserContext* RiddleParser::ShlAssignExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::ShlAssignExprContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::ShlAssignExprContext::ShlAssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::ShlAssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShlAssignExpr(this);
}
void RiddleParser::ShlAssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShlAssignExpr(this);
}

std::any RiddleParser::ShlAssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitShlAssignExpr(this);
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

RiddleParser::ExprPtrParserContext* RiddleParser::ModAssignExprContext::exprPtrParser() {
  return getRuleContext<RiddleParser::ExprPtrParserContext>(0);
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
//----------------- ShlExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::ShlExprContext::LeftLeft() {
  return getToken(RiddleParser::LeftLeft, 0);
}

std::vector<RiddleParser::ExpressionContext *> RiddleParser::ShlExprContext::expression() {
  return getRuleContexts<RiddleParser::ExpressionContext>();
}

RiddleParser::ExpressionContext* RiddleParser::ShlExprContext::expression(size_t i) {
  return getRuleContext<RiddleParser::ExpressionContext>(i);
}

RiddleParser::ShlExprContext::ShlExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::ShlExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShlExpr(this);
}
void RiddleParser::ShlExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShlExpr(this);
}

std::any RiddleParser::ShlExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitShlExpr(this);
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
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, RiddleParser::RuleExpression, precedence);

    

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
    setState(365);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CastExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(265);
      match(RiddleParser::Less);
      setState(266);
      antlrcpp::downCast<CastExprContext *>(_localctx)->type = typeName(0);
      setState(267);
      match(RiddleParser::Greater);
      setState(268);
      match(RiddleParser::LeftBracket);
      setState(269);
      antlrcpp::downCast<CastExprContext *>(_localctx)->value = exprPtrParser();
      setState(270);
      match(RiddleParser::RightBracket);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<BracketExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(272);
      match(RiddleParser::LeftBracket);
      setState(273);
      antlrcpp::downCast<BracketExprContext *>(_localctx)->expr = expression(0);
      setState(274);
      match(RiddleParser::RightBracket);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(276);
      match(RiddleParser::Not);
      setState(277);
      antlrcpp::downCast<NotExprContext *>(_localctx)->expr = expression(44);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<PositiveExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(278);
      match(RiddleParser::Add);
      setState(279);
      antlrcpp::downCast<PositiveExprContext *>(_localctx)->expr = expression(43);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NegativeExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(280);
      match(RiddleParser::Sub);
      setState(281);
      antlrcpp::downCast<NegativeExprContext *>(_localctx)->expr = expression(42);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<SelfAddLeftExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(282);
      match(RiddleParser::Add);
      setState(283);
      match(RiddleParser::Add);
      setState(284);
      antlrcpp::downCast<SelfAddLeftExprContext *>(_localctx)->expr = exprPtrParser();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<SelfAddRightExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(285);
      antlrcpp::downCast<SelfAddRightExprContext *>(_localctx)->expr = exprPtrParser();
      setState(286);
      match(RiddleParser::Add);
      setState(287);
      match(RiddleParser::Add);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<SelfSubLeftExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(289);
      match(RiddleParser::Sub);
      setState(290);
      match(RiddleParser::Sub);
      setState(291);
      antlrcpp::downCast<SelfSubLeftExprContext *>(_localctx)->expr = exprPtrParser();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<SelfSubRightExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(292);
      antlrcpp::downCast<SelfSubRightExprContext *>(_localctx)->expr = exprPtrParser();
      setState(293);
      match(RiddleParser::Sub);
      setState(294);
      match(RiddleParser::Sub);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<PtrExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(296);
      exprPtr(0);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<AssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(297);
      antlrcpp::downCast<AssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(298);
      match(RiddleParser::Assign);
      setState(299);
      antlrcpp::downCast<AssignExprContext *>(_localctx)->right = expression(17);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<AddAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(301);
      antlrcpp::downCast<AddAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(302);
      match(RiddleParser::Add);
      setState(303);
      match(RiddleParser::Assign);
      setState(304);
      antlrcpp::downCast<AddAssignExprContext *>(_localctx)->right = expression(16);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<SubAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(306);
      antlrcpp::downCast<SubAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(307);
      match(RiddleParser::Sub);
      setState(308);
      match(RiddleParser::Assign);
      setState(309);
      antlrcpp::downCast<SubAssignExprContext *>(_localctx)->right = expression(15);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<MulAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(311);
      antlrcpp::downCast<MulAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(312);
      match(RiddleParser::Star);
      setState(313);
      match(RiddleParser::Assign);
      setState(314);
      antlrcpp::downCast<MulAssignExprContext *>(_localctx)->right = expression(14);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<DivAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(316);
      antlrcpp::downCast<DivAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(317);
      match(RiddleParser::Div);
      setState(318);
      match(RiddleParser::Assign);
      setState(319);
      antlrcpp::downCast<DivAssignExprContext *>(_localctx)->right = expression(13);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<ModAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(321);
      antlrcpp::downCast<ModAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(322);
      match(RiddleParser::Mod);
      setState(323);
      match(RiddleParser::Assign);
      setState(324);
      antlrcpp::downCast<ModAssignExprContext *>(_localctx)->right = expression(12);
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<AddAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(326);
      antlrcpp::downCast<AddAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(327);
      match(RiddleParser::Add);
      setState(328);
      match(RiddleParser::Assign);
      setState(329);
      antlrcpp::downCast<AddAssignExprContext *>(_localctx)->right = expression(11);
      break;
    }

    case 18: {
      _localctx = _tracker.createInstance<AndAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(331);
      antlrcpp::downCast<AndAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(332);
      match(RiddleParser::And);
      setState(333);
      match(RiddleParser::Assign);
      setState(334);
      antlrcpp::downCast<AndAssignExprContext *>(_localctx)->right = expression(10);
      break;
    }

    case 19: {
      _localctx = _tracker.createInstance<OrAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(336);
      antlrcpp::downCast<OrAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(337);
      match(RiddleParser::Or);
      setState(338);
      match(RiddleParser::Assign);
      setState(339);
      antlrcpp::downCast<OrAssignExprContext *>(_localctx)->right = expression(9);
      break;
    }

    case 20: {
      _localctx = _tracker.createInstance<XorAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(341);
      antlrcpp::downCast<XorAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(342);
      match(RiddleParser::Xor);
      setState(343);
      match(RiddleParser::Assign);
      setState(344);
      antlrcpp::downCast<XorAssignExprContext *>(_localctx)->right = expression(8);
      break;
    }

    case 21: {
      _localctx = _tracker.createInstance<ShlAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(346);
      antlrcpp::downCast<ShlAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(347);
      match(RiddleParser::LeftLeft);
      setState(348);
      match(RiddleParser::Assign);
      setState(349);
      antlrcpp::downCast<ShlAssignExprContext *>(_localctx)->right = expression(7);
      break;
    }

    case 22: {
      _localctx = _tracker.createInstance<AShrAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(351);
      antlrcpp::downCast<AShrAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(352);
      match(RiddleParser::RightRight);
      setState(353);
      match(RiddleParser::Assign);
      setState(354);
      antlrcpp::downCast<AShrAssignExprContext *>(_localctx)->right = expression(6);
      break;
    }

    case 23: {
      _localctx = _tracker.createInstance<LShrAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(356);
      antlrcpp::downCast<LShrAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(357);
      match(RiddleParser::RightRightRight);
      setState(358);
      match(RiddleParser::Assign);
      setState(359);
      antlrcpp::downCast<LShrAssignExprContext *>(_localctx)->right = expression(5);
      break;
    }

    case 24: {
      _localctx = _tracker.createInstance<StringExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(361);
      string();
      break;
    }

    case 25: {
      _localctx = _tracker.createInstance<NumberExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(362);
      number();
      break;
    }

    case 26: {
      _localctx = _tracker.createInstance<BooleanExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(363);
      boolean();
      break;
    }

    case 27: {
      _localctx = _tracker.createInstance<NullExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(364);
      match(RiddleParser::Null);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(431);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(429);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(367);

          if (!(precpred(_ctx, 36))) throw FailedPredicateException(this, "precpred(_ctx, 36)");
          setState(368);
          match(RiddleParser::Star);
          setState(369);
          antlrcpp::downCast<MulExprContext *>(_localctx)->right = expression(37);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DivExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(370);

          if (!(precpred(_ctx, 35))) throw FailedPredicateException(this, "precpred(_ctx, 35)");
          setState(371);
          match(RiddleParser::Div);
          setState(372);
          antlrcpp::downCast<DivExprContext *>(_localctx)->right = expression(36);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ModExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(373);

          if (!(precpred(_ctx, 34))) throw FailedPredicateException(this, "precpred(_ctx, 34)");
          setState(374);
          match(RiddleParser::Mod);
          setState(375);
          antlrcpp::downCast<ModExprContext *>(_localctx)->right = expression(35);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AddExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(376);

          if (!(precpred(_ctx, 33))) throw FailedPredicateException(this, "precpred(_ctx, 33)");
          setState(377);
          match(RiddleParser::Add);
          setState(378);
          antlrcpp::downCast<AddExprContext *>(_localctx)->right = expression(34);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<SubExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(379);

          if (!(precpred(_ctx, 32))) throw FailedPredicateException(this, "precpred(_ctx, 32)");
          setState(380);
          match(RiddleParser::Sub);
          setState(381);
          antlrcpp::downCast<SubExprContext *>(_localctx)->right = expression(33);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ShlExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(382);

          if (!(precpred(_ctx, 31))) throw FailedPredicateException(this, "precpred(_ctx, 31)");
          setState(383);
          match(RiddleParser::LeftLeft);
          setState(384);
          antlrcpp::downCast<ShlExprContext *>(_localctx)->right = expression(32);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<AShrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(385);

          if (!(precpred(_ctx, 30))) throw FailedPredicateException(this, "precpred(_ctx, 30)");
          setState(386);
          match(RiddleParser::RightRight);
          setState(387);
          antlrcpp::downCast<AShrExprContext *>(_localctx)->right = expression(31);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<LShrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(388);

          if (!(precpred(_ctx, 29))) throw FailedPredicateException(this, "precpred(_ctx, 29)");
          setState(389);
          match(RiddleParser::RightRightRight);
          setState(390);
          antlrcpp::downCast<LShrExprContext *>(_localctx)->right = expression(30);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<GreaterExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(391);

          if (!(precpred(_ctx, 28))) throw FailedPredicateException(this, "precpred(_ctx, 28)");
          setState(392);
          match(RiddleParser::Greater);
          setState(393);
          antlrcpp::downCast<GreaterExprContext *>(_localctx)->right = expression(29);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LessExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(394);

          if (!(precpred(_ctx, 27))) throw FailedPredicateException(this, "precpred(_ctx, 27)");
          setState(395);
          match(RiddleParser::Less);
          setState(396);
          antlrcpp::downCast<LessExprContext *>(_localctx)->right = expression(28);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<GreaterEqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(397);

          if (!(precpred(_ctx, 26))) throw FailedPredicateException(this, "precpred(_ctx, 26)");
          setState(398);
          match(RiddleParser::Greater);
          setState(399);
          match(RiddleParser::Assign);
          setState(400);
          antlrcpp::downCast<GreaterEqualExprContext *>(_localctx)->right = expression(27);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<LessEqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(401);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(402);
          match(RiddleParser::Less);
          setState(403);
          match(RiddleParser::Assign);
          setState(404);
          antlrcpp::downCast<LessEqualExprContext *>(_localctx)->right = expression(26);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<EqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(405);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(406);
          match(RiddleParser::Equal);
          setState(407);
          antlrcpp::downCast<EqualExprContext *>(_localctx)->right = expression(25);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<NotEqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(408);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(409);
          match(RiddleParser::Not);
          setState(410);
          match(RiddleParser::Assign);
          setState(411);
          antlrcpp::downCast<NotEqualExprContext *>(_localctx)->right = expression(24);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<BitAndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(412);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(413);
          match(RiddleParser::And);
          setState(414);
          antlrcpp::downCast<BitAndExprContext *>(_localctx)->right = expression(23);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<BitXorExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(415);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(416);
          match(RiddleParser::Xor);
          setState(417);
          antlrcpp::downCast<BitXorExprContext *>(_localctx)->right = expression(22);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<BitOrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(418);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(419);
          match(RiddleParser::Or);
          setState(420);
          antlrcpp::downCast<BitOrExprContext *>(_localctx)->right = expression(21);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(421);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(422);
          match(RiddleParser::And);
          setState(423);
          match(RiddleParser::And);
          setState(424);
          antlrcpp::downCast<AndExprContext *>(_localctx)->right = expression(20);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(425);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(426);
          match(RiddleParser::Or);
          setState(427);
          match(RiddleParser::Or);
          setState(428);
          antlrcpp::downCast<OrExprContext *>(_localctx)->right = expression(19);
          break;
        }

        default:
          break;
        } 
      }
      setState(433);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
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

tree::TerminalNode* RiddleParser::IdContext::Identifier() {
  return getToken(RiddleParser::Identifier, 0);
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
  enterRule(_localctx, 46, RiddleParser::RuleId);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(434);
    match(RiddleParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModifierContext ------------------------------------------------------------------

RiddleParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::ModifierContext::Public() {
  return getToken(RiddleParser::Public, 0);
}

tree::TerminalNode* RiddleParser::ModifierContext::Protected() {
  return getToken(RiddleParser::Protected, 0);
}

tree::TerminalNode* RiddleParser::ModifierContext::Private() {
  return getToken(RiddleParser::Private, 0);
}


size_t RiddleParser::ModifierContext::getRuleIndex() const {
  return RiddleParser::RuleModifier;
}

void RiddleParser::ModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModifier(this);
}

void RiddleParser::ModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModifier(this);
}


std::any RiddleParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ModifierContext* RiddleParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 48, RiddleParser::RuleModifier);
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
    setState(436);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 29360128) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModifierListContext ------------------------------------------------------------------

RiddleParser::ModifierListContext::ModifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RiddleParser::ModifierContext *> RiddleParser::ModifierListContext::modifier() {
  return getRuleContexts<RiddleParser::ModifierContext>();
}

RiddleParser::ModifierContext* RiddleParser::ModifierListContext::modifier(size_t i) {
  return getRuleContext<RiddleParser::ModifierContext>(i);
}


size_t RiddleParser::ModifierListContext::getRuleIndex() const {
  return RiddleParser::RuleModifierList;
}

void RiddleParser::ModifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModifierList(this);
}

void RiddleParser::ModifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModifierList(this);
}


std::any RiddleParser::ModifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitModifierList(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::ModifierListContext* RiddleParser::modifierList() {
  ModifierListContext *_localctx = _tracker.createInstance<ModifierListContext>(_ctx, getState());
  enterRule(_localctx, 50, RiddleParser::RuleModifierList);
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
    setState(441);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 29360128) != 0)) {
      setState(438);
      modifier();
      setState(443);
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
  enterRule(_localctx, 52, RiddleParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(446);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RiddleParser::Hexadecimal:
      case RiddleParser::Decimal:
      case RiddleParser::Octal:
      case RiddleParser::Binary: {
        enterOuterAlt(_localctx, 1);
        setState(444);
        integer();
        break;
      }

      case RiddleParser::Float: {
        enterOuterAlt(_localctx, 2);
        setState(445);
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

//----------------- BooleanContext ------------------------------------------------------------------

RiddleParser::BooleanContext::BooleanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::BooleanContext::True() {
  return getToken(RiddleParser::True, 0);
}

tree::TerminalNode* RiddleParser::BooleanContext::False() {
  return getToken(RiddleParser::False, 0);
}


size_t RiddleParser::BooleanContext::getRuleIndex() const {
  return RiddleParser::RuleBoolean;
}

void RiddleParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}

void RiddleParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}


std::any RiddleParser::BooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitBoolean(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::BooleanContext* RiddleParser::boolean() {
  BooleanContext *_localctx = _tracker.createInstance<BooleanContext>(_ctx, getState());
  enterRule(_localctx, 54, RiddleParser::RuleBoolean);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(452);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RiddleParser::True: {
        enterOuterAlt(_localctx, 1);
        setState(448);
        match(RiddleParser::True);
        antlrcpp::downCast<BooleanContext *>(_localctx)->value = true;
        break;
      }

      case RiddleParser::False: {
        enterOuterAlt(_localctx, 2);
        setState(450);
        match(RiddleParser::False);
        antlrcpp::downCast<BooleanContext *>(_localctx)->value = false;
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
  enterRule(_localctx, 56, RiddleParser::RuleString);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
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
  enterRule(_localctx, 58, RiddleParser::RuleFloat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(456);
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
  enterRule(_localctx, 60, RiddleParser::RuleInteger);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(467);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RiddleParser::Decimal: {
        enterOuterAlt(_localctx, 1);
        setState(459);
        antlrcpp::downCast<IntegerContext *>(_localctx)->decimalToken = match(RiddleParser::Decimal);

                antlrcpp::downCast<IntegerContext *>(_localctx)->value =  stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->decimalToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->decimalToken->getText() : ""));
            
        break;
      }

      case RiddleParser::Hexadecimal: {
        enterOuterAlt(_localctx, 2);
        setState(461);
        antlrcpp::downCast<IntegerContext *>(_localctx)->hexadecimalToken = match(RiddleParser::Hexadecimal);

                antlrcpp::downCast<IntegerContext *>(_localctx)->value =  stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->hexadecimalToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->hexadecimalToken->getText() : "").substr(2),nullptr,16);
            
        break;
      }

      case RiddleParser::Binary: {
        enterOuterAlt(_localctx, 3);
        setState(463);
        antlrcpp::downCast<IntegerContext *>(_localctx)->binaryToken = match(RiddleParser::Binary);

                antlrcpp::downCast<IntegerContext *>(_localctx)->value =  stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->binaryToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->binaryToken->getText() : "").substr(2),nullptr,2);
            
        break;
      }

      case RiddleParser::Octal: {
        enterOuterAlt(_localctx, 4);
        setState(465);
        antlrcpp::downCast<IntegerContext *>(_localctx)->octalToken = match(RiddleParser::Octal);

                antlrcpp::downCast<IntegerContext *>(_localctx)->value =  stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->octalToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->octalToken->getText() : "").substr(1),nullptr,8);
            
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

//----------------- TemplateArgContext ------------------------------------------------------------------

RiddleParser::TemplateArgContext::TemplateArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RiddleParser::ExpressionContext* RiddleParser::TemplateArgContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::TypeNameContext* RiddleParser::TemplateArgContext::typeName() {
  return getRuleContext<RiddleParser::TypeNameContext>(0);
}


size_t RiddleParser::TemplateArgContext::getRuleIndex() const {
  return RiddleParser::RuleTemplateArg;
}

void RiddleParser::TemplateArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTemplateArg(this);
}

void RiddleParser::TemplateArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTemplateArg(this);
}


std::any RiddleParser::TemplateArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitTemplateArg(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::TemplateArgContext* RiddleParser::templateArg() {
  TemplateArgContext *_localctx = _tracker.createInstance<TemplateArgContext>(_ctx, getState());
  enterRule(_localctx, 62, RiddleParser::RuleTemplateArg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(471);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(469);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(470);
      typeName(0);
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

//----------------- TemplateArgsContext ------------------------------------------------------------------

RiddleParser::TemplateArgsContext::TemplateArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RiddleParser::TemplateArgContext *> RiddleParser::TemplateArgsContext::templateArg() {
  return getRuleContexts<RiddleParser::TemplateArgContext>();
}

RiddleParser::TemplateArgContext* RiddleParser::TemplateArgsContext::templateArg(size_t i) {
  return getRuleContext<RiddleParser::TemplateArgContext>(i);
}

std::vector<tree::TerminalNode *> RiddleParser::TemplateArgsContext::Comma() {
  return getTokens(RiddleParser::Comma);
}

tree::TerminalNode* RiddleParser::TemplateArgsContext::Comma(size_t i) {
  return getToken(RiddleParser::Comma, i);
}


size_t RiddleParser::TemplateArgsContext::getRuleIndex() const {
  return RiddleParser::RuleTemplateArgs;
}

void RiddleParser::TemplateArgsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTemplateArgs(this);
}

void RiddleParser::TemplateArgsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTemplateArgs(this);
}


std::any RiddleParser::TemplateArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitTemplateArgs(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::TemplateArgsContext* RiddleParser::templateArgs() {
  TemplateArgsContext *_localctx = _tracker.createInstance<TemplateArgsContext>(_ctx, getState());
  enterRule(_localctx, 64, RiddleParser::RuleTemplateArgs);
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
    setState(482);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 14) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 14)) & 4642147504492551) != 0)) {
      setState(478);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(473);
          templateArg();
          setState(474);
          match(RiddleParser::Comma); 
        }
        setState(480);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
      }
      setState(481);
      templateArg();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

RiddleParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RiddleParser::IdContext* RiddleParser::TypeNameContext::id() {
  return getRuleContext<RiddleParser::IdContext>(0);
}

tree::TerminalNode* RiddleParser::TypeNameContext::Less() {
  return getToken(RiddleParser::Less, 0);
}

tree::TerminalNode* RiddleParser::TypeNameContext::Greater() {
  return getToken(RiddleParser::Greater, 0);
}

RiddleParser::TemplateArgsContext* RiddleParser::TypeNameContext::templateArgs() {
  return getRuleContext<RiddleParser::TemplateArgsContext>(0);
}

tree::TerminalNode* RiddleParser::TypeNameContext::LeftSquare() {
  return getToken(RiddleParser::LeftSquare, 0);
}

tree::TerminalNode* RiddleParser::TypeNameContext::RightSquare() {
  return getToken(RiddleParser::RightSquare, 0);
}

RiddleParser::TypeNameContext* RiddleParser::TypeNameContext::typeName() {
  return getRuleContext<RiddleParser::TypeNameContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::TypeNameContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}


size_t RiddleParser::TypeNameContext::getRuleIndex() const {
  return RiddleParser::RuleTypeName;
}

void RiddleParser::TypeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeName(this);
}

void RiddleParser::TypeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeName(this);
}


std::any RiddleParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}


RiddleParser::TypeNameContext* RiddleParser::typeName() {
   return typeName(0);
}

RiddleParser::TypeNameContext* RiddleParser::typeName(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  RiddleParser::TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, parentState);
  RiddleParser::TypeNameContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 66;
  enterRecursionRule(_localctx, 66, RiddleParser::RuleTypeName, precedence);

    

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
    setState(491);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(485);
      antlrcpp::downCast<TypeNameContext *>(_localctx)->name = id();
      break;
    }

    case 2: {
      setState(486);
      antlrcpp::downCast<TypeNameContext *>(_localctx)->name = id();
      setState(487);
      match(RiddleParser::Less);
      setState(488);
      antlrcpp::downCast<TypeNameContext *>(_localctx)->args = templateArgs();
      setState(489);
      match(RiddleParser::Greater);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(500);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TypeNameContext>(parentContext, parentState);
        _localctx->baseType = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTypeName);
        setState(493);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(494);
        match(RiddleParser::LeftSquare);
        setState(495);
        antlrcpp::downCast<TypeNameContext *>(_localctx)->size = expression(0);
        setState(496);
        match(RiddleParser::RightSquare); 
      }
      setState(502);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
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
    case 20: return exprPtrSempred(antlrcpp::downCast<ExprPtrContext *>(context), predicateIndex);
    case 22: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);
    case 33: return typeNameSempred(antlrcpp::downCast<TypeNameContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool RiddleParser::exprPtrSempred(ExprPtrContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool RiddleParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 36);
    case 2: return precpred(_ctx, 35);
    case 3: return precpred(_ctx, 34);
    case 4: return precpred(_ctx, 33);
    case 5: return precpred(_ctx, 32);
    case 6: return precpred(_ctx, 31);
    case 7: return precpred(_ctx, 30);
    case 8: return precpred(_ctx, 29);
    case 9: return precpred(_ctx, 28);
    case 10: return precpred(_ctx, 27);
    case 11: return precpred(_ctx, 26);
    case 12: return precpred(_ctx, 25);
    case 13: return precpred(_ctx, 24);
    case 14: return precpred(_ctx, 23);
    case 15: return precpred(_ctx, 22);
    case 16: return precpred(_ctx, 21);
    case 17: return precpred(_ctx, 20);
    case 18: return precpred(_ctx, 19);
    case 19: return precpred(_ctx, 18);

  default:
    break;
  }
  return true;
}

bool RiddleParser::typeNameSempred(TypeNameContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 20: return precpred(_ctx, 1);

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
