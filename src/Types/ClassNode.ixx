module;
export module Types.ClassNode;
import Types.Class;

export namespace Riddle{
    // 防止内存泄漏，启用 RAII 思想
    class ClassNode{
    public:
        Class *theClass;

        ClassNode(): theClass(new Class()){
        }

        ~ClassNode(){
            delete theClass;
        }

        [[nodiscard]] Class &get() const{
            return *theClass;
        }
    };
} // namespace Riddle