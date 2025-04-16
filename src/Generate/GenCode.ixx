module;
#include <any>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
export module Generate.GenCode;
import Semantic.SemNode;
import Config.LLVMConfig;
import Config.BaseType;
export namespace Riddle {
    class GenCode final : public SemVisitor {
        std::unordered_map<std::string,llvm::Type*> base_types;
    public:
        llvm::LLVMContext &llvm_context;
        llvm::Module &llvm_module;
        llvm::IRBuilder<> builder;

        explicit GenCode(llvm::LLVMContext &llvm_context, llvm::Module &llvm_module):
            llvm_context(llvm_context), llvm_module(llvm_module), builder(llvm_context) {
            base_types = {
                {"int",builder.getInt32Ty()},
                {"short",builder.getInt16Ty()},
                {"long",builder.getInt64Ty()},
                {"char",builder.getInt8Ty()},
                {"bool",builder.getInt1Ty()},
                {"void",builder.getVoidTy()},
                {"double",builder.getDoubleTy()},
                {"float",builder.getFloatTy()},
            };
        }

        std::any visitProgram(ProgramNode *node) override {
            for (const auto &i: node->children) {
                visit(i.get());
            }
            this->llvm_module.print(llvm::outs(), nullptr);
            return {};
        }

        std::any visitInteger(IntegerNode *node) override {
            node->llvm_value = builder.getInt32(node->value);
            return {};
        }

        std::any visitFloat(FloatNode *node) override {
            node->llvm_value = llvm::ConstantFP::get(builder.getFloatTy(), 3.14);
            return {};
        }

        std::any visitBoolean(BooleanNode *node) override {
            node->llvm_value = builder.getInt1(node->value);
            return {};
        }

        std::any visitChar(CharNode *node) override {
            node->llvm_value = builder.getInt16(node->value);
            return {};
        }

        std::any visitBlock(BlockNode *node) override {
            for (const auto &i: node->children) {
                visit(i.get());
            }
            return {};
        }

        std::any visitType(TypeNode *node) override {
            if (node->select == ObjectNode::Base) {
                node->type->llvm_type = base_types.at(node->name);
            }
            return {};
        }

        std::any visitFuncDecl(FuncDeclNode *node) override {
            visit(node->returnType.get());
            node->funcTy = llvm::FunctionType::get(node->returnType->type->llvm_type, false);
            node->func =
                    llvm::Function::Create(node->funcTy, llvm::GlobalValue::ExternalLinkage, node->name, llvm_module);
            return {};
        }
    };
} // namespace Riddle
