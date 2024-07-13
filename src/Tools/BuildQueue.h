#ifndef RIDDLE_LANGUAGE_BUILDQUEUE_H
#define RIDDLE_LANGUAGE_BUILDQUEUE_H

#include "Types/Unit.h"
#include <llvm/IR/Module.h>
namespace Riddle {
    /// \brief 用于随时调整编译队列
    class BuildQueue {

    public:
        std::vector<Unit> queue;
        void push(const Unit& unit);
        void start();
    };
    static BuildQueue buildQueue;

}// namespace Riddle

#endif//RIDDLE_LANGUAGE_BUILDQUEUE_H
