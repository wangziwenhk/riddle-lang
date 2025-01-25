module;
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <map>
#include <string>
#include <utility>
export module IR.Objects;
import Type.Modifier;
import IR.Context;
export namespace Riddle {
    class Variable;
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

        virtual llvm::Type *toLLVM();
        /// 实例化本类
        virtual Variable *Instantiate();
        /// 实例化本类
        /// @param name 变量名称
        virtual Variable *Instantiate(const std::string &name);
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
        explicit StringLiteralTy(Context *ctx): Type(BooleanTyID, ctx) {}
        llvm::Type *toLLVM() override {
            return ctx->builder.getPtrTy();
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
}// namespace Riddle
namespace Riddle {
    llvm::Type *Type::toLLVM() {
        throw std::runtime_error("Type not implemented");
    }
    Variable *Type::Instantiate() {
        const auto var = ctx->builder.CreateAlloca(this->toLLVM());
        return new Variable("__tmp", this, var, ctx);
    }
    Variable *Type::Instantiate(const std::string &name) {
        const auto var = ctx->builder.CreateAlloca(this->toLLVM());
        return new Variable(name, this, var, ctx);
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