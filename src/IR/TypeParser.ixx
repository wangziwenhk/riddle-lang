module;
#include <llvm/IR/Type.h>
#include <llvm/IR/Instructions.h>
export module IR.TypeParser;

export namespace Riddle {
    llvm::Type *getSourceType(llvm::Value *value) {
        if(value->getType()->isPointerTy()) {
            if(const auto AP = llvm::dyn_cast<llvm::AllocaInst>(value)) {
                return AP->getAllocatedType();
            }
        }
        return value->getType();
    }
}// namespace Riddle