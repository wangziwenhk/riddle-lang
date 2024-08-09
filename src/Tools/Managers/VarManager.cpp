#include "VarManager.h"
#include <stdexcept>

namespace Riddle {
    bool VarManager::isDefined(const std::string &name) {
        const auto it = NamedVar.find(name);
        if(it == NamedVar.end()) return false;
        if(it->second.empty()) return false;
        return true;
    }
    void VarManager::push() {
        Defined.emplace();
    }
    void VarManager::pop() {
        for(auto i: Defined.top()) {
            NamedVar[i.first].pop();
            if(NamedVar[i.first].empty()) {
                NamedVar.erase(i.first);
            }
        }
        Defined.pop();
    }
    void VarManager::defineVar(const std::string &name, const bool &isConst, llvm::Value *value) {
        if(Defined.top().count(name)) {
            throw std::logic_error("The variable has been defined multiple times");
        }
        NamedVar[name].push(Variable(name, value, isConst));
        Defined.top()[name] = true;
    }
    Variable VarManager::getVar(const std::string &name) {
        if(!isDefined(name))
            throw std::logic_error("The variable does not exist");

        return NamedVar[name].top();
    }
    bool VarManager::isGlobal() {
        return Defined.size() == 1;
    }

}// namespace Riddle