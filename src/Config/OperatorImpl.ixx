module;
#include <functional>
#include "Support/Hash.hpp"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Value.h"
export module Config.OperatorImpl;
import Config.BasicOperator;

using opGroup_t = std::tuple<std::string, std::string, std::string>;
using opImplFunc = std::function<llvm::Value *(llvm::Value *, llvm::Value *, llvm::IRBuilder<> &)>;

#define opFunc(lt, rt, op)                                                                                             \
    {lt, rt, op}, [](llvm::Value * lhs, llvm::Value * rhs, llvm::IRBuilder<> & builder) -> llvm::Value *

export namespace Riddle {
    inline std::unordered_map<opGroup_t, opImplFunc> operatorImpl;

    void initOperatorImpl() {
        operatorImpl.insert({opFunc("int", "int", "+"){ return builder.CreateAdd(lhs, rhs); }});
        operatorImpl.insert({opFunc("int", "int", "-"){ return builder.CreateSub(lhs, rhs); }});
        operatorImpl.insert({opFunc("int", "int", "*"){ return builder.CreateMul(lhs, rhs); }});
        operatorImpl.insert({opFunc("int", "int", "/"){ return builder.CreateSDiv(lhs, rhs); }});
    }
} // namespace Riddle
