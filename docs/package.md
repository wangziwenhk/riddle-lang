# 库
## 定义
库必须是某个源文件或多个源文件组成的。

源文件的开头必须为用于标名;
```java
package SourceName
```

导入库的方法必须按照包的全限定名导入
```java
import package.name.ClassName
```
或者使用通配符
```java
import package.name.*
```
这种语法会导入指定包下的所有类和接口，但不包括子包中的内容。

## 查找顺序
1. 当前工作目录
2. 显式指定的地址
3. 系统默认的库加载路径
   1. `Path` (Windows)
   2. `usr\lib` | `\lib` (Unix \ Linux)

## 处理方式
![G](https://s2.loli.net/2024/07/15/G8QExmTkqWJHuNZ.png)

我们假设这是一个库的导入图，那么我们可以用拓扑排序在 BuildQueue 中依次编译。