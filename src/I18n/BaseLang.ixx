module;
#include <string>
export module lang.BaseLang;

export namespace Riddle {
    enum LangType {
        zh_cn,
        en_us,
    };
    class BaseLang {
    protected:
        LangType langType;

    public:
        explicit BaseLang(const LangType type) : langType(type) {}
        static BaseLang *nowLangClass;
        virtual ~BaseLang() = default;
        virtual std::string syntaxError() = 0;
        virtual std::string extraneousInput() = 0;
        virtual std::string recognitionError() = 0;
        virtual std::string noViableAlternativeAtInput() = 0;
        [[nodiscard]] LangType getLangType() const {
            return langType;
        }
    };

}// namespace Riddle
