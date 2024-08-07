//
// Created by wangz on 24-8-7.
//

#ifndef CLASS_H
#define CLASS_H

#include <llvm/IR/DerivedTypes.h>

namespace Riddle{

    class Class {
    public:
        llvm::StructType *types = nullptr;
    };

} // Riddle

#endif //CLASS_H
