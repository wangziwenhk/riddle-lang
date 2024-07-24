//
// Created by wangz on 24-7-17.
//

#ifndef RIDDLE_LANGUAGE_VARIABLE_H
#define RIDDLE_LANGUAGE_VARIABLE_H

#include <llvm/IR/Instructions.h>
#include <llvm/IR/Value.h>
#include <string>
namespace Riddle {
    const std::string Null = "null";
    class Variable {
    public:
        const std::string name;
        std::string type;
        llvm::Value *value;
        const bool isConst;
        Variable() = delete;
        Variable(const std::string &name,
                 llvm::Value *value,
                 const std::string &type = Null,
                 const bool isConst = false): name(name), value(value), type(type), isConst(isConst){};
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_VARIABLE_H
