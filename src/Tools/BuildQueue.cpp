#include "BuildQueue.h"



namespace Riddle {
    void BuildQueue::push(const Unit& unit) {
        libSource[unit.getPackName()].push_back(unit.getFilePath());
        for(auto i:unit.getImports()){
            libGraph[i].push_back(unit.getPackName());
        }
    }
    void BuildQueue::start() {
        //拓扑排序后处理
    }
}// namespace Riddle