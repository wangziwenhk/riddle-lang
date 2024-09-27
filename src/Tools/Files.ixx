module;
#include <string>
#include <vector>
export module Tools.Files;
export namespace Riddle {
    class Files {
        //我们应该增加一个缓存吗
    public:
        /// @brief 递归获取某个路径下的所有文件
        /// @param path 路径
        /// @return 递归路径下的所有文件
        static std::vector<std::string> getTreeFile(const std::string &path);
        /// @brief 递归获取某个路经下的所有源文件
        /// @param path 路径
        /// @return 递归路径下的所有源文件
        static std::vector<std::string> getTreeSource(const std::string &path);
        /// @brief 获取某个路径下的所有文件
        /// @param path 路径
        /// @return 路径下的所有文件
        static std::vector<std::string> getFiles(const std::string &path);
        /// @brief 获取某个路径下的所有源文件
        /// @param path 路径
        /// @return 路径下的所有源文件
        static std::vector<std::string> getSources(const std::string &path);
        /// @brief 读取某个文件中的所有内容
        /// @param path 文件路径
        /// @return 文件内容
        static std::vector<std::string> getFileTextLine(const std::string &path);
        /// @brief 获取某个文件的第一行
        /// @param path 文件路径
        /// @return 文件第一行
        static std::string getFileFirstLine(const std::string &path);
        /// @brief 检查某个文件是否为空
        /// @param path 文件路径
        /// @return 文件是否为空
        static bool isFileEmpty(const std::string &path);
        /// @brief 获取文件名称，也就是去除路径
        /// @param path 文件路径
        /// @return 文件名称
        static std::string getFileName(const std::string &path);
    };
}// namespace Riddle