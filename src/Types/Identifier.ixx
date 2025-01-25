module;
#include <string>
#include <utility>
#include <vector>
#include <ranges>
export module Type.Identifier;
export namespace Riddle {
    class Identifier {
    public:
        std::vector<std::string> id;
        Identifier() = default;
        explicit Identifier(std::vector<std::string> id) : id(std::move(id)) {}
        explicit Identifier(const std::string& str) {
            auto segments = str | std::views::split('.');
            id.reserve(std::distance(segments.begin(), segments.end()));
            for (auto&& segment : segments) {
                id.emplace_back(segment.begin(), segment.end());
            }
        }
    };
}// namespace Riddle