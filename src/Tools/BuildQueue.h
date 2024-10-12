#ifndef RIDDLE_LANGUAGE_BUILDQUEUE_H
#define RIDDLE_LANGUAGE_BUILDQUEUE_H

#include <llvm/IR/Module.h>
import Types.Unit;

namespace Riddle {
    /// @brief 用于随时调整编译队列
    class BuildQueue {
    private:
        /// @brief 用于构建各个库之间的导入关系
        /// @brief 这里使用包名判断库之间的关系
        std::unordered_map<std::string, std::vector<std::string>> libGraph;
        /// @brief 用于将不同包之间的库链接起来，本质上就是处理后拼接
        std::unordered_map<std::string, std::vector<Unit>> libSource;

    public:
        /// @brief 用于解析某个源文件
        void parserFile(const std::string &filePath);
        void push(const Unit &unit);
        void start();
    };
    static BuildQueue buildQueue;

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_BUILDQUEUE_H
