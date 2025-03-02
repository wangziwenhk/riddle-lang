#include <iostream>
#include <llvm/IR/Value.h>
using namespace std;
import Config.BasicOperator;

int main() {
    auto it = Riddle::numOpReType;
    for (const auto &[fst, snd]: it) {
        auto [op1,op2,op3] = fst;
        cout << op1 << " " << op2 << " " << op3 << " " << snd << endl;
    }
    return 0;
}
