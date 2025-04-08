module;
#include <any>
#include <llvm/IR/LLVMContext.h>
#include <utility>
export module Generate.Module;
import Support.Package;
import Grammar.GramVisitor;
import Semantic.SemNode;
export namespace Riddle {
    class Module {
    public:
        Package pack;
        llvm::LLVMContext &context;
        std::unique_ptr<ProgramNode> program;
        Module(llvm::LLVMContext &context, Package pack): pack(std::move(pack)), context(context) {
        }

        void startBuild() {
            GramVisitor gram_visitor;
            gram_visitor.visit(pack.program);
            program = std::move(gram_visitor.root);
        }
    };
} // namespace Riddle
