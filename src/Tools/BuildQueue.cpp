#include "BuildQueue.h"
#include "RiddleLexer.h"
#include "Visitors/PackageVisitor.h"
#include <iostream>
#include "Visitors/StmtVisitor.h"
import IR.ParserStmt;
import Types.Statements;
import ErrorManager;
namespace Riddle {
    void BuildQueue::push(const Unit &unit) {
        libSource[unit.getPackName()].push_back(unit);
        // 建模块关系图
        for(const auto& i: unit.getImports()) {
            libGraph[i].push_back(unit.getPackName());
        }
    }
    void BuildQueue::start() {
        // todo 实现解析包相关的东西
        // 暂时还不写，先完成编译main
        if(libSource.contains("main")) {
            llvm::LLVMContext llvm_ctx;
            Context context(llvm_ctx);
            StmtVisitor visitor(context,libSource["main"].front().parser);
            const auto it = any_cast<ProgramStmt*>(visitor.visit(libSource["main"].front().parseTree));
            ParserStmt ps(context);
            ps.accept(it);

        } else {
            std::cerr << R"(Not Found "main" package)" << std::endl;
        }
    }
    // 目前只做了main的解析
    void BuildQueue::parserFile(const std::string &filePath) {
        std::ifstream stream(filePath);
        const auto input = new antlr4::ANTLRInputStream(stream);
        const auto lexer = new RiddleLexer(input);
        // 添加自定义的错误处理
        LexerErrorListener lexerListener;
        lexer->removeErrorListeners();
        lexer->addErrorListener(&lexerListener);

        const auto tokens = new antlr4::CommonTokenStream(lexer);
        auto *parser = new RiddleParser(tokens);

        ParserErrorListener parserListener;

        std::string line;
        while (std::getline(stream, line)) {
            parserListener.lines.push_back(line);
        }
        stream.clear();
        stream.seekg(0);

        parser->removeErrorListeners();
        parser->addErrorListener(&parserListener);

        antlr4::tree::ParseTree *p = parser->program();
        PackageVisitor visitor(filePath, p,parser);
        push(visitor.unit);
    }
}// namespace Riddle