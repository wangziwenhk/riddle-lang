//
// Created by wangz on 24-7-9.
//

#include "GenVisitor.h"
#include <llvm/ADT/APInt.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/TargetSelect.h>

namespace Riddle{
    GenVisitor::GenVisitor(std::string moduleName):Builder(globalContext){
        module = new llvm::Module(moduleName, globalContext);
#ifdef TEST
        // print 函数
        auto printType = llvm::FunctionType::get(
                Builder.getInt32Ty(),
                llvm::PointerType::get(Builder.getInt8Ty(), 0),
                true
        );
        llvm::FunctionCallee printfFunc = module->getOrInsertFunction("printf", printType);
        FuncCalls["print"] = printfFunc;
#endif
    }
    std::any GenVisitor::visitInteger(RiddleParser::IntegerContext *ctx){
        return llvm::ConstantInt::get(globalContext, llvm::APInt(32,ctx->value));
    }
    std::any GenVisitor::visitFloat(RiddleParser::FloatContext *ctx){
        return llvm::ConstantFP::get(globalContext, llvm::APFloat(ctx->value));
    }
    std::any GenVisitor::visitObjectExpr(RiddleParser::ObjectExprContext *ctx) {
        llvm::Value* value = varManager.getVar(ctx->id()->getText()).value;
        return value;
    }
    std::any GenVisitor::visitPrint(RiddleParser::PrintContext *ctx) {
        //todo 等函数写好吧
        llvm::Value *formatStr = Builder.CreateGlobalStringPtr("OOOO");
        Builder.CreateCall(FuncCalls["print"], {formatStr});
        return RiddleParserBaseVisitor::visitPrint(ctx);
    }
    std::any GenVisitor::visitProgram(RiddleParser::ProgramContext *ctx) {
        auto ret = RiddleParserBaseVisitor::visitProgram(ctx);
        module->print(llvm::outs(), nullptr);
        return ret;
    }
    std::any GenVisitor::visitFuncDefine(RiddleParser::FuncDefineContext *ctx) {
        // todo 实现返回值
        llvm::FunctionType *funcType = llvm::FunctionType::get(Builder.getInt32Ty(), false);
        llvm::Function *Func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, ctx->funcName->getText() , *module);
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(globalContext, "entry", Func);
        Builder.SetInsertPoint(entry);
        return nullptr;
    }
}

