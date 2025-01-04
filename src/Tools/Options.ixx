module;
#include <stdexcept>
#include <string>
export module Tools.Options;
import Tools.Files;
export namespace Riddle {
    class Options {
    public:
        std::string source;
        std::string output;
        bool isMultiThread = false;

        Options() = default;

        explicit Options(const int argc, char *argv[]) {
            for(int i = 1; i < argc; ++i) {
                std::string arg = argv[i];

                if(arg == "-o" || arg == "--output") {
                    if(i + 1 < argc) {
                        output = argv[++i];

                    } else {
                        throw std::invalid_argument("Output file path is missing after '" + arg + "'");
                    }

                } else if(arg == "-m" || arg == "--multi-thread") {
                    isMultiThread = true;
                } else {
                    source = arg;
                }
            }

            if(output.empty()) {
                if(!source.empty()) {
                    output = source + ".ll";
                } else {
                    throw std::invalid_argument("Source file is missing");
                }
            }
        }
    };
}// namespace Riddle
