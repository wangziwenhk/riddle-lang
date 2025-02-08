module;
#include <any>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/Support/raw_ostream.h>
#include <vector>
export module IR.GenCode;
export import IR.GenContext;
import Semantics.SemNode;
import Types.Unit;
export namespace Riddle {
    class GenCode final : public SemNodeVisitor {
    protected:
        GenContext &context;
        const Unit &unit;

    public:
        explicit GenCode(GenContext &context, const Unit &unit): context(context), unit(unit) {}
        std::any visitProgram(ProgramNode *node) override {
            context.llvmModule->setModuleIdentifier(unit.getPackName());
            for(const auto i: *node->body) {
                visit(i);
            }
            context.llvmModule->print(llvm::outs(), nullptr);
            return {};
        }

        std::any visitFuncDefine(FuncDefineNode *node) override {
            const auto name = node->name;
            const auto returnType = std::any_cast<llvm::Type *>(visit(node->returnType));
            const auto funcType = llvm::FunctionType::get(returnType, false);
            const auto func = llvm::Function::Create(funcType, llvm::GlobalValue::ExternalLinkage, name, context.llvmModule.get());

            return {};
        }

        std::any visitType(TypeNode *node) override {
            const auto &name = node->name;
            static std::unordered_map<std::string, llvm::Type *> base_types = {
                    {"bool", llvm::Type::getInt1Ty(*context.llvmContext)},
                    {"int", llvm::Type::getInt32Ty(*context.llvmContext)},
                    {"float", llvm::Type::getDoubleTy(*context.llvmContext)},
                    {"double", llvm::Type::getDoubleTy(*context.llvmContext)},
                    {"void", llvm::Type::getVoidTy(*context.llvmContext)},
            };
            // 尝试获取基本类型
            if(base_types.contains(name)) {
                return base_types[name];
            }
            const auto obj = context.getObject(name);
            if(obj->getGenType() != GenObject::Class) {
                throw std::runtime_error("Object doesn't have a class");
            }
            const auto typ = dynamic_cast<GenClass*>(obj);
            return typ->getLLVMType();
        }
    };
}// namespace Riddle