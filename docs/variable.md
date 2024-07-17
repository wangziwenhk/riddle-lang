# 变量
每一个变量内存储的都是一个类的实例，包括 int,float 等基本类型
每个变量被 Variable 所表示
```c++
class Variable {
    public:
        const std::string name;
        std::string type;
        llvm::Value* value;
        const bool isConst;
        Variable() = delete;
        Variable(const std::string& name,const std::string& type):name(name),type(type),isConst(false){};
        Variable(const std::string& name,const std::string& type,const bool& isConst):name(name),type(type),isConst(isConst){};
    };

```