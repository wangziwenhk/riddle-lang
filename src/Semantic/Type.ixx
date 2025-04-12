module;
#include <string>
export module Semantic.Type;
export namespace Riddle {
    /**
     * 表示一个被实际解析的Type类型
     */
    class Type {
    public:
        std::string name;
    };

} // namespace Riddle
