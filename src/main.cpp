#include "argparse/argparse.hpp"
#include "config.h"
#include "termcolor/termcolor.hpp"
import Support.BuildQueue;
import Support.File;
using namespace std;

void parserArgs(const int argc, char *argv[]) {
    argparse::ArgumentParser program("riddle", GIT_VERSION);

    program.add_argument("files")
            .nargs(argparse::nargs_pattern::at_least_one);

    try {
        program.parse_args(argc, argv);
    } catch(const exception &e) {
        cout << termcolor::red << e.what() << termcolor::reset << endl;
        exit(1);
    }

    const auto files = program.get<vector<string>>("files");
    try {
        // 交由 Options 进行处理
        // Parser
        Riddle::BuildQueue buildQueue;
        for(const auto& i: files) {
            const auto option = Riddle::File(i);
            buildQueue.parserFile(option);
        }
        buildQueue.start();
    } catch(const exception &e) {
        cout << termcolor::red << e.what() << termcolor::reset << endl;
    }
}

int main(const int argc, char *argv[]) {
    setlocale(LC_ALL, "en_US.UTF-8");
    parserArgs(argc, argv);
    return 0;
}