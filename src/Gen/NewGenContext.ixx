module;
#include <iostream>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <memory>
#include <stack>
#include <utility>
export module Gen.NewGenContext;
import Support.Unit;
export namespace Riddle {
    class NewGenObject {};
    class NewGenContext {
        std::unordered_map<std::string, std::stack<NewGenObject*>> objects;
        std::stack<std::vector<std::string>> defined;

    public:
        std::unique_ptr<llvm::Module> llvmModule;
        llvm::LLVMContext *llvmContext;
        llvm::IRBuilder<> builder;
        Unit unit;
        NewGenContext(llvm::LLVMContext *ctx, Unit unit):
            llvmModule(new llvm::Module(unit.getPackName(), *ctx)), llvmContext(ctx), builder(*llvmContext),
            unit(std::move(unit)) {
            push();
        }

        ~NewGenContext() {
            pop();
        }

        void push() {
            defined.emplace();
        }

        void pop() {
            if (defined.empty()) {
                throw std::runtime_error("Empty stack");
            }
            for (const auto& i:defined.top()) {
                auto it = objects.find(i);
                if (it == objects.end()) {
                    throw std::runtime_error("Object not found while pushing out scope");
                }
                it->second.pop();
                if (it->second.empty()) {
                    objects.erase(i);
                }
            }
        }
    };
} // namespace Riddle
