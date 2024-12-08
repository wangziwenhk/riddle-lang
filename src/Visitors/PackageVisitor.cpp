#include "PackageVisitor.h"
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
    PackageVisitor::PackageVisitor(const std::string &sourcePath, antlr4::tree::ParseTree *tree,RiddleParser* parser) {
        unit.parseTree = tree;
        unit.parser = parser;
        unit.setDirectoryPath(sourcePath);
        unit.setFilePath(sourcePath);
        visit(tree);
    }
}// namespace Riddle