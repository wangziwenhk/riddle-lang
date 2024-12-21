// ReSharper disable CppParameterMayBeConstPtrOrRef
module;
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include <unordered_map>
#include <unordered_set>
export module managers.ClassManager;
import Types.Class;
export namespace Riddle {
    /// @brief 管理类
    class ClassManager {
        /// @brief 存储数据字段
        std::unordered_map<std::string, Class *> Classes;
        std::unordered_map<llvm::Type*, Class*> ClassesByType;
        llvm::LLVMContext &Context;
        std::unordered_map<std::string, llvm::Type *> baseType;

    public:
        explicit ClassManager(llvm::LLVMContext &context): Context(context) {
            baseType = {
                    {"int", llvm::Type::getInt32Ty(Context)},
                    {"double", llvm::Type::getDoubleTy(Context)},
                    {"float", llvm::Type::getFloatTy(Context)},
                    {"bool", llvm::Type::getInt1Ty(Context)},
                    {"char", llvm::Type::getInt8Ty(Context)},
                    {"void", llvm::Type::getVoidTy(Context)},
            };
        }

        /// @brief 查找相关的类
        Class *getClass(const std::string &name) {
            if(const auto it = Classes.find(name); it == Classes.end()) {
                throw std::logic_error("ClassManager:There is no such class");
            }
            return Classes.find(name)->second;
        }

        llvm::Type *getType(const std::string &name) {
            if(baseType.contains(name)) {
                return baseType.find(name)->second;
            }
            return getClass(name)->types;
        }

        // class 在进入该函数后则不可修改
        void createClass(Class *theClass) {
            Classes[theClass->types->getName().str()] = theClass;
            ClassesByType[theClass->types] = theClass;
        }

        // 从 Struct 地址获得 Class
        Class *getClassFromType(llvm::Type *type) {
            if(!type->isStructTy()) {
                throw std::logic_error("ClassManager : There is no such class");
            }

            const auto it = ClassesByType.find(type);
            if(it == ClassesByType.end()) {
                throw std::logic_error("ClassManager : There is no such class");
            }
            return it->second;
        }
    };
} // namespace Riddle