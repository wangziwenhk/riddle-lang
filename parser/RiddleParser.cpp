
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
      "id", "modifier", "modifierList", "number", "boolean", "float", "integer", 
      "tmpleDefine", "tmplDefineArg", "tmplUsed", "tmplArg", "tmplArgList", 
      "typeUsed", "property", "propertyItem"
    },
    std::vector<std::string>{
      "", "'var'", "'val'", "'for'", "'while'", "'continue'", "'break'", 
      "'if'", "'else'", "'fun'", "'return'", "'import'", "'package'", "'class'", 
      "'true'", "'false'", "'null'", "'try'", "'catch'", "'override'", "'static'", 
      "'const'", "'public'", "'protected'", "'private'", "'virtual'", "'operator'", 
      "'template'", "'typename'", "'('", "')'", "'['", "']'", "'{'", "'}'", 
      "':'", "';'", "','", "'=='", "'='", "'>'", "'<'", "'<<'", "'>>'", 
      "'>>>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'&'", "'|'", "'^'", 
      "'.'", "'\"'", "'''", "'\\n'"
    },
    std::vector<std::string>{
      "", "Var", "Val", "For", "While", "Continue", "Break", "If", "Else", 
      "Func", "Return", "Import", "Package", "Class", "True", "False", "Null", 
      "Try", "Catch", "Override", "Static", "Const", "Public", "Protected", 
      "Private", "Virtual", "Operator", "Template", "TypeName", "LeftBracket", 
      "RightBracket", "LeftSquare", "RightSquare", "LeftCurly", "RightCurly", 
      "Colon", "Semi", "Comma", "Equal", "Assign", "Greater", "Less", "LeftLeft", 
      "RightRight", "RightRightRight", "Add", "Sub", "Star", "Div", "Mod", 
      "Not", "And", "Or", "Xor", "Dot", "DoubleQuotes", "Quotes", "Endl", 
      "Identifier", "Hexadecimal", "Decimal", "Octal", "Binary", "Float", 
      "IntegerSequence", "HEX_DIGIT", "OCTAL_DIGIT", "BINARY_DIGIT", "DIGIT", 
      "STRING", "CHAR", "LINE_COMMENT", "BLOCK_COMMENT", "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,73,576,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,1,0,5,0,78,8,0,10,0,12,0,81,9,0,1,0,3,0,84,8,0,
  	1,1,1,1,1,2,1,2,3,2,90,8,2,1,2,3,2,93,8,2,1,2,1,2,3,2,97,8,2,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,113,8,3,1,4,1,4,5,
  	4,117,8,4,10,4,12,4,120,9,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,147,8,7,
  	1,8,1,8,1,8,5,8,152,8,8,10,8,12,8,155,9,8,1,8,3,8,158,8,8,1,9,1,9,1,9,
  	1,9,1,9,5,9,165,8,9,10,9,12,9,168,9,9,1,9,1,9,1,9,1,9,3,9,174,8,9,1,10,
  	3,10,177,8,10,1,10,3,10,180,8,10,1,10,3,10,183,8,10,1,10,1,10,1,10,1,
  	10,1,10,1,10,1,10,1,10,1,10,3,10,194,8,10,1,10,1,10,3,10,198,8,10,1,11,
  	1,11,1,11,3,11,203,8,11,1,11,1,11,3,11,207,8,11,1,11,1,11,3,11,211,8,
  	11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,14,1,14,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,3,15,242,8,15,1,16,1,16,3,16,246,8,16,1,17,3,17,249,8,17,1,17,
  	3,17,252,8,17,1,17,3,17,255,8,17,1,17,3,17,258,8,17,1,17,1,17,1,17,1,
  	17,3,17,264,8,17,1,17,1,17,1,18,1,18,1,18,3,18,271,8,18,1,18,1,18,1,19,
  	1,19,1,19,1,19,1,19,1,20,1,20,1,20,3,20,283,8,20,1,20,1,20,1,20,1,20,
  	1,20,3,20,290,8,20,1,20,1,20,1,20,5,20,295,8,20,10,20,12,20,298,9,20,
  	1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,3,22,404,8,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,5,22,468,8,22,10,22,12,22,471,9,22,1,23,1,23,1,24,1,24,1,25,5,25,
  	478,8,25,10,25,12,25,481,9,25,1,26,1,26,3,26,485,8,26,1,27,1,27,1,27,
  	1,27,3,27,491,8,27,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,1,29,
  	1,29,3,29,504,8,29,1,30,1,30,1,30,1,30,1,30,5,30,511,8,30,10,30,12,30,
  	514,9,30,1,30,1,30,1,31,1,31,1,31,1,31,1,31,3,31,523,8,31,1,32,1,32,1,
  	32,1,32,1,33,1,33,3,33,531,8,33,1,34,1,34,1,34,5,34,536,8,34,10,34,12,
  	34,539,9,34,1,34,3,34,542,8,34,1,35,1,35,1,35,1,35,1,35,3,35,549,8,35,
  	1,35,1,35,1,35,1,35,1,35,5,35,556,8,35,10,35,12,35,559,9,35,1,36,1,36,
  	1,36,1,36,1,36,5,36,566,8,36,10,36,12,36,569,9,36,1,36,1,36,1,36,1,37,
  	1,37,1,37,0,3,40,44,70,38,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,0,2,
  	2,0,36,36,57,57,2,0,19,20,22,26,642,0,83,1,0,0,0,2,85,1,0,0,0,4,96,1,
  	0,0,0,6,112,1,0,0,0,8,114,1,0,0,0,10,123,1,0,0,0,12,126,1,0,0,0,14,146,
  	1,0,0,0,16,157,1,0,0,0,18,173,1,0,0,0,20,176,1,0,0,0,22,199,1,0,0,0,24,
  	215,1,0,0,0,26,221,1,0,0,0,28,223,1,0,0,0,30,241,1,0,0,0,32,243,1,0,0,
  	0,34,248,1,0,0,0,36,267,1,0,0,0,38,274,1,0,0,0,40,289,1,0,0,0,42,299,
  	1,0,0,0,44,403,1,0,0,0,46,472,1,0,0,0,48,474,1,0,0,0,50,479,1,0,0,0,52,
  	484,1,0,0,0,54,490,1,0,0,0,56,492,1,0,0,0,58,503,1,0,0,0,60,505,1,0,0,
  	0,62,522,1,0,0,0,64,524,1,0,0,0,66,530,1,0,0,0,68,541,1,0,0,0,70,548,
  	1,0,0,0,72,560,1,0,0,0,74,573,1,0,0,0,76,78,3,4,2,0,77,76,1,0,0,0,78,
  	81,1,0,0,0,79,77,1,0,0,0,79,80,1,0,0,0,80,84,1,0,0,0,81,79,1,0,0,0,82,
  	84,5,0,0,1,83,79,1,0,0,0,83,82,1,0,0,0,84,1,1,0,0,0,85,86,7,0,0,0,86,
  	3,1,0,0,0,87,89,3,6,3,0,88,90,5,36,0,0,89,88,1,0,0,0,89,90,1,0,0,0,90,
  	92,1,0,0,0,91,93,5,57,0,0,92,91,1,0,0,0,92,93,1,0,0,0,93,97,1,0,0,0,94,
  	97,5,36,0,0,95,97,5,57,0,0,96,87,1,0,0,0,96,94,1,0,0,0,96,95,1,0,0,0,
  	97,5,1,0,0,0,98,113,3,10,5,0,99,113,3,12,6,0,100,113,3,34,17,0,101,113,
  	3,20,10,0,102,113,3,14,7,0,103,113,3,22,11,0,104,113,3,24,12,0,105,113,
  	3,30,15,0,106,113,3,32,16,0,107,113,3,26,13,0,108,113,3,28,14,0,109,113,
  	3,36,18,0,110,113,3,44,22,0,111,113,3,8,4,0,112,98,1,0,0,0,112,99,1,0,
  	0,0,112,100,1,0,0,0,112,101,1,0,0,0,112,102,1,0,0,0,112,103,1,0,0,0,112,
  	104,1,0,0,0,112,105,1,0,0,0,112,106,1,0,0,0,112,107,1,0,0,0,112,108,1,
  	0,0,0,112,109,1,0,0,0,112,110,1,0,0,0,112,111,1,0,0,0,113,7,1,0,0,0,114,
  	118,5,33,0,0,115,117,3,4,2,0,116,115,1,0,0,0,117,120,1,0,0,0,118,116,
  	1,0,0,0,118,119,1,0,0,0,119,121,1,0,0,0,120,118,1,0,0,0,121,122,5,34,
  	0,0,122,9,1,0,0,0,123,124,5,12,0,0,124,125,3,46,23,0,125,11,1,0,0,0,126,
  	127,5,11,0,0,127,128,3,46,23,0,128,13,1,0,0,0,129,130,5,1,0,0,130,131,
  	3,46,23,0,131,132,5,35,0,0,132,133,3,70,35,0,133,147,1,0,0,0,134,135,
  	5,1,0,0,135,136,3,46,23,0,136,137,5,39,0,0,137,138,3,44,22,0,138,147,
  	1,0,0,0,139,140,5,1,0,0,140,141,3,46,23,0,141,142,5,35,0,0,142,143,3,
  	70,35,0,143,144,5,39,0,0,144,145,3,44,22,0,145,147,1,0,0,0,146,129,1,
  	0,0,0,146,134,1,0,0,0,146,139,1,0,0,0,147,15,1,0,0,0,148,149,3,44,22,
  	0,149,150,5,37,0,0,150,152,1,0,0,0,151,148,1,0,0,0,152,155,1,0,0,0,153,
  	151,1,0,0,0,153,154,1,0,0,0,154,156,1,0,0,0,155,153,1,0,0,0,156,158,3,
  	44,22,0,157,153,1,0,0,0,157,158,1,0,0,0,158,17,1,0,0,0,159,160,3,46,23,
  	0,160,161,5,35,0,0,161,162,3,70,35,0,162,163,5,37,0,0,163,165,1,0,0,0,
  	164,159,1,0,0,0,165,168,1,0,0,0,166,164,1,0,0,0,166,167,1,0,0,0,167,169,
  	1,0,0,0,168,166,1,0,0,0,169,170,3,46,23,0,170,171,5,35,0,0,171,172,3,
  	70,35,0,172,174,1,0,0,0,173,166,1,0,0,0,173,174,1,0,0,0,174,19,1,0,0,
  	0,175,177,3,72,36,0,176,175,1,0,0,0,176,177,1,0,0,0,177,179,1,0,0,0,178,
  	180,3,60,30,0,179,178,1,0,0,0,179,180,1,0,0,0,180,182,1,0,0,0,181,183,
  	5,57,0,0,182,181,1,0,0,0,182,183,1,0,0,0,183,184,1,0,0,0,184,185,3,50,
  	25,0,185,186,5,9,0,0,186,187,3,46,23,0,187,188,5,29,0,0,188,189,3,18,
  	9,0,189,193,5,30,0,0,190,191,5,46,0,0,191,192,5,40,0,0,192,194,3,70,35,
  	0,193,190,1,0,0,0,193,194,1,0,0,0,194,197,1,0,0,0,195,198,3,8,4,0,196,
  	198,5,36,0,0,197,195,1,0,0,0,197,196,1,0,0,0,198,21,1,0,0,0,199,200,5,
  	3,0,0,200,202,5,29,0,0,201,203,3,6,3,0,202,201,1,0,0,0,202,203,1,0,0,
  	0,203,204,1,0,0,0,204,206,5,36,0,0,205,207,3,6,3,0,206,205,1,0,0,0,206,
  	207,1,0,0,0,207,208,1,0,0,0,208,210,5,36,0,0,209,211,3,6,3,0,210,209,
  	1,0,0,0,210,211,1,0,0,0,211,212,1,0,0,0,212,213,5,30,0,0,213,214,3,4,
  	2,0,214,23,1,0,0,0,215,216,5,4,0,0,216,217,5,29,0,0,217,218,3,44,22,0,
  	218,219,5,30,0,0,219,220,3,4,2,0,220,25,1,0,0,0,221,222,5,5,0,0,222,27,
  	1,0,0,0,223,224,5,6,0,0,224,29,1,0,0,0,225,226,5,7,0,0,226,227,5,29,0,
  	0,227,228,3,44,22,0,228,229,5,30,0,0,229,230,3,4,2,0,230,231,6,15,-1,
  	0,231,242,1,0,0,0,232,233,5,7,0,0,233,234,5,29,0,0,234,235,3,44,22,0,
  	235,236,5,30,0,0,236,237,3,4,2,0,237,238,5,8,0,0,238,239,3,4,2,0,239,
  	240,6,15,-1,0,240,242,1,0,0,0,241,225,1,0,0,0,241,232,1,0,0,0,242,31,
  	1,0,0,0,243,245,5,10,0,0,244,246,3,6,3,0,245,244,1,0,0,0,245,246,1,0,
  	0,0,246,33,1,0,0,0,247,249,3,72,36,0,248,247,1,0,0,0,248,249,1,0,0,0,
  	249,251,1,0,0,0,250,252,5,57,0,0,251,250,1,0,0,0,251,252,1,0,0,0,252,
  	254,1,0,0,0,253,255,3,60,30,0,254,253,1,0,0,0,254,255,1,0,0,0,255,257,
  	1,0,0,0,256,258,5,57,0,0,257,256,1,0,0,0,257,258,1,0,0,0,258,259,1,0,
  	0,0,259,260,5,13,0,0,260,263,3,46,23,0,261,262,5,35,0,0,262,264,3,46,
  	23,0,263,261,1,0,0,0,263,264,1,0,0,0,264,265,1,0,0,0,265,266,3,8,4,0,
  	266,35,1,0,0,0,267,268,5,17,0,0,268,270,3,8,4,0,269,271,3,2,1,0,270,269,
  	1,0,0,0,270,271,1,0,0,0,271,272,1,0,0,0,272,273,3,38,19,0,273,37,1,0,
  	0,0,274,275,5,18,0,0,275,276,5,29,0,0,276,277,3,14,7,0,277,278,5,30,0,
  	0,278,39,1,0,0,0,279,280,6,20,-1,0,280,282,3,46,23,0,281,283,3,64,32,
  	0,282,281,1,0,0,0,282,283,1,0,0,0,283,284,1,0,0,0,284,285,5,29,0,0,285,
  	286,3,16,8,0,286,287,5,30,0,0,287,290,1,0,0,0,288,290,3,46,23,0,289,279,
  	1,0,0,0,289,288,1,0,0,0,290,296,1,0,0,0,291,292,10,1,0,0,292,293,5,54,
  	0,0,293,295,3,40,20,2,294,291,1,0,0,0,295,298,1,0,0,0,296,294,1,0,0,0,
  	296,297,1,0,0,0,297,41,1,0,0,0,298,296,1,0,0,0,299,300,3,40,20,0,300,
  	43,1,0,0,0,301,302,6,22,-1,0,302,303,5,41,0,0,303,304,3,70,35,0,304,305,
  	5,40,0,0,305,306,5,29,0,0,306,307,3,42,21,0,307,308,5,30,0,0,308,404,
  	1,0,0,0,309,310,5,29,0,0,310,311,3,44,22,0,311,312,5,30,0,0,312,404,1,
  	0,0,0,313,314,5,50,0,0,314,404,3,44,22,45,315,316,5,45,0,0,316,404,3,
  	44,22,44,317,318,5,46,0,0,318,404,3,44,22,43,319,320,5,45,0,0,320,321,
  	5,45,0,0,321,404,3,42,21,0,322,323,3,42,21,0,323,324,5,45,0,0,324,325,
  	5,45,0,0,325,404,1,0,0,0,326,327,5,46,0,0,327,328,5,46,0,0,328,404,3,
  	42,21,0,329,330,3,42,21,0,330,331,5,46,0,0,331,332,5,46,0,0,332,404,1,
  	0,0,0,333,404,3,40,20,0,334,335,3,42,21,0,335,336,5,39,0,0,336,337,3,
  	44,22,18,337,404,1,0,0,0,338,339,3,42,21,0,339,340,5,45,0,0,340,341,5,
  	39,0,0,341,342,3,44,22,17,342,404,1,0,0,0,343,344,3,42,21,0,344,345,5,
  	46,0,0,345,346,5,39,0,0,346,347,3,44,22,16,347,404,1,0,0,0,348,349,3,
  	42,21,0,349,350,5,47,0,0,350,351,5,39,0,0,351,352,3,44,22,15,352,404,
  	1,0,0,0,353,354,3,42,21,0,354,355,5,48,0,0,355,356,5,39,0,0,356,357,3,
  	44,22,14,357,404,1,0,0,0,358,359,3,42,21,0,359,360,5,49,0,0,360,361,5,
  	39,0,0,361,362,3,44,22,13,362,404,1,0,0,0,363,364,3,42,21,0,364,365,5,
  	45,0,0,365,366,5,39,0,0,366,367,3,44,22,12,367,404,1,0,0,0,368,369,3,
  	42,21,0,369,370,5,51,0,0,370,371,5,39,0,0,371,372,3,44,22,11,372,404,
  	1,0,0,0,373,374,3,42,21,0,374,375,5,52,0,0,375,376,5,39,0,0,376,377,3,
  	44,22,10,377,404,1,0,0,0,378,379,3,42,21,0,379,380,5,53,0,0,380,381,5,
  	39,0,0,381,382,3,44,22,9,382,404,1,0,0,0,383,384,3,42,21,0,384,385,5,
  	42,0,0,385,386,5,39,0,0,386,387,3,44,22,8,387,404,1,0,0,0,388,389,3,42,
  	21,0,389,390,5,43,0,0,390,391,5,39,0,0,391,392,3,44,22,7,392,404,1,0,
  	0,0,393,394,3,42,21,0,394,395,5,44,0,0,395,396,5,39,0,0,396,397,3,44,
  	22,6,397,404,1,0,0,0,398,404,5,69,0,0,399,404,5,70,0,0,400,404,3,52,26,
  	0,401,404,3,54,27,0,402,404,5,16,0,0,403,301,1,0,0,0,403,309,1,0,0,0,
  	403,313,1,0,0,0,403,315,1,0,0,0,403,317,1,0,0,0,403,319,1,0,0,0,403,322,
  	1,0,0,0,403,326,1,0,0,0,403,329,1,0,0,0,403,333,1,0,0,0,403,334,1,0,0,
  	0,403,338,1,0,0,0,403,343,1,0,0,0,403,348,1,0,0,0,403,353,1,0,0,0,403,
  	358,1,0,0,0,403,363,1,0,0,0,403,368,1,0,0,0,403,373,1,0,0,0,403,378,1,
  	0,0,0,403,383,1,0,0,0,403,388,1,0,0,0,403,393,1,0,0,0,403,398,1,0,0,0,
  	403,399,1,0,0,0,403,400,1,0,0,0,403,401,1,0,0,0,403,402,1,0,0,0,404,469,
  	1,0,0,0,405,406,10,37,0,0,406,407,5,47,0,0,407,468,3,44,22,38,408,409,
  	10,36,0,0,409,410,5,48,0,0,410,468,3,44,22,37,411,412,10,35,0,0,412,413,
  	5,49,0,0,413,468,3,44,22,36,414,415,10,34,0,0,415,416,5,45,0,0,416,468,
  	3,44,22,35,417,418,10,33,0,0,418,419,5,46,0,0,419,468,3,44,22,34,420,
  	421,10,32,0,0,421,422,5,42,0,0,422,468,3,44,22,33,423,424,10,31,0,0,424,
  	425,5,43,0,0,425,468,3,44,22,32,426,427,10,30,0,0,427,428,5,44,0,0,428,
  	468,3,44,22,31,429,430,10,29,0,0,430,431,5,40,0,0,431,468,3,44,22,30,
  	432,433,10,28,0,0,433,434,5,41,0,0,434,468,3,44,22,29,435,436,10,27,0,
  	0,436,437,5,40,0,0,437,438,5,39,0,0,438,468,3,44,22,28,439,440,10,26,
  	0,0,440,441,5,41,0,0,441,442,5,39,0,0,442,468,3,44,22,27,443,444,10,25,
  	0,0,444,445,5,38,0,0,445,468,3,44,22,26,446,447,10,24,0,0,447,448,5,50,
  	0,0,448,449,5,39,0,0,449,468,3,44,22,25,450,451,10,23,0,0,451,452,5,51,
  	0,0,452,468,3,44,22,24,453,454,10,22,0,0,454,455,5,53,0,0,455,468,3,44,
  	22,23,456,457,10,21,0,0,457,458,5,52,0,0,458,468,3,44,22,22,459,460,10,
  	20,0,0,460,461,5,51,0,0,461,462,5,51,0,0,462,468,3,44,22,21,463,464,10,
  	19,0,0,464,465,5,52,0,0,465,466,5,52,0,0,466,468,3,44,22,20,467,405,1,
  	0,0,0,467,408,1,0,0,0,467,411,1,0,0,0,467,414,1,0,0,0,467,417,1,0,0,0,
  	467,420,1,0,0,0,467,423,1,0,0,0,467,426,1,0,0,0,467,429,1,0,0,0,467,432,
  	1,0,0,0,467,435,1,0,0,0,467,439,1,0,0,0,467,443,1,0,0,0,467,446,1,0,0,
  	0,467,450,1,0,0,0,467,453,1,0,0,0,467,456,1,0,0,0,467,459,1,0,0,0,467,
  	463,1,0,0,0,468,471,1,0,0,0,469,467,1,0,0,0,469,470,1,0,0,0,470,45,1,
  	0,0,0,471,469,1,0,0,0,472,473,5,58,0,0,473,47,1,0,0,0,474,475,7,1,0,0,
  	475,49,1,0,0,0,476,478,3,48,24,0,477,476,1,0,0,0,478,481,1,0,0,0,479,
  	477,1,0,0,0,479,480,1,0,0,0,480,51,1,0,0,0,481,479,1,0,0,0,482,485,3,
  	58,29,0,483,485,3,56,28,0,484,482,1,0,0,0,484,483,1,0,0,0,485,53,1,0,
  	0,0,486,487,5,14,0,0,487,491,6,27,-1,0,488,489,5,15,0,0,489,491,6,27,
  	-1,0,490,486,1,0,0,0,490,488,1,0,0,0,491,55,1,0,0,0,492,493,5,63,0,0,
  	493,494,6,28,-1,0,494,57,1,0,0,0,495,496,5,60,0,0,496,504,6,29,-1,0,497,
  	498,5,59,0,0,498,504,6,29,-1,0,499,500,5,62,0,0,500,504,6,29,-1,0,501,
  	502,5,61,0,0,502,504,6,29,-1,0,503,495,1,0,0,0,503,497,1,0,0,0,503,499,
  	1,0,0,0,503,501,1,0,0,0,504,59,1,0,0,0,505,506,5,27,0,0,506,507,5,41,
  	0,0,507,512,3,62,31,0,508,509,5,37,0,0,509,511,3,62,31,0,510,508,1,0,
  	0,0,511,514,1,0,0,0,512,510,1,0,0,0,512,513,1,0,0,0,513,515,1,0,0,0,514,
  	512,1,0,0,0,515,516,5,40,0,0,516,61,1,0,0,0,517,518,5,28,0,0,518,523,
  	3,46,23,0,519,520,3,70,35,0,520,521,3,46,23,0,521,523,1,0,0,0,522,517,
  	1,0,0,0,522,519,1,0,0,0,523,63,1,0,0,0,524,525,5,41,0,0,525,526,3,68,
  	34,0,526,527,5,40,0,0,527,65,1,0,0,0,528,531,3,44,22,0,529,531,3,70,35,
  	0,530,528,1,0,0,0,530,529,1,0,0,0,531,67,1,0,0,0,532,533,3,66,33,0,533,
  	534,5,37,0,0,534,536,1,0,0,0,535,532,1,0,0,0,536,539,1,0,0,0,537,535,
  	1,0,0,0,537,538,1,0,0,0,538,540,1,0,0,0,539,537,1,0,0,0,540,542,3,66,
  	33,0,541,537,1,0,0,0,541,542,1,0,0,0,542,69,1,0,0,0,543,544,6,35,-1,0,
  	544,549,3,40,20,0,545,546,3,40,20,0,546,547,3,64,32,0,547,549,1,0,0,0,
  	548,543,1,0,0,0,548,545,1,0,0,0,549,557,1,0,0,0,550,551,10,1,0,0,551,
  	552,5,31,0,0,552,553,3,44,22,0,553,554,5,32,0,0,554,556,1,0,0,0,555,550,
  	1,0,0,0,556,559,1,0,0,0,557,555,1,0,0,0,557,558,1,0,0,0,558,71,1,0,0,
  	0,559,557,1,0,0,0,560,561,5,31,0,0,561,562,5,31,0,0,562,567,3,74,37,0,
  	563,564,5,37,0,0,564,566,3,74,37,0,565,563,1,0,0,0,566,569,1,0,0,0,567,
  	565,1,0,0,0,567,568,1,0,0,0,568,570,1,0,0,0,569,567,1,0,0,0,570,571,5,
  	32,0,0,571,572,5,32,0,0,572,73,1,0,0,0,573,574,5,58,0,0,574,75,1,0,0,
  	0,46,79,83,89,92,96,112,118,146,153,157,166,173,176,179,182,193,197,202,
  	206,210,241,245,248,251,254,257,263,270,282,289,296,403,467,469,479,484,
  	490,503,512,522,530,537,541,548,557,567
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
    setState(83);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(79);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & -142881455769649414) != 0) || _la == RiddleParser::STRING

      || _la == RiddleParser::CHAR) {
        setState(76);
        statement_ed();
        setState(81);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(82);
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
    setState(85);
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
    setState(96);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(87);
      statement();
      setState(89);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(88);
        match(RiddleParser::Semi);
        break;
      }

      default:
        break;
      }
      setState(92);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
      case 1: {
        setState(91);
        match(RiddleParser::Endl);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(94);
      match(RiddleParser::Semi);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(95);
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
    setState(112);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(98);
      packStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(99);
      importStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(100);
      classDefine();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(101);
      funcDefine();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(102);
      varDefineStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(103);
      forStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(104);
      whileStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(105);
      ifStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(106);
      returnStatement();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(107);
      continueStatement();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(108);
      breakStatement();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(109);
      tryExpr();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(110);
      expression(0);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(111);
      bodyExpr();
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
    setState(114);
    match(RiddleParser::LeftCurly);
    setState(118);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -142881455769649414) != 0) || _la == RiddleParser::STRING

    || _la == RiddleParser::CHAR) {
      setState(115);
      statement_ed();
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(121);
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
    setState(123);
    match(RiddleParser::Package);
    setState(124);
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
    setState(126);
    match(RiddleParser::Import);
    setState(127);
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

RiddleParser::IdContext* RiddleParser::VarDefineStatementContext::id() {
  return getRuleContext<RiddleParser::IdContext>(0);
}

RiddleParser::TypeUsedContext* RiddleParser::VarDefineStatementContext::typeUsed() {
  return getRuleContext<RiddleParser::TypeUsedContext>(0);
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
    setState(146);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(129);
      match(RiddleParser::Var);
      setState(130);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->name = id();
      setState(131);
      match(RiddleParser::Colon);
      setState(132);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->type = typeUsed(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(134);
      match(RiddleParser::Var);
      setState(135);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->name = id();
      setState(136);
      match(RiddleParser::Assign);
      setState(137);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->value = expression(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(139);
      match(RiddleParser::Var);
      setState(140);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->name = id();
      setState(141);
      match(RiddleParser::Colon);
      setState(142);
      antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->type = typeUsed(0);
      setState(143);
      match(RiddleParser::Assign);
      setState(144);
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
    setState(157);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 14) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 14)) & 109194774073868295) != 0)) {
      setState(153);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(148);
          expression(0);
          setState(149);
          match(RiddleParser::Comma); 
        }
        setState(155);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      }
      setState(156);
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

std::vector<RiddleParser::IdContext *> RiddleParser::DefineArgsContext::id() {
  return getRuleContexts<RiddleParser::IdContext>();
}

RiddleParser::IdContext* RiddleParser::DefineArgsContext::id(size_t i) {
  return getRuleContext<RiddleParser::IdContext>(i);
}

std::vector<tree::TerminalNode *> RiddleParser::DefineArgsContext::Colon() {
  return getTokens(RiddleParser::Colon);
}

tree::TerminalNode* RiddleParser::DefineArgsContext::Colon(size_t i) {
  return getToken(RiddleParser::Colon, i);
}

std::vector<RiddleParser::TypeUsedContext *> RiddleParser::DefineArgsContext::typeUsed() {
  return getRuleContexts<RiddleParser::TypeUsedContext>();
}

RiddleParser::TypeUsedContext* RiddleParser::DefineArgsContext::typeUsed(size_t i) {
  return getRuleContext<RiddleParser::TypeUsedContext>(i);
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
    setState(173);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Identifier) {
      setState(166);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(159);
          id();
          setState(160);
          match(RiddleParser::Colon);
          setState(161);
          typeUsed(0);
          setState(162);
          match(RiddleParser::Comma); 
        }
        setState(168);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
      }

      setState(169);
      id();
      setState(170);
      match(RiddleParser::Colon);
      setState(171);
      typeUsed(0);
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

RiddleParser::ModifierListContext* RiddleParser::FuncDefineContext::modifierList() {
  return getRuleContext<RiddleParser::ModifierListContext>(0);
}

RiddleParser::IdContext* RiddleParser::FuncDefineContext::id() {
  return getRuleContext<RiddleParser::IdContext>(0);
}

RiddleParser::DefineArgsContext* RiddleParser::FuncDefineContext::defineArgs() {
  return getRuleContext<RiddleParser::DefineArgsContext>(0);
}

tree::TerminalNode* RiddleParser::FuncDefineContext::Semi() {
  return getToken(RiddleParser::Semi, 0);
}

tree::TerminalNode* RiddleParser::FuncDefineContext::Endl() {
  return getToken(RiddleParser::Endl, 0);
}

tree::TerminalNode* RiddleParser::FuncDefineContext::Sub() {
  return getToken(RiddleParser::Sub, 0);
}

tree::TerminalNode* RiddleParser::FuncDefineContext::Greater() {
  return getToken(RiddleParser::Greater, 0);
}

RiddleParser::PropertyContext* RiddleParser::FuncDefineContext::property() {
  return getRuleContext<RiddleParser::PropertyContext>(0);
}

RiddleParser::TmpleDefineContext* RiddleParser::FuncDefineContext::tmpleDefine() {
  return getRuleContext<RiddleParser::TmpleDefineContext>(0);
}

RiddleParser::TypeUsedContext* RiddleParser::FuncDefineContext::typeUsed() {
  return getRuleContext<RiddleParser::TypeUsedContext>(0);
}

RiddleParser::BodyExprContext* RiddleParser::FuncDefineContext::bodyExpr() {
  return getRuleContext<RiddleParser::BodyExprContext>(0);
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
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::LeftSquare) {
      setState(175);
      antlrcpp::downCast<FuncDefineContext *>(_localctx)->prop = property();
    }
    setState(179);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Template) {
      setState(178);
      antlrcpp::downCast<FuncDefineContext *>(_localctx)->tmpl = tmpleDefine();
    }
    setState(182);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Endl) {
      setState(181);
      match(RiddleParser::Endl);
    }
    setState(184);
    antlrcpp::downCast<FuncDefineContext *>(_localctx)->mod = modifierList();
    setState(185);
    match(RiddleParser::Func);
    setState(186);
    antlrcpp::downCast<FuncDefineContext *>(_localctx)->funcName = id();
    setState(187);
    match(RiddleParser::LeftBracket);
    setState(188);
    antlrcpp::downCast<FuncDefineContext *>(_localctx)->args = defineArgs();
    setState(189);
    match(RiddleParser::RightBracket);
    setState(193);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Sub) {
      setState(190);
      match(RiddleParser::Sub);
      setState(191);
      match(RiddleParser::Greater);
      setState(192);
      antlrcpp::downCast<FuncDefineContext *>(_localctx)->returnType = typeUsed(0);
    }
    setState(197);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RiddleParser::LeftCurly: {
        setState(195);
        antlrcpp::downCast<FuncDefineContext *>(_localctx)->body = bodyExpr();
        break;
      }

      case RiddleParser::Semi: {
        setState(196);
        match(RiddleParser::Semi);
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
    setState(199);
    match(RiddleParser::For);
    setState(200);
    match(RiddleParser::LeftBracket);
    setState(202);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -142881524489126150) != 0) || _la == RiddleParser::STRING

    || _la == RiddleParser::CHAR) {
      setState(201);
      antlrcpp::downCast<ForStatementContext *>(_localctx)->init = statement();
    }
    setState(204);
    match(RiddleParser::Semi);
    setState(206);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -142881524489126150) != 0) || _la == RiddleParser::STRING

    || _la == RiddleParser::CHAR) {
      setState(205);
      antlrcpp::downCast<ForStatementContext *>(_localctx)->cond = statement();
    }
    setState(208);
    match(RiddleParser::Semi);
    setState(210);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -142881524489126150) != 0) || _la == RiddleParser::STRING

    || _la == RiddleParser::CHAR) {
      setState(209);
      antlrcpp::downCast<ForStatementContext *>(_localctx)->incr = statement();
    }
    setState(212);
    match(RiddleParser::RightBracket);
    setState(213);
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
    setState(215);
    match(RiddleParser::While);
    setState(216);
    match(RiddleParser::LeftBracket);
    setState(217);
    antlrcpp::downCast<WhileStatementContext *>(_localctx)->cond = expression(0);
    setState(218);
    match(RiddleParser::RightBracket);
    setState(219);
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
    setState(221);
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
    setState(223);
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
    setState(241);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(225);
      match(RiddleParser::If);
      setState(226);
      match(RiddleParser::LeftBracket);
      setState(227);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->cond = expression(0);
      setState(228);
      match(RiddleParser::RightBracket);
      setState(229);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->body = statement_ed();
      antlrcpp::downCast<IfStatementContext *>(_localctx)->hasElse = false;
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(232);
      match(RiddleParser::If);
      setState(233);
      match(RiddleParser::LeftBracket);
      setState(234);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->cond = expression(0);
      setState(235);
      match(RiddleParser::RightBracket);
      setState(236);
      antlrcpp::downCast<IfStatementContext *>(_localctx)->body = statement_ed();
      setState(237);
      match(RiddleParser::Else);
      setState(238);
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
    setState(243);
    match(RiddleParser::Return);
    setState(245);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(244);
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

std::vector<tree::TerminalNode *> RiddleParser::ClassDefineContext::Endl() {
  return getTokens(RiddleParser::Endl);
}

tree::TerminalNode* RiddleParser::ClassDefineContext::Endl(size_t i) {
  return getToken(RiddleParser::Endl, i);
}

tree::TerminalNode* RiddleParser::ClassDefineContext::Colon() {
  return getToken(RiddleParser::Colon, 0);
}

RiddleParser::PropertyContext* RiddleParser::ClassDefineContext::property() {
  return getRuleContext<RiddleParser::PropertyContext>(0);
}

RiddleParser::TmpleDefineContext* RiddleParser::ClassDefineContext::tmpleDefine() {
  return getRuleContext<RiddleParser::TmpleDefineContext>(0);
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
    setState(248);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::LeftSquare) {
      setState(247);
      antlrcpp::downCast<ClassDefineContext *>(_localctx)->prop = property();
    }
    setState(251);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(250);
      match(RiddleParser::Endl);
      break;
    }

    default:
      break;
    }
    setState(254);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Template) {
      setState(253);
      antlrcpp::downCast<ClassDefineContext *>(_localctx)->tmpl = tmpleDefine();
    }
    setState(257);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Endl) {
      setState(256);
      match(RiddleParser::Endl);
    }
    setState(259);
    match(RiddleParser::Class);
    setState(260);
    antlrcpp::downCast<ClassDefineContext *>(_localctx)->className = id();
    setState(263);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Colon) {
      setState(261);
      match(RiddleParser::Colon);
      setState(262);
      antlrcpp::downCast<ClassDefineContext *>(_localctx)->parentClass = id();
    }
    setState(265);
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
    setState(267);
    match(RiddleParser::Try);
    setState(268);
    antlrcpp::downCast<TryExprContext *>(_localctx)->tryBody = bodyExpr();
    setState(270);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RiddleParser::Semi

    || _la == RiddleParser::Endl) {
      setState(269);
      null_cnt();
    }
    setState(272);
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
    setState(274);
    match(RiddleParser::Catch);
    setState(275);
    match(RiddleParser::LeftBracket);
    setState(276);
    varDefineStatement();
    setState(277);
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

RiddleParser::IdContext* RiddleParser::FuncExprContext::id() {
  return getRuleContext<RiddleParser::IdContext>(0);
}

RiddleParser::ArgsExprContext* RiddleParser::FuncExprContext::argsExpr() {
  return getRuleContext<RiddleParser::ArgsExprContext>(0);
}

RiddleParser::TmplUsedContext* RiddleParser::FuncExprContext::tmplUsed() {
  return getRuleContext<RiddleParser::TmplUsedContext>(0);
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

RiddleParser::IdContext* RiddleParser::ObjectExprContext::id() {
  return getRuleContext<RiddleParser::IdContext>(0);
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

    size_t _la = 0;

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
    setState(289);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<FuncExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(280);
      antlrcpp::downCast<FuncExprContext *>(_localctx)->funcName = id();
      setState(282);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == RiddleParser::Less) {
        setState(281);
        antlrcpp::downCast<FuncExprContext *>(_localctx)->tmpl = tmplUsed();
      }
      setState(284);
      match(RiddleParser::LeftBracket);
      setState(285);
      antlrcpp::downCast<FuncExprContext *>(_localctx)->args = argsExpr();
      setState(286);
      match(RiddleParser::RightBracket);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ObjectExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(288);
      id();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(296);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<BlendExprContext>(_tracker.createInstance<ExprPtrContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->parentNode = previousContext;
        pushNewRecursionContext(newContext, startState, RuleExprPtr);
        setState(291);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(292);
        match(RiddleParser::Dot);
        setState(293);
        antlrcpp::downCast<BlendExprContext *>(_localctx)->childNode = exprPtr(2); 
      }
      setState(298);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
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
    setState(299);
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

RiddleParser::TypeUsedContext* RiddleParser::CastExprContext::typeUsed() {
  return getRuleContext<RiddleParser::TypeUsedContext>(0);
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

tree::TerminalNode* RiddleParser::StringExprContext::STRING() {
  return getToken(RiddleParser::STRING, 0);
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
//----------------- CharExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::CharExprContext::CHAR() {
  return getToken(RiddleParser::CHAR, 0);
}

RiddleParser::CharExprContext::CharExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::CharExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharExpr(this);
}
void RiddleParser::CharExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharExpr(this);
}

std::any RiddleParser::CharExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitCharExpr(this);
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
    setState(403);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CastExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(302);
      match(RiddleParser::Less);
      setState(303);
      antlrcpp::downCast<CastExprContext *>(_localctx)->type = typeUsed(0);
      setState(304);
      match(RiddleParser::Greater);
      setState(305);
      match(RiddleParser::LeftBracket);
      setState(306);
      antlrcpp::downCast<CastExprContext *>(_localctx)->value = exprPtrParser();
      setState(307);
      match(RiddleParser::RightBracket);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<BracketExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(309);
      match(RiddleParser::LeftBracket);
      setState(310);
      antlrcpp::downCast<BracketExprContext *>(_localctx)->expr = expression(0);
      setState(311);
      match(RiddleParser::RightBracket);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(313);
      match(RiddleParser::Not);
      setState(314);
      antlrcpp::downCast<NotExprContext *>(_localctx)->expr = expression(45);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<PositiveExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(315);
      match(RiddleParser::Add);
      setState(316);
      antlrcpp::downCast<PositiveExprContext *>(_localctx)->expr = expression(44);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NegativeExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(317);
      match(RiddleParser::Sub);
      setState(318);
      antlrcpp::downCast<NegativeExprContext *>(_localctx)->expr = expression(43);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<SelfAddLeftExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(319);
      match(RiddleParser::Add);
      setState(320);
      match(RiddleParser::Add);
      setState(321);
      antlrcpp::downCast<SelfAddLeftExprContext *>(_localctx)->expr = exprPtrParser();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<SelfAddRightExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(322);
      antlrcpp::downCast<SelfAddRightExprContext *>(_localctx)->expr = exprPtrParser();
      setState(323);
      match(RiddleParser::Add);
      setState(324);
      match(RiddleParser::Add);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<SelfSubLeftExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(326);
      match(RiddleParser::Sub);
      setState(327);
      match(RiddleParser::Sub);
      setState(328);
      antlrcpp::downCast<SelfSubLeftExprContext *>(_localctx)->expr = exprPtrParser();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<SelfSubRightExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(329);
      antlrcpp::downCast<SelfSubRightExprContext *>(_localctx)->expr = exprPtrParser();
      setState(330);
      match(RiddleParser::Sub);
      setState(331);
      match(RiddleParser::Sub);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<PtrExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(333);
      exprPtr(0);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<AssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(334);
      antlrcpp::downCast<AssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(335);
      match(RiddleParser::Assign);
      setState(336);
      antlrcpp::downCast<AssignExprContext *>(_localctx)->right = expression(18);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<AddAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(338);
      antlrcpp::downCast<AddAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(339);
      match(RiddleParser::Add);
      setState(340);
      match(RiddleParser::Assign);
      setState(341);
      antlrcpp::downCast<AddAssignExprContext *>(_localctx)->right = expression(17);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<SubAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(343);
      antlrcpp::downCast<SubAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(344);
      match(RiddleParser::Sub);
      setState(345);
      match(RiddleParser::Assign);
      setState(346);
      antlrcpp::downCast<SubAssignExprContext *>(_localctx)->right = expression(16);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<MulAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(348);
      antlrcpp::downCast<MulAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(349);
      match(RiddleParser::Star);
      setState(350);
      match(RiddleParser::Assign);
      setState(351);
      antlrcpp::downCast<MulAssignExprContext *>(_localctx)->right = expression(15);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<DivAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(353);
      antlrcpp::downCast<DivAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(354);
      match(RiddleParser::Div);
      setState(355);
      match(RiddleParser::Assign);
      setState(356);
      antlrcpp::downCast<DivAssignExprContext *>(_localctx)->right = expression(14);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<ModAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(358);
      antlrcpp::downCast<ModAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(359);
      match(RiddleParser::Mod);
      setState(360);
      match(RiddleParser::Assign);
      setState(361);
      antlrcpp::downCast<ModAssignExprContext *>(_localctx)->right = expression(13);
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<AddAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(363);
      antlrcpp::downCast<AddAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(364);
      match(RiddleParser::Add);
      setState(365);
      match(RiddleParser::Assign);
      setState(366);
      antlrcpp::downCast<AddAssignExprContext *>(_localctx)->right = expression(12);
      break;
    }

    case 18: {
      _localctx = _tracker.createInstance<AndAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(368);
      antlrcpp::downCast<AndAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(369);
      match(RiddleParser::And);
      setState(370);
      match(RiddleParser::Assign);
      setState(371);
      antlrcpp::downCast<AndAssignExprContext *>(_localctx)->right = expression(11);
      break;
    }

    case 19: {
      _localctx = _tracker.createInstance<OrAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(373);
      antlrcpp::downCast<OrAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(374);
      match(RiddleParser::Or);
      setState(375);
      match(RiddleParser::Assign);
      setState(376);
      antlrcpp::downCast<OrAssignExprContext *>(_localctx)->right = expression(10);
      break;
    }

    case 20: {
      _localctx = _tracker.createInstance<XorAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(378);
      antlrcpp::downCast<XorAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(379);
      match(RiddleParser::Xor);
      setState(380);
      match(RiddleParser::Assign);
      setState(381);
      antlrcpp::downCast<XorAssignExprContext *>(_localctx)->right = expression(9);
      break;
    }

    case 21: {
      _localctx = _tracker.createInstance<ShlAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(383);
      antlrcpp::downCast<ShlAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(384);
      match(RiddleParser::LeftLeft);
      setState(385);
      match(RiddleParser::Assign);
      setState(386);
      antlrcpp::downCast<ShlAssignExprContext *>(_localctx)->right = expression(8);
      break;
    }

    case 22: {
      _localctx = _tracker.createInstance<AShrAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(388);
      antlrcpp::downCast<AShrAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(389);
      match(RiddleParser::RightRight);
      setState(390);
      match(RiddleParser::Assign);
      setState(391);
      antlrcpp::downCast<AShrAssignExprContext *>(_localctx)->right = expression(7);
      break;
    }

    case 23: {
      _localctx = _tracker.createInstance<LShrAssignExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(393);
      antlrcpp::downCast<LShrAssignExprContext *>(_localctx)->left = exprPtrParser();
      setState(394);
      match(RiddleParser::RightRightRight);
      setState(395);
      match(RiddleParser::Assign);
      setState(396);
      antlrcpp::downCast<LShrAssignExprContext *>(_localctx)->right = expression(6);
      break;
    }

    case 24: {
      _localctx = _tracker.createInstance<StringExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(398);
      match(RiddleParser::STRING);
      break;
    }

    case 25: {
      _localctx = _tracker.createInstance<CharExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(399);
      match(RiddleParser::CHAR);
      break;
    }

    case 26: {
      _localctx = _tracker.createInstance<NumberExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(400);
      number();
      break;
    }

    case 27: {
      _localctx = _tracker.createInstance<BooleanExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(401);
      boolean();
      break;
    }

    case 28: {
      _localctx = _tracker.createInstance<NullExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(402);
      match(RiddleParser::Null);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(469);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(467);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(405);

          if (!(precpred(_ctx, 37))) throw FailedPredicateException(this, "precpred(_ctx, 37)");
          setState(406);
          match(RiddleParser::Star);
          setState(407);
          antlrcpp::downCast<MulExprContext *>(_localctx)->right = expression(38);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DivExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(408);

          if (!(precpred(_ctx, 36))) throw FailedPredicateException(this, "precpred(_ctx, 36)");
          setState(409);
          match(RiddleParser::Div);
          setState(410);
          antlrcpp::downCast<DivExprContext *>(_localctx)->right = expression(37);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ModExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(411);

          if (!(precpred(_ctx, 35))) throw FailedPredicateException(this, "precpred(_ctx, 35)");
          setState(412);
          match(RiddleParser::Mod);
          setState(413);
          antlrcpp::downCast<ModExprContext *>(_localctx)->right = expression(36);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AddExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(414);

          if (!(precpred(_ctx, 34))) throw FailedPredicateException(this, "precpred(_ctx, 34)");
          setState(415);
          match(RiddleParser::Add);
          setState(416);
          antlrcpp::downCast<AddExprContext *>(_localctx)->right = expression(35);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<SubExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(417);

          if (!(precpred(_ctx, 33))) throw FailedPredicateException(this, "precpred(_ctx, 33)");
          setState(418);
          match(RiddleParser::Sub);
          setState(419);
          antlrcpp::downCast<SubExprContext *>(_localctx)->right = expression(34);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ShlExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(420);

          if (!(precpred(_ctx, 32))) throw FailedPredicateException(this, "precpred(_ctx, 32)");
          setState(421);
          match(RiddleParser::LeftLeft);
          setState(422);
          antlrcpp::downCast<ShlExprContext *>(_localctx)->right = expression(33);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<AShrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(423);

          if (!(precpred(_ctx, 31))) throw FailedPredicateException(this, "precpred(_ctx, 31)");
          setState(424);
          match(RiddleParser::RightRight);
          setState(425);
          antlrcpp::downCast<AShrExprContext *>(_localctx)->right = expression(32);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<LShrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(426);

          if (!(precpred(_ctx, 30))) throw FailedPredicateException(this, "precpred(_ctx, 30)");
          setState(427);
          match(RiddleParser::RightRightRight);
          setState(428);
          antlrcpp::downCast<LShrExprContext *>(_localctx)->right = expression(31);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<GreaterExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(429);

          if (!(precpred(_ctx, 29))) throw FailedPredicateException(this, "precpred(_ctx, 29)");
          setState(430);
          match(RiddleParser::Greater);
          setState(431);
          antlrcpp::downCast<GreaterExprContext *>(_localctx)->right = expression(30);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LessExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(432);

          if (!(precpred(_ctx, 28))) throw FailedPredicateException(this, "precpred(_ctx, 28)");
          setState(433);
          match(RiddleParser::Less);
          setState(434);
          antlrcpp::downCast<LessExprContext *>(_localctx)->right = expression(29);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<GreaterEqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(435);

          if (!(precpred(_ctx, 27))) throw FailedPredicateException(this, "precpred(_ctx, 27)");
          setState(436);
          match(RiddleParser::Greater);
          setState(437);
          match(RiddleParser::Assign);
          setState(438);
          antlrcpp::downCast<GreaterEqualExprContext *>(_localctx)->right = expression(28);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<LessEqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(439);

          if (!(precpred(_ctx, 26))) throw FailedPredicateException(this, "precpred(_ctx, 26)");
          setState(440);
          match(RiddleParser::Less);
          setState(441);
          match(RiddleParser::Assign);
          setState(442);
          antlrcpp::downCast<LessEqualExprContext *>(_localctx)->right = expression(27);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<EqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(443);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(444);
          match(RiddleParser::Equal);
          setState(445);
          antlrcpp::downCast<EqualExprContext *>(_localctx)->right = expression(26);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<NotEqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(446);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(447);
          match(RiddleParser::Not);
          setState(448);
          match(RiddleParser::Assign);
          setState(449);
          antlrcpp::downCast<NotEqualExprContext *>(_localctx)->right = expression(25);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<BitAndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(450);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(451);
          match(RiddleParser::And);
          setState(452);
          antlrcpp::downCast<BitAndExprContext *>(_localctx)->right = expression(24);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<BitXorExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(453);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(454);
          match(RiddleParser::Xor);
          setState(455);
          antlrcpp::downCast<BitXorExprContext *>(_localctx)->right = expression(23);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<BitOrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(456);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(457);
          match(RiddleParser::Or);
          setState(458);
          antlrcpp::downCast<BitOrExprContext *>(_localctx)->right = expression(22);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(459);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(460);
          match(RiddleParser::And);
          setState(461);
          match(RiddleParser::And);
          setState(462);
          antlrcpp::downCast<AndExprContext *>(_localctx)->right = expression(21);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(463);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(464);
          match(RiddleParser::Or);
          setState(465);
          match(RiddleParser::Or);
          setState(466);
          antlrcpp::downCast<OrExprContext *>(_localctx)->right = expression(20);
          break;
        }

        default:
          break;
        } 
      }
      setState(471);
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
    setState(472);
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

tree::TerminalNode* RiddleParser::ModifierContext::Operator() {
  return getToken(RiddleParser::Operator, 0);
}

tree::TerminalNode* RiddleParser::ModifierContext::Virtual() {
  return getToken(RiddleParser::Virtual, 0);
}

tree::TerminalNode* RiddleParser::ModifierContext::Static() {
  return getToken(RiddleParser::Static, 0);
}

tree::TerminalNode* RiddleParser::ModifierContext::Override() {
  return getToken(RiddleParser::Override, 0);
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
    setState(474);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 131596288) != 0))) {
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
    setState(479);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 131596288) != 0)) {
      setState(476);
      modifier();
      setState(481);
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
    setState(484);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RiddleParser::Hexadecimal:
      case RiddleParser::Decimal:
      case RiddleParser::Octal:
      case RiddleParser::Binary: {
        enterOuterAlt(_localctx, 1);
        setState(482);
        integer();
        break;
      }

      case RiddleParser::Float: {
        enterOuterAlt(_localctx, 2);
        setState(483);
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
    setState(490);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RiddleParser::True: {
        enterOuterAlt(_localctx, 1);
        setState(486);
        match(RiddleParser::True);
        antlrcpp::downCast<BooleanContext *>(_localctx)->value = true;
        break;
      }

      case RiddleParser::False: {
        enterOuterAlt(_localctx, 2);
        setState(488);
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
  enterRule(_localctx, 56, RiddleParser::RuleFloat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(492);
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
  enterRule(_localctx, 58, RiddleParser::RuleInteger);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(503);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RiddleParser::Decimal: {
        enterOuterAlt(_localctx, 1);
        setState(495);
        antlrcpp::downCast<IntegerContext *>(_localctx)->decimalToken = match(RiddleParser::Decimal);

                antlrcpp::downCast<IntegerContext *>(_localctx)->value =  stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->decimalToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->decimalToken->getText() : ""));
            
        break;
      }

      case RiddleParser::Hexadecimal: {
        enterOuterAlt(_localctx, 2);
        setState(497);
        antlrcpp::downCast<IntegerContext *>(_localctx)->hexadecimalToken = match(RiddleParser::Hexadecimal);

                antlrcpp::downCast<IntegerContext *>(_localctx)->value =  stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->hexadecimalToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->hexadecimalToken->getText() : "").substr(2),nullptr,16);
            
        break;
      }

      case RiddleParser::Binary: {
        enterOuterAlt(_localctx, 3);
        setState(499);
        antlrcpp::downCast<IntegerContext *>(_localctx)->binaryToken = match(RiddleParser::Binary);

                antlrcpp::downCast<IntegerContext *>(_localctx)->value =  stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->binaryToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->binaryToken->getText() : "").substr(2),nullptr,2);
            
        break;
      }

      case RiddleParser::Octal: {
        enterOuterAlt(_localctx, 4);
        setState(501);
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

//----------------- TmpleDefineContext ------------------------------------------------------------------

RiddleParser::TmpleDefineContext::TmpleDefineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::TmpleDefineContext::Template() {
  return getToken(RiddleParser::Template, 0);
}

tree::TerminalNode* RiddleParser::TmpleDefineContext::Less() {
  return getToken(RiddleParser::Less, 0);
}

std::vector<RiddleParser::TmplDefineArgContext *> RiddleParser::TmpleDefineContext::tmplDefineArg() {
  return getRuleContexts<RiddleParser::TmplDefineArgContext>();
}

RiddleParser::TmplDefineArgContext* RiddleParser::TmpleDefineContext::tmplDefineArg(size_t i) {
  return getRuleContext<RiddleParser::TmplDefineArgContext>(i);
}

tree::TerminalNode* RiddleParser::TmpleDefineContext::Greater() {
  return getToken(RiddleParser::Greater, 0);
}

std::vector<tree::TerminalNode *> RiddleParser::TmpleDefineContext::Comma() {
  return getTokens(RiddleParser::Comma);
}

tree::TerminalNode* RiddleParser::TmpleDefineContext::Comma(size_t i) {
  return getToken(RiddleParser::Comma, i);
}


size_t RiddleParser::TmpleDefineContext::getRuleIndex() const {
  return RiddleParser::RuleTmpleDefine;
}

void RiddleParser::TmpleDefineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTmpleDefine(this);
}

void RiddleParser::TmpleDefineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTmpleDefine(this);
}


std::any RiddleParser::TmpleDefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitTmpleDefine(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::TmpleDefineContext* RiddleParser::tmpleDefine() {
  TmpleDefineContext *_localctx = _tracker.createInstance<TmpleDefineContext>(_ctx, getState());
  enterRule(_localctx, 60, RiddleParser::RuleTmpleDefine);
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
    setState(505);
    match(RiddleParser::Template);
    setState(506);
    match(RiddleParser::Less);
    setState(507);
    tmplDefineArg();
    setState(512);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == RiddleParser::Comma) {
      setState(508);
      match(RiddleParser::Comma);
      setState(509);
      tmplDefineArg();
      setState(514);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(515);
    match(RiddleParser::Greater);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TmplDefineArgContext ------------------------------------------------------------------

RiddleParser::TmplDefineArgContext::TmplDefineArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::TmplDefineArgContext::TypeName() {
  return getToken(RiddleParser::TypeName, 0);
}

RiddleParser::IdContext* RiddleParser::TmplDefineArgContext::id() {
  return getRuleContext<RiddleParser::IdContext>(0);
}

RiddleParser::TypeUsedContext* RiddleParser::TmplDefineArgContext::typeUsed() {
  return getRuleContext<RiddleParser::TypeUsedContext>(0);
}


size_t RiddleParser::TmplDefineArgContext::getRuleIndex() const {
  return RiddleParser::RuleTmplDefineArg;
}

void RiddleParser::TmplDefineArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTmplDefineArg(this);
}

void RiddleParser::TmplDefineArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTmplDefineArg(this);
}


std::any RiddleParser::TmplDefineArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitTmplDefineArg(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::TmplDefineArgContext* RiddleParser::tmplDefineArg() {
  TmplDefineArgContext *_localctx = _tracker.createInstance<TmplDefineArgContext>(_ctx, getState());
  enterRule(_localctx, 62, RiddleParser::RuleTmplDefineArg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(522);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RiddleParser::TypeName: {
        enterOuterAlt(_localctx, 1);
        setState(517);
        match(RiddleParser::TypeName);
        setState(518);
        antlrcpp::downCast<TmplDefineArgContext *>(_localctx)->name = id();
        break;
      }

      case RiddleParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(519);
        typeUsed(0);
        setState(520);
        antlrcpp::downCast<TmplDefineArgContext *>(_localctx)->name = id();
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

//----------------- TmplUsedContext ------------------------------------------------------------------

RiddleParser::TmplUsedContext::TmplUsedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::TmplUsedContext::Less() {
  return getToken(RiddleParser::Less, 0);
}

tree::TerminalNode* RiddleParser::TmplUsedContext::Greater() {
  return getToken(RiddleParser::Greater, 0);
}

RiddleParser::TmplArgListContext* RiddleParser::TmplUsedContext::tmplArgList() {
  return getRuleContext<RiddleParser::TmplArgListContext>(0);
}


size_t RiddleParser::TmplUsedContext::getRuleIndex() const {
  return RiddleParser::RuleTmplUsed;
}

void RiddleParser::TmplUsedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTmplUsed(this);
}

void RiddleParser::TmplUsedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTmplUsed(this);
}


std::any RiddleParser::TmplUsedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitTmplUsed(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::TmplUsedContext* RiddleParser::tmplUsed() {
  TmplUsedContext *_localctx = _tracker.createInstance<TmplUsedContext>(_ctx, getState());
  enterRule(_localctx, 64, RiddleParser::RuleTmplUsed);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(524);
    match(RiddleParser::Less);
    setState(525);
    antlrcpp::downCast<TmplUsedContext *>(_localctx)->args = tmplArgList();
    setState(526);
    match(RiddleParser::Greater);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TmplArgContext ------------------------------------------------------------------

RiddleParser::TmplArgContext::TmplArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RiddleParser::ExpressionContext* RiddleParser::TmplArgContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::TypeUsedContext* RiddleParser::TmplArgContext::typeUsed() {
  return getRuleContext<RiddleParser::TypeUsedContext>(0);
}


size_t RiddleParser::TmplArgContext::getRuleIndex() const {
  return RiddleParser::RuleTmplArg;
}

void RiddleParser::TmplArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTmplArg(this);
}

void RiddleParser::TmplArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTmplArg(this);
}


std::any RiddleParser::TmplArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitTmplArg(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::TmplArgContext* RiddleParser::tmplArg() {
  TmplArgContext *_localctx = _tracker.createInstance<TmplArgContext>(_ctx, getState());
  enterRule(_localctx, 66, RiddleParser::RuleTmplArg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(530);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(528);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(529);
      typeUsed(0);
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

//----------------- TmplArgListContext ------------------------------------------------------------------

RiddleParser::TmplArgListContext::TmplArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RiddleParser::TmplArgContext *> RiddleParser::TmplArgListContext::tmplArg() {
  return getRuleContexts<RiddleParser::TmplArgContext>();
}

RiddleParser::TmplArgContext* RiddleParser::TmplArgListContext::tmplArg(size_t i) {
  return getRuleContext<RiddleParser::TmplArgContext>(i);
}

std::vector<tree::TerminalNode *> RiddleParser::TmplArgListContext::Comma() {
  return getTokens(RiddleParser::Comma);
}

tree::TerminalNode* RiddleParser::TmplArgListContext::Comma(size_t i) {
  return getToken(RiddleParser::Comma, i);
}


size_t RiddleParser::TmplArgListContext::getRuleIndex() const {
  return RiddleParser::RuleTmplArgList;
}

void RiddleParser::TmplArgListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTmplArgList(this);
}

void RiddleParser::TmplArgListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTmplArgList(this);
}


std::any RiddleParser::TmplArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitTmplArgList(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::TmplArgListContext* RiddleParser::tmplArgList() {
  TmplArgListContext *_localctx = _tracker.createInstance<TmplArgListContext>(_ctx, getState());
  enterRule(_localctx, 68, RiddleParser::RuleTmplArgList);
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
    setState(541);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 14) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 14)) & 109194774073868295) != 0)) {
      setState(537);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(532);
          tmplArg();
          setState(533);
          match(RiddleParser::Comma); 
        }
        setState(539);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
      }
      setState(540);
      tmplArg();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeUsedContext ------------------------------------------------------------------

RiddleParser::TypeUsedContext::TypeUsedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RiddleParser::TypeUsedContext::getRuleIndex() const {
  return RiddleParser::RuleTypeUsed;
}

void RiddleParser::TypeUsedContext::copyFrom(TypeUsedContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::ArrayTypeContext::LeftSquare() {
  return getToken(RiddleParser::LeftSquare, 0);
}

tree::TerminalNode* RiddleParser::ArrayTypeContext::RightSquare() {
  return getToken(RiddleParser::RightSquare, 0);
}

RiddleParser::TypeUsedContext* RiddleParser::ArrayTypeContext::typeUsed() {
  return getRuleContext<RiddleParser::TypeUsedContext>(0);
}

RiddleParser::ExpressionContext* RiddleParser::ArrayTypeContext::expression() {
  return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::ArrayTypeContext::ArrayTypeContext(TypeUsedContext *ctx) { copyFrom(ctx); }

void RiddleParser::ArrayTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayType(this);
}
void RiddleParser::ArrayTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayType(this);
}

std::any RiddleParser::ArrayTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitArrayType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TmplTypeContext ------------------------------------------------------------------

RiddleParser::ExprPtrContext* RiddleParser::TmplTypeContext::exprPtr() {
  return getRuleContext<RiddleParser::ExprPtrContext>(0);
}

RiddleParser::TmplUsedContext* RiddleParser::TmplTypeContext::tmplUsed() {
  return getRuleContext<RiddleParser::TmplUsedContext>(0);
}

RiddleParser::TmplTypeContext::TmplTypeContext(TypeUsedContext *ctx) { copyFrom(ctx); }

void RiddleParser::TmplTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTmplType(this);
}
void RiddleParser::TmplTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTmplType(this);
}

std::any RiddleParser::TmplTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitTmplType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BaseTypeContext ------------------------------------------------------------------

RiddleParser::ExprPtrContext* RiddleParser::BaseTypeContext::exprPtr() {
  return getRuleContext<RiddleParser::ExprPtrContext>(0);
}

RiddleParser::BaseTypeContext::BaseTypeContext(TypeUsedContext *ctx) { copyFrom(ctx); }

void RiddleParser::BaseTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBaseType(this);
}
void RiddleParser::BaseTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBaseType(this);
}

std::any RiddleParser::BaseTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitBaseType(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::TypeUsedContext* RiddleParser::typeUsed() {
   return typeUsed(0);
}

RiddleParser::TypeUsedContext* RiddleParser::typeUsed(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  RiddleParser::TypeUsedContext *_localctx = _tracker.createInstance<TypeUsedContext>(_ctx, parentState);
  RiddleParser::TypeUsedContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 70;
  enterRecursionRule(_localctx, 70, RiddleParser::RuleTypeUsed, precedence);

    

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
    setState(548);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<BaseTypeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(544);
      antlrcpp::downCast<BaseTypeContext *>(_localctx)->name = exprPtr(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<TmplTypeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(545);
      antlrcpp::downCast<TmplTypeContext *>(_localctx)->name = exprPtr(0);
      setState(546);
      antlrcpp::downCast<TmplTypeContext *>(_localctx)->tmpl = tmplUsed();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(557);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ArrayTypeContext>(_tracker.createInstance<TypeUsedContext>(parentContext, parentState));
        _localctx = newContext;
        newContext->baseType = previousContext;
        pushNewRecursionContext(newContext, startState, RuleTypeUsed);
        setState(550);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(551);
        match(RiddleParser::LeftSquare);
        setState(552);
        antlrcpp::downCast<ArrayTypeContext *>(_localctx)->size = expression(0);
        setState(553);
        match(RiddleParser::RightSquare); 
      }
      setState(559);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PropertyContext ------------------------------------------------------------------

RiddleParser::PropertyContext::PropertyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> RiddleParser::PropertyContext::LeftSquare() {
  return getTokens(RiddleParser::LeftSquare);
}

tree::TerminalNode* RiddleParser::PropertyContext::LeftSquare(size_t i) {
  return getToken(RiddleParser::LeftSquare, i);
}

std::vector<RiddleParser::PropertyItemContext *> RiddleParser::PropertyContext::propertyItem() {
  return getRuleContexts<RiddleParser::PropertyItemContext>();
}

RiddleParser::PropertyItemContext* RiddleParser::PropertyContext::propertyItem(size_t i) {
  return getRuleContext<RiddleParser::PropertyItemContext>(i);
}

std::vector<tree::TerminalNode *> RiddleParser::PropertyContext::RightSquare() {
  return getTokens(RiddleParser::RightSquare);
}

tree::TerminalNode* RiddleParser::PropertyContext::RightSquare(size_t i) {
  return getToken(RiddleParser::RightSquare, i);
}

std::vector<tree::TerminalNode *> RiddleParser::PropertyContext::Comma() {
  return getTokens(RiddleParser::Comma);
}

tree::TerminalNode* RiddleParser::PropertyContext::Comma(size_t i) {
  return getToken(RiddleParser::Comma, i);
}


size_t RiddleParser::PropertyContext::getRuleIndex() const {
  return RiddleParser::RuleProperty;
}

void RiddleParser::PropertyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty(this);
}

void RiddleParser::PropertyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty(this);
}


std::any RiddleParser::PropertyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitProperty(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::PropertyContext* RiddleParser::property() {
  PropertyContext *_localctx = _tracker.createInstance<PropertyContext>(_ctx, getState());
  enterRule(_localctx, 72, RiddleParser::RuleProperty);
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
    setState(560);
    match(RiddleParser::LeftSquare);
    setState(561);
    match(RiddleParser::LeftSquare);
    setState(562);
    propertyItem();
    setState(567);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == RiddleParser::Comma) {
      setState(563);
      match(RiddleParser::Comma);
      setState(564);
      propertyItem();
      setState(569);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(570);
    match(RiddleParser::RightSquare);
    setState(571);
    match(RiddleParser::RightSquare);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyItemContext ------------------------------------------------------------------

RiddleParser::PropertyItemContext::PropertyItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RiddleParser::PropertyItemContext::Identifier() {
  return getToken(RiddleParser::Identifier, 0);
}


size_t RiddleParser::PropertyItemContext::getRuleIndex() const {
  return RiddleParser::RulePropertyItem;
}

void RiddleParser::PropertyItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPropertyItem(this);
}

void RiddleParser::PropertyItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPropertyItem(this);
}


std::any RiddleParser::PropertyItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RiddleParserVisitor*>(visitor))
    return parserVisitor->visitPropertyItem(this);
  else
    return visitor->visitChildren(this);
}

RiddleParser::PropertyItemContext* RiddleParser::propertyItem() {
  PropertyItemContext *_localctx = _tracker.createInstance<PropertyItemContext>(_ctx, getState());
  enterRule(_localctx, 74, RiddleParser::RulePropertyItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(573);
    match(RiddleParser::Identifier);
   
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
    case 35: return typeUsedSempred(antlrcpp::downCast<TypeUsedContext *>(context), predicateIndex);

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
    case 1: return precpred(_ctx, 37);
    case 2: return precpred(_ctx, 36);
    case 3: return precpred(_ctx, 35);
    case 4: return precpred(_ctx, 34);
    case 5: return precpred(_ctx, 33);
    case 6: return precpred(_ctx, 32);
    case 7: return precpred(_ctx, 31);
    case 8: return precpred(_ctx, 30);
    case 9: return precpred(_ctx, 29);
    case 10: return precpred(_ctx, 28);
    case 11: return precpred(_ctx, 27);
    case 12: return precpred(_ctx, 26);
    case 13: return precpred(_ctx, 25);
    case 14: return precpred(_ctx, 24);
    case 15: return precpred(_ctx, 23);
    case 16: return precpred(_ctx, 22);
    case 17: return precpred(_ctx, 21);
    case 18: return precpred(_ctx, 20);
    case 19: return precpred(_ctx, 19);

  default:
    break;
  }
  return true;
}

bool RiddleParser::typeUsedSempred(TypeUsedContext *_localctx, size_t predicateIndex) {
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
