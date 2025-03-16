module;
#include <clang/Driver/Compilation.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/Linker/Linker.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Target/TargetMachine.h>
#include <memory>
#include <queue>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

#include "RiddleLexer.h"
#include "RiddleParser.h"
export module Support.BuildQueue;
import Support.Unit;
import Manager.ErrorManager;
import Support.File;
import Parsing.PackageVisitor;
import Parsing.GramAnalysis;
import Semantics.SemAnalysis;
import Semantics.SemNode;
import Gen.GenCode;
import Gen.Moudule;
import Gen.BuildTarget;
export namespace Riddle {
    class BuildQueue {
        /// @brief 用于构建各个库之间的导入关系
        /// @brief 这里使用包名判断库之间的关系
        std::unordered_map<std::string, std::vector<std::string>> libGraph;
        /// @brief 用于将不同包之间的库链接起来，本质上就是处理后拼接
        std::unordered_map<std::string, std::vector<Unit>> libSource;

    public:
        std::shared_ptr<BuildTarget> buildTarget;

        BuildQueue() {
            buildTarget = std::make_shared<BuildTarget>();
        }

        /// @brief 用于解析某个源文件
        void parserFile(const File &option) {
            std::ifstream stream(option.source);
            if (!stream.is_open()) {
                throw std::runtime_error("Could not open file " + option.source);
            }
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
            PackageVisitor visitor(option, p, parser);
            push(visitor.unit);
        }

        void push(const Unit &unit) {
            libSource[unit.getPackName()].push_back(unit);
            // 建模块关系图
            // libGraph 指向依赖自己的库
            libGraph[unit.getPackName()];
            for (const auto &i: unit.getImports()) {
                libGraph[i].push_back(unit.getPackName());
            }
        }

        // 拓扑排序
        void start() {
            if (!libSource.contains("main")) {
                std::cerr << R"(Not Found "main" package)" << std::endl;
                return;
            }
            // 处理入度
            std::unordered_map<std::string_view, int> in;
            for (const auto &[fst, snd]: libGraph) {
                if (libSource[fst].empty()) {
                    throw std::logic_error(std::format("Module '{}' not found", fst));
                }
                for (const auto &j: snd) {
                    in[j]++;
                }
            }
            for (const auto &i: libSource | std::views::keys) {
                // 为没有依赖的节点赋值
                if (!in.contains(i)) in[i] = 0;
            }
            // 处理head
            std::queue<std::string_view> que;
            for (const auto &[lib, snd]: in) {
                if (snd == 0) {
                    que.push(lib);
                }
            }

            // 拓扑排序处理依赖关系
            std::vector<std::string_view> buildList;
            while (!que.empty()) {
                auto lib = que.front();
                que.pop();
                buildList.push_back(lib);
                for (const auto &j: libGraph[lib.data()]) {
                    in[j]--;
                    if (in[j] == 0) {
                        que.push(j);
                    }
                }
            }

            std::unique_ptr<llvm::LLVMContext> llvm_ctx = std::make_unique<llvm::LLVMContext>();
            std::unordered_map<std::string, std::unique_ptr<Module>> contextMap;
            // 依次编译
            for (auto i: buildList) {
                auto unit = libSource[i.data()].front();
                contextMap.emplace(unit.getPackName(), std::make_unique<Module>(llvm_ctx.get(), unit));
                auto &module = contextMap.at(unit.getPackName());

                module->context.buildTarget = this->buildTarget;

                // link 其他 Context
                for (const auto &lib: unit.getImports()) {
                    module->import(*contextMap.at(lib));
                }
                module->start();
            }

            // 合并模块到唯一一个中
            auto mainModule = std::make_unique<llvm::Module>("@main", *llvm_ctx);
            for (auto &[moduleName, module]: contextMap) {
                if (llvm::Linker::linkModules(*mainModule, std::move(module->context.llvmModule))) {
                    llvm::errs() << "Error linking " << moduleName << "\n";
                    return;
                }
            }

            std::string outFileName = "out";

            std::error_code ec;
            llvm::raw_fd_ostream Dest(outFileName + ".ll", ec);
            if (ec) {
                llvm::errs() << "Could not open output file: " << ec.message() << "\n";
                return;
            }
            mainModule->print(Dest, nullptr);
            mainModule->print(llvm::outs(), nullptr);
            Dest.flush();
            Dest.close();

            system(("clang " + outFileName + ".ll" + " -o " + outFileName).c_str());
        }
    };
} // namespace Riddle
