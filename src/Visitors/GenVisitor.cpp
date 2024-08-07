#include "GenVisitor.h"
#include "Tools/GenTools.h"
#include "llvm/IR/PassManager.h"
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>
#include <system_error>

namespace Riddle{
    [[maybe_unused]]
    GenVisitor::GenVisitor(const std::string &moduleName): Builder(globalContext){
        module = new llvm::Module(moduleName, globalContext);
        // print 函数
        auto printType = llvm::FunctionType::get(
            Builder.getInt32Ty(),
            llvm::PointerType::get(Builder.getInt8Ty(), 0),
            true);
        llvm::FunctionCallee printfFunc = module->getOrInsertFunction("printf", printType);
        FuncCalls["printf"] = printfFunc;
        cast = castMapTemplate;
    }

    std::any GenVisitor::visitInteger(RiddleParser::IntegerContext *ctx){
        llvm::Value *p = Builder.getInt32(ctx->value);
        return p;
    }

    std::any GenVisitor::visitFloat(RiddleParser::FloatContext *ctx){
        llvm::Value *p = llvm::ConstantFP::get(globalContext, llvm::APFloat(ctx->value));
        return p;
    }

    std::any GenVisitor::visitString(RiddleParser::StringContext *ctx){
        auto str = ctx->STRING()->getText();
        //去掉前后的引号
        str = str.substr(1, str.size() - 2);
        llvm::Value *p = Builder.CreateGlobalString(str);
        return p;
    }

    std::any GenVisitor::visitObjectExpr(RiddleParser::ObjectExprContext *ctx){
        llvm::Value *value = varManager.getVar(ctx->id()->getText()).value;
        return value;
    }

    std::any GenVisitor::visitProgram(RiddleParser::ProgramContext *ctx){
        varManager.push();
        auto ret = RiddleParserBaseVisitor::visitProgram(ctx);
        varManager.pop();
        module->print(llvm::outs(), nullptr);
        return ret;
    }

    std::any GenVisitor::visitDefineArgs(RiddleParser::DefineArgsContext *ctx){
        std::vector<llvm::Type *> types;
        std::vector<std::string> names;
        std::string name;
        for (const auto i:ctx->children) {
            if (isIdentifier(i))
                name = i->getText();
            else if (dynamic_cast<RiddleParser::TypeNameContext *>(i) != nullptr) {
                auto type = any_cast<llvm::Type *>(visit(i));
                types.push_back(type);
                names.push_back(name);
                name = "";
            }
        }
        return DefineArgsType{types, names};
    }

    std::any GenVisitor::visitFuncDefine(RiddleParser::FuncDefineContext *ctx){
        auto args = any_cast<DefineArgsType>(visit(ctx->args));
        llvm::Type *resultType;
        if (ctx->returnType == nullptr) {
            resultType = Builder.getVoidTy();
        } else {
            const auto type = any_cast<llvm::Type *>(visit(ctx->returnType));
            resultType = type;
        }

        const std::string funcPkgName = packStack.top() + ctx->funcName->getText();

        llvm::FunctionType *funcType = llvm::FunctionType::get(resultType, args.types, false);
        llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, funcPkgName, *module);
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(globalContext, "entry", func);
        llvm::BasicBlock *oldBlock = Builder.GetInsertBlock();
        Builder.SetInsertPoint(entry);
        FuncCalls[ctx->funcName->getText()] = module->getOrInsertFunction(funcPkgName, funcType);

        ParentStack.push(func);
        varManager.push();

        //获取参数列表
        auto argIter = func->args().begin();
        for (int i = 0;i < args.names.size();i++, argIter++) {
            llvm::AllocaInst *Alloca = Builder.CreateAlloca(args.types[i], nullptr, args.names[i]);
            Builder.CreateStore(argIter, Alloca);
            varManager.defineVar(args.names[i], false, Alloca);
        }

        visit(ctx->funcBody());
        varManager.pop();
        ParentStack.pop();
        Builder.SetInsertPoint(oldBlock);
        return nullptr;
    }

    std::any GenVisitor::visitReturnStatement(RiddleParser::ReturnStatementContext *ctx){
        llvm::Value *p = any_cast<llvm::Value *>(visit(ctx->result));
        Builder.CreateRet(p);
        return nullptr;
    }

    std::any GenVisitor::visitStatement_ed(RiddleParser::Statement_edContext *ctx){
        return visit(ctx->children[0]);
    }

    std::any GenVisitor::visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx){
        const std::string name = packStack.top() + ctx->name->getText();
        llvm::Value *value = nullptr;
        llvm::Type *type = nullptr;

        if (ctx->type != nullptr) {
            type = any_cast<llvm::Type *>(visit(ctx->type));
        }
        if (ctx->value != nullptr) {
            value = any_cast<llvm::Value *>(visit(ctx->value));
            type = value->getType();
        }

        // 对于类中成员的定义
        if (std::holds_alternative<llvm::StructType *>(ParentStack.top())) {
            // todo 增加初始值设定
            const auto structTy = std::get<llvm::StructType *>(ParentStack.top());
            std::vector<llvm::Type *> newMember = structTy->elements();
            newMember.push_back(type);
            structTy->setBody(newMember);
            return nullptr;
        }

        llvm::Value *var;
        if (varManager.isGlobal()) {
            llvm::Constant *CV = nullptr;
            if (value != nullptr) {
                CV = llvm::dyn_cast<llvm::Constant>(value);
            }
            var = new llvm::GlobalVariable(*module, type, false,
                                           llvm::GlobalVariable::LinkageTypes::ExternalLinkage, CV, name);
        } else {
            llvm::Value *size = nullptr;
            var = Builder.CreateAlloca(type, size, name);
            if (ctx->value != nullptr)
                assignBinaryOp(var, value, "=");
        }
        varManager.defineVar(name, false, var);
        return nullptr;
    }

    std::any GenVisitor::visitObjValExpr(RiddleParser::ObjValExprContext *ctx){
        llvm::Value *var = varManager.getVar(ctx->id()->getText()).value;
        llvm::Value *LoadedValue = Builder.CreateLoad(var->getType(), var, "tempVar");
        return LoadedValue;
    }

    std::any GenVisitor::visitIfStatement(RiddleParser::IfStatementContext *ctx){
        auto cond = any_cast<llvm::Value *>(visit(ctx->cond));
        llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(globalContext, "if.then",
                                                               std::get<llvm::Function *>(ParentStack.top()));
        llvm::BasicBlock *elseBlock = llvm::BasicBlock::Create(globalContext, "if.else",
                                                               std::get<llvm::Function *>(ParentStack.top()));
        llvm::BasicBlock *oldBlock = Builder.GetInsertBlock();
        Builder.CreateCondBr(cond, thenBlock, elseBlock);

        Builder.SetInsertPoint(thenBlock);
        visit(ctx->body);
        Builder.CreateBr(oldBlock);

        Builder.SetInsertPoint(elseBlock);
        if (ctx->elseBody != nullptr) visit(ctx->elseBody);
        Builder.CreateBr(oldBlock);

        Builder.SetInsertPoint(oldBlock);
        return nullptr;
    }

    std::any GenVisitor::visitBoolean(RiddleParser::BooleanContext *ctx){
        llvm::Value *p = Builder.getInt1(ctx->value);
        return p;
    }

    std::any GenVisitor::visitWhileStatement(RiddleParser::WhileStatementContext *ctx){
        llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(globalContext, "while.cond",
                                                               std::get<llvm::Function *>(ParentStack.top()));
        llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(globalContext, "while.loop",
                                                               std::get<llvm::Function *>(ParentStack.top()));
        llvm::BasicBlock *oldBlock = Builder.GetInsertBlock();

        Builder.CreateBr(condBlock);
        Builder.SetInsertPoint(condBlock);
        auto Cond = any_cast<llvm::Value *>(visit(ctx->runCond));
        Builder.CreateCondBr(Cond, loopBlock, oldBlock);

        varManager.push();
        Builder.SetInsertPoint(loopBlock);
        visit(ctx->body);
        Builder.CreateBr(condBlock);
        varManager.pop();

        Builder.SetInsertPoint(oldBlock);
        return nullptr;
    }

    std::any GenVisitor::visitForStatement(RiddleParser::ForStatementContext *ctx){
        llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(globalContext, "for.cond",
                                                               std::get<llvm::Function *>(ParentStack.top()));
        llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(globalContext, "for.loop",
                                                               std::get<llvm::Function *>(ParentStack.top()));
        llvm::BasicBlock *oldBlock = Builder.GetInsertBlock();

        //这里我们认为这个变量的作用域在 for 里面，但是实际上是在 for 的外面，但是外面获取不到这个变量的信息
        varManager.push();
        if (ctx->init) {
            visit(ctx->init);
        }
        Builder.CreateBr(condBlock);
        Builder.SetInsertPoint(condBlock);
        auto Cond = any_cast<llvm::Value *>(visit(ctx->termCond));
        Builder.CreateCondBr(Cond, loopBlock, oldBlock);

        Builder.SetInsertPoint(loopBlock);
        visit(ctx->body);
        Builder.CreateBr(condBlock);

        Builder.SetInsertPoint(oldBlock);
        varManager.pop();
        return nullptr;
    }

    std::any GenVisitor::visitBracketExpr(RiddleParser::BracketExprContext *ctx){
        return visit(ctx->expr);
    }

    llvm::Value *GenVisitor::binaryOperator(llvm::Value *value1, llvm::Value *value2, const std::string &op){
        // todo 实现类的二元运算符
        if (value1->getType()->isStructTy()) {
            throw std::logic_error("还没实现");
        } else {
            //基本类型处理
            auto it = opMap.find(op);
            if (it != opMap.end()) {
                return it->second(Builder, value1, value2);
            }
        }
        return nullptr;
    }

    llvm::Value *GenVisitor::assignBinaryOp(llvm::Value *var, llvm::Value *value, const std::string &op){
        llvm::Type *type = nullptr;
        if (auto gep = dyn_cast<llvm::GetElementPtrInst>(var)) {
            type = gep->getResultElementType();
        } else if (auto allocaTy = dyn_cast<llvm::AllocaInst>(var)) {
            type = allocaTy->getAllocatedType();
        }

        auto loadValue = Builder.CreateLoad(type, var);
        if (type != value->getType() && isSampleType(getTypeName(type))) {
            value = cast[getTypeName(type)][getTypeName(value->getType())](Builder, value);
        }
        auto result = binaryOperator(loadValue, value, op.substr(0, op.size() - 1));
        Builder.CreateStore(result, var);
        return result;
    }

    // region 非赋值的双目运算
    std::any GenVisitor::visitAddExpr(RiddleParser::AddExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "+");
    }

    std::any GenVisitor::visitSubExpr(RiddleParser::SubExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "-");
    }

    std::any GenVisitor::visitMulExpr(RiddleParser::MulExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "*");
    }

    std::any GenVisitor::visitDivExpr(RiddleParser::DivExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "/");
    }

    std::any GenVisitor::visitShlExpr(RiddleParser::ShlExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "<<");
    }

    std::any GenVisitor::visitAShrExpr(RiddleParser::AShrExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, ">>");
    }

    std::any GenVisitor::visitLShrExpr(RiddleParser::LShrExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, ">>>");
    }

    std::any GenVisitor::visitBitXorExpr(RiddleParser::BitXorExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "^");
    }

    std::any GenVisitor::visitBitAndExpr(RiddleParser::BitAndExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "&");
    }

    std::any GenVisitor::visitBitOrExpr(RiddleParser::BitOrExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "|");
    }

    std::any GenVisitor::visitGreaterExpr(RiddleParser::GreaterExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, ">");
    }

    std::any GenVisitor::visitLessExpr(RiddleParser::LessExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "<");
    }

    std::any GenVisitor::visitModExpr(RiddleParser::ModExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "%");
    }

    std::any GenVisitor::visitLessEqualExpr(RiddleParser::LessEqualExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "<=");
    }

    std::any GenVisitor::visitGreaterEqualExpr(RiddleParser::GreaterEqualExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, ">=");
    }

    std::any GenVisitor::visitAndExpr(RiddleParser::AndExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "&&");
    }

    std::any GenVisitor::visitOrExpr(RiddleParser::OrExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "||");
    }

    std::any GenVisitor::visitNotEqualExpr(RiddleParser::NotEqualExprContext *ctx){
        auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "!=");
    }

    // endregion
    // region 赋值的双目运算
    std::any GenVisitor::visitAssignExpr(RiddleParser::AssignExprContext *ctx){
        auto var = any_cast<llvm::Value *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "=");
    }

    std::any GenVisitor::visitAddAssignExpr(RiddleParser::AddAssignExprContext *ctx){
        auto var = any_cast<llvm::Value *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "+=");
    }

    std::any GenVisitor::visitSubAssignExpr(RiddleParser::SubAssignExprContext *ctx){
        auto var = any_cast<llvm::Value *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "-=");
    }

    std::any GenVisitor::visitMulAssignExpr(RiddleParser::MulAssignExprContext *ctx){
        auto var = any_cast<llvm::Value *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "*=");
    }

    std::any GenVisitor::visitDivAssignExpr(RiddleParser::DivAssignExprContext *ctx){
        auto var = any_cast<llvm::Value *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "/=");
    }

    std::any GenVisitor::visitModAssignExpr(RiddleParser::ModAssignExprContext *ctx){
        auto var = any_cast<llvm::Value *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "%=");
    }

    std::any GenVisitor::visitShlAssignExpr(RiddleParser::ShlAssignExprContext *ctx){
        auto var = any_cast<llvm::Value *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "<<=");
    }

    std::any GenVisitor::visitAShrAssignExpr(RiddleParser::AShrAssignExprContext *ctx){
        auto var = any_cast<llvm::Value *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, ">>=");
    }

    std::any GenVisitor::visitLShrAssignExpr(RiddleParser::LShrAssignExprContext *ctx){
        auto var = any_cast<llvm::Value *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, ">>>=");
    }

    std::any GenVisitor::visitAndAssignExpr(RiddleParser::AndAssignExprContext *ctx){
        auto var = any_cast<llvm::Value *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "&=");
    }

    std::any GenVisitor::visitOrAssignExpr(RiddleParser::OrAssignExprContext *ctx){
        auto var = any_cast<llvm::Value *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "|=");
    }

    std::any GenVisitor::visitXorAssignExpr(RiddleParser::XorAssignExprContext *ctx){
        auto var = any_cast<llvm::Value *>(visit(ctx->left));
        auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "^=");
    }

    // endregion
    std::any GenVisitor::visitCastExpr(RiddleParser::CastExprContext *ctx){
        auto type = ctx->type->getText();
        auto var = any_cast<llvm::Value *>(visit(ctx->value));
        auto value = Builder.CreateLoad(var->getType(), var, "tempVar");
        auto func = cast[getTypeName(value->getType())][type];
        return func(Builder, value);
    }

    std::any GenVisitor::visitFuncExpr(RiddleParser::FuncExprContext *ctx){
        auto funcName = ctx->funcName->getText();
        if (!FuncCalls.contains(funcName)) {
            throw std::logic_error("This function \"" + std::string(funcName) + "\" is undefined");
        }
        auto args = any_cast<std::vector<llvm::Value *> >(visit(ctx->args));
        auto func = FuncCalls[funcName];
        llvm::Value *result = Builder.CreateCall(func, args);
        return result;
    }

    std::any GenVisitor::visitArgsExpr(RiddleParser::ArgsExprContext *ctx){
        std::vector<llvm::Value *> args;
        for (const auto &i:ctx->children) {
            if (!isTerminalNode(i)) {
                args.push_back(any_cast<llvm::Value *>(visit(i)));
            }
        }
        return args;
    }

    std::any GenVisitor::visitTypeName(RiddleParser::TypeNameContext *ctx){
        // 内置类型
        const auto name = ctx->name->getText();
        if (isSampleType(name)) {
            return getSampleType(name, Builder);
        }
        // 自定义类型
        auto type = classManager.getClass(name);
        return llvm::dyn_cast<llvm::Type>(type.types);
    }

    std::any GenVisitor::visitPtrExpr(RiddleParser::PtrExprContext *ctx){
        auto ptr = any_cast<llvm::Value *>(visit(ctx->children[0]));
        auto type = llvm::dyn_cast<llvm::PointerType>(ptr->getType());
        if (type == nullptr) return ptr;
        llvm::Value *value = Builder.CreateLoad(type, ptr);
        return value;
    }

    std::any GenVisitor::visitPackStatement(RiddleParser::PackStatementContext *ctx){
        auto packName = ctx->packName->getText();
        if (packName == "main")
            packStack.push("");
        else
            packStack.push(packName);

        return nullptr;
    }

    std::any GenVisitor::visitClassDefine(RiddleParser::ClassDefineContext *ctx){
        const std::string name = packStack.top() + ctx->className->getText();
        Class theClass;
        theClass.types = llvm::StructType::create(globalContext, name);
        packStack.push(packStack.top() + ctx->className->getText());
        varManager.push();
        ParentStack.push(theClass.types);
        visit(ctx->body);
        packStack.pop();
        varManager.pop();
        ParentStack.pop();
        classManager.createClass(theClass);
        return nullptr;
    }

    std::any GenVisitor::visitClassBody(RiddleParser::ClassBodyContext *ctx){
        return RiddleParserBaseVisitor::visitClassBody(ctx);
    }
} // namespace Riddle
