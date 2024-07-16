#ifndef RIDDLE_LANGUAGE_GENVISITOR_H
#define RIDDLE_LANGUAGE_GENVISITOR_H

#include "RiddleParserBaseVisitor.h"
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
namespace Riddle{
    /// @brief 用于实现生成 IR 的类
    class GenVisitor : public RiddleParserBaseVisitor {
    private:
        llvm::Module *module;
        llvm::LLVMContext globalContext;
        llvm::IRBuilder<> Builder;
    public:
        GenVisitor(std::string moduleName);
        /// @brief 用于生成一个显式的 int 常量
        /// @param ctx IntegerContext
        /// @return llvm::Value*
        std::any visitInteger(RiddleParser::IntegerContext *ctx) override;
        /// @brief 用于生成一个显式的 float 常量
        /// @param ctx FloatContext
        /// @return llvm::Value*
        std::any visitFloat(RiddleParser::FloatContext *ctx) override;

    };
}



#endif//RIDDLE_LANGUAGE_GENVISITOR_H
