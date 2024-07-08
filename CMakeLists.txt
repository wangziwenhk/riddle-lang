cmake_minimum_required(VERSION 3.28)
project(Riddle_Language)

set(CMAKE_CXX_STANDARD 17)

include_directories(parser)
link_directories(dist)

add_executable(Riddle_Language src/main.cpp)

target_link_libraries(Riddle_Language antlr4-runtime)