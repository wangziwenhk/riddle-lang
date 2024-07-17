#ifndef RIDDLE_LANGUAGE_UNIT_H
#define RIDDLE_LANGUAGE_UNIT_H

#include <string>
#include <vector>
#include <antlr4-runtime.h>
typedef std::string Path;
namespace Riddle {
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
        Unit():parseTree(nullptr){};
        explicit Unit(const Path &selfPath);
        /// @brief 设置包名，通过 PackageVisitor 获取
        void setPackName(Path name);
        /// @brief 获取包名
        Path getPackName()const;
        /// @brief 设置编译单元目录的路径
        void setDirectoryPath(Path path);
        /// @brief 获取编译单元目录的路径
        Path getDirectoryPath() const;
        /// @brief 设置源文件的完整路径
        void setFilePath(Path path);
        /// @brief 获取源文件的完整路径
        Path getFilePath() const;
        /// @brief 添加库相关
        /// @param lib 包名
        void addImports(const std::string &lib);
        void addImports(const std::vector<std::string> &libs);
        std::vector<std::string> getImports()const;
        size_t getImportSize();
        /// @brief 添加优先级比较
        bool operator>(const Unit &x);
        bool operator<(const Unit &x);
        /// @brief 解析树
        antlr4::tree::ParseTree* parseTree;
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_UNIT_H
