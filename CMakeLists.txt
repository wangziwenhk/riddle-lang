cmake_minimum_required(VERSION 3.22.1)

project(riddle-lang VERSION 0.1 LANGUAGES CXX C)

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
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=lld")
elseif (LINUX)
    set(PLATFORM_DEFINES "-DLINUX")
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections")
    add_compile_options(-ffunction-sections -fdata-sections)
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Wl,--strip-all")
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

if (MSVC)
    add_compile_options(/wd4819)
endif ()

# 添加编译目标选择
set(RIDDLE_BUILD_TARGET "ALL" CACHE STRING "Specify target architectures (e.g., X86,ARM)")

# 处理 ALL
if (${RIDDLE_BUILD_TARGET} STREQUAL "ALL")
    set(RIDDLE_BUILD_TARGET "X86,ARM,AARCH64,AMDGPU,AVR,PBF,HEXGON")
endif ()

if (RIDDLE_BUILD_TARGET)
    string(REPLACE "," ";" TARGET_LIST "${RIDDLE_BUILD_TARGET}")
endif ()

message(STATUS "Target architectures: ${TARGET_LIST}")

# 基础组件
set(llvm_components core irreader support analysis passes codegen target mc object)

foreach (TARGET IN LISTS TARGET_LIST)
    if (${TARGET} STREQUAL "X86")
        add_definitions(-DRIDDLE_TARGET_X86)
        list(APPEND llvm_components x86asmparser x86desc x86codegen x86disassembler x86targetmca)
    elseif (${TARGET} STREQUAL "ARM")
        add_definitions(-DRIDDLE_TARGET_ARM)
        list(APPEND llvm_components armasmparser armdesc armcodegen armdisassembler)
    elseif (${TARGET} STREQUAL "AARCH64")
        add_definitions(-DRIDDLE_TARGET_AARCH64)
        list(APPEND llvm_components aarch64asmparser aarch64desc aarch64codegen aarch64disassembler)
    elseif (${TARGET} STREQUAL "AMDGPU")
        add_definitions(-DRIDDLE_TARGET_AMDGPU)
        list(APPEND llvm_components amdgpuasmparser amdgputargetmca amdgpucodegen amdgpuinfo amdgpudisassembler)
    elseif (${TARGET} STREQUAL "AVR")
        add_definitions(-DRIDDLE_TARGET_AVR)
        list(APPEND llvm_components avrasmparser avrdesc avrcodegen avrdisassembler)
    elseif (${TARGET} STREQUAL "BPF")
        add_definitions(-DRIDDLE_TARGET_BPF)
        list(APPEND llvm_components bpfasmparser bpfdesc bpfcodegen bpfdisassembler)
    elseif (${TARGET} STREQUAL "HEXGON")
        add_definitions(-DRIDDLE_TARGET_HEXGON)
        list(APPEND llvm_components hexagonasmparser hexagondesc hexagoncodegen hexagondisassembler)
    else ()
        message(WARNING "Unknown target: ${TARGET}")
    endif ()
endforeach ()

llvm_map_components_to_libnames(llvm_libs ${llvm_components})

#llvm_map_components_to_libnames(llvm_libs
#        core irreader support analysis passes codegen target mc object
#        # X86
#        x86asmparser x86desc x86codegen x86disassembler x86targetmca
#        # Aarch
#        aarch64asmparser aarch64desc aarch64codegen aarch64disassembler
#        # arm
#        armasmparser armdesc armcodegen armdisassembler
#        # amdgpu
#        amdgpuasmparser amdgputargetmca amdgpucodegen amdgpuinfo amdgpudisassembler
#        # avr
#        avrasmparser avrdesc avrcodegen avrdisassembler
#        # bpf
#        bpfasmparser bpfdesc bpfcodegen bpfdisassembler
#        # hexgon
#        hexagonasmparser hexagondesc hexagoncodegen hexagondisassembler
#        # lanai
#        lanaiasmparser lanaidesc lanaicodegen lanaidisassembler
#        # loongarch
#        loongarchasmparser loongarchdesc loongarchcodegen loongarchdisassembler
#        # mips
#        mipsasmparser mipsdesc mipscodegen mipsdisassembler
#        # msp430
#        msp430asmparser msp430desc msp430codegen msp430disassembler
#        # nvptx
#        nvptxcodegen nvptxdesc
#        # powerpc
#        powerpcasmparser powerpcdesc powerpcdisassembler powerpccodegen powerpcinfo
#        # riscv
#        riscvasmparser riscvdesc riscvcodegen riscvdisassembler riscvtargetmca
#        # sparc
#        sparcasmparser sparcdesc sparccodegen sparcdisassembler
#        # spirv
#        spirvcodegen spirvdesc
#        # systemz
#        systemzasmparser systemzdesc systemzcodegen systemzdisassembler
#        # ve
#        vecodegen vedesc vedisassembler veasmparser
#        # xcore
#        xcoredesc xcorecodegen xcoredisassembler
#        # wasm
#        WebAssemblyAsmParser WebAssemblyCodeGen WebAssemblyDesc WebAssemblyDisassembler WebAssemblyInfo WebAssemblyUtils
#)


message(STATUS "LLVM libraries: ${llvm_libs}")

target_link_libraries(riddle ${llvm_libs})
target_link_libraries(riddle riddle-module)
target_link_libraries(riddle antlr4_shared)
target_link_libraries(riddle argparse::argparse)
target_link_libraries(riddle magic_enum::magic_enum)

if (Windows)
    set(CMAKE_INSTALL_PREFIX "C:/Program Files/Riddle" CACHE PATH "Installation prefix, default is C:/Program Files/Riddle")
endif ()

install(TARGETS riddle DESTINATION bin)