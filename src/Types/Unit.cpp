//
// Created by wangz on 24-7-11.
//

#include "Unit.h"
#include "Tools/Setup.h"

namespace Riddle {
    void Unit::addImports(const std::vector<std::string> &libs) {
        for(const auto &i: libs) {
            imports.push_back(i);
        }
    }

    void Unit::addImports(const std::string &lib) {
        imports.push_back(lib);
    }

}// namespace Riddle