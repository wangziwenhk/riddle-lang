#ifndef RIDDLE_LANGUAGE_BUILDQUEUE_H
#define RIDDLE_LANGUAGE_BUILDQUEUE_H
#include <llvm/IR/Module.h>
namespace Riddle{
    /// \brief 用于随时调整编译队列
    class BuildQueue{
    private:
        struct Unit{

        };
    public:
        void addModule(llvm::Module* module){

        }
    };

} // Riddle

#endif //RIDDLE_LANGUAGE_BUILDQUEUE_H
