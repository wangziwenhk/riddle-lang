module;
#include <ranges>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
export module Manager.ObjectManager;
import IR.Objects;
import IR.Context;
export namespace Riddle {
    class ObjectManager {
        std::unordered_map<std::string, std::stack<Object *>> objects;
        std::stack<std::unordered_map<std::string, bool>> isDefined;
        Context *ctx = nullptr;

    public:
        explicit ObjectManager(Context *ctx): ctx(ctx) {}

        void push() {
            isDefined.emplace();
        }

        void pop() {
            if(isDefined.empty()) {
                throw std::runtime_error("ObjectManager::pop(): empty stack");
            }
            for(const auto &i: isDefined.top() | std::views::keys) {
                objects[i].pop();
                if(objects[i].empty()) {
                    objects.erase(i);
                }
            }
            isDefined.pop();
        }

        Variable *getVariable(const std::string &name, Type *type) const {
            return new Variable(name, type, ctx);
        }

        void addObject(const std::string &name, Object *object) {
            if(isDefined.top().contains(name)) {
                throw std::runtime_error("ObjectManager::addObject(): object already exists");
            }
        }
    };
}// namespace Riddle