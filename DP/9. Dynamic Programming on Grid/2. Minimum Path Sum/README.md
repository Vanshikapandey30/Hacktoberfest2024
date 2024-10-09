Minimum Path Sum Problem
========================

Problem Definition
------------------

The Minimum Path Sum problem involves finding the path from the top-left corner to the bottom-right corner of a grid such that the sum of the values along the path is minimized. You can only move either down or right at any point in time.

### Example

*   Input: Grid =
    
        
                [
                  [1, 3, 1],
                  [1, 5, 1],
                  [4, 2, 1]
                ]
                
    
*   Output: 7
    
        
                The minimum path sum is 7 (1 → 3 → 1 → 1).
                
    

Solution Approaches
-------------------

### 1\. Recursive Approach

This approach uses recursion to explore all possible paths from the top-left to the bottom-right corner. The base case is when you reach the bottom-right corner.

#### Pseudocode

    function minPathSumRecursive(grid, row, col):
        if row == 0 and col == 0:
            return grid[0][0]
        if row < 0 or col < 0:
            return infinity
        return grid[row][col] + min(minPathSumRecursive(grid, row - 1, col), minPathSumRecursive(grid, row, col - 1))
    

#### Java Implementation

    public class MinimumPathSum {
        public static int minPathSumRecursive(int[][] grid, int row, int col) {
            if (row == 0 && col == 0) {
                return grid[0][0];
            }
            if (row < 0 || col < 0) {
                return Integer.MAX_VALUE;
            }
            return grid[row][col] + Math.min(minPathSumRecursive(grid, row - 1, col), minPathSumRecursive(grid, row, col - 1));
        }
    
        public static void main(String[] args) {
            int[][] grid = {
                {1, 3, 1},
                {1, 5, 1},
                {4, 2, 1}
            };
            System.out.println(minPathSumRecursive(grid, 2, 2)); // Output: 7
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2^(m+n)), where m is the number of rows and n is the number of columns. The exponential growth is due to the branching factor at each step.
*   **Space Complexity:** O(m+n) due to the recursion stack.

### 2\. Memoization Approach

This approach uses recursion with memoization to store already computed results, significantly reducing the number of calculations.

#### Pseudocode

    function minPathSumMemo(grid, row, col, memo):
        if row == 0 and col == 0:
            return grid[0][0]
        if row < 0 or col < 0:
            return infinity
        if memo[row][col] is not set:
            memo[row][col] = grid[row][col] + min(minPathSumMemo(grid, row - 1, col, memo), minPathSumMemo(grid, row, col - 1, memo))
        return memo[row][col]
    
    function minPathSum(grid):
        initialize memo table with -1
        return minPathSumMemo(grid, m-1, n-1, memo)
    

#### Java Implementation

    public class MinimumPathSum {
        public static int minPathSumMemo(int[][] grid, int row, int col, int[][] memo) {
            if (row == 0 && col == 0) {
                return grid[0][0];
            }
            if (row < 0 || col < 0) {
                return Integer.MAX_VALUE;
            }
            if (memo[row][col] != -1) {
                return memo[row][col];
            }
            memo[row][col] = grid[row][col] + Math.min(minPathSumMemo(grid, row - 1, col, memo), minPathSumMemo(grid, row, col - 1, memo));
            return memo[row][col];
        }
    
        public static int minPathSum(int[][] grid) {
            int m = grid.length;
            int n = grid[0].length;
            int[][] memo = new int[m][n];
            for (int[] row : memo) {
                Arrays.fill(row, -1);
            }
            return minPathSumMemo(grid, m - 1, n - 1, memo);
        }
    
        public static void main(String[] args) {
            int[][] grid = {
                {1, 3, 1},
                {1, 5, 1},
                {4, 2, 1}
            };
            System.out.println(minPathSum(grid)); // Output: 7
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n), where m is the number of rows and n is the number of columns. Each cell is computed once.
*   **Space Complexity:** O(m\*n) for the memoization table.

### 3\. Dynamic Programming Approach

This approach uses a bottom-up dynamic programming table to store the minimum path sums to each cell in the grid.

#### Pseudocode

    function minPathSumDP(grid):
        create a dp table of size m x n
        for i from 0 to m-1:
            for j from 0 to n-1:
                if i == 0 and j == 0:
                    dp[i][j] = grid[i][j]
                else if i == 0:
                    dp[i][j] = dp[i][j - 1] + grid[i][j]
                else if j == 0:
                    dp[i][j] = dp[i - 1][j] + grid[i][j]
                else:
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1])
        return dp[m-1][n-1]
    

#### Java Implementation

    public class MinimumPathSum {
        public static int minPathSumDP(int[][] grid) {
            int m = grid.length;
            int n = grid[0].length;
            int[][] dp = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0 && j == 0) {
                        dp[i][j] = grid[i][j];
                    } else if (i == 0) {
                        dp[i][j] = dp[i][j - 1] + grid[i][j];
                    } else if (j == 0) {
                        dp[i][j] = dp[i - 1][j] + grid[i][j];
                    } else {
                        dp[i][j] = grid[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
            return dp[m - 1][n - 1];
        }
    
        public static void main(String[] args) {
            int[][] grid = {
                {1, 3, 1},
                {1, 5, 1},
                {4, 2, 1}
            };
            System.out.println(minPathSumDP(grid)); // Output: 7
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n), where m is the number of rows and n is the number of columns. Each cell is computed once.
*   **Space Complexity:** O(m\*n) for the DP table.

### 4\. Optimized Space Dynamic Programming Approach

This approach optimizes the space complexity by using a single array instead of a 2D DP table.

#### Pseudocode

    function minPathSumOptimized(grid):
        create a dp array of size n
        for i from 0 to m-1:
            for j from 0 to n-1:
                if j == 0:
                    dp[j] = dp[j] + grid[i][j] if i > 0 else grid[i][j]
                else:
                    dp[j] = grid[i][j] + min(dp[j], dp[j - 1])
        return dp[n - 1]
    

#### Java Implementation

    public class MinimumPathSum {
        public static int minPathSumOptimized(int[][] grid) {
            int m = grid.length;
            int n = grid[0].length;
            int[] dp = new int[n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == 0) {
                        dp[j] += grid[i][j];
                    } else {
                        dp[j] = grid[i][j] + Math.min(dp[j], dp[j - 1]);
                    }
                }
            }
            return dp[n - 1];
        }
    
        public static void main(String[] args) {
            int[][] grid = {
                {1, 3, 1},
                {1, 5, 1},
                {4, 2, 1}
            };
            System.out.println(minPathSumOptimized(grid)); // Output: 7
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n), where m is the number of rows and n is the number of columns. Each cell is computed once.
*   **Space Complexity:** O(n) for the 1D DP array.

Conclusion
----------

The Minimum Path Sum problem can be efficiently solved using various approaches. The recursive method is simple but inefficient for larger grids. The memoization and dynamic programming approaches provide optimal solutions, with the optimized space version being the most efficient in terms of space usage.