#ifndef RIDDLE_LANGUAGE_PACKAGEVISITOR_H
#define RIDDLE_LANGUAGE_PACKAGEVISITOR_H

#include <RiddleParserBaseVisitor.h>
#include <antlr4-runtime.h>
import Types.Unit;
namespace Riddle {
    /// @brief 用于解析库和包的类，对于每个源文件都需要单独实例化
    class PackageVisitor : public RiddleParserBaseVisitor {
    public:
        Unit unit;
        PackageVisitor() = delete;
        PackageVisitor(const std::string &sourcePath, antlr4::tree::ParseTree *tree,RiddleParser* parser);
        std::any visitPackStatement(RiddleParser::PackStatementContext *ctx) override;
        std::any visitImportStatement(RiddleParser::ImportStatementContext *ctx) override;
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_PACKAGEVISITOR_H
