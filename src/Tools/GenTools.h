#ifndef RIDDLE_LANGUAGE_GENTOOLS_H
#define RIDDLE_LANGUAGE_GENTOOLS_H
#include <antlr4-runtime.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instructions.h>
#include <string>
#include <variant>
#include <Types/ClassNode.h>

namespace Riddle{
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

    struct DefineArgsType{
        std::vector<llvm::Type *> types;
        std::vector<std::string> names;
    };

    /// @brief 判断是否为简单类型
    /// @param type 类型名称
    bool isSampleType(const std::string &type);

    /// @brief 判断是否为数组(包括动态数组)
    /// @param var 变量
    bool isArray(llvm::Value *var);

    /// @brief 判断当前是否在类的定义中
    /// @param parent 父栈
    /// @return 是否在类的定义中
    inline bool isClassDefine(const std::variant<llvm::Function *, ClassNode> parent){
        return std::holds_alternative<ClassNode>(parent);
    }
} // namespace Riddle

#endif//RIDDLE_LANGUAGE_GENTOOLS_H
