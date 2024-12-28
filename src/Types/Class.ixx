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
    };

}// namespace Riddle