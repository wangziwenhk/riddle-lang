<div align="center">
  <img src="./resources/logo.svg" alt="Logo" width="250" height="250">
  <h1>Riddle Language</h1>
</div>


Simplified Chinese | [English](./README_en.md)

![Static Badge](https://img.shields.io/badge/C%2B%2B-20-green?logo=C%2B%2B)
![Static Badge](https://img.shields.io/badge/LLVM-18.1.8-purple?logo=LLVm)

![](https://starchart.cc/wangziwenhk/Riddle-Language.svg)
A lightweight, flexible, and modern programming language.

Riddle Language is a memory-safe programming language designed to address the shortcomings of C/C++.

# Features

- **Memory Safety**: Riddle Language ensures memory safety at compile time, eliminating common programming errors such as null pointer dereferencing and buffer overflows. This guarantees the robustness and security of software.
- **High Performance**: Riddle Language combines safety with high-performance execution, making it suitable for resource-intensive applications. This is achieved through advanced optimizations and a meticulously designed runtime system.
- **Simplicity and Expressiveness**: Riddle Language offers a concise and expressive syntax that promotes code readability and maintainability. It provides modern language constructs, powerful abstractions, and a rich set of libraries to simplify the development process.
- **Concurrency and Parallelism**: Riddle Language has built-in support for concurrent and parallel programming. It offers lightweight threads, asynchronous programming models, and synchronization primitives, simplifying the development of scalable and efficient applications.
- **Interoperability**: Riddle Language seamlessly integrates with existing codebases and libraries written in other languages. It provides straightforward bindings with C and C++ and supports interoperability with popular frameworks and ecosystems.

# Tech Stack :rocket:

- [LLVM](https://github.com/llvm/llvm-project)
- [Antlr4](https://github.com/antlr/antlr4)
- [TermColor](https://github.com/ikalnytskyi/termcolor)
- ArgParse
- magic_enum
# License

This project is open-sourced under the [**Apache License 2.0**](https://www.apache.org/licenses/LICENSE-2.0.html). This license requires that **the original copyright
notice, license notice, and disclaimer be retained when modifying and distributing the software**;
it allows users to freely use, modify, copy, and distribute software licensed under Apache for both commercial and non-commercial purposes. Users are allowed to release modified products or derivatives under different licenses, provided that the portions not modified retain the Apache License;
the Apache License does not provide any form of warranty, and users are entirely responsible for any damages caused by using the software.

# Getting Executables
## 1. Download a Release
You can obtain the executables from the [releases page on GitHub](https://github.com/wangziwenhk/riddle-lang/releases).
## 2. Build from Source
### Requirements
- CMake version 3.28 or higher
- A compiler that supports C++20 features
    - GCC version 14 or higher
    - Clang version 18 or higher
    - MSVC 2022 or higher
- LLVM version 18 or higher
- TermColor
- Antlr version 4.13 or higher
- ArgParse 3.0 or higher
- magic_enum 0.9.5 or higher
### Configuration
```bash
mkdir build
cd build
cmake ..
```
### Compilation
```bash
cmake --build . --config Release
```