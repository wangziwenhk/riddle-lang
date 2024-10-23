#include "Tools/BuildQueue.h"
#include "Visitors/GenVisitor.h"
#include "termcolor/termcolor.hpp"
import Tools.Options;
using namespace std;
int main(const int argc, char *argv[]) {
    // 交由 Options 进行处理
    Riddle::Options opt;
    try{
        opt = Riddle::Options(argc, argv);
    }
    catch(std::invalid_argument) {
        cout<<termcolor::red<<"No source file"<<termcolor::reset;
    }
    // Parser
    Riddle::buildQueue.parserFile(opt.source);
    Riddle::buildQueue.start();
    return 0;
}