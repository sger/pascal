cmake_minimum_required(VERSION 3.10)
project(pascal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable clang-tidy
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=clang-analyzer-*,modernize-*,readability-*")

# Include headers
include_directories(include)

# Collect all source files recursively
file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.cpp")

# Create the executable
add_executable(pascal ${SOURCES})
