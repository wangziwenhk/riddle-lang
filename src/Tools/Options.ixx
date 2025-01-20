module;
#include <string>
#include <utility>
export module Tools.Options;
export namespace Riddle {
    class Option {
    public:
        std::string source;
        std::string output;

        Option() = default;
        explicit Option(std::string source): source(std::move(source)) {
            output = this->source + ".ll";
        }
    };
}// namespace Riddle
