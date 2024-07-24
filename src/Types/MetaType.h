//
// Created by wangz on 24-7-23.
//

#ifndef RIDDLE_LANGUAGE_METATYPE_H
#define RIDDLE_LANGUAGE_METATYPE_H
#include <llvm/IR/Type.h>
namespace Riddle {

    /// @brief 用于模板类中的模板参数
    class MetaType {
        std::string typeName;
        std::string name;
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_METATYPE_H
