module;
#include <string>
#include <unordered_set>
#include <vector>
export module Config.BasicType;
export namespace Riddle::BasicType {
#define BTNS "int", "short", "long", "char", "bool", "double", "float"
    inline std::vector<std::string> list = {BTNS};
    inline std::unordered_set<std::string> set = {BTNS};
#undef BTNS
} // namespace Riddle::BasicType
