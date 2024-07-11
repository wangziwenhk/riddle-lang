#ifndef RIDDLE_LANGUAGE_UNIT_H
#define RIDDLE_LANGUAGE_UNIT_H

#include <vector>
#include <string>

namespace Riddle{
    class Unit{
    public:
        /// \brief 导入的库
        std::vector<std::string> imports;
        /// \brief 文件所在目录，用于查找相对于的包
        std::string selfPath;
    };

} // Riddle

#endif //RIDDLE_LANGUAGE_UNIT_H
