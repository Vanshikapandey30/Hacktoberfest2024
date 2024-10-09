Maximum Path in Grid Problem
============================

Problem Definition
------------------

The Maximum Path in Grid problem involves finding the maximum sum of values along a path from the top-left corner to the bottom-right corner of a grid. You can only move right, down, or diagonally down-right.

### Example

*   Input: Grid =
    
        
                [
                  [5, 3, 2, 1],
                  [1, 2, 10, 2],
                  [4, 3, 8, 1],
                  [1, 0, 2, 3]
                ]
                
    
*   Output: 25
    
        
                The maximum path is:
                5 → 3 → 10 → 8 → 2 → 3 = 25
                
    

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach

This approach uses a 2D DP table where dp\[i\]\[j\] represents the maximum path sum to reach cell (i, j). The value is derived from the maximum path sums from the cells above, to the left, and diagonally left above.

#### Pseudocode

    function maxPathSum(grid):
        m = number of rows in grid
        n = number of columns in grid
        create a dp table of size m x n
        dp[0][0] = grid[0][0]
        for i from 0 to m-1:
            for j from 0 to n-1:
                if i > 0:
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + grid[i][j])
                if j > 0:
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + grid[i][j])
                if i > 0 and j > 0:
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + grid[i][j])
        return dp[m-1][n-1]
    

#### Java Implementation

    public class MaximumPathInGrid {
        public static int maxPathSum(int[][] grid) {
            int m = grid.length;
            int n = grid[0].length;
    
            int[][] dp = new int[m][n];
            dp[0][0] = grid[0][0];
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i > 0) {
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j] + grid[i][j]);
                    }
                    if (j > 0) {
                        dp[i][j] = Math.max(dp[i][j], dp[i][j - 1] + grid[i][j]);
                    }
                    if (i > 0 && j > 0) {
                        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + grid[i][j]);
                    }
                }
            }
            return dp[m - 1][n - 1];
        }
    
        public static void main(String[] args) {
            int[][] grid = {
                {5, 3, 2, 1},
                {1, 2, 10, 2},
                {4, 3, 8, 1},
                {1, 0, 2, 3}
            };
            System.out.println(maxPathSum(grid)); // Output: 25
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n), where m is the number of rows and n is the number of columns. Each cell is processed once.
*   **Space Complexity:** O(m\*n) for the DP table.

### 2\. Optimized Space Dynamic Programming Approach

This approach reduces the space complexity to O(n) by using a 1D array to store the maximum path sums for the current row, updating it as we progress through the grid.

#### Pseudocode

    function maxPathSum(grid):
        m = number of rows in grid
        n = number of columns in grid
        create a dp array of size n
        dp[0] = grid[0][0]
        for j from 1 to n-1:
            dp[j] = dp[j-1] + grid[0][j]
        for i from 1 to m-1:
            for j from 0 to n-1:
                from_top = dp[j] if i > 0 else 0
                from_left = dp[j - 1] if j > 0 else 0
                from_diag = dp[j - 1] if i > 0 and j > 0 else 0
                dp[j] = grid[i][j] + max(from_top, from_left, from_diag)
        return dp[n - 1]
    

#### Java Implementation

    public class MaximumPathInGrid {
        public static int maxPathSum(int[][] grid) {
            int m = grid.length;
            int n = grid[0].length;
    
            int[] dp = new int[n];
            dp[0] = grid[0][0];
    
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j - 1] + grid[0][j];
            }
    
            for (int i = 1; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int from_top = dp[j];
                    int from_left = (j > 0) ? dp[j - 1] : Integer.MIN_VALUE;
                    int from_diag = (j > 0) ? dp[j - 1] : Integer.MIN_VALUE;
    
                    dp[j] = grid[i][j] + Math.max(from_top, Math.max(from_left, from_diag));
                }
            }
            return dp[n - 1];
        }
    
        public static void main(String[] args) {
            int[][] grid = {
                {5, 3, 2, 1},
                {1, 2, 10, 2},
                {4, 3, 8, 1},
                {1, 0, 2, 3}
            };
            System.out.println(maxPathSum(grid)); // Output: 25
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n), where m is the number of rows and n is the number of columns. Each cell is processed once.
*   **Space Complexity:** O(n) for the 1D DP array.

Conclusion
----------

The Maximum Path in Grid problem can be effectively solved using dynamic programming techniques. The standard approach uses a 2D DP table, while the optimized space approach uses a 1D array to minimize space complexity.