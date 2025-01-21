module;
#include <llvm/Linker/Linker.h>
export module Tools.Linker;
import IR.Context;
export namespace Riddle {
    class ModuleLinker {
        ModuleLinker() = default;

        void linkModule(const Context & target, Context& lib) {
            // 合并模块
            llvm::Linker linker(*target.module);
            // ReSharper disable once CppTooWideScope
            const bool LinkError = linker.linkInModule(std::move(lib.module));

            if (LinkError) {
                throw std::runtime_error("Linking failed");
            }
            // 合并其他的
        }
    };
}// namespace Riddle