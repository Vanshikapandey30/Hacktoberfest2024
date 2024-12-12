Longest Path in Grid
====================

Problem Definition
------------------

The Longest Path in Grid problem involves finding the longest path in a 2D grid where you can move to adjacent cells (up, down, left, right) if the value in the next cell is greater than the current cell. The path must be continuous, and you cannot revisit cells.

### Example

*   Input: grid = \[\[1,2,3\],\[6,5,4\],\[7,8,9\]\]
    
        
                Output: 5
                
    
*   Explanation: The longest path is 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9, which has a length of 5.

Solution Approaches
-------------------

### 1\. Depth-First Search (DFS) with Memoization

This approach uses DFS to explore all possible paths from each cell, with memoization to store results for previously calculated paths, thus optimizing the solution.

#### Pseudocode

    function longestPath(grid):
        if grid is empty:
            return 0
    
        memo = 2D array of size equal to grid filled with -1
        maxLength = 0
    
        for each cell (i, j) in grid:
            maxLength = max(maxLength, dfs(i, j, grid, memo))
    
        return maxLength
    
    function dfs(i, j, grid, memo):
        if memo[i][j] != -1:
            return memo[i][j]
    
        directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        maxLength = 1
    
        for each direction (dx, dy) in directions:
            newI = i + dx
            newJ = j + dy
            if isInBounds(newI, newJ, grid) and grid[newI][newJ] > grid[i][j]:
                maxLength = max(maxLength, 1 + dfs(newI, newJ, grid, memo))
    
        memo[i][j] = maxLength
        return maxLength
    

#### Java Implementation

    public class LongestPathInGrid {
        private static final int[][] directions = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        };
    
        public static int longestPath(int[][] grid) {
            if (grid.length == 0) {
                return 0;
            }
    
            int rows = grid.length;
            int cols = grid[0].length;
            int[][] memo = new int[rows][cols];
            for (int[] row : memo) {
                Arrays.fill(row, -1);
            }
    
            int maxLength = 0;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    maxLength = Math.max(maxLength, dfs(i, j, grid, memo));
                }
            }
    
            return maxLength;
        }
    
        private static int dfs(int i, int j, int[][] grid, int[][] memo) {
            if (memo[i][j] != -1) {
                return memo[i][j];
            }
    
            int maxLength = 1;
            for (int[] direction : directions) {
                int newI = i + direction[0];
                int newJ = j + direction[1];
                if (isInBounds(newI, newJ, grid) && grid[newI][newJ] > grid[i][j]) {
                    maxLength = Math.max(maxLength, 1 + dfs(newI, newJ, grid, memo));
                }
            }
    
            memo[i][j] = maxLength;
            return maxLength;
        }
    
        private static boolean isInBounds(int i, int j, int[][] grid) {
            return i >= 0 && i < grid.length && j >= 0 && j < grid[0].length;
        }
    
        public static void main(String[] args) {
            int[][] grid = {{1, 2, 3}, {6, 5, 4}, {7, 8, 9}};
            System.out.println(longestPath(grid)); // Output: 5
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(N \* M) where N is the number of rows and M is the number of columns in the grid.
*   **Space Complexity:** O(N \* M) for the memoization table.

### 2\. Dynamic Programming Approach

This approach uses a DP table to keep track of the longest path ending at each cell. We first sort the cells based on their values and then update the DP table based on the adjacency condition.

#### Pseudocode

    function longestPath(grid):
        if grid is empty:
            return 0
    
        rows = number of rows in grid
        cols = number of columns in grid
        dp = 2D array of size rows x cols filled with 1
    
        for each cell (i, j) in sorted order of grid values:
            for each direction (dx, dy) in directions:
                newI = i + dx
                newJ = j + dy
                if isInBounds(newI, newJ, grid) and grid[newI][newJ] > grid[i][j]:
                    dp[newI][newJ] = max(dp[newI][newJ], dp[i][j] + 1)
    
        maxLength = 0
        for each value in dp:
            maxLength = max(maxLength, value)
    
        return maxLength
    

#### Java Implementation

    import java.util.Arrays;
    
    public class LongestPathInGrid {
        private static final int[][] directions = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        };
    
        public static int longestPath(int[][] grid) {
            if (grid.length == 0) {
                return 0;
            }
    
            int rows = grid.length;
            int cols = grid[0].length;
            int[][] dp = new int[rows][cols];
    
            for (int i = 0; i < rows; i++) {
                Arrays.fill(dp[i], 1);
            }
    
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    for (int[] direction : directions) {
                        int newI = i + direction[0];
                        int newJ = j + direction[1];
                        if (isInBounds(newI, newJ, grid) && grid[newI][newJ] > grid[i][j]) {
                            dp[newI][newJ] = Math.max(dp[newI][newJ], dp[i][j] + 1);
                        }
                    }
                }
            }
    
            int maxLength = 0;
            for (int[] row : dp) {
                for (int value : row) {
                    maxLength = Math.max(maxLength, value);
                }
            }
    
            return maxLength;
        }
    
        private static boolean isInBounds(int i, int j, int[][] grid) {
            return i >= 0 && i < grid.length && j >= 0 && j < grid[0].length;
        }
    
        public static void main(String[] args) {
            int[][] grid = {{1, 2, 3}, {6, 5, 4}, {7, 8, 9}};
            System.out.println(longestPath(grid)); // Output: 5
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(N \* M) where N is the number of rows and M is the number of columns in the grid.
*   **Space Complexity:** O(N \* M) for the DP table.

Conclusion
----------

The Longest Path in Grid problem can be solved efficiently using DFS with memoization or a dynamic programming approach. The choice of approach depends on the specific constraints and requirements of the problem.