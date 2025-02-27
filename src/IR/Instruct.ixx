module;
#include <iostream>
#include <string>
#include <utility>
#include <vector>
export module IR.Instruct;
export namespace Riddle {
    /**
     * 表示IR中的指令
     */
    class Instruct {
    public:
        enum InstructType {
            Alloca,
            Class,
            IntegerTy,
            FuncCall,
            Value,
        };
        virtual ~Instruct() = default;

        explicit Instruct(const InstructType type): type(type) {}

        [[nodiscard]] InstructType getInstType() const {
            return type;
        }

    protected:
        InstructType type;
    };

    /**
     * IR 中的类型表示
     */
    class TypeInst : public Instruct {
    protected:
        explicit TypeInst(const InstructType type,
                          std::string name): Instruct(type), name(std::move(name)) {}

    public:
        std::string name;
    };

    class IntegerTypeInst final : public TypeInst {
    public:
        /// 获取一个 32 bit 的整数类型
        IntegerTypeInst(): TypeInst(IntegerTy, "i32"), NumBits(32) {}
        explicit IntegerTypeInst(const unsigned int NumBits): TypeInst(IntegerTy, "i" + std::to_string(NumBits)),
                                                              NumBits(NumBits) {}

    private:
        unsigned int NumBits;
    };

    class ClassTypeInst final : public TypeInst {
    public:
        explicit ClassTypeInst(std::string name,
                               std::vector<TypeInst *> body): TypeInst(Class, std::move(name)),
                                                              body(std::move(body)) {}

        std::string getName() {
            return name;
        }

        std::vector<TypeInst *>::iterator body_begin() {
            return body.begin();
        }

        std::vector<TypeInst *>::iterator body_end() {
            return body.end();
        }

    protected:
        std::vector<TypeInst *> body;
    };

    class ValueInst final : public Instruct {
    public:
        explicit ValueInst(std::string name = ""): Instruct(Value), name(std::move(name)) {
            if(this->name.empty()) {
                this->name = std::to_string(count);
                count++;
            }
        }

        [[nodiscard]] std::string getName() const {
            return name;
        }

    protected:
        std::string name;
        static size_t count;
    };

    size_t ValueInst::count = 0;

    /**
     * 在栈上开辟一个变量的 IR 表示
     */
    class AllocaInst final : public Instruct {
    public:
        explicit AllocaInst(TypeInst *type, ValueInst *var): Instruct(Alloca), type(type), var(var) {}

        TypeInst *type;
        ValueInst *var;
    };

    class FuncCallInst final : public Instruct {
    public:
        explicit FuncCallInst(std::string funcName,
                              std::vector<ValueInst *> args = {}): Instruct(FuncCall),
                                                                   funcName(std::move(funcName)),
                                                                   args(std::move(args)) {}

        [[nodiscard]] std::string getFuncName() const {
            return funcName;
        }

        std::vector<ValueInst *> getArgs() {
            return args;
        }

        std::vector<ValueInst *>::iterator getArgBegin() {
            return args.begin();
        }

        std::vector<ValueInst *>::iterator getArgEnd() {
            return args.end();
        }

    protected:
        std::string funcName;
        std::vector<ValueInst *> args;
    };
}// namespace Riddle