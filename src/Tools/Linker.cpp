#include "Linker.h"
#include "Files.h"
#include <ext/rope>
#include <filesystem>
#include <regex>
namespace fs = std::filesystem;

std::string getLibName(std::string PackageName) {
    auto pos = std::find(PackageName.rbegin(), PackageName.rend(), '.');
    return {pos.base(), PackageName.end()};
}

namespace Riddle {
    Linker::Linker() {
    }
    std::string Linker::findSourceLib(const std::string &libPackName, const std::string &sourcePath) {
        const std::string libName = getLibName(libPackName);
        const auto files = Files::getTreeSource(sourcePath);
        for(int i = static_cast<int>(files.size()) - 1; i >= 0; i--) {
            fs::path filePath(files[i]);
            std::string name = filePath.filename().string();
            name = name.substr(0, name.size() - 4);
            if(name != libName) continue;

            auto statement = Files::getFileFirstLine(files[i]);
            std::smatch matches;
            std::regex pattern("package ([a-zA-Z.]+);");
            if(std::regex_search(statement, matches, pattern)) {
                if(matches.size() <= 1) continue;

                std::string thisPackageName = matches[1].str();
                if(thisPackageName == libPackName)
                    return sourcePath;
            }
        }
        return "UNKNOWN";
    }
    std::string Linker::findLib(const std::string &libPackName, const std::string &sourcePath) {
        std::string sp = findSourceLib(libPackName, sourcePath);
        if(sp != "UNKNOWN") return sp;
        return "UNKNOWN";
    }
}// namespace Riddle
