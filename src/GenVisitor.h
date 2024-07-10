//
// Created by wangz on 24-7-9.
//

#ifndef RIDDLE_LANGUAGE_GENVISITOR_H
#define RIDDLE_LANGUAGE_GENVISITOR_H

#include "RiddleParserBaseVisitor.h"
class GenVisitor:public RiddleParserBaseVisitor{
    std::any visitInteger(RiddleParser::IntegerContext *ctx) override;
};


#endif //RIDDLE_LANGUAGE_GENVISITOR_H
