module;
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <map>
export module Types.Class;
export namespace Riddle {
    class Class {
    public:
        llvm::StructType *type = nullptr;
        std::unordered_map<std::string, int> members;
        std::map<std::string, llvm::FunctionCallee> funcs;

        int getMember(const std::string &name) {
            const auto it = members.find(name);
            if(it == members.end()) {
                throw std::invalid_argument("No such member");
            }
            return it->second;
        }

        llvm::FunctionCallee getFunction(const std::string &name) {
            const auto it = funcs.find(name);
            if(it == funcs.end()) {
                throw std::invalid_argument("No such function");
            }
            return it->second;
        }
    };

}// namespace Riddle