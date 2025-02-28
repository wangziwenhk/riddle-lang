#pragma once

#include <string>
#include <tuple>

template<>
struct std::hash<std::tuple<std::string, std::string, std::string> > {
    size_t operator()(const tuple<string, string, string> &t) const noexcept {
        const size_t h1 = hash<string>{}(get<0>(t));
        const size_t h2 = hash<string>{}(get<1>(t));
        const size_t h3 = hash<string>{}(get<2>(t));
        return h1 ^ (h2 << 1) ^ (h3 << 2); // 结合哈希值
    }
};
