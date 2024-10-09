Unique Paths Problem
====================

Problem Definition
------------------

The Unique Paths problem involves finding the number of distinct paths from the top-left corner to the bottom-right corner of a grid, where you can only move down or to the right.

### Example

*   Input: Grid Size = 3 x 7
    
        
                Starting Point: (0, 0)
                Ending Point: (2, 6)
                
    
*   Output: 28
    
        
                There are 28 unique paths from the top-left to the bottom-right corner.
                
    

Solution Approaches
-------------------

### 1\. Recursive Approach

This approach uses recursion to explore all possible paths. The base case is when you reach the bottom-right corner, and the function returns 1.

#### Pseudocode

    function uniquePathsRecursive(m, n):
        if m == 1 or n == 1:
            return 1
        return uniquePathsRecursive(m - 1, n) + uniquePathsRecursive(m, n - 1)
    

#### Java Implementation

    public class UniquePaths {
        public static int uniquePathsRecursive(int m, int n) {
            if (m == 1 || n == 1) {
                return 1;
            }
            return uniquePathsRecursive(m - 1, n) + uniquePathsRecursive(m, n - 1);
        }
    
        public static void main(String[] args) {
            System.out.println(uniquePathsRecursive(3, 7)); // Output: 28
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2^(m+n)), where m is the number of rows and n is the number of columns. The exponential growth is due to the branching factor at each step.
*   **Space Complexity:** O(m+n) due to the recursion stack.

### 2\. Memoization Approach

This approach uses recursion with memoization to store already computed results, reducing the number of calculations.

#### Pseudocode

    function uniquePathsMemo(m, n, memo):
        if m == 1 or n == 1:
            return 1
        if memo[m][n] is not set:
            memo[m][n] = uniquePathsMemo(m - 1, n, memo) + uniquePathsMemo(m, n - 1, memo)
        return memo[m][n]
    
    function uniquePaths(m, n):
        initialize memo table with -1
        return uniquePathsMemo(m, n, memo)
    

#### Java Implementation

    public class UniquePaths {
        public static int uniquePathsMemo(int m, int n, int[][] memo) {
            if (m == 1 || n == 1) {
                return 1;
            }
            if (memo[m][n] != -1) {
                return memo[m][n];
            }
            memo[m][n] = uniquePathsMemo(m - 1, n, memo) + uniquePathsMemo(m, n - 1, memo);
            return memo[m][n];
        }
    
        public static int uniquePaths(int m, int n) {
            int[][] memo = new int[m + 1][n + 1];
            for (int[] row : memo) {
                Arrays.fill(row, -1);
            }
            return uniquePathsMemo(m, n, memo);
        }
    
        public static void main(String[] args) {
            System.out.println(uniquePaths(3, 7)); // Output: 28
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n), where m is the number of rows and n is the number of columns. Each cell is computed once.
*   **Space Complexity:** O(m\*n) for the memoization table.

### 3\. Dynamic Programming Approach

This approach uses a bottom-up dynamic programming table to store the number of unique paths to each cell in the grid.

#### Pseudocode

    function uniquePathsDP(m, n):
        create a dp table of size m x n
        for i from 0 to m-1:
            for j from 0 to n-1:
                if i == 0 or j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m-1][n-1]
    

#### Java Implementation

    public class UniquePaths {
        public static int uniquePathsDP(int m, int n) {
            int[][] dp = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
            }
            return dp[m - 1][n - 1];
        }
    
        public static void main(String[] args) {
            System.out.println(uniquePathsDP(3, 7)); // Output: 28
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n), where m is the number of rows and n is the number of columns. Each cell is computed once.
*   **Space Complexity:** O(m\*n) for the dp table.

### 4\. Space Optimized Dynamic Programming Approach

This approach optimizes the space complexity by using a 1D array instead of a 2D table, reducing the space requirement significantly.

#### Pseudocode

    function uniquePathsOptimized(m, n):
        create a dp array of size n
        for i from 0 to m-1:
            for j from 0 to n-1:
                if j == 0:
                    dp[j] = 1
                else:
                    dp[j] += dp[j - 1]
        return dp[n - 1]
    

#### Java Implementation

    public class UniquePaths {
        public static int uniquePathsOptimized(int m, int n) {
            int[] dp = new int[n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (j == 0) {
                        dp[j] = 1;
                    } else {
                        dp[j] += dp[j - 1];
                    }
                }
            }
            return dp[n - 1];
        }
    
        public static void main(String[] args) {
            System.out.println(uniquePathsOptimized(3, 7)); // Output: 28
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m\*n), where m is the number of rows and n is the number of columns.
*   **Space Complexity:** O(n) for the dp array.