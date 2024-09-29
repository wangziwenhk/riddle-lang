module;
#include <llvm/IR/Instructions.h>
#include <string>
#include <utility>
export module Type.Variable;
export namespace Riddle {
    class Variable {
    public:
        const std::string name;
        llvm::Value *var;
        const bool isConst;
        Variable() = delete;
        Variable(std::string name,
                 llvm::Value *var,
                 const bool isConst = false): name(std::move(name)), var(var), isConst(isConst){};
    };

}// namespace Riddle