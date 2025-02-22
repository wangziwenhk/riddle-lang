module;
#include <any>
#include <llvm/IR/LLVMContext.h>
#include <ranges>
export module IR.Moudule;
import Parsing.GramAnalysis;
import Semantics.SemAnalysis;
import Semantics.SemContext;
import Semantics.SemNode;
import IR.GenCode;
import Support.Unit;
export namespace Riddle {
    class Module {
    public:
        GenContext context;
        GramAnalysis gram;
        SemAnalysis sem;
        Unit &unit;
        ProgramNode *programNode = nullptr;
        std::string name;
        Module(llvm::LLVMContext *llvm_ctx, Unit &unit): context(llvm_ctx, unit.getPackName()),
                                                                  unit(unit) {
            name = unit.getPackName();
        }

        void start() {
            programNode = std::any_cast<ProgramNode *>(gram.visit(unit.parseTree));
            sem.visit(programNode);
            GenCode gen(context,unit);
            gen.visit(programNode);
        }

        void import(Module &lib) {
            const auto sem_lib_module = new SemModule(lib.name);
            for(auto val: lib.sem.getSemContext().getAllObjects() | std::views::values) {
                sem_lib_module->addObject(val.top().get());
            }
            sem.getSemContext().addSemObject(sem_lib_module);

            const auto gen_lib_module = new GenModule(lib.name);
            // gen 部分的合并
            for(auto i: lib.context.getAllObjects() | std::ranges::views::values) {
                const auto obj = i.top();
                gen_lib_module->addObject(obj);
            }
            context.addObject(gen_lib_module);
        }
    };
}// namespace Riddle