#include "termcolor/termcolor.hpp"
#include "argparse/argparse.hpp"
import Support.BuildQueue;
import Support.Options;
import Support.CommandHelp;
using namespace std;
int main(const int argc, char *argv[]) {
    argparse::ArgumentParser program("riddle");
    // try {
    std::setlocale(LC_ALL, "en_US.UTF-8");
    if(argc > 1) {
        const auto str = string(argv[1]);
        if(str == "-help" || str == "-H") {
            Riddle::printCommandHelp();
            return 0;
        }
    }
    // 交由 Options 进行处理
    // Parser
    Riddle::BuildQueue buildQueue;
    for(int i = 1; i < argc; i++) {
        const auto option = Riddle::Option(argv[i]);
        buildQueue.parserFile(option);
    }
    buildQueue.start();
    // } catch(const std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }

    return 0;
}