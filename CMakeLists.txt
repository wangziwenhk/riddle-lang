cmake_minimum_required(VERSION 3.28)
project(Riddle_Language)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_path(ANTLR4_INCLUDE_DIR antlr4-runtime/antlr4-runtime.h
        PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)


find_package(LLVM REQUIRED CONFIG)
find_package(antlr4-runtime CONFIG REQUIRED)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Found Antlr4: ${ANTLR4CPP_INCLUDE_DIRS}")

link_directories(dist)

file(GLOB AST_FILES "parser/*.cpp")
file(GLOB SOURCE_FILES "src/*")

add_executable(Riddle_Language ${SOURCE_FILES} ${AST_FILES})

target_include_directories(Riddle_Language PRIVATE ${ANTLR4_INCLUDE_DIR})
target_include_directories(Riddle_Language PRIVATE ${LLVM_INCLUDE_DIRS})
target_include_directories(Riddle_Language PRIVATE parser)
target_link_libraries(Riddle_Language LLVMCore)
target_link_libraries(Riddle_Language antlr4_shared)
