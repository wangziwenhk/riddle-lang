#include "Tools/BuildQueue.h"
#include "termcolor/termcolor.hpp"
import Tools.Options;
using namespace std;
int main(const int argc, char *argv[]) {
    std::setlocale(LC_ALL, "en_US.UTF-8");
    // 交由 Options 进行处理
    const auto opt = Riddle::Options(argc, argv);
    // Parser
    Riddle::buildQueue.parserFile(opt.source);
    Riddle::buildQueue.start();
    return 0;
}