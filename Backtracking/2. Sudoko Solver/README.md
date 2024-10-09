Sudoku Solver
=============

Problem Statement
-----------------

The Sudoku problem is a classic puzzle that involves filling a 9×9 grid with digits from 1 to 9. The grid is divided into nine 3×3 sub-grids, and the following rules must be satisfied:

*   Each row must contain the digits 1 to 9 without repetition.
*   Each column must contain the digits 1 to 9 without repetition.
*   Each 3×3 sub-grid must contain the digits 1 to 9 without repetition.

Backtracking Approach
---------------------

Backtracking is a common algorithmic technique for solving constraint satisfaction problems like Sudoku. The basic idea is to fill the board one cell at a time, checking for validity, and backtrack if we reach an invalid state.

### Steps

1.  Find an empty cell in the grid.
2.  Try filling the cell with digits from 1 to 9.
3.  Check if the digit placement is valid (i.e., it does not violate Sudoku rules).
4.  If valid, recursively attempt to fill the next empty cell.
5.  If the board is solved, return true. If not, backtrack (remove the digit and try the next one).
6.  Repeat until the board is solved or no digits are left to try.

Example
-------

Consider the following partially filled Sudoku grid:

    5 3 . | . 7 . | . . .
    6 . . | 1 9 5 | . . .
    . 9 8 | . . . | . 6 .
    ---------------------
    8 . . | . 6 . | . . 3
    4 . . | 8 . 3 | . . 1
    7 . . | . 2 . | . . 6
    ---------------------
    . 6 . | . . . | 2 8 .
    . . . | 4 1 9 | . . 5
    . . . | . 8 . | . 7 9

The solution will fill in the empty cells according to the Sudoku rules.

Java Implementation
-------------------

    public class SudokuSolver {
        public static void main(String[] args) {
            char[][] board = {
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
            };
    
            if (solveSudoku(board)) {
                printBoard(board);
            } else {
                System.out.println("No solution exists");
            }
        }
    
        public static boolean solveSudoku(char[][] board) {
            for (int row = 0; row < 9; row++) {
                for (int col = 0; col < 9; col++) {
                    if (board[row][col] == '.') {
                        for (char num = '1'; num <= '9'; num++) {
                            if (isValid(board, row, col, num)) {
                                board[row][col] = num;
    
                                if (solveSudoku(board)) {
                                    return true;
                                }
    
                                board[row][col] = '.'; // backtrack
                            }
                        }
                        return false; // No valid number found, need to backtrack
                    }
                }
            }
            return true; // Solved
        }
    
        private static boolean isValid(char[][] board, int row, int col, char num) {
            for (int i = 0; i < 9; i++) {
                if (board[row][i] == num || board[i][col] == num ||
                    board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == num) {
                    return false;
                }
            }
            return true;
        }
    
        private static void printBoard(char[][] board) {
            for (int r = 0; r < 9; r++) {
                for (int d = 0; d < 9; d++) {
                    System.out.print(board[r][d] + " ");
                }
                System.out.print("\n");
            }
        }
    }
    

Time and Space Complexity
-------------------------

*   **Time Complexity:** O(9^(N\*N)), where N is the number of empty cells (worst case). This is because, in the worst case, we might have to try all numbers for each empty cell.
*   **Space Complexity:** O(N^2) due to the recursion stack. In this case, N is 9 for a standard Sudoku grid.

Conclusion
----------

The Sudoku Solver is an excellent example of the backtracking technique, demonstrating how to systematically explore potential solutions while adhering to constraints. The approach can be adapted to various similar constraint satisfaction problems.