module;
#include <any>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Linker/Linker.h>
#include <llvm/Transforms/Utils/Cloning.h>
#include <ranges>
export module Gen.Moudule;
import Parsing.GramAnalysis;
import Semantics.SemAnalysis;
import Semantics.SemContext;
import Semantics.SemNode;
import Gen.GenCode;
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
            for(auto i: lib.context.getAllObjects() | std::views::values) {
                const auto obj = i.top();
                gen_lib_module->addObject(obj->clone());
            }
            context.addObject(gen_lib_module);

            // link module
            llvm::ValueToValueMapTy vmap;
            auto cloneModule = CloneModule(*lib.context.llvmModule,vmap);
            llvm::Linker linker(*this->context.llvmModule);
            linker.linkInModule(std::move(cloneModule));

            // 替换所有原始克隆指针
            for(const auto i:gen_lib_module->getAllObjects() | std::views::values) {
                switch(i->getGenType()) {
                    case GenObject::Variable: {
                        const auto var = dynamic_cast<GenVariable*>(i);
                        if(!var->isGlobal) {
                            var->alloca->alloca = vmap[var->alloca->alloca];
                        }
                        else {
                            var->alloca->alloca = context.llvmModule->getGlobalVariable(var->name);
                        }
                        break;
                    }
                    case GenObject::Function: {
                        const auto func = dynamic_cast<GenFunction*>(i);
                        func->llvmFunction = context.llvmModule->getFunction(func->name);
                        break;
                    }
                    // case GenObject::Class: {
                    //     const auto cls = dynamic_cast<GenClass*>(i);
                    //     cls->type = context.m;
                    // }
                    default: {
                        break;
                    }
                }
            }
        }
    };
}// namespace Riddle