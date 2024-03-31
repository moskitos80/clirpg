cmake_minimum_required(VERSION 3.22.0)
project(CliRpg VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

set(INC_DIRS include)
set(SRC_FILES src/main.cpp)
set(TEST_FILES tests/main.cpp)
list(APPEND ${TEST_FILES} ${SRC_FILES})

add_compile_options(
    -g3
    -Og
    -Wall
    # -Weffc++
    -Werror
    -Wpedantic
    -Wsign-conversion
)

add_executable(CliRpgGame ${SRC_FILES})
target_include_directories(CliRpgGame PRIVATE ${INC_DIRS})

#######

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(CliRpgTest ${TEST_FILES})
target_include_directories(CliRpgTest PRIVATE ${INC_DIRS})

target_link_libraries(CliRpgTest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(CliRpgTest)