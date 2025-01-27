module;
#include <format>
#include <ranges>
#include <string>
#include <utility>
#include <vector>
export module Type.Identifier;
export namespace Riddle {
    class Identifier {
    public:
        std::vector<std::string> id;
        Identifier() = default;
        explicit Identifier(std::vector<std::string> id): id(std::move(id)) {}
        explicit Identifier(const std::string &str) {
            auto segments = str | std::views::split('.');
            id.reserve(std::distance(segments.begin(), segments.end()));
            for(auto &&segment: segments) {
                id.emplace_back(segment.begin(), segment.end());
            }
        }

        [[nodiscard]] bool empty() const { return id.empty(); }

        [[nodiscard]] std::string toString() const {
            std::string s;
            for(const auto& i:id) {
                s += i;
            }
            return s;
        }
    };
}// namespace Riddle
