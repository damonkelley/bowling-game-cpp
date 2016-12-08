cmake_minimum_required(VERSION 2.8.9)

option(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(BowlingGame)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CATCH_INCLUDE_DIR extern/catch/include CACHE INTERNAL "Path to include folder for Catch")

enable_testing(true)  # Enables unit-testing.

add_library(BowlingGame src/Game.cpp)

include_directories(
    src
    ${CATCH_INCLUDE_DIR}
    ${COMMON_INCLUDES})

enable_testing(true)  # Enables unit-testing.

add_executable(testsuite test/GameTest.cpp)
target_link_libraries(testsuite BowlingGame)

add_test(NAME Test-Suite COMMAND testsuite)
add_custom_target(check COMMAND testsuite DEPENDS BowlingGame)
