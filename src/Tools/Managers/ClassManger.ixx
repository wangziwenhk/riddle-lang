module;
#include <llvm/IR/IRBuilder.h>
export module Manager.ClassManager;
import Types.Class;
import Types.ClassNode;

export namespace Riddle {
    /// @brief 管理类
    class ClassManager {
        /// @brief 存储数据字段
        std::unordered_map<std::string, const ClassNode> Classes;

    public:
        ClassNode getClass(const std::string &name);

        // class 在进入该函数后则不可修改
        void createClass(const ClassNode &theClass);
    };
} // namespace Riddle