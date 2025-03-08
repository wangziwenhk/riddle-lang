module;
#include <format>
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "Support/Hash.hpp"
export module Semantics.SemContext;
export import Semantics.SemNode;
import Config.BasicOperator;
export namespace Riddle {
    /// 在词法解析过程中产生的 Object
    class SemObject {
    public:
        enum SemObjectType {
            Variable,
            Function,
            Class,
            Module,
        };

    protected:
        SemObjectType type;

    public:
        explicit SemObject(const SemObjectType type): type(type) {
        }

        virtual ~SemObject() = default;

        [[nodiscard]] virtual std::string getName() const = 0;

        [[nodiscard]] virtual SemObjectType getSemObjType() const noexcept {
            return type;
        }

        virtual TypeNode *getConstType() = 0;

        virtual SemObject *clone() = 0;
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

        TypeNode *getConstType() override {
            return type;
        }


        [[nodiscard]] std::string getName() const override {
            return name;
        }

        [[nodiscard]] ExprNode *&getValue() {
            return value;
        }

        SemObject *clone() override {
            return new SemVariable(*this);
        }
    };

    class SemFunction final : public SemObject {
    public:
        FuncDefineNode *define;

        explicit SemFunction(FuncDefineNode *def): SemObject(Function), define(def) {
        }

        [[nodiscard]] TypeNode *&getReturnType() const {
            return define->returnType;
        }

        TypeNode *getConstType() override {
            return getReturnType();
        }

        [[nodiscard]] std::string getName() const override {
            return define->name;
        }

        [[nodiscard]] ArgNode *&getArgument(const size_t index) const {
            return define->args.at(index);
        }

        SemObject *clone() override {
            return new SemFunction(*this);
        }
    };

    class SemClass final : public SemObject {
        std::unordered_map<std::string, SemFunction *> funcs;
        std::unordered_map<std::string, SemVariable *> members;

    public:
        ClassDefineNode *define;

        explicit SemClass(ClassDefineNode *define): SemObject(Class), define(define) {
        }

        [[nodiscard]] std::string getName() const override {
            return define->name;
        }

        [[nodiscard]] TypeNode *getConstType() override {
            return define;
        }

        void addFunction(SemFunction *func) {
            if (funcs.contains(func->getName())) {
                throw std::runtime_error("Function '" + func->getName() + "' already exists");
            }
            funcs[func->getName()] = func;
        }

        SemFunction *getFunction(const std::string &name) {
            if (!funcs.contains(name)) {
                throw std::runtime_error("Function '" + name + "' not found");
            }
            return funcs[name];
        }

        void addMember(SemVariable *member) {
            if (members.contains(member->getName())) {
                throw std::runtime_error("Member '" + member->getName() + "' already exists");
            }
            members[member->getName()] = member;
        }

        SemVariable *getMember(const std::string &name) {
            if (!members.contains(name)) {
                throw std::runtime_error("Member '" + name + "' not found");
            }
            return members[name];
        }

        SemObject *clone() override {
            return new SemClass(*this);
        }
    };

    class SemModule final : public SemObject {
    protected:
        std::unordered_map<std::string, SemObject *> objects;
        std::string name;

    public:
        explicit SemModule(std::string name): SemObject(Module), name(std::move(name)) {
        }

        void addObject(SemObject *obj) {
            if (objects.contains(obj->getName())) {
                throw std::runtime_error("Duplicate object name");
            }
            objects[obj->getName()] = obj;
        }

        SemObject *getObject(const std::string &name) const {
            const auto it = objects.find(name);
            if (it == objects.end()) {
                throw std::runtime_error("Duplicate object name");
            }
            return it->second;
        }

        std::string getName() const override {
            return name;
        }

        TypeNode *getConstType() override {
            return nullptr;
        }

        SemObject *clone() override {
            return new SemModule(*this);
        }
    };

    class SemContext {
    protected:
        std::unordered_map<std::string, std::stack<std::shared_ptr<SemObject> > > symbols{};
        std::stack<std::unordered_set<std::string> > defines;
        std::stack<SemClass *> classes;
        std::stack<SemFunction *> functions;

        std::unordered_map<std::tuple<std::string, std::string, std::string>, std::string> operators;
        std::string name;

    public:
        explicit SemContext(std::string name): defines(), name(std::move(name)) {
            operators = numOpReType;
            // 初始化逻辑运算符（可短路
            for (const auto &i: LogicOp::list) {
                operators.insert({{"bool", "bool", i}, "bool"});
            }
            push();
        }

        ~SemContext() {
            pop();
        }

        std::string getName() const {
            return name;
        }

        auto &getAllObjects() {
            return symbols;
        }

        void push() {
            defines.emplace();
        }

        void pop() {
            for (const auto &i: defines.top()) {
                symbols.at(i).pop();
                if (symbols.at(i).empty()) {
                    symbols.erase(i);
                }
            }
            defines.pop();
        }

        void pushClass(SemClass *theClass) {
            classes.push(theClass);
        }

        void popClass() {
            if (classes.empty()) {
                return;
            }
            classes.pop();
        }

        SemClass *getNowClass() {
            if (classes.empty()) {
                return nullptr;
            }
            return classes.top();
        }

        void pushFunc(SemFunction *func) {
            functions.push(func);
        }

        void popFunc() {
            if (functions.empty()) {
                return;
            }
            functions.pop();
        }

        SemFunction *getNowFunc() {
            if (functions.empty()) {
                return nullptr;
            }
            return functions.top();
        }

        size_t deep() const {
            return defines.size();
        }

        void addSemObject(SemObject *obj) {
            const std::string name = obj->getName();
            if (defines.top().contains(name)) {
                throw std::runtime_error(std::format("SemObject \"{}\" already exists", name));
            }
            defines.top().insert(name);
            symbols[name].emplace(obj);
        }

        SemObject *getSemObject(const std::string &name) {
            const auto it = symbols.find(name);
            if (it == symbols.end()) {
                return nullptr;
            }
            return it->second.top().get();
        }

        void addOperator(std::tuple<std::string, std::string, std::string> opGroup, const std::string& type) {
            const auto op = std::get<2>(opGroup);
            if (LogicOp::set.contains(op)) {
                throw std::logic_error(std::format("Logical {} operators cannot be overloaded", op));
            }
            operators.insert({opGroup, type});
        }

        std::string getOperator(const std::tuple<std::string, std::string, std::string> &opGroup) {
            const auto it = operators.find(opGroup);
            auto [lt,rt,op] = opGroup;
            auto aaa = operators.contains(opGroup);
            if (it == operators.end()) {
                throw std::runtime_error(std::format("Duplicate operator: '{}' '{}' '{}'", lt, op, rt));
            }
            return it->second;
        }
    };
} // namespace Riddle
