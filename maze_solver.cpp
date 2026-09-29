#include "maze_solver.h"

#include <sstream>

MazeSolver::MazeSolver(std::string maze_string) {
    std::stringstream ss(maze_string);
    std::string line;
    while (std::getline(ss, line)) {
        maze.push_back(line);
    }
}

int MazeSolver::find_empty_space() {
    if (maze.size() == 1) {
        std::string row = maze[0];
        for (int i = 0; i < row.size(); i++) {
            if (row[i] == ' ') {
                return i;
            }
        }
    }
    return -1;
}

std::string MazeSolver::solve() {
    // For now, just handle single row
    int result = find_empty_space();
    if (result != -1) {
        return "Empty space found at position " + std::to_string(result);
    }
    return "No solution found";
}
