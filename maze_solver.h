#pragma once

#include <string>
#include <utility>
#include <vector>

class MazeSolver {
public:
    MazeSolver(std::string maze_string);

    // User Story 1: Find the empty space in a single-row input
    int find_empty_space();

    // Find S (start) and E (end) positions in maze
    void find_start_and_end();

    // User Story 2: Walk through a straight hallway maze
    std::vector<std::pair<int, int>> walk_hallway();

    // Main solving method
    std::string solve();

    std::vector<std::string> maze;
    std::pair<int, int> start{-1, -1};
    std::pair<int, int> end{-1, -1};
    std::vector<std::pair<int, int>> path;
};
