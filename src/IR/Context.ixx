module;
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <format>
#include "llvm/IR/IRBuilder.h"
#include <memory>
#include <stack>
export module IR.Context;
import Manager.OpManager;
import Manager.SemManager;
export namespace Riddle {
    class Context {
        int _deep = 0;
        int classStackDepth = 0;

    public:
        llvm::LLVMContext *llvm_context;
        std::unique_ptr<llvm::Module> module;
        llvm::IRBuilder<> builder;
        SemManager semManager;
        OpManager opManager;
        bool isLinked = false;// 是否已经被链接，这对于析构函数十分重要


        explicit Context(llvm::LLVMContext *context): llvm_context(context),
                                                      module(new llvm::Module("", *context)),
                                                      builder(*context),
                                                      opManager(context) {}
        ~Context() = default;

        inline void push() {
            _deep++;
        }

        inline void pop() {
            if(_deep == 0) {
                throw std::runtime_error("Cannot pop from empty context");
            }
            _deep--;
        }

        inline unsigned long long deep() const {
            return _deep;
        }
    };
}// namespace Riddle
