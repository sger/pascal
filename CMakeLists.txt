cmake_minimum_required(VERSION 3.10)
project(pascal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include headers
include_directories(include)

# Collect all source files recursively
file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.cpp")

# Create the executable
add_executable(Pascal ${SOURCES})
