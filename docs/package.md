# 库
## 定义
库必须是某个源文件或多个源文件组成的。

源文件的开头必须为用于标名，这样做也可以加快查找库的速度。
```java
package SourceName
```
## 查找顺序
1. 当前工作目录
2. 显式指定的地址
3. 系统默认的库加载路径
   1. `Path` (Windows)
   2. `usr\lib` | `\lib` (Unix \ Linux)