
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
                  "varDefineStatement", "argsExpr", "defineArgs", "funcDefine", "funcBody",
                  "forStatement", "whileStatement", "ifStatement", "returnStatement",
                  "varClassDefine", "funcClassDefine", "defineStatement_ed", "classDefine",
                  "classBody", "exprPtr", "expression", "id", "number", "boolean", "string",
                  "float", "integer", "templateArg", "templateArgs", "typeName"},
          std::vector<std::string>{
                  "", "'var'", "'val'", "'for'", "'while'", "'if'", "'else'", "'fun'",
                  "'return'", "'import'", "'package'", "'class'", "'public'", "'protected'",
                  "'Private'", "'override'", "'true'", "'false'", "'static'", "'const'",
                  "'('", "')'", "'['", "']'", "'{'", "'}'", "':'", "';'", "','", "'=='",
                  "'='", "'>'", "'<'", "'<<'", "'>>'", "'>>>'", "'+'", "'-'", "'*'",
                  "'/'", "'%'", "'!'", "'&'", "'|'", "'^'", "'.'", "'\"'", "'''", "'\\n'"},
          std::vector<std::string>{
                  "", "Var", "Val", "For", "While", "If", "Else", "Func", "Return",
                  "Import", "Package", "Class", "Public", "Protected", "Private", "Override",
                  "True", "False", "Static", "Const", "LeftBracket", "RightBracket",
                  "LeftSquare", "RightSquare", "LeftCurly", "RightCurly", "Colon", "Semi",
                  "Comma", "Equal", "Assign", "Greater", "Less", "LeftLeft", "RightRight",
                  "RightRightRight", "Add", "Sub", "Star", "Div", "Mod", "Not", "And",
                  "Or", "Xor", "Dot", "DoubleQuotes", "Quotes", "Endl", "Identifier",
                  "Hexadecimal", "Decimal", "Octal", "Binary", "Float", "IntegerSequence",
                  "HEX_DIGIT", "OCTAL_DIGIT", "BINARY_DIGIT", "DIGIT", "STRING", "LINE_COMMENT",
                  "BLOCK_COMMENT", "WHITESPACE"});
  static const int32_t serializedATNSegment[] = {
          4, 1, 63, 513, 2, 0, 7, 0, 2, 1, 7, 1, 2, 2, 7, 2, 2, 3, 7, 3, 2, 4, 7, 4, 2, 5, 7, 5, 2, 6, 7, 6, 2,
          7, 7, 7, 2, 8, 7, 8, 2, 9, 7, 9, 2, 10, 7, 10, 2, 11, 7, 11, 2, 12, 7, 12, 2, 13, 7, 13, 2, 14, 7,
          14, 2, 15, 7, 15, 2, 16, 7, 16, 2, 17, 7, 17, 2, 18, 7, 18, 2, 19, 7, 19, 2, 20, 7, 20, 2, 21, 7,
          21, 2, 22, 7, 22, 2, 23, 7, 23, 2, 24, 7, 24, 2, 25, 7, 25, 2, 26, 7, 26, 2, 27, 7, 27, 2, 28, 7,
          28, 2, 29, 7, 29, 1, 0, 5, 0, 62, 8, 0, 10, 0, 12, 0, 65, 9, 0, 1, 0, 3, 0, 68, 8, 0, 1, 1, 1, 1, 3,
          1, 72, 8, 1, 1, 1, 3, 1, 75, 8, 1, 1, 1, 1, 1, 3, 1, 79, 8, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1,
          2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 5, 2, 93, 8, 2, 10, 2, 12, 2, 96, 9, 2, 1, 2, 3, 2, 99, 8, 2, 1, 3,
          1, 3, 1, 3, 1, 4, 1, 4, 1, 4, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1, 5, 1,
          5, 1, 5, 1, 5, 3, 5, 122, 8, 5, 1, 6, 1, 6, 1, 6, 5, 6, 127, 8, 6, 10, 6, 12, 6, 130, 9, 6, 1, 6, 3,
          6, 133, 8, 6, 1, 7, 1, 7, 1, 7, 1, 7, 1, 7, 5, 7, 140, 8, 7, 10, 7, 12, 7, 143, 9, 7, 1, 7, 1, 7, 1,
          7, 3, 7, 148, 8, 7, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 1, 8, 3, 8, 157, 8, 8, 1, 8, 1, 8, 1, 8, 1, 8,
          1, 9, 5, 9, 164, 8, 9, 10, 9, 12, 9, 167, 9, 9, 1, 10, 1, 10, 1, 10, 3, 10, 172, 8, 10, 1, 10, 1,
          10, 3, 10, 176, 8, 10, 1, 10, 1, 10, 3, 10, 180, 8, 10, 1, 10, 1, 10, 1, 10, 1, 11, 1, 11, 1, 11,
          1, 11, 1, 11, 1, 11, 1, 12, 1, 12, 1, 12, 1, 12, 1, 12, 1, 12, 1, 12, 1, 12, 1, 12, 1, 12, 1, 12,
          1, 12, 1, 12, 1, 12, 1, 12, 1, 12, 3, 12, 207, 8, 12, 1, 13, 1, 13, 1, 13, 1, 14, 1, 14, 1, 14,
          1, 14, 1, 14, 1, 14, 1, 14, 1, 14, 1, 14, 1, 14, 1, 14, 1, 14, 1, 14, 1, 14, 1, 14, 3, 14, 227,
          8, 14, 1, 15, 1, 15, 1, 15, 1, 15, 1, 15, 1, 15, 1, 15, 3, 15, 236, 8, 15, 1, 15, 1, 15, 1, 15,
          1, 15, 1, 16, 1, 16, 3, 16, 244, 8, 16, 1, 16, 3, 16, 247, 8, 16, 1, 16, 3, 16, 250, 8, 16, 1,
          16, 1, 16, 3, 16, 254, 8, 16, 1, 17, 1, 17, 1, 17, 1, 17, 1, 17, 1, 17, 1, 18, 5, 18, 263, 8, 18,
          10, 18, 12, 18, 266, 9, 18, 1, 19, 1, 19, 1, 19, 1, 19, 1, 19, 1, 19, 3, 19, 274, 8, 19, 1, 20,
          1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20,
          1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20,
          1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20,
          1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20,
          1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20,
          1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20,
          1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20,
          1, 20, 1, 20, 3, 20, 377, 8, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20,
          1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20,
          1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20,
          1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20,
          1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 1, 20, 5, 20, 441, 8, 20,
          10, 20, 12, 20, 444, 9, 20, 1, 21, 1, 21, 1, 21, 5, 21, 449, 8, 21, 10, 21, 12, 21, 452, 9, 21,
          1, 22, 1, 22, 3, 22, 456, 8, 22, 1, 23, 1, 23, 1, 23, 1, 23, 3, 23, 462, 8, 23, 1, 24, 1, 24, 1,
          25, 1, 25, 1, 25, 1, 26, 1, 26, 1, 26, 1, 26, 1, 26, 1, 26, 1, 26, 1, 26, 3, 26, 477, 8, 26, 1,
          27, 1, 27, 3, 27, 481, 8, 27, 1, 28, 1, 28, 1, 28, 5, 28, 486, 8, 28, 10, 28, 12, 28, 489, 9,
          28, 1, 28, 3, 28, 492, 8, 28, 1, 29, 1, 29, 1, 29, 1, 29, 1, 29, 1, 29, 1, 29, 3, 29, 501, 8, 29,
          1, 29, 1, 29, 1, 29, 1, 29, 1, 29, 5, 29, 508, 8, 29, 10, 29, 12, 29, 511, 9, 29, 1, 29, 0, 2,
          40, 58, 30, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42,
          44, 46, 48, 50, 52, 54, 56, 58, 0, 0, 577, 0, 67, 1, 0, 0, 0, 2, 78, 1, 0, 0, 0, 4, 98, 1, 0, 0,
          0, 6, 100, 1, 0, 0, 0, 8, 103, 1, 0, 0, 0, 10, 121, 1, 0, 0, 0, 12, 132, 1, 0, 0, 0, 14, 147, 1,
          0, 0, 0, 16, 149, 1, 0, 0, 0, 18, 165, 1, 0, 0, 0, 20, 168, 1, 0, 0, 0, 22, 184, 1, 0, 0, 0, 24,
          206, 1, 0, 0, 0, 26, 208, 1, 0, 0, 0, 28, 226, 1, 0, 0, 0, 30, 228, 1, 0, 0, 0, 32, 253, 1, 0, 0,
          0, 34, 255, 1, 0, 0, 0, 36, 264, 1, 0, 0, 0, 38, 273, 1, 0, 0, 0, 40, 376, 1, 0, 0, 0, 42, 445,
          1, 0, 0, 0, 44, 455, 1, 0, 0, 0, 46, 461, 1, 0, 0, 0, 48, 463, 1, 0, 0, 0, 50, 465, 1, 0, 0, 0, 52,
          476, 1, 0, 0, 0, 54, 480, 1, 0, 0, 0, 56, 491, 1, 0, 0, 0, 58, 500, 1, 0, 0, 0, 60, 62, 3, 2, 1,
          0, 61, 60, 1, 0, 0, 0, 62, 65, 1, 0, 0, 0, 63, 61, 1, 0, 0, 0, 63, 64, 1, 0, 0, 0, 64, 68, 1, 0, 0,
          0, 65, 63, 1, 0, 0, 0, 66, 68, 5, 0, 0, 1, 67, 63, 1, 0, 0, 0, 67, 66, 1, 0, 0, 0, 68, 1, 1, 0, 0,
          0, 69, 71, 3, 4, 2, 0, 70, 72, 5, 27, 0, 0, 71, 70, 1, 0, 0, 0, 71, 72, 1, 0, 0, 0, 72, 74, 1, 0,
          0, 0, 73, 75, 5, 48, 0, 0, 74, 73, 1, 0, 0, 0, 74, 75, 1, 0, 0, 0, 75, 79, 1, 0, 0, 0, 76, 79, 5,
          27, 0, 0, 77, 79, 5, 48, 0, 0, 78, 69, 1, 0, 0, 0, 78, 76, 1, 0, 0, 0, 78, 77, 1, 0, 0, 0, 79, 3,
          1, 0, 0, 0, 80, 99, 3, 6, 3, 0, 81, 99, 3, 8, 4, 0, 82, 99, 3, 34, 17, 0, 83, 99, 3, 16, 8, 0, 84,
          99, 3, 10, 5, 0, 85, 99, 3, 20, 10, 0, 86, 99, 3, 22, 11, 0, 87, 99, 3, 24, 12, 0, 88, 99, 3, 26,
          13, 0, 89, 99, 3, 40, 20, 0, 90, 94, 5, 24, 0, 0, 91, 93, 3, 2, 1, 0, 92, 91, 1, 0, 0, 0, 93, 96,
          1, 0, 0, 0, 94, 92, 1, 0, 0, 0, 94, 95, 1, 0, 0, 0, 95, 97, 1, 0, 0, 0, 96, 94, 1, 0, 0, 0, 97, 99,
          5, 25, 0, 0, 98, 80, 1, 0, 0, 0, 98, 81, 1, 0, 0, 0, 98, 82, 1, 0, 0, 0, 98, 83, 1, 0, 0, 0, 98, 84,
          1, 0, 0, 0, 98, 85, 1, 0, 0, 0, 98, 86, 1, 0, 0, 0, 98, 87, 1, 0, 0, 0, 98, 88, 1, 0, 0, 0, 98, 89,
          1, 0, 0, 0, 98, 90, 1, 0, 0, 0, 99, 5, 1, 0, 0, 0, 100, 101, 5, 10, 0, 0, 101, 102, 3, 42, 21, 0,
          102, 7, 1, 0, 0, 0, 103, 104, 5, 9, 0, 0, 104, 105, 3, 42, 21, 0, 105, 9, 1, 0, 0, 0, 106, 107,
          5, 1, 0, 0, 107, 108, 5, 49, 0, 0, 108, 109, 5, 26, 0, 0, 109, 122, 3, 58, 29, 0, 110, 111, 5,
          1, 0, 0, 111, 112, 5, 49, 0, 0, 112, 113, 5, 30, 0, 0, 113, 122, 3, 40, 20, 0, 114, 115, 5, 1,
          0, 0, 115, 116, 5, 49, 0, 0, 116, 117, 5, 26, 0, 0, 117, 118, 3, 58, 29, 0, 118, 119, 5, 30,
          0, 0, 119, 120, 3, 40, 20, 0, 120, 122, 1, 0, 0, 0, 121, 106, 1, 0, 0, 0, 121, 110, 1, 0, 0, 0,
          121, 114, 1, 0, 0, 0, 122, 11, 1, 0, 0, 0, 123, 124, 3, 40, 20, 0, 124, 125, 5, 28, 0, 0, 125,
          127, 1, 0, 0, 0, 126, 123, 1, 0, 0, 0, 127, 130, 1, 0, 0, 0, 128, 126, 1, 0, 0, 0, 128, 129, 1,
          0, 0, 0, 129, 131, 1, 0, 0, 0, 130, 128, 1, 0, 0, 0, 131, 133, 3, 40, 20, 0, 132, 128, 1, 0, 0,
          0, 132, 133, 1, 0, 0, 0, 133, 13, 1, 0, 0, 0, 134, 135, 5, 49, 0, 0, 135, 136, 5, 26, 0, 0, 136,
          137, 3, 58, 29, 0, 137, 138, 5, 28, 0, 0, 138, 140, 1, 0, 0, 0, 139, 134, 1, 0, 0, 0, 140, 143,
          1, 0, 0, 0, 141, 139, 1, 0, 0, 0, 141, 142, 1, 0, 0, 0, 142, 144, 1, 0, 0, 0, 143, 141, 1, 0, 0,
          0, 144, 145, 5, 49, 0, 0, 145, 146, 5, 26, 0, 0, 146, 148, 3, 58, 29, 0, 147, 141, 1, 0, 0, 0,
          147, 148, 1, 0, 0, 0, 148, 15, 1, 0, 0, 0, 149, 150, 5, 7, 0, 0, 150, 151, 5, 49, 0, 0, 151, 152,
          5, 20, 0, 0, 152, 153, 3, 14, 7, 0, 153, 156, 5, 21, 0, 0, 154, 155, 5, 26, 0, 0, 155, 157, 3,
          58, 29, 0, 156, 154, 1, 0, 0, 0, 156, 157, 1, 0, 0, 0, 157, 158, 1, 0, 0, 0, 158, 159, 5, 24,
          0, 0, 159, 160, 3, 18, 9, 0, 160, 161, 5, 25, 0, 0, 161, 17, 1, 0, 0, 0, 162, 164, 3, 2, 1, 0,
          163, 162, 1, 0, 0, 0, 164, 167, 1, 0, 0, 0, 165, 163, 1, 0, 0, 0, 165, 166, 1, 0, 0, 0, 166, 19,
          1, 0, 0, 0, 167, 165, 1, 0, 0, 0, 168, 169, 5, 3, 0, 0, 169, 171, 5, 20, 0, 0, 170, 172, 3, 10,
          5, 0, 171, 170, 1, 0, 0, 0, 171, 172, 1, 0, 0, 0, 172, 173, 1, 0, 0, 0, 173, 175, 5, 27, 0, 0,
          174, 176, 3, 40, 20, 0, 175, 174, 1, 0, 0, 0, 175, 176, 1, 0, 0, 0, 176, 177, 1, 0, 0, 0, 177,
          179, 5, 27, 0, 0, 178, 180, 3, 4, 2, 0, 179, 178, 1, 0, 0, 0, 179, 180, 1, 0, 0, 0, 180, 181,
          1, 0, 0, 0, 181, 182, 5, 21, 0, 0, 182, 183, 3, 2, 1, 0, 183, 21, 1, 0, 0, 0, 184, 185, 5, 4, 0,
          0, 185, 186, 5, 20, 0, 0, 186, 187, 3, 40, 20, 0, 187, 188, 5, 21, 0, 0, 188, 189, 3, 2, 1, 0,
          189, 23, 1, 0, 0, 0, 190, 191, 5, 5, 0, 0, 191, 192, 5, 20, 0, 0, 192, 193, 3, 40, 20, 0, 193,
          194, 5, 21, 0, 0, 194, 195, 3, 2, 1, 0, 195, 196, 6, 12, -1, 0, 196, 207, 1, 0, 0, 0, 197, 198,
          5, 5, 0, 0, 198, 199, 5, 20, 0, 0, 199, 200, 3, 40, 20, 0, 200, 201, 5, 21, 0, 0, 201, 202, 3,
          2, 1, 0, 202, 203, 5, 6, 0, 0, 203, 204, 3, 2, 1, 0, 204, 205, 6, 12, -1, 0, 205, 207, 1, 0, 0,
          0, 206, 190, 1, 0, 0, 0, 206, 197, 1, 0, 0, 0, 207, 25, 1, 0, 0, 0, 208, 209, 5, 8, 0, 0, 209,
          210, 3, 2, 1, 0, 210, 27, 1, 0, 0, 0, 211, 212, 5, 1, 0, 0, 212, 213, 5, 49, 0, 0, 213, 214, 5,
          26, 0, 0, 214, 227, 3, 58, 29, 0, 215, 216, 5, 1, 0, 0, 216, 217, 5, 49, 0, 0, 217, 218, 5, 30,
          0, 0, 218, 227, 3, 40, 20, 0, 219, 220, 5, 1, 0, 0, 220, 221, 5, 49, 0, 0, 221, 222, 5, 26, 0,
          0, 222, 223, 3, 58, 29, 0, 223, 224, 5, 30, 0, 0, 224, 225, 3, 40, 20, 0, 225, 227, 1, 0, 0,
          0, 226, 211, 1, 0, 0, 0, 226, 215, 1, 0, 0, 0, 226, 219, 1, 0, 0, 0, 227, 29, 1, 0, 0, 0, 228,
          229, 5, 7, 0, 0, 229, 230, 5, 49, 0, 0, 230, 231, 5, 20, 0, 0, 231, 232, 3, 14, 7, 0, 232, 235,
          5, 21, 0, 0, 233, 234, 5, 26, 0, 0, 234, 236, 3, 58, 29, 0, 235, 233, 1, 0, 0, 0, 235, 236, 1,
          0, 0, 0, 236, 237, 1, 0, 0, 0, 237, 238, 5, 24, 0, 0, 238, 239, 3, 18, 9, 0, 239, 240, 5, 25,
          0, 0, 240, 31, 1, 0, 0, 0, 241, 244, 3, 28, 14, 0, 242, 244, 3, 30, 15, 0, 243, 241, 1, 0, 0,
          0, 243, 242, 1, 0, 0, 0, 244, 246, 1, 0, 0, 0, 245, 247, 5, 27, 0, 0, 246, 245, 1, 0, 0, 0, 246,
          247, 1, 0, 0, 0, 247, 249, 1, 0, 0, 0, 248, 250, 5, 48, 0, 0, 249, 248, 1, 0, 0, 0, 249, 250,
          1, 0, 0, 0, 250, 254, 1, 0, 0, 0, 251, 254, 5, 27, 0, 0, 252, 254, 5, 48, 0, 0, 253, 243, 1, 0,
          0, 0, 253, 251, 1, 0, 0, 0, 253, 252, 1, 0, 0, 0, 254, 33, 1, 0, 0, 0, 255, 256, 5, 11, 0, 0, 256,
          257, 3, 42, 21, 0, 257, 258, 5, 24, 0, 0, 258, 259, 3, 36, 18, 0, 259, 260, 5, 25, 0, 0, 260,
          35, 1, 0, 0, 0, 261, 263, 3, 32, 16, 0, 262, 261, 1, 0, 0, 0, 263, 266, 1, 0, 0, 0, 264, 262,
          1, 0, 0, 0, 264, 265, 1, 0, 0, 0, 265, 37, 1, 0, 0, 0, 266, 264, 1, 0, 0, 0, 267, 268, 3, 42, 21,
          0, 268, 269, 5, 20, 0, 0, 269, 270, 3, 12, 6, 0, 270, 271, 5, 21, 0, 0, 271, 274, 1, 0, 0, 0,
          272, 274, 3, 42, 21, 0, 273, 267, 1, 0, 0, 0, 273, 272, 1, 0, 0, 0, 274, 39, 1, 0, 0, 0, 275,
          276, 6, 20, -1, 0, 276, 277, 5, 32, 0, 0, 277, 278, 3, 58, 29, 0, 278, 279, 5, 31, 0, 0, 279,
          280, 5, 20, 0, 0, 280, 281, 3, 38, 19, 0, 281, 282, 5, 21, 0, 0, 282, 377, 1, 0, 0, 0, 283, 284,
          5, 20, 0, 0, 284, 285, 3, 40, 20, 0, 285, 286, 5, 21, 0, 0, 286, 377, 1, 0, 0, 0, 287, 288, 5,
          41, 0, 0, 288, 377, 3, 40, 20, 44, 289, 290, 5, 36, 0, 0, 290, 377, 3, 40, 20, 43, 291, 292,
          5, 37, 0, 0, 292, 377, 3, 40, 20, 42, 293, 294, 5, 36, 0, 0, 294, 295, 5, 36, 0, 0, 295, 377,
          3, 38, 19, 0, 296, 297, 3, 38, 19, 0, 297, 298, 5, 36, 0, 0, 298, 299, 5, 36, 0, 0, 299, 377,
          1, 0, 0, 0, 300, 301, 5, 37, 0, 0, 301, 302, 5, 37, 0, 0, 302, 377, 3, 38, 19, 0, 303, 304, 3,
          38, 19, 0, 304, 305, 5, 37, 0, 0, 305, 306, 5, 37, 0, 0, 306, 377, 1, 0, 0, 0, 307, 377, 3, 38,
          19, 0, 308, 309, 3, 38, 19, 0, 309, 310, 5, 30, 0, 0, 310, 311, 3, 40, 20, 17, 311, 377, 1,
          0, 0, 0, 312, 313, 3, 38, 19, 0, 313, 314, 5, 36, 0, 0, 314, 315, 5, 30, 0, 0, 315, 316, 3, 40,
          20, 16, 316, 377, 1, 0, 0, 0, 317, 318, 3, 38, 19, 0, 318, 319, 5, 37, 0, 0, 319, 320, 5, 30,
          0, 0, 320, 321, 3, 40, 20, 15, 321, 377, 1, 0, 0, 0, 322, 323, 3, 38, 19, 0, 323, 324, 5, 38,
          0, 0, 324, 325, 5, 30, 0, 0, 325, 326, 3, 40, 20, 14, 326, 377, 1, 0, 0, 0, 327, 328, 3, 38,
          19, 0, 328, 329, 5, 39, 0, 0, 329, 330, 5, 30, 0, 0, 330, 331, 3, 40, 20, 13, 331, 377, 1, 0,
          0, 0, 332, 333, 3, 38, 19, 0, 333, 334, 5, 40, 0, 0, 334, 335, 5, 30, 0, 0, 335, 336, 3, 40,
          20, 12, 336, 377, 1, 0, 0, 0, 337, 338, 3, 38, 19, 0, 338, 339, 5, 36, 0, 0, 339, 340, 5, 30,
          0, 0, 340, 341, 3, 40, 20, 11, 341, 377, 1, 0, 0, 0, 342, 343, 3, 38, 19, 0, 343, 344, 5, 42,
          0, 0, 344, 345, 5, 30, 0, 0, 345, 346, 3, 40, 20, 10, 346, 377, 1, 0, 0, 0, 347, 348, 3, 38,
          19, 0, 348, 349, 5, 43, 0, 0, 349, 350, 5, 30, 0, 0, 350, 351, 3, 40, 20, 9, 351, 377, 1, 0,
          0, 0, 352, 353, 3, 38, 19, 0, 353, 354, 5, 44, 0, 0, 354, 355, 5, 30, 0, 0, 355, 356, 3, 40,
          20, 8, 356, 377, 1, 0, 0, 0, 357, 358, 3, 38, 19, 0, 358, 359, 5, 33, 0, 0, 359, 360, 5, 30,
          0, 0, 360, 361, 3, 40, 20, 7, 361, 377, 1, 0, 0, 0, 362, 363, 3, 38, 19, 0, 363, 364, 5, 34,
          0, 0, 364, 365, 5, 30, 0, 0, 365, 366, 3, 40, 20, 6, 366, 377, 1, 0, 0, 0, 367, 368, 3, 38, 19,
          0, 368, 369, 5, 35, 0, 0, 369, 370, 5, 30, 0, 0, 370, 371, 3, 40, 20, 5, 371, 377, 1, 0, 0, 0,
          372, 377, 3, 48, 24, 0, 373, 377, 3, 44, 22, 0, 374, 377, 3, 46, 23, 0, 375, 377, 3, 42, 21,
          0, 376, 275, 1, 0, 0, 0, 376, 283, 1, 0, 0, 0, 376, 287, 1, 0, 0, 0, 376, 289, 1, 0, 0, 0, 376,
          291, 1, 0, 0, 0, 376, 293, 1, 0, 0, 0, 376, 296, 1, 0, 0, 0, 376, 300, 1, 0, 0, 0, 376, 303, 1,
          0, 0, 0, 376, 307, 1, 0, 0, 0, 376, 308, 1, 0, 0, 0, 376, 312, 1, 0, 0, 0, 376, 317, 1, 0, 0, 0,
          376, 322, 1, 0, 0, 0, 376, 327, 1, 0, 0, 0, 376, 332, 1, 0, 0, 0, 376, 337, 1, 0, 0, 0, 376, 342,
          1, 0, 0, 0, 376, 347, 1, 0, 0, 0, 376, 352, 1, 0, 0, 0, 376, 357, 1, 0, 0, 0, 376, 362, 1, 0, 0,
          0, 376, 367, 1, 0, 0, 0, 376, 372, 1, 0, 0, 0, 376, 373, 1, 0, 0, 0, 376, 374, 1, 0, 0, 0, 376,
          375, 1, 0, 0, 0, 377, 442, 1, 0, 0, 0, 378, 379, 10, 36, 0, 0, 379, 380, 5, 38, 0, 0, 380, 441,
          3, 40, 20, 37, 381, 382, 10, 35, 0, 0, 382, 383, 5, 39, 0, 0, 383, 441, 3, 40, 20, 36, 384,
          385, 10, 34, 0, 0, 385, 386, 5, 40, 0, 0, 386, 441, 3, 40, 20, 35, 387, 388, 10, 33, 0, 0, 388,
          389, 5, 36, 0, 0, 389, 441, 3, 40, 20, 34, 390, 391, 10, 32, 0, 0, 391, 392, 5, 37, 0, 0, 392,
          441, 3, 40, 20, 33, 393, 394, 10, 31, 0, 0, 394, 395, 5, 33, 0, 0, 395, 441, 3, 40, 20, 32,
          396, 397, 10, 30, 0, 0, 397, 398, 5, 34, 0, 0, 398, 441, 3, 40, 20, 31, 399, 400, 10, 29, 0,
          0, 400, 401, 5, 35, 0, 0, 401, 441, 3, 40, 20, 30, 402, 403, 10, 28, 0, 0, 403, 404, 5, 31,
          0, 0, 404, 441, 3, 40, 20, 29, 405, 406, 10, 27, 0, 0, 406, 407, 5, 32, 0, 0, 407, 441, 3, 40,
          20, 28, 408, 409, 10, 26, 0, 0, 409, 410, 5, 31, 0, 0, 410, 411, 5, 30, 0, 0, 411, 441, 3, 40,
          20, 27, 412, 413, 10, 25, 0, 0, 413, 414, 5, 32, 0, 0, 414, 415, 5, 30, 0, 0, 415, 441, 3, 40,
          20, 26, 416, 417, 10, 24, 0, 0, 417, 418, 5, 29, 0, 0, 418, 441, 3, 40, 20, 25, 419, 420, 10,
          23, 0, 0, 420, 421, 5, 41, 0, 0, 421, 422, 5, 30, 0, 0, 422, 441, 3, 40, 20, 24, 423, 424, 10,
          22, 0, 0, 424, 425, 5, 42, 0, 0, 425, 441, 3, 40, 20, 23, 426, 427, 10, 21, 0, 0, 427, 428,
          5, 44, 0, 0, 428, 441, 3, 40, 20, 22, 429, 430, 10, 20, 0, 0, 430, 431, 5, 43, 0, 0, 431, 441,
          3, 40, 20, 21, 432, 433, 10, 19, 0, 0, 433, 434, 5, 42, 0, 0, 434, 435, 5, 42, 0, 0, 435, 441,
          3, 40, 20, 20, 436, 437, 10, 18, 0, 0, 437, 438, 5, 43, 0, 0, 438, 439, 5, 43, 0, 0, 439, 441,
          3, 40, 20, 19, 440, 378, 1, 0, 0, 0, 440, 381, 1, 0, 0, 0, 440, 384, 1, 0, 0, 0, 440, 387, 1,
          0, 0, 0, 440, 390, 1, 0, 0, 0, 440, 393, 1, 0, 0, 0, 440, 396, 1, 0, 0, 0, 440, 399, 1, 0, 0, 0,
          440, 402, 1, 0, 0, 0, 440, 405, 1, 0, 0, 0, 440, 408, 1, 0, 0, 0, 440, 412, 1, 0, 0, 0, 440, 416,
          1, 0, 0, 0, 440, 419, 1, 0, 0, 0, 440, 423, 1, 0, 0, 0, 440, 426, 1, 0, 0, 0, 440, 429, 1, 0, 0,
          0, 440, 432, 1, 0, 0, 0, 440, 436, 1, 0, 0, 0, 441, 444, 1, 0, 0, 0, 442, 440, 1, 0, 0, 0, 442,
          443, 1, 0, 0, 0, 443, 41, 1, 0, 0, 0, 444, 442, 1, 0, 0, 0, 445, 450, 5, 49, 0, 0, 446, 447, 5,
          45, 0, 0, 447, 449, 5, 49, 0, 0, 448, 446, 1, 0, 0, 0, 449, 452, 1, 0, 0, 0, 450, 448, 1, 0, 0,
          0, 450, 451, 1, 0, 0, 0, 451, 43, 1, 0, 0, 0, 452, 450, 1, 0, 0, 0, 453, 456, 3, 52, 26, 0, 454,
          456, 3, 50, 25, 0, 455, 453, 1, 0, 0, 0, 455, 454, 1, 0, 0, 0, 456, 45, 1, 0, 0, 0, 457, 458,
          5, 16, 0, 0, 458, 462, 6, 23, -1, 0, 459, 460, 5, 17, 0, 0, 460, 462, 6, 23, -1, 0, 461, 457,
          1, 0, 0, 0, 461, 459, 1, 0, 0, 0, 462, 47, 1, 0, 0, 0, 463, 464, 5, 60, 0, 0, 464, 49, 1, 0, 0,
          0, 465, 466, 5, 54, 0, 0, 466, 467, 6, 25, -1, 0, 467, 51, 1, 0, 0, 0, 468, 469, 5, 51, 0, 0,
          469, 477, 6, 26, -1, 0, 470, 471, 5, 50, 0, 0, 471, 477, 6, 26, -1, 0, 472, 473, 5, 53, 0, 0,
          473, 477, 6, 26, -1, 0, 474, 475, 5, 52, 0, 0, 475, 477, 6, 26, -1, 0, 476, 468, 1, 0, 0, 0,
          476, 470, 1, 0, 0, 0, 476, 472, 1, 0, 0, 0, 476, 474, 1, 0, 0, 0, 477, 53, 1, 0, 0, 0, 478, 481,
          3, 40, 20, 0, 479, 481, 3, 58, 29, 0, 480, 478, 1, 0, 0, 0, 480, 479, 1, 0, 0, 0, 481, 55, 1,
          0, 0, 0, 482, 483, 3, 54, 27, 0, 483, 484, 5, 28, 0, 0, 484, 486, 1, 0, 0, 0, 485, 482, 1, 0,
          0, 0, 486, 489, 1, 0, 0, 0, 487, 485, 1, 0, 0, 0, 487, 488, 1, 0, 0, 0, 488, 490, 1, 0, 0, 0, 489,
          487, 1, 0, 0, 0, 490, 492, 3, 54, 27, 0, 491, 487, 1, 0, 0, 0, 491, 492, 1, 0, 0, 0, 492, 57,
          1, 0, 0, 0, 493, 494, 6, 29, -1, 0, 494, 501, 3, 42, 21, 0, 495, 496, 3, 42, 21, 0, 496, 497,
          5, 32, 0, 0, 497, 498, 3, 56, 28, 0, 498, 499, 5, 31, 0, 0, 499, 501, 1, 0, 0, 0, 500, 493, 1,
          0, 0, 0, 500, 495, 1, 0, 0, 0, 501, 509, 1, 0, 0, 0, 502, 503, 10, 1, 0, 0, 503, 504, 5, 22, 0,
          0, 504, 505, 3, 40, 20, 0, 505, 506, 5, 23, 0, 0, 506, 508, 1, 0, 0, 0, 507, 502, 1, 0, 0, 0,
          508, 511, 1, 0, 0, 0, 509, 507, 1, 0, 0, 0, 509, 510, 1, 0, 0, 0, 510, 59, 1, 0, 0, 0, 511, 509,
          1, 0, 0, 0, 38, 63, 67, 71, 74, 78, 94, 98, 121, 128, 132, 141, 147, 156, 165, 171, 175, 179,
          206, 226, 235, 243, 246, 249, 253, 264, 273, 376, 440, 442, 450, 455, 461, 476, 480, 487,
          491, 500, 509};
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
      setState(67);
      _errHandler->sync(this);
      switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
          case 1: {
              enterOuterAlt(_localctx, 1);
              setState(63);
              _errHandler->sync(this);
              _la = _input->LA(1);
              while((((_la & ~0x3fULL) == 0) &&
                     ((1ULL << _la) & 1188671236277997498) != 0)) {
                  setState(60);
                  statement_ed();
                  setState(65);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
              }
              break;
          }

          case 2: {
              enterOuterAlt(_localctx, 2);
              setState(66);
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
      setState(78);
      _errHandler->sync(this);
      switch(_input->LA(1)) {
          case RiddleParser::Var:
          case RiddleParser::For:
          case RiddleParser::While:
          case RiddleParser::If:
          case RiddleParser::Func:
          case RiddleParser::Return:
          case RiddleParser::Import:
          case RiddleParser::Package:
          case RiddleParser::Class:
          case RiddleParser::True:
          case RiddleParser::False:
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
              setState(69);
              statement();
              setState(71);
              _errHandler->sync(this);

              switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
                  case 1: {
                      setState(70);
                      match(RiddleParser::Semi);
                      break;
                  }

                  default:
                      break;
              }
              setState(74);
              _errHandler->sync(this);

              switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
                  case 1: {
                      setState(73);
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
              setState(76);
              match(RiddleParser::Semi);
              break;
          }

          case RiddleParser::Endl: {
              enterOuterAlt(_localctx, 3);
              setState(77);
              match(RiddleParser::Endl);
              break;
          }

          default:
              throw NoViableAltException(this);
      }

  } catch (RecognitionException &e) {
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

RiddleParser::ClassDefineContext *RiddleParser::StatementContext::classDefine() {
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
      setState(98);
      _errHandler->sync(this);
      switch(_input->LA(1)) {
          case RiddleParser::Package: {
              enterOuterAlt(_localctx, 1);
              setState(80);
              packStatement();
              break;
          }

          case RiddleParser::Import: {
              enterOuterAlt(_localctx, 2);
              setState(81);
              importStatement();
              break;
          }

          case RiddleParser::Class: {
              enterOuterAlt(_localctx, 3);
              setState(82);
              classDefine();
              break;
          }

          case RiddleParser::Func: {
              enterOuterAlt(_localctx, 4);
              setState(83);
              funcDefine();
              break;
          }

          case RiddleParser::Var: {
              enterOuterAlt(_localctx, 5);
              setState(84);
              varDefineStatement();
              break;
          }

          case RiddleParser::For: {
              enterOuterAlt(_localctx, 6);
              setState(85);
              forStatement();
              break;
          }

          case RiddleParser::While: {
              enterOuterAlt(_localctx, 7);
              setState(86);
              whileStatement();
              break;
          }

          case RiddleParser::If: {
              enterOuterAlt(_localctx, 8);
              setState(87);
              ifStatement();
              break;
          }

          case RiddleParser::Return: {
              enterOuterAlt(_localctx, 9);
              setState(88);
              returnStatement();
              break;
          }

          case RiddleParser::True:
          case RiddleParser::False:
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
              enterOuterAlt(_localctx, 10);
              setState(89);
              expression(0);
              break;
          }

          case RiddleParser::LeftCurly: {
              enterOuterAlt(_localctx, 11);
              setState(90);
              match(RiddleParser::LeftCurly);
              setState(94);
              _errHandler->sync(this);
              _la = _input->LA(1);
              while((((_la & ~0x3fULL) == 0) &&
                     ((1ULL << _la) & 1188671236277997498) != 0)) {
                  setState(91);
                  statement_ed();
                  setState(96);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
              }
              setState(97);
              match(RiddleParser::RightCurly);
              break;
          }

          default:
              throw NoViableAltException(this);
      }

  } catch (RecognitionException &e) {
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
      setState(100);
      match(RiddleParser::Package);
      setState(101);
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
      setState(103);
      match(RiddleParser::Import);
      setState(104);
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

tree::TerminalNode *RiddleParser::VarDefineStatementContext::Identifier() {
    return getToken(RiddleParser::Identifier, 0);
}

RiddleParser::TypeNameContext *RiddleParser::VarDefineStatementContext::typeName() {
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
    enterRule(_localctx, 10, RiddleParser::RuleVarDefineStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
      setState(121);
      _errHandler->sync(this);
      switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
          case 1: {
              enterOuterAlt(_localctx, 1);
              setState(106);
              match(RiddleParser::Var);
              setState(107);
              antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->name = match(RiddleParser::Identifier);
              setState(108);
              match(RiddleParser::Colon);
              setState(109);
              antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->type = typeName(0);
              break;
          }

          case 2: {
              enterOuterAlt(_localctx, 2);
              setState(110);
              match(RiddleParser::Var);
              setState(111);
              antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->name = match(RiddleParser::Identifier);
              setState(112);
              match(RiddleParser::Assign);
              setState(113);
              antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->value = expression(0);
              break;
          }

          case 3: {
              enterOuterAlt(_localctx, 3);
              setState(114);
              match(RiddleParser::Var);
              setState(115);
              antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->name = match(RiddleParser::Identifier);
              setState(116);
              match(RiddleParser::Colon);
              setState(117);
              antlrcpp::downCast<VarDefineStatementContext *>(_localctx)->type = typeName(0);
              setState(118);
              match(RiddleParser::Assign);
              setState(119);
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
    enterRule(_localctx, 12, RiddleParser::RuleArgsExpr);
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
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 1188389761150287872) != 0)) {
        setState(128);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
        while(alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if(alt == 1) {
                setState(123);
                expression(0);
                setState(124);
                match(RiddleParser::Comma);
            }
            setState(130);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
        }
        setState(131);
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

RiddleParser::TypeNameContext *RiddleParser::DefineArgsContext::typeName(size_t i) {
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
    enterRule(_localctx, 14, RiddleParser::RuleDefineArgs);
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
    if (_la == RiddleParser::Identifier) {
        setState(141);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
        while(alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if(alt == 1) {
                setState(134);
                match(RiddleParser::Identifier);
                setState(135);
                match(RiddleParser::Colon);
                setState(136);
                typeName(0);
                setState(137);
                match(RiddleParser::Comma);
            }
            setState(143);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
        }

        setState(144);
        match(RiddleParser::Identifier);
        setState(145);
        match(RiddleParser::Colon);
        setState(146);
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

RiddleParser::TypeNameContext *RiddleParser::FuncDefineContext::typeName() {
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
    enterRule(_localctx, 16, RiddleParser::RuleFuncDefine);
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
      setState(149);
      match(RiddleParser::Func);
      setState(150);
      antlrcpp::downCast<FuncDefineContext *>(_localctx)->funcName = match(RiddleParser::Identifier);
      setState(151);
      match(RiddleParser::LeftBracket);
      setState(152);
      antlrcpp::downCast<FuncDefineContext *>(_localctx)->args = defineArgs();
      setState(153);
      match(RiddleParser::RightBracket);
      setState(156);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if(_la == RiddleParser::Colon) {
          setState(154);
          match(RiddleParser::Colon);
          setState(155);
          antlrcpp::downCast<FuncDefineContext *>(_localctx)->returnType = typeName(0);
      }
      setState(158);
      match(RiddleParser::LeftCurly);
      setState(159);
      antlrcpp::downCast<FuncDefineContext *>(_localctx)->body = funcBody();
      setState(160);
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
    enterRule(_localctx, 18, RiddleParser::RuleFuncBody);
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
      setState(165);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while((((_la & ~0x3fULL) == 0) &&
             ((1ULL << _la) & 1188671236277997498) != 0)) {
          setState(162);
          statement_ed();
          setState(167);
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
    enterRule(_localctx, 20, RiddleParser::RuleForStatement);
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
      setState(168);
      match(RiddleParser::For);
      setState(169);
      match(RiddleParser::LeftBracket);
      setState(171);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if(_la == RiddleParser::Var) {
          setState(170);
          antlrcpp::downCast<ForStatementContext *>(_localctx)->init = varDefineStatement();
      }
      setState(173);
      match(RiddleParser::Semi);
      setState(175);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if((((_la & ~0x3fULL) == 0) &&
          ((1ULL << _la) & 1188389761150287872) != 0)) {
          setState(174);
          antlrcpp::downCast<ForStatementContext *>(_localctx)->termCond = expression(0);
      }
      setState(177);
      match(RiddleParser::Semi);
      setState(179);
      _errHandler->sync(this);

      _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1188389761167069114) != 0)) {
          setState(178);
          antlrcpp::downCast<ForStatementContext *>(_localctx)->selfVar = statement();
      }
    setState(181);
    match(RiddleParser::RightBracket);
    setState(182);
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
    enterRule(_localctx, 22, RiddleParser::RuleWhileStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
      setState(184);
      match(RiddleParser::While);
      setState(185);
      match(RiddleParser::LeftBracket);
      setState(186);
      antlrcpp::downCast<WhileStatementContext *>(_localctx)->runCond = expression(0);
      setState(187);
      match(RiddleParser::RightBracket);
      setState(188);
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
    enterRule(_localctx, 24, RiddleParser::RuleIfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
      setState(206);
      _errHandler->sync(this);
      switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
          case 1: {
              enterOuterAlt(_localctx, 1);
              setState(190);
              match(RiddleParser::If);
              setState(191);
              match(RiddleParser::LeftBracket);
              setState(192);
              antlrcpp::downCast<IfStatementContext *>(_localctx)->cond = expression(0);
              setState(193);
              match(RiddleParser::RightBracket);
              setState(194);
              antlrcpp::downCast<IfStatementContext *>(_localctx)->body = statement_ed();
              antlrcpp::downCast<IfStatementContext *>(_localctx)->hasElse = false;
              break;
          }

          case 2: {
              enterOuterAlt(_localctx, 2);
              setState(197);
              match(RiddleParser::If);
              setState(198);
              match(RiddleParser::LeftBracket);
              setState(199);
              antlrcpp::downCast<IfStatementContext *>(_localctx)->cond = expression(0);
              setState(200);
              match(RiddleParser::RightBracket);
              setState(201);
              antlrcpp::downCast<IfStatementContext *>(_localctx)->body = statement_ed();
              setState(202);
              match(RiddleParser::Else);
              setState(203);
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
    enterRule(_localctx, 26, RiddleParser::RuleReturnStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
      setState(208);
      match(RiddleParser::Return);
      setState(209);
      antlrcpp::downCast<ReturnStatementContext *>(_localctx)->result = statement_ed();

  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarClassDefineContext ------------------------------------------------------------------

RiddleParser::VarClassDefineContext::VarClassDefineContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode *RiddleParser::VarClassDefineContext::Var() {
    return getToken(RiddleParser::Var, 0);
}

tree::TerminalNode *RiddleParser::VarClassDefineContext::Colon() {
    return getToken(RiddleParser::Colon, 0);
}

tree::TerminalNode *RiddleParser::VarClassDefineContext::Identifier() {
    return getToken(RiddleParser::Identifier, 0);
}

RiddleParser::TypeNameContext *RiddleParser::VarClassDefineContext::typeName() {
    return getRuleContext<RiddleParser::TypeNameContext>(0);
}

tree::TerminalNode *RiddleParser::VarClassDefineContext::Assign() {
    return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ExpressionContext *RiddleParser::VarClassDefineContext::expression() {
    return getRuleContext<RiddleParser::ExpressionContext>(0);
}


size_t RiddleParser::VarClassDefineContext::getRuleIndex() const {
    return RiddleParser::RuleVarClassDefine;
}

void RiddleParser::VarClassDefineContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->enterVarClassDefine(this);
}

void RiddleParser::VarClassDefineContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->exitVarClassDefine(this);
}


std::any RiddleParser::VarClassDefineContext::accept(tree::ParseTreeVisitor *visitor) {
    if(auto parserVisitor = dynamic_cast<RiddleParserVisitor *>(visitor))
        return parserVisitor->visitVarClassDefine(this);
    else
        return visitor->visitChildren(this);
}

RiddleParser::VarClassDefineContext *RiddleParser::varClassDefine() {
    VarClassDefineContext *_localctx = _tracker.createInstance<VarClassDefineContext>(_ctx, getState());
    enterRule(_localctx, 28, RiddleParser::RuleVarClassDefine);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        setState(226);
        _errHandler->sync(this);
        switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
            case 1: {
                enterOuterAlt(_localctx, 1);
                setState(211);
                match(RiddleParser::Var);
                setState(212);
                antlrcpp::downCast<VarClassDefineContext *>(_localctx)->name = match(RiddleParser::Identifier);
                setState(213);
                match(RiddleParser::Colon);
                setState(214);
                antlrcpp::downCast<VarClassDefineContext *>(_localctx)->type = typeName(0);
                break;
            }

            case 2: {
                enterOuterAlt(_localctx, 2);
                setState(215);
                match(RiddleParser::Var);
                setState(216);
                antlrcpp::downCast<VarClassDefineContext *>(_localctx)->name = match(RiddleParser::Identifier);
                setState(217);
                match(RiddleParser::Assign);
                setState(218);
                antlrcpp::downCast<VarClassDefineContext *>(_localctx)->value = expression(0);
                break;
            }

            case 3: {
                enterOuterAlt(_localctx, 3);
                setState(219);
                match(RiddleParser::Var);
                setState(220);
                antlrcpp::downCast<VarClassDefineContext *>(_localctx)->name = match(RiddleParser::Identifier);
                setState(221);
                match(RiddleParser::Colon);
                setState(222);
                antlrcpp::downCast<VarClassDefineContext *>(_localctx)->type = typeName(0);
                setState(223);
                match(RiddleParser::Assign);
                setState(224);
                antlrcpp::downCast<VarClassDefineContext *>(_localctx)->value = expression(0);
                break;
            }

            default:
                break;
        }

    } catch(RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- FuncClassDefineContext ------------------------------------------------------------------

RiddleParser::FuncClassDefineContext::FuncClassDefineContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode *RiddleParser::FuncClassDefineContext::Func() {
    return getToken(RiddleParser::Func, 0);
}

tree::TerminalNode *RiddleParser::FuncClassDefineContext::LeftBracket() {
    return getToken(RiddleParser::LeftBracket, 0);
}

tree::TerminalNode *RiddleParser::FuncClassDefineContext::RightBracket() {
    return getToken(RiddleParser::RightBracket, 0);
}

tree::TerminalNode *RiddleParser::FuncClassDefineContext::LeftCurly() {
    return getToken(RiddleParser::LeftCurly, 0);
}

tree::TerminalNode *RiddleParser::FuncClassDefineContext::RightCurly() {
    return getToken(RiddleParser::RightCurly, 0);
}

tree::TerminalNode *RiddleParser::FuncClassDefineContext::Identifier() {
    return getToken(RiddleParser::Identifier, 0);
}

RiddleParser::DefineArgsContext *RiddleParser::FuncClassDefineContext::defineArgs() {
    return getRuleContext<RiddleParser::DefineArgsContext>(0);
}

RiddleParser::FuncBodyContext *RiddleParser::FuncClassDefineContext::funcBody() {
    return getRuleContext<RiddleParser::FuncBodyContext>(0);
}

tree::TerminalNode *RiddleParser::FuncClassDefineContext::Colon() {
    return getToken(RiddleParser::Colon, 0);
}

RiddleParser::TypeNameContext *RiddleParser::FuncClassDefineContext::typeName() {
    return getRuleContext<RiddleParser::TypeNameContext>(0);
}


size_t RiddleParser::FuncClassDefineContext::getRuleIndex() const {
    return RiddleParser::RuleFuncClassDefine;
}

void RiddleParser::FuncClassDefineContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->enterFuncClassDefine(this);
}

void RiddleParser::FuncClassDefineContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->exitFuncClassDefine(this);
}


std::any RiddleParser::FuncClassDefineContext::accept(tree::ParseTreeVisitor *visitor) {
    if(auto parserVisitor = dynamic_cast<RiddleParserVisitor *>(visitor))
        return parserVisitor->visitFuncClassDefine(this);
    else
        return visitor->visitChildren(this);
}

RiddleParser::FuncClassDefineContext *RiddleParser::funcClassDefine() {
    FuncClassDefineContext *_localctx = _tracker.createInstance<FuncClassDefineContext>(_ctx, getState());
    enterRule(_localctx, 30, RiddleParser::RuleFuncClassDefine);
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
        setState(228);
        match(RiddleParser::Func);
        setState(229);
        antlrcpp::downCast<FuncClassDefineContext *>(_localctx)->funcName = match(RiddleParser::Identifier);
        setState(230);
        match(RiddleParser::LeftBracket);
        setState(231);
        antlrcpp::downCast<FuncClassDefineContext *>(_localctx)->args = defineArgs();
        setState(232);
        match(RiddleParser::RightBracket);
        setState(235);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if(_la == RiddleParser::Colon) {
            setState(233);
            match(RiddleParser::Colon);
            setState(234);
            antlrcpp::downCast<FuncClassDefineContext *>(_localctx)->returnType = typeName(0);
        }
        setState(237);
        match(RiddleParser::LeftCurly);
        setState(238);
        antlrcpp::downCast<FuncClassDefineContext *>(_localctx)->body = funcBody();
        setState(239);
        match(RiddleParser::RightCurly);

    } catch(RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- DefineStatement_edContext ------------------------------------------------------------------

RiddleParser::DefineStatement_edContext::DefineStatement_edContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {
}

RiddleParser::VarClassDefineContext *RiddleParser::DefineStatement_edContext::varClassDefine() {
    return getRuleContext<RiddleParser::VarClassDefineContext>(0);
}

RiddleParser::FuncClassDefineContext *RiddleParser::DefineStatement_edContext::funcClassDefine() {
    return getRuleContext<RiddleParser::FuncClassDefineContext>(0);
}

tree::TerminalNode *RiddleParser::DefineStatement_edContext::Semi() {
    return getToken(RiddleParser::Semi, 0);
}

tree::TerminalNode *RiddleParser::DefineStatement_edContext::Endl() {
    return getToken(RiddleParser::Endl, 0);
}


size_t RiddleParser::DefineStatement_edContext::getRuleIndex() const {
    return RiddleParser::RuleDefineStatement_ed;
}

void RiddleParser::DefineStatement_edContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->enterDefineStatement_ed(this);
}

void RiddleParser::DefineStatement_edContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->exitDefineStatement_ed(this);
}


std::any RiddleParser::DefineStatement_edContext::accept(tree::ParseTreeVisitor *visitor) {
    if(auto parserVisitor = dynamic_cast<RiddleParserVisitor *>(visitor))
        return parserVisitor->visitDefineStatement_ed(this);
    else
        return visitor->visitChildren(this);
}

RiddleParser::DefineStatement_edContext *RiddleParser::defineStatement_ed() {
    DefineStatement_edContext *_localctx = _tracker.createInstance<DefineStatement_edContext>(_ctx, getState());
    enterRule(_localctx, 32, RiddleParser::RuleDefineStatement_ed);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        setState(253);
        _errHandler->sync(this);
        switch(_input->LA(1)) {
            case RiddleParser::Var:
            case RiddleParser::Func: {
                enterOuterAlt(_localctx, 1);
                setState(243);
                _errHandler->sync(this);
                switch(_input->LA(1)) {
                    case RiddleParser::Var: {
                        setState(241);
                        varClassDefine();
                        break;
                    }

                    case RiddleParser::Func: {
                        setState(242);
                        funcClassDefine();
                        break;
                    }

                    default:
                        throw NoViableAltException(this);
                }
                setState(246);
                _errHandler->sync(this);

                switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
                    case 1: {
                        setState(245);
                        match(RiddleParser::Semi);
                        break;
                    }

                    default:
                        break;
                }
                setState(249);
                _errHandler->sync(this);

                switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
                    case 1: {
                        setState(248);
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
                setState(251);
                match(RiddleParser::Semi);
                break;
            }

            case RiddleParser::Endl: {
                enterOuterAlt(_localctx, 3);
                setState(252);
                match(RiddleParser::Endl);
                break;
            }

            default:
                throw NoViableAltException(this);
        }

    } catch(RecognitionException &e) {
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

tree::TerminalNode *RiddleParser::ClassDefineContext::Class() {
    return getToken(RiddleParser::Class, 0);
}

tree::TerminalNode *RiddleParser::ClassDefineContext::LeftCurly() {
    return getToken(RiddleParser::LeftCurly, 0);
}

tree::TerminalNode *RiddleParser::ClassDefineContext::RightCurly() {
    return getToken(RiddleParser::RightCurly, 0);
}

RiddleParser::IdContext *RiddleParser::ClassDefineContext::id() {
    return getRuleContext<RiddleParser::IdContext>(0);
}

RiddleParser::ClassBodyContext *RiddleParser::ClassDefineContext::classBody() {
    return getRuleContext<RiddleParser::ClassBodyContext>(0);
}


size_t RiddleParser::ClassDefineContext::getRuleIndex() const {
    return RiddleParser::RuleClassDefine;
}

void RiddleParser::ClassDefineContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->enterClassDefine(this);
}

void RiddleParser::ClassDefineContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->exitClassDefine(this);
}


std::any RiddleParser::ClassDefineContext::accept(tree::ParseTreeVisitor *visitor) {
    if(auto parserVisitor = dynamic_cast<RiddleParserVisitor *>(visitor))
        return parserVisitor->visitClassDefine(this);
    else
        return visitor->visitChildren(this);
}

RiddleParser::ClassDefineContext *RiddleParser::classDefine() {
    ClassDefineContext *_localctx = _tracker.createInstance<ClassDefineContext>(_ctx, getState());
    enterRule(_localctx, 34, RiddleParser::RuleClassDefine);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        enterOuterAlt(_localctx, 1);
        setState(255);
        match(RiddleParser::Class);
        setState(256);
        antlrcpp::downCast<ClassDefineContext *>(_localctx)->className = id();
        setState(257);
        match(RiddleParser::LeftCurly);
        setState(258);
        antlrcpp::downCast<ClassDefineContext *>(_localctx)->body = classBody();
        setState(259);
        match(RiddleParser::RightCurly);

    } catch(RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ClassBodyContext ------------------------------------------------------------------

RiddleParser::ClassBodyContext::ClassBodyContext(ParserRuleContext *parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState) {
}

std::vector<RiddleParser::DefineStatement_edContext *> RiddleParser::ClassBodyContext::defineStatement_ed() {
    return getRuleContexts<RiddleParser::DefineStatement_edContext>();
}

RiddleParser::DefineStatement_edContext *RiddleParser::ClassBodyContext::defineStatement_ed(size_t i) {
    return getRuleContext<RiddleParser::DefineStatement_edContext>(i);
}


size_t RiddleParser::ClassBodyContext::getRuleIndex() const {
    return RiddleParser::RuleClassBody;
}

void RiddleParser::ClassBodyContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->enterClassBody(this);
}

void RiddleParser::ClassBodyContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->exitClassBody(this);
}


std::any RiddleParser::ClassBodyContext::accept(tree::ParseTreeVisitor *visitor) {
    if(auto parserVisitor = dynamic_cast<RiddleParserVisitor *>(visitor))
        return parserVisitor->visitClassBody(this);
    else
        return visitor->visitChildren(this);
}

RiddleParser::ClassBodyContext *RiddleParser::classBody() {
    ClassBodyContext *_localctx = _tracker.createInstance<ClassBodyContext>(_ctx, getState());
    enterRule(_localctx, 36, RiddleParser::RuleClassBody);
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
        setState(264);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while((((_la & ~0x3fULL) == 0) &&
               ((1ULL << _la) & 281475110928514) != 0)) {
            setState(261);
            defineStatement_ed();
            setState(266);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }

    } catch(RecognitionException &e) {
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

tree::TerminalNode *RiddleParser::FuncExprContext::LeftBracket() {
    return getToken(RiddleParser::LeftBracket, 0);
}

tree::TerminalNode *RiddleParser::FuncExprContext::RightBracket() {
    return getToken(RiddleParser::RightBracket, 0);
}

RiddleParser::IdContext *RiddleParser::FuncExprContext::id() {
    return getRuleContext<RiddleParser::IdContext>(0);
}

RiddleParser::ArgsExprContext *RiddleParser::FuncExprContext::argsExpr() {
    return getRuleContext<RiddleParser::ArgsExprContext>(0);
}

RiddleParser::FuncExprContext::FuncExprContext(ExprPtrContext *ctx) { copyFrom(ctx); }

void RiddleParser::FuncExprContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->enterFuncExpr(this);
}
void RiddleParser::FuncExprContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->exitFuncExpr(this);
}

std::any RiddleParser::FuncExprContext::accept(tree::ParseTreeVisitor *visitor) {
    if(auto parserVisitor = dynamic_cast<RiddleParserVisitor *>(visitor))
        return parserVisitor->visitFuncExpr(this);
    else
        return visitor->visitChildren(this);
}
//----------------- ObjectExprContext ------------------------------------------------------------------

RiddleParser::IdContext *RiddleParser::ObjectExprContext::id() {
    return getRuleContext<RiddleParser::IdContext>(0);
}

RiddleParser::ObjectExprContext::ObjectExprContext(ExprPtrContext *ctx) { copyFrom(ctx); }

void RiddleParser::ObjectExprContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->enterObjectExpr(this);
}
void RiddleParser::ObjectExprContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->exitObjectExpr(this);
}

std::any RiddleParser::ObjectExprContext::accept(tree::ParseTreeVisitor *visitor) {
    if(auto parserVisitor = dynamic_cast<RiddleParserVisitor *>(visitor))
        return parserVisitor->visitObjectExpr(this);
    else
        return visitor->visitChildren(this);
}
RiddleParser::ExprPtrContext *RiddleParser::exprPtr() {
    ExprPtrContext *_localctx = _tracker.createInstance<ExprPtrContext>(_ctx, getState());
    enterRule(_localctx, 38, RiddleParser::RuleExprPtr);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        setState(273);
        _errHandler->sync(this);
        switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
            case 1: {
                _localctx = _tracker.createInstance<RiddleParser::FuncExprContext>(_localctx);
                enterOuterAlt(_localctx, 1);
                setState(267);
                antlrcpp::downCast<FuncExprContext *>(_localctx)->funcName = id();
                setState(268);
                match(RiddleParser::LeftBracket);
                setState(269);
                antlrcpp::downCast<FuncExprContext *>(_localctx)->args = argsExpr();
                setState(270);
                match(RiddleParser::RightBracket);
                break;
            }

            case 2: {
                _localctx = _tracker.createInstance<RiddleParser::ObjectExprContext>(_localctx);
                enterOuterAlt(_localctx, 2);
                setState(272);
                id();
                break;
            }

            default:
                break;
        }

    } catch(RecognitionException &e) {
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

RiddleParser::ExprPtrContext *RiddleParser::SelfSubRightExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::AndAssignExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

tree::TerminalNode *RiddleParser::CastExprContext::Less() {
    return getToken(RiddleParser::Less, 0);
}

tree::TerminalNode *RiddleParser::CastExprContext::Greater() {
    return getToken(RiddleParser::Greater, 0);
}

tree::TerminalNode *RiddleParser::CastExprContext::LeftBracket() {
    return getToken(RiddleParser::LeftBracket, 0);
}

tree::TerminalNode *RiddleParser::CastExprContext::RightBracket() {
    return getToken(RiddleParser::RightBracket, 0);
}

RiddleParser::TypeNameContext *RiddleParser::CastExprContext::typeName() {
    return getRuleContext<RiddleParser::TypeNameContext>(0);
}

RiddleParser::ExprPtrContext *RiddleParser::CastExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
}

RiddleParser::CastExprContext::CastExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::CastExprContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->enterCastExpr(this);
}
void RiddleParser::CastExprContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->exitCastExpr(this);
}

std::any RiddleParser::CastExprContext::accept(tree::ParseTreeVisitor *visitor) {
    if(auto parserVisitor = dynamic_cast<RiddleParserVisitor *>(visitor))
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
//----------------- MulAssignExprContext ------------------------------------------------------------------

tree::TerminalNode* RiddleParser::MulAssignExprContext::Star() {
  return getToken(RiddleParser::Star, 0);
}

tree::TerminalNode* RiddleParser::MulAssignExprContext::Assign() {
  return getToken(RiddleParser::Assign, 0);
}

RiddleParser::ExprPtrContext *RiddleParser::MulAssignExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::XorAssignExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::AddAssignExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::OrAssignExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::PtrExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
}

RiddleParser::PtrExprContext::PtrExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void RiddleParser::PtrExprContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->enterPtrExpr(this);
}
void RiddleParser::PtrExprContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->exitPtrExpr(this);
}

std::any RiddleParser::PtrExprContext::accept(tree::ParseTreeVisitor *visitor) {
    if(auto parserVisitor = dynamic_cast<RiddleParserVisitor *>(visitor))
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

RiddleParser::ExprPtrContext *RiddleParser::DivAssignExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

tree::TerminalNode *RiddleParser::NotEqualExprContext::Assign() {
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

RiddleParser::ExprPtrContext *RiddleParser::SelfSubLeftExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::AssignExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::SelfAddRightExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::SubAssignExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::SelfAddLeftExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::LShrAssignExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::AShrAssignExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::ShlAssignExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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

RiddleParser::ExprPtrContext *RiddleParser::ModAssignExprContext::exprPtr() {
    return getRuleContext<RiddleParser::ExprPtrContext>(0);
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
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, RiddleParser::RuleExpression, precedence);


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
    setState(376);
    _errHandler->sync(this);
    switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
            _localctx = _tracker.createInstance<CastExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;

            setState(276);
            match(RiddleParser::Less);
            setState(277);
            antlrcpp::downCast<CastExprContext *>(_localctx)->type = typeName(0);
            setState(278);
            match(RiddleParser::Greater);
            setState(279);
            match(RiddleParser::LeftBracket);
            setState(280);
            antlrcpp::downCast<CastExprContext *>(_localctx)->value = exprPtr();
            setState(281);
            match(RiddleParser::RightBracket);
            break;
        }

        case 2: {
            _localctx = _tracker.createInstance<BracketExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(283);
            match(RiddleParser::LeftBracket);
            setState(284);
            antlrcpp::downCast<BracketExprContext *>(_localctx)->expr = expression(0);
            setState(285);
            match(RiddleParser::RightBracket);
            break;
        }

        case 3: {
            _localctx = _tracker.createInstance<NotExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(287);
            match(RiddleParser::Not);
            setState(288);
            antlrcpp::downCast<NotExprContext *>(_localctx)->expr = expression(44);
            break;
        }

        case 4: {
            _localctx = _tracker.createInstance<PositiveExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(289);
            match(RiddleParser::Add);
            setState(290);
            antlrcpp::downCast<PositiveExprContext *>(_localctx)->expr = expression(43);
            break;
        }

        case 5: {
            _localctx = _tracker.createInstance<NegativeExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(291);
            match(RiddleParser::Sub);
            setState(292);
            antlrcpp::downCast<NegativeExprContext *>(_localctx)->expr = expression(42);
            break;
        }

        case 6: {
            _localctx = _tracker.createInstance<SelfAddLeftExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(293);
            match(RiddleParser::Add);
            setState(294);
            match(RiddleParser::Add);
            setState(295);
            antlrcpp::downCast<SelfAddLeftExprContext *>(_localctx)->expr = exprPtr();
            break;
        }

        case 7: {
            _localctx = _tracker.createInstance<SelfAddRightExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(296);
            antlrcpp::downCast<SelfAddRightExprContext *>(_localctx)->expr = exprPtr();
            setState(297);
            match(RiddleParser::Add);
            setState(298);
            match(RiddleParser::Add);
            break;
        }

        case 8: {
            _localctx = _tracker.createInstance<SelfSubLeftExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(300);
            match(RiddleParser::Sub);
            setState(301);
            match(RiddleParser::Sub);
            setState(302);
            antlrcpp::downCast<SelfSubLeftExprContext *>(_localctx)->expr = exprPtr();
            break;
        }

        case 9: {
            _localctx = _tracker.createInstance<SelfSubRightExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(303);
            antlrcpp::downCast<SelfSubRightExprContext *>(_localctx)->expr = exprPtr();
            setState(304);
            match(RiddleParser::Sub);
            setState(305);
            match(RiddleParser::Sub);
            break;
        }

        case 10: {
            _localctx = _tracker.createInstance<PtrExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(307);
            exprPtr();
            break;
        }

        case 11: {
            _localctx = _tracker.createInstance<AssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(308);
            antlrcpp::downCast<AssignExprContext *>(_localctx)->left = exprPtr();
            setState(309);
            match(RiddleParser::Assign);
            setState(310);
            antlrcpp::downCast<AssignExprContext *>(_localctx)->right = expression(17);
            break;
        }

        case 12: {
            _localctx = _tracker.createInstance<AddAssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(312);
            antlrcpp::downCast<AddAssignExprContext *>(_localctx)->left = exprPtr();
            setState(313);
            match(RiddleParser::Add);
            setState(314);
            match(RiddleParser::Assign);
            setState(315);
            antlrcpp::downCast<AddAssignExprContext *>(_localctx)->right = expression(16);
            break;
        }

        case 13: {
            _localctx = _tracker.createInstance<SubAssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(317);
            antlrcpp::downCast<SubAssignExprContext *>(_localctx)->left = exprPtr();
            setState(318);
            match(RiddleParser::Sub);
            setState(319);
            match(RiddleParser::Assign);
            setState(320);
            antlrcpp::downCast<SubAssignExprContext *>(_localctx)->right = expression(15);
            break;
        }

        case 14: {
            _localctx = _tracker.createInstance<MulAssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(322);
            antlrcpp::downCast<MulAssignExprContext *>(_localctx)->left = exprPtr();
            setState(323);
            match(RiddleParser::Star);
            setState(324);
            match(RiddleParser::Assign);
            setState(325);
            antlrcpp::downCast<MulAssignExprContext *>(_localctx)->right = expression(14);
            break;
        }

        case 15: {
            _localctx = _tracker.createInstance<DivAssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(327);
            antlrcpp::downCast<DivAssignExprContext *>(_localctx)->left = exprPtr();
            setState(328);
            match(RiddleParser::Div);
            setState(329);
            match(RiddleParser::Assign);
            setState(330);
            antlrcpp::downCast<DivAssignExprContext *>(_localctx)->right = expression(13);
            break;
        }

        case 16: {
            _localctx = _tracker.createInstance<ModAssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(332);
            antlrcpp::downCast<ModAssignExprContext *>(_localctx)->left = exprPtr();
            setState(333);
            match(RiddleParser::Mod);
            setState(334);
            match(RiddleParser::Assign);
            setState(335);
            antlrcpp::downCast<ModAssignExprContext *>(_localctx)->right = expression(12);
            break;
        }

        case 17: {
            _localctx = _tracker.createInstance<AddAssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(337);
            antlrcpp::downCast<AddAssignExprContext *>(_localctx)->left = exprPtr();
            setState(338);
            match(RiddleParser::Add);
            setState(339);
            match(RiddleParser::Assign);
            setState(340);
            antlrcpp::downCast<AddAssignExprContext *>(_localctx)->right = expression(11);
            break;
        }

        case 18: {
            _localctx = _tracker.createInstance<AndAssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(342);
            antlrcpp::downCast<AndAssignExprContext *>(_localctx)->left = exprPtr();
            setState(343);
            match(RiddleParser::And);
            setState(344);
            match(RiddleParser::Assign);
            setState(345);
            antlrcpp::downCast<AndAssignExprContext *>(_localctx)->right = expression(10);
            break;
        }

        case 19: {
            _localctx = _tracker.createInstance<OrAssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(347);
            antlrcpp::downCast<OrAssignExprContext *>(_localctx)->left = exprPtr();
            setState(348);
            match(RiddleParser::Or);
            setState(349);
            match(RiddleParser::Assign);
            setState(350);
            antlrcpp::downCast<OrAssignExprContext *>(_localctx)->right = expression(9);
            break;
        }

        case 20: {
            _localctx = _tracker.createInstance<XorAssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(352);
            antlrcpp::downCast<XorAssignExprContext *>(_localctx)->left = exprPtr();
            setState(353);
            match(RiddleParser::Xor);
            setState(354);
            match(RiddleParser::Assign);
            setState(355);
            antlrcpp::downCast<XorAssignExprContext *>(_localctx)->right = expression(8);
            break;
        }

        case 21: {
            _localctx = _tracker.createInstance<ShlAssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(357);
            antlrcpp::downCast<ShlAssignExprContext *>(_localctx)->left = exprPtr();
            setState(358);
            match(RiddleParser::LeftLeft);
            setState(359);
            match(RiddleParser::Assign);
            setState(360);
            antlrcpp::downCast<ShlAssignExprContext *>(_localctx)->right = expression(7);
            break;
        }

        case 22: {
            _localctx = _tracker.createInstance<AShrAssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(362);
            antlrcpp::downCast<AShrAssignExprContext *>(_localctx)->left = exprPtr();
            setState(363);
            match(RiddleParser::RightRight);
            setState(364);
            match(RiddleParser::Assign);
            setState(365);
            antlrcpp::downCast<AShrAssignExprContext *>(_localctx)->right = expression(6);
            break;
        }

        case 23: {
            _localctx = _tracker.createInstance<LShrAssignExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(367);
            antlrcpp::downCast<LShrAssignExprContext *>(_localctx)->left = exprPtr();
            setState(368);
            match(RiddleParser::RightRightRight);
            setState(369);
            match(RiddleParser::Assign);
            setState(370);
            antlrcpp::downCast<LShrAssignExprContext *>(_localctx)->right = expression(5);
            break;
        }

        case 24: {
            _localctx = _tracker.createInstance<StringExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(372);
            string();
            break;
        }

        case 25: {
            _localctx = _tracker.createInstance<NumberExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(373);
            number();
            break;
        }

        case 26: {
            _localctx = _tracker.createInstance<BooleanExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(374);
            boolean();
            break;
        }

        case 27: {
            _localctx = _tracker.createInstance<ObjValExprContext>(_localctx);
            _ctx = _localctx;
            previousContext = _localctx;
            setState(375);
            id();
            break;
        }

        default:
            break;
    }
    _ctx->stop = _input->LT(-1);
    setState(442);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(440);
        _errHandler->sync(this);
        switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
            case 1: {
                auto newContext = _tracker.createInstance<MulExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
                _localctx = newContext;
                newContext->left = previousContext;
                pushNewRecursionContext(newContext, startState, RuleExpression);
                setState(378);

                if(!(precpred(_ctx, 36))) throw FailedPredicateException(this, "precpred(_ctx, 36)");
                setState(379);
                match(RiddleParser::Star);
                setState(380);
                antlrcpp::downCast<MulExprContext *>(_localctx)->right = expression(37);
                break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DivExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(381);

          if (!(precpred(_ctx, 35))) throw FailedPredicateException(this, "precpred(_ctx, 35)");
          setState(382);
          match(RiddleParser::Div);
          setState(383);
          antlrcpp::downCast<DivExprContext *>(_localctx)->right = expression(36);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ModExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(384);

          if (!(precpred(_ctx, 34))) throw FailedPredicateException(this, "precpred(_ctx, 34)");
          setState(385);
          match(RiddleParser::Mod);
          setState(386);
          antlrcpp::downCast<ModExprContext *>(_localctx)->right = expression(35);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<AddExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(387);

          if (!(precpred(_ctx, 33))) throw FailedPredicateException(this, "precpred(_ctx, 33)");
          setState(388);
          match(RiddleParser::Add);
          setState(389);
          antlrcpp::downCast<AddExprContext *>(_localctx)->right = expression(34);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<SubExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(390);

          if (!(precpred(_ctx, 32))) throw FailedPredicateException(this, "precpred(_ctx, 32)");
          setState(391);
          match(RiddleParser::Sub);
          setState(392);
          antlrcpp::downCast<SubExprContext *>(_localctx)->right = expression(33);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ShlExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(393);

          if (!(precpred(_ctx, 31))) throw FailedPredicateException(this, "precpred(_ctx, 31)");
          setState(394);
          match(RiddleParser::LeftLeft);
          setState(395);
          antlrcpp::downCast<ShlExprContext *>(_localctx)->right = expression(32);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<AShrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(396);

          if (!(precpred(_ctx, 30))) throw FailedPredicateException(this, "precpred(_ctx, 30)");
          setState(397);
          match(RiddleParser::RightRight);
          setState(398);
          antlrcpp::downCast<AShrExprContext *>(_localctx)->right = expression(31);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<LShrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(399);

          if (!(precpred(_ctx, 29))) throw FailedPredicateException(this, "precpred(_ctx, 29)");
          setState(400);
          match(RiddleParser::RightRightRight);
          setState(401);
          antlrcpp::downCast<LShrExprContext *>(_localctx)->right = expression(30);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<GreaterExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(402);

          if (!(precpred(_ctx, 28))) throw FailedPredicateException(this, "precpred(_ctx, 28)");
          setState(403);
          match(RiddleParser::Greater);
          setState(404);
          antlrcpp::downCast<GreaterExprContext *>(_localctx)->right = expression(29);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<LessExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(405);

          if (!(precpred(_ctx, 27))) throw FailedPredicateException(this, "precpred(_ctx, 27)");
          setState(406);
          match(RiddleParser::Less);
          setState(407);
          antlrcpp::downCast<LessExprContext *>(_localctx)->right = expression(28);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<GreaterEqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(408);

          if (!(precpred(_ctx, 26))) throw FailedPredicateException(this, "precpred(_ctx, 26)");
          setState(409);
          match(RiddleParser::Greater);
          setState(410);
          match(RiddleParser::Assign);
          setState(411);
          antlrcpp::downCast<GreaterEqualExprContext *>(_localctx)->right = expression(27);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<LessEqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(412);

          if (!(precpred(_ctx, 25))) throw FailedPredicateException(this, "precpred(_ctx, 25)");
          setState(413);
          match(RiddleParser::Less);
          setState(414);
          match(RiddleParser::Assign);
          setState(415);
          antlrcpp::downCast<LessEqualExprContext *>(_localctx)->right = expression(26);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<EqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(416);

          if (!(precpred(_ctx, 24))) throw FailedPredicateException(this, "precpred(_ctx, 24)");
          setState(417);
          match(RiddleParser::Equal);
          setState(418);
          antlrcpp::downCast<EqualExprContext *>(_localctx)->right = expression(25);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<NotEqualExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(419);

          if (!(precpred(_ctx, 23))) throw FailedPredicateException(this, "precpred(_ctx, 23)");
          setState(420);
          match(RiddleParser::Not);
          setState(421);
          match(RiddleParser::Assign);
          setState(422);
          antlrcpp::downCast<NotEqualExprContext *>(_localctx)->right = expression(24);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<BitAndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(423);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(424);
          match(RiddleParser::And);
          setState(425);
          antlrcpp::downCast<BitAndExprContext *>(_localctx)->right = expression(23);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<BitXorExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(426);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(427);
          match(RiddleParser::Xor);
          setState(428);
          antlrcpp::downCast<BitXorExprContext *>(_localctx)->right = expression(22);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<BitOrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(429);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(430);
          match(RiddleParser::Or);
          setState(431);
          antlrcpp::downCast<BitOrExprContext *>(_localctx)->right = expression(21);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(432);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(433);
          match(RiddleParser::And);
          setState(434);
          match(RiddleParser::And);
          setState(435);
          antlrcpp::downCast<AndExprContext *>(_localctx)->right = expression(20);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(436);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(437);
          match(RiddleParser::Or);
          setState(438);
          match(RiddleParser::Or);
          setState(439);
          antlrcpp::downCast<OrExprContext *>(_localctx)->right = expression(19);
          break;
        }

        default:
          break;
        } 
      }
      setState(444);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
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
    enterRule(_localctx, 42, RiddleParser::RuleId);

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
    setState(445);
    match(RiddleParser::Identifier);
    setState(450);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
            setState(446);
            match(RiddleParser::Dot);
            setState(447);
            match(RiddleParser::Identifier);
        }
        setState(452);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
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
    enterRule(_localctx, 44, RiddleParser::RuleNumber);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
      setState(455);
      _errHandler->sync(this);
      switch(_input->LA(1)) {
          case RiddleParser::Hexadecimal:
          case RiddleParser::Decimal:
          case RiddleParser::Octal:
          case RiddleParser::Binary: {
              enterOuterAlt(_localctx, 1);
              setState(453);
              integer();
              break;
          }

          case RiddleParser::Float: {
              enterOuterAlt(_localctx, 2);
              setState(454);
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
    enterRule(_localctx, 46, RiddleParser::RuleBoolean);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
      setState(461);
      _errHandler->sync(this);
      switch(_input->LA(1)) {
          case RiddleParser::True: {
              enterOuterAlt(_localctx, 1);
              setState(457);
              match(RiddleParser::True);
              antlrcpp::downCast<BooleanContext *>(_localctx)->value = true;
              break;
          }

          case RiddleParser::False: {
              enterOuterAlt(_localctx, 2);
              setState(459);
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
    enterRule(_localctx, 48, RiddleParser::RuleString);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
      setState(463);
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
    enterRule(_localctx, 50, RiddleParser::RuleFloat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
      setState(465);
      antlrcpp::downCast<FloatContext *>(_localctx)->floatToken = match(RiddleParser::Float);

      antlrcpp::downCast<FloatContext *>(_localctx)->value = stod((antlrcpp::downCast<FloatContext *>(_localctx)->floatToken != nullptr ? antlrcpp::downCast<FloatContext *>(_localctx)->floatToken->getText() : ""));


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
    enterRule(_localctx, 52, RiddleParser::RuleInteger);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
      setState(476);
      _errHandler->sync(this);
      switch(_input->LA(1)) {
          case RiddleParser::Decimal: {
              enterOuterAlt(_localctx, 1);
              setState(468);
              antlrcpp::downCast<IntegerContext *>(_localctx)->decimalToken = match(RiddleParser::Decimal);

              antlrcpp::downCast<IntegerContext *>(_localctx)->value = stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->decimalToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->decimalToken->getText() : ""));

              break;
          }

          case RiddleParser::Hexadecimal: {
              enterOuterAlt(_localctx, 2);
              setState(470);
              antlrcpp::downCast<IntegerContext *>(_localctx)->hexadecimalToken = match(RiddleParser::Hexadecimal);

              antlrcpp::downCast<IntegerContext *>(_localctx)->value = stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->hexadecimalToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->hexadecimalToken->getText() : "").substr(2), nullptr, 16);

              break;
          }

          case RiddleParser::Binary: {
              enterOuterAlt(_localctx, 3);
              setState(472);
              antlrcpp::downCast<IntegerContext *>(_localctx)->binaryToken = match(RiddleParser::Binary);

              antlrcpp::downCast<IntegerContext *>(_localctx)->value = stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->binaryToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->binaryToken->getText() : "").substr(2), nullptr, 2);

              break;
          }

          case RiddleParser::Octal: {
              enterOuterAlt(_localctx, 4);
              setState(474);
              antlrcpp::downCast<IntegerContext *>(_localctx)->octalToken = match(RiddleParser::Octal);

              antlrcpp::downCast<IntegerContext *>(_localctx)->value = stoi((antlrcpp::downCast<IntegerContext *>(_localctx)->octalToken != nullptr ? antlrcpp::downCast<IntegerContext *>(_localctx)->octalToken->getText() : "").substr(1), nullptr, 8);

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

RiddleParser::ExpressionContext *RiddleParser::TemplateArgContext::expression() {
    return getRuleContext<RiddleParser::ExpressionContext>(0);
}

RiddleParser::TypeNameContext *RiddleParser::TemplateArgContext::typeName() {
    return getRuleContext<RiddleParser::TypeNameContext>(0);
}


size_t RiddleParser::TemplateArgContext::getRuleIndex() const {
    return RiddleParser::RuleTemplateArg;
}

void RiddleParser::TemplateArgContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->enterTemplateArg(this);
}

void RiddleParser::TemplateArgContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->exitTemplateArg(this);
}


std::any RiddleParser::TemplateArgContext::accept(tree::ParseTreeVisitor *visitor) {
    if(auto parserVisitor = dynamic_cast<RiddleParserVisitor *>(visitor))
        return parserVisitor->visitTemplateArg(this);
    else
        return visitor->visitChildren(this);
}

RiddleParser::TemplateArgContext *RiddleParser::templateArg() {
    TemplateArgContext *_localctx = _tracker.createInstance<TemplateArgContext>(_ctx, getState());
    enterRule(_localctx, 54, RiddleParser::RuleTemplateArg);

#if __cplusplus > 201703L
    auto onExit = finally([=, this] {
#else
    auto onExit = finally([=] {
#endif
        exitRule();
    });
    try {
        setState(480);
        _errHandler->sync(this);
        switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
            case 1: {
                enterOuterAlt(_localctx, 1);
                setState(478);
                expression(0);
                break;
            }

            case 2: {
                enterOuterAlt(_localctx, 2);
                setState(479);
                typeName(0);
                break;
            }

            default:
                break;
        }

    } catch(RecognitionException &e) {
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

RiddleParser::TemplateArgContext *RiddleParser::TemplateArgsContext::templateArg(size_t i) {
    return getRuleContext<RiddleParser::TemplateArgContext>(i);
}

std::vector<tree::TerminalNode *> RiddleParser::TemplateArgsContext::Comma() {
    return getTokens(RiddleParser::Comma);
}

tree::TerminalNode *RiddleParser::TemplateArgsContext::Comma(size_t i) {
    return getToken(RiddleParser::Comma, i);
}


size_t RiddleParser::TemplateArgsContext::getRuleIndex() const {
    return RiddleParser::RuleTemplateArgs;
}

void RiddleParser::TemplateArgsContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->enterTemplateArgs(this);
}

void RiddleParser::TemplateArgsContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->exitTemplateArgs(this);
}


std::any RiddleParser::TemplateArgsContext::accept(tree::ParseTreeVisitor *visitor) {
    if(auto parserVisitor = dynamic_cast<RiddleParserVisitor *>(visitor))
        return parserVisitor->visitTemplateArgs(this);
    else
        return visitor->visitChildren(this);
}

RiddleParser::TemplateArgsContext *RiddleParser::templateArgs() {
    TemplateArgsContext *_localctx = _tracker.createInstance<TemplateArgsContext>(_ctx, getState());
    enterRule(_localctx, 56, RiddleParser::RuleTemplateArgs);
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
        setState(491);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if((((_la & ~0x3fULL) == 0) &&
            ((1ULL << _la) & 1188389761150287872) != 0)) {
            setState(487);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
            while(alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                if(alt == 1) {
                    setState(482);
                    templateArg();
                    setState(483);
                    match(RiddleParser::Comma);
                }
                setState(489);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
            }
            setState(490);
            templateArg();
        }

    } catch(RecognitionException &e) {
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

RiddleParser::IdContext *RiddleParser::TypeNameContext::id() {
    return getRuleContext<RiddleParser::IdContext>(0);
}

tree::TerminalNode *RiddleParser::TypeNameContext::Less() {
    return getToken(RiddleParser::Less, 0);
}

tree::TerminalNode *RiddleParser::TypeNameContext::Greater() {
    return getToken(RiddleParser::Greater, 0);
}

RiddleParser::TemplateArgsContext *RiddleParser::TypeNameContext::templateArgs() {
    return getRuleContext<RiddleParser::TemplateArgsContext>(0);
}

tree::TerminalNode *RiddleParser::TypeNameContext::LeftSquare() {
    return getToken(RiddleParser::LeftSquare, 0);
}

tree::TerminalNode *RiddleParser::TypeNameContext::RightSquare() {
    return getToken(RiddleParser::RightSquare, 0);
}

RiddleParser::TypeNameContext *RiddleParser::TypeNameContext::typeName() {
    return getRuleContext<RiddleParser::TypeNameContext>(0);
}

RiddleParser::ExpressionContext *RiddleParser::TypeNameContext::expression() {
    return getRuleContext<RiddleParser::ExpressionContext>(0);
}


size_t RiddleParser::TypeNameContext::getRuleIndex() const {
    return RiddleParser::RuleTypeName;
}

void RiddleParser::TypeNameContext::enterRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->enterTypeName(this);
}

void RiddleParser::TypeNameContext::exitRule(tree::ParseTreeListener *listener) {
    auto parserListener = dynamic_cast<RiddleParserListener *>(listener);
    if(parserListener != nullptr)
        parserListener->exitTypeName(this);
}


std::any RiddleParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
    if(auto parserVisitor = dynamic_cast<RiddleParserVisitor *>(visitor))
        return parserVisitor->visitTypeName(this);
    else
        return visitor->visitChildren(this);
}


RiddleParser::TypeNameContext *RiddleParser::typeName() {
    return typeName(0);
}

RiddleParser::TypeNameContext *RiddleParser::typeName(int precedence) {
    ParserRuleContext *parentContext = _ctx;
    size_t parentState = getState();
    RiddleParser::TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, parentState);
    RiddleParser::TypeNameContext *previousContext = _localctx;
    (void)previousContext;// Silence compiler, in case the context is not used by generated code.
    size_t startState = 58;
    enterRecursionRule(_localctx, 58, RiddleParser::RuleTypeName, precedence);


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
        setState(500);
        _errHandler->sync(this);
        switch(getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
            case 1: {
                setState(494);
                antlrcpp::downCast<TypeNameContext *>(_localctx)->name = id();
                break;
            }

            case 2: {
                setState(495);
                antlrcpp::downCast<TypeNameContext *>(_localctx)->name = id();
                setState(496);
                match(RiddleParser::Less);
                setState(497);
                antlrcpp::downCast<TypeNameContext *>(_localctx)->args = templateArgs();
                setState(498);
                match(RiddleParser::Greater);
                break;
            }

            default:
                break;
        }
        _ctx->stop = _input->LT(-1);
        setState(509);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
        while(alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if(alt == 1) {
                if(!_parseListeners.empty())
                    triggerExitRuleEvent();
                previousContext = _localctx;
                _localctx = _tracker.createInstance<TypeNameContext>(parentContext, parentState);
                _localctx->baseType = previousContext;
                pushNewRecursionContext(_localctx, startState, RuleTypeName);
                setState(502);

                if(!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
                setState(503);
                match(RiddleParser::LeftSquare);
                setState(504);
                antlrcpp::downCast<TypeNameContext *>(_localctx)->size = expression(0);
                setState(505);
                match(RiddleParser::RightSquare);
            }
            setState(511);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
        }
    } catch(RecognitionException &e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }
    return _localctx;
}

bool RiddleParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
        case 20:
            return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);
        case 29:
            return typeNameSempred(antlrcpp::downCast<TypeNameContext *>(context), predicateIndex);

        default:
            break;
  }
  return true;
}

bool RiddleParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
        case 0:
            return precpred(_ctx, 36);
        case 1:
            return precpred(_ctx, 35);
        case 2:
            return precpred(_ctx, 34);
        case 3:
            return precpred(_ctx, 33);
        case 4:
            return precpred(_ctx, 32);
        case 5:
            return precpred(_ctx, 31);
        case 6:
            return precpred(_ctx, 30);
        case 7:
            return precpred(_ctx, 29);
        case 8:
            return precpred(_ctx, 28);
        case 9:
            return precpred(_ctx, 27);
        case 10:
            return precpred(_ctx, 26);
        case 11:
            return precpred(_ctx, 25);
        case 12:
            return precpred(_ctx, 24);
        case 13:
            return precpred(_ctx, 23);
        case 14:
            return precpred(_ctx, 22);
        case 15:
            return precpred(_ctx, 21);
        case 16:
            return precpred(_ctx, 20);
        case 17:
            return precpred(_ctx, 19);
        case 18:
            return precpred(_ctx, 18);

        default:
            break;
  }
  return true;
}

bool RiddleParser::typeNameSempred(TypeNameContext *_localctx, size_t predicateIndex) {
    switch(predicateIndex) {
        case 19:
            return precpred(_ctx, 1);

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
