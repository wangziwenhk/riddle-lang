module;
#include <string>
#include <utility>
#include <vector>
export module Support.Package;
export namespace Riddle {
    class Package {
        std::string name;
        std::vector<std::string> depend;

    public:
        Package() = default;
        explicit Package(std::string name): name(std::move(name)) {
        }

        [[nodiscard]] std::string getName() const {
            return name;
        }

        void setName(const std::string &name) {
            this->name = name;
        }

        void addDepend(const std::string &lib) {
            this->depend.push_back(lib);
        }

        [[nodiscard]] std::vector<std::string> getDepend() const {
            return depend;
        }
    };
} // namespace Riddle
