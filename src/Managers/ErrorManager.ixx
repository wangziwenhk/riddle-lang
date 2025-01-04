module;
#include "RiddleParser.h"
#include <antlr4-runtime.h>
#include <string>
export module managers.ErrorManager;
#define ull unsigned long long
export namespace Riddle {
    /// @brief 所有错误的基本类
    class BaseError {
    public:
        std::string fileName;
        std::string msg;
        unsigned long long row;
        unsigned long long column;

        BaseError(std::string fileName, std::string msg, const ull row, const ull column): fileName(std::move(fileName)), msg(std::move(msg)), row(row), column(column) {}
    };

    /// @brief 语法错误
    class SyntaxError : public BaseError {
    };

    class LexerErrorListener final : public antlr4::BaseErrorListener {
    public:
        void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol,
                         const size_t line, const size_t charPositionInLine, const std::string &msg,
                         std::exception_ptr e) override {
            std::cerr << msg << " " << line << ":" << charPositionInLine << " - " << msg << std::endl;
        }
    };

    class ParserErrorListener final : public antlr4::BaseErrorListener {
    public:
        std::vector<std::string> lines;

        void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol,
                         const size_t line, const size_t charPositionInLine, const std::string &msg,
                         const std::exception_ptr e) override {
            if(const auto parse = dynamic_cast<RiddleParser *>(recognizer)) {
                // parse->setTrace(true);
                const std::string errorRule = recognizer->getRuleNames()[parse->getRuleContext()->getRuleIndex()];
                if(errorRule == "varDefineStatement") {
                    varDefineError(recognizer, offendingSymbol, line, charPositionInLine, msg, e);
                }
            }
            std::cerr << msg << " " << line << ":" << charPositionInLine << " - " << msg << std::endl;
        }
        static void varDefineError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol,
                                   const size_t line, const size_t charPositionInLine, const std::string &msg,
                                   std::exception_ptr e) {
            const auto parse = dynamic_cast<RiddleParser *>(recognizer);
            if(!parse) {
                return;
            }
            std::cerr << "VarDefineError";
            std::cerr << msg << " " << line << ":" << charPositionInLine << " - " << msg << std::endl;
        }
    };
}// namespace Riddle