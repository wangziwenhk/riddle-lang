#include "VarManager.h"
#include <stdexcept>

namespace Riddle {
    void VarManager::push() {
        isDefined.emplace();
    }
    void VarManager::pop() {
        for(auto i:isDefined.top()){
            NamedVar[i.first].pop();
            if(NamedVar[i.first].empty()){
                NamedVar.erase(i.first);
            }
        }
        isDefined.pop();
    }
    void VarManager::DefineVar(std::string name, bool isConst, std::string type) {
        if(isDefined.top().count(name)){
            throw std::logic_error("The variable has been defined multiple times");
        }
        NamedVar[name].push(variable(name,type,isConst));
        isDefined.top()[name] = true;
    }
}// namespace Riddle