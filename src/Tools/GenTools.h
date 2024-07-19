#ifndef RIDDLE_LANGUAGE_GENTOOLS_H
#define RIDDLE_LANGUAGE_GENTOOLS_H
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Value.h>
#include <string>
namespace Riddle {
    llvm::AllocaInst *InitAlloca(std::string name, std::string type, llvm::IRBuilder<> &Builder);
    bool isBooleanTy(llvm::Value *value);
}// namespace Riddle

#endif//RIDDLE_LANGUAGE_GENTOOLS_H
