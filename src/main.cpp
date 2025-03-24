#include "argparse/argparse.hpp"
#include "config.h"
#include "termcolor/termcolor.hpp"
import Support.BuildQueue;
import Config.Init;
using namespace std;

void parserArgs(const int argc, char *argv[]) {
    argparse::ArgumentParser program("riddle", GIT_VERSION);

    program.add_argument("files").nargs(argparse::nargs_pattern::at_least_one);
    program.add_argument("--noexcept").help("disable exception handling").nargs(0);
    program.add_argument("--enable-gc").help("enable GC").nargs(0);

    try {
        program.parse_args(argc, argv);
    } catch (const exception &e) {
        cout << termcolor::red << e.what() << termcolor::reset << endl;
        exit(1);
    }

    const auto files = program.get<vector<string>>("files");
    try {
        // 交由 Files 进行处理
        // Parser
        Riddle::BuildQueue buildQueue;
        buildQueue.buildTarget->isExpect = !program.is_used("--noexcept");
        buildQueue.buildTarget->isEnableGc = program.is_used("--enable-gc");
        for (const auto &i: files) {
            buildQueue.parserFile(i);
        }
        buildQueue.start();
    } catch (const exception &e) {
        cout << termcolor::red << e.what() << termcolor::reset << endl;
    }
}

int main(const int argc, char *argv[]) {
    setlocale(LC_ALL, "en_US.UTF-8");
    Riddle::init::init();
    parserArgs(argc, argv);
    return 0;
}
