#ifndef RIDDLE_LANGUAGE_DOUBLEMAP_H
#define RIDDLE_LANGUAGE_DOUBLEMAP_H
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

namespace Riddle{
    template<typename KeyTy, typename Tp>
    class doubleMap{
        __gnu_pbds::tree<KeyTy, Tp, std::less<int>, __gnu_pbds::rb_tree_tag,
            __gnu_pbds::tree_order_statistics_node_update> tree;

    public:
        auto findByKey(KeyTy key){
            return tree.find(key);
        }

        auto findByValue(Tp value){
            auto it = tree.lower_bound(value);
            if (it->second != value) {
                return tree.end();
            }
            return it;
        }

        void insert(KeyTy key, Tp value){
            tree.insert({key, value});
        }

        auto erase(KeyTy key){
            return tree.erase(key);
        }

        bool countByKey(KeyTy key){
            return findByKey(key) != tree.end();
        }

        bool countByValue(Tp value){
            return findByValue(value) != tree.end();
        }
    };
} // Riddle

#endif //RIDDLE_LANGUAGE_DOUBLEMAP_H
