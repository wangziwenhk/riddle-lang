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

        Modifier() = default;

        Modifier(const std::initializer_list<ModifierType> list) {
            for (const auto i: list) {
                modifiers[i] = true;
            }
        }

        [[nodiscard]] bool get(const ModifierType type) const {
            return modifiers[type];
        }

        void set(const ModifierType type, const bool flag) {
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
            const auto it = modifierMap.find(name);
            if (it == modifierMap.end()) {
                throw std::logic_error(std::format("Unknown modifier '{}'", name));
            }
            return it->second;
        }

    private:
        std::bitset<magic_enum::enum_count<ModifierType>()> modifiers;

        // 全局的 unordered_map，用于存储字符串到 enum 的映射
        static const std::unordered_map<std::string, ModifierType> modifierMap;
    };

    decltype(Modifier::modifierMap) Modifier::modifierMap = {
        {"public", Public}, {"private", Private}, {"protected", Protected}, {"virtual", Virtual},
        {"static", Static}, {"const", Const}, {"override", Override}, {"operator", Operator}
    };
} // namespace Riddle
