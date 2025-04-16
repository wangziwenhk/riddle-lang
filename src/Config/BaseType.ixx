module;
#include <string>
#include <unordered_set>
export module Config.BaseType;

export namespace Riddle {
    std::unordered_set<std::string> baseType = {"int", "void", "long", "char", "bool", "short", "double", "float"};

    bool isBaseType(const std::string &type) {
        return baseType.contains(type);
    }
}
