#ifndef RIDDLE_LANGUAGE_GENVISITOR_H
#define RIDDLE_LANGUAGE_GENVISITOR_H

#include "RiddleParserBaseVisitor.h"
#include <llvm/IR/LLVMContext.h>
namespace Riddle{
    class GenVisitor : public RiddleParserBaseVisitor {
    private:
        llvm::LLVMContext globalContext;
    public:
        GenVisitor();
        /// \brief 用于生成一个显式的 int 常量
        /// \param ctx IntegerContext
        /// \return llvm::Value*
        std::any visitInteger(RiddleParser::IntegerContext *ctx) override;
        /// \brief 用于生成一个显式的 float 常量
        /// \param ctx FloatContext
        /// \return llvm::Value*
        std::any visitFloat(RiddleParser::FloatContext *ctx) override;
    };
}



#endif//RIDDLE_LANGUAGE_GENVISITOR_H
