module;
#include <format>
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
export module Semantics.SemContext;
export import Semantics.SemNode;
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
        TypeNode *type;
        std::string name;
        ExprNode *value;

    public:
        bool is_arg = false;
        explicit SemVariable(const VarDefineNode *def): SemObject(Variable) {
            type = def->type;
            name = def->name;
            value = def->value;
        }

        explicit SemVariable(const ArgNode *def): SemObject(Variable), value(nullptr), is_arg(true) {
            type = def->type;
            name = def->name;
        }

        [[nodiscard]] TypeNode *&getType() {
            return type;
        }

        [[nodiscard]] std::string getName() const override {
            return name;
        }

        [[nodiscard]] ExprNode *&getValue() {
            return value;
        }
    };

    class SemFunction final : public SemObject {
    public:
        FuncDefineNode *define;
        explicit SemFunction(FuncDefineNode *def): SemObject(Function), define(def) {}

        [[nodiscard]] TypeNode *&getReturnType() const {
            return define->returnType;
        }

        [[nodiscard]] std::string getName() const override {
            return define->name;
        }

        [[nodiscard]] ArgNode *&getArgument(const size_t index) const {
            return define->args.at(index);
        }
    };

    class SemClass final : public SemObject {
    public:
        ClassDefineNode *define;

        explicit SemClass(ClassDefineNode *define): SemObject(Class), define(define) {}

        [[nodiscard]] std::string getName() const override {
            return define->name;
        }
    };

    class SemContext {
    protected:
        std::pmr::unordered_map<std::string, std::stack<std::unique_ptr<SemObject>>> symbols{};
        std::stack<std::unordered_set<std::string>> defines;
        std::stack<SemClass *> classes;
        std::stack<SemFunction *> functions;

    public:
        SemContext(): defines() {}

        void push() {
            defines.emplace();
        }

        void pop() {
            for(const auto &i: defines.top()) {
                symbols.at(i).pop();
                if(symbols.at(i).empty()) {
                    symbols.erase(i);
                }
            }
            defines.pop();
        }

        void pushClass(SemClass *theClass) {
            classes.push(theClass);
        }

        void popClass() {
            if(classes.empty()) {
                return;
            }
            classes.pop();
        }

        SemClass *getNowClass() {
            if(classes.empty()) {
                return nullptr;
            }
            return classes.top();
        }

        void pushFunc(SemFunction *func) {
            functions.push(func);
        }

        void popFunc() {
            if(functions.empty()) {
                return;
            }
            functions.pop();
        }

        SemFunction *getNowFunc() {
            if(functions.empty()) {
                return nullptr;
            }
            return functions.top();
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
            return it->second.top().get();
        }
    };
}// namespace Riddle