#include <stdint.h>
#include "termcolor/termcolor.hpp"
import Tools.BuildQueue;
import Tools.Options;
using namespace std;
int main(const int argc, char *argv[]) {
    std::setlocale(LC_ALL, "en_US.UTF-8");
    // 交由 Options 进行处理
    const auto opt = Riddle::Options(argc, argv);
    // Parser
    freopen(opt.output.c_str(), "w", stdout);
    Riddle::BuildQueue buildQueue;
    buildQueue.parserFile(opt.source);
    buildQueue.start();
    return 0;
}