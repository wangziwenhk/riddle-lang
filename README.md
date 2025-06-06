<div align="center">
  <img src="./resources/logo.svg" alt="Logo" width="250" height="250">
  <h1>Riddle Language</h1>
</div>

# 当前仓库已经被废弃，请转到https://github.com/wangziwenhk/riddle

简体中文 | [English](./README_en.md)

![Static Badge](https://img.shields.io/badge/C%2B%2B-20-green?logo=C%2B%2B)
![Static Badge](https://img.shields.io/badge/LLVM-18.1.8-purple?logo=LLVm)

![](https://starchart.cc/wangziwenhk/Riddle-Language.svg)
轻便，灵活，现代化的编程语言。

Riddle Language 是一个内存安全的编程语言，用于修复 C/C++ 的不足之处而出现。

如果你需要代码补全和语言支持，请看
- [VSCode 插件](https://github.com/wangziwenhk/riddle-lang-vscode) 
- [Riddle 手册](https://wangziwenhk.github.io/riddle-docs/)

QQ群号：677741637

# 特性

- 内存安全：Riddle Language 在编译时保证内存安全，消除常见的编程错误，如空指针解引用和缓冲区溢出。这确保了软件的健壮性和安全性。
- 高性能：Riddle Language 将安全性与高性能执行相结合，使其适用于资源密集型应用。通过高级优化和精心设计的运行时系统实现这一目标。
- 简洁和表达力：Riddle Language 提供了简洁且富有表达力的语法，促进代码的可读性和可维护性。它提供了现代语言结构、强大的抽象和丰富的库集，以简化开发过程。
- 并发和并行：Riddle Language 内置对并发和并行编程的支持。它提供轻量级线程、异步编程模型和同步原语，简化了可扩展和高效应用程序的开发。
- 互操作性：Riddle Language 无缝集成现有的代码库和用其他语言编写的库。它提供了与 C 和 C++ 的简单绑定，并支持与流行框架和生态系统的互操作性。

# 技术栈 :rocket:

- [LLVM](https://github.com/llvm/llvm-project)
- [Antlr4](https://github.com/antlr/antlr4)
- [TermColor](https://github.com/ikalnytskyi/termcolor)
- ArgParse
- magic_enum

# 许可证

本项目使用 [**Apache License 2.0**](https://www.apache.org/licenses/LICENSE-2.0.html) 开放源代码，此协议要求**在修改和分发软件时保留原始的版权声明、许可证声明和免责声明**；
允许用户自由地使用、修改、复制和分发 Apache 许可的软件，无论是用于商业用途还是非商业用途；允许用户以不同的许可证发布修改后的产品或衍生品，但未做修改的那部分必须保留 Apache 许可证；
Apache 许可证没有提供任何形式的保证，用户对使用软件所造成的任何损害负有全部责任。

# 获取可执行程序
## 1. 下载发行版
你可以通过 github 的[发行版页面](https://github.com/wangziwenhk/riddle-lang/releases)获取可执行程序
## 2. 自行构建
### 准备
- Cmake 3.28 及以上版本
- 支持 C++ 20 特性的编译器
  - GCC 14 及以上版本
  - Clang 18 及以上版本
  - MSVC 2022 及以上版本
- LLVM 18 及以上版本
- TermColor
- Antlr 4.13 及以上版本
- ArgParse 3.0 及以上版本
- magic_enum 0.9.5 及以上版本
### 配置
```bash
mkdir build
cd build
cmake ..
```
### 编译
```bash
cmake --build . --config Release
```
