//
// Created by wangz on 24-7-17.
//

#ifndef RIDDLE_LANGUAGE_VARMANAGER_H
#define RIDDLE_LANGUAGE_VARMANAGER_H

#include <stack>
#include <string>
#include <unordered_map>
namespace Riddle {

    class VarManager {
    public:
        /// @brief 存储某个变量基本信息的类
        class variable{
        public:
            const std::string name;
            const std::string type;
            const bool isConst;
            variable() = delete;
            variable(const std::string name,const std::string type):name(name),type(type),isConst(false){};
            variable(const std::string name,const std::string type,bool isConst):name(name),type(type),isConst(isConst){};
        };
    private:
        std::unordered_map<std::string,std::stack<variable>>NamedVar;
        std::stack<std::unordered_map<std::string,bool>>isDefined;
    public:
        VarManager() = default;
        /// @brief 进入下一个作用域
        void push();
        /// @brief 退出作用域
        void pop();
        /// @brief 定义一个新的变量
        /// @param name 变量名
        /// @param type 类型，当类型为 null 时说明在下一次赋值时判断，在被引用之前必须有类型
        /// @param isConst 是否不变
        void DefineVar(std::string name,bool isConst,std::string type="null");
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_VARMANAGER_H
