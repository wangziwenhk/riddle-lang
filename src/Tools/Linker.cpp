#include "Linker.h"
#include "Files.h"
#include <ext/rope>
#include <filesystem>
#include <iostream>
#include <regex>
namespace fs= std::filesystem;

std::string getLibName(std::string PackageName) {
    auto pos= std::find(PackageName.rbegin(), PackageName.rend(), '.');
    return {pos.base(), PackageName.end()};
}

namespace Riddle {
    std::vector<std::string> Linker::SystemLibPaths;
    Linker::Linker() {
        //对不同系统区分搜索
#ifdef WIN32
        std::string systemPaths= std::getenv("PATH");
        __gnu_cxx::rope<char> temp;
        for(auto i: systemPaths) {
            if(i == ';') {
                SystemLibPaths.emplace_back(temp.c_str());
                temp.clear();
            } else
                temp.push_back(i);
        }
        SystemLibPaths.emplace_back(temp.c_str());
#endif
#ifdef LINUX
        SystemLibPaths.emplace_back("usr/lib");
        SystemLibPaths.emplace_back("lib");
#endif
    }
    std::string Linker::findLib(const std::string &libPackName, const std::string &sourcePath) {
        std::string libName= getLibName(libPackName);
        //Source File Path
        auto files= Files::getTreeSource(sourcePath);
        for(int i= (int)files.size() - 1; i >= 0; i--) {
            fs::path filePath(files[i]);
            std::string name= filePath.filename().string();
            name= name.substr(0, name.size() - 4);
            if(name != libName) continue;

            auto statement= Files::getFileFirstLine(files[i]);
            std::smatch matches;
            std::regex pattern("package ([a-zA-Z.]+);");
            if(std::regex_search(statement, matches, pattern)) {
                if(matches.size() <= 1) continue;

                std::string thisPackageName= matches[1].str();
                if(thisPackageName == libPackName)
                    return sourcePath;
            }
        }

        return {};
    }
}// namespace Riddle
