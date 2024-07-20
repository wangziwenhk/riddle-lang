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
        std::unordered_map<std::string, llvm::FunctionCallee> FuncCalls;
        std::stack<llvm::Function *> FuncStack;
        VarManager varManager;
        llvm::IRBuilder<> Builder;
        llvm::LLVMContext globalContext;
        llvm::Module *module;

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
        /// @brief 用于获取当前作用域下的某个对象或变量
        /// @warning 这里只有该源文件的当前作用域的变量可能被调用，且需要使用全限定名
        /// @param ctx ObjectExprContext*
        /// @returns llvm::AllocaInst*
        std::any visitObjectExpr(RiddleParser::ObjectExprContext *ctx) override;
        /// @brief 用于获取当前作用域下的某个对象或变量的值
        /// @warning 这里只有该源文件的当前作用域的变量可能被调用，且需要使用全限定名
        /// @param ctx ObjValExprContext*
        /// @returns llvm::Value*
        std::any visitObjValExpr(RiddleParser::ObjValExprContext *ctx) override;
        /// @brief 输出数值的函数
        /// @param ctx PrintContext*
        /// @returns nullptr
        std::any visitPrintf(RiddleParser::PrintfContext *ctx) override;
        /// @brief 获取参数列表
        /// @param ctx ArgsExprContext*
        /// @returns std::vector\<llvm::Type*\>
        std::any visitDefineArgs(RiddleParser::DefineArgsContext *ctx) override;
        /// @brief 定义/声明一个变量
        /// @param ctx VarDefineStatementContext*
        /// @returns nullptr
        std::any visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) override;
        /// @brief 判断语句 ( 控制流 )
        /// @param ctx IfStatementContext*
        /// @returns nullptr
        /// @todo 预计改为有表达式的类型
        std::any visitIfStatement(RiddleParser::IfStatementContext *ctx) override;
        /// @brief 布尔类型的常量
        /// @param ctx BooleanContext
        /// @returns llvm::Value*
        std::any visitBoolean(RiddleParser::BooleanContext *ctx) override;
        /// @brief 赋值语句
        /// @param ctx AssignExprContext*
        /// @returns llvm::Value,返回的是变量当前的值
        std::any visitAssignExpr(RiddleParser::AssignExprContext *ctx) override;
        /// @brief while 语句 ( 控制流 )
        /// @param ctx WhileStatementContext*
        /// @returns nullptr
        std::any visitWhileStatement(RiddleParser::WhileStatementContext *ctx) override;
        /// @brief for 语句 ( 控制流 )
        /// @param ctx ForStatementContext*
        /// @returns nullptr
        std::any visitForStatement(RiddleParser::ForStatementContext *ctx) override;
    };
}// namespace Riddle


#endif//RIDDLE_LANGUAGE_GENVISITOR_H
