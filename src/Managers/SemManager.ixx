module;
#include <vector>
export module Manager.SemManager;
import Semantics.SemNode;
export namespace Riddle {
    class SemManager {
        std::vector<SemNode *> semNodes;

    public:
        SemManager() = default;
        ~SemManager() {
            for(auto &i: semNodes) {
                delete i;
                i = nullptr;
            }
            semNodes.clear();
        }

        void addToAllocator(SemNode *semNode) {
            if(semNode == nullptr) {
                return;
            }
            semNodes.push_back(semNode);
        }
    };
}// namespace Riddle
