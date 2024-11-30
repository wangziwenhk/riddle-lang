module;
#include <antlr4-runtime.h>
#include <string>
export module ErrorManager;
#define ull unsigned long long
namespace Riddle {
    std::string getLineText(antlr4::CharStream *inputStream, size_t line) {
        std::string lineText;
        size_t currentLine = 1;

        // 从输入流中逐个字符读取，直到找到目标行
        size_t currentPos = 0;
        while(currentPos < inputStream->size()) {
            char c = inputStream->LA(1);// 获取当前字符
            inputStream->consume();
            ++currentPos;

            // 当读取到换行符时，检查是否为目标行
            if(c == '\n') {
                if(currentLine == line) {
                    break;
                }
                ++currentLine;
            }
            // 如果是目标行，保存字符
            if(currentLine == line) {
                lineText += c;
            }
        }

        return lineText;
    }
}

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
            auto inputStream = dynamic_cast<antlr4::CharStream*>(recognizer->getInputStream());
            std::string lineText = getLineText(inputStream, line-1);
            std::cerr << lineText << '\n';
            std::cerr << "Lexer error at line " << line << ":" << charPositionInLine << " - " << msg << std::endl;
        }
    };
}