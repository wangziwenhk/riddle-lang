module;
#include <llvm/IR/Constants.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>
#include <string>
#include <utility>
export module Types.Value;

export namespace Riddle {
    class Value {
    protected:
        llvm::IRBuilder<> &builder;

    public:
        enum ValueTyID {
            IntTyID,
            FloatTyID,
            StringTyID,
            BoolTyID,
            StructTyID,
            PtrTyID,
        };

        ValueTyID ID;

        explicit Value(llvm::IRBuilder<> &builder, const ValueTyID id): builder(builder), ID(id) {}

        virtual ~Value() = default;
        virtual llvm::Value *toLLVM() = 0;
    };

    class Integer final : public Value {
        int value;

    public:
        explicit Integer(llvm::IRBuilder<> &builder, const int value): Value(builder, IntTyID), value(value) {}

        int &getValue() {
            return value;
        }

        llvm::Value *toLLVM() override {
            return builder.getInt32(value);
        }
    };

    class Float final : public Value {
        double value;

    public:
        explicit Float(llvm::IRBuilder<> &builder, const double value): Value(builder, FloatTyID), value(value) {}
        double &getValue() {
            return value;
        }

        llvm::Value *toLLVM() override {
            const auto doubleTy = builder.getDoubleTy();
            return llvm::ConstantFP::get(doubleTy, value);
        }
    };

    class String final : public Value {
        std::string value;

    public:
        explicit String(llvm::IRBuilder<> &builder, std::string str): Value(builder, StringTyID), value(std::move(str)) {}

        std::string &getValue() {
            return value;
        }

        llvm::Value *toLLVM() override {
            return builder.CreateGlobalStringPtr(value);
        }
    };

    class Bool final : public Value {
        bool value;

    public:
        explicit Bool(llvm::IRBuilder<> &builder, const bool value): Value(builder, BoolTyID), value(value) {}
        bool &getValue() {
            return value;
        }

        llvm::Value *toLLVM() override {
            return builder.getInt1(value);
        }
    };

    class Pointer final : public Value {
        Value *value;

    public:
        explicit Pointer(llvm::IRBuilder<> &builder, Value *value): Value(builder, PtrTyID), value(value) {}
        [[nodiscard]] Value *getValue() const {
            return value;
        }

        llvm::Value *toLLVM() override {
            llvm::Value *pointerTo = value->toLLVM();
            const auto type = llvm::PointerType::get(builder.getContext(), 0);
            return builder.CreatePointerCast(pointerTo, type);
        }
    };
}// namespace Riddle