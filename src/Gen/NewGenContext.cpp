module;
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
module Gen.NewGenContext;
namespace Riddle {
    NewGenClassType *NewGenClassType::create(NewGenContext &ctx, llvm::StructType *sty) {
        const auto ptr = new NewGenClassType(ctx, sty);
        ctx.addGenObjectToAllocator(ptr);
        return ptr;
    }

    NewGenBaseType *NewGenBaseType::create(NewGenContext &ctx, llvm::Type *sty) {
        const auto ptr = new NewGenBaseType(ctx, sty);
        ctx.addGenObjectToAllocator(ptr);
        return ptr;
    }

    NewGenInteger *NewGenInteger::create(NewGenContext &ctx, const int value) {
        const auto ptr = new NewGenInteger(ctx, value);
        ctx.addGenObjectToAllocator(ptr);
        return ptr;
    }

    NewGenFloat *NewGenFloat::create(NewGenContext &ctx, const float value) {
        const auto ptr = new NewGenFloat(ctx, value);
        ctx.addGenObjectToAllocator(ptr);
        return ptr;
    }
    NewGenVariable *NewGenVariable::create(NewGenContext &ctx, VarDefineNode *define) {
        const auto ptr = new NewGenVariable(ctx, define);
        ctx.addGenObjectToAllocator(ptr);
        return ptr;
    }

    llvm::Value *NewGenInteger::getLLVMValue() {
        if (llvm_value == nullptr) {
            llvm_value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*context.llvmContext), value, true);
        }
        return llvm_value;
    }

    llvm::Value *NewGenFloat::getLLVMValue() {
        if (llvm_value == nullptr) {
            llvm_value = llvm::ConstantFP::get(llvm::Type::getFloatTy(*context.llvmContext), value);
        }
        return llvm_value;
    }


} // namespace Riddle
