cmake_minimum_required(VERSION 3.2)
project(pascal)

# add_subdirectory(division)
# set(SOURCE_FILES main.cpp sample.cpp)
file(GLOB SOURCE_FILES *.cpp)

add_executable(pascal ${SOURCE_FILES})
# target_link_libraries(divider division)
install(TARGETS pascal DESTINATION ${PASCAL_INSTALL_BIN_DIR})