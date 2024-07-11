#ifndef RIDDLE_LANGUAGE_SETUP_H
#define RIDDLE_LANGUAGE_SETUP_H
#include <string>

namespace Riddle {
    class Setup {
    private:
        std::string workPath;

    public:
        Setup();
        std::string getWorkPath();
    };
    static Setup Setup;

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_SETUP_H
