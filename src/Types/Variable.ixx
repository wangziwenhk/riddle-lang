module;
#include <llvm/IR/Instructions.h>
#include <string>
#include <utility>
export module Type.Variable;
export namespace Riddle {
    const std::string Null = "null";
    class Variable {
    public:
        const std::string name;
        llvm::Value *value;
        const bool isConst;
        Variable() = delete;
        Variable(std::string name,
                 llvm::Value *value,
                 const bool isConst = false): name(std::move(name)), value(value), isConst(isConst){};
    };

}// namespace Riddle