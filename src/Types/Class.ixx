module;
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <map>
export module Types.Class;
export namespace Riddle {
    class Class {
    public:
        llvm::StructType *types = nullptr;
        std::unordered_map<std::string, int> names;
        std::map<std::string, llvm::FunctionCallee> funcs;
        std::string moduleName;
    };

}// namespace Riddle