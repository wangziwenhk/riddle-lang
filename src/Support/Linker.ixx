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
            // 合并 stmtManager
            for(auto& i: lib.stmtManager.getAllStmt()) {
                target.stmtManager.getAllStmt().push_back(i);
                i = nullptr;
            }
            // 合并 objectManager
            for(auto [name, stk]: lib.objectManager->getObjects()) {
                if(lib.baseTypeMap.contains(name)) {
                    continue;
                }
                if(target.objectManager->isFactObject(name)) {
                    throw std::runtime_error("Object '" + name + "' already exists");
                }
                stk.top()->setContext(&target);
                target.objectManager->addObject(name, stk.top());
            }
            target.isLinked = true;
        }
    };
}// namespace Riddle