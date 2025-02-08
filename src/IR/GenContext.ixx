module;
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <stack>
#include <unordered_set>
#include <utility>
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
        explicit GenObject(const GenObjectType type, std::string name): type_id(type), name(std::move(name)) {}
        virtual ~GenObject() = default;

        [[nodiscard]] GenObjectType getGenType() const { return type_id; }
    };

    class GenVariable final : public GenObject {
    public:
        VarDefineNode *define;
        explicit GenVariable(VarDefineNode *define): GenObject(Variable, std::move(define->name)), define(define) {}
    };

    class GenClass final : public GenObject {
    public:
        // todo 实现class
        GenClass(): GenObject(Class, "") {}

        [[nodiscard]] llvm::Type *getLLVMType() const {
            return nullptr;
        }
    };

    class GenContext {
        std::unordered_map<std::string, std::stack<std::unique_ptr<GenObject>>> objects;
        std::stack<std::unordered_set<std::string>> defines;

    public:
        llvm::LLVMContext *llvmContext;
        std::unique_ptr<llvm::Module> llvmModule;
        llvm::IRBuilder<> builder;


        explicit GenContext(llvm::LLVMContext *llvmContext): llvmContext(llvmContext),
                                                             llvmModule(new llvm::Module("", *llvmContext)),
                                                             builder(*llvmContext) {}

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
            return objects[name].top().get();
        }

        void push() {
            defines.emplace();
        }

        void pop() {
            for(const auto &i: defines.top()) {
                objects.at(i).pop();
                if(objects.at(i).empty()) {
                    objects.erase(i);
                }
            }
            defines.pop();
        }
    };
}// namespace Riddle