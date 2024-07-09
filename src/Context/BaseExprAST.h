//
// Created by wangz on 24-7-9.
//

#ifndef RIDDLE_LANGUAGE_BASEEXPRAST_H
#define RIDDLE_LANGUAGE_BASEEXPRAST_H
#include <llvm/IR/Value.h>
namespace RiddleAST{
    /// \brief 是其他 AST 节点的基类
    class BaseExprAST{
    public:
        virtual ~BaseExprAST() = 0;
        virtual llvm::Value Codegen() = 0;
    };
}

#endif //RIDDLE_LANGUAGE_BASEEXPRAST_H
