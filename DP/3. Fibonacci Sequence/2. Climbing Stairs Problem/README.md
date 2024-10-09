Climbing Stairs Problem
=======================

Problem Definition
------------------

The **Climbing Stairs Problem** is a classic problem where you are asked to determine the number of distinct ways to climb to the top of a staircase with `n` steps. You can take either `1` or `2` steps at a time.

### Example

If `n = 3`, the distinct ways to climb the stairs are:

*   1 step + 1 step + 1 step
*   1 step + 2 steps
*   2 steps + 1 step

Thus, the total number of ways to climb `3` steps is `3`.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach uses the relationship that the number of ways to reach the `n-th` step is the sum of the ways to reach the `(n-1)-th` and `(n-2)-th` steps.

#### Pseudocode

    function climbStairsRecursive(n):
        if n == 0 or n == 1:
            return 1
        return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2)
    

#### Java Implementation

    public class ClimbingStairs {
    
        public static int climbStairsRecursive(int n) {
            if (n == 0 || n == 1) {
                return 1;
            }
            return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
        }
    
        public static void main(String[] args) {
            int n = 3; // Example input
            System.out.println(climbStairsRecursive(n));  // Output: 3
        }
    }
    

### 2\. Memoization Approach

The memoization approach optimizes the recursive solution by storing previously computed results to avoid redundant calculations.

#### Pseudocode

    function climbStairsMemo(n, memo):
        if memo[n] is not -1:
            return memo[n]
        if n == 0 or n == 1:
            return 1
        memo[n] = climbStairsMemo(n - 1, memo) + climbStairsMemo(n - 2, memo)
        return memo[n]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class ClimbingStairs {
    
        public static int climbStairsMemo(int n, int[] memo) {
            if (memo[n] != -1) {
                return memo[n];
            }
            if (n == 0 || n == 1) {
                return 1;
            }
            memo[n] = climbStairsMemo(n - 1, memo) + climbStairsMemo(n - 2, memo);
            return memo[n];
        }
    
        public static void main(String[] args) {
            int n = 3; // Example input
            int[] memo = new int[n + 1];
            Arrays.fill(memo, -1);
            System.out.println(climbStairsMemo(n, memo));  // Output: 3
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds a table iteratively to compute the number of ways to climb the stairs from the base up to `n`.

#### Pseudocode

    function climbStairsDP(n):
        dp = array of size n + 1
        dp[0] = 1
        dp[1] = 1
        for i from 2 to n:
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]
    

#### Java Implementation

    public class ClimbingStairs {
    
        public static int climbStairsDP(int n) {
            int[] dp = new int[n + 1];
            dp[0] = 1;
            dp[1] = 1;
    
            for (int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
    
        public static void main(String[] args) {
            int n = 3; // Example input
            System.out.println(climbStairsDP(n));  // Output: 3
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive Approach:** O(2<sup>n</sup>) time, O(n) space (due to recursion stack).
*   **Memoization Approach:** O(n) time, O(n) space (for memoization array).
*   **Dynamic Programming Approach:** O(n) time, O(n) space (for DP table).