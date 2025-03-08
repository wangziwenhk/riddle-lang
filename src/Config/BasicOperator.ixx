module;
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "Support/Hash.hpp"
export module Config.BasicOperator;
import Config.BasicType;
export namespace Riddle {
    namespace NumOp {
        inline std::vector<std::string> list = {
            "+", "-", "*", "/", "%", ">>", "<<", "&",
            "|", "^", "<", ">", "<=", ">=", "==", "!=",
            "+=", "-=", "*=", "/=", "%=", ">>=", "<<=",
            "^=", "&=", "~="
        };
        inline std::unordered_set<std::string> set = {
            "+", "-", "*", "/", "%", ">>", "<<", "&",
            "|", "^", "<", ">", "<=", ">=", "==", "!=",
            "+=", "-=", "*=", "/=", "%=", ">>=", "<<=",
            "^=", "&=", "~="
        };
    } // namespace NumOp

    namespace LogicOp {
        inline std::vector<std::string> list = {"&&", "||"};
        inline std::unordered_set<std::string> set = {"&&", "||"};
    } // namespace LogicOp

    inline std::unordered_map<std::tuple<std::string, std::string, std::string>, std::string> numOpReType;

    void initBasicOpReType() {
        for (const auto &i: BasicType::list) {
            for (const auto &j: NumOp::list) {
                numOpReType.insert({std::make_tuple(i, i, j), i});
            }
        }
    }
} // namespace Riddle
