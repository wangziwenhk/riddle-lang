module;
#include <any>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <utility>
export module Generate.Module;
import Support.Package;
import Grammar.GramVisitor;
import Semantic.SemNode;
import Semantic.SemAnalysis;
import Generate.GenCode;
import Config.LLVMConfig;
export namespace Riddle {
    class Module {
    public:
        Package pack;
        std::shared_ptr<ProgramNode> program;
        llvm::LLVMContext &llvm_context = globalContext;
        std::unique_ptr<llvm::Module> llvm_module;

        explicit Module(Package pack): pack(std::move(pack)) {
            this->llvm_module = std::make_unique<llvm::Module>(this->pack.getName(), llvm_context);
        }

        void startBuild() {
            GramVisitor gram_visitor;
            program = std::any_cast<std::shared_ptr<ProgramNode>>(gram_visitor.visit(pack.program));
            SemAnalysis sem_analysis;
            sem_analysis.visit(program.get());
            GenCode gen_code(llvm_context,*llvm_module);
            gen_code.visit(program.get());
        }
    };
} // namespace Riddle
