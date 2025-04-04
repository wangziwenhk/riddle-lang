module;
#include <any>
#include <map>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Linker/Linker.h>
#include <llvm/Transforms/Utils/Cloning.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <ranges>
#include <llvm/IR/Value.h>
export module Gen.Moudule;
import Parsing.GramAnalysis;
import Semantics.SemAnalysis;
import Semantics.SemContext;
import Semantics.SemNode;
import Support.Unit;
import Gen.NewGenContext;
import Gen.NewGenCode;
export namespace Riddle {
    class Module {
    public:
        NewGenContext context;
        GramAnalysis gram;
        SemAnalysis sem;
        Unit &unit;
        ProgramNode *programNode = nullptr;
        std::string name;

        Module(llvm::LLVMContext *llvm_ctx, Unit &unit): context(llvm_ctx, unit),
                                                         sem(unit.getPackName()), unit(unit) {
            name = unit.getPackName();
        }

        void start() {
            programNode = std::any_cast<ProgramNode *>(gram.visit(unit.parseTree));
            sem.visit(programNode);
            NewGenCode gen(context);
            gen.visit(programNode);
        }

        void import(Module &lib) {
            throw std::runtime_error("Not implemented");
        }
    };
} // namespace Riddle
