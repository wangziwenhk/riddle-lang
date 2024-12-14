module;
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
export module managers.FuncManager;
export namespace Riddle {
    class FuncManager {
        std::unordered_map<std::string, std::stack<llvm::FunctionCallee>> funcCalls;
        std::stack<std::unordered_set<std::string>> defined;

    public:
        FuncManager() = default;
        ~FuncManager() = default;

        void registerFunction(const std::string &name, llvm::FunctionCallee func) {
            if(defined.top().contains(name)) {
                throw std::runtime_error("Function '" + name + "' already registered");
            }
            funcCalls[name].emplace(func);
            defined.top().emplace(name);
        }

        llvm::FunctionCallee getFunction(const std::string &name) {
            if(!funcCalls.contains(name)) {
                throw std::logic_error("Function \'"+name+"\' not found");
            }
            return funcCalls[name].top();
        }

        void push() {
            defined.emplace();
        }

        void pop() {
            for(const auto &i: defined.top()) {
                funcCalls[i].pop();
                if(funcCalls[i].empty()) {
                    funcCalls.erase(i);
                }
            }
            defined.pop();
        }
    };
}// namespace Riddle