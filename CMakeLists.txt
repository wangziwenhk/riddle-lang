cmake_minimum_required(VERSION 3.28)
project(Riddle_Language)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(parser)
include_directories(LLVM-lib)
include_directories(antlr4-runtime)

link_directories(dist)

file(GLOB AST_FILES "parser/*.cpp")
file(GLOB SOURCE_FILES
        "src/*")

add_executable(Riddle_Language ${SOURCE_FILES} ${AST_FILES}
        src/tools.h)

target_link_libraries(Riddle_Language antlr4-runtime)