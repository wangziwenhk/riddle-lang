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
    program.add_argument("-I", "--include-path")
       .help("add C/C++ include path")
       .nargs(1)
       .append()
       .metavar("DIR");

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

        if (program.is_used("--include-path")) {
            const auto includePaths = program.get<vector<string>>("--include-path");
            for (const auto &path : includePaths) {
                buildQueue.buildTarget->cx_include_paths.push_back(path);
            }
        }

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
    // const auto a = Riddle::header::parseCHead(argv[1]);
    return 0;
}
