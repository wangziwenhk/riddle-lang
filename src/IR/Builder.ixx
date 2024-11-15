module;
#include <llvm/IR/IRBuilder.h>
#include <stack>
export module IR.Builder;

import IR.Context;
import Type.Variable;
import Type.DefineArg;
import Manager.VarManager;
import Manager.StmtManager;
import Manager.OpManager;
import Manager.ClassManager;
export namespace Riddle {
    class Builder {
        Context *ctx = nullptr;
        llvm::IRBuilder<> llvmBuilder;
        std::stack<llvm::Function *> functions;

    public:
        explicit Builder(Context &context): ctx(&context), llvmBuilder(ctx->llvm_context) {}

        [[nodiscard]] Context &getContext() const { return *ctx; }
        // constant

        /// @brief 获取不同位数的整数类型
        /// @param bits 整数类型的位数
        /// @return llvm:IntegerTy
        [[nodiscard]] inline llvm::IntegerType *getIntegerTy(const unsigned bits = 32) const {
            return llvm::Type::getIntNTy(ctx->llvm_context, bits);
        }

        /// @brief 获取单浮点类型
        [[nodiscard]] inline llvm::Type *getFloatTy() const {
            return llvm::Type::getFloatTy(ctx->llvm_context);
        }

        /// @brief 获取双浮点类型
        [[nodiscard]] inline llvm::Type *getDoubleTy() const {
            return llvm::Type::getDoubleTy(ctx->llvm_context);
        }

        /// @brief 获取空类型
        [[nodiscard]] inline llvm::Type *getVoidTy() const {
            return llvm::Type::getVoidTy(ctx->llvm_context);
        }

        /// @brief 获取布尔类型
        [[nodiscard]] inline llvm::Type *getBoolTy() const {
            return getIntegerTy(1);
        }

        /// @brief 将 int 类型 转化为 llvm::Constant 类型
        inline llvm::Constant *getInt32(const unsigned int &value) {
            return llvmBuilder.getInt32(value);
        }

        /// @brief 将 long long int 类型 转化为 llvm::Constant 类型
        inline llvm::Constant *getInt64(const unsigned long long &value) {
            return llvmBuilder.getInt64(value);
        }

        /// @brief 将 int N 类型 转化为 llvm::Constant 类型
        inline llvm::Constant *getIntN(const unsigned long long bits, const long long int) {
            return llvmBuilder.getIntN(bits, bits);
        }

        [[nodiscard]] inline llvm::Constant *getDouble(const double &value) const {
            return llvm::ConstantFP::get(llvm::Type::getDoubleTy(ctx->llvm_context), value);
        }

        /// @brief 创建一个变量
        /// @param type 变量类型
        /// @param value 变量初始值
        /// @param name 变量名称
        /// @param is_const 是否不可变
        /// @return 变量
        llvm::Value *createVariable(llvm::Type *type, llvm::Value *value, const std::string &name = "", const bool is_const = false) {
            llvm::Value *var;
            // 对全局变量特判
            if(ctx->deep() <= 1) {
                auto *CV = llvm::dyn_cast<llvm::Constant>(value);
                var = new llvm::GlobalVariable(ctx->module, type, is_const, llvm::GlobalVariable::LinkageTypes::ExternalLinkage, CV, name);
            } else {

                var = llvmBuilder.CreateAlloca(type, nullptr, name);
                if(value != nullptr) llvmBuilder.CreateStore(value, var);
            }
            ctx->addVariable(Variable(name, var, is_const));
            return var;
        }


        /// @brief 仅作为创建函数
        std::tuple<llvm::FunctionType *, llvm::Function *> createFuncDefine(const std::string &funcName, llvm::Type *return_type, const std::vector<llvm::Type *> &args) const {
            llvm::FunctionType *funcType = llvm::FunctionType::get(return_type, args, false);
            llvm::Function *func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, funcName, ctx->module);
            return {funcType, func};
        }

        void pushParent(llvm::Function *func) {
            functions.push(func);
        }

        void popParent() {
            functions.pop();
        }

        llvm::Function *getParent() {
            return functions.top();
        }

        void setNowBlock(llvm::BasicBlock *block) {
            llvmBuilder.SetInsertPoint(block);
        }

        void createJump(llvm::BasicBlock *block) {
            llvmBuilder.CreateBr(block);
        }

        void createCondJump(llvm::Value *cond, llvm::BasicBlock *True, llvm::BasicBlock *False) {
            llvmBuilder.CreateCondBr(cond, True, False);
        }

        [[nodiscard]] llvm::BasicBlock *getNowBlock() const {
            return llvmBuilder.GetInsertBlock();
        }

        llvm::BasicBlock *createBasicBlock(const std::string &label, llvm::Function *func) const {
            llvm::BasicBlock *block = llvm::BasicBlock::Create(ctx->llvm_context, label, func);
            return block;
        }

        llvm::Value *createReturn(llvm::Value *value = nullptr) {
            if(value == nullptr) {
                return llvmBuilder.CreateRetVoid();
            }
            return llvmBuilder.CreateRet(value);
        }

        void printCode() const {
            ctx->module.print(llvm::outs(), nullptr);
        }

        inline void push() const {
            ctx->push();
        }
        inline void pop() const {
            ctx->pop();
        }

        [[nodiscard]] inline Variable getVar(const std::string &name) const {
            return ctx->varManager.getVar(name);
        }

        [[nodiscard]] inline llvm::Value *getBool(const bool value) {
            return llvmBuilder.getInt1(value);
        }

        inline StmtManager &getStmtManager() const {
            return ctx->stmtManager;
        }

        inline VarManager &getVarManager() const {
            return ctx->varManager;
        }

        inline ClassManager &getClassManager() const {
            return ctx->classManager;
        }

        inline OpManager &getOpManager() const {
            return ctx->opManager;
        }

        inline llvm::IRBuilder<> &getLLVMBuilder(){
            return llvmBuilder;
        }
    };
}// namespace Riddle