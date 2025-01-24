module;
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <llvm/IR/IRBuilder.h>
#include <stack>
export module IR.Context;
import Manager.StmtManager;
import Manager.ClassManager;
import Manager.OpManager;
import Tools.Allocator;
import Manager.ValueManager;
export namespace Riddle {
    class Context {
        int _deep = 0;

    public:
        llvm::LLVMContext &llvm_context;
        std::unique_ptr<llvm::Module> module;
        ClassManager classManager;
        StmtManager stmtManager;
        OpManager opManager;
        ValueManager valueManager;
        llvm::IRBuilder<> llvmBuilder;

        explicit Context(llvm::LLVMContext &context): llvm_context(context), module(new llvm::Module("", context)),
                                                      classManager(context), opManager(context),
                                                      valueManager(llvmBuilder), llvmBuilder(context) {}

        inline void push() {
            _deep++;
        }

        inline void pop() {
            if(_deep == 0) {
                throw std::runtime_error("Cannot pop from an empty context");
            }
            _deep--;
        }

        inline unsigned long long deep() const {
            return _deep;
        }
    };
}// namespace Riddle