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
#include <system_error>

std::string getValueStr(llvm::Value *value) {
    if(auto *CI= llvm::dyn_cast<llvm::ConstantInt>(value)) {
        llvm::APInt intValue= CI->getValue();
        int intVal= intValue.getSExtValue();
        delete CI;
        return std::to_string(intVal);
    } else if(auto *CFP= llvm::dyn_cast<llvm::ConstantFP>(value)) {
        llvm::APFloat floatValue= CFP->getValueAPF();
        double floatVal= floatValue.convertToDouble();
        delete CFP;
        return std::to_string(floatVal);
    } else if(auto *CDS= llvm::dyn_cast<llvm::ConstantDataArray>(value)) {
        if(CDS->getElementType()->isIntegerTy(8)) {
            std::string strValue= CDS->getAsCString().str();
            delete CDS;
            return strValue;
        } else {
            delete CDS;
            throw std::logic_error("This thing cannot be implicitly converted to a string");
        }
    }
    throw std::logic_error("This thing cannot be implicitly converted to a string");
}

bool isStringConstant(llvm::Value *value) {
    if(auto globalVar= llvm::dyn_cast<llvm::GlobalVariable>(value)) {
        if(globalVar->isConstant()) {
            if(auto constArray= llvm::dyn_cast<llvm::ConstantDataArray>(globalVar->getInitializer())) {
                if(constArray->getElementType()->isIntegerTy(8)) {
                    return true;
                }
            } else if(auto constZero= llvm::dyn_cast<llvm::ConstantAggregateZero>(globalVar->getInitializer())) {
                if(constZero->getType()->getArrayElementType()->isIntegerTy(8)) {
                    return true;
                }
            }
        }
    }
    return false;
}

namespace Riddle {
    GenVisitor::GenVisitor(std::string moduleName): Builder(globalContext) {
        module= new llvm::Module(moduleName, globalContext);
        // print 函数
        auto printType= llvm::FunctionType::get(
                Builder.getInt32Ty(),
                llvm::PointerType::get(Builder.getInt8Ty(), 0),
                true);
        llvm::FunctionCallee printfFunc= module->getOrInsertFunction("printf", printType);
        FuncCalls["print"]= printfFunc;
    }
    std::any GenVisitor::visitInteger(RiddleParser::IntegerContext *ctx) {
        llvm::Value *p= Builder.getInt32(ctx->value);
        return p;
    }
    std::any GenVisitor::visitFloat(RiddleParser::FloatContext *ctx) {
        llvm::Value *p= llvm::ConstantFP::get(globalContext, llvm::APFloat(ctx->value));
        return p;
    }
    std::any GenVisitor::visitString(RiddleParser::StringContext *ctx) {
        auto str= ctx->STRING()->getText();
        //去掉前后的引号
        str= str.substr(1, str.size() - 2);
        llvm::Value *p= Builder.CreateGlobalString(str);
        return p;
    }
    std::any GenVisitor::visitObjectExpr(RiddleParser::ObjectExprContext *ctx) {
        llvm::Value *value= varManager.getVar(ctx->id()->getText()).value;
        return value;
    }
    std::any GenVisitor::visitPrint(RiddleParser::PrintContext *ctx) {
        auto value= any_cast<llvm::Value *>(visit(ctx->value));
        llvm::Value *formatStr= nullptr;
        //判断是不是字符串，如果不是的话就不用额外加了
        if(isStringConstant(value)) formatStr= value;
        else
            Builder.CreateGlobalString(getValueStr(value));
        Builder.CreateCall(FuncCalls["print"], {formatStr});
        return nullptr;
    }
    std::any GenVisitor::visitProgram(RiddleParser::ProgramContext *ctx) {
        auto ret= RiddleParserBaseVisitor::visitProgram(ctx);
        module->print(llvm::outs(), nullptr);
        return ret;
    }
    std::any GenVisitor::visitFuncDefine(RiddleParser::FuncDefineContext *ctx) {
        // todo 实现自定义的返回值
        llvm::FunctionType *funcType= llvm::FunctionType::get(Builder.getInt32Ty(), false);
        llvm::Function *Func= llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, ctx->funcName->getText(), *module);
        llvm::BasicBlock *entry= llvm::BasicBlock::Create(globalContext, "entry", Func);
        Builder.SetInsertPoint(entry);
        visit(ctx->funcBody());
        return nullptr;
    }
    std::any GenVisitor::visitReturnStatement(RiddleParser::ReturnStatementContext *ctx) {
        llvm::Value* p = any_cast<llvm::Value*>(visit(ctx->result));
        Builder.CreateRet(p);
        return nullptr;
    }
    std::any GenVisitor::visitStatement_ed(RiddleParser::Statement_edContext *ctx) {
        return visit(ctx->children[0]);
    }

}// namespace Riddle
