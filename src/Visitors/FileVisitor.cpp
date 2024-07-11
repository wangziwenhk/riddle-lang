#include "FileVisitor.h"

std::any FileVisitor::visitImportStatment(RiddleParser::ImportStatmentContext *ctx){

    return RiddleParserBaseVisitor::visitImportStatment(ctx);
}
