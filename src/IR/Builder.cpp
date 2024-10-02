module;
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>
module IR.Builder;
import Type.Variable;
namespace Riddle {
    llvm::Value *Builder::createVariable(llvm::Type *type, llvm::Value *value, const std::string &name, const bool is_const){
        llvm::Value *var;
        // 对全局变量特判
        if(ctx->deep() <= 1) {
            llvm::Constant *CV = llvm::dyn_cast<llvm::Constant>(value);
            var = new llvm::GlobalVariable(ctx->module, type, is_const, llvm::GlobalVariable::LinkageTypes::ExternalLinkage, CV, name);
        } else {
            var = llvmBuilder.CreateAlloca(type, nullptr, name);
            llvmBuilder.CreateStore(value, var);
        }
        ctx->addVariable(Variable(name,var,is_const));
        return var;
    }

}