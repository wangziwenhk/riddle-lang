module;
#include <llvm/IR/IRBuilder.h>
export module Manager.ValueManager;
import Types.Value;
import Tools.Allocator;
export namespace Riddle {
    class ValueManager {
        llvm::IRBuilder<> &builder;
        Allocator<Value> allocator;

    public:
        explicit ValueManager(llvm::IRBuilder<> &ctx): builder(ctx) {}

        [[nodiscard]] Integer *getInteger(const int value) {
            const auto it = new Integer(builder, value);
            allocator.addPtr(it);
            return it;
        }

        [[nodiscard]] Float *getFloat(const double value) {
            const auto it = new Float(builder, value);
            allocator.addPtr(it);
            return it;
        }

        [[nodiscard]] String *getString(const std::string &value) {
            const auto it = new String(builder, value);
            allocator.addPtr(it);
            return it;
        }

        [[nodiscard]] Bool *getBool(const bool value) {
            const auto it = new Bool(builder, value);
            allocator.addPtr(it);
            return it;
        }

        [[nodiscard]] LLVMValue *getLLVMValue(llvm::Value *value, llvm::Type *type) {
            const auto it = new LLVMValue(builder, value, type);
            allocator.addPtr(it);
            return it;
        }
    };
}// namespace Riddle