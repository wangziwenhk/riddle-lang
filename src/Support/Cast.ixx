module;
#include <any>
#include <memory>
#include <stdexcept>
#include <type_traits>
export module Support.Cast;
export namespace Riddle {
    template<typename T>
    struct is_shared_ptr : std::false_type {};

    template<typename T>
    struct is_shared_ptr<std::shared_ptr<T>> : std::true_type {};

    template<typename Tp, typename SrcTp>
    std::enable_if_t<!is_shared_ptr<Tp>::value, Tp> fit_cast(const std::any &pack) {
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
    Tp fit_cast(const std::any &pack) {
        if (!pack.has_value()) {
            throw std::invalid_argument("Pack cannot be empty");
        }
        return std::any_cast<Tp>(pack);
    }

    template<typename T>
    struct shared_ptr_inner {};

    template<typename T>
    struct shared_ptr_inner<std::shared_ptr<T>> {
        using type = T;
    };

    template<typename Tp, typename SrcTp>
    std::enable_if_t<is_shared_ptr<Tp>::value, Tp> fit_cast(const std::any &pack) {
        if (!pack.has_value()) {
            throw std::invalid_argument("Pack cannot be empty");
        }

        try {
            auto src = std::any_cast<SrcTp>(pack);
            using TargetInner = typename shared_ptr_inner<Tp>::type;
            auto result = std::dynamic_pointer_cast<TargetInner>(src);

            if (!result) {
                throw std::invalid_argument("bad fit cast for shared_ptr");
            }
            return result;
        } catch (const std::bad_any_cast &) {
            throw std::invalid_argument("bad any cast for shared_ptr");
        }
    }

} // namespace Riddle
