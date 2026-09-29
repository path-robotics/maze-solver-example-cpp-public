cmake_minimum_required(VERSION 3.14)
project(maze_solver CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(maze_solver maze_solver.cpp)
target_include_directories(maze_solver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(maze_demo main.cpp)
target_link_libraries(maze_demo PRIVATE maze_solver)
