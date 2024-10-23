module;
#include <getopt.h>
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
        explicit Options(int argc, char *argv[]) {
            int opt;
            while((opt = getopt(argc,argv,"o:"))) {
                switch(opt) {
                    case 'o':
                        output = optarg;
                        break;
                    default:
                        return;
                }
            }
            if (optind < argc) {
                source = argv[optind];
            }
            if(output.empty()) {
                output = source+".exe";
            }
        }
    };
} // namespace Riddle