Minimum Cost Path
=================

Problem Definition
------------------

The Minimum Cost Path problem involves finding the path from the top-left corner to the bottom-right corner of a grid that minimizes the cost. Each cell in the grid has a cost associated with entering that cell, and you can only move down, right, or diagonally down-right.

### Example

*   Input: cost = \[\[1, 3, 5\], \[2, 1, 2\], \[4, 3, 1\]\]
    
        
                Output: 7
                
    
*   Explanation: The path is 1 → 3 → 1 → 2 → 1, which has a minimum cost of 7.

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach

This approach utilizes a DP table where each cell contains the minimum cost to reach that cell from the start. The value of each cell is computed based on the minimum of the costs from the adjacent cells (left, top, and top-left diagonal).

#### Pseudocode

    function minCostPath(cost):
        if cost is empty:
            return 0
    
        rows = number of rows in cost
        cols = number of columns in cost
        dp = 2D array of size rows x cols
    
        dp[0][0] = cost[0][0]
    
        for each i from 1 to rows:
            dp[i][0] = dp[i-1][0] + cost[i][0]
        for each j from 1 to cols:
            dp[0][j] = dp[0][j-1] + cost[0][j]
    
        for each i from 1 to rows:
            for each j from 1 to cols:
                dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
    
        return dp[rows-1][cols-1]
    

#### Java Implementation

    public class MinimumCostPath {
        public static int minCostPath(int[][] cost) {
            if (cost.length == 0) {
                return 0;
            }
    
            int rows = cost.length;
            int cols = cost[0].length;
            int[][] dp = new int[rows][cols];
    
            dp[0][0] = cost[0][0];
    
            for (int i = 1; i < rows; i++) {
                dp[i][0] = dp[i - 1][0] + cost[i][0];
            }
            for (int j = 1; j < cols; j++) {
                dp[0][j] = dp[0][j - 1] + cost[0][j];
            }
    
            for (int i = 1; i < rows; i++) {
                for (int j = 1; j < cols; j++) {
                    dp[i][j] = cost[i][j] + Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
    
            return dp[rows - 1][cols - 1];
        }
    
        public static void main(String[] args) {
            int[][] cost = {
                {1, 3, 5},
                {2, 1, 2},
                {4, 3, 1}
            };
            System.out.println(minCostPath(cost)); // Output: 7
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(N \* M) where N is the number of rows and M is the number of columns in the cost grid.
*   **Space Complexity:** O(N \* M) for the DP table.

### 2\. Recursive Approach with Memoization

This approach employs recursion to explore all possible paths, utilizing memoization to store the results of previously computed states, thus optimizing the solution.

#### Pseudocode

    function minCostPath(cost):
        if cost is empty:
            return 0
    
        rows = number of rows in cost
        cols = number of columns in cost
        memo = 2D array of size rows x cols filled with -1
    
        return dfs(0, 0, cost, memo)
    
    function dfs(i, j, cost, memo):
        if i == rows - 1 and j == cols - 1:
            return cost[i][j]
        if i >= rows or j >= cols:
            return infinity
        if memo[i][j] != -1:
            return memo[i][j]
    
        memo[i][j] = cost[i][j] + min(dfs(i + 1, j, cost, memo), dfs(i, j + 1, cost, memo), dfs(i + 1, j + 1, cost, memo))
        return memo[i][j]
    

#### Java Implementation

    public class MinimumCostPath {
        public static int minCostPath(int[][] cost) {
            if (cost.length == 0) {
                return 0;
            }
    
            int rows = cost.length;
            int cols = cost[0].length;
            int[][] memo = new int[rows][cols];
            for (int[] row : memo) {
                Arrays.fill(row, -1);
            }
    
            return dfs(0, 0, cost, memo);
        }
    
        private static int dfs(int i, int j, int[][] cost, int[][] memo) {
            if (i == cost.length - 1 && j == cost[0].length - 1) {
                return cost[i][j];
            }
            if (i >= cost.length || j >= cost[0].length) {
                return Integer.MAX_VALUE;
            }
            if (memo[i][j] != -1) {
                return memo[i][j];
            }
    
            memo[i][j] = cost[i][j] + Math.min(dfs(i + 1, j, cost, memo), Math.min(dfs(i, j + 1, cost, memo), dfs(i + 1, j + 1, cost, memo)));
            return memo[i][j];
        }
    
        public static void main(String[] args) {
            int[][] cost = {
                {1, 3, 5},
                {2, 1, 2},
                {4, 3, 1}
            };
            System.out.println(minCostPath(cost)); // Output: 7
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(N \* M) where N is the number of rows and M is the number of columns in the cost grid.
*   **Space Complexity:** O(N \* M) for the memoization table.

Conclusion
----------

The Minimum Cost Path problem can be effectively solved using either a dynamic programming approach or a recursive approach with memoization. The choice of method depends on the problem constraints and preferences for readability versus performance.