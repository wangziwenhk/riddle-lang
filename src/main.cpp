#include "Tools/BuildQueue.h"
#include "Visitors/GenVisitor.h"
#include "termcolor/termcolor.hpp"
import Tools.Options;
using namespace std;
int main(const int argv, char *argc[]) {
    // 交由 Options 进行处理
    vector<string> args;
    for(int i = 1; i < argv; i++) {
        args.push_back(argc[i]);
    }
    Riddle::Options opt;
    try{
        opt = Riddle::Options(args);
    }
    catch(std::invalid_argument) {
        cout<<termcolor::red<<"No source file"<<termcolor::reset;
    }
    // Parser
    Riddle::buildQueue.parserFile(opt.source);
    Riddle::buildQueue.start();
    return 0;
}