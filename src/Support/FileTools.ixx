module;
#include <filesystem>
#include <fstream>
export module Support.FileTools;
export namespace Riddle {
    namespace fs = std::filesystem;

    std::string readFile(const std::string &filePath) {
        const auto path = fs::path(filePath);
        if (!exists(path)) {
            throw std::runtime_error("File does not exist: " + filePath);
        }
        if (!is_regular_file(path)) {
            throw std::runtime_error("Not a regular file: " + filePath);
        }
        std::ifstream file(path, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Could not open file: " + filePath);
        }
        return {std::istreambuf_iterator(file), std::istreambuf_iterator<char>()};
    }

    std::ifstream getFileStream(const std::string &filePath) {
        const auto path = fs::path(filePath);
        if (!exists(path)) {
            throw std::runtime_error("File does not exist: " + filePath);
        }
        if (!is_regular_file(path)) {
            throw std::runtime_error("Not a regular file: " + filePath);
        }
        std::ifstream file(path, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Could not open file: " + filePath);
        }
        return file;
    }
} // namespace Riddle
