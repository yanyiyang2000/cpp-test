cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3 -fsanitize=address")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(Test LANGUAGES CXX)

add_compile_options(
    -Wall # enable all warnings
)

add_subdirectory(${PROJECT_SOURCE_DIR}/example)
