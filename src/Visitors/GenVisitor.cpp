//
// Created by wangz on 24-7-9.
//

#include "GenVisitor.h"
#include "Tools/llvmTools.h"
#include <llvm/ADT/APInt.h>
#include <llvm/IR/IRBuilder.h>
using namespace Riddle;

/// \brief 用于生成一个显式的 int 常量
/// \return llvm::Value*
std::any GenVisitor::visitInteger(RiddleParser::IntegerContext *ctx){
    return llvm::ConstantInt::get(getGlobalContext(), llvm::APInt(32,ctx->value));
}
/// \brief 用于生成一个显式的 float 常量
/// \return llvm::Value*
std::any GenVisitor::visitFloat(RiddleParser::FloatContext *ctx){
    return llvm::ConstantFP::get(getGlobalContext(), llvm::APFloat(ctx->value));
}
