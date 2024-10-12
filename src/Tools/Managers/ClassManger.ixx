module;
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include <stack>
#include <unordered_map>
#include <unordered_set>
export module Manager.ClassManager;
import Types.Class;
import Types.ClassNode;

export namespace Riddle {
    /// @brief 管理类
    class ClassManager {
        /// @brief 存储数据字段
        std::unordered_map<std::string, std::stack<ClassNode>> Classes;
        std::stack<std::unordered_set<std::string>>isDefined;
        llvm::LLVMContext &Context;

    public:
        explicit ClassManager(llvm::LLVMContext &context): Context(context) {}
        ClassNode getClass(const std::string &name);
        llvm::Type *getType(const std::string &name);
        // class 在进入该函数后则不可修改
        void createClass(const ClassNode &theClass);
        void push();
        void pop();

    };
} // namespace Riddle