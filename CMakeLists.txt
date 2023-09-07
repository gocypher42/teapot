cmake_minimum_required(VERSION 3.22.1)

project(teapot
        LANGUAGES CXX
        VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()
if (MSVC)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif()

include(FetchContent)

FetchContent_Declare(fmt
                     GIT_REPOSITORY https://github.com/fmtlib/fmt.git
                     GIT_TAG 10.1.1)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(argparse
                     GIT_REPOSITORY https://github.com/p-ranav/argparse.git
                     GIT_TAG v2.9)
FetchContent_MakeAvailable(argparse)

FetchContent_Declare(spdlog
                     GIT_REPOSITORY https://github.com/gabime/spdlog.git
                     GIT_TAG v1.12.0)
FetchContent_MakeAvailable(spdlog)

add_subdirectory(src)
