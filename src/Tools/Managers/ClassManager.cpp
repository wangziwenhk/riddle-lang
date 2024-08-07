//
// Created by wangz on 24-7-29.
//

#include "ClassManager.h"

namespace Riddle {
    /// @brief 查找相关的类
    /// <p>
    /// a
    /// </p>
    Class ClassManager::getClass(const std::string &name) {
        const auto it = Classes.find(name);
        if (it == Classes.end()) {
            throw std::logic_error("没有这个类或者使用了不支持的路径");
        }
        return Classes.find(name)->second;
    }

    void ClassManager::createClass(Class theClass) {
        Classes[theClass.types->getName().str()] = theClass;
    }
}// namespace Riddle