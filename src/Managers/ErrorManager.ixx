module;
#include <antlr4-runtime.h>
#include <string>
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
        void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol,
                         const size_t line, const size_t charPositionInLine, const std::string &msg,
                         std::exception_ptr e) override {
            std::cerr<<recognizer->getState()<<std::endl;
            if(msg.find("extraneous input") != std::string::npos) {
                std::cerr << BaseLang::nowLangClass->extraneousInput() << " " << line << ":" << charPositionInLine << " - " << msg << std::endl;
            }
            else if(msg.find("recognition error")!=std::string::npos) {
                std::cerr << BaseLang::nowLangClass->syntaxError() << " " << line << ":" << charPositionInLine << " - " << msg << std::endl;
            }

        }
    };
}// namespace Riddle