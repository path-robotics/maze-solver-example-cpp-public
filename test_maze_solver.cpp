#include <gtest/gtest.h>

#include <string>
#include <utility>

#include "maze_solver.h"

TEST(MazeSolverTest, SingleRowMaze) {
    std::string maze = "### ###";
    MazeSolver solver(maze);
    int result = solver.find_empty_space();
    EXPECT_EQ(result, 3);
}

TEST(MazeSolverTest, SimpleHallway) {
    std::string maze = R"(#######
#S    #
##### #
#     #
# #####
#    E#
#######)";
    MazeSolver solver(maze);
    auto path = solver.explore_maze();
    EXPECT_FALSE(path.empty());
    EXPECT_EQ(path.front(), std::make_pair(1, 1));  // Start
    EXPECT_EQ(path.back(), std::make_pair(5, 5));   // End
}

TEST(MazeSolverTest, MazeWithRooms) {
    std::string maze = R"(#########
#S      #
# ##### #
# #   # #
# # # # #
# # # # #
#   #  E#
#########)";
    MazeSolver solver(maze);
    auto path = solver.explore_maze();
    EXPECT_FALSE(path.empty());
    EXPECT_GT(path.size(), 0);
}

// Test maze with no solution
TEST(MazeSolverTest, NoSolution) {
    std::string maze = R"(#####
#S# #
### #
#  E#
#####)";
    MazeSolver solver(maze);
    auto path = solver.explore_maze();
    EXPECT_TRUE(path.empty());
}
