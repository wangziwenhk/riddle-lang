module;
#include <llvm/IR/Function.h>
#include <llvm/Linker/Linker.h>
export module Support.Linker;
import IR.Context;
export namespace Riddle {
    class Linker {
        Linker() = default;

    public:
        /// @brief 合并模块
        ///
        /// 当合并完成后，lib 将失效
        /// @param target 目标模块
        /// @param lib 库
        static void linkContext(Context &target, Context &lib) {
            llvm::Linker linker(*target.module);
            // ReSharper disable once CppTooWideScope
            const bool LinkError = linker.linkInModule(std::move(lib.module));

            if(LinkError) {
                throw std::runtime_error("Linking failed");
            }
            throw std::runtime_error("Linking succeeded");
        }
    };
}// namespace Riddle