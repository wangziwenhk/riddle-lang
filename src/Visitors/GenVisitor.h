#ifndef RIDDLE_LANGUAGE_GENVISITOR_H
#define RIDDLE_LANGUAGE_GENVISITOR_H

#include "RiddleParserBaseVisitor.h"
class GenVisitor : public RiddleParserBaseVisitor {
    /// \brief 用于生成一个显式的 int 常量
    /// \return llvm::Value*
    std::any visitInteger(RiddleParser::IntegerContext *ctx) override;
    /// \brief 用于生成一个显式的 float 常量
    /// \return llvm::Value*
    std::any visitFloat(RiddleParser::FloatContext *ctx) override;
};


#endif//RIDDLE_LANGUAGE_GENVISITOR_H
