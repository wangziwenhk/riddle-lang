#ifndef RIDDLE_LANGUAGE_GENVISITOR_H
#define RIDDLE_LANGUAGE_GENVISITOR_H

#include "Tools/VarManager.h"
#include <RiddleParserBaseVisitor.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
namespace Riddle {
    /// @brief 用于实现生成 IR 的类
    class GenVisitor : public RiddleParserBaseVisitor {
    private:
        llvm::Module *module;
        llvm::LLVMContext globalContext;
        llvm::IRBuilder<> Builder;
        VarManager varManager;
        std::unordered_map<std::string, llvm::FunctionCallee> FuncCalls;

    public:
        GenVisitor(std::string moduleName);
        /// @brief 程序的根节点
        /// @param ctx ProgramContext*
        /// @returns null
        std::any visitProgram(RiddleParser::ProgramContext *ctx) override;
        /// @brief 加了换行符和分号的语句
        /// @param ctx Statement_edContext*
        /// @returns std::any
        std::any visitStatement_ed(RiddleParser::Statement_edContext *ctx) override;
        /// @brief 定义一个函数
        /// @warning 目前只能定义 i32 的返回值
        /// @param ctx FuncDefineContext*
        /// @returns null
        std::any visitFuncDefine(RiddleParser::FuncDefineContext *ctx) override;
        /// @brief 结束一个函数
        /// @param ctx ReturnStatementContext
        /// @returns nullptr
        std::any visitReturnStatement(RiddleParser::ReturnStatementContext *ctx) override;
        /// @brief 用于生成一个显式的 int 常量
        /// @param ctx IntegerContext
        /// @return llvm::Value*
        std::any visitInteger(RiddleParser::IntegerContext *ctx) override;
        /// @brief 用于生成一个显式的 float 常量
        /// @param ctx FloatContext*
        /// @return llvm::Value*
        std::any visitFloat(RiddleParser::FloatContext *ctx) override;
        /// @brief 用于生成一个显式的 string 常量
        /// @param ctx StringContext
        /// @returns llvm::Value*
        std::any visitString(RiddleParser::StringContext *ctx) override;
        /// @brief 用于获取当前作用域下的某个对象或变量的值
        /// @warning 这里只有该源文件的当前作用域的变量可能被调用，且需要使用全限定名
        /// @param ctx ObjectExprContext*
        /// @returns llvm::Value*
        std::any visitObjectExpr(RiddleParser::ObjectExprContext *ctx) override;
        /// @brief 输出数值的函数
        /// @param ctx PrintContext*
        /// @returns nullptr
        std::any visitPrint(RiddleParser::PrintContext *ctx) override;
    };
}// namespace Riddle


#endif//RIDDLE_LANGUAGE_GENVISITOR_H
