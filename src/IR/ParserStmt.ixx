module;
#include <any>
#include <iostream>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Verifier.h>
#include <stack>
export module IR.ParserStmt;
import Types.Statements;
import managers.ClassManager;
import managers.VarManager;
import managers.OpManager;
import Types.Class;
import IR.Context;
import IR.TypeParser;
import Type.Variable;
export namespace Riddle {
    class ParserStmt {
        Context *ctx = nullptr;
        llvm::IRBuilder<> llvmBuilder;
        ClassManager classManager;
        std::stack<llvm::BasicBlock *> breakBlocks;
        std::stack<llvm::BasicBlock *> continueBlocks;
        std::stack<llvm::Function *> parent;

    public:
        explicit ParserStmt(Context *ctx): ctx(ctx), llvmBuilder(ctx->llvm_context), classManager(ctx->llvm_context) {
        }

        // 获取从语句得到的结果
        std::any accept(BaseStmt *stmt) {// NOLINT(*-no-recursion)
            switch(stmt->getStmtTypeID()) {
                case BaseStmt::StmtTypeID::ProgramStmtID:
                    Program(dynamic_cast<ProgramStmt *>(stmt));
                    return nullptr;

                case BaseStmt::StmtTypeID::IntegerStmtID:
                    return Integer(dynamic_cast<IntegerStmt *>(stmt));

                case BaseStmt::StmtTypeID::DoubleStmtID:
                    return Double(dynamic_cast<DoubleStmt *>(stmt));

                case BaseStmt::StmtTypeID::BoolStmtID:
                    return Boolean(dynamic_cast<BoolStmt *>(stmt));

                case BaseStmt::StmtTypeID::ObjStmtID:
                    return Object(dynamic_cast<ObjectStmt *>(stmt));

                case BaseStmt::StmtTypeID::FuncDefineStmtID:
                    return FuncDefine(dynamic_cast<FuncDefineStmt *>(stmt));

                case BaseStmt::StmtTypeID::VarDefineStmtID:
                    return VarDefine(dynamic_cast<VarDefineStmt *>(stmt));

                case BaseStmt::StmtTypeID::ReturnStmtID:
                    return Return(dynamic_cast<ReturnStmt *>(stmt));

                case BaseStmt::StmtTypeID::WhileStmtID:
                    return While(dynamic_cast<WhileStmt *>(stmt));

                case BaseStmt::StmtTypeID::ForStmtID:
                    return For(dynamic_cast<ForStmt *>(stmt));

                case BaseStmt::StmtTypeID::ContinueStmtID:
                    return Continue();

                case BaseStmt::StmtTypeID::BreakStmtID:
                    return Break();

                case BaseStmt::StmtTypeID::BinaryExprStmtID:
                    return BinaryExpr(dynamic_cast<BinaryExprStmt *>(stmt));

                case BaseStmt::StmtTypeID::FuncCallStmtID:
                    return FuncCall(dynamic_cast<FuncCallStmt *>(stmt));

                case BaseStmt::StmtTypeID::StringStmtID:
                    return String(dynamic_cast<StringStmt *>(stmt));

                case BaseStmt::StmtTypeID::IfStmtID:
                    If(dynamic_cast<IfStmt *>(stmt));
                    return nullptr;

                case BaseStmt::StmtTypeID::ClassDefineStmtID:
                    ClassDefine(dynamic_cast<ClassDefineStmt *>(stmt));
                    return nullptr;

                case BaseStmt::StmtTypeID::BlockStmtID:
                    return Block(dynamic_cast<BlockStmt *>(stmt));

                case BaseStmt::StmtTypeID::NoneStmtID:
                    return nullptr;

                // 未知的 StmtTypeID 类型或未实现的类型
                default:
                    throw std::logic_error("Unhandled StmtTypeID");
            }
        }
        llvm::Value *Integer(const IntegerStmt *stmt) {
            llvm::Value *result = llvmBuilder.getInt32(stmt->value);
            return result;
        }

        llvm::Value *Double(const DoubleStmt *stmt) const {
            llvm::Value *result = llvm::ConstantFP::get(llvm::Type::getDoubleTy(ctx->llvm_context), stmt->value);
            return result;
        }

        llvm::Value *Boolean(const BoolStmt *stmt) {
            llvm::Value *result = llvmBuilder.getInt1(stmt->value);
            return result;
        }
        llvm::Value *String(const StringStmt *stmt) {
            llvm::Value *result = llvmBuilder.CreateGlobalStringPtr(stmt->value);
            return result;
        }

        void Program(ProgramStmt *stmt) {// NOLINT(*-no-recursion)
            ctx->push();
            // TestLib start
            llvm::FunctionType *printfType = llvm::FunctionType::get(llvmBuilder.getVoidTy(), {llvmBuilder.getPtrTy()}, false);
            llvm::Function *printfFunc = llvm::Function::Create(
                    printfType, llvm::Function::ExternalLinkage, "printf", ctx->module);
            ctx->funcManager.registerFunction("printf", printfFunc);
            // TestLib end
            for(const auto i: stmt->body) {
                accept(i);
            }
            ctx->pop();
            if(verifyModule(ctx->module, &llvm::errs())) {
                std::cerr << "Failed to verify module" << std::endl;
            }
            ctx->module.print(llvm::outs(), nullptr);
        }

        /// @brief 定义一个函数的具体实现，根据给定的函数定义语句创建LLVM函数
        llvm::Function *FuncDefine(const FuncDefineStmt *stmt) {// NOLINT(*-no-recursion)
            const std::string name = stmt->func_name;
            llvm::Type *returnType = classManager.getType(stmt->return_type);
            const auto args = stmt->args;
            BaseStmt *body = stmt->body;
            std::vector<llvm::Type *> argTypes;
            if(stmt->args != nullptr) {
                argTypes = args->getArgsTypes(classManager);
            }
            llvm::FunctionType *funcType = llvm::FunctionType::get(returnType, argTypes, false);
            llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, ctx->module);
            llvm::BasicBlock *entry = llvm::BasicBlock::Create(ctx->llvm_context, "entry", func);
            llvmBuilder.SetInsertPoint(entry);
            ctx->funcManager.registerFunction(name, func);

            // 预处理 varDefine
            std::function<void(BaseStmt *)> pre_varDefine = [&](BaseStmt *s) {
                // 立刻分配空间
                if(const auto it = dynamic_cast<VarDefineStmt *>(s)) {
                    accept(it);
                    return;
                }
                if(s->BodyCount() == 1) {
                    if(const auto it = dynamic_cast<ForStmt *>(s)) {
                        pre_varDefine(it->body);
                    }
                    if(const auto it = dynamic_cast<WhileStmt *>(s)) {
                        pre_varDefine(it->body);
                    }
                    if(const auto it = dynamic_cast<BlockStmt *>(s)) {
                        for(const auto i: it->stmts) {
                            pre_varDefine(i);
                        }
                        for(int i = 0; i < it->stmts.size(); i++) {
                            if(const auto t = dynamic_cast<VarDefineStmt *>(it->stmts[i])) {
                                if(!t->value->isNoneStmt()) {
                                    it->stmts[i] = ctx->stmtManager.getBinaryExpr(ctx->stmtManager.getObject(t->name), t->value, "=");
                                    i--;
                                } else {
                                    it->stmts[i] = ctx->stmtManager.getNoneStmt();
                                }
                            }
                        }
                    }
                    if(const auto it = dynamic_cast<IfStmt *>(s)) {
                        pre_varDefine(it->thenBody);
                    }
                } else if(s->BodyCount() == 2) {
                    if(const auto it = dynamic_cast<IfStmt *>(s)) {
                        pre_varDefine(it->thenBody);
                        pre_varDefine(it->elseBody);
                    }
                }
            };

            ctx->push();
            parent.push(func);

            if(args != nullptr) {
                const auto argNames = args->getArgsNames();
                int i = 0;
                for(auto it = func->arg_begin(); it != func->arg_end(); ++it, ++i) {
                    it->setName(argNames[i]);
                    llvm::Value *t = it;
                    ctx->varManager.defineVar(argNames[i], false, t);
                }
            }

            pre_varDefine(body);

            accept(body);
            if(returnType->isVoidTy()) {
                const auto t = ctx->stmtManager.getReturn();
                accept(t);
            }
            ctx->pop();
            parent.pop();

            return func;
        }


        llvm::Value *VarDefine(const VarDefineStmt *stmt) {// NOLINT(*-no-recursion)
            llvm::Value *value = nullptr;
            if(!stmt->value->isNoneStmt()) {
                value = std::any_cast<llvm::Value *>(accept(stmt->value));
            }
            const std::string name = stmt->name;
            llvm::Type *type = nullptr;
            if(stmt->type.empty() && value != nullptr) {
                type = value->getType();
            } else {
                type = classManager.getType(stmt->type);
            }

            llvm::Value *var;
            // 对全局变量特判
            if(ctx->deep() <= 1) {
                auto *CV = llvm::dyn_cast<llvm::Constant>(value);
                var = new llvm::GlobalVariable(ctx->module, type, false,
                                               llvm::GlobalVariable::LinkageTypes::ExternalLinkage, CV, name);
            } else {
                var = llvmBuilder.CreateAlloca(type, nullptr, name);
            }
            ctx->addVariable(Variable(name, var, false));
            return var;
        }

        llvm::Value *Object(const ObjectStmt *stmt) const {
            const std::string name = stmt->name;
            return ctx->varManager.getVar(name).var;
        }

        llvm::Value *Return(const ReturnStmt *stmt) {// NOLINT(*-no-recursion)
            if(stmt->value == nullptr) {
                return llvmBuilder.CreateRetVoid();
            }
            const auto result = std::any_cast<llvm::Value *>(accept(stmt->value));
            return llvmBuilder.CreateRet(result);
        }

        llvm::Value *Block(const BlockStmt *stmt) {// NOLINT(*-no-recursion)
            ctx->push();
            for(const auto i: stmt->stmts) {
                accept(i);
            }
            ctx->pop();
            return nullptr;
        }

        llvm::Value *While(const WhileStmt *stmt) {// NOLINT(*-no-recursion)
            llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(ctx->llvm_context, "while.cond", parent.top());
            llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(ctx->llvm_context, "while.loop", parent.top());
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(ctx->llvm_context, "while.exit", parent.top());

            llvmBuilder.CreateBr(condBlock);
            llvmBuilder.SetInsertPoint(condBlock);
            // cond 是必须要求的
            const auto cond = std::any_cast<llvm::Value *>(accept(stmt->condition));
            llvmBuilder.CreateCondBr(cond, loopBlock, exitBlock);

            breakBlocks.push(exitBlock);
            continueBlocks.push(condBlock);

            ctx->push();
            llvmBuilder.SetInsertPoint(loopBlock);
            accept(stmt->body);
            llvmBuilder.CreateBr(condBlock);
            ctx->pop();

            breakBlocks.pop();
            continueBlocks.pop();

            llvmBuilder.SetInsertPoint(exitBlock);
            return nullptr;
        }

        llvm::Value *For(const ForStmt *stmt) {// NOLINT(*-no-recursion)
            llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(ctx->llvm_context, "for.cond", parent.top());
            llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(ctx->llvm_context, "for.loop", parent.top());
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(ctx->llvm_context, "for.exit", parent.top());

            if(!stmt->init->isNoneStmt()) {
                accept(stmt->init);
            }

            ctx->push();

            if(!stmt->init->isNoneStmt()) {
                accept(stmt->init);
            }

            llvmBuilder.CreateBr(condBlock);
            llvmBuilder.SetInsertPoint(condBlock);
            // 如果没有 Cond 那么一直运行
            llvm::Value *cond = llvmBuilder.getInt1(true);
            if(!stmt->condition->isNoneStmt()) {
                cond = std::any_cast<llvm::Value *>(accept(stmt->condition));
            }

            llvmBuilder.CreateCondBr(cond, loopBlock, exitBlock);

            // 设置当前 break 和 continue 执行的对象
            breakBlocks.push(exitBlock);
            continueBlocks.push(condBlock);

            llvmBuilder.SetInsertPoint(loopBlock);
            if(!stmt->self_change->isNoneStmt()) {
                accept(stmt->self_change);
            }
            accept(stmt->body);
            llvmBuilder.CreateBr(condBlock);

            llvmBuilder.SetInsertPoint(exitBlock);

            ctx->pop();

            breakBlocks.pop();
            continueBlocks.pop();

            return nullptr;
        }

        llvm::Value *Break() {
            llvmBuilder.CreateBr(breakBlocks.top());
            return nullptr;
        }

        llvm::Value *Continue() {
            llvmBuilder.CreateBr(continueBlocks.top());
            return nullptr;
        }

        llvm::Value *BinaryExpr(const BinaryExprStmt *stmt) {// NOLINT(*-no-recursion)
            auto lhs = std::any_cast<llvm::Value *>(accept(stmt->lhs));
            const auto rhs = std::any_cast<llvm::Value *>(accept(stmt->rhs));
            const auto op = stmt->opt;
            if(lhs->getType()->isPointerTy() && op != "=") {
                lhs = llvmBuilder.CreateLoad(getSourceType(lhs), lhs);
            }
            // 由于可能的运算符的数量过多，我们使用一个Manager来控制
            // 虽然 ptr 类型无法获取到实际存储的类型，但是仍然可以匹配上
            llvm::Value *result = ctx->opManager.getOpFunc(OpGroup{getSourceType(lhs), getSourceType(rhs), op})(llvmBuilder, lhs, rhs);
            return result;
        }

        llvm::Value *FuncCall(const FuncCallStmt *stmt) {// NOLINT(*-no-recursion)
            const auto name = stmt->name;
            const auto argList = stmt->args;
            std::vector<llvm::Value *> args;
            for(const auto i: argList->args) {
                auto value = std::any_cast<llvm::Value *>(accept(i));
                args.push_back(value);
            }
            llvm::Value *result = llvmBuilder.CreateCall(ctx->funcManager.getFunction(name), args);
            return result;
        }

        void If(const IfStmt *stmt) {// NOLINT(*-no-recursion)
            llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(ctx->llvm_context, "if.cond", parent.top());
            llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(ctx->llvm_context, "if.then", parent.top());
            llvm::BasicBlock *elseBlock = nullptr;
            if(!stmt->elseBody->isNoneStmt()) {
                elseBlock = llvm::BasicBlock::Create(ctx->llvm_context, "if.else", parent.top());
            }
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(ctx->llvm_context, "if.exit", parent.top());


            ctx->push();

            llvmBuilder.CreateBr(condBlock);
            llvmBuilder.SetInsertPoint(condBlock);
            const auto cond = std::any_cast<llvm::Value *>(accept(stmt->condition));
            if(elseBlock == nullptr) {
                llvmBuilder.CreateCondBr(cond, thenBlock, exitBlock);
            } else {
                llvmBuilder.CreateCondBr(cond, thenBlock, elseBlock);
            }

            // if true
            ctx->push();
            llvmBuilder.SetInsertPoint(thenBlock);
            accept(stmt->thenBody);
            llvmBuilder.CreateBr(exitBlock);
            ctx->pop();

            // if false
            if(elseBlock != nullptr) {
                ctx->push();
                llvmBuilder.SetInsertPoint(elseBlock);
                accept(stmt->elseBody);
                llvmBuilder.CreateBr(exitBlock);
                ctx->pop();
            }

            ctx->pop();
            llvmBuilder.SetInsertPoint(exitBlock);
        }

        void ClassDefine(const ClassDefineStmt *stmt) {// NOLINT(*-no-recursion)
            const auto theClass = new Class();
            theClass->types = llvm::StructType::create(ctx->llvm_context, stmt->name);
            // 成员创建
            int cnt = 0;
            std::vector<llvm::Type *> types;
            for(const auto i: stmt->members) {
                const auto memberName = i->name;
                llvm::Type *type = nullptr;
                const llvm::Value *value = nullptr;
                if(!i->value->isNoneStmt()) {
                    value = std::any_cast<llvm::Value *>(accept(i->value));
                }
                if(i->type.empty() && value != nullptr) {
                    type = value->getType();
                } else {
                    type = classManager.getType(i->type);
                }
                theClass->names[memberName] = cnt;
                types.push_back(type);
                cnt++;
            }
            theClass->types->setBody(types);
            classManager.createClass(theClass);

            // 方法创建
            for(const auto i: stmt->funcDefines) {
                std::string sourceName = i->func_name;
                i->func_name = stmt->name + "_" + i->func_name;

                auto self = ctx->stmtManager.getDefineArg("this", stmt->name, ctx->stmtManager.getNoneStmt());
                if(i->args == nullptr || i->args->isNoneStmt()) {
                    i->args = ctx->stmtManager.getDefineArgList({self});
                } else {
                    i->args->args.push_back(self);
                }
                const auto call = std::any_cast<llvm::Function*>(accept(i));
                theClass->funcs[sourceName] = call;
            }
        }
    };
}// namespace Riddle