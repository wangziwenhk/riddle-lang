module;
#include <llvm/IR/IRBuilder.h>
export module ValueManager;
import Types.Value;
import Tools.Allocator;
export namespace Riddle {
    class ValueManager {
        llvm::IRBuilder<> &builder;
        Allocator &allocator;

    public:
        explicit ValueManager(llvm::IRBuilder<> &ctx, Allocator &allocator): builder(ctx), allocator(allocator) {}

        [[nodiscard]] Integer *getInteger(const int value) const {
            const auto it = new Integer(builder, value);
            allocator.addPtr(it);
            return it;
        }

        [[nodiscard]] Float *getFloat(const double value) const {
            const auto it = new Float(builder, value);
            allocator.addPtr(it);
            return it;
        }

        [[nodiscard]] String *getString(const std::string &value) const {
            const auto it = new String(builder, value);
            allocator.addPtr(it);
            return it;
        }

        [[nodiscard]] Bool *getBool(const bool value) const {
            const auto it = new Bool(builder, value);
            allocator.addPtr(it);
            return it;
        }
    };
}// namespace Riddle