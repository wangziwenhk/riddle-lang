module;
#include <vector>
#include <any>
export module Semantics.SemAnalysis;
import Semantics.SemNode;
export namespace Riddle {
    // 语义分析补全 Unknown 的代码
    class SemAnalysis final : SemNodeVisitor {
        std::any visitProgram(ProgramNode *node) override {
            for(const auto& i: *node->body) {
                visit(i.get());
            }
            return {};
        }
    };
}// namespace Riddle