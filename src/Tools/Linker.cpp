#include "Linker.h"
#include "Files.h"
#include <ext/rope>
#include <filesystem>
namespace fs= std::filesystem;

std::string getLibName(std::string PackageName) {
    auto pos= std::find(PackageName.rbegin(), PackageName.rend(), '.');
    return {pos.base(), PackageName.end()};
}

namespace Riddle {
    std::vector<std::string> Linker::SystemLibPaths;
    bool Linker::isDef= false;
    Linker::Linker() {
        if(isDef) {
            throw std::logic_error("Linker is defined multiple times");
        }
        isDef= true;
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
    std::string Linker::findLib(const std::string &libName, const std::string &sourcePath) {
        std::string name= getLibName(libName);
        //Source File Path
        auto files= Files::getTreeSource(sourcePath);
        for(int i= (int)files.size() - 1; i >= 0; i--) {
            fs::path filePath(files[i]);
            if(filePath.filename() == name) {
                // todo 写完找库的逻辑
            }
        }
        return {};
    }
}// namespace Riddle
