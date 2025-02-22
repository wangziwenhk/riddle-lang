module;
#include <any>
#include <ranges>
export module IR.Moudule;
import Parsing.GramAnalysis;
import Semantics.SemAnalysis;
import Semantics.SemNode;
import IR.GenCode;
import Support.Unit;
export namespace Riddle {
    class Module {
    public:
        GenContext &context;
        GramAnalysis gram;
        SemAnalysis sem;
        GenCode gen;
        const Unit &unit;
        ProgramNode* programNode = nullptr;
        Module(GenContext &context, const Unit &unit): context(context), gen(context, unit), unit(unit) {}

        void start() {
            programNode = std::any_cast<ProgramNode *>(gram.visit(unit.parseTree));
            sem.visit(programNode);
            gen.visit(programNode);
        }

        void import(GenContext &lib) const {
            const auto lib_module = new GenModule(lib.name);
            for(auto i: lib.getAllObjects() | std::ranges::views::values) {
                const auto obj = i.top();
                lib_module->addObject(obj);
            }
            context.addObject(lib_module);
        }
    };
}// namespace Riddle