module;
#include <algorithm>
#include <unordered_map>
#include <memory>
export module Types.UnionFind;
using lld = unsigned long long;
export namespace Riddle {
    template<typename T>
    class UnionFind {
        std::unordered_map<T, std::shared_ptr<T>> parent;// 存储指向父节点的指针
        std::unordered_map<T, lld> rank;                 // 存储秩（用于按秩合并）

    public:
        // 添加一个新的元素，并初始化它为自己的父节点
        void add(const T &x) {
            if(!parent.contains(x)  ) {
                parent[x] = std::make_shared<T>(x);// 使用共享指针存储
                rank[x] = 1;                       // 初始化秩为1
            }
        }

        // 查找元素 x 的根，并进行路径压缩
        T find(const T &x) {
            if(*parent[x] != x) {
                T root = find(*parent[x]);
                parent[x] = std::make_shared<T>(root);// 路径压缩时更新指针
            }
            return *parent[x];
        }

        // 合并两个元素 x 和 y 所在的集合，按秩合并
        void unionSets(const T &x, const T &y) {
            T rootX = find(x);
            T rootY = find(y);

            if(rootX != rootY) {
                if(rank[rootX] > rank[rootY]) {
                    parent[rootY] = std::make_shared<T>(rootX);// 合并并更新指针
                } else if(rank[rootX] < rank[rootY]) {
                    parent[rootX] = std::make_shared<T>(rootY);
                } else {
                    parent[rootY] = std::make_shared<T>(rootX);
                    rank[rootX] += 1;// 增加根节点的秩
                }
            }
        }

        // 判断两个元素是否属于同一个集合
        bool isConnected(const T& x, const T& y) {
            return find(x) == find(y);
        }
    };

}// namespace Riddle