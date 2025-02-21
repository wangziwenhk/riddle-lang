module;
#include <string>
#include <utility>
export module Support.File;
export namespace Riddle {
    class File {
    public:
        std::string source;
        std::string output;

        File() = default;
        explicit File(std::string source): source(std::move(source)) {
            output = this->source + ".ll";
        }
    };
}// namespace Riddle
