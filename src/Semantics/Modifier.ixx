module;
#include <algorithm>
#include <bitset>
#include <format>
#include <magic_enum.hpp>
#include <stdexcept>
export module Semantics.Modifier;
export namespace Riddle {
    class Modifier {
    public:
        enum ModifierType {
            Public,
            Private,
            Protected,
            Virtual,
            Static,
            Const,
            Override,
            Operator,
        };

        Modifier() noexcept = default;

        Modifier(const std::initializer_list<ModifierType> list) noexcept {
            for (const auto i: list) {
                modifiers[i] = true;
            }
        }

        [[nodiscard]] bool get(const ModifierType type) const noexcept {
            return modifiers[type];
        }

        void set(const ModifierType type, const bool flag) noexcept {
            modifiers[type] = flag;
        }

        [[nodiscard]] std::vector<ModifierType> getModifierList() const {
            std::vector<ModifierType> result;
            using base = std::underlying_type_t<ModifierType>;
            for (base i = 0; i < modifiers.size(); i++) {
                if (modifiers[i]) {
                    result.push_back(static_cast<ModifierType>(i));
                }
            }
            return result;
        }

        static ModifierType getPrimitiveType(std::string name) {
            std::ranges::transform(name, name.begin(), ::tolower);
            const auto it = _modifierMap.find(name);
            if (it == _modifierMap.end()) {
                throw std::logic_error(std::format("Unknown modifier '{}'", name));
            }
            return it->second;
        }

        static std::string getPrimitiveTypeName(const ModifierType type) {
            const auto it = _modifierStrMap.find(type);
            if (it == _modifierStrMap.end()) {
                throw std::logic_error(std::format("Unknown modifier '{}'", static_cast<int>(type)));
            }
            return it->second;
        }

        /**
         * 检测是否有类的作用域限制
         *
         * 例如带有 Protected 和 Private 修饰的属性/函数
         */
        [[nodiscard]] bool isClassScopeLimited() const noexcept {
            return modifiers[Protected] || modifiers[Private];
        }

    private:
        std::bitset<magic_enum::enum_count<ModifierType>()> modifiers;

        // 全局的 unordered_map，用于存储字符串到 enum 的映射
        static const std::unordered_map<std::string, ModifierType> _modifierMap;
        // 全局的 unordered_map，用于存储 enum 到字符串的映射
        static const std::unordered_map<ModifierType, std::string> _modifierStrMap;
    };

    decltype(Modifier::_modifierMap) Modifier::_modifierMap = {
        {"public", Public}, {"private", Private}, {"protected", Protected}, {"virtual", Virtual},
        {"static", Static}, {"const", Const}, {"override", Override}, {"operator", Operator}
    };

    decltype(Modifier::_modifierStrMap) Modifier::_modifierStrMap = {
        {Public, "public"}, {Private, "private"}, {Protected, "protected"}, {Virtual, "virtual"},
        {Static, "static"}, {Const, "const"}, {Override, "override"}, {Operator, "operator"}
    };
} // namespace Riddle
