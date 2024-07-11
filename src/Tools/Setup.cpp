#include "Setup.h"
#include <filesystem>
#include <string>

namespace Riddle{
    std::string Setup::getWorkPath(){
        return workPath;
    }

    Setup::Setup(){
        std::filesystem::path currentPath = std::filesystem::current_path();
        workPath = currentPath.string();
    }
} // Riddle