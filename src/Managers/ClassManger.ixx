module;
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <unordered_map>
#include <unordered_set>
export module Manager.ClassManager;
import Types.Class;
import Types.ClassNode;
export namespace Riddle {
    /// @brief 管理类
    class ClassManager {
        /// @brief 存储数据字段
        std::unordered_map<std::string, ClassNode> Classes;
        llvm::LLVMContext &Context;

    public:
        explicit ClassManager(llvm::LLVMContext &context): Context(context) {}

        /// @brief 查找相关的类
        ClassNode getClass(const std::string &name) {
            if(const auto it = Classes.find(name); it == Classes.end()) {
                throw std::logic_error("ClassManager:There is no such class");
            }
            return Classes.find(name)->second;
        }

        llvm::Type *getType(const std::string &name) {
            static const std::unordered_map<std::string, llvm::Type *> baseType = {
                    {"int", llvm::Type::getInt32Ty(Context)},
                    {"double", llvm::Type::getDoubleTy(Context)},
                    {"float", llvm::Type::getFloatTy(Context)},
                    {"bool", llvm::Type::getInt1Ty(Context)},
                    {"char", llvm::Type::getInt8Ty(Context)},
                    {"void", llvm::Type::getVoidTy(Context)},
            };

            if(baseType.contains(name)) {
                return baseType.find(name)->second;
            }
            return getClass(name).theClass->types;
        }

        // class 在进入该函数后则不可修改
        void createClass(const ClassNode &theClass) {
            Classes[theClass.get().types->getName().str()] = theClass;
        }
    };
} // namespace Riddle