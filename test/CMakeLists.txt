cmake_minimum_required(VERSION 3.2)
project(pascal_tests)

add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)

file(GLOB SOURCE_FILES *.cpp)

add_executable(pascal_tests ${SOURCE_FILES})
target_link_libraries(pascal_tests gtest)
install(TARGETS pascal_tests DESTINATION bin)