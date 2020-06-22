cmake_minimum_required(VERSION 3.2)

project(pascal)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(PASCAL_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(src)
add_subdirectory(test)