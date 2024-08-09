//
// Created by wangz on 24-7-29.
//

#include "ClassManager.h"

namespace Riddle{
    /// @brief 查找相关的类
    ClassNode ClassManager::getClass(const std::string &name){
        if (const auto it = Classes.find(name);it == Classes.end()) {
            throw std::logic_error("没有这个类或者使用了不支持的路径");
        }
        return Classes.find(name)->second;
    }

    void ClassManager::createClass(const ClassNode &theClass){
        Classes.emplace(theClass.get().types->getName().str(),theClass);
    }
} // namespace Riddle
