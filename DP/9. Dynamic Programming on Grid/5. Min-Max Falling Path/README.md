Min/Max Falling Path Problem
============================

Problem Definition
------------------

The Min/Max Falling Path problem involves finding a path from the top to the bottom of a given grid (or matrix) such that the sum of the values along the path is minimized or maximized. You can move to the adjacent cells directly below the current cell, which means you can move down, down-left, or down-right.

### Example

*   Input: Grid =
    
        
                [
                  [2, 1, 3],
                  [6, 5, 4],
                  [7, 8, 9]
                ]
                
    
*   Output: Min Falling Path Sum = 12
    
        
                The path is:
                1 → 5 → 6 = 12
                
    

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach

This approach uses a 2D DP table to store the minimum or maximum falling path sums for each cell. The value for each cell is calculated based on the adjacent cells in the previous row.

#### Pseudocode

    function minFallingPathSum(grid):
        n = number of rows in grid
        if n == 0:
            return 0
        m = number of columns in grid
        create a dp table of size n x m
        for j from 0 to m-1:
            dp[0][j] = grid[0][j]
        for i from 1 to n-1:
            for j from 0 to m-1:
                dp[i][j] = grid[i][j] + min(dp[i-1][j], 
                                             dp[i-1][j-1] if j > 0 else infinity, 
                                             dp[i-1][j+1] if j < m-1 else infinity)
        return min(dp[n-1])
    

#### Java Implementation

    public class MinFallingPathSum {
        public static int minFallingPathSum(int[][] grid) {
            int n = grid.length;
            if (n == 0) return 0;
            int m = grid[0].length;
            
            int[][] dp = new int[n][m];
            for (int j = 0; j < m; j++) {
                dp[0][j] = grid[0][j];
            }
            
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int fromAbove = dp[i - 1][j];
                    int fromLeft = (j > 0) ? dp[i - 1][j - 1] : Integer.MAX_VALUE;
                    int fromRight = (j < m - 1) ? dp[i - 1][j + 1] : Integer.MAX_VALUE;
                    dp[i][j] = grid[i][j] + Math.min(fromAbove, Math.min(fromLeft, fromRight));
                }
            }
            
            int minPathSum = Integer.MAX_VALUE;
            for (int j = 0; j < m; j++) {
                minPathSum = Math.min(minPathSum, dp[n - 1][j]);
            }
            return minPathSum;
        }
    
        public static void main(String[] args) {
            int[][] grid = {
                {2, 1, 3},
                {6, 5, 4},
                {7, 8, 9}
            };
            System.out.println(minFallingPathSum(grid)); // Output: 12
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n \* m), where n is the number of rows and m is the number of columns. Each cell is processed once.
*   **Space Complexity:** O(n \* m) for the DP table.

### 2\. Optimized Space Dynamic Programming Approach

This approach reduces the space complexity to O(m) by using a 1D array to store the minimum path sums for the current row, updating it as we progress through the grid.

#### Pseudocode

    function minFallingPathSum(grid):
        n = number of rows in grid
        if n == 0:
            return 0
        m = number of columns in grid
        create a dp array of size m
        for j from 0 to m-1:
            dp[j] = grid[0][j]
        for i from 1 to n-1:
            for j from 0 to m-1:
                fromAbove = dp[j]
                fromLeft = (j > 0) ? dp[j - 1] : infinity
                fromRight = (j < m - 1) ? dp[j + 1] : infinity
                dp[j] = grid[i][j] + min(fromAbove, fromLeft, fromRight)
        return min(dp)
    

#### Java Implementation

    public class MinFallingPathSum {
        public static int minFallingPathSum(int[][] grid) {
            int n = grid.length;
            if (n == 0) return 0;
            int m = grid[0].length;
            
            int[] dp = new int[m];
            for (int j = 0; j < m; j++) {
                dp[j] = grid[0][j];
            }
            
            for (int i = 1; i < n; i++) {
                int[] newDp = new int[m];
                for (int j = 0; j < m; j++) {
                    int fromAbove = dp[j];
                    int fromLeft = (j > 0) ? dp[j - 1] : Integer.MAX_VALUE;
                    int fromRight = (j < m - 1) ? dp[j + 1] : Integer.MAX_VALUE;
                    newDp[j] = grid[i][j] + Math.min(fromAbove, Math.min(fromLeft, fromRight));
                }
                dp = newDp;
            }
            
            int minPathSum = Integer.MAX_VALUE;
            for (int j = 0; j < m; j++) {
                minPathSum = Math.min(minPathSum, dp[j]);
            }
            return minPathSum;
        }
    
        public static void main(String[] args) {
            int[][] grid = {
                {2, 1, 3},
                {6, 5, 4},
                {7, 8, 9}
            };
            System.out.println(minFallingPathSum(grid)); // Output: 12
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n \* m), where n is the number of rows and m is the number of columns. Each cell is processed once.
*   **Space Complexity:** O(m) for the 1D DP array.

Conclusion
----------

The Min/Max Falling Path problem can be efficiently solved using dynamic programming techniques. The standard approach uses a 2D DP table, while the optimized space approach uses a 1D array to minimize space complexity.