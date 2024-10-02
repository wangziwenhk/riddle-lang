module;
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <stack>
#include <unordered_map>
#include <unordered_set>
export module IR.Context;

import Type.Variable;

namespace Riddle {
    class VarManager {
        std::unordered_map<std::string, std::stack<Variable *>> Vars;
        std::stack<std::unordered_set<std::string>> Defined = {};

    public:
        VarManager(): Vars({}) {}

        /// @brief 获取一个变量
        /// @param name 变量名
        /// @return 变量
        Variable &getVariable(const std::string &name);

        /// @brief 添加一个变量
        /// @param var 变量
        void addVariable(Variable &var);

        /// @brief 进入下一个生命周期
        void push();

        /// @brief 退出当前作用域
        void pop();
    };
}// namespace Riddle

export namespace Riddle {
    class Context {
        int _deep = 0;

    public:
        llvm::LLVMContext &context;
        llvm::Module module;
        VarManager varManager;

        explicit Context(llvm::LLVMContext &context): context(context), module("", context) {}

        inline void addVariable(Variable var) {
            varManager.addVariable(var);
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