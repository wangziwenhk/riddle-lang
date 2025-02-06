module;
#include <format>
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
export module Semantics.SemContext;
import Semantics.SemNode;
export namespace Riddle {
    /// 在词法解析过程中产生的 Object
    class SemObject {
    public:
        enum SemObjectType {
            Variable,
            Function,
            Class,
        };

    protected:
        SemObjectType type;

    public:
        explicit SemObject(const SemObjectType type): type(type) {}
        virtual ~SemObject() = default;

        [[nodiscard]] virtual std::string getName() const = 0;

        [[nodiscard]] virtual SemObjectType getSemObjType() const noexcept {
            return type;
        }
    };

    class SemVariable final : public SemObject {
    public:
        VarDefineNode *define;
        explicit SemVariable(VarDefineNode *def): SemObject(Variable), define(def) {}

        [[nodiscard]] TypeNode *getType() const {
            return define->type;
        }

        [[nodiscard]] std::string getName() const override {
            return define->name;
        }

        [[nodiscard]] ExprNode *getValue() const {
            return define->value;
        }
    };

    class SemContext {
    protected:
        std::pmr::unordered_map<std::string, std::stack<SemObject *>> symbols;
        std::stack<std::unordered_set<std::string>> defines;

    public:
        SemContext() = default;

        void push() {
            defines.emplace();
        }

        void pop() {
            for(const auto &i: defines.top()) {
                auto &it = symbols.at(i).top();
                delete it;
                it = nullptr;
                symbols.at(i).pop();
                if(symbols.at(i).empty()) {
                    symbols.erase(i);
                }
            }
            defines.pop();
        }

        size_t deep() const {
            return defines.size();
        }

        void addSemObject(SemObject *obj) {
            const std::string name = obj->getName();
            if(defines.top().contains(name)) {
                throw std::runtime_error(std::format("SemObject \"{}\" already exists", name));
            }
            defines.top().insert(name);
            symbols[name].emplace(obj);
        }

        SemObject *getSemObject(const std::string &name) {
            const auto it = symbols.find(name);
            if(it == symbols.end()) {
                return nullptr;
            }
            return it->second.top();
        }
    };
}// namespace Riddle