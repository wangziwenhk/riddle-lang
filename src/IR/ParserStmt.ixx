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
import IR.Objects;
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
            Object *result = new Constant(ctx, intTy, v);
            return result;
        }

        Object *DoublePs(const DoubleStmt *stmt) const {
            Type *doubleTy = new DoubleTy(ctx);
            llvm::Value *v = llvm::ConstantFP::get(ctx->builder.getDoubleTy(), stmt->value);
            Object *result = new Constant(ctx, doubleTy, v);
            return result;
        }

        Object *BooleanPs(const BoolStmt *stmt) const {
            Type *intTy = new BooleanTy(ctx);
            llvm::Constant *v = ctx->builder.getInt32(stmt->value);
            Object *result = new Constant(ctx, intTy, v);
            return result;
        }

        Object *StringLiteralPs(const StringLiteralStmt *stmt) const {
            Type *stringLiteral = new StringLiteralTy(ctx);
            llvm::Value *v = ctx->builder.CreateGlobalStringPtr(stmt->value);
            Object *result = new Constant(ctx, stringLiteral, v);
            return result;
        }

        void ProgramPs(ProgramStmt *stmt) {
            ctx->push();
            for(const auto i: stmt->body) {
                accept(i);
            }
            ctx->pop();
            if(verifyModule(*ctx->module, &llvm::errs())) {
                std::cerr << "Failed to verify module" << std::endl;
            }
            std::error_code EC;
            llvm::raw_fd_ostream OS(unit.getFileOption().output, EC, llvm::sys::fs::OF_None);
            ctx->module->print(OS, nullptr);
        }

        /// @brief 定义一个函数的具体实现，根据给定的函数定义语句创建LLVM函数
        Object* FuncDefinePs(const FuncDefineStmt *stmt) {
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
            Object *returnType = ctx->objectManager.getObject(stmt->return_type);

            auto args = stmt->args;
            BaseStmt *body = stmt->body;
            if(stmt->args == nullptr) {
                args = ctx->stmtManager.getDefineArgList({});
            }

            std::vector<llvm::Type *> argTypes;
            argTypes.reserve(args->args.size());
            for(const auto arg: args) {
                argTypes.push_back(ctx->objectManager.getObject(name));
            }

            if(!stmt->theClass.empty()) {
                const auto theClass = ctx->classManager.getClass(stmt->theClass);
                const auto theClassTy = theClass->type;
                const auto ptr_theClass = theClassTy->getPointerTo();
                argTypes.insert(argTypes.begin(), ptr_theClass);
                const auto thisArg = ctx->stmtManager.getDefineArg("this", theClassTy->getName().str(), ctx->stmtManager.getNoneStmt());
                args->args.insert(args->args.begin(), thisArg);
                ctx->classManager.pushNowClass(theClass);
            } else {
                ctx->classManager.pushNowClass(nullptr);
            }
            llvm::FunctionType *funcType = llvm::FunctionType::get(returnType, argTypes, false);
            llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, name, *ctx->module);
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
                        for(const auto &i: it->stmts) {
                            if(const auto t = dynamic_cast<VarDefineStmt *>(i)) {
                                t->isAlloca = true;
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

            // 配置函数传参
            if(args != nullptr) {
                const auto argNames = args->getArgsNames();
                int i = 0;
                auto it = func->arg_begin();
                if(!stmt->theClass.empty()) {
                    it->setName("this");
                    const auto theClass = ctx->classManager.getClass(stmt->theClass)->type;
                    Value *t = ctx->valueManager.getLLVMValue(it, theClass);
                    ctx->varManager.defineVar("this", false, t);
                    it++;
                    i++;
                }
                // 配置其他arg
                for(; it != func->arg_end(); ++it, ++i) {
                    it->setName(argNames[i]);
                    Value *t = ctx->valueManager.getLLVMValue(it, it->getType());
                    ctx->varManager.defineVar(argNames[i], false, t);
                }
            } else if(!stmt->theClass.empty()) {
                const auto it = func->arg_begin();
                it->setName("this");
                const auto theClass = ctx->classManager.getClass(stmt->theClass)->type;
                const auto t = ctx->valueManager.getLLVMValue(it, theClass);
                ctx->varManager.defineVar("this", false, t);
            }

            pre_varDefine(body);

            accept(body);
            if(returnType->isVoidTy()) {
                const auto t = ctx->stmtManager.getReturn();
                accept(t);
            }
            ctx->pop();
            parent.pop();
            ctx->classManager.popNowClass();

            const auto mod = stmt->modifier;
            return {func, mod};
        }

        /// @brief 用于解析变量定义的函数
        /// @param stmt 语句
        void VarDefinePs(VarDefineStmt *stmt) {
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

            if(stmt->isAlloca) {
                ctx->addVariable(Var(name, stmt->alloca, false));
                if(value != nullptr) {
                    ctx->llvmBuilder.CreateStore(value->toLLVM(), stmt->alloca->toLLVM());
                }
                return;
            }

            Value *var;
            // 对全局变量特判
            if(ctx->deep() <= 1) {
                if(value == nullptr) {
                    throw std::logic_error("VarDefinePs called with nullptr");
                }
                auto *CV = llvm::dyn_cast<llvm::Constant>(value->toLLVM());
                auto ptr = new llvm::GlobalVariable(*ctx->module, type, false,
                                                    llvm::GlobalVariable::LinkageTypes::ExternalLinkage, CV, name);
                var = ctx->valueManager.getLLVMValue(ptr, type);
            } else {
                // 实际上此处应该是被提前 Alloca 的时候运行的，不需要赋值，后续会被替换为 = 运算符
                auto ptr = ctx->llvmBuilder.CreateAlloca(type, nullptr, name);
                var = ctx->valueManager.getLLVMValue(ptr, type);
            }
            stmt->alloca = var;
        }

        // ReSharper disable once CppDFAConstantFunctionResult
        Value *ObjectPs(const ObjectStmt *stmt) const {
            const std::string name = stmt->name;
            // ReSharper disable once CppDFAUnreadVariable
            // ReSharper disable once CppDFAUnusedValue
            const auto ptr = ctx->varManager.getVar(name).var;
            const bool isLoaded = stmt->isLoaded;
            if(const auto var = llvm::dyn_cast<llvm::AllocaInst>(ptr->toLLVM()); var != nullptr) {
                Value *value = nullptr;
                if(isLoaded) {
                    llvm::Value *load = ctx->llvmBuilder.CreateLoad(var->getAllocatedType(), ptr->toLLVM());
                    value = ctx->valueManager.getLLVMValue(load, load->getType());
                } else {
                    value = ctx->valueManager.getLLVMValue(var, var->getAllocatedType());
                }
                return value;
            }

            return ptr;
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

        void ClassDefinePs(ClassDefineStmt *stmt) {
            const auto theClass = new Class();
            theClass->type = llvm::StructType::create(ctx->llvm_context, stmt->name);
            std::vector<llvm::Type *> types;
            size_t cnt = 0;
            // 构建继承
            if(!stmt->parentClass.empty()) {
                const auto parentClass = ctx->classManager.getClass(stmt->parentClass);
                std::vector<llvm::Type *> parentTypes;
                // 将父类的所有成员插入
                parentTypes.resize(parentClass->members.size());
                for(const auto &[name, index]: parentClass->members) {
                    llvm::Type *type = parentClass->type->getElementType(index);
                    parentTypes[index] = type;
                    theClass->members[name] = cnt;
                    cnt++;
                }
                types = parentTypes;
                // 继承方法
                for(auto i: parentClass->funcs) {
                    theClass->funcs.emplace(i);
                }
            }
            // 成员创建
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
                ++cnt;
            }
            theClass->type->setBody(types);
            ctx->classManager.createClass(theClass);

            // 方法创建
            for(const auto i: stmt->funcDefines) {
                std::string sourceName = i->func_name;
                i->func_name = stmt->name + "_" + i->func_name;
                i->theClass = stmt->name;

                const auto call = std::any_cast<Class::ClassFunc>(accept(i));
                theClass->funcs.emplace(sourceName, call);
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
            const auto funcName = stmt->call->name;
            // insert self
            const auto argList = stmt->call->args;
            argList->args.insert(argList->args.begin(), stmt->object);

            std::vector<llvm::Value *> args;
            for(const auto i: argList->args) {
                auto value = std::any_cast<Value *>(accept(i))->toLLVM();
                args.push_back(value);
            }
            const llvm::FunctionCallee call = ctx->classManager.getClassFunc(theClass, funcName).getFunc();
            llvm::Value *result_t = ctx->llvmBuilder.CreateCall(call, args);
            Value *result = ctx->valueManager.getLLVMValue(result_t, result_t->getType());
            return result;
        }

        Value *MemberExprPs(const MemberExprStmt *stmt) {
            const auto object = std::any_cast<Value *>(accept(stmt->parent));
            const auto type = object->getType();
            const auto theClass = ctx->classManager.getClassFromType(type);

            const std::string child = stmt->child->name;

            const size_t index = theClass->getMember(child);
            if(object->toLLVM()->getType()->isPointerTy()) {
                llvm::Value *ptr = ctx->llvmBuilder.CreateStructGEP(
                        theClass->type,
                        object->toLLVM(),
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
            }
            llvm::Value *ptr = ctx->llvmBuilder.CreateExtractValue(object->toLLVM(), index);
            return ctx->valueManager.getLLVMValue(ptr, type);
        }
    };
}// namespace Riddle