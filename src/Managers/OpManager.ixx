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
    };

    // 管理运算符的实际实现
    class OpManager {
        // 这个成员中存的是一个function用于生成不同类型的llvm ir Create
        std::map<OpGroup, FIW> opMap;
        llvm::LLVMContext &ctx;

    public:
        explicit OpManager(llvm::LLVMContext &ctx): ctx(ctx) {
            //基础类型的运算符实现
            const auto i32Ty = llvm::Type::getInt32Ty(ctx);
            const std::vector<std::pair<OpGroup, FIW>> baseOpGroups = {
                    {{i32Ty, i32Ty, "="}, [](FIA) -> llvm::Value * {
                         return builder.CreateStore(rhs, lhs);
                     }},
                    {{i32Ty, i32Ty, "=="}, [](FIA) -> llvm::Value * {
                         return builder.CreateICmpEQ(lhs, rhs);
                     }},
            };
            for(auto [group, func]: baseOpGroups) {
                opMap[group] = func;
            }
        }

        FIW getOpFunc(const OpGroup &op) {
            return opMap[op];
        }
    };
}