module;
#include "llvm/IR/Module.h"
export module Builder;
export namespace Riddle {
    class Builder {
    public:
        llvm::Module &module;
        llvm::LLVMContext &context;

        explicit Builder(llvm::Module &module): module(module), context(module.getContext()) {}

        
    };
}// namespace Riddle