#ifndef RIDDLE_LANGUAGE_UNIT_H
#define RIDDLE_LANGUAGE_UNIT_H

#include <string>
#include <vector>

namespace Riddle {

    class Unit {
    private:
        /// \brief 导入的库
        std::vector<std::string> imports;
        /// \brief 文件所在目录，用于查找相对于的包
        std::string selfPath;
    public:
        Unit()= default;
        explicit Unit(const std::string &selfPath);
        /// \brief 添加库相关
        /// \param lib 某个被作为库的源文件的绝对路径
        void addImports(const std::string &lib);
        void addImports(const std::vector<std::string> &libs);
        size_t getImportSize();
        /// \brief 添加优先级比较
        bool operator > (const Unit& x);
        bool operator < (const Unit& x);
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_UNIT_H
