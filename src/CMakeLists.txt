cmake_minimum_required(VERSION 3.2)
project(pascal)

file(GLOB SOURCE_FILES *.cpp)

add_executable(pascal ${SOURCE_FILES})
install(TARGETS pascal DESTINATION ${PASCAL_INSTALL_BIN_DIR})