#include <cstdint>
#include "termcolor/termcolor.hpp"
import Support.BuildQueue;
import Support.Options;
using namespace std;
int main(const int argc, char *argv[]) {
    std::setlocale(LC_ALL, "en_US.UTF-8");
    // 交由 Options 进行处理
    // Parser
    Riddle::BuildQueue buildQueue;
    for(int i = 1; i < argc; i++) {
        const auto option = Riddle::Option(argv[i]);
        buildQueue.parserFile(option);
    }
    buildQueue.start();
    return 0;
}