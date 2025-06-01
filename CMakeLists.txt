cmake_minimum_required(VERSION 3.14)  # Use 3.14+ for full vcpkg & GTest support
project(pascal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable clang-tidy (optional)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=clang-analyzer-*,modernize-*,readability-*")

# Enable testing support
enable_testing()

# Include headers
include_directories(include)

# === Main Application ===
file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.cpp")
add_executable(pascal ${SOURCES})

# === Unit Tests ===
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

if(TEST_SOURCES)  # Only build tests if they exist
    find_package(GTest CONFIG REQUIRED)

    add_executable(pascal_tests ${TEST_SOURCES})
    target_include_directories(pascal_tests PRIVATE include)
    target_link_libraries(pascal_tests PRIVATE GTest::gtest GTest::gtest_main)

    add_test(NAME pascal_tests COMMAND pascal_tests)
endif()
