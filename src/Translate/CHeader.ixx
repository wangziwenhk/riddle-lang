module;
#include <clang/AST/ASTConsumer.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendAction.h>
#include <clang/Tooling/Tooling.h>
#include <iostream>
export module Translate.CHeader;
namespace Riddle{
    using namespace clang;
    class CHeader {
        class CHeaderASTVisitor : public RecursiveASTVisitor<CHeaderASTVisitor> {
        public:
            explicit CHeaderASTVisitor(ASTContext &Context) : Context(Context) {}

            bool VisitFunctionDecl(FunctionDecl *FD) {
                std::cout << "Function: " << FD->getNameAsString() << std::endl;
                for (const auto *Param : FD->parameters()) {
                    std::cout << "  Param: " << Param->getNameAsString() << " (Type: "
                              << Param->getType().getAsString() << ")" << std::endl;
                }
                return true;
            }

        private:
            ASTContext &Context;
        };
    };
}