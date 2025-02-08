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

            // 处理函数参数
            std::vector<llvm::Type *> paramTypes;
            for(const auto i: node->args) {
                auto type = std::any_cast<llvm::Type *>(visit(i->type));
                paramTypes.push_back(type);
            }

            const auto funcType = llvm::FunctionType::get(returnType, paramTypes, false);
            const auto func = llvm::Function::Create(funcType, llvm::GlobalValue::ExternalLinkage, name, context.llvmModule.get());

            // 处理函数参数命名
            int index = 0;
            for(auto it = func->arg_begin(); it != func->arg_end(); ++it, ++index) {
                it->setName(node->args.at(index)->name);
            }

            const auto entry = llvm::BasicBlock::Create(context.llvmModule->getContext(), "entry", func);
            context.builder.SetInsertPoint(entry);

            context.push();

            for(const auto i: *node->body) {
                visit(i);
            }

            context.pop();
            return {};
        }

        std::any visitAlloca(AllocaNode *node) override {
            const auto type = std::any_cast<llvm::Type *>(visitType(node->type));
            llvm::Value* alloca = context.builder.CreateAlloca(type);
            node->alloca = alloca;
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
            const auto typ = dynamic_cast<GenClass *>(obj);
            return typ->getLLVMType();
        }
    };
}// namespace Riddle