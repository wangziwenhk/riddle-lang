module;
#include <vector>
#include <string>
module Types.Unit;

namespace Riddle {
    Unit::Unit(const Path &selfPath) {
        this->directoryPath = selfPath;
    }
    void Unit::addImports(const std::vector<std::string> &libs) {
        for(const auto &i: libs) {
            imports.push_back(i);
        }
    }
    void Unit::addImports(const std::string &lib) {
        imports.push_back(lib);
    }
    bool Unit::operator>(const Unit &x) const {
        return this->imports.size() > x.imports.size();
    }
    bool Unit::operator<(const Unit &x) const {
        return this->imports.size() < x.imports.size();
    }
    size_t Unit::getImportSize() const {
        return imports.size();
    }
    void Unit::setPackName(std::string name) {
        this->packName = std::move(name);
    }
    std::string Unit::getPackName() const {
        return packName;
    }
    std::string Unit::getDirectoryPath() const {
        return directoryPath;
    }
    void Unit::setDirectoryPath(Path path) {
        directoryPath = std::move(path);
    }
    void Unit::setFilePath(const Path &path) {
        this->filePath = path;
    }
    std::string Unit::getFilePath() const {
        return filePath;
    }
    std::vector<std::string> Unit::getImports() const {
        return imports;
    }
}// namespace Riddle