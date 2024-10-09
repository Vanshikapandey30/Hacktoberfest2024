Knight's Tour Problem
=====================

Problem Statement
-----------------

The Knight's Tour problem involves finding a sequence of moves for a knight on a chessboard such that the knight visits every square exactly once. The knight moves in an "L" shape: two squares in one direction and one square perpendicular.

Backtracking Approach
---------------------

The backtracking approach explores all possible moves for the knight until it either finds a solution or exhausts all options. The algorithm follows these steps:

1.  Place the knight on the starting square and mark it as visited.
2.  If the knight has visited all squares, return true.
3.  For each possible knight move, check if the move is valid (within bounds and not visited).
4.  If the move is valid, recursively attempt to complete the tour from the new position.
5.  If a recursive call returns true, return true.
6.  If no valid moves lead to a solution, backtrack (unmark the current square).

### Example

Consider the following 5x5 chessboard:

    0  1  2  3  4
    5  6  7  8  9
    10 11 12 13 14
    15 16 17 18 19
    20 21 22 23 24

The knight starts at position (0, 0). A possible knight's tour could be:

    0  10  1  11  2
    7  3  12  20  8
    16  21  4  22  9
    17  5  13  6  18
    19  14  15  24  23

Java Implementation
-------------------

    public class KnightsTour {
        static int N = 5; // Chessboard size
        static int[] rowMoves = {2, 1, -1, -2, -2, -1, 1, 2};
        static int[] colMoves = {1, 2, 2, 1, -1, -2, -2, -1};
    
        public static void main(String[] args) {
            int[][] board = new int[N][N];
            if (solveKnightsTour(board, 0, 0, 1)) {
                printBoard(board);
            } else {
                System.out.println("No solution exists.");
            }
        }
    
        private static boolean solveKnightsTour(int[][] board, int currRow, int currCol, int moveCount) {
            if (moveCount == N * N) {
                return true;
            }
    
            for (int i = 0; i < 8; i++) {
                int nextRow = currRow + rowMoves[i];
                int nextCol = currCol + colMoves[i];
                if (isSafe(board, nextRow, nextCol)) {
                    board[nextRow][nextCol] = moveCount;
                    if (solveKnightsTour(board, nextRow, nextCol, moveCount + 1)) {
                        return true;
                    }
                    board[nextRow][nextCol] = -1; // Backtrack
                }
            }
            return false;
        }
    
        private static boolean isSafe(int[][] board, int row, int col) {
            return (row >= 0 && row < N && col >= 0 && col < N && board[row][col] == 0);
        }
    
        private static void printBoard(int[][] board) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    System.out.print(board[i][j] + "\t");
                }
                System.out.println();
            }
        }
    }
    

Time and Space Complexity
-------------------------

*   **Time Complexity:** O(8^N2), where N is the size of the chessboard. This is because there are up to 8 possible moves from each position, and we may visit each square multiple times.
*   **Space Complexity:** O(N^2) due to the recursion stack and the board array.

Conclusion
----------

The Knight's Tour problem is a classic example of using backtracking to explore all possible moves of a knight on a chessboard. This problem showcases how backtracking can effectively find a solution by exploring all paths.