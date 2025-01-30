module;
#include <RiddleParserBaseVisitor.h>
#include <antlr4-runtime.h>
export module Visitor.PackageVisitor;

import Types.Unit;
import Support.Options;
export namespace Riddle {
    /// @brief 用于解析库和包的类，对于每个源文件都需要单独实例化
    class PackageVisitor final : public RiddleParserBaseVisitor {
    public:
        Unit unit;
        PackageVisitor() = delete;
        std::any visitPackStatement(RiddleParser::PackStatementContext *ctx) override {
            unit.setPackName(ctx->packName->getText());
            return RiddleParserBaseVisitor::visitPackStatement(ctx);
        }
        std::any visitImportStatement(RiddleParser::ImportStatementContext *ctx) override {
            unit.addImports(ctx->libName->getText());
            return RiddleParserBaseVisitor::visitImportStatement(ctx);
        }
        PackageVisitor(const Option &option, antlr4::tree::ParseTree *tree, RiddleParser *parser) {
            unit.parseTree = tree;
            unit.parser = parser;
            unit.setFileOption(option);
            PackageVisitor::visit(tree);
        }
    };

}// namespace Riddle