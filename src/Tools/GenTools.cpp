#include "GenTools.h"
#include "RiddleLexer.h"
#include "Setup.h"
#include <llvm/IR/Constants.h>

namespace Riddle {
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
    llvm::Type *getSampleType(std::string type, llvm::IRBuilder<> &Builder) {
        auto it = SampleType.find(type);
        if(it == SampleType.end()) {
            throw std::logic_error("There is no such type");
        }
        return it->second(Builder);
    }
    bool isSampleType(std::string type) {
        auto it = SampleType.find(type);
        return it != SampleType.end();
    }
    std::vector<llvm::Type *> getTypes(std::vector<std::string> type, llvm::IRBuilder<> &Builder) {
        std::vector<llvm::Type *> result;
        for(auto i: type) {
            result.push_back(getSampleType(i, Builder));
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
            return "array";
        } else if(type->isPointerTy()) {
            return "pointer";
        }
        //遇不到的判断
        throw std::logic_error("This type cannot be recognized");
    }

}// namespace Riddle