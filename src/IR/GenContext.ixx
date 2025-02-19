module;
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <stack>
#include <unordered_set>
#include <utility>
#include <ranges>
export module IR.GenContext;
import Semantics.SemNode;
export namespace Riddle {
    class GenObject {
    public:
        enum GenObjectType {
            Variable,
            Function,
            Class,
        };

    protected:
        GenObjectType type_id;

    public:
        std::string name;
        /// 表示 context 是否拥有该对象的所有权
        bool is_weak = false;
        explicit GenObject(const GenObjectType type, std::string name): type_id(type), name(std::move(name)) {}
        virtual ~GenObject() = default;

        [[nodiscard]] GenObjectType getGenType() const { return type_id; }
    };

    class GenVariable final : public GenObject {

    public:
        explicit GenVariable(const VarDefineNode *define): GenObject(Variable, define->name) {
            alloca = define->alloca->alloca;
            type = define->type;
        }
        explicit GenVariable(const ArgNode* define):GenObject(Variable,define->name) {
            alloca = define->alloca->alloca;
            type = define->type;
        }

        llvm::Value* alloca;
        TypeNode* type;
    };

    class GenFunction final : public GenObject {
    public:
        FuncDefineNode *define;
        llvm::Function* llvmFunction;
        GenFunction(FuncDefineNode *define, llvm::Function *func): GenObject(Function, define->name), define(define), llvmFunction(func) {}
    };

    class GenClass final : public GenObject {
        std::unordered_map<std::string,GenFunction*>functions;
    public:
        ClassDefineNode *define;
        llvm::StructType *type = nullptr;
        explicit GenClass(ClassDefineNode *define): GenObject(Class, define->name), define(define) {}

        ~GenClass() override {
            for(const auto i:functions | std::views::values) {
                delete i;
            }
        }

        [[nodiscard]] llvm::Type *getLLVMType() const noexcept{
            return type;
        }

        void addFunc(GenFunction *func) {
            if(functions.contains(func->name)) {
                throw std::logic_error("Function " + func->name + " all exist");
            }
            functions[func->name] = func;
        }

        GenFunction *getFunc(const std::string &name) const {
            if(!functions.contains(name)) {
                throw std::logic_error("Function " + name + " does not exist");
            }
            return functions.at(name);
        }
    };

    class GenContext {
        std::unordered_map<std::string, std::stack<GenObject*>> objects;
        std::stack<std::unordered_set<std::string>> defines;
        std::stack<GenFunction *> functions;

    public:
        llvm::LLVMContext *llvmContext;
        std::unique_ptr<llvm::Module> llvmModule;
        llvm::IRBuilder<> builder;


        explicit GenContext(llvm::LLVMContext *llvmContext): llvmContext(llvmContext),
                                                             llvmModule(new llvm::Module("", *llvmContext)),
                                                             builder(*llvmContext) {}

        void pushFunc(GenFunction *func)  {
            functions.push(func);
        }

        void popFunc() {
            functions.pop();
        }

        GenFunction *getNowFunc() {
            return functions.top();
        }

        void addObject(GenObject *object) {
            if(defines.top().contains(object->name)) {
                throw std::runtime_error(std::format("Object '{}' already exists", object->name));
            }
            defines.top().insert(object->name);
            objects[object->name].emplace(object);
        }

        GenObject *getObject(std::string name) {
            if(!objects.contains(name)) {
                throw std::runtime_error(std::format("Object '{}' does not exist", name));
            }
            return objects[name].top();
        }

        void push() {
            defines.emplace();
        }

        void pop() {
            for(const auto &i: defines.top()) {
                const auto ptr = objects.at(i).top();
                objects.at(i).pop();
                if(objects.at(i).empty()) {
                    objects.erase(i);
                }
                if(!ptr->is_weak) {
                    delete ptr;
                }
            }
            defines.pop();
        }
    };
}// namespace Riddle