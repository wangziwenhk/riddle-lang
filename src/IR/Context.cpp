module;
#include <stdexcept>
module IR.Context;

namespace Riddle {
    Variable &VarManager::getVariable(const std::string &name) {
        if(!Vars.contains(name) || Vars.find(name)->second.empty()) {
            throw std::logic_error("Variable not found");
        }
        return *Vars[name].top();
    }

    void VarManager::addVariable(Variable &var) {
        if(Defined.top().contains(var.name)) {
            throw std::logic_error("Variable already exists");
        }
        Defined.top().insert(var.name);
        Vars[var.name].push(&var);
    }

    void VarManager::push() {
        Defined.emplace();
    }

    void VarManager::pop() {
        for(const auto &i: Defined.top()) {
            Vars[i].pop();
            if(Vars[i].empty()) {
                Vars.erase(i);
            }
        }
        Defined.pop();
    }

}// namespace Riddle