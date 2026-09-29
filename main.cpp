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

    return 0;
}
