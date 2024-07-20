#include "Tools/BuildQueue.h"
using namespace std;
int main(int argv, char *argc[]) {
    if(argv < 2) return 0;
    Riddle::buildQueue.parserFile(argc[1]);
    Riddle::buildQueue.start();
    return 0;
}