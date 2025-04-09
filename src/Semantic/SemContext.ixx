module;
#include <stack>
#include <string>
#include <unordered_map>
export module Semantic.SemContext;
export namespace Riddle {
    class SemObject {
    public:
        ~SemObject();
    };
    class SemContext {
        std::unordered_map<std::string, std::stack<void *>> objects;

    public:
    };
} // namespace Riddle
