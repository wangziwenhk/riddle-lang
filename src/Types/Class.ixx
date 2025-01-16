module;
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <map>
export module Types.Class;
import Type.Modifier;
export namespace Riddle {
    class Class {
    public:
        class ClassFunc {
        public:
            llvm::FunctionCallee *func;
            Modifier modifier;
            ClassFunc(llvm::FunctionCallee *func, const Modifier modifier): func(func), modifier(modifier) {}

            [[nodiscard]] llvm::FunctionCallee *getFunc() const {
                return func;
            }

            [[nodiscard]] Modifier getModifier() const {
                return modifier;
            }
        };

        /// 类中包含的结构体
        llvm::StructType *type = nullptr;
        /// 成员
        std::unordered_map<std::string, size_t> members;
        /// 方法
        std::unordered_map<std::string, ClassFunc> funcs;
        /// 父类
        std::vector<Class *> parentClasses;

        /// @brief 安全的获取一个成员
        /// @param name 成员名称
        /// @return 成员在结构体中的偏移量
        size_t getMember(const std::string &name) {
            const auto it = members.find(name);
            if(it == members.end()) {
                throw std::invalid_argument("No such member");
            }
            return it->second;
        }

        /// @brief 安全的获取一个函数
        /// @param name 函数名称
        /// @return 函数调用实体
        ClassFunc getFunction(const std::string &name) {
            const auto it = funcs.find(name);
            if(it == funcs.end()) {
                throw std::invalid_argument("No such function");
            }
            return it->second;
        }

        /// @brief 安全的添加一个函数
        void addFunction(const ClassFunc &func) {
            const std::string name = func.func->getCallee()->getName().str();
            if(funcs.contains(name)) {
                throw std::invalid_argument("Function already exists");
            }
            funcs[name] = func;
        }
    };

}// namespace Riddle