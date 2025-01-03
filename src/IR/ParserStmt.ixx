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
import IR.Statements;
import managers.ClassManager;
import managers.VarManager;
import managers.OpManager;
import Types.Class;
import IR.Context;
import Type.Variable;
import Types.Value;
export namespace Riddle {
    class ParserStmt {
        Context *ctx = nullptr;

        std::stack<llvm::BasicBlock *> breakBlocks;
        std::stack<llvm::BasicBlock *> continueBlocks;
        std::stack<llvm::Function *> parent;

    public:
        explicit ParserStmt(Context *ctx): ctx(ctx) {
        }

        // 获取从语句得到的结果
        std::any accept(BaseStmt *stmt) {
            switch(stmt->getStmtTypeID()) {
                case BaseStmt::StmtTypeID::ProgramStmtID:
                    ProgramPs(dynamic_cast<ProgramStmt *>(stmt));
                    return {};

                case BaseStmt::StmtTypeID::IntegerStmtID:
                    return IntegerPs(dynamic_cast<IntegerStmt *>(stmt));

                case BaseStmt::StmtTypeID::DoubleStmtID:
                    return DoublePs(dynamic_cast<DoubleStmt *>(stmt));

                case BaseStmt::StmtTypeID::BoolStmtID:
                    return BooleanPs(dynamic_cast<BoolStmt *>(stmt));

                case BaseStmt::StmtTypeID::ObjStmtID:
                    return ObjectPs(dynamic_cast<ObjectStmt *>(stmt));

                case BaseStmt::StmtTypeID::FuncDefineStmtID:
                    return FuncDefinePs(dynamic_cast<FuncDefineStmt *>(stmt));

                case BaseStmt::StmtTypeID::VarDefineStmtID:
                    VarDefinePs(dynamic_cast<VarDefineStmt *>(stmt));
                    return {};

                case BaseStmt::StmtTypeID::ReturnStmtID:
                    ReturnPs(dynamic_cast<ReturnStmt *>(stmt));
                    return {};

                case BaseStmt::StmtTypeID::WhileStmtID:
                    WhilePs(dynamic_cast<WhileStmt *>(stmt));
                    return {};

                case BaseStmt::StmtTypeID::ForStmtID:
                    ForPs(dynamic_cast<ForStmt *>(stmt));
                    return {};

                case BaseStmt::StmtTypeID::ContinueStmtID:
                    ContinuePs();
                    return {};

                case BaseStmt::StmtTypeID::BreakStmtID:
                    BreakPs();
                    return {};

                case BaseStmt::StmtTypeID::BinaryExprStmtID:
                    return BinaryExprPs(dynamic_cast<BinaryExprStmt *>(stmt));

                case BaseStmt::StmtTypeID::FuncCallStmtID:
                    return FuncCallPs(dynamic_cast<FuncCallStmt *>(stmt));

                case BaseStmt::StmtTypeID::StringStmtID:
                    return StringPs(dynamic_cast<StringStmt *>(stmt));

                case BaseStmt::StmtTypeID::IfStmtID:
                    IfPs(dynamic_cast<IfStmt *>(stmt));
                    return {};

                case BaseStmt::StmtTypeID::ClassDefineStmtID:
                    ClassDefinePs(dynamic_cast<ClassDefineStmt *>(stmt));
                    return {};

                case BaseStmt::StmtTypeID::MethodCallStmtID:
                    return MethodCallPs(dynamic_cast<MethodCallStmt *>(stmt));

                case BaseStmt::StmtTypeID::MemberExprStmtID:
                    return MemberExprPs(dynamic_cast<MemberExprStmt *>(stmt));

                case BaseStmt::StmtTypeID::BlockStmtID:
                    return BlockPs(dynamic_cast<BlockStmt *>(stmt));

                case BaseStmt::StmtTypeID::NoneStmtID:
                    return {};

                // 未知的 StmtTypeID 类型或未实现的类型
                default:
                    throw std::logic_error("Unhandled StmtTypeID");
            }
        }
        Value *IntegerPs(const IntegerStmt *stmt) const {
            Value *result = ctx->valueManager.getInteger(stmt->value);
            return result;
        }

        Value *DoublePs(const DoubleStmt *stmt) const {
            Value *result = ctx->valueManager.getFloat(stmt->value);
            return result;
        }

        Value *BooleanPs(const BoolStmt *stmt) const {
            Value *result = ctx->valueManager.getBool(stmt->value);
            return result;
        }

        Value *StringPs(const StringStmt *stmt) const {
            Value *result = ctx->valueManager.getString(stmt->value);
            return result;
        }

        void ProgramPs(ProgramStmt *stmt) {
            ctx->push();
            // TestLib start
            llvm::FunctionType *printfType = llvm::FunctionType::get(ctx->llvmBuilder.getVoidTy(), {ctx->llvmBuilder.getPtrTy()}, true);
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
        llvm::Function *FuncDefinePs(const FuncDefineStmt *stmt) {
            const std::string name = stmt->func_name;
            llvm::Type *returnType = ctx->classManager.getType(stmt->return_type);
            const auto args = stmt->args;
            BaseStmt *body = stmt->body;
            std::vector<llvm::Type *> argTypes;
            if(stmt->args != nullptr) {
                argTypes = args->getArgsTypes(ctx->classManager);
            }
            if(!stmt->theClass.empty()) {
                const auto theClass = ctx->classManager.getClass(stmt->theClass)->type;
                const auto ptr_theClass = theClass->getPointerTo();
                argTypes.insert(argTypes.begin(), ptr_theClass);
            }
            llvm::FunctionType *funcType = llvm::FunctionType::get(returnType, argTypes, false);
            llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, ctx->module);
            llvm::BasicBlock *entry = llvm::BasicBlock::Create(ctx->llvm_context, "entry", func);
            ctx->llvmBuilder.SetInsertPoint(entry);
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


        void VarDefinePs(const VarDefineStmt *stmt) {
            Value *value = nullptr;
            if(!stmt->value->isNoneStmt()) {
                value = std::any_cast<Value *>(accept(stmt->value));
            }
            const std::string name = stmt->name;
            llvm::Type *type = nullptr;
            if(stmt->type.empty() && value != nullptr) {
                type = value->getType();
            } else {
                type = ctx->classManager.getType(stmt->type);
            }

            llvm::Value *var;
            // 对全局变量特判
            if(ctx->deep() <= 1) {
                if(value == nullptr) {
                    throw std::logic_error("VarDefinePs called with nullptr");
                }
                auto *CV = llvm::dyn_cast<llvm::Constant>(value->toLLVM());
                var = new llvm::GlobalVariable(ctx->module, type, false,
                                               llvm::GlobalVariable::LinkageTypes::ExternalLinkage, CV, name);
            } else {
                // 实际上此处应该是被提前 Alloca 的时候运行的，不需要赋值，后续会被替换为 = 运算符
                var = ctx->llvmBuilder.CreateAlloca(type, nullptr, name);
            }
            ctx->addVariable(Variable(name, var, false));
        }

        // ReSharper disable once CppDFAConstantFunctionResult
        Value *ObjectPs(const ObjectStmt *stmt) const {
            const std::string name = stmt->name;
            // ReSharper disable once CppDFAUnreadVariable
            // ReSharper disable once CppDFAUnusedValue
            const auto ptr = ctx->varManager.getVar(name).var;
            const bool isLoaded = stmt->isLoaded;
            Value *value = nullptr;
            if(const auto arg = llvm::dyn_cast<llvm::Argument>(ptr); arg != nullptr) {
                value = ctx->valueManager.getLLVMValue(arg, arg->getType());
            } else if(const auto var = llvm::dyn_cast<llvm::AllocaInst>(ptr); var != nullptr) {
                if(isLoaded) {
                    llvm::Value *load = ctx->llvmBuilder.CreateLoad(var->getAllocatedType(), ptr);
                    value = ctx->valueManager.getLLVMValue(load, load->getType());
                } else {
                    value = ctx->valueManager.getLLVMValue(var, var->getAllocatedType());
                }
            }

            return value;
        }

        void ReturnPs(const ReturnStmt *stmt) {
            if(stmt->value == nullptr) {
                ctx->llvmBuilder.CreateRetVoid();
            }
            const auto result = std::any_cast<Value *>(accept(stmt->value));
            ctx->llvmBuilder.CreateRet(result->toLLVM());
        }

        llvm::Value *BlockPs(const BlockStmt *stmt) {
            ctx->push();
            for(const auto i: stmt->stmts) {
                accept(i);
            }
            ctx->pop();
            return nullptr;
        }

        void WhilePs(const WhileStmt *stmt) {
            llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(ctx->llvm_context, "while.cond", parent.top());
            llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(ctx->llvm_context, "while.loop", parent.top());
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(ctx->llvm_context, "while.exit", parent.top());

            ctx->llvmBuilder.CreateBr(condBlock);
            ctx->llvmBuilder.SetInsertPoint(condBlock);
            // cond 是必须要求的
            const auto cond = std::any_cast<Value *>(accept(stmt->condition));
            ctx->llvmBuilder.CreateCondBr(cond->toLLVM(), loopBlock, exitBlock);

            breakBlocks.push(exitBlock);
            continueBlocks.push(condBlock);

            ctx->push();
            ctx->llvmBuilder.SetInsertPoint(loopBlock);
            accept(stmt->body);
            ctx->llvmBuilder.CreateBr(condBlock);
            ctx->pop();

            breakBlocks.pop();
            continueBlocks.pop();

            ctx->llvmBuilder.SetInsertPoint(exitBlock);
        }

        void ForPs(const ForStmt *stmt) {
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

            ctx->llvmBuilder.CreateBr(condBlock);
            ctx->llvmBuilder.SetInsertPoint(condBlock);
            // 如果没有 Cond 那么一直运行
            llvm::Value *cond = ctx->llvmBuilder.getInt1(true);
            if(!stmt->condition->isNoneStmt()) {
                cond = std::any_cast<Value *>(accept(stmt->condition))->toLLVM();
            }

            ctx->llvmBuilder.CreateCondBr(cond, loopBlock, exitBlock);

            // 设置当前 break 和 continue 执行的对象
            breakBlocks.push(exitBlock);
            continueBlocks.push(condBlock);

            ctx->llvmBuilder.SetInsertPoint(loopBlock);
            if(!stmt->self_change->isNoneStmt()) {
                accept(stmt->self_change);
            }
            accept(stmt->body);
            ctx->llvmBuilder.CreateBr(condBlock);

            ctx->llvmBuilder.SetInsertPoint(exitBlock);

            ctx->pop();

            breakBlocks.pop();
            continueBlocks.pop();
        }

        void BreakPs() {
            ctx->llvmBuilder.CreateBr(breakBlocks.top());
        }

        void ContinuePs() {
            ctx->llvmBuilder.CreateBr(continueBlocks.top());
        }

        Value *BinaryExprPs(const BinaryExprStmt *stmt) {
            const auto lhs = std::any_cast<Value *>(accept(stmt->lhs));
            const auto rhs = std::any_cast<Value *>(accept(stmt->rhs))->toLLVM();
            const auto op = stmt->opt;
            if(lhs->getType()->isPointerTy() && op != "=") {
                const auto load_lhs = ctx->llvmBuilder.CreateLoad(lhs->getType(), lhs->toLLVM());
                llvm::Value *result_t = ctx->opManager.getOpFunc(OpGroup{load_lhs->getType(), rhs->getType(), op})(ctx->llvmBuilder, load_lhs, rhs);
                Value *result = ctx->valueManager.getLLVMValue(result_t, result_t->getType());
                return result;
            }
            // 由于可能的运算符的数量过多，我们使用一个Manager来控制
            // 虽然 ptr 类型无法获取到实际存储的类型，但是仍然可以匹配上
            llvm::Value *result_t = ctx->opManager.getOpFunc(OpGroup{lhs->getType(), rhs->getType(), op})(ctx->llvmBuilder, lhs->toLLVM(), rhs);
            Value *result = ctx->valueManager.getLLVMValue(result_t, result_t->getType());
            return result;
        }


        void IfPs(const IfStmt *stmt) {
            llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(ctx->llvm_context, "if.cond", parent.top());
            llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(ctx->llvm_context, "if.then", parent.top());
            llvm::BasicBlock *elseBlock = nullptr;
            if(!stmt->elseBody->isNoneStmt()) {
                elseBlock = llvm::BasicBlock::Create(ctx->llvm_context, "if.else", parent.top());
            }
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(ctx->llvm_context, "if.exit", parent.top());


            ctx->push();

            ctx->llvmBuilder.CreateBr(condBlock);
            ctx->llvmBuilder.SetInsertPoint(condBlock);
            const auto cond = std::any_cast<Value *>(accept(stmt->condition))->toLLVM();
            if(elseBlock == nullptr) {
                ctx->llvmBuilder.CreateCondBr(cond, thenBlock, exitBlock);
            } else {
                ctx->llvmBuilder.CreateCondBr(cond, thenBlock, elseBlock);
            }

            // if true
            ctx->push();
            ctx->llvmBuilder.SetInsertPoint(thenBlock);
            accept(stmt->thenBody);
            ctx->llvmBuilder.CreateBr(exitBlock);
            ctx->pop();

            // if false
            if(elseBlock != nullptr) {
                ctx->push();
                ctx->llvmBuilder.SetInsertPoint(elseBlock);
                accept(stmt->elseBody);
                ctx->llvmBuilder.CreateBr(exitBlock);
                ctx->pop();
            }

            ctx->pop();
            ctx->llvmBuilder.SetInsertPoint(exitBlock);
        }

        void ClassDefinePs(const ClassDefineStmt *stmt) {
            const auto theClass = new Class();
            theClass->type = llvm::StructType::create(ctx->llvm_context, stmt->name);
            // 成员创建
            int cnt = 0;
            std::vector<llvm::Type *> types;
            for(const auto i: stmt->members) {
                const auto memberName = i->name;
                llvm::Type *type = nullptr;
                Value *value = nullptr;
                if(!i->value->isNoneStmt()) {
                    value = std::any_cast<Value *>(accept(i->value));
                }
                if(i->type.empty() && value != nullptr) {
                    type = value->getType();
                } else {
                    type = ctx->classManager.getType(i->type);
                }
                theClass->members[memberName] = cnt;
                types.push_back(type);
                cnt++;
            }
            theClass->type->setBody(types);
            ctx->classManager.createClass(theClass);

            // 方法创建
            for(const auto i: stmt->funcDefines) {
                std::string sourceName = i->func_name;
                i->func_name = stmt->name + "_" + i->func_name;
                i->theClass = stmt->name;

                const auto call = std::any_cast<llvm::Function *>(accept(i));
                theClass->funcs[sourceName] = call;
            }
        }

        Value *FuncCallPs(const FuncCallStmt *stmt) {
            const auto name = stmt->name;
            const auto argList = stmt->args;
            std::vector<llvm::Value *> args;
            for(const auto i: argList->args) {
                auto value = std::any_cast<Value *>(accept(i))->toLLVM();
                args.push_back(value);
            }
            llvm::Value *result_t = ctx->llvmBuilder.CreateCall(ctx->funcManager.getFunction(name), args);
            Value *result = ctx->valueManager.getLLVMValue(result_t, result_t->getType());
            return result;
        }

        Value *MethodCallPs(const MethodCallStmt *stmt) {
            const auto object = std::any_cast<Value *>(accept(stmt->object));
            const auto type = object->getType();
            const auto theClass = ctx->classManager.getClassFromType(type);
            // insert self
            const auto argList = stmt->call->args;
            argList->args.insert(argList->args.begin(), stmt->object);

            std::vector<llvm::Value *> args;
            for(const auto i: argList->args) {
                auto value = std::any_cast<Value *>(accept(i))->toLLVM();
                args.push_back(value);
            }
            llvm::Value *result_t = ctx->llvmBuilder.CreateCall(theClass->funcs[stmt->call->name], args);
            Value *result = ctx->valueManager.getLLVMValue(result_t, result_t->getType());
            return result;
        }

        Value *MemberExprPs(const MemberExprStmt *stmt) {
            const auto object_t = std::any_cast<Value *>(accept(stmt->parent));
            llvm::Value *object = object_t->toLLVM();
            const auto type = object->getType();
            const auto theClass = ctx->classManager.getClassFromType(type);

            const std::string child = stmt->child->name;

            const int index = theClass->members[child];
            if(type->isPointerTy()) {
                llvm::Value *ptr = ctx->llvmBuilder.CreateStructGEP(
                        theClass->type,
                        object,
                        index);

                Value *result = nullptr;
                llvm::Type *childType = theClass->type->getElementType(index);

                if(stmt->isLoaded) {
                    llvm::Value *load = ctx->llvmBuilder.CreateLoad(childType, ptr);
                    result = ctx->valueManager.getLLVMValue(load, childType);
                } else {
                    result = ctx->valueManager.getLLVMValue(ptr, childType);
                }
                return result;
            } else {
                llvm::Value *ptr = ctx->llvmBuilder.CreateExtractValue(object, index);
                return ctx->valueManager.getLLVMValue(ptr, type);
            }
        }
    };
}// namespace Riddle