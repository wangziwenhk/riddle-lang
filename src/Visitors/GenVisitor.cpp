#include "GenVisitor.h"
#include "Tools/GenTools.h"
#include "llvm/IR/PassManager.h"
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Support/Error.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/raw_ostream.h>
#include <system_error>

namespace Riddle {
    GenVisitor::GenVisitor(std::string moduleName): Builder(globalContext) {
        module = new llvm::Module(moduleName, globalContext);
        // print 函数
        auto printType = llvm::FunctionType::get(
                Builder.getInt32Ty(),
                llvm::PointerType::get(Builder.getInt8Ty(), 0),
                true);
        llvm::FunctionCallee printfFunc = module->getOrInsertFunction("printf", printType);
        FuncCalls["print"] = printfFunc;
    }
    std::any GenVisitor::visitInteger(RiddleParser::IntegerContext *ctx) {
        llvm::Value *p = Builder.getInt32(ctx->value);
        return p;
    }
    std::any GenVisitor::visitFloat(RiddleParser::FloatContext *ctx) {
        llvm::Value *p = llvm::ConstantFP::get(globalContext, llvm::APFloat(ctx->value));
        return p;
    }
    std::any GenVisitor::visitString(RiddleParser::StringContext *ctx) {
        auto str = ctx->STRING()->getText();
        //去掉前后的引号
        str = str.substr(1, str.size() - 2);
        llvm::Value *p = Builder.CreateGlobalString(str);
        return p;
    }
    std::any GenVisitor::visitObjectExpr(RiddleParser::ObjectExprContext *ctx) {
        llvm::AllocaInst *value = varManager.getVar(ctx->id()->getText()).value;
        return value;
    }
    std::any GenVisitor::visitPrintf(RiddleParser::PrintfContext *ctx) {
        auto value = any_cast<llvm::Value *>(visit(ctx->value));
        auto format = any_cast<llvm::Value *>(visit(ctx->format));
        Builder.CreateCall(FuncCalls["print"], {format, value});
        return nullptr;
    }
    std::any GenVisitor::visitProgram(RiddleParser::ProgramContext *ctx) {
        varManager.push();
        auto ret = RiddleParserBaseVisitor::visitProgram(ctx);
        varManager.pop();
        module->print(llvm::outs(), nullptr);
        return ret;
    }
    std::any GenVisitor::visitFuncDefine(RiddleParser::FuncDefineContext *ctx) {
        // todo 实现自定义的返回值
        llvm::FunctionType *funcType = llvm::FunctionType::get(Builder.getInt32Ty(), false);
        llvm::Function *Func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, ctx->funcName->getText(), *module);
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(globalContext, "entry", Func);
        Builder.SetInsertPoint(entry);
        FuncCalls[ctx->funcName->getText()] = module->getOrInsertFunction(ctx->funcName->getText(), funcType);
        FuncStack.push(Func);
        visit(ctx->funcBody());
        FuncStack.pop();
        return nullptr;
    }
    std::any GenVisitor::visitReturnStatement(RiddleParser::ReturnStatementContext *ctx) {
        llvm::Value *p = any_cast<llvm::Value *>(visit(ctx->result));
        Builder.CreateRet(p);
        return nullptr;
    }
    std::any GenVisitor::visitStatement_ed(RiddleParser::Statement_edContext *ctx) {
        return visit(ctx->children[0]);
    }
    std::any GenVisitor::visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) {
        std::string name = ctx->name->getText();
        if(ctx->type == nullptr) {//需要类型推断
            auto value = any_cast<llvm::Value *>(visit(ctx->value));
            throw std::logic_error("没实现");
        } else if(ctx->value == nullptr) {//声明
            std::string type = ctx->type->getText();
            llvm::AllocaInst *Alloca = InitAlloca(name, type, Builder);
            varManager.DefineVar(name, false, Alloca, type);
        } else {//完整的定义
            std::string type = ctx->type->getText();
            auto value = any_cast<llvm::Value *>(visit(ctx->value));
            llvm::AllocaInst *Alloca = InitAlloca(name, type, Builder);
            Builder.CreateStore(value, Alloca);
            varManager.DefineVar(name, false, Alloca, type);
        }
        return nullptr;
    }
    std::any GenVisitor::visitObjValExpr(RiddleParser::ObjValExprContext *ctx) {
        llvm::AllocaInst *var = varManager.getVar(ctx->id()->getText()).value;
        llvm::Value *LoadedValue = Builder.CreateLoad(var->getAllocatedType(), var, "tempVar");
        return LoadedValue;
    }
    std::any GenVisitor::visitIfStatement(RiddleParser::IfStatementContext *ctx) {
        auto cond = any_cast<llvm::Value *>(visit(ctx->cond));
        //        if(!isBooleanTy(cond)) {
        //            llvm::Value *Zero = llvm::ConstantInt::get(cond->getType(), 1);
        //            cond = Builder.CreateICmpEQ(Zero, cond, "isEqual");
        //        }
        llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(globalContext, "if.then", FuncStack.top());
        llvm::BasicBlock *elseBlock = llvm::BasicBlock::Create(globalContext, "if.else", FuncStack.top());
        llvm::BasicBlock *endBlock = llvm::BasicBlock::Create(globalContext, "if.end", FuncStack.top());
        Builder.CreateCondBr(cond, thenBlock, elseBlock);

        Builder.SetInsertPoint(thenBlock);
        visit(ctx->body);
        Builder.CreateBr(endBlock);

        Builder.SetInsertPoint(elseBlock);
        if(ctx->elseBody != nullptr) visit(ctx->elseBody);
        Builder.CreateBr(endBlock);

        Builder.SetInsertPoint(endBlock);
        return nullptr;
    }
    std::any GenVisitor::visitBoolean(RiddleParser::BooleanContext *ctx) {
        llvm::Value *p;
        p = Builder.getInt1(ctx->value);
        return p;
    }

}// namespace Riddle
