module;
#include <any>
#include <stdexcept>
export module Support.Cast;
export namespace Riddle {
    template<typename Tp, typename SrcTp>
    Tp fit_cast(const std::any& pack) {
        if (!pack.has_value()) {
            throw std::invalid_argument("Pack cannot be empty");
        }
        const auto result = dynamic_cast<Tp>(std::any_cast<SrcTp>(pack));
        if (result == nullptr) {
            throw std::invalid_argument("bad fit cast");
        }
        return result;
    }

    template<typename Tp>
    Tp fit_cast(const std::any& pack) {
        if (!pack.has_value()) {
            throw std::invalid_argument("Pack cannot be empty");
        }
        return std::any_cast<Tp>(pack);
    }
} // namespace Riddle
