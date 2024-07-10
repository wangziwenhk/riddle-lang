//
// Created by wangz on 24-7-10.
//

#ifndef RIDDLE_LANGUAGE_TOOLS_H
#define RIDDLE_LANGUAGE_TOOLS_H

#include <llvm/IR/LLVMContext.h>
namespace Riddle{
    /// \brief 由于 LLVM 提供的 getGlobalContext 函数在 LLVM 9.0 版本被移除，所以使用自定义的 GlobalContext
    static llvm::LLVMContext GlobalContext;
    llvm::LLVMContext& getGlobalContext(){
        return GlobalContext;
    }
}



#endif //RIDDLE_LANGUAGE_TOOLS_H
