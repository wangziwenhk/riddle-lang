module;
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <llvm/IR/IRBuilder.h>
#include <stack>
export module IR.Context;

import Type.Variable;
import Manager.VarManager;
import Manager.StmtManager;
import Manager.ClassManager;
import Manager.OpManager;
import Manager.FuncManager;
import Tools.Allocator;
import Manager.ValueManager;
export namespace Riddle {
    class Context {
        int _deep = 0;

    public:
        llvm::LLVMContext &llvm_context;
        std::unique_ptr<llvm::Module> module;
        VarManager varManager;
        ClassManager classManager;
        StmtManager stmtManager;
        OpManager opManager;
        FuncManager funcManager;
        ValueManager valueManager;
        llvm::IRBuilder<> llvmBuilder;

        explicit Context(llvm::LLVMContext &context): llvm_context(context), module(new llvm::Module("", context)),
                                                      classManager(context), opManager(context),
                                                      valueManager(llvmBuilder), llvmBuilder(context) {}

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