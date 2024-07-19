#include "GenTools.h"
#include <llvm/IR/Constants.h>

namespace Riddle{
    std::string getValueStr(llvm::Value *value) {
        if(auto *CI= llvm::dyn_cast<llvm::ConstantInt>(value)) {
            llvm::APInt intValue= CI->getValue();
            int intVal= intValue.getSExtValue();
            return std::to_string(intVal);
        } else if(auto *CFP= llvm::dyn_cast<llvm::ConstantFP>(value)) {
            llvm::APFloat floatValue= CFP->getValueAPF();
            double floatVal= floatValue.convertToDouble();
            return std::to_string(floatVal);
        } else if(auto *CDS= llvm::dyn_cast<llvm::ConstantDataArray>(value)) {
            if(CDS->getElementType()->isIntegerTy(8)) {
                std::string strValue= CDS->getAsCString().str();
                return strValue;
            } else {
                throw std::logic_error("This thing cannot be implicitly converted to a string");
            }
        }
        throw std::logic_error("This thing cannot be implicitly converted to a string");
    }

    llvm::AllocaInst *InitAlloca(std::string name, std::string type, llvm::IRBuilder<> &Builder, llvm::LLVMContext &Context) {
        llvm::AllocaInst *Alloca= nullptr;
        if(type == "int") {
            Alloca= Builder.CreateAlloca(llvm::Type::getInt32Ty(Context), nullptr, name);
        } else if(type == "float") {
            Alloca= Builder.CreateAlloca(llvm::Type::getDoubleTy(Context), nullptr, name);
        }
        return Alloca;
    }

}