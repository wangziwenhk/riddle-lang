#include <iostream>
#include <llvm/IR/Value.h>
using namespace std;
import IR.IRContext;
int main(){
    Riddle::IRContext context;
    context.body.push_back(new Riddle::AllocaInst(new Riddle::IntegerTypeInst(32)));
    context.body.push_back(new Riddle::AllocaInst(new Riddle::IntegerTypeInst(16)));
    context.body.push_back(new Riddle::FuncCallInst("main",{new Riddle::ValueInst("1")}));
    context.print(cout);
    return 0;
}