module;
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "Support/Hash.hpp"
export module Config.BasicOperator;
import Config.BasicType;

export namespace Riddle {
    inline std::vector<std::string> ArithmeticBinaryOperatorList = {"+", "-", "*", "/", "%", ">>", "<<", "&", "|", "^"};
    inline std::unordered_map<std::tuple<std::string, std::string, std::string>, std::string> basicOpReType;
} // namespace Riddle

namespace Riddle {
    __attribute__((constructor)) void initBasicOpReType() {
        std::cout << ArithmeticBinaryOperatorList.size() << std::endl;

        for (const auto &i: basicType::list) {
            for (const auto &j: ArithmeticBinaryOperatorList) {
                basicOpReType.insert({std::make_tuple(i, i, j), i});
            }
        }
    }
} // namespace Riddle
