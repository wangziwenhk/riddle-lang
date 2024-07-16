//
// Created by wangz on 24-7-9.
//

#include "GenVisitor.h"
#include <llvm/ADT/APInt.h>
#include <llvm/IR/IRBuilder.h>

namespace Riddle{
    std::any GenVisitor::visitInteger(RiddleParser::IntegerContext *ctx){
        return llvm::ConstantInt::get(globalContext, llvm::APInt(32,ctx->value));
    }
    std::any GenVisitor::visitFloat(RiddleParser::FloatContext *ctx){
        return llvm::ConstantFP::get(globalContext, llvm::APFloat(ctx->value));
    }
    GenVisitor::GenVisitor(std::string moduleName):Builder(globalContext){
        module = new llvm::Module(moduleName,globalContext);
    }
}

