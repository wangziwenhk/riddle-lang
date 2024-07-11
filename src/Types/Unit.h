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
        /// \brief 添加库
        void addImports(const std::string &lib);
        void addImports(const std::vector<std::string> &libs);
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_UNIT_H
