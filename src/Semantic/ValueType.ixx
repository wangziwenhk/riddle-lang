module;
#include <llvm/IR/Type.h>
#include <memory>
#include <string>
#include <utility>
export module Semantic.ValueType;
export namespace Riddle {
    /**
     * 表示一个被实际解析的Type类型
     */
    class ValueType {
    public:
        explicit ValueType(std::string name): name(std::move(name)) {
        }
        std::string name;
        llvm::Type *llvm_type = nullptr;

        size_t pointerSize = 0;

        static auto create(std::string name = "") {
            return std::make_shared<ValueType>(std::move(name));
        }
    };

} // namespace Riddle
