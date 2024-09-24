//
// Created by wangz on 24-8-8.
//

#ifndef CLASSNODE_H
#define CLASSNODE_H
import Types.Class;

namespace Riddle{
    // 防止内存泄漏，启用 RAII 思想
    class ClassNode{
    public:
        Class *theClass;

        ClassNode(): theClass(new Class()){
        }

        ~ClassNode(){
        }

        Class &get() const{
            return *theClass;
        }
    };
} // Riddle

#endif //CLASSNODE_H
