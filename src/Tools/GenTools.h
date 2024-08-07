#ifndef RIDDLE_LANGUAGE_GENTOOLS_H
#define RIDDLE_LANGUAGE_GENTOOLS_H
#include <antlr4-runtime.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Value.h>
#include <string>
namespace Riddle {
    /// @brief 获取简单类型
    /// @param type 简单类型的名称
    /// @param Builder 生成器
    llvm::Type *getSampleType(const std::string &type, llvm::IRBuilder<> &Builder);


    /// @brief 获取类型名称 (可能的?)
    std::string getTypeName(llvm::Type *type);

    /// @brief 判断是否为终止节点
    /// @param tree 节点
    bool isTerminalNode(antlr4::tree::ParseTree *tree);

    /// @brief 判断是否为标识符节点
    /// @param tree 节点
    bool isIdentifier(antlr4::tree::ParseTree *tree);

    struct DefineArgsType {
        std::vector<llvm::Type *> types;
        std::vector<std::string> names;
    };
    /// @brief 判断是否为简单类型
    /// @param type 类型名称
    bool isSampleType(const std::string &type);

    /// @brief 判断是否为数组(包括动态数组)
    /// @param var 变量
    bool isArray(llvm::Value *var);

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_GENTOOLS_H
