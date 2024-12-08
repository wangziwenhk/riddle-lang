module;
#include <string>
export module lang.English;
export import lang.BaseLang;
export namespace Riddle {
    class EnglishLang final : public BaseLang {
    public:
        EnglishLang(): BaseLang(en_us){}
        std::string syntaxError() override {
            return "Lexer error at line";
        }
        std::string extraneousInput() override {
            return "extraneous input";
        }
        std::string recognitionError() override {
            return "recognition error";
        }
        std::string noViableAlternativeAtInput() override{
            return "no viable alternative at input";
        }
    };
}// namespace Riddle