module;
#include <llvm/IR/IRBuilder.h>
export module IR.Builder;

import IR.Context;

export namespace Riddle {
    class Builder {
        Context *ctx = nullptr;
        llvm::IRBuilder<> llvmBuilder;

    public:
        explicit Builder(Context &context): ctx(&context), llvmBuilder(ctx->context) {}

        // constant

        /// @brief 获取不同位数的整数类型
        /// @param bits 整数类型的位数
        /// @return llvm:IntegerTy
        inline llvm::IntegerType *getIntegerTy(const unsigned bits = 32) const {
            return llvm::Type::getIntNTy(ctx->context, bits);
        }

        /// @brief 获取单浮点类型
        inline llvm::Type *getFloatTy() const {
            return llvm::Type::getFloatTy(ctx->context);
        }

        /// @brief 获取双浮点类型
        inline llvm::Type *getDoubleTy() const {
            return llvm::Type::getDoubleTy(ctx->context);
        }

        /// @brief 获取空类型
        inline llvm::Type *getVoidTy() const {
            return llvm::Type::getVoidTy(ctx->context);
        }

        /// @brief 获取布尔类型
        inline llvm::Type *getBoolTy() const {
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
        inline llvm::Constant* getIntN(const unsigned long long bits,const long long int) {
            return llvmBuilder.getIntN(bits,bits);
        }

        /// @brief 创建一个变量
        /// @param type 变量类型
        /// @param value 变量初始值
        /// @param name 变量名称
        /// @param is_const 是否不可变
        /// @return 变量
        llvm::Value *createVariable(llvm::Type *type, llvm::Value *value, const std::string &name = "", bool is_const = false);


    };
}// namespace Riddle