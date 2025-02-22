module;
#include <string>
#include <unordered_set>
#include <vector>
export module Config.BasicType;
export namespace Riddle::basic_type {
#define BTNS "int", "short", "long", "char", "bool", "double", "float"
    std::vector<std::string> list = {
            BTNS};
    std::unordered_set<std::string> set = {
            BTNS};
#undef BTNS
}// namespace Riddle::basic_type