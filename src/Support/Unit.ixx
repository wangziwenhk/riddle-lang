module;
#include "../../parser/RiddleParser.h"


#include <antlr4-runtime.h>
#include <string>
#include <utility>
#include <vector>
export module Support.Unit;
export namespace Riddle {
    class Unit {
        /// @brief 当前单元的包名
        std::string packName;
        /// @brief 导入的库，内容为包名
        std::vector<std::string> imports;
        /// @brief 文件的完整路径
        std::string filePath;

    public:
        RiddleParser *parser{};
        /// 解析树
        antlr4::tree::ParseTree *parseTree = nullptr;

        Unit() = default;
        explicit Unit(std::string filePath): filePath(std::move(filePath)) {
            parser = nullptr;
        }

        /// 设置包名，通过 PackageVisitor 获取
        void setPackName(std::string name) {
            this->packName = std::move(name);
        }

        /// 获取包名
        [[nodiscard]] std::string getPackName() const {
            return packName;
        }

        /// 设置源文件的完整路径
        void setFileOption(const std::string &filePath) {
            this->filePath = filePath;
        }

        /// 获取源文件的完整路径
        [[nodiscard]] std::string getFileOption() const {
            return this->filePath;
        }

        /// 添加库
        /// @param lib 包名
        void addImports(const std::string &lib) {
            imports.push_back(lib);
        }

        void addImports(const std::vector<std::string> &libs) {
            for (const auto &i: libs) {
                imports.push_back(i);
            }
        }

        [[nodiscard]] std::vector<std::string> getImports() const {
            return imports;
        }

        [[nodiscard]] size_t getImportSize() const {
            return imports.size();
        }

        /// 添加优先级比较
        bool operator>(const Unit &x) const {
            return this->imports.size() > x.imports.size();
        }

        bool operator<(const Unit &x) const {
            return this->imports.size() < x.imports.size();
        }
    };

} // namespace Riddle
