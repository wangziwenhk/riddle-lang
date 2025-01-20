module;
#include "RiddleLexer.h"
#include <Visitors/StmtVisitor.h>
#include <llvm/IR/LLVMContext.h>
#include <queue>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>
export module Tools.BuildQueue;
import Types.Unit;
import IR.ParserStmt;
import Manager.ErrorManager;
import Tools.Options;
import Visitor.PackageVisitor;
export namespace Riddle {
    class BuildQueue {
        /// @brief 用于构建各个库之间的导入关系
        /// @brief 这里使用包名判断库之间的关系
        std::unordered_map<std::string, std::vector<std::string>> libGraph;
        /// @brief 用于将不同包之间的库链接起来，本质上就是处理后拼接
        std::unordered_map<std::string, std::vector<Unit>> libSource;

    public:
        /// @brief 用于解析某个源文件
        void parserFile(Option option) {
            std::ifstream stream(option.source);
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
            while(std::getline(stream, line)) {
                parserListener.lines.push_back(line);
            }
            stream.clear();
            stream.seekg(0);

            parser->removeErrorListeners();
            parser->addErrorListener(&parserListener);

            antlr4::tree::ParseTree *p = parser->program();
            PackageVisitor visitor(option, p, parser);
            push(visitor.unit);
        }
        void push(const Unit &unit) {
            libSource[unit.getPackName()].push_back(unit);
            // 建模块关系图
            // libGraph 指向依赖自己的库
            for(const auto &i: unit.getImports()) {
                libGraph[i].push_back(unit.getPackName());
            }
        }
        // 拓扑排序
        void start() {
            // todo 实现解析包相关的东西
            // 暂时还不写，先完成编译main
            if(!libSource.contains("main")) {
                std::cerr << R"(Not Found "main" package)" << std::endl;
            }
            // 处理入度
            std::unordered_map<std::string_view, int> in;
            for(const auto &i: libGraph | std::views::values) {
                for(const auto &j: i) {
                    in[j]++;
                }
            }
            for(const auto &i: libSource | std::views::keys) {
                if(!in.contains(i)) in[i] = 0;
            }
            // 处理head
            std::queue<std::string_view> que;
            for(const auto &[lib, snd]: in) {
                if(snd == 0) {
                    que.push(lib);
                }
            }

            // 拓扑排序处理依赖关系
            std::vector<std::string_view> buildList;
            while(!que.empty()) {
                auto lib = que.front();
                que.pop();
                buildList.push_back(lib);
                for(const auto &j: libGraph[lib.data()]) {
                    in[j]--;
                    if(in[j] == 0) {
                        que.push(j);
                    }
                }
            }

            // 依次编译
            for(auto i: buildList) {
                llvm::LLVMContext llvm_ctx;
                Context context(llvm_ctx);
                for(const auto &j: libSource[i.data()]) {
                    StmtVisitor visitor(context, j.parser);
                    const auto it = any_cast<ProgramStmt *>(visitor.visit(j.parseTree));
                    ParserStmt ps(&context, j);
                    ps.accept(it);
                }
            }
        }
    };
}// namespace Riddle
