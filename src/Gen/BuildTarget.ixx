module;
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/TargetParser/Host.h>
export module Gen.BuildTarget;

export namespace Riddle {
    class BuildTarget {
    public:
        std::unique_ptr<llvm::TargetMachine> TM = nullptr;
        bool isExpect = false;

        BuildTarget() {
            const auto cpu = llvm::sys::getHostCPUName();
            const auto TargetTriple = llvm::sys::getDefaultTargetTriple();
            std::string Error;
            const auto Features = "";
            const auto Target = llvm::TargetRegistry::lookupTarget(TargetTriple, Error);
            const llvm::TargetOptions Opt;
            constexpr auto RM = std::optional<llvm::Reloc::Model>();
            TM.reset(Target->createTargetMachine(TargetTriple, cpu, Features, Opt, RM));
        }

        void resetTarget(const std::string &TargetTriple, const std::string &cpu = llvm::sys::getHostCPUName().str()) {
            std::string Error;
            const auto Features = "";
            const auto Target = llvm::TargetRegistry::lookupTarget(TargetTriple, Error);
            const llvm::TargetOptions Opt;
            constexpr auto RM = std::optional<llvm::Reloc::Model>();
            TM.reset(Target->createTargetMachine(TargetTriple, cpu, Features, Opt, RM));
        }
    };
} // namespace Riddle
