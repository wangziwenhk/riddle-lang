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

namespace Riddle {
    [[maybe_unused]] GenVisitor::GenVisitor(const std::string &moduleName): Builder(globalContext) {
        module = new llvm::Module(moduleName, globalContext);
        module->setSourceFileName(moduleName + ".red");
        opMap = getBinaryOpMap(Builder);
        // print 函数
        const auto printType = llvm::FunctionType::get(
                Builder.getInt32Ty(),
                llvm::PointerType::get(Builder.getInt8Ty(), 0),
                true);
        const auto printfFunc = module->getOrInsertFunction("printf", printType);
        FuncCalls["printf"] = printfFunc;
        cast = castMapTemplate;
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
        llvm::Value *value = varManager.getVar(ctx->Identifier()->getText()).value;
        return  std::tuple{value,value->getType()};
    }

    std::any GenVisitor::visitProgram(RiddleParser::ProgramContext *ctx) {
        varManager.push();
        auto ret = RiddleParserBaseVisitor::visitProgram(ctx);
        varManager.pop();
        module->print(llvm::outs(), nullptr);
        return ret;
    }

    std::any GenVisitor::visitDefineArgs(RiddleParser::DefineArgsContext *ctx) {
        std::vector<llvm::Type *> types;
        std::vector<std::string> names;
        std::string name;
        for(const auto i: ctx->children) {
            if(isIdentifier(i))
                name = i->getText();
            else if(dynamic_cast<RiddleParser::TypeNameContext *>(i) != nullptr) {
                auto type = any_cast<llvm::Type *>(visit(i));
                types.push_back(type);
                names.push_back(name);
                name = "";
            }
        }
        return DefineArgsType{types, names};
    }

    std::any GenVisitor::visitFuncDefine(RiddleParser::FuncDefineContext *ctx) {
        auto args = any_cast<DefineArgsType>(visit(ctx->args));
        llvm::Type *resultType;
        if(ctx->returnType == nullptr) {
            resultType = Builder.getVoidTy();
        } else {
            const auto type = any_cast<llvm::Type *>(visit(ctx->returnType));
            resultType = type;
        }
        if(ParentStack.size() && isClassDefine(ParentStack.top())) {
            args.names.insert(args.names.begin(), "this");
            args.types.insert(args.types.begin(), std::get<ClassNode>(ParentStack.top()).get().types);
        }

        const std::string funcPkgName = packStack.top() + ctx->funcName->getText();

        llvm::FunctionType *funcType = llvm::FunctionType::get(resultType, args.types, false);
        llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, funcPkgName, *module);
        llvm::BasicBlock *entry = llvm::BasicBlock::Create(globalContext, "entry", func);
        llvm::BasicBlock *oldBlock = Builder.GetInsertBlock();
        Builder.SetInsertPoint(entry);
        // 对于类中方法的定义
        if(ParentStack.size() && isClassDefine(ParentStack.top())) {
            const auto theClass = std::get<ClassNode>(ParentStack.top());
            theClass.get().funcs[ctx->funcName->getText()] = module->getOrInsertFunction(funcPkgName, funcType);
        } else {
            FuncCalls[ctx->funcName->getText()] = module->getOrInsertFunction(funcPkgName, funcType);
        }
        ParentStack.push(func);
        varManager.push();

        //获取参数列表
        auto argIter = func->args().begin();
        for(int i = 0; i < args.names.size(); i++, argIter++) {
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

    std::any GenVisitor::visitReturnStatement(RiddleParser::ReturnStatementContext *ctx) {
        const auto p = any_cast<llvm::Value *>(visit(ctx->result));
        Builder.CreateRet(p);
        return nullptr;
    }

    std::any GenVisitor::visitStatement_ed(RiddleParser::Statement_edContext *ctx) {
        return visit(ctx->children[0]);
    }

    std::any GenVisitor::visitVarDefineStatement(RiddleParser::VarDefineStatementContext *ctx) {
        const std::string name = packStack.top() + ctx->name->getText();
        llvm::Value *value = nullptr;
        llvm::Type *type = nullptr;

        if(ctx->type != nullptr) {
            type = any_cast<llvm::Type *>(visit(ctx->type));
        }
        if(ctx->value != nullptr) {
            value = any_cast<llvm::Value *>(visit(ctx->value));
            type = value->getType();
        }

        // 对于类中成员的定义
        if(isClassDefine(ParentStack.top())) {
            // todo 增加初始值设定
            const auto theClass = std::get<ClassNode>(ParentStack.top());
            std::vector<llvm::Type *> newMember = theClass.get().types->elements();
            newMember.push_back(type);
            theClass.get().types->setBody(newMember);
            theClass.get().names.insert({ctx->name->getText(), theClass.get().names.size()});
            return nullptr;
        }

        llvm::Value *var;
        if(varManager.isGlobal()) {
            llvm::Constant *CV = nullptr;
            if(value != nullptr) {
                CV = llvm::dyn_cast<llvm::Constant>(value);
            }
            var = new llvm::GlobalVariable(*module, type, false,
                                           llvm::GlobalVariable::LinkageTypes::ExternalLinkage, CV, name);
        } else {
            llvm::Value *size = nullptr;
            var = Builder.CreateAlloca(type, size, name);
            if(ctx->value != nullptr)
                assignBinaryOp(var, value, "=");
        }
        varManager.defineVar(name, false, var);
        return nullptr;
    }

    std::any GenVisitor::visitIfStatement(RiddleParser::IfStatementContext *ctx) {
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
        if(ctx->elseBody != nullptr) visit(ctx->elseBody);
        Builder.CreateBr(oldBlock);

        Builder.SetInsertPoint(oldBlock);
        return nullptr;
    }

    std::any GenVisitor::visitBoolean(RiddleParser::BooleanContext *ctx) {
        llvm::Value *p = Builder.getInt1(ctx->value);
        return p;
    }

    std::any GenVisitor::visitWhileStatement(RiddleParser::WhileStatementContext *ctx) {
        llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(globalContext, "while.cond",
                                                               std::get<llvm::Function *>(ParentStack.top()));
        llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(globalContext, "while.loop",
                                                               std::get<llvm::Function *>(ParentStack.top()));
        llvm::BasicBlock *oldBlock = Builder.GetInsertBlock();

        Builder.CreateBr(condBlock);
        Builder.SetInsertPoint(condBlock);
        const auto Cond = any_cast<llvm::Value *>(visit(ctx->runCond));
        Builder.CreateCondBr(Cond, loopBlock, oldBlock);

        varManager.push();
        Builder.SetInsertPoint(loopBlock);
        visit(ctx->body);
        Builder.CreateBr(condBlock);
        varManager.pop();

        Builder.SetInsertPoint(oldBlock);
        return nullptr;
    }

    std::any GenVisitor::visitForStatement(RiddleParser::ForStatementContext *ctx) {
        llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(globalContext, "for.cond",
                                                               std::get<llvm::Function *>(ParentStack.top()));
        llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(globalContext, "for.loop",
                                                               std::get<llvm::Function *>(ParentStack.top()));
        llvm::BasicBlock *oldBlock = Builder.GetInsertBlock();

        //这里我们认为这个变量的作用域在 for 里面，但是实际上是在 for 的外面，但是外面获取不到这个变量的信息
        varManager.push();
        if(ctx->init) {
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

    std::any GenVisitor::visitBracketExpr(RiddleParser::BracketExprContext *ctx) {
        return visit(ctx->expr);
    }

    llvm::Value *GenVisitor::binaryOperator(llvm::Value *value1, llvm::Value *value2, const std::string &op) {
        if(op == "") return value2;
        //基本类型处理
        const auto it = opMap.find(op);
        if(it == opMap.end()) throw std::logic_error("没实现");
        const auto it2 = it->second.find(value1->getType());
        if(it2 == it->second.end()) throw std::logic_error("没实现");
        const auto it3 = it2->second.find(value2->getType());
        if(it3 == it2->second.end()) throw std::logic_error("没实现");
        return it3->second(Builder, value1, value2);
    }

    llvm::Value *GenVisitor::assignBinaryOp(llvm::Value *var, llvm::Value *value, const std::string &op) {
        llvm::Type *type = nullptr;
        if(const auto gep = dyn_cast<llvm::GetElementPtrInst>(var)) {
            type = gep->getResultElementType();
        } else if(const auto allocaTy = dyn_cast<llvm::AllocaInst>(var)) {
            type = allocaTy->getAllocatedType();
        }

        const auto loadValue = Builder.CreateLoad(type, var);
        if(type != value->getType() && isSampleType(getTypeName(type))) {
            value = cast[getTypeName(type)][getTypeName(value->getType())](Builder, value);
        }
        const auto result = binaryOperator(loadValue, value, op.substr(0, op.size() - 1));
        Builder.CreateStore(result, var);
        return result;
    }

    // region 非赋值的双目运算
    std::any GenVisitor::visitAddExpr(RiddleParser::AddExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "+");
    }

    std::any GenVisitor::visitSubExpr(RiddleParser::SubExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "-");
    }

    std::any GenVisitor::visitMulExpr(RiddleParser::MulExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "*");
    }

    std::any GenVisitor::visitDivExpr(RiddleParser::DivExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "/");
    }

    std::any GenVisitor::visitShlExpr(RiddleParser::ShlExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "<<");
    }

    std::any GenVisitor::visitAShrExpr(RiddleParser::AShrExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, ">>");
    }

    std::any GenVisitor::visitLShrExpr(RiddleParser::LShrExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, ">>>");
    }

    std::any GenVisitor::visitBitXorExpr(RiddleParser::BitXorExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "^");
    }

    std::any GenVisitor::visitBitAndExpr(RiddleParser::BitAndExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "&");
    }

    std::any GenVisitor::visitBitOrExpr(RiddleParser::BitOrExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "|");
    }

    std::any GenVisitor::visitGreaterExpr(RiddleParser::GreaterExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, ">");
    }

    std::any GenVisitor::visitLessExpr(RiddleParser::LessExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "<");
    }

    std::any GenVisitor::visitModExpr(RiddleParser::ModExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "%");
    }

    std::any GenVisitor::visitLessEqualExpr(RiddleParser::LessEqualExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "<=");
    }

    std::any GenVisitor::visitGreaterEqualExpr(RiddleParser::GreaterEqualExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, ">=");
    }

    std::any GenVisitor::visitAndExpr(RiddleParser::AndExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "&&");
    }

    std::any GenVisitor::visitOrExpr(RiddleParser::OrExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "||");
    }

    std::any GenVisitor::visitNotEqualExpr(RiddleParser::NotEqualExprContext *ctx) {
        const auto value1 = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value2 = any_cast<llvm::Value *>(visit(ctx->right));
        return binaryOperator(value1, value2, "!=");
    }

    // endregion
    // region 赋值的双目运算
    std::any GenVisitor::visitAssignExpr(RiddleParser::AssignExprContext *ctx) {
        const auto var = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "=");
    }

    std::any GenVisitor::visitAddAssignExpr(RiddleParser::AddAssignExprContext *ctx) {
        const auto var = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "+=");
    }

    std::any GenVisitor::visitSubAssignExpr(RiddleParser::SubAssignExprContext *ctx) {
        const auto var = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "-=");
    }

    std::any GenVisitor::visitMulAssignExpr(RiddleParser::MulAssignExprContext *ctx) {
        const auto var = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "*=");
    }

    std::any GenVisitor::visitDivAssignExpr(RiddleParser::DivAssignExprContext *ctx) {
        const auto var = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "/=");
    }

    std::any GenVisitor::visitModAssignExpr(RiddleParser::ModAssignExprContext *ctx) {
        const auto var = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "%=");
    }

    std::any GenVisitor::visitShlAssignExpr(RiddleParser::ShlAssignExprContext *ctx) {
        const auto var = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "<<=");
    }

    std::any GenVisitor::visitAShrAssignExpr(RiddleParser::AShrAssignExprContext *ctx) {
        const auto var = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, ">>=");
    }

    std::any GenVisitor::visitLShrAssignExpr(RiddleParser::LShrAssignExprContext *ctx) {
        const auto var = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, ">>>=");
    }

    std::any GenVisitor::visitAndAssignExpr(RiddleParser::AndAssignExprContext *ctx) {
        const auto var = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "&=");
    }

    std::any GenVisitor::visitOrAssignExpr(RiddleParser::OrAssignExprContext *ctx) {
        const auto var = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "|=");
    }

    std::any GenVisitor::visitXorAssignExpr(RiddleParser::XorAssignExprContext *ctx) {
        const auto var = any_cast<llvm::Value *>(visit(ctx->left));
        const auto value = any_cast<llvm::Value *>(visit(ctx->right));
        return assignBinaryOp(var, value, "^=");
    }

    // endregion
    std::any GenVisitor::visitCastExpr(RiddleParser::CastExprContext *ctx) {
        const auto type = ctx->type->getText();
        const auto var = any_cast<llvm::Value *>(visit(ctx->value));
        const auto value = Builder.CreateLoad(var->getType(), var, "tempVar");
        const auto func = cast[getTypeName(value->getType())][type];
        return func(Builder, value);
    }

    std::any GenVisitor::visitFuncExpr(RiddleParser::FuncExprContext *ctx) {
        auto funcName = ctx->funcName->getText();
        if(!FuncCalls.contains(funcName)) {
            throw std::logic_error("This function \"" + std::string(funcName) + "\" is undefined");
        }
        const auto args = any_cast<std::vector<llvm::Value *>>(visit(ctx->args));
        const auto func = FuncCalls[funcName];
        llvm::Value *result = Builder.CreateCall(func, args);
        return std::tuple{result,result->getType()};
    }

    std::any GenVisitor::visitArgsExpr(RiddleParser::ArgsExprContext *ctx) {
        std::vector<llvm::Value *> args;
        for(const auto &i: ctx->children) {
            if(!isTerminalNode(i)) {
                args.push_back(any_cast<llvm::Value *>(visit(i)));
            }
        }
        return args;
    }

    std::any GenVisitor::visitTypeName(RiddleParser::TypeNameContext *ctx) {
        // 内置类型
        const auto name = ctx->name->getText();
        if(isSampleType(name)) {
            return getSampleType(name, Builder);
        }
        // 自定义类型
        const auto theClass = classManager.getClass(name);
        return llvm::dyn_cast<llvm::Type>(theClass.get().types);
    }

    std::any GenVisitor::visitPtrExpr(RiddleParser::PtrExprContext *ctx) {
        auto ptr = any_cast<llvm::Value *>(visit(ctx->children[0]));
        const auto type = llvm::dyn_cast<llvm::PointerType>(ptr->getType());
        if(type == nullptr) return ptr;
        llvm::Value *value = Builder.CreateLoad(type, ptr);
        return value;
    }

    // BUG 这里不考虑对函数返回的对象的引用
    std::any GenVisitor::visitBlendExpr(RiddleParser::BlendExprContext *ctx) {
        // todo 这里暂时没法使用对象的函数
        const auto [parent,type] = std::any_cast<std::tuple<llvm::Value*,llvm::Type*>>(visit(ctx->parent));

        const auto childName = ctx->child->getText();
        ClassNode theClass;

        if(const auto Alloca = llvm::dyn_cast<llvm::AllocaInst>(parent)) {
            theClass = classManager.getClass(Alloca->getAllocatedType()->getStructName().str());
        }else {
            theClass = classManager.getClass(type->getStructName().str());
        }

        if(const auto FuncExpr = dynamic_cast<RiddleParser::FuncExprContext *>(ctx->child)) {
            const auto func = theClass.get().funcs.at(childName);
            const auto args = any_cast<std::vector<llvm::Value *>>(visit(FuncExpr->args));
            llvm::Value *result = Builder.CreateCall(func, args);
            return std::tuple{result,result->getType()};
        } else {
            const auto it = theClass.get().names.find(childName);
            if(it == theClass.get().names.end()) {
                throw std::logic_error("没有这个成员");
            }
            llvm::Value *result = Builder.CreateStructGEP(theClass.get().types, parent, it->second);
            return std::tuple{result,theClass.get().types->getElementType(it->second)};
        }
    }
    std::any GenVisitor::visitExprPtrParser(RiddleParser::ExprPtrParserContext *ctx) {
        auto tp = any_cast<std::tuple<llvm::Value*,llvm::Type*>>(visit(ctx->children[0]));
        auto [value,type] = tp;
        return value;
    }


    std::any GenVisitor::visitPackStatement(RiddleParser::PackStatementContext *ctx) {
        const auto packName = ctx->packName->getText();
        if(packName == "main")
            packStack.push("");
        else
            packStack.push(packName);

        return nullptr;
    }

    std::any GenVisitor::visitClassDefine(RiddleParser::ClassDefineContext *ctx) {
        const std::string name = packStack.top() + ctx->className->getText();
        const ClassNode theClass;
        theClass.get().types = llvm::StructType::create(globalContext, name);
        packStack.push(packStack.top() + ctx->className->getText());
        varManager.push();
        ParentStack.push(theClass);
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
