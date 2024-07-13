#include "PackageVisitor.h"
#include "Tools/Linker.h"
namespace Riddle {
    std::any PackageVisitor::visitPackStatement(RiddleParser::PackStatementContext *ctx) {
        unit.setPackName(ctx->packName->getText());
        return RiddleParserBaseVisitor::visitPackStatement(ctx);
    }
    std::any PackageVisitor::visitImportStatement(RiddleParser::ImportStatementContext *ctx) {
        unit.addImports(linker.findLib(ctx->libName->getText(),unit.getSelfPath(),unit.getPackName()));
        return RiddleParserBaseVisitor::visitImportStatement(ctx);
    }
}// namespace Riddle