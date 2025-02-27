#include <iostream>
#include <llvm/IR/Value.h>
using namespace std;
import IR.IRContext;
int main(){
    Riddle::IRContext context;
    const auto a = new Riddle::ValueInst("argv");
    const auto b = new Riddle::ValueInst("argc");
    context.body.push_back(new Riddle::AllocaInst(new Riddle::IntegerTypeInst(32),a));
    context.body.push_back(new Riddle::AllocaInst(new Riddle::IntegerTypeInst(32),b));
    context.body.push_back(new Riddle::FuncCallInst("main",{a,b}));
    context.print(cout);
    return 0;
}