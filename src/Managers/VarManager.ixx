module;
#include <llvm/IR/Value.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <ranges>
export module Manager.VarManager;

import Type.Variable;

export namespace Riddle {
    class VarManager {
        //成员区
        std::unordered_map<std::string, std::stack<Variable>> NamedVar;
        std::stack<std::unordered_map<std::string, bool>> Defined;

        bool isDefined(const std::string &name) {
            const auto it = NamedVar.find(name);
            if(it == NamedVar.end()) return false;
            if(it->second.empty()) return false;
            return true;
        }

    public://函数区
        VarManager() = default;
        /// @brief 进入下一个作用域
        void push() {
            Defined.emplace();
        }
        /// @brief 退出作用域
        void pop() {
            for(const auto &name: Defined.top() | std::views::keys) {
                NamedVar[name].pop();
                if(NamedVar[name].empty()) {
                    NamedVar.erase(name);
                }
            }
            Defined.pop();
        }
        /// @brief 定义一个新的变量
        /// @param name 变量名
        /// @param isConst 是否不变
        /// @param value 指某个局部变量的地址
        void defineVar(const std::string &name, const bool &isConst, llvm::Value *value = nullptr) {
            if(Defined.top().contains(name)) {
                throw std::logic_error("The variable has been defined multiple times");
            }
            NamedVar[name].emplace(name, value, isConst);
            Defined.top()[name] = true;
        }
        void addVar(const Variable &var) {
            NamedVar[var.name].push(var);
            Defined.top()[var.name] = true;
        }
        /// @brief 获取一个变量的属性
        /// @param name 变量名
        /// @returns 变量的属性
        Variable getVar(const std::string &name) {
            return NamedVar[name].top();
        }
        /// @brief 获取当前是否为全局
        /// @returns 是否为全局
        [[nodiscard]] bool isGlobal() const {
            return Defined.size() == 1;
        }
    };

}// namespace Riddle