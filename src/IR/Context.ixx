module;
#include "llvm/IR/LLVMContext.h"

#include <stack>
#include <unordered_map>
#include <unordered_set>
export module Context;

import Type.Variable;
import Types.UnionFind;

namespace Riddle {
    class VarManager {
        std::unordered_map<std::string, std::stack<Variable *>> Vars;
        std::stack<std::unordered_set<std::string>> Defined;

    public:
        VarManager(): Vars({}), Defined({}) {}

        /// @brief 获取一个变量
        Variable &getVariable(const std::string &name) {
            if(!Vars.contains(name) || Vars.find(name)->second.empty()) {
                throw std::out_of_range("Variable not found");
            }
            return *Vars[name].top();
        }

        void addVariable(Variable &var) {
            if(Defined.top().contains(var.name)) {
                throw std::logic_error("Variable already exists");
            }
            Defined.top().insert(var.name);
            Vars[var.name].push(&var);
        }

        void push() {
            Defined.emplace();
        }

        void pop() {
            for(auto i: Defined.top()) {
                Vars[i].pop();
                if(Vars[i].empty()) {
                    Vars.erase(i);
                }
            }
            Defined.pop();
        }
    };
}// namespace Riddle
export namespace Riddle {
    class Context {
    public:
        llvm::LLVMContext &context;
        VarManager varManager;

        explicit Context(llvm::LLVMContext &context): context(context) {}

        void addVar(Variable var) {
            varManager.addVariable(var);
        }
    };
}