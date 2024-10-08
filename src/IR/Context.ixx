module;
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <stack>
#include <unordered_map>
#include <unordered_set>
export module IR.Context;

import Type.Variable;
import Manager.VarManager;

export namespace Riddle {
    class Context {
        int _deep = 0;

    public:
        llvm::LLVMContext &llvm_context;
        llvm::Module module;
        VarManager varManager;

        explicit Context(llvm::LLVMContext &context): llvm_context(context), module("", context) {}

        inline void addVariable(const Variable &var) {
            varManager.addVar(var);
        }

        inline void push() {
            varManager.push();
        }

        inline void pop() {
            varManager.pop();
        }

        inline unsigned long long deep() const {
            return _deep;
        }
    };
}