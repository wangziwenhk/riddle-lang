module;
#include <vector>
export module Tools.Allocator;
export namespace Riddle {
    class Allocator final {
        std::vector<void *> data;

    public:
        Allocator() = default;

        ~Allocator() {
            for(const auto i:data) {
                // ReSharper disable once CppDeletingVoidPointer
                delete i;
            }
        }

        void addPtr(void *ptr) {
            data.push_back(ptr);
        }
    };
}// namespace Riddle
