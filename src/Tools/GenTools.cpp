#include "GenTools.h"
#include "../Setup.h"
#include "RiddleLexer.h"

namespace Riddle {
    bool isTerminalNode(antlr4::tree::ParseTree *tree) {
        return dynamic_cast<antlr4::tree::TerminalNode *>(tree) != nullptr;
    }
    bool isIdentifier(antlr4::tree::ParseTree *tree) {
        if(isTerminalNode(tree)) {
            if (const antlr4::tree::TerminalNode *terminalNode = dynamic_cast<antlr4::tree::TerminalNode *>(tree)) {
                const antlr4::Token *token = terminalNode->getSymbol();
                return token->getType() == RiddleLexer::Identifier;
            }
        }
        return false;
    }

    llvm::Type *getSampleType(const std::string &type, llvm::IRBuilder<> &Builder){
        const auto it = SampleType.find(type);
        if(it == SampleType.end()) {
            throw std::logic_error("There is no such type");
        }
        return it->second(Builder);
    }

    bool isSampleType(const std::string &type){
        return SampleType.contains(type);
    }

    std::string getTypeName(llvm::Type *type) {
        if(type->isIntegerTy(1)) {
            return "bool";
        }
        if (type->isIntegerTy(8)) {
            return "char";
        }
        if (type->isIntegerTy(16)) {
            return "short";
        }
        if (type->isIntegerTy(32)) {
            return "int";
        }
        if (type->isFloatTy()) {
            return "float";
        }
        if (type->isDoubleTy()) {
            return "double";
        }
        if (type->isStructTy()) {
            const auto structTy = llvm::cast<llvm::StructType>(type);
            return structTy->getName().str();
        }
        if (type->isArrayTy()) {
            return "array";
        }
        if (type->isPointerTy()) {
            return "pointer";
        }
        //遇不到的判断
        throw std::logic_error("This type cannot be recognized");
    }

    bool isArray(llvm::Value *var){
        if (const llvm::AllocaInst *AI = dyn_cast<llvm::AllocaInst>(var)) {
            return AI->isArrayAllocation();
        }
        return var->getType()->isArrayTy();
    }

}// namespace Riddle