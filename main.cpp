#include <iostream>
#include <string>

#include "maze_solver.h"

int main() {
    // Test User Story 1
    std::cout << "=== User Story 1 ===" << std::endl;
    std::string maze1 = "### ###";
    MazeSolver solver(maze1);
    std::cout << solver.solve() << std::endl;

    // Test User Story 2
    std::cout << "\n=== User Story 2 ===" << std::endl;
    std::string maze2 = R"(#######
#S    #
##### #
#     #
# #####
#    E#
#######)";
    MazeSolver solver2(maze2);
    std::cout << solver2.solve() << std::endl;

    // Test User Story 3 - rooms
    std::cout << "\n=== User Story 3 ===" << std::endl;
    std::string maze3 = R"(#########
#S      #
# ##### #
# #   # #
# # # # #
# # # # #
#   #  E#
#########)";
    MazeSolver solver3(maze3);
    std::cout << solver3.solve() << std::endl;

    // Test User Story 4 - winding paths
    std::cout << "\n=== User Story 4 ===" << std::endl;
    std::string maze4 = R"(###########
#S        #
##### ### #
#   # #   #
# # # # ###
# # #   # #
# ### # # #
#     #  E#
###########)";
    MazeSolver solver4(maze4);
    std::cout << solver4.solve() << std::endl;

    // Test User Story 5 - dead ends
    std::cout << "\n=== User Story 5 ===" << std::endl;
    std::string maze5 = R"(#########
#S#     #
# # ### #
# #   # #
# ### # #
#     #E#
#########)";
    MazeSolver solver5(maze5);
    std::cout << solver5.solve() << std::endl;

    return 0;
}
