module;
#include <stdexcept>
#include <string>
#include <vector>
export module Tools.Options;
import Tools.Files;
export namespace Riddle {
    class Options {
    public:
        std::string source;
        std::string output;
        bool isMultiThread = false;
        Options() = default;
        explicit Options(std::vector<std::string>&args) {
            if (args.empty()) {
                return;
            }
            // 解析 args
            bool isExpect = false;
            std::string pre;
            for (const auto& arg : args) {
                if(isExpect) {
                    if(pre == "--source" || pre == "-s") {
                        source = arg;
                        pre = "";
                    }
                    else if (pre == "--output" || pre == "-o") {
                        output = arg;
                        pre = "";
                    }
                    isExpect = false;
                }
                if(arg[0]=='-') {
                    isExpect = true;
                }
                if(arg == "-m" || arg == "--multi-thread") {
                    isMultiThread = true;
                    isExpect = false;
                    pre = "";
                }
                if(source.empty()) {
                    source = arg;
                }
                pre = arg;

            }
            // 自动补全
            if(source.empty()) {
                throw std::invalid_argument("Options source is empty");
            }
            if(output.empty()) {
                output = Files::getFileName(source);
            }
        }
    };
} // namespace Riddle