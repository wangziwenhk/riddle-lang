module;
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <llvm/IR/IRBuilder.h>
#include <memory>
#include <stack>
#include <unordered_set>
export module IR.Context;
import Manager.StmtManager;
import Manager.OpManager;
import Type.Modifier;
import Tools.Allocator;
import Type.Identifier;

export namespace Riddle {
    class Type;
    class Class;
    class Value;
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
        ~Context();

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

        void initBaseTypes();
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
            ValueTyID,
            FunctionTyID,
            ModuleTyID,
            ClassTyID,
        };

    protected:
        ObjectTypeID objectTypeID;

    public:
        // ReSharper disable once CppDFANotInitializedField
        Modifier modifier{};
        // ReSharper disable once CppDFANotInitializedField
        std::string name;
        Context* ctx = nullptr;

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

        [[nodiscard]] virtual bool isVariable() {
            return false;
        }

        [[nodiscard]] virtual bool isFunction() {
            return false;
        }

        virtual Type *getType() = 0;
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

        Type *getType() override {
            return this;
        }

        virtual llvm::Type *toLLVM();
        /// 实例化本类
        virtual Value *Instantiate();
        /// 实例化本类
        /// @param name 变量名称
        virtual Value *Instantiate(const std::string &name);

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

    class Value final : public Object {
    public:
        Value(Context *ctx,
              const std::string &name,
              llvm::Value *value,
              Type *type): Object(ValueTyID, ctx, name), type(type), value(value) {}

        Value(Context *ctx,
              llvm::Value *value,
              Type *type): Object(ValueTyID, ctx, "__tmp"), type(type), value(value) {}

        ~Value() override = default;

    protected:
        Type *type;
        llvm::Value *value;

    public:
        [[nodiscard]] llvm::Value *toLLVM() const {
            return value;
        }

        Type *getType() override {
            return type;
        }

        Object *getObject(const std::string &name) override;
    };

    class Function final : public Object {
        llvm::Function *llvmFunc;
        Type *returnType;
        std::vector<Value *> parameters;
        Modifier modifier;
        bool isMethod;

    public:
        /// @param ctx 上下文
        /// @param name 函数名
        /// @param llvmFunc 具体函数实现
        /// @param returnType 返回值类型
        /// @param args 参数类型
        /// @param modifier 函数修饰符
        /// @param isMethod 是否为一个方法
        explicit Function(Context *ctx,// NOLINT(*-pro-type-member-init)
                          const std::string &name,
                          llvm::Function *llvmFunc,
                          Type *returnType,
                          const std::vector<Type *> &args = {},
                          const Modifier modifier = {},
                          const bool isMethod = false): Object(FunctionTyID, ctx, name),
                                                        llvmFunc(llvmFunc), returnType(returnType),
                                                        modifier(modifier), isMethod(isMethod) {
            auto it = llvmFunc->arg_begin();
            for(int i = 0; i < args.size(); ++i, ++it) {
                parameters.push_back(args[i]->Instantiate(it->getName().str()));
            }
        }

        /// 这里获取到的 object 是返回值的object
        Object *getObject(const std::string &name) override {
            return returnType->getObject(name);
        }

        [[nodiscard]] llvm::Value *createCall(const std::vector<llvm::Value *> &args, llvm::IRBuilder<> builder) const {
            return builder.CreateCall(llvmFunc->getFunctionType(), llvmFunc, args);
        }

        /// 这里实际上获取到的是 returnType
        Type *getType() override {
            return returnType;
        }

        bool isFunction() override {
            return true;
        }

        [[nodiscard]] llvm::FunctionCallee getCallee() const {
            return llvmFunc;
        }
    };

    class Class final : public Type {
        llvm::StructType *structTy;
        std::unordered_map<std::string, std::pair<Type *, size_t>> members;
        std::unordered_map<std::string, Function *> functions;

    public:
        explicit Class(Context *ctx,
                       const std::string &name,
                       const std::vector<std::pair<std::string, Type *>> &member): Type(ClassTyID, ctx) {
            structTy = llvm::StructType::create(ctx->llvm_context);
            structTy->setName(name);
            size_t cnt = 0;
            for(const auto &[name, type]: member) {
                members.insert({name, {type, cnt}});
                cnt++;
            }
            updateStructTy();
        }

        void updateStructTy() {
            std::vector<llvm::Type *> memberTypes;
            memberTypes.reserve(members.size());
            for(auto &i: members) {
                memberTypes.push_back(i.second.first->toLLVM());
                members.insert(i);
            }
            structTy->setBody(memberTypes);
        }

        /// 向类中添加成员
        ///
        /// 你应该在执行完成该函数后 update 结构体
        void addMember(const std::string &name, Type *type) {
            if(members.contains(name)) {
                throw std::runtime_error("Member '" + name + "' already exists");
            }
            members[name].first = type;
            members[name].second = members.size();
        }

        /// 向类中添加方法
        void addFunction(const std::string &name, Function *function) {
            if(functions.contains(name)) {
                throw std::runtime_error("Function '" + name + "' already exists");
            }
            functions[name] = function;
        }

        llvm::Type *toLLVM() override {
            if(structTy->elements().size() != members.size()) {
                throw std::runtime_error("StructTy doesn't have the same number of members");
            }
            return structTy;
        }

        const auto &getAllMembers() const {
            return members;
        }

        const auto &getAllFunctions() const {
            return functions;
        }

        size_t getMemberSize() const {
            return members.size();
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
            return it->second.first;
        }

        size_t getMemberIndex(const std::string &name) {
            const auto it = members.find(name);
            if(it == members.end()) {
                throw std::runtime_error("Member not found");
            }
            return it->second.second;
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

        Type *getType() override {
            throw std::runtime_error("Type not implemented");
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

        Type *getType() override {
            throw std::runtime_error("Type not implemented");
        }
    };

    class ObjectManager {
        std::unordered_map<std::string, std::stack<Object *>> objects{};
        std::stack<std::unordered_set<std::string>> isDefined;

    public:
        explicit ObjectManager() = default;

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

        Value *getVariable(const std::string &name) {
            Object *obj = getObject(name);
            if(!obj->isVariable()) {
                throw std::runtime_error("ObjectManager::getValue(): object not variable");
            }
            return dynamic_cast<Value *>(obj);
        }

        Value *getVariable(const Identifier &id) {
            Object *obj = getObject(id);
            if(!obj->isVariable()) {
                throw std::runtime_error("ObjectManager::getValue(): object not variable");
            }
            return dynamic_cast<Value *>(obj);
        }

        Value *getValue(const std::string &name) {
            Object *obj = getObject(name);
            return dynamic_cast<Value *>(obj);
        }

        Value *getValue(const Identifier &id) {
            Object *obj = getObject(id);
            return dynamic_cast<Value *>(obj);
        }

        Function *getFunction(const std::string &name) {
            Object *obj = getObject(name);
            if(!obj->isFunction()) {
                throw std::runtime_error("ObjectManager::getFunction(): object not function");
            }
            return dynamic_cast<Function *>(obj);
        }

        Function *getFunction(const Identifier &id) {
            Object *obj = getObject(id);
            if(!obj->isFunction()) {
                throw std::runtime_error("ObjectManager::getFunction(): object not function");
            }
            return dynamic_cast<Function *>(obj);
        }
    };


}// namespace Riddle
namespace Riddle {
    Context::Context(llvm::LLVMContext &context): llvm_context(context), module(new llvm::Module("", context)), builder(context),
                                                  opManager(context), objectManager(new ObjectManager()), llvmBuilder(context) {
    }
    Context::~Context() {
        delete objectManager;
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
    void Context::initBaseTypes() {
        objectManager->addObject("int", new IntegerTy(this));
        objectManager->addObject("float", new FloatTy(this));
        objectManager->addObject("double", new DoubleTy(this));
        objectManager->addObject("bool", new BooleanTy(this));
        objectManager->addObject("void", new VoidTy(this));
    }
    llvm::Type *Type::toLLVM() {
        throw std::runtime_error("Type not implemented");
    }
    Value *Type::Instantiate() {
        llvm::Type *type = this->toLLVM();
        const auto var = ctx->builder.CreateAlloca(type);
        return new Value(ctx, "__tmp", var, this);
    }
    Value *Type::Instantiate(const std::string &name) {
        const auto var = ctx->builder.CreateAlloca(this->toLLVM());
        return new Value(ctx, name, var, this);
    }
    Object *Value::getObject(const std::string &name) {
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
