module;
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <llvm/IR/IRBuilder.h>
#include <stack>
#include <unordered_set>
export module IR.Context;
import Manager.StmtManager;
import Manager.OpManager;
import Type.Modifier;
import Tools.Allocator;
import Type.Identifier;

export namespace Riddle {
    class Class;
    class Variable;
    class ObjectManager;
    class Context {
        int _deep = 0;
        std::stack<Class *> classStack;
        int classStackDepth = 0;

    public:
        llvm::LLVMContext &llvm_context;
        std::unique_ptr<llvm::Module> module;
        llvm::IRBuilder<> builder;
        StmtManager stmtManager;
        OpManager opManager;
        ObjectManager *objectManager;
        llvm::IRBuilder<> llvmBuilder;


        explicit Context(llvm::LLVMContext &context);

    public:
        inline void push();

        inline void pop();

        inline unsigned long long deep() const {
            return _deep;
        }

        void pushNowClass(Class *theClass) {
            classStack.push(theClass);
        }

        Class *getNowClass() {
            if(classStack.empty()) {
                throw std::runtime_error("Cannot get now class from an empty context");
            }
            return classStack.top();
        }

        void popNowClass() {
            if(classStack.empty()) {
                throw std::runtime_error("Cannot get now class from an empty context");
            }
            classStack.pop();
        }
    };

    class Object {
    public:
        enum ObjectTypeID {
            /// constant type id
            IntegerTyID,
            FloatTyID,
            DoubleTyID,
            BooleanTyID,
            VoidTyID,
            StringLiteralTyID,

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
        Modifier modifier{};
        std::string name;
        std::shared_ptr<Context> ctx = nullptr;

        Object() = delete;

        Object(const ObjectTypeID &type_id, Context *ctx, std::string name): objectTypeID(type_id), name(std::move(name)), ctx(ctx) {}
        virtual ~Object() = default;

        /// 获取 Object 类型的 ID
        [[nodiscard]] ObjectTypeID getObjectTypeID() const {
            return objectTypeID;
        }

        /// 获取 Object 的对象
        [[nodiscard]] virtual Object *getObject(const std::string &name) = 0;

        [[nodiscard]] virtual bool isType() {
            return false;
        }
    };

    /// 用来表示类型
    class Type : public Object {
    public:
        Type(const ObjectTypeID id, Context *ctx): Object(id, ctx, "__type") {}

        virtual bool isClassTy() {
            return false;
        }

        Object *getObject(const std::string &name) override {
            throw std::runtime_error("Type not implemented");
        }

        bool isType() override {
            return true;
        }

        virtual llvm::Type *toLLVM();
        /// 实例化本类
        virtual Variable *Instantiate();
        /// 实例化本类
        /// @param name 变量名称
        virtual Variable *Instantiate(const std::string &name);

        virtual bool isVoidTy() {
            return false;
        }
    };

    class IntegerTy final : public Type {
    public:
        explicit IntegerTy(Context *ctx): Type(IntegerTyID, ctx) {}

        llvm::Type *toLLVM() override {
            return llvm::Type::getInt32Ty(ctx->llvm_context);
        }
    };

    class FloatTy final : public Type {
    public:
        explicit FloatTy(Context *ctx): Type(FloatTyID, ctx) {}

        llvm::Type *toLLVM() override {
            return llvm::Type::getFloatTy(ctx->llvm_context);
        }
    };

    class DoubleTy final : public Type {
    public:
        explicit DoubleTy(Context *ctx): Type(DoubleTyID, ctx) {}
        llvm::Type *toLLVM() override {
            return llvm::Type::getDoubleTy(ctx->llvm_context);
        }
    };

    class BooleanTy final : public Type {
    public:
        explicit BooleanTy(Context *ctx): Type(BooleanTyID, ctx) {}
        llvm::Type *toLLVM() override {
            return llvm::Type::getInt1Ty(ctx->llvm_context);
        }
    };

    class StringLiteralTy final : public Type {
    public:
        explicit StringLiteralTy(Context *ctx): Type(StringLiteralTyID, ctx) {}
        llvm::Type *toLLVM() override {
            return ctx->builder.getPtrTy();
        }
    };

    class VoidTy final : public Type {
    public:
        explicit VoidTy(Context *ctx): Type(VoidTyID, ctx) {}
        llvm::Type *toLLVM() override {
            return llvm::Type::getVoidTy(ctx->llvm_context);
        }

        bool isVoidTy() override {
            return true;
        }
    };

    /// 常量
    class Constant final : public Object {
        Type *type;
        llvm::Value *value;

    public:
        Constant(Context *ctx, Type *type, llvm::Value *value): Object(ConstantTyID, ctx, "__constValue"), type(type), value(value) {}

        Object *getObject(const std::string &name) override {
            throw std::runtime_error("Constant not implemented");
        }

        [[nodiscard]] llvm::Value *toLLVM() const {
            return value;
        }
    };

    /// 表示一个被实例化的变量
    class Variable final : public Object {
        llvm::Value *var;
        Type *type;

    public:
        Variable(std::string name, Type *type, llvm::Value *var, Context *ctx): Object(VariableTyID, ctx, std::move(name)), var(var), type(type) {}

        ~Variable() override {
            delete type;
        }

        Object *getObject(const std::string &name) override;

        [[nodiscard]] Type *getType() const {
            return type;
        }

        [[nodiscard]] llvm::Value *toLLVM() const {
            return var;
        }
    };

    class Function final : public Object {
        llvm::Function *llvmFunc;
        Object *returnObject;
        std::vector<Variable *> parameters;
        bool isMethod;

    public:
        /// @param ctx 上下文
        /// @param name 函数名
        /// @param llvmFunc 具体函数实现
        /// @param returnType 返回值类型
        /// @param args 参数类型
        /// @param isMethod 是否为一个方法
        explicit Function(Context *ctx,// NOLINT(*-pro-type-member-init)
                          const std::string &name,
                          llvm::Function *llvmFunc,
                          Type *returnType,
                          const std::vector<Type *> &args,
                          const bool isMethod): Object(FunctionTyID, ctx, name),
                                                llvmFunc(llvmFunc), isMethod(isMethod) {
            auto it = llvmFunc->arg_begin();
            for(int i = 0; i < args.size(); ++i, ++it) {
                parameters.push_back(args[i]->Instantiate(it->getName().str()));
            }
            returnObject = returnType->Instantiate();
        }

        /// 这里获取到的 object 是返回值的object
        Object *getObject(const std::string &name) override {
            return returnObject->getObject(name);
        }

        [[nodiscard]] llvm::Value *createCall(const std::vector<llvm::Value *> &args, llvm::IRBuilder<> builder) const {
            return builder.CreateCall(llvmFunc->getFunctionType(), llvmFunc, args);
        }
    };

    class Class final : public Type {
        llvm::StructType *structTy;
        std::unordered_map<std::string, Type *> members;
        std::unordered_map<std::string, Function *> functions;

    public:
        explicit Class(Context *ctx,
                       const std::string &name,
                       const std::vector<std::pair<std::string, Type *>> &member): Type(ClassTyID, ctx) {
            structTy = llvm::StructType::create(ctx->llvm_context);
            structTy->setName(name);
            // 设置成员
            std::vector<llvm::Type *> memberTypes;
            for(auto &i: member) {
                memberTypes.push_back(i.second->toLLVM());
                members.insert(i);
            }
            structTy->setBody(memberTypes);
        }

        llvm::Type *toLLVM() override {
            return structTy;
        }

        /// @warning 无效的
        Object *getObject(const std::string &name) override {
            throw std::runtime_error("Class not implemented");
        }

        Type *getMember(const std::string &name) {
            const auto it = members.find(name);
            if(it == members.end()) {
                throw std::runtime_error("Member not found");
            }
            return it->second;
        }

        Function *getFunction(const std::string &name) {
            const auto it = functions.find(name);
            if(it == functions.end()) {
                throw std::runtime_error("Function not found");
            }
            return it->second;
        }

        bool isMethod(const std::string &name) const {
            return functions.contains(name);
        }

        bool isMember(const std::string &name) const {
            return members.contains(name);
        }
    };

    class Module final : public Object {
        std::unordered_map<std::string, Object *> members;

    public:
        Module(Context *ctx, const std::string &name): Object(ModuleTyID, ctx, name) {}

        Object *getObject(const std::string &name) override {
            const auto it = members.find(name);
            if(it == members.end()) {
                throw std::runtime_error("Member not found");
            }
            return it->second;
        }

        void addObject(const std::string &name, Object *obj) {
            if(members.contains(name)) {
                throw std::runtime_error("Member already exists");
            }
            members[name] = obj;
        }
    };

    class ObjectManager {
        std::unordered_map<std::string, std::stack<Object *>> objects{};
        std::stack<std::unordered_set<std::string>> isDefined;
        std::weak_ptr<Context> ctx{};

    public:
        explicit ObjectManager(const std::shared_ptr<Context> &ctx): ctx(ctx) {}

        void push() {
            isDefined.emplace();
        }

        void pop() {
            if(isDefined.empty()) {
                throw std::runtime_error("ObjectManager::pop(): empty stack");
            }
            for(const auto &i: isDefined.top()) {
                delete objects[i].top();
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
            isDefined.top().insert(name);
            objects[name].push(object);
        }

        // 单一获取
        Object *getObject(const std::string &name) {
            if(name.find('.') != std::string::npos) {
                return getObject(Identifier(name));
            }
            const auto it = objects.find(name);
            if(it == objects.end()) {
                throw std::runtime_error("ObjectManager::getObject(): object not found");
            }
            return it->second.top();
        }

        Object *getObject(const Identifier &id) {
            if(id.id.empty()) {
                throw std::runtime_error("ObjectManager::getObject(): identifier not found");
            }
            Object *t = getObject(id.id[0]);
            for(int i = 1; i < id.id.size(); i++) {
                t = t->getObject(id.id[i]);
            }
            return t;
        }

        Type *getType(const std::string &name) {
            Object *obj = getObject(name);
            if(!obj->isType()) {
                throw std::runtime_error("ObjectManager::getType(): object not type");
            }
            return dynamic_cast<Type *>(obj);
        }

        Type *getType(const Identifier &id) {
            Object *obj = getObject(id);
            if(!obj->isType()) {
                throw std::runtime_error("ObjectManager::getType(): object not type");
            }
            return dynamic_cast<Type *>(obj);
        }

        Class *getClass(const std::string &name) {
            Type *obj = getType(name);
            if(!obj->isClassTy()) {
                throw std::runtime_error("ObjectManager::getClass(): object not Class");
            }
            return dynamic_cast<Class *>(obj);
        }

        Class *getClass(const Identifier &id) {
            Type *obj = getType(id);
            if(!obj->isClassTy()) {
                throw std::runtime_error("ObjectManager::getClass(): object not Class");
            }
            return dynamic_cast<Class *>(obj);

        }
    };


}// namespace Riddle
namespace Riddle {
    Context::Context(llvm::LLVMContext &context): llvm_context(context), module(new llvm::Module("", context)), builder(context),
                                                  opManager(context), llvmBuilder(context) {
        const std::shared_ptr<Context> t(this);
        objectManager = new ObjectManager(t);
    }
    void Context::push() {
        objectManager->push();
        _deep++;
    }
    void Context::pop() {
        if(_deep == 0) {
            throw std::runtime_error("Cannot pop from an empty context");
        }
        objectManager->pop();
        _deep--;
    }
    llvm::Type *Type::toLLVM() {
        throw std::runtime_error("Type not implemented");
    }
    Variable *Type::Instantiate() {
        const auto var = ctx->builder.CreateAlloca(this->toLLVM());
        return new Variable("__tmp", this, var, ctx.get());
    }
    Variable *Type::Instantiate(const std::string &name) {
        const auto var = ctx->builder.CreateAlloca(this->toLLVM());
        return new Variable(name, this, var, ctx.get());
    }
    Object *Variable::getObject(const std::string &name) {
        if(!type->isClassTy()) {
            throw std::logic_error("Variable: Object is not a struct");
        }
        const auto cty = dynamic_cast<Class *>(type);
        if(cty->isMember(name)) {
            const auto memberTy = cty->getMember(name);
            const auto var = memberTy->Instantiate();
            return var;
        } else if(cty->isMethod(name)) {
            return cty->getFunction(name);
        } else {
            throw std::logic_error("Variable: Can't find Object");
        }
    }
}// namespace Riddle
