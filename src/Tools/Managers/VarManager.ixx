module;
#include <llvm/IR/Value.h>
#include <stack>
#include <string>
#include <unordered_map>
export module Manager.VarManager;

import Type.Variable;

export namespace Riddle {
    class VarManager {
        //成员区
        std::unordered_map<std::string, std::stack<Variable>> NamedVar;
        std::stack<std::unordered_map<std::string, bool>> Defined;

        bool isDefined(const std::string &name);

    public://函数区
        VarManager() = default;
        /// @brief 进入下一个作用域
        void push();
        /// @brief 退出作用域
        void pop();
        /// @brief 定义一个新的变量
        /// @param name 变量名
        /// @param isConst 是否不变
        /// @param value 指某个局部变量的地址
        void defineVar(const std::string &name, const bool &isConst, llvm::Value *value = nullptr);
        /// @brief 获取一个变量的属性
        /// @param name 变量名
        /// @returns 变量的属性
        Variable getVar(const std::string &name);
        /// @brief 获取当前是否为全局
        /// @returns 是否为全局
        [[nodiscard]] bool isGlobal()const;
    };

}// namespace Riddle