module;
#include <antlr4-runtime.h>
#include <string>
#include "RiddleParser.h"
export module ErrorManager;
#define ull unsigned long long
import lang.BaseLang;
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
            std::cerr << BaseLang::nowLangClass->recognitionError() << " " << line << ":" << charPositionInLine << " - " << msg << std::endl;
        }
    };

    class ParserErrorListener final : public antlr4::BaseErrorListener {
    public:
        std::vector<std::string>lines;

        void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol,
                         const size_t line, const size_t charPositionInLine, const std::string &msg,
                         const std::exception_ptr e) override {
            if(auto parse = dynamic_cast<RiddleParser *>(recognizer)) {
                // parse->setTrace(true);
                const std::string errorRule = recognizer->getRuleNames()[parse->getRuleContext()->getRuleIndex()];
                if(errorRule == "varDefineStatement") {
                    varDefineError(recognizer, offendingSymbol, line, charPositionInLine, msg, e);
                }
            }
            if(msg.find("extraneous input") != std::string::npos) {
                std::cerr << BaseLang::nowLangClass->extraneousInput() << " " << line << ":" << charPositionInLine << " - " << msg << std::endl;
            } else if(msg.find("recognition error") != std::string::npos) {
                std::cerr << BaseLang::nowLangClass->syntaxError() << " " << line << ":" << charPositionInLine << " - " << msg << std::endl;
            }
        }
        static void varDefineError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol,
                         const size_t line, const size_t charPositionInLine, const std::string &msg,
                         std::exception_ptr e) {
            auto parse = dynamic_cast<RiddleParser*>(recognizer);
            if(!parse) {
                return;
            }
            std::cerr << "VarDefineError";
            if(const auto it1 = msg.find("no viable alternative at input");it1!=std::string::npos) {
                std::cerr << " " << line << ":" << charPositionInLine << " - " << BaseLang::nowLangClass->noViableAlternativeAtInput() << std::endl;
            }
        }
    };
}// namespace Riddle