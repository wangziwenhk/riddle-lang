#include "BuildQueue.h"
#include "Visitors/PackageVisitor.h"
#include "Visitors/GenVisitor.h"
#include "RiddleLexer.h"
#include <iostream>

namespace Riddle {
    void BuildQueue::push(const Unit& unit) {
        libSource[unit.getPackName()].push_back(unit);
        for(auto i:unit.getImports()){
            libGraph[i].push_back(unit.getPackName());
        }
    }
    void BuildQueue::start() {
        // todo 实现解析包相关的东西
        // 暂时还不写，先完成编译
        if(libSource.count("main")){
            GenVisitor visitor(std::string());
            visitor.visit(libSource["main"].front().parseTree);
        }
        else{
            std::cerr<<R"(Not Found "main" package)"<<std::endl;
            return;
        }
    }
    // 目前只做了main的解析
    void BuildQueue::Parser(std::string filePath) {
        std::ifstream stream(filePath);
        antlr4::ANTLRInputStream input(stream);
        RiddleLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        RiddleParser parser(&tokens);
        antlr4::tree::ParseTree* p = parser.program();
        PackageVisitor visitor(filePath, p);
        push(visitor.unit);
    }
}// namespace Riddle