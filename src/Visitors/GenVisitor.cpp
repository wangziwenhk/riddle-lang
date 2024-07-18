//
// Created by wangz on 24-7-9.
//

#include "GenVisitor.h"
#include "llvm/IR/PassManager.h"
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Support/Error.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Bitcode/BitcodeWriterPass.h>
#include <system_error>

std::string getValueStr(llvm::Value* value){
    if (llvm::ConstantInt *CI = llvm::dyn_cast<llvm::ConstantInt>(value)) {
        llvm::APInt intValue = CI->getValue();
        int intVal = intValue.getSExtValue();
        return std::to_string(intVal);
    } else if (llvm::ConstantFP *CFP = llvm::dyn_cast<llvm::ConstantFP>(value)) {
        llvm::APFloat floatValue = CFP->getValueAPF();
        double floatVal = floatValue.convertToDouble();
        return std::to_string(floatVal);
    } else if (llvm::ConstantDataSequential *CDS = llvm::dyn_cast<llvm::ConstantDataSequential>(value)) {
        if (CDS->isString()) {
            std::string strValue = CDS->getAsCString().str();
            return strValue;
        }
        else return "???";
    }
    return "???";
}

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
        llvm::Value* p = Builder.getInt32(ctx->value);
        return p;
    }
    std::any GenVisitor::visitFloat(RiddleParser::FloatContext *ctx){
        llvm::Value* p = llvm::ConstantFP::get(globalContext, llvm::APFloat(ctx->value));
        return p;
    }
    std::any GenVisitor::visitObjectExpr(RiddleParser::ObjectExprContext *ctx) {
        llvm::Value* value = varManager.getVar(ctx->id()->getText()).value;
        return value;
    }
    std::any GenVisitor::visitPrint(RiddleParser::PrintContext *ctx) {
        auto value = any_cast<llvm::Value*>(visit(ctx->value));
        llvm::Value *formatStr = Builder.CreateGlobalStringPtr(getValueStr(value));
        Builder.CreateCall(FuncCalls["print"], {formatStr});
        return RiddleParserBaseVisitor::visitPrint(ctx);
    }
    std::any GenVisitor::visitProgram(RiddleParser::ProgramContext *ctx) {
        auto ret = RiddleParserBaseVisitor::visitProgram(ctx);
        module->print(llvm::outs(), nullptr);
        return ret;
    }
    std::any GenVisitor::visitFuncDefine(RiddleParser::FuncDefineContext *ctx) {
        // todo 实现自定义的返回值
        llvm::FunctionType *funcType = llvm::FunctionType::get(Builder.getInt32Ty(), false);
        llvm::Function *Func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, ctx->funcName->getText() , *module);
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(globalContext, "entry", Func);
        Builder.SetInsertPoint(entry);
        visit(ctx->funcBody());
        Builder.CreateRet(Builder.getInt32(0));
        return nullptr;
    }
}

