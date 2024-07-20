#include "GenTools.h"
#include "RiddleLexer.h"
#include <llvm/IR/Constants.h>

namespace Riddle {
    llvm::AllocaInst *InitAlloca(std::string name, std::string type, llvm::IRBuilder<> &Builder) {
        llvm::AllocaInst *Alloca = nullptr;
        Alloca = Builder.CreateAlloca(GetType(type,Builder), nullptr, name);
        return Alloca;
    }
    bool isBooleanTy(llvm::Value *value) {
        llvm::Type *Ty = value->getType();
        if(Ty->isPointerTy()) {
            return Ty->getPointerTo()->isIntegerTy(1);
        } else {
            return Ty->isIntegerTy(1);
        }
    }
    bool isTerminalNode(antlr4::tree::ParseTree *tree) {
        return dynamic_cast<antlr4::tree::TerminalNode *>(tree) != nullptr;
    }
    bool isIdentifier(antlr4::tree::ParseTree *tree) {
        if (isTerminalNode(tree)) {
            antlr4::tree::TerminalNode *terminalNode = dynamic_cast<antlr4::tree::TerminalNode*>(tree);
            if (terminalNode) {
                antlr4::Token *token = terminalNode->getSymbol();
                return token->getType() == RiddleLexer::Identifier;
            }
        }
        return false;
    }
    llvm::Type *GetType(std::string type, llvm::IRBuilder<> &Builder) {
        if(type=="int")
            return Builder.getInt32Ty();
        else if(type=="float")
            return Builder.getFloatTy();
        else if(type=="double")
            return Builder.getDoubleTy();
        else if(type=="bool")
            return Builder.getInt1Ty();
        else if(type=="char")
            return Builder.getInt8Ty();
        throw std::logic_error("There is no such type");
    }
    std::vector<llvm::Type *> GetTypes(std::vector<std::string> type, llvm::IRBuilder<> &Builder) {
        std::vector<llvm::Type *> result;
        for(auto i:type){
            result.push_back(GetType(i,Builder));
        }
        return result;
    }

}// namespace Riddle