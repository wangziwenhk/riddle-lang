#include "Files.h"
#include <filesystem>
#include <fstream>
#include <iostream>
namespace fs= std::filesystem;
namespace Riddle {
    std::vector<std::string> Files::getTreeFile(const std::string &path) {// NOLINT(*-no-recursion)
        std::vector<std::string> files;
        try {
            for(const auto &entry: fs::directory_iterator(path)) {
                if(entry.is_regular_file()) {
                    files.push_back(entry.path().string());
                } else if(entry.is_directory()) {
                    std::vector<std::string> child= getTreeFile(entry.path().string());
                    files.insert(files.end(), child.begin(), child.end());
                }
            }
        } catch(const std::exception &e) {
            std::cerr << "Error accessing directory: " << e.what() << std::endl;
        }
        return files;
    }

    std::vector<std::string> Files::getTreeSource(const std::string &path) {
        auto files= getTreeFile(path);
        std::vector<std::string> sourceFiles;
        while(!files.empty()) {
            auto i= files.back();
            fs::path filepath(i);
            //判断源文件后缀
            if(filepath.extension().string() == ".red") {
                sourceFiles.push_back(i);
            }
            files.pop_back();
        }
        return sourceFiles;
    }
    std::vector<std::string> Files::getFileTextLine(const std::string &path) {
        std::ifstream file(path);
        if(!file.is_open()) {
            throw std::runtime_error("File \"" + path + "\" can't open.");
        }
        if(isFileEmpty(path))
            return {};

        std::vector<std::string> result;
        std::string line;
        while(std::getline(file, line)) {
            result.emplace_back(line);
        }
        return result;
    }
    std::string Files::getFileFirstLine(const std::string &path) {
        std::ifstream file(path);
        if(!file.is_open()) {
            throw std::runtime_error("File \"" + path + "\" can't open.");
        }
        if(isFileEmpty(path))
            return {};

        std::string line;
        while(line.empty()) {
            std::getline(file, line);
        }
        file.close();
        return line;
    }
    bool Files::isFileEmpty(const std::string &path) {
        std::ifstream file(path, std::ios::binary | std::ios::ate);
        if(!file.is_open()) {
            throw std::runtime_error("File \"" + path + "\" can't open.");
        }
        // 获取文件大小
        std::streampos fileSize= file.tellg();
        // 如果文件大小为0，则文件为空
        return fileSize == 0;
    }
    std::vector<std::string> Files::getFiles(const std::string &path) {
        std::vector<std::string> files;
        try {
            for(const auto &entry: fs::directory_iterator(path)) {
                if(entry.is_regular_file()) {
                    files.push_back(entry.path().string());
                }
            }
        } catch(const std::exception &e) {
            std::cerr << "Error accessing directory: " << e.what() << std::endl;
        }
        return files;
    }
    std::vector<std::string> Files::getSources(const std::string &path) {
        auto files= getFiles(path);
        std::vector<std::string> sourceFiles;
        while(!files.empty()) {
            auto i= files.back();
            fs::path filepath(i);
            //判断源文件后缀
            if(filepath.extension().string() == ".red") {
                sourceFiles.push_back(i);
            }
            files.pop_back();
        }
        return sourceFiles;
    }
}// namespace Riddle