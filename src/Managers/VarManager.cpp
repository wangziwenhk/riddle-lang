module;
#include <llvm/IR/Value.h>
#include <stdexcept>
#include <ranges>
module Manager.VarManager;

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
        for(const auto& name: Defined.top() | std::views::keys) {
            NamedVar[name].pop();
            if(NamedVar[name].empty()) {
                NamedVar.erase(name);
            }
        }
        Defined.pop();
    }
    void VarManager::defineVar(const std::string &name, const bool &isConst, llvm::Value *value) {
        if(Defined.top().contains(name)) {
            throw std::logic_error("The variable has been defined multiple times");
        }
        NamedVar[name].emplace(name, value, isConst);
        Defined.top()[name] = true;
    }
    void VarManager::addVar(const Variable &var) {
        NamedVar[var.name].push(var);
        Defined.top()[var.name] = true;
    }
    Variable VarManager::getVar(const std::string &name) {
        return NamedVar[name].top();
    }
    bool VarManager::isGlobal() const {
        return Defined.size() == 1;
    }

}// namespace Riddle