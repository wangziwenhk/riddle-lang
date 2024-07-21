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

    public:// 工具
        /// @brief 用于处理二元操作
        /// @param value1 需要进行二元操作的变量
        /// @param value2 值
        /// @param op 二元操作符
        /// @returns llvm::Value*
        llvm::Value* binaryOperator(llvm::Value *value1, llvm::Value *value2, std::string op);
    public:
        GenVisitor(std::string moduleName);
        /// @brief 程序的根节点
        /// @returns null
        std::any visitProgram(RiddleParser::ProgramContext *ctx) override;
        /// @brief 加了换行符和分号的语句
        /// @returns std::any
        std::any visitStatement_ed(RiddleParser::Statement_edContext *ctx) override;
        /// @brief 加括号的表达式，用于改变表达式优先级
        /// @returns std::any
        std::any visitBracketExpr(RiddleParser::BracketExprContext *ctx) override;
        /// @brief 定义一个函数
        /// @warning 目前只能定义 i32 的返回值
        /// @returns null
        std::any visitFuncDefine(RiddleParser::FuncDefineContext *ctx) override;
        /// @brief 结束一个函数
        /// @returns nullptr
        std::any visitReturnStatement(RiddleParser::ReturnStatementContext *ctx) override;
        /// @brief 用于生成一个显式的 int 常量
        /// @return llvm::Value*
        std::any visitInteger(RiddleParser::IntegerContext *ctx) override;
        /// @brief 用于生成一个显式的 float 常量
        /// @return llvm::Value*
        std::any visitFloat(RiddleParser::FloatContext *ctx) override;
        /// @brief 用于生成一个显式的 string 常量
        /// @returns llvm::Value*
        std::any visitString(RiddleParser::StringContext *ctx) override;
        /// @brief 用于获取当前作用域下的某个对象或变量
        /// @warning 这里只有该源文件的当前作用域的变量可能被调用，且需要使用全限定名
        /// @returns llvm::AllocaInst*
        std::any visitObjectExpr(RiddleParser::ObjectExprContext *ctx) override;
        /// @brief 用于获取当前作用域下的某个对象或变量的值
        /// @warning 这里只有该源文件的当前作用域的变量可能被调用，且需要使用全限定名
        /// @returns llvm::Value*
        std::any visitObjValExpr(RiddleParser::ObjValExprContext *ctx) override;
        /// @brief 输出数值的函数
        /// @returns nullptr
        std::any visitPrintf(RiddleParser::PrintfContext *ctx) override;
        /// @brief 获取参数列表
        /// @returns std::vector\<llvm::Type*\>
        std::any visitDefineArgs(RiddleParser::DefineArgsContext *ctx) override;
        /// @brief 定义/声明一个变量
        /// @returns nullptr
        std::any visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) override;
        /// @brief 判断语句 ( 控制流 )
        /// @returns nullptr
        /// @todo 预计改为有表达式的类型
        std::any visitIfStatement(RiddleParser::IfStatementContext *ctx) override;
        /// @brief 布尔类型的常量
        /// @returns llvm::Value*
        std::any visitBoolean(RiddleParser::BooleanContext *ctx) override;
        /// @brief 赋值语句
        /// @returns llvm::Value,返回的是变量当前的值
        std::any visitAssignExpr(RiddleParser::AssignExprContext *ctx) override;
        /// @brief while 语句 ( 控制流 )
        /// @returns nullptr
        std::any visitWhileStatement(RiddleParser::WhileStatementContext *ctx) override;
        /// @brief for 语句 ( 控制流 )
        /// @returns nullptr
        std::any visitForStatement(RiddleParser::ForStatementContext *ctx) override;
        /// @brief 相加操作
        /// @returns llvm::Value*
        std::any visitAddExpr(RiddleParser::AddExprContext *ctx) override;
        /// @brief 相减操作
        /// @returns llvm::Value*
        std::any visitSubExpr(RiddleParser::SubExprContext *ctx) override;
        /// @brief 相乘操作
        /// @returns llvm::Value*
        std::any visitMulExpr(RiddleParser::MulExprContext *ctx) override;
        /// @brief 相除操作
        /// @returns llvm::Value*
        std::any visitDivExpr(RiddleParser::DivExprContext *ctx) override;
        /// @brief 左移操作
        /// @returns llvm::Value*
        std::any visitShlExpr(RiddleParser::ShlExprContext *ctx) override;
        /// @brief 有符号右移操作
        /// @returns llvm::Value*
        std::any visitAshrExpr(RiddleParser::AshrExprContext *ctx) override;
        /// @brief 无符号右移操作
        /// @returns llvm::Value*
        std::any visitLshrExpr(RiddleParser::LshrExprContext *ctx) override;
        /// @brief 异或操作
        /// @returns llvm::Value*
        std::any visitBitXorExpr(RiddleParser::BitXorExprContext *ctx) override;
        /// @brief 按位与操作
        /// @returns llvm::Value*
        std::any visitBitAndExpr(RiddleParser::BitAndExprContext *ctx) override;
        /// @brief 按位或操作
        /// @returns llvm::Value*
        std::any visitBitOrExpr(RiddleParser::BitOrExprContext *ctx) override;
    };
}// namespace Riddle


#endif//RIDDLE_LANGUAGE_GENVISITOR_H
