#include "GenTools.h"
#include "RiddleLexer.h"
#include <llvm/IR/Constants.h>

namespace Riddle {
    llvm::AllocaInst *initAlloca(std::string name, std::string type, llvm::IRBuilder<> &Builder) {
        llvm::AllocaInst *Alloca = nullptr;
        Alloca = Builder.CreateAlloca(getType(type, Builder), nullptr, name);
        return Alloca;
    }
    bool isTerminalNode(antlr4::tree::ParseTree *tree) {
        return dynamic_cast<antlr4::tree::TerminalNode *>(tree) != nullptr;
    }
    bool isIdentifier(antlr4::tree::ParseTree *tree) {
        if(isTerminalNode(tree)) {
            antlr4::tree::TerminalNode *terminalNode = dynamic_cast<antlr4::tree::TerminalNode *>(tree);
            if(terminalNode) {
                antlr4::Token *token = terminalNode->getSymbol();
                return token->getType() == RiddleLexer::Identifier;
            }
        }
        return false;
    }
    llvm::Type *getType(std::string type, llvm::IRBuilder<> &Builder) {
        if(type == "int")
            return Builder.getInt32Ty();
        else if(type == "float")
            return Builder.getFloatTy();
        else if(type == "double")
            return Builder.getDoubleTy();
        else if(type == "bool")
            return Builder.getInt1Ty();
        else if(type == "char")
            return Builder.getInt8Ty();
        else if(type == "array")
            return Builder.getPtrTy();
        throw std::logic_error("There is no such type");
    }
    std::vector<llvm::Type *> getTypes(std::vector<std::string> type, llvm::IRBuilder<> &Builder) {
        std::vector<llvm::Type *> result;
        for(auto i: type) {
            result.push_back(getType(i, Builder));
        }
        return result;
    }

    std::string getTypeName(llvm::Type *type) {
        if(type->isIntegerTy(1)) {
            return "bool";
        } else if(type->isIntegerTy(8)) {
            return "char";
        } else if(type->isIntegerTy(16)) {
            return "short";
        } else if(type->isIntegerTy(32)) {
            return "int";
        } else if(type->isFloatTy()) {
            return "float";
        } else if(type->isDoubleTy()) {
            return "double";
        } else if(type->isStructTy()) {
            auto structTy = llvm::cast<llvm::StructType>(type);
            return structTy->getName().str();
        } else if(type->isArrayTy()) {
            auto arrayTy = llvm::cast<llvm::ArrayType>(type);
            return "array";
        }
        //遇不到的判断
        throw std::logic_error("This type cannot be recognized");
    }

}// namespace Riddle