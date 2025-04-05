module;
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
module Gen.NewGenContext;
namespace Riddle {
    NewGenClassType *NewGenClassType::create(NewGenContext &ctx, llvm::StructType *sty) {
        const auto ptr = new NewGenClassType(ctx, sty);
        ctx.addGenObject(ptr);
        return ptr;
    }
    NewGenBaseType *NewGenBaseType::create(NewGenContext &ctx, llvm::Type *sty) {
        const auto ptr = new NewGenBaseType(ctx, sty);
        ctx.addGenObject(ptr);
        return ptr;
    }
    NewGenInteger *NewGenInteger::create(NewGenContext &ctx, const int value) {
        const auto ptr = new NewGenInteger(ctx, value);
        ctx.addGenObject(ptr);
        return ptr;
    }
    llvm::Value *NewGenInteger::getLLVMValue() {
        if (llvm_value == nullptr) {
            llvm_value = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*context.llvmContext), value, true);
        }
        return llvm_value;
    }

} // namespace Riddle
