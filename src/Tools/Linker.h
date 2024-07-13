#ifndef RIDDLE_LANGUAGE_LINKER_H
#define RIDDLE_LANGUAGE_LINKER_H

#include <string>
#include <vector>
namespace Riddle{
    /// \brief 用于寻找库的全局工具
    class Linker{
    private:
        /// \brief 防止多重定义导致的 Bug
        static bool isDef;
        static std::vector<std::string> SystemLibPaths;
    public:
        Linker();
        /// \brief 依次从（当前路径，显式指定的路径和系统默认的库路径）寻找库
        /// \param libName 需要寻找的库的包名
        /// \param sourcePath 主动导入该库的源文件的绝对路径
        /// \return 返回库源文件的绝对路径
        static std::string findLib(const std::string& libName,const std::string&sourcePath);
    };
    static Linker linker;
}



#endif //RIDDLE_LANGUAGE_LINKER_H
