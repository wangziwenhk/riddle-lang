cmake_minimum_required(VERSION 3.28)
project(Riddle_Language)

set(CMAKE_CXX_STANDARD 20)

include_directories(parser)
include_directories(LLVM-lib)
include_directories(antlr4-runtime)

link_directories(${PROJECT_SOURCE_DIR}/dist)

file(GLOB AST_FILES "Parser/*.cpp")
file(GLOB SOURCE_FILES "src/*.cpp")

add_executable(Riddle_Language ${SOURCE_FILES} ${AST_FILES})

target_link_libraries(Riddle_Language antlr4-runtime)