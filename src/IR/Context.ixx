module;
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <stack>
export module IR.Context;

import Type.Variable;
import Manager.VarManager;
import Manager.StmtManager;
import Manager.ClassManager;
import Manager.OpManager;
export namespace Riddle {
    class Context {
        int _deep = 0;

    public:
        llvm::LLVMContext &llvm_context;
        llvm::Module module;
        VarManager varManager;
        ClassManager classManager;
        StmtManager stmtManager;
        OpManager opManager;

        explicit Context(llvm::LLVMContext &context): llvm_context(context), module("", context), classManager(context), opManager(context) {}

        inline void addVariable(const Variable &var) {
            varManager.addVar(var);
        }

        inline void push() {
            varManager.push();
            _deep++;
        }

        inline void pop() {
            if(_deep == 0) {
                throw std::runtime_error("Cannot pop from an empty context");
            }
            varManager.pop();
            _deep--;
        }

        inline unsigned long long deep() const {
            return _deep;
        }
    };
}// namespace Riddle