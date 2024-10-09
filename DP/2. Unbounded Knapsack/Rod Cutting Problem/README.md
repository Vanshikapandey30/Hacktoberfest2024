Rod Cutting Problem
===================

Problem Definition
------------------

The **Rod Cutting Problem** is a variation of the unbounded knapsack problem. Given a rod of length `N` and an array of prices that contains prices of all pieces of size `i`, where `1 <= i <= N`, the goal is to determine the maximum revenue obtainable by cutting up the rod and selling the pieces.

### Problem Statement

You are given a rod of length `n` and an array `price[]` where `price[i]` represents the price of a rod of length `i + 1`. You need to determine the maximum revenue obtainable by cutting the rod and selling the pieces.

### Example

For a rod of length `4` and prices `{1, 5, 8, 9}`:

*   If you cut the rod into lengths `2` and `2`, you will get revenue of `5 + 5 = 10`.
*   If you cut it into a length of `4`, you will get revenue of `9`.

Hence, the maximum revenue is `10`.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach explores all possible ways of cutting the rod and calculates the maximum revenue.

#### Pseudocode

    function rodCuttingRecursive(price, length):
        if length == 0:
            return 0
        maxRevenue = 0
        for each i from 1 to length:
            maxRevenue = max(maxRevenue, price[i-1] + rodCuttingRecursive(price, length - i))
        return maxRevenue
    

#### Java Implementation

    public class RodCutting {
    
        public static int rodCuttingRecursive(int[] price, int length) {
            if (length == 0) {
                return 0;
            }
            int maxRevenue = 0;
            for (int i = 1; i <= length; i++) {
                maxRevenue = Math.max(maxRevenue, price[i - 1] + rodCuttingRecursive(price, length - i));
            }
            return maxRevenue;
        }
    
        public static void main(String[] args) {
            int[] price = {1, 5, 8, 9};
            int length = 4;
            System.out.println(rodCuttingRecursive(price, length));  // Output: 10
        }
    }
    

### 2\. Memoization Approach

The memoization approach uses a table to store results of subproblems, reducing redundant calculations.

#### Pseudocode

    function rodCuttingMemo(price, length, memo):
        if length == 0:
            return 0
        if memo[length] != -1:
            return memo[length]
        maxRevenue = 0
        for each i from 1 to length:
            maxRevenue = max(maxRevenue, price[i-1] + rodCuttingMemo(price, length - i, memo))
        memo[length] = maxRevenue
        return memo[length]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class RodCutting {
    
        public static int rodCuttingMemo(int[] price, int length, int[] memo) {
            if (length == 0) {
                return 0;
            }
            if (memo[length] != -1) {
                return memo[length];
            }
            int maxRevenue = 0;
            for (int i = 1; i <= length; i++) {
                maxRevenue = Math.max(maxRevenue, price[i - 1] + rodCuttingMemo(price, length - i, memo));
            }
            memo[length] = maxRevenue;
            return memo[length];
        }
    
        public static void main(String[] args) {
            int[] price = {1, 5, 8, 9};
            int length = 4;
            int[] memo = new int[length + 1];
            Arrays.fill(memo, -1);
            System.out.println(rodCuttingMemo(price, length, memo));  // Output: 10
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

In the dynamic programming approach, we build a table where each entry at index `i` stores the maximum revenue obtainable for a rod of length `i`.

#### Pseudocode

    function rodCuttingDP(price, length):
        dp = array of size length + 1
        dp[0] = 0
        for each i from 1 to length:
            for each j from 1 to i:
                dp[i] = max(dp[i], price[j-1] + dp[i-j])
        return dp[length]
    

#### Java Implementation

    public class RodCutting {
    
        public static int rodCuttingDP(int[] price, int length) {
            int[] dp = new int[length + 1];
            dp[0] = 0;
    
            for (int i = 1; i <= length; i++) {
                for (int j = 1; j <= i; j++) {
                    dp[i] = Math.max(dp[i], price[j - 1] + dp[i - j]);
                }
            }
    
            return dp[length];
        }
    
        public static void main(String[] args) {
            int[] price = {1, 5, 8, 9};
            int length = 4;
            System.out.println(rodCuttingDP(price, length));  // Output: 10
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive:** O(2<sup>n</sup>) time, O(n) space (due to call stack)
*   **Memoization:** O(n<sup>2</sup>) time, O(n) space (for the memoization table)
*   **Dynamic Programming:** O(n<sup>2</sup>) time, O(n) space (for the DP table)