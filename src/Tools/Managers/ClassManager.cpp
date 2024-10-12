module;
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Type.h>
#include <stdexcept>
#include <unordered_map>
module Manager.ClassManager;

namespace Riddle {
    /// @brief 查找相关的类
    ClassNode ClassManager::getClass(const std::string &name) {
        if(isDefined.top().contains(name)) {
            throw std::logic_error("ClassManager:Duplicate definition");
        }
        if(const auto it = Classes.find(name); it == Classes.end()) {
            throw std::logic_error("ClassManager:There is no such class");
        }
        return Classes.find(name)->second.top();
    }
    llvm::Type *ClassManager::getType(const std::string &name) {
        const std::unordered_map<std::string, llvm::Type *> baseType = {
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
        Classes[theClass.get().types->getName().str()].push(theClass);
    }
    void ClassManager::push() {
        isDefined.emplace();
    }
    void ClassManager::pop() {
        for(const auto &i: isDefined.top()) {
            Classes[i].pop();
            if(Classes[i].empty()) {
                Classes.erase(i);
            }
        }
        isDefined.pop();
    }
}// namespace Riddle
