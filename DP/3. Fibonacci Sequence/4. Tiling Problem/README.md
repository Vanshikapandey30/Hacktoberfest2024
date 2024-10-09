Tiling Problem
==============

Problem Definition
------------------

The **Tiling Problem** involves finding the number of ways to completely tile a `1 x n` board using `1 x m` tiles. The goal is to determine how many different arrangements can be made using these tiles to fill the entire board.

### Example

For example, if `n = 4` and `m = 2`, you can tile the board in the following ways:

*   All vertical tiles
*   Two horizontal tiles on the top and two on the bottom
*   One vertical tile followed by two horizontal tiles
*   Two horizontal tiles followed by one vertical tile

So the total number of ways to tile a `1 x 4` board using `1 x 2` tiles is `3`.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach follows the idea that the number of ways to tile a `1 x n` board can be calculated based on the number of ways to tile shorter boards.

#### Pseudocode

    function tilingRecursive(n, m):
        if n < m:
            return 0
        if n == m:
            return 1
        if n < 1:
            return 1
        return tilingRecursive(n - 1, m) + tilingRecursive(n - m, m)
    

#### Java Implementation

    public class Tiling {
    
        public static int tilingRecursive(int n, int m) {
            if (n < m) return 0;
            if (n == m) return 1;
            if (n < 1) return 1;
            return tilingRecursive(n - 1, m) + tilingRecursive(n - m, m);
        }
    
        public static void main(String[] args) {
            int n = 4; // Length of the board
            int m = 2; // Length of the tile
            System.out.println(tilingRecursive(n, m));  // Output: 3
        }
    }
    

### 2\. Memoization Approach

The memoization approach optimizes the recursive solution by storing previously computed results to avoid redundant calculations.

#### Pseudocode

    function tilingMemo(n, m, memo):
        if memo[n] is not -1:
            return memo[n]
        if n < m:
            return 0
        if n == m:
            return 1
        if n < 1:
            return 1
        memo[n] = tilingMemo(n - 1, m, memo) + tilingMemo(n - m, m, memo)
        return memo[n]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class Tiling {
    
        public static int tilingMemo(int n, int m, int[] memo) {
            if (memo[n] != -1) {
                return memo[n];
            }
            if (n < m) return 0;
            if (n == m) return 1;
            if (n < 1) return 1;
            memo[n] = tilingMemo(n - 1, m, memo) + tilingMemo(n - m, m, memo);
            return memo[n];
        }
    
        public static void main(String[] args) {
            int n = 4; // Length of the board
            int m = 2; // Length of the tile
            int[] memo = new int[n + 1];
            Arrays.fill(memo, -1);
            System.out.println(tilingMemo(n, m, memo));  // Output: 3
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds a table iteratively to compute the number of ways to tile the board.

#### Pseudocode

    function tilingDP(n, m):
        dp = array of size n + 1
        dp[0] = 1
        for i from 1 to n:
            dp[i] = dp[i - 1] if i - 1 >= 0 else 0
            if i - m >= 0:
                dp[i] += dp[i - m]
        return dp[n]
    

#### Java Implementation

    public class Tiling {
    
        public static int tilingDP(int n, int m) {
            int[] dp = new int[n + 1];
            dp[0] = 1;
    
            for (int i = 1; i <= n; i++) {
                dp[i] = dp[i - 1];
                if (i - m >= 0) {
                    dp[i] += dp[i - m];
                }
            }
            return dp[n];
        }
    
        public static void main(String[] args) {
            int n = 4; // Length of the board
            int m = 2; // Length of the tile
            System.out.println(tilingDP(n, m));  // Output: 3
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive Approach:** O(2<sup>n</sup>) time, O(n) space (due to recursion stack).
*   **Memoization Approach:** O(n) time, O(n) space (for memoization array).
*   **Dynamic Programming Approach:** O(n) time, O(n) space (for DP table).