//
// Created by wangz on 24-7-10.
//

#ifndef RIDDLE_LANGUAGE_LLVMTOOLS_H
#define RIDDLE_LANGUAGE_LLVMTOOLS_H

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <map>

namespace Riddle{
    /// \brief 由于 LLVM 提供的 getGlobalContext 函数在 LLVM 9.0 版本被移除，所以使用自定义的 GlobalContext
    static llvm::LLVMContext GlobalContext;
    llvm::LLVMContext& getGlobalContext(){
        return GlobalContext;
    }
    /// \brief 简化指令生成的辅助对象
    static llvm::IRBuilder<> Builder(Riddle::getGlobalContext());
    /// \brief 保存了所有命名的全局变量
    static std::map<std::string, llvm::Value*>NamedValues;
}



#endif //RIDDLE_LANGUAGE_LLVMTOOLS_H
