module;
#include <iostream>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <memory>
#include <stack>
#include <utility>
export module Gen.NewGenContext;
import Support.Unit;
export namespace Riddle {
    class NewGenContext;
    class NewGenObject {
    public:
        enum NewGenObjectType : char {
            Variable,
            BaseType,
            ClassType,
            Module,
            Function,
            LLVMValue,
            Constant,
        };

    private:
        NewGenObjectType type;

    protected:
        explicit NewGenObject(NewGenContext &context, const NewGenObjectType id): type(id), context(context) {
        }

        NewGenContext &context;

    public:
        [[nodiscard]] NewGenObjectType getType() const {
            return type;
        }
        virtual ~NewGenObject() = default;
    };

    class NewGenType : public NewGenObject {
    protected:
        explicit NewGenType(NewGenContext &context, const NewGenObjectType id): NewGenObject(context, id) {
        }

    public:
        virtual llvm::Type *getLLVMType() noexcept = 0;
    };

    /**
     * 表示一个类的包装
     */
    class NewGenClassType final : public NewGenType {
        llvm::StructType *type;

    public:
        explicit NewGenClassType(NewGenContext &context, llvm::StructType *sty):
            NewGenType(context, ClassType), type(sty) {
        }

        llvm::StructType *getLLVMType() noexcept override {
            return type;
        }

        static NewGenClassType *create(NewGenContext &ctx, llvm::StructType *sty);

        void setLLVMType(llvm::StructType *ty) noexcept {
            type = ty;
        }
    };

    class NewGenBaseType final : public NewGenType {
        llvm::Type *type;

    public:
        explicit NewGenBaseType(NewGenContext &context, llvm::Type *ty): NewGenType(context, BaseType), type(ty) {
        }

        llvm::Type *getLLVMType() noexcept override {
            return type;
        }

        void setLLVMType(llvm::Type *ty) noexcept {
            type = ty;
        }

        static NewGenBaseType *create(NewGenContext &ctx, llvm::Type *sty);
    };

    class NewGenValue : public NewGenObject {
    protected:
        llvm::Value *llvm_value = nullptr;

    public:
        NewGenValue(NewGenContext &ctx, llvm::Value *value, const NewGenObjectType id = LLVMValue):
            NewGenObject(ctx, id), llvm_value(value) {
        }

        virtual llvm::Value *getLLVMValue() {
            return llvm_value;
        }
    };

    class NewGenConstant : public NewGenValue {
    protected:
        explicit NewGenConstant(NewGenContext &context): NewGenValue(context, nullptr, Constant) {
        }

        llvm::Value *getLLVMValue() override = 0;
    };

    class NewGenInteger final : public NewGenConstant {
    public:
        int value;
        explicit NewGenInteger(NewGenContext &context, const int value): NewGenConstant(context), value(value) {
        }

        llvm::Value *getLLVMValue() override;

        static NewGenInteger *create(NewGenContext &ctx, int value);
    };

    class NewGenContext {
        std::unordered_map<std::string, std::stack<NewGenObject *>> objects;
        std::stack<std::vector<std::string>> defined;
        std::unordered_map<std::string, llvm::Type *> base_types;
        std::vector<NewGenObject *> object_allocator;

    public:
        std::unique_ptr<llvm::Module> llvmModule;
        llvm::LLVMContext *llvmContext;
        llvm::IRBuilder<> builder;
        Unit unit;
        NewGenContext(llvm::LLVMContext *ctx, Unit unit):
            llvmModule(new llvm::Module(unit.getPackName(), *ctx)), llvmContext(ctx), builder(*llvmContext),
            unit(std::move(unit)) {
            push();
            base_types = {{"long", builder.getInt64Ty()},  {"int", builder.getInt32Ty()},
                          {"short", builder.getInt8Ty()},  {"char", builder.getInt8Ty()},
                          {"float", builder.getFloatTy()}, {"double", builder.getDoubleTy()},
                          {"void", builder.getVoidTy()}};
        }

        ~NewGenContext() {
            pop();
            for (const auto i: object_allocator) {
                delete i;
            }
        }

        /**
         * 作用域提升
         */
        void push() {
            defined.emplace();
        }

        /**
         * 作用域下降
         */
        void pop() {
            if (defined.empty()) {
                throw std::runtime_error("Empty stack");
            }
            for (const auto &i: defined.top()) {
                auto it = objects.find(i);
                if (it == objects.end()) {
                    throw std::runtime_error("Object not found while pushing out scope");
                }
                it->second.pop();
                if (it->second.empty()) {
                    objects.erase(i);
                }
            }
        }

        llvm::Type *getBaseType(const std::string &name) {
            const auto it = base_types.find(name);
            if (it == base_types.end()) {
                throw std::runtime_error("Can't find base type");
            }
            return it->second;
        }

        void addGenObject(NewGenObject *obj) {
            object_allocator.emplace_back(obj);
        }

        NewGenObject *getGlobalObject(const std::string &name) {
            const auto it = objects.find(name);
            if (it == objects.end() || it->second.empty()) {
                throw std::runtime_error("Can't find global object");
            }
            return it->second.top();
        }
    };
} // namespace Riddle
