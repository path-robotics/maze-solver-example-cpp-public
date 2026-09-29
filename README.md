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

## Part 2: Analysis

### Analysis Story 1: Limitations

My algorithm may not solve correctly for:

1. **Mazes without a valid start (S) or end (E) marker** - The algorithm requires both markers to function. It will return "No solution found" if either is missing.

2. **Mazes with multiple possible paths** - While the algorithm will find A solution, it doesn't necessarily find ALL solutions or allow the user to choose between them.

3. **Very large mazes** - The current implementation stores the entire path history for each explored position in the queue, which could consume significant memory for large mazes.

4. **Mazes with diagonal movement** - The current implementation only checks 4 directions (up, down, left, right). If diagonal movement is allowed, it won't find those paths.

### Analysis Story 2: Complexity and Optimization

**Current Complexity:**
- Time Complexity: O(R × C) where R is rows and C is columns, as we may visit each cell once
- Space Complexity: O(R × C × P) where P is the path length, since we store the full path for each queue entry

**Optimization Approaches:**

1. **Path Reconstruction** - Instead of storing the complete path in each queue entry, store only the parent pointer for each cell. Reconstruct the path at the end by backtracking through parents. This reduces space complexity to O(R × C).

2. **Better Data Structures** - Currently using a `std::vector` for the queue (with `erase(begin())` being O(n)). Using `std::deque` or `std::queue` would make queue operations O(1).

3. **Heuristic Search (A\*)** - For finding optimal paths faster, implement A\* algorithm with Manhattan distance heuristic. This could significantly reduce the number of cells explored in larger mazes.

4. **Early Termination** - The current BFS already stops when finding the end, but we could add additional pruning strategies.

5. **Maze Representation** - Currently storing the maze as a vector of strings. Converting to a more efficient 2D data structure could improve access times.
