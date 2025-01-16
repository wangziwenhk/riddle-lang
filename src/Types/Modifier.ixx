module;
#include <bitset>
#include <stdexcept>
#include <vector>
export module Type.Modifier;
constexpr int ModifierSize = 8;
export namespace Riddle {
    class Modifier {
        std::bitset<ModifierSize> modifiers;
        static std::bitset<ModifierSize> nonObjectModifier;

        static void initObjectModifier() {
            static bool isInit = false;
            if(isInit) {
                return;
            }
            isInit = true;
            nonObjectModifier[Virtual] = true;
        }

    public:
        enum ModifierType : unsigned char {
            None = 0,
            Public,
            Protected,
            Private,
            Virtual,
            Static,
            Const,
        };
        Modifier(): modifiers(std::bitset<ModifierSize>()) {
            initObjectModifier();
        }

        /// @brief 添加一个新的标识符
        /// @param mod 标识符
        void addModifier(const ModifierType mod) {
            if(modifiers.test(mod)) {
                throw std::logic_error("Modifier: Modifier already exists");
            }
            modifiers[mod] = true;
        }

        /// @brief 检查一个标识是否存在
        /// @param mod 标识符
        [[nodiscard]] bool isModified(const ModifierType mod) const {
            try {
                return modifiers.test(mod);
            } catch(const std::out_of_range &e) {
                throw std::out_of_range("Modifier: " + std::string(e.what()));
            } catch(...) {
                throw std::logic_error("Modifier: Unknown exception");
            }
        }

        /// @brief 获取所有修饰符
        /// @return 存在的修饰符的 vector
        [[nodiscard]] std::vector<ModifierType> getModifierList() const {
            std::vector<ModifierType> result;
            for(int i = 0; i < modifiers.size(); ++i) {
                if(modifiers.test(i)) {
                    result.push_back(static_cast<ModifierType>(i));
                }
            }
            return result;
        }

        /// @brief 判断当前是否可以作为一个对象的修饰符
        [[nodiscard]] bool isObjectModifier() const {
            // 如果当前的修饰符中有类似 virtual 之类的非对象可以使用的修饰符，那么 it 的结果就不为 0
            const auto it = modifiers & nonObjectModifier;
            return !it.any();
        }
    };
    std::bitset<ModifierSize> Modifier::nonObjectModifier;
}