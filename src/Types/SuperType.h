//
// Created by wangz on 24-7-23.
//

#ifndef RIDDLE_LANGUAGE_SUPERTYPE_H
#define RIDDLE_LANGUAGE_SUPERTYPE_H

#include "Types/MetaType.h"
#include <llvm/IR/Type.h>
namespace Riddle {
    /// @brief 用于替代 llvm::Type
    class SuperType {
    public:
        llvm::Type *type = nullptr;
        std::string typeName;
        bool isTemplate;
        std::vector<MetaType> templateArgs;

    public:
        SuperType(llvm::Type *type,
                  std::string typeName,
                  bool isTemplate = false,
                  std::vector<MetaType> templateArgs = {}): type(type), typeName(typeName), isTemplate(isTemplate), templateArgs(templateArgs){};
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_SUPERTYPE_H
