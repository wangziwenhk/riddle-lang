module;
#include <vector>
export module Support.Allocator;
export namespace Riddle {
    template<typename Tp>
    class Allocator final {
        std::vector<Tp *> data;

    public:
        Allocator() = default;

        ~Allocator() {
            for(const auto i:data) {
                delete i;
            }
        }

        void addPtr(Tp *ptr) {
            data.push_back(ptr);
        }
    };
}// namespace Riddle
