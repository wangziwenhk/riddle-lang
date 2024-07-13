#include "PackageVisitor.h"
#include "Tools/Linker.h"
#include <filesystem>
namespace Riddle {
    std::any PackageVisitor::visitPackStatement(RiddleParser::PackStatementContext *ctx) {
        unit.setPackName(ctx->packName->getText());
        return RiddleParserBaseVisitor::visitPackStatement(ctx);
    }
    std::any PackageVisitor::visitImportStatement(RiddleParser::ImportStatementContext *ctx) {
        std::filesystem::path path(unit.getSelfPath());
        unit.addImports(linker.findLib(ctx->libName->getText(),path.parent_path().string(),unit.getPackName()));
        return RiddleParserBaseVisitor::visitImportStatement(ctx);
    }
    PackageVisitor::PackageVisitor(std::string sourcePath) {
        unit.setSelfPath(sourcePath);
    }
}// namespace Riddle