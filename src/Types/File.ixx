module;
#include <string>
#include <utility>
#include <vector>
export module Type.File;
namespace Riddle {
    class File {
    public:
        std::vector<std::string> contents;
        explicit File(std::vector<std::string> contents) : contents(std::move(contents)) {}
    };
}