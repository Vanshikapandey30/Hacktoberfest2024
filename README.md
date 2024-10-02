
# Sudoku Solver (C++ Backtracking)

This is a C++ application that solves Sudoku puzzles using the backtracking algorithm. The program supports two modes:
- **Easy Mode** (3x3 Sudoku)
- **Hard Mode** (9x9 Sudoku)

## Table of Contents
- [Features](#features)
- [How it Works](#how-it-works)
- [Installation](#installation)
- [Usage](#usage)

## Features
- Solve Sudoku puzzles using backtracking.
- Two difficulty levels:
  - **Easy**: 3x3 Sudoku grid.
  - **Hard**: Standard 9x9 Sudoku grid.
- Validates if the Sudoku board can be solved.
- Displays the solved Sudoku board.

## How it Works
The application uses backtracking to solve Sudoku. The algorithm attempts to place numbers in empty cells, recursively trying every possible number that follows Sudoku rules (no duplicates in the same row,column,or subgrid). If an invalid placement is found, it backtracks and tries another number.
