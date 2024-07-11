//
// Created by wangz on 24-7-11.
//

#ifndef RIDDLE_LANGUAGE_FILEVISITOR_H
#define RIDDLE_LANGUAGE_FILEVISITOR_H

#include "RiddleParserBaseVisitor.h"
class FileVisitor:public RiddleParserBaseVisitor{
    std::any visitImportStatment(RiddleParser::ImportStatmentContext *ctx) override;
};


#endif //RIDDLE_LANGUAGE_FILEVISITOR_H
