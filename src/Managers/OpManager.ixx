module;
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Type.h>

#include <map>
export module Manager.OpManager;
import Types.Statements;
#define FIW std::function<llvm::Value *(llvm::IRBuilder<> &, llvm::Value *, llvm::Value *)>
#define FIA llvm::IRBuilder<> &builder, llvm::Value *lhs, llvm::Value *rhs

export namespace Riddle {
    struct OpGroup {
        llvm::Type *lhs;
        llvm::Type *rhs;
        std::string op;

        bool operator<(const OpGroup &other) const {
            return op < other.op;
        }

        bool operator>(const OpGroup &other) const {
            return op > other.op;
        }

        OpGroup(llvm::Type *lhs, llvm::Type *rhs, const std::string &op): lhs(lhs), rhs(rhs), op(op) {}
    };
}// namespace Riddle

const std::vector<std::pair<Riddle::OpGroup, FIW>> &getBaseOpGroups(llvm::LLVMContext &ctx) {
    const auto i32Ty = llvm::Type::getInt32Ty(ctx);
    static const std::vector<std::pair<Riddle::OpGroup, FIW>> baseOpGroups = {
            {{i32Ty, i32Ty, "="}, [](FIA) -> llvm::Value * {
                 return builder.CreateStore(rhs, lhs);
             }},
            {{i32Ty, i32Ty, "=="}, [](FIA) -> llvm::Value * {
                 return builder.CreateICmpEQ(lhs, rhs);
             }},
            {{i32Ty, i32Ty, "<"}, [](FIA) -> llvm::Value * {
                 return builder.CreateICmpSLT(lhs, rhs);
             }},
            {{i32Ty, i32Ty, "<="}, [](FIA) -> llvm::Value * {
                 return builder.CreateICmpSLE(lhs, rhs);
             }},
            {{i32Ty, i32Ty, ">"}, [](FIA) -> llvm::Value * {
                 return builder.CreateICmpSGT(lhs, rhs);
             }},
            {{i32Ty, i32Ty, ">="}, [](FIA) -> llvm::Value * {
                 return builder.CreateICmpSGE(lhs, rhs);
             }},
            {{i32Ty, i32Ty, "+"}, [](FIA) -> llvm::Value * {
                 return builder.CreateAdd(lhs, rhs);
             }},
            {{i32Ty, i32Ty, "-"}, [](FIA) -> llvm::Value * {
                 return builder.CreateSub(lhs, rhs);
             }},
            {{i32Ty, i32Ty, "*"}, [](FIA) -> llvm::Value * {
                 return builder.CreateMul(lhs, rhs);
             }},
            {{i32Ty, i32Ty, "/"}, [](FIA) -> llvm::Value * {
                 return builder.CreateSDiv(lhs, rhs);
             }},
            {{i32Ty, i32Ty, "%"}, [](FIA) -> llvm::Value * {
                 return builder.CreateSRem(lhs, rhs);
             }},
            {{i32Ty, i32Ty, "&"}, [](FIA) -> llvm::Value * {
                 // 按位与
                 return builder.CreateAnd(lhs, rhs);
             }},
            {{i32Ty, i32Ty, "|"}, [](FIA) -> llvm::Value * {
                 // 按位或
                 return builder.CreateOr(lhs, rhs);
             }},
            {{i32Ty, i32Ty, "^"}, [](FIA) -> llvm::Value * {
                 return builder.CreateXor(lhs, rhs);
             }},

    };
    return baseOpGroups;
}

export namespace Riddle {
    // 管理运算符的实际实现
    class OpManager {
        // 这个成员中存的是一个function用于生成不同类型的llvm ir Create
        std::map<OpGroup, FIW> opMap;
        llvm::LLVMContext &ctx;

    public:
        explicit OpManager(llvm::LLVMContext &ctx): ctx(ctx) {
            //基础类型的运算符实现
            // ReSharper disable once CppTooWideScopeInitStatement
            auto baseOpGroups = getBaseOpGroups(ctx);
            for(auto [group, func]: baseOpGroups) {
                opMap[group] = func;
            }
        }

        FIW getOpFunc(const OpGroup &op) {
            const auto it = opMap.find(op);
            if(it == opMap.end()) {
                throw std::runtime_error("Op group does not exist");
            }
            return it->second;
        }
    };
}// namespace Riddle