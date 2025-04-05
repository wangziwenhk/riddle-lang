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
    class NewGenObject {
    public:
        enum NewGenObjectType : char {
            Variable,
            BaseType,
            ClassType,
            Module,
            Function,
            TempLLVMValue,
        };

    private:
        NewGenObjectType type;

    public:
        explicit NewGenObject(const NewGenObjectType type): type(type) {
        }

        [[nodiscard]] NewGenObjectType getType() const {
            return type;
        }
    };

    class NewGenType : public NewGenObject {
    public:
        explicit NewGenType(const NewGenObjectType type): NewGenObject(type) {
        }

        virtual ~NewGenType() = default;

        virtual llvm::Type *getLLVMType() noexcept = 0;
    };

    class NewGenClassType final : public NewGenType {
        llvm::StructType *type;

    public:
        explicit NewGenClassType(llvm::StructType *sty): NewGenType(ClassType), type(sty) {
        }

        llvm::StructType *getLLVMType() noexcept override {
            return type;
        }
    };

    class NewGenBaseType final : public NewGenType {
        llvm::Type *type;

    public:
        explicit NewGenBaseType(llvm::Type *ty): NewGenType(BaseType), type(ty) {
        }
        llvm::Type *getLLVMType() noexcept override {
            return type;
        }
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
    };
} // namespace Riddle
