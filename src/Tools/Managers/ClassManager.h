//
// Created by wangz on 24-7-29.
//

#ifndef RIDDLE_LANGUAGE_CLASSMANAGER_H
#define RIDDLE_LANGUAGE_CLASSMANAGER_H
#include <llvm/IR/IRBuilder.h>

#include "Types/Class.h"

namespace Riddle {
    /// @brief 管理类
    class ClassManager {
        /// @brief 存储数据字段
        std::unordered_map<std::string, Class> Classes;
    public:
        Class getClass(const std::string &name);

        void createClass(Class theClass);
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_CLASSMANAGER_H
