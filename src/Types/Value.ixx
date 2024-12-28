module;
#include <string>
#include <utility>
export module Value;


export namespace Riddle {
    class Value {
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

        explicit Value(const ValueTyID id): ID(id) {}

        virtual ~Value() = default;
    };

    class Integer final : public Value {
        int value;

    public:
        explicit Integer(const int value): Value(IntTyID), value(value) {}

        int &getValue() {
            return value;
        }
    };

    class Float final : public Value {
        float value;

    public:
        explicit Float(const float value): Value(FloatTyID), value(value) {}
        float &getValue() {
            return value;
        }
    };

    class String final : public Value {
        std::string value;

    public:
        explicit String(std::string str): Value(StringTyID), value(std::move(str)) {}
    };

    class Bool final : public Value {
        bool value;

    public:
        explicit Bool(const bool value): Value(BoolTyID), value(value) {}
        bool &getValue() {
            return value;
        }
    };

    class Pointer final : public Value {
        Value value;

    public:
        explicit Pointer(const Value &value): Value(PtrTyID), value(value) {}
        Value &getValue() {
            return value;
        }
    };
}// namespace Riddle