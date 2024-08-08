//
// Created by wangz on 24-8-7.
//

#ifndef CLASS_H
#define CLASS_H

#include <map>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>

namespace Riddle{

    class Class {
    public:
        llvm::StructType *types = nullptr;
        std::vector<std::string> names;
        std::map<std::string, llvm::FunctionCallee> funcs;
    };

} // Riddle

#endif //CLASS_H
