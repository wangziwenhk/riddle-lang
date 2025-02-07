module;
#include "RiddleParser.h"


#include <antlr4-runtime.h>
#include <string>
#include <utility>
#include <vector>
export module Types.Unit;
import Support.Options;
using Path = std::string;
export namespace Riddle {
    class Unit {
        /// @brief 当前单元的包名
        std::string packName;
        /// @brief 导入的库，内容为包名
        std::vector<std::string> imports;
        /// @brief 文件的完整路径
        Option option;

    public:
        RiddleParser *parser{};
        /// @brief 解析树
        antlr4::tree::ParseTree *parseTree = nullptr;

        Unit() = default;
        explicit Unit(Option option): option(std::move(option)) {
            parser = nullptr;
        }

        /// @brief 设置包名，通过 PackageVisitor 获取
        void setPackName(Path name) {
            this->packName = std::move(name);
        }

        /// @brief 获取包名
        [[nodiscard]] Path getPackName() const {
            return packName;
        }

        /// @brief 设置源文件的完整路径
        void setFileOption(const Option &option) {
            this->option = option;
        }

        /// @brief 获取源文件的完整路径
        [[nodiscard]] Option getFileOption() const {
            return this->option;
        }

        /// @brief 添加库相关
        /// @param lib 包名
        void addImports(const std::string &lib) {
            imports.push_back(lib);
        }

        void addImports(const std::vector<std::string> &libs) {
            for(const auto &i: libs) {
                imports.push_back(i);
            }
        }

        [[nodiscard]] std::vector<std::string> getImports() const {
            return imports;
        }

        [[nodiscard]] size_t getImportSize() const {
            return imports.size();
        }

        /// @brief 添加优先级比较
        bool operator>(const Unit &x) const {
            return this->imports.size() > x.imports.size();
        }

        bool operator<(const Unit &x) const {
            return this->imports.size() < x.imports.size();
        }
    };

}// namespace Riddle
