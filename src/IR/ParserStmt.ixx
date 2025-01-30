module;
#include <any>
#include <iostream>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>
#include <stack>
#include <utility>
export module IR.ParserStmt;
import IR.Statements;
import Manager.OpManager;
import IR.Context;
import Types.Unit;
export namespace Riddle {
    class ParserStmt {
        Context *ctx = nullptr;

        std::stack<llvm::BasicBlock *> breakBlocks;
        std::stack<llvm::BasicBlock *> continueBlocks;
        std::stack<llvm::Function *> parent;

        Unit unit;

    public:
        explicit ParserStmt(Context *ctx, Unit unit): ctx(ctx), unit(std::move(unit)) {}

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

                case BaseStmt::StmtTypeID::StringLiteralStmtID:
                    return StringLiteralPs(dynamic_cast<StringLiteralStmt *>(stmt));

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
        Object *IntegerPs(const IntegerStmt *stmt) const {
            Type *intTy = new IntegerTy(ctx);
            llvm::Constant *v = ctx->builder.getInt32(stmt->value);
            Object *result = new Value(ctx, v, intTy);
            return result;
        }

        Object *DoublePs(const DoubleStmt *stmt) const {
            Type *doubleTy = new DoubleTy(ctx);
            llvm::Value *v = llvm::ConstantFP::get(ctx->builder.getDoubleTy(), stmt->value);
            Object *result = new Value(ctx, v, doubleTy);
            return result;
        }

        Object *BooleanPs(const BoolStmt *stmt) const {
            Type *intTy = new BooleanTy(ctx);
            llvm::Constant *v = ctx->builder.getInt32(stmt->value);
            Object *result = new Value(ctx, v, intTy);
            return result;
        }

        Object *StringLiteralPs(const StringLiteralStmt *stmt) const {
            Type *stringLiteral = new StringLiteralTy(ctx);
            llvm::Value *v = ctx->builder.CreateGlobalStringPtr(stmt->value);
            Object *result = new Value(ctx, v, stringLiteral);
            return result;
        }

        void ProgramPs(ProgramStmt *stmt) {
            for(const auto i: stmt->body) {
                accept(i);
            }
            if(verifyModule(*ctx->module, &llvm::errs())) {
                std::cerr << "Failed to verify module" << std::endl;
            }
            std::error_code EC;
            llvm::raw_fd_ostream OS(unit.getFileOption().output, EC, llvm::sys::fs::OF_None);
            ctx->module->print(OS, nullptr);
        }

        /// @brief 预处理 varDefine
        void PreVarDefinePs(BaseStmt *s) {
            if(const auto it = dynamic_cast<VarDefineStmt *>(s);it) {
                s->setIsBuild(false);
                VarDefinePs(it);
                s->setIsBuild(true);
                return;
            }
            if(s->BodyCount() == 1) {
                if(const auto it = dynamic_cast<ForStmt *>(s)) {
                    PreVarDefinePs(it->body);
                    return;
                }
                if(const auto it = dynamic_cast<WhileStmt *>(s)) {
                    PreVarDefinePs(it->body);
                    return;
                }
                if(const auto it = dynamic_cast<BlockStmt *>(s)) {
                    for(const auto i: it->stmts) {
                        PreVarDefinePs(i);
                    }
                    return;
                }
                if(const auto it = dynamic_cast<IfStmt *>(s)) {
                    PreVarDefinePs(it->thenBody);
                }
            } else if(s->BodyCount() == 2) {
                if(const auto it = dynamic_cast<IfStmt *>(s)) {
                    PreVarDefinePs(it->thenBody);
                    PreVarDefinePs(it->elseBody);
                }
            }
        }

        /// @brief 定义一个函数的具体实现，根据给定的函数定义语句创建LLVM函数
        Object *FuncDefinePs(const FuncDefineStmt *stmt) {
            // 判断函数修饰符是否合法
            if(stmt->theClass.empty()) {
                if(!stmt->modifier.isFunctionModifier()) {
                    throw std::logic_error("You are using the wrong modifier for the function: " + stmt->func_name);
                }
            } else {
                if(!stmt->modifier.isMethodModifier()) {
                    throw std::logic_error("You are using the wrong modifier for the method: " + stmt->theClass + "::" + stmt->func_name);
                }
            }

            const std::string name = stmt->func_name;
            const auto returnType = ctx->objectManager->getType(stmt->return_type);
            if(returnType == nullptr) {
                throw std::logic_error(std::format("\'{}\' is not a Type", stmt->return_type.toString()));
            }

            auto args = stmt->args;
            BaseStmt *body = stmt->body;
            if(stmt->args == nullptr) {
                args = ctx->stmtManager.getDefineArgList({});
            }

            std::vector<llvm::Type *> argTypes;
            std::vector<Type *> riddleArgTypes;
            argTypes.reserve(args->args.size());
            for(const auto arg: args->args) {
                const auto t = ctx->objectManager->getType(arg->type);
                riddleArgTypes.push_back(t);
                argTypes.push_back(t->toLLVM());
            }

            if(!stmt->theClass.empty()) {
                const auto theClass = ctx->objectManager->getClass(stmt->theClass);
                const auto theClassTy = llvm::dyn_cast<llvm::StructType>(theClass->toLLVM());
                const auto ptr_theClass = theClassTy->getPointerTo();
                argTypes.insert(argTypes.begin(), ptr_theClass);
                const auto thisArg = ctx->stmtManager.getDefineArg("this", theClassTy->getName().str(), ctx->stmtManager.getNoneStmt());
                args->args.insert(args->args.begin(), thisArg);
                ctx->pushNowClass(theClass);
            } else {
                ctx->pushNowClass(nullptr);
            }
            llvm::FunctionType *funcType = llvm::FunctionType::get(returnType->toLLVM(), argTypes, false);
            llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, *ctx->module);
            llvm::BasicBlock *entry = llvm::BasicBlock::Create(*ctx->llvm_context, "entry", func);
            ctx->builder.SetInsertPoint(entry);
            const auto mod = stmt->modifier;
            const auto funcObj = new Function(ctx, name, func, returnType, riddleArgTypes, mod, ctx->getNowClass());
            ctx->objectManager->addObject(name, funcObj);

            // 预处理对象分配
            ctx->push();
            parent.push(func);
            PreVarDefinePs(stmt->body);
            ctx->pop();
            parent.pop();

            ctx->push();
            parent.push(func);


            // 配置函数传参
            // ReSharper disable once CppDFAConstantConditions
            if(args != nullptr) {
                const auto argNames = args->getArgsNames();
                int i = 0;
                auto it = func->arg_begin();
                if(!stmt->theClass.empty()) {
                    it->setName("this");
                    const auto theClass = ctx->objectManager->getClass(stmt->theClass);
                    const auto t = new Value(ctx, "this", it, theClass, true);
                    ctx->objectManager->addObject("this", t);
                    it++;
                    i++;
                }
                // 配置其他arg
                for(; it != func->arg_end(); ++it, ++i) {
                    it->setName(argNames[i]);
                    const auto t = new Value(ctx, argNames[i], it, riddleArgTypes[i], true);
                    ctx->objectManager->addObject(argNames[i], t);
                }
                // ReSharper disable once CppDFAUnreachableCode
            } else if(!stmt->theClass.empty()) {
                const auto it = func->arg_begin();
                it->setName("this");
                const auto theClass = ctx->objectManager->getClass(stmt->theClass);
                const auto t = new Value(ctx, "this", it, theClass, true);
                ctx->objectManager->addObject("this", t);
            }

            accept(body);
            if(returnType->isVoidTy()) {
                const auto t = ctx->stmtManager.getReturn();
                accept(t);
            }
            ctx->pop();
            parent.pop();
            ctx->popNowClass();

            return funcObj;
        }

        /// @brief 用于解析变量定义的函数
        /// @param stmt 语句
        void VarDefinePs(VarDefineStmt *stmt) {
            const std::string_view name = stmt->name;
            Type *type = nullptr;
            if(!stmt->type.empty()) {
                type = ctx->objectManager->getType(stmt->type);
            }

            Value *value = nullptr;
            if(!stmt->value->isNoneStmt()) {
                value = dynamic_cast<Value *>(std::any_cast<Object *>(accept(stmt->value)));
            }
            if(type == nullptr && value != nullptr) {
                type = value->getType();
            }
            // 推断判断是否失败
            if(type == nullptr) {
                throw std::logic_error(std::format("Failed to infer the type of \'{}\'", stmt->name));
            }

            // 如果已经被预处理完成
            if(stmt->isAlloca) {
                const auto alloca = new Value(ctx, name.data(), stmt->alloca, type, true);
                ctx->objectManager->addObject(name.data(), alloca);
                if(value != nullptr) {
                    ctx->builder.CreateStore(value->toLLVM(), stmt->alloca);
                }
                return;
            }

            Value *var;

            // 否则进行预处理/全局变量处理
            if(ctx->deep() <= 1) {
                // 全局变量
                if(value == nullptr) {
                    throw std::logic_error("VarDefinePs(): called with nullptr");
                }
                auto *c = llvm::dyn_cast<llvm::Constant>(value->toLLVM());
                const auto ptr = new llvm::GlobalVariable(*ctx->module, type->toLLVM(), false,
                                                          llvm::GlobalVariable::LinkageTypes::ExternalLinkage, c, name);
                var = new Value(ctx, name.data(), ptr, type);
            } else {
                const auto ptr = ctx->builder.CreateAlloca(type->toLLVM(), nullptr, name);
                var = new Value(ctx, name.data(), ptr, type);
            }
            stmt->alloca = var->toLLVM();
            stmt->isAlloca = true;
            ctx->objectManager->addObject(name.data(), var);
        }

        // ReSharper disable once CppDFAConstantFunctionResult
        Object *ObjectPs(const ObjectStmt *stmt) const {
            const std::string name = stmt->name;
            // ReSharper disable once CppDFAUnreadVariable
            // ReSharper disable once CppDFAUnusedValue
            const auto ptr = ctx->objectManager->getObject(name);
            const bool isLoaded = stmt->isLoaded;
            const auto t = dynamic_cast<Value *>(ptr);
            if(!stmt->getIsBuild()) {
                return ptr;
            }
            if(t != nullptr) {
                if(const auto var = llvm::dyn_cast<llvm::AllocaInst>(t->toLLVM()); var != nullptr) {
                    Value *value = nullptr;
                    if(isLoaded) {
                        llvm::Value *load = ctx->builder.CreateLoad(var->getAllocatedType(), t->toLLVM());
                        Type *type = ptr->getType();
                        value = new Value(ctx, load, type);
                    } else {
                        value = dynamic_cast<Value *>(ptr);
                    }
                    return value;
                }
            }
            return ptr;
        }

        void ReturnPs(const ReturnStmt *stmt) {
            if(stmt->value == nullptr) {
                ctx->builder.CreateRetVoid();
            }
            const auto result = dynamic_cast<Value *>(std::any_cast<Object *>(accept(stmt->value)));
            ctx->builder.CreateRet(result->toLLVM());
        }

        Object *BlockPs(const BlockStmt *stmt) {
            ctx->push();
            for(const auto i: stmt->stmts) {
                accept(i);
            }
            ctx->pop();
            return nullptr;
        }

        void WhilePs(const WhileStmt *stmt) {
            llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(*ctx->llvm_context, "while.cond", parent.top());
            llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(*ctx->llvm_context, "while.loop", parent.top());
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(*ctx->llvm_context, "while.exit", parent.top());

            ctx->builder.CreateBr(condBlock);
            ctx->builder.SetInsertPoint(condBlock);
            // cond 是必须要求的
            const auto cond = dynamic_cast<Value *>(std::any_cast<Object *>(accept(stmt->condition)));
            ctx->builder.CreateCondBr(cond->toLLVM(), loopBlock, exitBlock);

            breakBlocks.push(exitBlock);
            continueBlocks.push(condBlock);

            ctx->push();
            ctx->builder.SetInsertPoint(loopBlock);
            accept(stmt->body);
            ctx->builder.CreateBr(condBlock);
            ctx->pop();

            breakBlocks.pop();
            continueBlocks.pop();

            ctx->builder.SetInsertPoint(exitBlock);
        }

        void ForPs(const ForStmt *stmt) {
            llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(*ctx->llvm_context, "for.cond", parent.top());
            llvm::BasicBlock *loopBlock = llvm::BasicBlock::Create(*ctx->llvm_context, "for.loop", parent.top());
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(*ctx->llvm_context, "for.exit", parent.top());

            if(!stmt->init->isNoneStmt()) {
                accept(stmt->init);
            }

            ctx->push();

            if(!stmt->init->isNoneStmt()) {
                accept(stmt->init);
            }

            ctx->builder.CreateBr(condBlock);
            ctx->builder.SetInsertPoint(condBlock);
            // 如果没有 Cond 那么一直运行
            llvm::Value *cond = ctx->builder.getInt1(true);
            if(!stmt->condition->isNoneStmt()) {
                cond = dynamic_cast<Value *>(std::any_cast<Object *>(accept(stmt->condition)))->toLLVM();
            }

            ctx->builder.CreateCondBr(cond, loopBlock, exitBlock);

            // 设置当前 break 和 continue 执行的对象
            breakBlocks.push(exitBlock);
            continueBlocks.push(condBlock);

            ctx->builder.SetInsertPoint(loopBlock);
            if(!stmt->self_change->isNoneStmt()) {
                accept(stmt->self_change);
            }
            accept(stmt->body);
            ctx->builder.CreateBr(condBlock);

            ctx->builder.SetInsertPoint(exitBlock);

            ctx->pop();

            breakBlocks.pop();
            continueBlocks.pop();
        }

        void BreakPs() {
            ctx->builder.CreateBr(breakBlocks.top());
        }

        void ContinuePs() {
            ctx->builder.CreateBr(continueBlocks.top());
        }

        Object *BinaryExprPs(const BinaryExprStmt *stmt) {
            const auto lhs = dynamic_cast<Value *>(std::any_cast<Object *>(accept(stmt->lhs)));
            const auto rhs = dynamic_cast<Value *>(std::any_cast<Object *>(accept(stmt->rhs)))->toLLVM();
            const auto op = stmt->opt;
            Type *type = lhs->getType();
            if(lhs->getType()->toLLVM()->isPointerTy() && op != "=") {
                const auto load_lhs = ctx->builder.CreateLoad(lhs->getType()->toLLVM(), lhs->toLLVM());
                llvm::Value *result_t = ctx->opManager.getOpFunc(OpGroup{load_lhs->getType(), rhs->getType(), op})(ctx->builder, load_lhs, rhs);
                return new Value(ctx, result_t, type);
            }
            // 由于可能的运算符的数量过多，我们使用一个Manager来控制
            // 虽然 ptr 类型无法获取到实际存储的类型，但是仍然可以匹配上
            llvm::Value *result_t = ctx->opManager.getOpFunc(OpGroup{lhs->getType()->toLLVM(), rhs->getType(), op})(ctx->builder, lhs->toLLVM(), rhs);
            return new Value(ctx, result_t, type);
        }


        void IfPs(const IfStmt *stmt) {
            llvm::BasicBlock *condBlock = llvm::BasicBlock::Create(*ctx->llvm_context, "if.cond", parent.top());
            llvm::BasicBlock *thenBlock = llvm::BasicBlock::Create(*ctx->llvm_context, "if.then", parent.top());
            llvm::BasicBlock *elseBlock = nullptr;
            if(!stmt->elseBody->isNoneStmt()) {
                elseBlock = llvm::BasicBlock::Create(*ctx->llvm_context, "if.else", parent.top());
            }
            llvm::BasicBlock *exitBlock = llvm::BasicBlock::Create(*ctx->llvm_context, "if.exit", parent.top());


            ctx->push();

            ctx->builder.CreateBr(condBlock);
            ctx->builder.SetInsertPoint(condBlock);
            const auto cond = dynamic_cast<Value *>(std::any_cast<Object *>(accept(stmt->condition)))->toLLVM();
            if(elseBlock == nullptr) {
                ctx->builder.CreateCondBr(cond, thenBlock, exitBlock);
            } else {
                ctx->builder.CreateCondBr(cond, thenBlock, elseBlock);
            }

            // if true
            ctx->push();
            ctx->builder.SetInsertPoint(thenBlock);
            accept(stmt->thenBody);
            ctx->builder.CreateBr(exitBlock);
            ctx->pop();

            // if false
            if(elseBlock != nullptr) {
                ctx->push();
                ctx->builder.SetInsertPoint(elseBlock);
                accept(stmt->elseBody);
                ctx->builder.CreateBr(exitBlock);
                ctx->pop();
            }

            ctx->pop();
            ctx->builder.SetInsertPoint(exitBlock);
        }

        void ClassDefinePs(ClassDefineStmt *stmt) {
            const auto theClass = new Class(ctx, stmt->name, {});
            // 构建继承
            if(!stmt->parentClass.empty()) {
                const auto parentClass = ctx->objectManager->getClass(stmt->parentClass);
                for(const auto &[name, type]: parentClass->getAllMembers()) {
                    theClass->addMember(name, type.first);
                }
                theClass->updateStructTy();

                // 继承方法
                for(const auto &[name, func]: parentClass->getAllFunctions()) {
                    theClass->addFunction(name, func);
                }
            }
            // 成员创建
            for(const auto i: stmt->members) {
                std::string_view memberName = i->name;
                const auto type = ctx->objectManager->getType(i->type);
                theClass->addMember(memberName.data(), type);
            }
            theClass->updateStructTy();
            ctx->objectManager->addObject(stmt->name, theClass);

            // 函数创建
            ctx->pushNowClass(theClass);
            for(const auto i: stmt->funcDefines) {
                std::string_view name = i->func_name;
                const auto func = dynamic_cast<Function *>(std::any_cast<Object *>(accept(i)));
                if(func == nullptr) {
                    throw std::runtime_error("ClassDefinePs(): Result not a Function");
                }
                theClass->addFunction(name.data(), func);
            }
            ctx->popNowClass();
        }

        Object *FuncCallPs(const FuncCallStmt *stmt) {
            const auto name = stmt->name;
            const auto argList = stmt->args;
            std::vector<llvm::Value *> args;
            for(const auto i: argList->args) {
                auto value = dynamic_cast<Value *>(std::any_cast<Object *>(accept(i)))->toLLVM();
                args.push_back(value);
            }
            Function *func = ctx->objectManager->getFunction(name);
            if(!stmt->getIsBuild()) {
                const auto result = new Value(ctx,nullptr,func->getType());
                return result;
            }
            llvm::Value *result_t = ctx->builder.CreateCall(func->getCallee(), args);
            const auto result = new Value(ctx, result_t, func->getType());
            return result;
        }

        Object *MethodCallPs(const MethodCallStmt *stmt) {
            const auto object = dynamic_cast<Value *>(std::any_cast<Object *>(accept(stmt->object)));
            Type *type = object->getType();
            if(!type->isClassTy()) {
                throw std::runtime_error("MethodCallPs(): Result not a Class");
            }
            const auto theClass = dynamic_cast<Class *>(type);
            const std::string_view funcName = stmt->call->name;
            // insert self
            const auto argList = stmt->call->args;
            argList->args.insert(argList->args.begin(), stmt->object);

            std::vector<llvm::Value *> args;
            for(const auto i: argList->args) {
                auto value = dynamic_cast<Value *>(std::any_cast<Object *>(accept(i)))->toLLVM();
                args.push_back(value);
            }
            if(!stmt->getIsBuild()) {
                return theClass->getFunction(funcName.data())->getType();
            }
            const llvm::FunctionCallee call = theClass->getFunction(funcName.data())->getCallee();
            llvm::Value *result_t = ctx->builder.CreateCall(call, args);
            const auto result = new Value(ctx, result_t, type);
            return result;
        }

        Object *MemberExprPs(const MemberExprStmt *stmt) {
            const auto object = dynamic_cast<Value *>(std::any_cast<Object *>(accept(stmt->parent)));
            const auto type = object->getType();
            if(!type->isClassTy()) {
                throw std::runtime_error("MethodCallPs(): Result not a Class");
            }
            const auto theClass = dynamic_cast<Class *>(type);

            const std::string child = stmt->child->name;

            const size_t index = theClass->getMemberIndex(child);
            if(!stmt->getIsBuild()) {
                const auto obj = new Value(ctx,nullptr,theClass->getMember(stmt->child->name));
                return obj;
            }
            if(object->toLLVM()->getType()->isPointerTy()) {
                llvm::Value *ptr = ctx->builder.CreateStructGEP(
                        theClass->toLLVM(),
                        object->toLLVM(),
                        index);

                Value *result = nullptr;
                Type *childType = theClass->getMember(child);

                if(stmt->isLoaded) {
                    llvm::Value *load = ctx->builder.CreateLoad(childType->toLLVM(), ptr);
                    result = new Value(ctx, load, childType);
                } else {
                    result = new Value(ctx, ptr, childType);
                }
                return result;
            }
            llvm::Value *ptr = ctx->builder.CreateExtractValue(object->toLLVM(), index);
            return new Value(ctx, ptr, type);
        }
    };
}// namespace Riddle