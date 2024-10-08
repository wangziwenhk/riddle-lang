module;
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Type.h>
#include <stdexcept>
#include <unordered_map>
module Manager.ClassManager;

namespace Riddle {
    /// @brief 查找相关的类
    ClassNode ClassManager::getClass(const std::string &name) {
        if(const auto it = Classes.find(name); it == Classes.end()) {
            throw std::logic_error("没有这个类或者使用了不支持的路径");
        }
        return Classes.find(name)->second;
    }
    llvm::Type *ClassManager::getType(const std::string &name) {
        std::unordered_map<std::string, llvm::Type *> baseType = {
                {"int", llvm::Type::getInt32Ty(Context)},
                {"double", llvm::Type::getDoubleTy(Context)},
                {"float", llvm::Type::getFloatTy(Context)},
                {"bool", llvm::Type::getInt1Ty(Context)},
                {"char", llvm::Type::getInt8Ty(Context)}};
        if(baseType.contains(name)) {
            return baseType.find(name)->second;
        }
        return getClass(name).theClass->types;
    }

    void ClassManager::createClass(const ClassNode &theClass) {
        Classes.emplace(theClass.get().types->getName().str(), theClass);
    }
} // namespace Riddle
