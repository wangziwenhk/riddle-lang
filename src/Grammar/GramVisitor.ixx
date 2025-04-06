module;
#include <memory>
#include "RiddleParserBaseVisitor.h"
export module Grammar.GramVisitor;
import Semantic.SemNode;
export namespace Riddle {
    class GramVisitor final : public RiddleParserBaseVisitor {
    public:
        std::unique_ptr<ProgramNode> root;
        std::any visitProgram(RiddleParser::ProgramContext *context) override {
            root = std::make_unique<ProgramNode>();
            return {};
        }
    };
} // namespace Riddle
