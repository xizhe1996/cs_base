cmake_minimum_required(VERSION 3.16)
project(leetcode_practice LANGUAGES CXX)

# ========= C++ 标准 =========
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ========= 编译输出目录 =========
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ========= 编译选项 =========
if (MSVC)
    add_compile_options(/W4 /Zi)
else()
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -g
        -O0
    )
endif()

# ========= 头文件目录 =========
include_directories(${PROJECT_SOURCE_DIR}/include)

# ========= 收集 src 下所有 cpp 文件 =========
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# 为每个 cpp 生成一个独立可执行文件
foreach(src_file ${SRC_FILES})
    get_filename_component(target_name ${src_file} NAME_WE)
    add_executable(${target_name} ${src_file})
endforeach()