module;
#include <format>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
export module Manager.SemManager;
import Semantics.SemNode;
export namespace Riddle {
    class SemManager {
        std::unordered_map<std::string, std::stack<SemNode *>> semMap;
        std::stack<std::set<std::string>> defined;

    public:
        SemManager() = default;

        SemNode *getNode(std::string name) {
            const auto it = semMap.find(name);
            if(it == semMap.end()) {
                throw std::out_of_range(std::format("SemManager::getNode(): {}", name));
            }
            return it->second.top();
        }

        void addNode(std::string name,SemNode* node) {
            if(defined.top().contains(name)) {
                throw std::logic_error(std::format("SemManager::addNode(): \"{}\" already exits", name));
            }
            defined.top().insert(name);
        }

        void push() {
            defined.emplace();
        }

        void pop() {
            for(const auto& i:defined.top()) {
                semMap.at(i).pop();
                if(semMap.at(i).empty()) {
                    semMap.erase(i);
                }
            }
            defined.pop();
        }
    };
}// namespace Riddle
