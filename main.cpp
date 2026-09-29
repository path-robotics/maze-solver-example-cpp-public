#include <iostream>
#include <string>

#include "maze_solver.h"

int main() {
    // Test User Story 1
    std::string maze1 = "### ###";
    MazeSolver solver(maze1);
    std::cout << solver.solve() << std::endl;

    return 0;
}
