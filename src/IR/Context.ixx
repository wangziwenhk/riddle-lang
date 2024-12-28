module;
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <llvm/IR/IRBuilder.h>
#include <stack>
export module IR.Context;

import Type.Variable;
import managers.VarManager;
import managers.StmtManager;
import managers.ClassManager;
import managers.OpManager;
import managers.FuncManager;
import Tools.Allocator;
import ValueManager;
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
        FuncManager funcManager;
        ValueManager valueManager;
        Allocator allocator;
        llvm::IRBuilder<> llvmBuilder;

        explicit Context(llvm::LLVMContext &context): llvm_context(context), module("", context),
                                                      classManager(context), opManager(context),
                                                      valueManager(llvmBuilder, allocator), llvmBuilder(context) {}

        inline void addVariable(const Variable &var) {
            varManager.addVar(var);
        }

        inline void push() {
            varManager.push();
            funcManager.push();
            _deep++;
        }

        inline void pop() {
            if(_deep == 0) {
                throw std::runtime_error("Cannot pop from an empty context");
            }
            varManager.pop();
            funcManager.pop();
            _deep--;
        }

        inline unsigned long long deep() const {
            return _deep;
        }
    };
}// namespace Riddle