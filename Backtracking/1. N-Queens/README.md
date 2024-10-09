N-Queens Problem
================

Problem Statement
-----------------

The N-Queens Problem is a classic combinatorial problem that asks how to place `N` queens on an `N × N` chessboard so that no two queens threaten each other. This means that no two queens can be in the same row, column, or diagonal.

Backtracking Approach
---------------------

Backtracking is a systematic method for exploring all possible configurations to solve a problem. In the context of the N-Queens Problem, the idea is to place queens one row at a time, checking for conflicts as we proceed.

### Steps

1.  Start in the leftmost column.
2.  Try all rows in the current column. For each row, check if placing the queen there would lead to a conflict.
3.  If placing the queen does not lead to a conflict, place it and move to the next column.
4.  If all queens are placed successfully, record the solution.
5.  If a conflict occurs, backtrack: remove the queen from the current position and try the next row.
6.  Repeat until all solutions are found.

Example
-------

Consider the 4-Queens problem. The possible solutions are:

*       Q . . .
        . . Q .
        . . . Q
        . Q . .
    
*       . Q . .
        . . . Q
        Q . . .
        . . Q .
    

Java Implementation
-------------------

    import java.util.ArrayList;
    import java.util.List;
    
    public class NQueens {
        public static void main(String[] args) {
            int n = 4; // Size of the chessboard
            List> solutions = solveNQueens(n);
            for (List solution : solutions) {
                for (String row : solution) {
                    System.out.println(row);
                }
                System.out.println();
            }
        }
    
        public static List> solveNQueens(int n) {
            List> result = new ArrayList<>();
            boolean[] column = new boolean[n];
            boolean[] diagonal1 = new boolean[2 * n - 1];
            boolean[] diagonal2 = new boolean[2 * n - 1];
            backtrack(result, new ArrayList<>(), 0, n, column, diagonal1, diagonal2);
            return result;
        }
    
        private static void backtrack(List> result, List current, int row, int n,
                                       boolean[] column, boolean[] diagonal1, boolean[] diagonal2) {
            if (row == n) {
                result.add(new ArrayList<>(current));
                return;
            }
            for (int col = 0; col < n; col++) {
                if (!column[col] && !diagonal1[row + col] && !diagonal2[row - col + n - 1]) {
                    char[] rowChars = new char[n];
                    for (int i = 0; i < n; i++) {
                        rowChars[i] = '.';
                    }
                    rowChars[col] = 'Q';
                    current.add(new String(rowChars));
                    column[col] = true;
                    diagonal1[row + col] = true;
                    diagonal2[row - col + n - 1] = true;
    
                    backtrack(result, current, row + 1, n, column, diagonal1, diagonal2);
    
                    current.remove(current.size() - 1);
                    column[col] = false;
                    diagonal1[row + col] = false;
                    diagonal2[row - col + n - 1] = false;
                }
            }
        }
    }
    

Time and Space Complexity
-------------------------

*   **Time Complexity:** O(N!), where N is the number of queens. This is because we have N choices for the first queen, (N-1) for the second, and so on.
*   **Space Complexity:** O(N), due to the recursion stack and storage for the board configuration.

Conclusion
----------

The N-Queens Problem is an excellent example of backtracking and demonstrates how to systematically explore potential solutions. The approach can be adapted to various combinatorial problems, making it a valuable technique in algorithm design.