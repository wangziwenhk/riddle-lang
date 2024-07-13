#ifndef RIDDLE_LANGUAGE_FILES_H
#define RIDDLE_LANGUAGE_FILES_H

#include <string>
#include <vector>
namespace Riddle {
    class Files {
        //我们应该增加一个缓存吗
    public:
        /// \brief 获取某个路径下的所有目录下的所有文件
        /// \param path 路径
        /// \return 路径下的所有文件
        static std::vector<std::string> getTreeFile(const std::string& path);
        /// \brief 获取某个路经下的所有源文件
        /// \param path 路径
        /// \return 路径下的所有源文件
        static std::vector<std::string> getTreeSource(const std::string& path);
        static std::vector<std::string> getFileTextLine(const std::string& path);
        static std::string getFileFirstLine(const std::string& path);
        static bool isFileEmpty(const std::string& path);
    };
}// namespace Riddle

#endif//RIDDLE_LANGUAGE_FILES_H
