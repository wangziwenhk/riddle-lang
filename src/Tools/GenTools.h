#ifndef RIDDLE_LANGUAGE_GENTOOLS_H
#define RIDDLE_LANGUAGE_GENTOOLS_H
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Value.h>
#include <string>
namespace Riddle{
    std::string getValueStr(llvm::Value *value);
    llvm::AllocaInst *InitAlloca(std::string name, std::string type, llvm::IRBuilder<> &Builder, llvm::LLVMContext &Context);
}

#endif//RIDDLE_LANGUAGE_GENTOOLS_H
