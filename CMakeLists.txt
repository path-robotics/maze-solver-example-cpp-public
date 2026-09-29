cmake_minimum_required(VERSION 3.14)
project(maze_solver CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(maze_solver maze_solver.cpp)
target_include_directories(maze_solver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(GTest)
if(NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    FetchContent_MakeAvailable(googletest)
endif()

enable_testing()
add_executable(test_maze_solver test_maze_solver.cpp)
target_link_libraries(test_maze_solver PRIVATE maze_solver GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(test_maze_solver)
