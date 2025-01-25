module;
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <llvm/IR/IRBuilder.h>
#include <stack>
#include <ranges>
export module IR.Context;
import Manager.StmtManager;
import Manager.OpManager;
import Type.Modifier;
import Tools.Allocator;
export namespace Riddle {
    class Context;

    class Object {
    public:
        enum ObjectTypeID {
            /// constant type id
            IntegerTyID,
            FloatTyID,
            DoubleTyID,
            BooleanTyID,

            ConstantTyID,

            VariableTyID,
            FunctionTyID,
            ModuleTyID,
            ClassTyID,
        };

    protected:
        ObjectTypeID objectTypeID;

    public:
        // ReSharper disable once CppDFANotInitializedField
        Modifier modifier;
        std::string name;
        Context *ctx{};

        Object() = delete;

        Object(const ObjectTypeID &type_id, Context *ctx, std::string name): objectTypeID(type_id), name(std::move(name)), ctx(ctx) {}
        virtual ~Object() = default;

        /// 获取 Object 类型的 ID
        [[nodiscard]] ObjectTypeID getObjectTypeID() const {
            return objectTypeID;
        }

        /// 获取 Object 的对象
        [[nodiscard]] virtual Object *getObject(const std::string &name) = 0;
    };

    class ObjectManager {
        std::unordered_map<std::string, std::stack<Object *>> objects{};
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

        /// 向 Manager 中添加一个 Object
        void addObject(const std::string &name, Object *object) {
            if(isDefined.top().contains(name)) {
                throw std::runtime_error("ObjectManager::addObject(): object already exists");
            }
        }

        Object* getObject(const std::string &name) {
            const auto it = objects.find(name);
            if(it == objects.end()) {
                throw std::runtime_error("ObjectManager::getObject(): object not found");
            }
            return it->second.top();
        }
    };

    class Context {
        int _deep = 0;

    public:
        llvm::LLVMContext &llvm_context;
        std::unique_ptr<llvm::Module> module;
        llvm::IRBuilder<> builder;
        StmtManager stmtManager;
        OpManager opManager;
        ObjectManager objectManager;
        llvm::IRBuilder<> llvmBuilder;

        explicit Context(llvm::LLVMContext &context): llvm_context(context), module(new llvm::Module("", context)), builder(context),
                                                                                 opManager(context), objectManager(this), llvmBuilder(context) {
        }

    public:
        inline void push() {
            _deep++;
        }

        inline void pop() {
            if(_deep == 0) {
                throw std::runtime_error("Cannot pop from an empty context");
            }
            _deep--;
        }

        inline unsigned long long deep() const {
            return _deep;
        }
    };
}// namespace Riddle
