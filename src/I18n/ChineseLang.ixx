module;
#include <string>
export module lang.Chinese;
export import lang.BaseLang;
export namespace Riddle {
    class ChineseLang final : public BaseLang {
    public:
        ChineseLang():BaseLang(zh_cn){}
        std::string syntaxError() override {
            return "不正确的语法";
        }
        std::string extraneousInput() override {
            return "额外的输入";
        }
        std::string recognitionError() override {
            return "不存在的语法";
        }
        std::string noViableAlternativeAtInput() override{
            return "没有可行的替代方案";
        }
    };
}// namespace Riddle