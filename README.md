# Maze Solver

A simple maze solver that can navigate through various types of mazes, from simple single-row puzzles to complex mazes with rooms, winding paths, and dead ends.

## Requirements

- A C++17 compiler (GCC 9+ or Clang 10+)
- CMake 3.14+
- GoogleTest (found via `find_package`; downloaded automatically with FetchContent if not installed)

## Building

```bash
cmake -S . -B build
cmake --build build
```

## Running the Solution

To run the main demo that shows all user stories:

```bash
./build/maze_demo
```

To run the tests:

```bash
ctest --test-dir build --output-on-failure
# or
./build/test_maze_solver
```

## Implementation

The maze solver uses a breadth-first search (BFS) algorithm to explore the maze. It:
- Parses maze strings into a 2D grid representation
- Finds start (S) and end (E) positions
- Explores all reachable cells using a queue
- Tracks visited positions to avoid loops
- Returns the shortest path from start to end

## User Stories Completed

1. ✅ Find empty space in single-row input
2. ✅ Walk through hallway mazes
3. ✅ Navigate mazes with rooms
4. ✅ Follow winding paths
5. ✅ Handle dead ends and find the exit

---
