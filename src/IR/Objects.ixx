module;
#include <llvm/IR/Function.h>
#include <map>
#include <string>
#include <utility>
export module IR.Objects;
import Type.Modifier;
import IR.Context;
export namespace Riddle {
    // 所有 object 的基本类型
    class Object {
    public:
        enum ObjectTypeID {
            /// constant type id
            IntegerTyID,
            FloatTyID,
            DoubleTyID,

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

    /// 用来表示类型
    class Type : public Object {
    public:
        Type(const ObjectTypeID id, Context *ctx): Object(id, ctx, "__type") {}

        virtual bool isClassTy() {
            return false;
        }

        virtual llvm::Type *toLLVM();
    };

    class IntegerTy : public Type {
    public:
        explicit IntegerTy(Context *ctx): Type(IntegerTyID, ctx) {}

        llvm::Type *toLLVM() override {
            return llvm::Type::getInt32Ty(ctx->llvm_context);
        }
    };

    class FloatTy : public Type {
    public:
        explicit FloatTy(Context *ctx): Type(FloatTyID, ctx) {}

        llvm::Type *toLLVM() override {
            return llvm::Type::getFloatTy(ctx->llvm_context);
        }
    };

    class DoubleTy : public Type {
    public:
        explicit DoubleTy(Context *ctx): Type(DoubleTyID, ctx) {}
        llvm::Type *toLLVM() override {
            return llvm::Type::getDoubleTy(ctx->llvm_context);
        }
    };

    class Class : public Type {
        llvm::StructType *structTy;
        std::unordered_map<std::string, Type *> members;

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
    };

    /// 表示一个被实例化的变量
    class Variable final : public Object {
        std::map<std::string, Object *> members;
        Type *type;

    public:
        Variable(std::string name, Type *type, Context *ctx);

        ~Variable() override {
            delete type;
        }

        Object *getObject(const std::string &name) override {
            if(!type->isClassTy()) {
                throw std::logic_error("Variable: Object is not a struct");
            }
            const auto it = members.find(name);
            if(it == members.end()) {
                throw std::logic_error("Variable: Member not found");
            }
            return it->second;
        }

        [[nodiscard]] Type *getType() const {
            return type;
        }

        void addMember(const std::string &name, Object *object) {
            if(!members.contains(name)) {
                throw std::logic_error("Variable: Member already exists");
            }
            members[name] = object;
        }
    };

}// namespace Riddle

module IR.Objects.INS;
export namespace Riddle {
    Variable::Variable(std::string name, Type *type, Context *ctx): Object(VariableTyID, ctx, std::move(name)), type(type) {
        throw std::logic_error("Variable: not implement");
    }
}// namespace Riddle