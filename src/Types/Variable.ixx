module;
#include <string>
#include <utility>
export module Type.Variable;
import Types.Value;
export namespace Riddle {
    class Variable {
    public:
        const std::string name;
        Value *var;
        const bool isConst;
        Variable() = delete;
        Variable(std::string name,
                 Value *var,
                 const bool isConst = false): name(std::move(name)), var(var), isConst(isConst) {}
    };

}// namespace Riddle