Obstacle Grid Problem
=====================

Problem Definition
------------------

The Obstacle Grid problem requires you to find the number of unique paths from the top-left corner to the bottom-right corner of a grid, where some cells are blocked by obstacles. You can only move down or right. An obstacle is represented by a 1 and a free space by a 0.

### Example

*   Input: Grid =
    
        
                [
                  [0, 0, 0],
                  [0, 1, 0],
                  [0, 0, 0]
                ]
                
    
*   Output: 2
    
        
                There are two unique paths: 
                1. (0,0) → (0,1) → (0,2) → (1,2) → (2,2)
                2. (0,0) → (1,0) → (2,0) → (2,1) → (2,2)
                
    

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach

This approach uses a 2D DP table where dp\[i\]\[j\] represents the number of unique paths to cell (i, j). The value is derived from the number of paths to the cells directly above and to the left.

#### Pseudocode

    function uniquePathsWithObstacles(grid):
        if grid[0][0] == 1 or grid[m-1][n-1] == 1:
            return 0
        create a dp table of size m x n
        for i from 0 to m-1:
            for j from 0 to n-1:
                if grid[i][j] == 1:
                    dp[i][j] = 0
                else if i == 0 and j == 0:
                    dp[i][j] = 1
                else:
                    from_top = dp[i - 1][j] if i > 0 else 0
                    from_left = dp[i][j - 1] if j > 0 else 0
                    dp[i][j] = from_top + from_left
        return dp[m-1][n-1]
    

#### Java Implementation

    public class ObstacleGrid {
        public static int uniquePathsWithObstacles(int[][] grid) {
            int m = grid.length;
            int n = grid[0].length;
    
            if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
                return 0;
            }
    
            int[][] dp = new int[m][n];
            dp[0][0] = 1;
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        dp[i][j] = 0;
                    } else {
                        if (i > 0) dp[i][j] += dp[i - 1][j];
                        if (j > 0) dp[i][j] += dp[i][j - 1];
                    }
                }
            }
            return dp[m - 1][n - 1];
        }
    
        public static void main(String[] args) {
            int[][] grid = {
                {0, 0, 0},
                {0, 1, 0},
                {0, 0, 0}
            };
            System.out.println(uniquePathsWithObstacles(grid)); // Output: 2
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n), where m is the number of rows and n is the number of columns. Each cell is processed once.
*   **Space Complexity:** O(m\*n) for the DP table.

### 2\. Optimized Space Dynamic Programming Approach

This approach reduces the space complexity to O(n) by using a 1D array to store only the results from the previous row.

#### Pseudocode

    function uniquePathsWithObstacles(grid):
        if grid[0][0] == 1 or grid[m-1][n-1] == 1:
            return 0
        create a dp array of size n
        for i from 0 to m-1:
            for j from 0 to n-1:
                if grid[i][j] == 1:
                    dp[j] = 0
                else if i == 0 and j == 0:
                    dp[j] = 1
                else:
                    from_top = dp[j] if i > 0 else 0
                    from_left = dp[j - 1] if j > 0 else 0
                    dp[j] += from_top
        return dp[n - 1]
    

#### Java Implementation

    public class ObstacleGrid {
        public static int uniquePathsWithObstacles(int[][] grid) {
            int m = grid.length;
            int n = grid[0].length;
    
            if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
                return 0;
            }
    
            int[] dp = new int[n];
            dp[0] = 1;
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        dp[j] = 0;
                    } else {
                        if (j > 0) {
                            dp[j] += dp[j - 1];
                        }
                    }
                }
            }
            return dp[n - 1];
        }
    
        public static void main(String[] args) {
            int[][] grid = {
                {0, 0, 0},
                {0, 1, 0},
                {0, 0, 0}
            };
            System.out.println(uniquePathsWithObstacles(grid)); // Output: 2
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n), where m is the number of rows and n is the number of columns. Each cell is processed once.
*   **Space Complexity:** O(n) for the 1D DP array.

Conclusion
----------

The Obstacle Grid problem can be effectively solved using dynamic programming techniques. The standard approach uses a 2D DP table, while the optimized space approach uses a 1D array to minimize space complexity.