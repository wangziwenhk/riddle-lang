cmake_minimum_required(VERSION 3.30)

project(riddle-lang VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

message(STATUS "Current operating system: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Current C++ compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Current C compiler: ${CMAKE_C_COMPILER_ID}")
message(STATUS "Current build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Current generator: ${CMAKE_GENERATOR}")

# Enter the system type for better searching of the database.
if (WIN32)
    set(PLATFORM_DEFINES "-DWIN32")
else (LINUX)
    set(PLATFORM_DEFINES "-DLINUX")
endif ()

find_path(ANTLR4_INCLUDE_DIR antlr4-runtime/antlr4-runtime.h
        PATHS ${CMAKE_PREFIX_PATH} NO_DEFAULT_PATH)

find_package(LLVM REQUIRED CONFIG)
find_package(antlr4-runtime CONFIG REQUIRED)
find_path(TERMCOLOR_INCLUDE_DIRS "termcolor/termcolor.hpp")
find_package(argparse CONFIG REQUIRED)
find_package(magic_enum CONFIG REQUIRED)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Found Antlr4 include ${ANTLR4_INCLUDE_DIR}")
message(STATUS "Found Termcolor include ${TERMCOLOR_INCLUDE_DIRS}")

include_directories(src)
include_directories(parser)
include_directories(${TERMCOLOR_INCLUDE_DIRS})
include_directories(${ANTLR4_INCLUDE_DIR})
include_directories(${LLVM_INCLUDE_DIRS})

execute_process(
        COMMAND git describe --tags --always
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

configure_file(
        "resources/config.h.in"
        "${CMAKE_SOURCE_DIR}/src/config.h"
)

file(GLOB_RECURSE AST_FILES "parser/*.cpp" "parser/*.h")
file(GLOB_RECURSE HEADER_FILES "src/*.h")
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
file(GLOB_RECURSE MODULE_FILES "src/*.ixx")

list(FILTER SOURCE_FILES EXCLUDE REGEX ".*main.cpp$")

# 添加 模块编译
add_library(riddle-module ${SOURCE_FILES})

target_sources(riddle-module PUBLIC FILE_SET CXX_MODULES FILES ${MODULE_FILES})

# 添加 主编译目标
add_executable(riddle src/main.cpp ${SOURCE_FILES} ${AST_FILES})
add_executable(test test/test.cpp ${SOURCE_FILES} ${AST_FILES})

if (MSVC)
    add_compile_options(/wd4819)
endif ()

llvm_map_components_to_libnames(llvm_libs linker core irreader support analysis passes)
message(STATUS "LLVM libraries: ${llvm_libs}")

target_link_libraries(riddle ${llvm_libs})
target_link_libraries(riddle riddle-module)
target_link_libraries(riddle antlr4_shared)
target_link_libraries(riddle argparse::argparse)
target_link_libraries(riddle magic_enum::magic_enum)

target_link_libraries(test ${llvm_libs})
target_link_libraries(test riddle-module)
target_link_libraries(test antlr4_shared)
target_link_libraries(test argparse::argparse)
target_link_libraries(test magic_enum::magic_enum)
