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

        /// @brief 获取不同位数的整数类型
        /// @param bits 整数类型的位数
        /// @return llvm:IntegerTy
        inline llvm::Type *getIntegerTy(const unsigned bits = 32) const {
            return llvm::Type::getIntNTy(ctx->context, bits);
        }

        inline llvm::Type *getFloatTy() const {
            return llvm::Type::getFloatTy(ctx->context);
        }

        inline llvm::Type *getDoubleTy() const {
            return llvm::Type::getDoubleTy(ctx->context);
        }

        inline llvm::Type *getVoidTy() const {
            return llvm::Type::getVoidTy(ctx->context);
        }

        inline llvm::Type *getBoolTy() const {
            return getIntegerTy(1);
        }

        llvm::Value *CreateVariable(llvm::Type *type, llvm::Value *value, const std::string &name = "", bool is_const = false);


    };
}// namespace Riddle