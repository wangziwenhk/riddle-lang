#ifndef RIDDLE_LANGUAGE_VARMANAGER_H
#define RIDDLE_LANGUAGE_VARMANAGER_H

#include "Types/Variable.h"
#include <stack>
#include <string>
#include <unordered_map>
namespace Riddle {
    class VarManager {
    private://成员区
        std::unordered_map<std::string, std::stack<Variable>> NamedVar;
        std::stack<std::unordered_map<std::string, bool>> Defined;

    private:
        bool isDefined(std::string name);

    public://函数区
        VarManager() = default;
        /// @brief 进入下一个作用域
        void push();
        /// @brief 退出作用域
        void pop();
        /// @brief 定义一个新的变量
        /// @param name 变量名
        /// @param type 类型，当类型为 null 时说明在下一次赋值时判断，在被引用之前必须有类型
        /// @param isConst 是否不变
        void defineVar(const std::string &name, const bool &isConst, llvm::AllocaInst *value = nullptr, const std::string &type = "null");
        /// @brief 获取一个变量的属性
        /// @param name 变量名
        /// @returns 变量的属性
        Variable getVar(const std::string &name);
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_VARMANAGER_H
