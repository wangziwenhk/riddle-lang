#include "GenTools.h"
#include <llvm/IR/Constants.h>

namespace Riddle {
    llvm::AllocaInst *InitAlloca(std::string name, std::string type, llvm::IRBuilder<> &Builder) {
        llvm::AllocaInst *Alloca = nullptr;
        if(type == "int") {
            Alloca = Builder.CreateAlloca(Builder.getInt32Ty(), nullptr, name);
        } else if(type == "float") {
            Alloca = Builder.CreateAlloca(Builder.getDoubleTy(), nullptr, name);
        } else if(type == "char") {
            Alloca = Builder.CreateAlloca(Builder.getInt8Ty(), nullptr, name);
        } else if(type == "bool") {
            Alloca = Builder.CreateAlloca(Builder.getInt1Ty(), nullptr, name);
        }
        return Alloca;
    }
    bool isBooleanTy(llvm::Value *value) {
        llvm::Type *Ty = value->getType();
        if(Ty->isPointerTy()) {
            return Ty->getPointerTo()->isIntegerTy(1);
        } else {
            return Ty->isIntegerTy(1);
        }
    }

}// namespace Riddle