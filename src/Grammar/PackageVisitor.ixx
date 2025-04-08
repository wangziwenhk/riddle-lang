module;
#include <antlr4-runtime/antlr4-common.h>
#include "RiddleParserBaseVisitor.h"
export module Grammar.PackageVisitor;
import Support.Package;
export namespace Riddle {
    class PackageVisitor final : public RiddleParserBaseVisitor {
    public:
        Package pack;
        std::any visitProgram(RiddleParser::ProgramContext *context) override {
            for (const auto i: context->children) {
                if (antlrcpp::is<RiddleParser::PackStatementContext *>(i->children[0]->children[0])) {
                    visit(i);
                }
            }
            if (pack.getName().empty()) {
                throw std::invalid_argument("Name cannot be empty");
            }
            pack.program = context;
            return {};
        }
        std::any visitPackStatement(RiddleParser::PackStatementContext *context) override {
            pack.setName(context->packName->getText());
            return {};
        }
    };
} // namespace Riddle
