module;
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <memory>
export module NewGenContext;

export namespace Riddle {
    class NewGenContext {
    public:
        std::unique_ptr<llvm::Module> module;
        llvm::IRBuilder<> builder;
    };
} // namespace Riddle
