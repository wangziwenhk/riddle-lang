#ifndef RIDDLE_LANGUAGE_GENTOOLS_H
#define RIDDLE_LANGUAGE_GENTOOLS_H
#include <antlr4-runtime.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Value.h>
#include <string>
namespace Riddle {
    llvm::Type *GetType(std::string type, llvm::IRBuilder<> &Builder);
    std::vector<llvm::Type *> GetTypes(std::vector<std::string> type, llvm::IRBuilder<> &Builder);

    llvm::AllocaInst *InitAlloca(std::string name, std::string type, llvm::IRBuilder<> &Builder);
    bool isBooleanTy(llvm::Value *value);
    bool isTerminalNode(antlr4::tree::ParseTree *tree);
    bool isIdentifier(antlr4::tree::ParseTree *tree);
    struct DefineArgsType {
        std::vector<std::string> typeNames;
        std::vector<std::string> names;
    };
}// namespace Riddle

#endif//RIDDLE_LANGUAGE_GENTOOLS_H
