#include "Linker.h"
#include <ext/rope>
#include "Files.h"
namespace Riddle{
    std::vector<std::string> Linker::SystemLibPaths;
    bool Linker::isDef = false;
    Linker::Linker() {
        if(isDef){
            throw std::logic_error("Linker is defined multiple times");
        }
        isDef = true;
        //对不同系统区分搜索
#ifdef WIN32
        std::string systemPaths = std::getenv("PATH");
        __gnu_cxx::rope<char> temp;
        for(auto i:systemPaths){
            if(i==';'){
                SystemLibPaths.emplace_back(temp.c_str());
                temp.clear();
            }
            else temp.push_back(i);
        }
        SystemLibPaths.emplace_back(temp.c_str());
#endif
#ifdef LINUX
        SystemLibPaths.emplace_back("usr/lib");
        SystemLibPaths.emplace_back("lib");
#endif
    }
    std::string Linker::findLib(const std::string& libName, const std::string& sourcePath) {
        //Source File Path
        auto files = Files::getTreeFile(sourcePath);
        return {};
    }
}


