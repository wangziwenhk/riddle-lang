#include "PackageVisitor.h"
#include "Tools/Linker.h"
#include <filesystem>
namespace Riddle {
    std::any PackageVisitor::visitPackStatement(RiddleParser::PackStatementContext *ctx) {
        unit.setPackName(ctx->packName->getText());
        return RiddleParserBaseVisitor::visitPackStatement(ctx);
    }
    std::any PackageVisitor::visitImportStatement(RiddleParser::ImportStatementContext *ctx) {
        unit.addImports(ctx->libName->getText());
        return RiddleParserBaseVisitor::visitImportStatement(ctx);
    }
    PackageVisitor::PackageVisitor(std::string sourcePath, antlr4::tree::ParseTree *tree) {
        unit.parseTree = tree;
        unit.setDirectoryPath(sourcePath);
        this->visit(tree);
    }
}// namespace Riddle