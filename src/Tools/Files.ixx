module;
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
export module Tools.Files;
namespace fs = std::filesystem;
export namespace Riddle {
    class Files {
        //我们应该增加一个缓存吗
    public:
        /// @brief 递归获取某个路径下的所有文件
        /// @param path 路径
        /// @return 递归路径下的所有文件
        static std::vector<std::string> getTreeFile(const std::string &path) {// NOLINT(*-no-recursion)
            std::vector<std::string> files;
            try {
                for(const auto &entry: fs::directory_iterator(path)) {
                    if(entry.is_regular_file()) {
                        files.push_back(entry.path().string());
                    } else if(entry.is_directory()) {
                        std::vector<std::string> child = getTreeFile(entry.path().string());
                        files.insert(files.end(), child.begin(), child.end());
                    }
                }
            } catch(const std::exception &e) {
                std::cerr << "Error accessing directory: " << e.what() << std::endl;
            }
            return files;
        }
        /// @brief 递归获取某个路经下的所有源文件
        /// @param path 路径
        /// @return 递归路径下的所有源文件
        static std::vector<std::string> getTreeSource(const std::string &path) {
            auto files = getTreeFile(path);
            std::vector<std::string> sourceFiles;
            while(!files.empty()) {
                auto i = files.back();
                fs::path filepath(i);
                //判断源文件后缀
                if(filepath.extension().string() == ".red") {
                    sourceFiles.push_back(i);
                }
                files.pop_back();
            }
            return sourceFiles;
        }
        /// @brief 获取某个路径下的所有文件
        /// @param path 路径
        /// @return 路径下的所有文件
        static std::vector<std::string> getFiles(const std::string &path) {
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
        /// @brief 获取某个路径下的所有源文件
        /// @param path 路径
        /// @return 路径下的所有源文件
        static std::vector<std::string> getSources(const std::string &path) {
            auto files = getFiles(path);
            std::vector<std::string> sourceFiles;
            while(!files.empty()) {
                auto i = files.back();
                fs::path filepath(i);
                //判断源文件后缀
                if(filepath.extension().string() == ".red") {
                    sourceFiles.push_back(i);
                }
                files.pop_back();
            }
            return sourceFiles;
        }
        /// @brief 读取某个文件中的所有内容
        /// @param path 文件路径
        /// @return 文件内容
        static std::vector<std::string> getFileTextLine(const std::string &path) {
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
        /// @brief 获取某个文件的第一行
        /// @param path 文件路径
        /// @return 文件第一行
        static std::string getFileFirstLine(const std::string &path) {
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
        /// @brief 检查某个文件是否为空
        /// @param path 文件路径
        /// @return 文件是否为空
        static bool isFileEmpty(const std::string &path) {
            std::ifstream file(path, std::ios::binary | std::ios::ate);
            if(!file.is_open()) {
                throw std::runtime_error("File \"" + path + "\" can't open.");
            }
            // 获取文件大小
            const std::streampos fileSize = file.tellg();
            // 如果文件大小为0，则文件为空
            return fileSize == 0;
        }
        /// @brief 获取文件名称，也就是去除路径
        /// @param path 文件路径
        /// @return 文件名称
        static std::string getFileName(const std::string &path){
            const fs::path file_path(path);
            return file_path.filename().string();
        }
    };
}// namespace Riddle