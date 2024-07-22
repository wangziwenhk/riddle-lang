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
    [[maybe_unused]]
    GenVisitor::GenVisitor(std::string moduleName): Builder(globalContext) {
        module = new llvm::Module(moduleName, globalContext);
        // print 函数
        auto printType = llvm::FunctionType::get(
                Builder.getInt32Ty(),
                llvm::PointerType::get(Builder.getInt8Ty(), 0),
                true);
        llvm::FunctionCallee printfFunc = module->getOrInsertFunction("printf", printType);
        FuncCalls["print"] = printfFunc;

        cast = implicitTemplate;
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
    std::any GenVisitor::visitDefineArgs(RiddleParser::DefineArgsContext *ctx) {
        std::vector<std::string> types;
        std::vector<std::string> names;
        std::string type, name;
        for(auto i: ctx->children) {
            if(!isIdentifier(i)) continue;

            if(name.empty())
                name = i->getText();
            else if(type.empty())
                type = i->getText();
            else {
                types.push_back(type);
                names.push_back(name);
            }
        }
        if(!type.empty()) {
            types.push_back(type);
            names.push_back(name);
        }
        return DefineArgsType{types, names};
    }
    std::any GenVisitor::visitFuncDefine(RiddleParser::FuncDefineContext *ctx) {
        // todo 实现自定义的返回值
        auto args = any_cast<DefineArgsType>(visit(ctx->args));
        auto argsTypes = getTypes(args.typeNames, Builder);

        llvm::FunctionType *funcType = llvm::FunctionType::get(Builder.getInt32Ty(), argsTypes, false);
        llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, ctx->funcName->getText(), *module);
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(globalContext, "entry", func);
        Builder.SetInsertPoint(entry);
        FuncCalls[ctx->funcName->getText()] = module->getOrInsertFunction(ctx->funcName->getText(), funcType);
        FuncStack.push(func);
        varManager.push();

        for(int i = 0; i < args.names.size(); i++) {
            llvm::AllocaInst *Alloca = initAlloca(args.names[i], args.typeNames[i], Builder);
            varManager.defineVar(args.names[i], false, Alloca, args.typeNames[i]);
        }

        visit(ctx->funcBody());
        varManager.pop();
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
        if(ctx->type == nullptr) {
            auto value = any_cast<llvm::Value *>(visit(ctx->value));
            throw std::logic_error("没实现");
        } else if(ctx->value == nullptr) {
            std::string type = ctx->type->getText();
            llvm::AllocaInst *Alloca = initAlloca(name, type, Builder);
            varManager.defineVar(name, false, Alloca, type);
        } else {
            std::string type = ctx->type->getText();
            auto value = any_cast<llvm::Value *>(visit(ctx->value));
            llvm::AllocaInst *Alloca = initAlloca(name, type, Builder);
            Builder.CreateStore(value, Alloca);
            varManager.defineVar(name, false, Alloca, type);
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

    std::any GenVisitor::visitWhileStatement(RiddleParser::WhileStatementContext *ctx) {
        llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(globalContext, "while.cond", FuncStack.top());
        llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(globalContext, "while.loop", FuncStack.top());
        llvm::BasicBlock *afterBlock = llvm::BasicBlock::Create(globalContext, "while.end", FuncStack.top());

        Builder.CreateBr(condBlock);
        Builder.SetInsertPoint(condBlock);
        auto Cond = any_cast<llvm::Value *>(visit(ctx->runCond));
        Builder.CreateCondBr(Cond, loopBlock, afterBlock);

        varManager.push();
        Builder.SetInsertPoint(loopBlock);
        visit(ctx->body);
        Builder.CreateBr(condBlock);
        varManager.pop();

        Builder.SetInsertPoint(afterBlock);
        return nullptr;
    }
    std::any GenVisitor::visitForStatement(RiddleParser::ForStatementContext *ctx) {
        llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(globalContext, "for.cond", FuncStack.top());
        llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(globalContext, "for.loop", FuncStack.top());
        llvm::BasicBlock *afterBlock = llvm::BasicBlock::Create(globalContext, "for.end", FuncStack.top());

        //这里我们认为这个变量的作用域在 for 里面，但是实际上是在 for 的外面，但是外面获取不到这个变量的信息
        varManager.push();
        if(ctx->init) {
            visit(ctx->init);
        }
        Builder.CreateBr(condBlock);
        Builder.SetInsertPoint(condBlock);
        auto Cond = any_cast<llvm::Value *>(visit(ctx->termCond));
        Builder.CreateCondBr(Cond, loopBlock, afterBlock);

        Builder.SetInsertPoint(loopBlock);
        visit(ctx->body);
        Builder.CreateBr(condBlock);

        Builder.SetInsertPoint(afterBlock);
        varManager.pop();
        return nullptr;
    }
    std::any GenVisitor::visitBracketExpr(RiddleParser::BracketExprContext *ctx) {
        return visit(ctx->expr);
    }
    llvm::Value *GenVisitor::binaryOperator(llvm::Value *value1, llvm::Value *value2, std::string op) {
        // todo 实现类的二元运算符
        if(value1->getType()->isStructTy()) {
            throw std::logic_error("还没实现");
        } else {//基本类型处理
            auto it = opMap.find(op);
            if(it != opMap.end()) {
                return it->second(Builder, value1, value2);
            }
        }
        return nullptr;
    }
    llvm::Value *GenVisitor::assignBinaryOp(llvm::AllocaInst *var, llvm::Value *value, std::string op) {
        auto loadValue = Builder.CreateLoad(var->getAllocatedType(), var);
        // 删除后面的等于号
        auto opt = op;
        opt.pop_back();
        auto result = binaryOperator(loadValue, value, opt);
        Builder.CreateStore(result, var);
        return result;
    }
    // region 非赋值的双目运算
    std::any GenVisitor::visitAddExpr(RiddleParser::AddExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "+");
    }
    std::any GenVisitor::visitSubExpr(RiddleParser::SubExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "-");
    }
    std::any GenVisitor::visitMulExpr(RiddleParser::MulExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "*");
    }
    std::any GenVisitor::visitDivExpr(RiddleParser::DivExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "/");
    }
    std::any GenVisitor::visitShlExpr(RiddleParser::ShlExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "<<");
    }
    std::any GenVisitor::visitAShrExpr(RiddleParser::AShrExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, ">>");
    }
    std::any GenVisitor::visitLShrExpr(RiddleParser::LShrExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, ">>>");
    }
    std::any GenVisitor::visitBitXorExpr(RiddleParser::BitXorExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "^");
    }
    std::any GenVisitor::visitBitAndExpr(RiddleParser::BitAndExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "&");
    }
    std::any GenVisitor::visitBitOrExpr(RiddleParser::BitOrExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "|");
    }
    std::any GenVisitor::visitGreaterExpr(RiddleParser::GreaterExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, ">");
    }
    std::any GenVisitor::visitLessExpr(RiddleParser::LessExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "<");
    }
    std::any GenVisitor::visitModExpr(RiddleParser::ModExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "%");
    }
    std::any GenVisitor::visitLessEqualExpr(RiddleParser::LessEqualExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "<=");
    }
    std::any GenVisitor::visitGreaterEqualExpr(RiddleParser::GreaterEqualExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, ">=");
    }
    std::any GenVisitor::visitAndExpr(RiddleParser::AndExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "&&");
    }
    std::any GenVisitor::visitOrExpr(RiddleParser::OrExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "||");
    }
    std::any GenVisitor::visitNotEqualExpr(RiddleParser::NotEqualExprContext *ctx) {
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "!=");
    }
    // endregion
    // region 赋值的双目运算
    std::any GenVisitor::visitAssignExpr(RiddleParser::AssignExprContext *ctx) {
        auto var = any_cast<llvm::AllocaInst *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        Builder.CreateStore(value, var);
        return value;
    }
    std::any GenVisitor::visitAddAssignExpr(RiddleParser::AddAssignExprContext *ctx) {
        auto var = any_cast<llvm::AllocaInst *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "+=");
    }
    std::any GenVisitor::visitSubAssignExpr(RiddleParser::SubAssignExprContext *ctx) {
        auto var = any_cast<llvm::AllocaInst *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "-=");
    }
    std::any GenVisitor::visitMulAssignExpr(RiddleParser::MulAssignExprContext *ctx) {
        auto var = any_cast<llvm::AllocaInst *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "*=");
    }
    std::any GenVisitor::visitDivAssignExpr(RiddleParser::DivAssignExprContext *ctx) {
        auto var = any_cast<llvm::AllocaInst *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "/=");
    }
    std::any GenVisitor::visitModAssignExpr(RiddleParser::ModAssignExprContext *ctx) {
        auto var = any_cast<llvm::AllocaInst *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "%=");
    }
    std::any GenVisitor::visitShlAssignExpr(RiddleParser::ShlAssignExprContext *ctx) {
        auto var = any_cast<llvm::AllocaInst *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "<<=");
    }
    std::any GenVisitor::visitAShrAssignExpr(RiddleParser::AShrAssignExprContext *ctx) {
        auto var = any_cast<llvm::AllocaInst *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, ">>=");
    }
    std::any GenVisitor::visitLShrAssignExpr(RiddleParser::LShrAssignExprContext *ctx) {
        auto var = any_cast<llvm::AllocaInst *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, ">>>=");
    }
    std::any GenVisitor::visitAndAssignExpr(RiddleParser::AndAssignExprContext *ctx) {
        auto var = any_cast<llvm::AllocaInst *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "&=");
    }
    std::any GenVisitor::visitOrAssignExpr(RiddleParser::OrAssignExprContext *ctx) {
        auto var = any_cast<llvm::AllocaInst *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "|=");
    }
    std::any GenVisitor::visitXorAssignExpr(RiddleParser::XorAssignExprContext *ctx) {
        auto var = any_cast<llvm::AllocaInst *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "^=");
    }
    // endregion
}// namespace Riddle
