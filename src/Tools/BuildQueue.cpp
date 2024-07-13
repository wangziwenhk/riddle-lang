#include "BuildQueue.h"
#include <iostream>

namespace Riddle {
    void BuildQueue::push(const Unit& unit) {
        queue.push_back(unit);
    }
    void BuildQueue::start() {
        std::sort(queue.begin(), queue.end());
        for(auto i:queue){
            //检查文件是否存在？
        }
    }
}// namespace Riddle