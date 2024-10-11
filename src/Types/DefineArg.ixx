module;
#include <llvm/IR/Type.h>
#include <string>
#include <vector>
export module Type.DefineArg;
export namespace Riddle {
    class DefineArg {
        std::string name;
        std::string type;
        std::string default_value;
    };
    class Arg {
        std::string value;
    };
    struct DefineArgsType {
        std::vector<llvm::Type *> types;
        std::vector<std::string> names;
    };
    typedef std::vector<DefineArg> DefineArgs;
    typedef std::vector<Arg> Args;
}// namespace Riddle