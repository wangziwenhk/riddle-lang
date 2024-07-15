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
