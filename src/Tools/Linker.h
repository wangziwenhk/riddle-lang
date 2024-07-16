#ifndef RIDDLE_LANGUAGE_LINKER_H
#define RIDDLE_LANGUAGE_LINKER_H

#include <algorithm>
#include <string>
#include <vector>

namespace Riddle {
    /// @brief 用于寻找库的全局工具
    class Linker {
    private:
        /// @brief 从当前路径寻找库
        /// @param libPackName 需要寻找的库的包名
        /// @param sourcePath 主动导入该库的源文件的绝对路径
        /// @return 返回库源文件的绝对路径
        std::string findSourceLib(const std::string &libPackName, const std::string &sourcePath);
    public:
        Linker();
        /// @brief 从多个路径寻找库
        /// @param libPackName 需要寻找的库的包名
        /// @param sourcePath 主动导入该库的源文件的绝对路径
        /// @param packName 源文件的包名
        /// @return 返回库源文件的绝对路径
        std::string findLib(const std::string &libPackName, const std::string &sourcePath);
    };
    static Linker linker;
}// namespace Riddle


#endif//RIDDLE_LANGUAGE_LINKER_H
