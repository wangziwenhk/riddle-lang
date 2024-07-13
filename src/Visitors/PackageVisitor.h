#ifndef RIDDLE_LANGUAGE_PACKAGEVISITOR_H
#define RIDDLE_LANGUAGE_PACKAGEVISITOR_H

#include "RiddleParserBaseVisitor.h"
#include "Types/Unit.h"
namespace Riddle {
    /// @brief 用于解析库和包的类
    class PackageVisitor: public RiddleParserBaseVisitor{
    public:
        Unit unit;
        PackageVisitor() = delete;
        PackageVisitor(std::string sourcePath);
        std::any visitPackStatement(RiddleParser::PackStatementContext *ctx) override;
        std::any visitImportStatement(RiddleParser::ImportStatementContext *ctx) override;
    };

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_PACKAGEVISITOR_H
