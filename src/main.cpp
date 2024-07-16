#include "Tools/BuildQueue.h"
#include <fstream>
#include <iostream>
using namespace std;
int main(int argv, char *argc[]) {
    if(argv < 2) return 0;
    Riddle::buildQueue.Parser(argc[1]);
    Riddle::buildQueue.start();
    return 0;
}
