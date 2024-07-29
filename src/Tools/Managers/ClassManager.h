//
// Created by wangz on 24-7-29.
//

#ifndef RIDDLE_LANGUAGE_CLASSMANAGER_H
#define RIDDLE_LANGUAGE_CLASSMANAGER_H
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>
namespace Riddle {
    /// @brief 管理类
    class ClassManager {
        /// @brief 存储数据字段
        llvm::StructType *data;
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_CLASSMANAGER_H
