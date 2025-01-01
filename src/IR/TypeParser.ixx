module;
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Type.h>
export module IR.TypeParser;

export namespace Riddle {
    llvm::Type *getSourceType(llvm::Value *value) {
        if(value->getType()->isPointerTy()) {
            if(const auto AI = llvm::dyn_cast<llvm::AllocaInst>(value)) {
                return AI->getAllocatedType();  
            }
            if(const auto GV = llvm::dyn_cast<llvm::GlobalVariable>(value)) {
                return GV->getValueType();
            }
            if(const auto *SI = llvm::dyn_cast<llvm::StoreInst>(value)) {
                return SI->getValueOperand()->getType();
            }
        }
        return value->getType();
    }
}// namespace Riddle