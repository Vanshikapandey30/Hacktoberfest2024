Integer Break Problem
=====================

Problem Definition
------------------

The **Integer Break Problem** involves breaking an integer `n` into at least two positive integers such that the product of these integers is maximized. The goal is to determine the maximum product you can obtain by splitting `n`.

### Problem Statement

You are given an integer `n`. Your task is to break it into at least two positive integers such that the product of these integers is maximized and return that maximum product.

### Example

For `n = 10`, the best way to break it would be `3 + 3 + 4`, which yields the product `3 * 3 * 4 = 36`.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach tries all possible ways of breaking the integer and recursively computes the maximum product.

#### Pseudocode

    function integerBreakRecursive(n):
        if n == 1:
            return 1
        maxProduct = 0
        for i from 1 to n-1:
            maxProduct = max(maxProduct, i * max(n - i, integerBreakRecursive(n - i)))
        return maxProduct
    

#### Java Implementation

    public class IntegerBreak {
    
        public static int integerBreakRecursive(int n) {
            if (n == 1) {
                return 1;
            }
            int maxProduct = 0;
            for (int i = 1; i < n; i++) {
                maxProduct = Math.max(maxProduct, i * Math.max(n - i, integerBreakRecursive(n - i)));
            }
            return maxProduct;
        }
    
        public static void main(String[] args) {
            int n = 10;
            System.out.println(integerBreakRecursive(n));  // Output: 36
        }
    }
    

### 2\. Memoization Approach

The memoization approach stores the results of subproblems to avoid redundant calculations and improve performance.

#### Pseudocode

    function integerBreakMemo(n, memo):
        if n == 1:
            return 1
        if memo[n] != -1:
            return memo[n]
        maxProduct = 0
        for i from 1 to n-1:
            maxProduct = max(maxProduct, i * max(n - i, integerBreakMemo(n - i, memo)))
        memo[n] = maxProduct
        return memo[n]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class IntegerBreak {
    
        public static int integerBreakMemo(int n, int[] memo) {
            if (n == 1) {
                return 1;
            }
            if (memo[n] != -1) {
                return memo[n];
            }
            int maxProduct = 0;
            for (int i = 1; i < n; i++) {
                maxProduct = Math.max(maxProduct, i * Math.max(n - i, integerBreakMemo(n - i, memo)));
            }
            memo[n] = maxProduct;
            return memo[n];
        }
    
        public static void main(String[] args) {
            int n = 10;
            int[] memo = new int[n + 1];
            Arrays.fill(memo, -1);
            System.out.println(integerBreakMemo(n, memo));  // Output: 36
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds a table to iteratively compute the solution in a bottom-up manner.

#### Pseudocode

    function integerBreakDP(n):
        dp = array of size n+1
        dp[1] = 1
        for i from 2 to n:
            for j from 1 to i-1:
                dp[i] = max(dp[i], j * max(i - j, dp[i - j]))
        return dp[n]
    

#### Java Implementation

    public class IntegerBreak {
    
        public static int integerBreakDP(int n) {
            int[] dp = new int[n + 1];
            dp[1] = 1;
    
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j < i; j++) {
                    dp[i] = Math.max(dp[i], j * Math.max(i - j, dp[i - j]));
                }
            }
            return dp[n];
        }
    
        public static void main(String[] args) {
            int n = 10;
            System.out.println(integerBreakDP(n));  // Output: 36
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive Approach:** O(2<sup>n</sup>) time, O(n) space (due to recursion stack).
*   **Memoization Approach:** O(n<sup>2</sup>) time, O(n) space (for memoization table).
*   **Dynamic Programming Approach:** O(n<sup>2</sup>) time, O(n) space (for DP table).