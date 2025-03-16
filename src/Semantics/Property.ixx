module;
#include <bitset>
#include "magic_enum/magic_enum.hpp"
export module Semantics.Property;
export namespace Riddle {
    class Property {
    public:
        enum PropertyType {
            Packaged, ///< 启用紧凑模式
            InterruptService, ///< 中断服务
        };

        bool get(const PropertyType type) {
            return types[type];
        }

        void set(const PropertyType type, const bool value) {
            types[type] = value;
        }

    private:
        std::bitset<magic_enum::enum_count<PropertyType>()> types;
    };
}
