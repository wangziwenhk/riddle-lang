module;
#include <functional>
#include "Support/Hash.hpp"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Value.h"
export module Config.OperatorImpl;
import Config.BasicOperator;
import Config.BasicType;

using opGroup_t = std::tuple<std::string, std::string, std::string>;
using opImplFunc = std::function<llvm::Value *(llvm::Value *, llvm::Value *, llvm::IRBuilder<> &)>;

#define opFunc(lt, rt, op)                                                                                             \
    {lt, rt, op}, [](llvm::Value * lhs, llvm::Value * rhs, llvm::IRBuilder<> & builder) -> llvm::Value *

export namespace Riddle {
    inline std::unordered_map<opGroup_t, opImplFunc> operatorImpl;

    void initOperatorImpl() {
        //赋值的通用实现
        for (auto i: BasicType::list) {
            operatorImpl.insert({opFunc("int", "int", "="){ return builder.CreateStore(lhs, rhs); }});
        }

        operatorImpl.insert({opFunc("int", "int", "+"){ return builder.CreateAdd(lhs, rhs); }});
        operatorImpl.insert({
            opFunc("int", "int", "+="){
                const auto load = builder.CreateLoad(builder.getInt32Ty(), lhs);
                const auto val = builder.CreateAdd(load, rhs);
                return builder.CreateStore(val,lhs);
            }
        });
        operatorImpl.insert({opFunc("int", "int", "-"){ return builder.CreateSub(lhs, rhs); }});
        operatorImpl.insert({
            opFunc("int", "int", "-="){
                const auto load = builder.CreateLoad(builder.getInt32Ty(), lhs);
                const auto val = builder.CreateSub(load, rhs);
                return builder.CreateStore(val,lhs);
            }
        });
        operatorImpl.insert({opFunc("int", "int", "*"){ return builder.CreateMul(lhs, rhs); }});
        operatorImpl.insert({
            opFunc("int", "int", "*="){
                const auto load = builder.CreateLoad(builder.getInt32Ty(), lhs);
                const auto val = builder.CreateMul(load, rhs);
                return builder.CreateStore(val,lhs);
            }
        });
        operatorImpl.insert({opFunc("int", "int", "/"){ return builder.CreateSDiv(lhs, rhs); }});
        operatorImpl.insert({
            opFunc("int", "int", "/="){
                const auto load = builder.CreateLoad(builder.getInt32Ty(), lhs);
                const auto val = builder.CreateSDiv(load, rhs);
                return builder.CreateStore(val,lhs);
            }
        });
        operatorImpl.insert({opFunc("int", "int", "%"){ return builder.CreateSRem(lhs, rhs); }});
        operatorImpl.insert({
            opFunc("int", "int", "%="){
                const auto load = builder.CreateLoad(builder.getInt32Ty(), lhs);
                const auto val = builder.CreateSRem(load, rhs);
                return builder.CreateStore(val,lhs);
            }
        });
        operatorImpl.insert({opFunc("int", "int", ">>"){ return builder.CreateAShr(lhs, rhs); }});
        operatorImpl.insert({
            opFunc("int", "int", ">>="){
                const auto load = builder.CreateLoad(builder.getInt32Ty(), lhs);
                const auto val = builder.CreateAShr(load, rhs);
                return builder.CreateStore(val,lhs);
            }
        });
        operatorImpl.insert({opFunc("int", "int", "<<"){ return builder.CreateShl(lhs, rhs); }});
        operatorImpl.insert({
            opFunc("int", "int", "<<="){
                const auto load = builder.CreateLoad(builder.getInt32Ty(), lhs);
                const auto val = builder.CreateShl(load, rhs);
                return builder.CreateStore(val,lhs);
            }
        });
        operatorImpl.insert({
            opFunc("int", "int", ">"){ return builder.CreateICmp(llvm::ICmpInst::ICMP_SGT, lhs, rhs); }
        });
        operatorImpl.insert({
            opFunc("int", "int", "<"){ return builder.CreateICmp(llvm::ICmpInst::ICMP_SLT, lhs, rhs); }
        });
        operatorImpl.insert({
            opFunc("int", "int", ">="){ return builder.CreateICmp(llvm::ICmpInst::ICMP_SGE, lhs, rhs); }
        });
        operatorImpl.insert({
            opFunc("int", "int", "<="){ return builder.CreateICmp(llvm::ICmpInst::ICMP_SLE, lhs, rhs); }
        });
        operatorImpl.insert({
            opFunc("int", "int", "=="){ return builder.CreateICmp(llvm::ICmpInst::ICMP_EQ, lhs, rhs); }
        });
        operatorImpl.insert({
            opFunc("int", "int", "!="){ return builder.CreateICmp(llvm::ICmpInst::ICMP_NE, lhs, rhs); }
        });
    }
} // namespace Riddle
