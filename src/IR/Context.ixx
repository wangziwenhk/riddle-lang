module;
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <stack>
#include <unordered_map>
#include <unordered_set>
export module IR.Context;

import Type.Variable;
import Manager.VarManager;
import Managers.StmtManager;
import Manager.ClassManager;
export namespace Riddle {
    class Context {
        int _deep = 0;

    public:
        llvm::LLVMContext &llvm_context;
        llvm::Module module;
        VarManager varManager;
        ClassManager classManager;
        StmtManager stmtManager;

        explicit Context(llvm::LLVMContext &context): llvm_context(context), module("", context), classManager(context) {}

        inline void addVariable(const Variable &var) {
            varManager.addVar(var);
        }

        inline void push() {
            varManager.push();
            classManager.push();
            _deep++;
        }

        inline void pop() {
            varManager.pop();
            classManager.pop();
            _deep--;
        }

        inline unsigned long long deep() const {
            return _deep;
        }

        inline StmtManager &getStmtManager() {
            return stmtManager;
        }
    };
}// namespace Riddle