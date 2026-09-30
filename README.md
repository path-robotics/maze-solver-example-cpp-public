# Path Robotics Software Interview - Code Review

## Context

A software engineer's responsibilities have shifted significantly in the era of LLM coding agents. We're spending much more time reviewing code than writing it. Judging software quality is more important than ever!

This repository is the output of GitHub Copilot circa December 2025. It was given an programming problem we, Path Robotics, used to give candidates. We're asking you, the candidate, to review the code and provide feedback. Specifically, we're asking :arrow_down:

* Pretend this repository is a pull request made by someone you work with.
* It's your job to give constructive feedback to improve the solution.
* Everything is fair game! Consider things like:
  * Use of data structures
  * Adherence to software design principles
  * Flow control
  * Testing
* **Important:** There is no "right answer" we're expecting.
  * The goal here is to frame a conversation about software quality, not to find some hidden bug or "gotcha".


## Problem Statement (what we asked the agent)

The agent was asked to write a maze solver that could find a path from a start point (S) to an end point (E) in a 2 dimensional maze. Here's an example :arrow_down:

```
#########################
S #   #       #         #
# ### # # ##### ####### #
#   #   #           #   #
### # ############# # # #
# # # #   #       # # # #
# # ### # # ##### # # # #
# #     #   #     # # # #
# ########### ####### # #
# #   #     #   #     # #
# # # # # ##### # ##### #
#   # # #     #   #     #
##### # ##### ##### #####
#     #   #   #   # #   #
# ### # ### # # # # # # #
# #   # #   # # #   # # #
# ##### # ##### ####### #
#       #               E
#########################
```

It was given a single constraint: use C++. Everything else was left up as a judgement call

## Status

This code builds with no warnings at default flags. All 4 tests pass.

You do not need to build anything to do this review. If you want to run it anyway, the project uses CMake and GoogleTest:

```
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```
