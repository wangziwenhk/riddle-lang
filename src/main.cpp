#include "argparse/argparse.hpp"
#include "config.h"
#include "termcolor/termcolor.hpp"
import Support.BuildQueue;
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
        Riddle::BuildQueue buildQueue;
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
    parserArgs(argc, argv);
    return 0;
}
