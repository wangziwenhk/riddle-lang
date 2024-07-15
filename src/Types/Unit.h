#ifndef RIDDLE_LANGUAGE_UNIT_H
#define RIDDLE_LANGUAGE_UNIT_H

#include <string>
#include <vector>

namespace Riddle {
    typedef std::string Path;
    class Unit {
    private:
        /// @brief 当前单元的包名
        std::string packName;
        /// @brief 导入的库，内容为包名
        std::vector<std::string> imports;
        /// @brief 文件的目录，用于查找相对于的包
        Path directoryPath;
        /// @brief 文件的完整路径
        Path filePath;

    public:
        Unit()= default;
        explicit Unit(const Path &selfPath);
        /// @brief 设置包名，通过 PackageVisitor 获取
        inline void setPackName(Path name);
        /// @brief 获取包名
        inline Path getPackName()const;
        /// @brief 设置编译单元目录的路径
        inline void setDirectoryPath(Path path);
        /// @brief 获取编译单元目录的路径
        inline Path getDirectoryPath() const;
        /// @brief 设置源文件的完整路径
        inline void setFilePath(Path path);
        /// @brief 获取源文件的完整路径
        inline Path getFilePath() const;
        /// @brief 添加库相关
        /// @param lib 包名
        inline void addImports(const std::string &lib);
        inline void addImports(const std::vector<std::string> &libs);
        inline std::vector<std::string> getImports()const;
        inline size_t getImportSize();
        /// @brief 添加优先级比较
        inline bool operator>(const Unit &x);
        inline bool operator<(const Unit &x);
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_UNIT_H
