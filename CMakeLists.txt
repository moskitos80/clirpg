cmake_minimum_required(VERSION 3.22.0)
project(CliRpg VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

add_compile_options(
    -g3
    -Og
    -Wall
    # -Weffc++
    -Werror
    -Wpedantic
    -Wsign-conversion
)

add_executable(CliRpgGame 
    src/game/Engine.cpp
    src/main.cpp
)

target_include_directories(CliRpgGame PRIVATE src/include)

#######

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(CliRpgTest 
    tests/main.cpp

    src/game/HeroFate.cpp
    tests/game/HeroFate.cpp

    src/game/Creature.cpp
    tests/game/Creature.cpp

    src/game/Player.cpp
    tests/game/Player.cpp

    src/game/Potion.cpp
    tests/game/Potion.cpp
)
target_link_libraries(CliRpgTest GTest::gtest_main)
target_include_directories(CliRpgTest PRIVATE src/include)

include(GoogleTest)
gtest_discover_tests(CliRpgTest)