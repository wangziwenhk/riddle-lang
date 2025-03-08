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
                                                         sem(unit.getPackName()), unit(unit) {
            name = unit.getPackName();
        }

        void start() {
            programNode = std::any_cast<ProgramNode *>(gram.visit(unit.parseTree));
            sem.visit(programNode);
            GenCode gen(context, unit);
            gen.visit(programNode);
        }

        void import(Module &lib) {
            const auto sem_lib_module = new SemModule(lib.name);
            std::vector<SemClass *> sem_classes;
            for (auto val: lib.sem.getSemContext().getAllObjects() | std::views::values) {
                if (val.top().get()->getSemObjType() != SemObject::Class) {
                    sem_lib_module->addObject(val.top()->clone());
                } else {
                    sem_classes.push_back(dynamic_cast<SemClass *>(val.top()->clone()));
                }
            }
            sem.getSemContext().addSemObject(sem_lib_module);
            for (const auto i: sem_classes) {
                i->define->name = lib.name + "@" + i->define->name;
                sem.getSemContext().addSemObject(i);
            }

            const auto gen_lib_module = new GenModule(lib.name);
            // gen 部分的合并
            std::vector<GenClass *> gen_classes;
            for (auto i: lib.context.getAllObjects() | std::views::values) {
                const auto obj = i.top();
                gen_lib_module->addObject(obj->clone());
            }
            context.addObject(gen_lib_module);

            // link module
            llvm::ValueToValueMapTy vmap;
            auto cloneModule = CloneModule(*lib.context.llvmModule, vmap);
            llvm::Linker linker(*this->context.llvmModule);
            linker.linkInModule(std::move(cloneModule));

            // 替换所有原始克隆指针
            for (const auto i: gen_lib_module->getAllObjects() | std::views::values) {
                switch (i->getGenType()) {
                    case GenObject::Variable: {
                        const auto var = dynamic_cast<GenVariable *>(i);
                        if (!var->isGlobal) {
                            var->alloca->alloca = vmap[var->alloca->alloca];
                        } else {
                            const auto g = context.llvmModule->getGlobalVariable(var->name);
                            g->setInitializer(nullptr);
                            var->alloca->alloca = g;
                        }
                        break;
                    }
                    case GenObject::Function: {
                        const auto func = dynamic_cast<GenFunction *>(i);
                        func->define->body = nullptr;
                        func->getLLVMFunction() = llvm::dyn_cast<llvm::Function>(context.llvmModule->getOrInsertFunction(
                            func->name, func->getLLVMFunction()->getFunctionType()).getCallee());
                        if (func->getLLVMFunction() != nullptr) {
                            func->getLLVMFunction()->deleteBody();
                        }

                        break;
                    }
                    case GenObject::Class: {
                        const auto cls = dynamic_cast<GenClass *>(i);
                        cls->setName(cls->define->buildName);
                    }
                    default: {
                        break;
                    }
                }
            }
        }
    };
} // namespace Riddle
