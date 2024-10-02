module;
#include "RiddleParserBaseVisitor.h"
export module Visitors.StatVisitor;
export namespace Riddle {
    class StatVisitor final : RiddleParserBaseVisitor {
    public:
        std::any visitProgram(RiddleParser::ProgramContext *context) override;
    };
}// namespace Riddle