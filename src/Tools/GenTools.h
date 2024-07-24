#ifndef RIDDLE_LANGUAGE_GENTOOLS_H
#define RIDDLE_LANGUAGE_GENTOOLS_H
#include <antlr4-runtime.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Value.h>
#include <string>
namespace Riddle {
    llvm::Type *getSampleType(std::string type, llvm::IRBuilder<> &Builder);
    bool isSampleType(std::string type);
    std::vector<llvm::Type *> getTypes(std::vector<std::string> type, llvm::IRBuilder<> &Builder);

    /// @brief 获取类型名称 (可能的?)
    std::string getTypeName(llvm::Type *type);

    bool isTerminalNode(antlr4::tree::ParseTree *tree);
    bool isIdentifier(antlr4::tree::ParseTree *tree);
    struct DefineArgsType {
        std::vector<std::string> typeNames;
        std::vector<std::string> names;
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_GENTOOLS_H
