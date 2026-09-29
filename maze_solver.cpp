#include "maze_solver.h"

#include <algorithm>
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

void MazeSolver::find_start_and_end() {
    for (int row_idx = 0; row_idx < maze.size(); row_idx++) {
        for (int col_idx = 0; col_idx < maze[row_idx].size(); col_idx++) {
            char c = maze[row_idx][col_idx];
            if (c == 'S') {
                start = std::make_pair(row_idx, col_idx);
            } else if (c == 'E') {
                end = std::make_pair(row_idx, col_idx);
            }
        }
    }
}

std::vector<std::pair<int, int>> MazeSolver::walk_hallway() {
    if (start.first == -1 || end.first == -1) {
        find_start_and_end();
    }

    if (start.first == -1 || end.first == -1) {
        return {};
    }

    std::pair<int, int> current = start;
    path = {current};

    // Simple approach: try moving right, down, left, up
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (current != end) {
        int row = current.first;
        int col = current.second;
        bool moved = false;

        for (auto& dir : directions) {
            int new_row = row + dir.first;
            int new_col = col + dir.second;

            // Check bounds
            if (new_row >= 0 && new_row < maze.size() && new_col >= 0 && new_col < maze[new_row].size()) {
                char cell = maze[new_row][new_col];
                std::pair<int, int> new_pos(new_row, new_col);

                // Move if it's empty space or the end, and we haven't been there
                if ((cell == ' ' || cell == 'E') && std::find(path.begin(), path.end(), new_pos) == path.end()) {
                    current = new_pos;
                    path.push_back(current);
                    moved = true;
                    break;
                }
            }
        }

        if (!moved) {
            break;
        }
    }

    if (current == end) {
        return path;
    }
    return {};
}

std::string MazeSolver::solve() {
    // Check if single row first
    if (maze.size() == 1) {
        int result = find_empty_space();
        if (result != -1) {
            return "Empty space found at position " + std::to_string(result);
        }
    }

    // Try hallway walking
    std::vector<std::pair<int, int>> result = walk_hallway();
    if (!result.empty()) {
        std::ostringstream out;
        out << "Path found with " << result.size() << " steps: [";
        for (size_t i = 0; i < result.size(); i++) {
            if (i > 0) {
                out << ", ";
            }
            out << "(" << result[i].first << ", " << result[i].second << ")";
        }
        out << "]";
        return out.str();
    }

    return "No solution found";
}
