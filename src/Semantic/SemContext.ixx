module;
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
export module Semantic.SemContext;
import Semantic.SemNode;
export namespace Riddle {
    class SemObject {
    public:
        enum SemObjectType {
            Variable,
            Function,
            Type,
        };

    protected:
        explicit SemObject(std::string name, const SemObjectType id): id(id), name(std::move(name)) {
        }

    public:
        SemObjectType id;

        std::string name;
        virtual ~SemObject() = default;
    };

    class SemVariable final : public SemObject {
    public:
        VarDeclNode *define{};

        explicit SemVariable(std::string name, VarDeclNode *define):
            SemObject(std::move(name), Variable), define(define) {
        }

        static auto create(std::string name, VarDeclNode *define) {
            return std::make_shared<SemVariable>(std::move(name), define);
        }
    };

    class SemType final : public SemObject {
    public:
        explicit SemType(std::string name): SemObject(std::move(name), Type) {
        }
    };

    class SemContext {
        std::unordered_map<std::string, std::stack<std::shared_ptr<SemObject>>> objects;
        std::stack<std::unordered_set<std::string>> defined;

    public:
        SemContext() {
            push();
        }

        ~SemContext() {
            pop();
        }

        void push() {
            constexpr size_t max_deep = 1e5;
            if (defined.size() > max_deep) {
                throw std::runtime_error("SemContext::push(): stack overflow");
            }
            defined.emplace();
        }

        void pop() {
            if (defined.empty()) {
                throw std::runtime_error("SemContext::pop(): empty stack");
            }
            for (const auto &i: defined.top()) {
                objects.at(i).pop();
                if (objects.at(i).empty()) {
                    objects.erase(i);
                }
            }
            defined.pop();
        }

        void addObject(const std::shared_ptr<SemObject> &obj) {
            if (defined.top().contains(obj->name)) {
                throw std::runtime_error("SemContext::addObject(): object already exists");
            }
            objects[obj->name].emplace(obj);
            defined.top().insert(obj->name);
        }

        std::shared_ptr<SemObject> getObject(const std::string &name) {
            if (!objects.contains(name) || objects.at(name).empty()) {
                throw std::runtime_error("SemContext::getObject(): object not found");
            }
            return objects.at(name).top();
        }
    };
} // namespace Riddle
