module;
#include <llvm/IR/LLVMContext.h>
export module Config.LLVMConfig;
export namespace Riddle {
    llvm::LLVMContext globalContext;
}
