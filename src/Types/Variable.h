//
// Created by wangz on 24-7-17.
//

#ifndef RIDDLE_LANGUAGE_VARIABLE_H
#define RIDDLE_LANGUAGE_VARIABLE_H

#include <string>
namespace Riddle {

    class Variable {
    public:
        const std::string name;
        std::string type;
        const bool isConst;
        Variable() = delete;
        Variable(const std::string& name,const std::string& type):name(name),type(type),isConst(false){};
        Variable(const std::string& name,const std::string& type,const bool& isConst):name(name),type(type),isConst(isConst){};
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_VARIABLE_H
