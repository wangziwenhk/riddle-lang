//
// Created by wangz on 24-7-29.
//

#ifndef RIDDLE_LANGUAGE_CLASSMANAGER_H
#define RIDDLE_LANGUAGE_CLASSMANAGER_H
#include <llvm/IR/IRBuilder.h>

import Types.Class;
import Types.ClassNode;

namespace Riddle{
    /// @brief 管理类
    class ClassManager{
        /// @brief 存储数据字段
        std::unordered_map<std::string,const ClassNode> Classes;

    public:
        ClassNode getClass(const std::string &name);

        // class 在进入该函数后则不可修改
        void createClass(const ClassNode &theClass);
    };
} // namespace Riddle

#endif//RIDDLE_LANGUAGE_CLASSMANAGER_H
