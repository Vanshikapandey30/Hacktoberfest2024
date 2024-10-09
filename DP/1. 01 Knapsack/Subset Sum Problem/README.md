Subset Sum Problem
==================

Definition
----------

The **Subset Sum Problem** is a classic problem in computer science and combinatorics, where the goal is to determine if there exists a subset of a given set of integers whose sum is equal to a specified value.

### Problem Statement

Given:

*   A set of non-negative integers `S`.
*   A target sum `T`.

The objective is to determine whether any subset of `S` sums to exactly `T`.

### Example

Consider the set `S = {3, 34, 4, 12, 5, 2}` and target sum `T = 9`. The subset `{4, 5}` sums to `9`, so the output is **true**.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach explores all subsets by either including or excluding each element from the set. The time complexity is exponential, but it serves as a foundation for optimized solutions.

#### Pseudocode

    function isSubsetSum(set, n, sum):
        if sum == 0:
            return true
        if n == 0 and sum != 0:
            return false
        if set[n-1] > sum:
            return isSubsetSum(set, n-1, sum)
        return isSubsetSum(set, n-1, sum) or 
               isSubsetSum(set, n-1, sum-set[n-1])
    

#### Java Implementation

    public class SubsetSum {
        public static boolean isSubsetSum(int[] set, int n, int sum) {
            if (sum == 0) {
                return true;
            }
            if (n == 0 && sum != 0) {
                return false;
            }
            if (set[n - 1] > sum) {
                return isSubsetSum(set, n - 1, sum);
            }
            return isSubsetSum(set, n - 1, sum) || 
                   isSubsetSum(set, n - 1, sum - set[n - 1]);
        }
    
        public static void main(String[] args) {
            int[] set = {3, 34, 4, 12, 5, 2};
            int sum = 9;
            int n = set.length;
            System.out.println(isSubsetSum(set, n, sum));  // Output: true
        }
    }
    

### 2\. Memoization Approach

The memoization approach optimizes the recursive solution by storing intermediate results to avoid redundant calculations. The time complexity is reduced to `O(n * sum)`.

#### Pseudocode

    function isSubsetSumMemo(set, n, sum, memo):
        if memo[n][sum] is not -1:
            return memo[n][sum]
        if sum == 0:
            return true
        if n == 0:
            return false
        if set[n-1] > sum:
            memo[n][sum] = isSubsetSumMemo(set, n-1, sum, memo)
        else:
            memo[n][sum] = isSubsetSumMemo(set, n-1, sum, memo) or 
                           isSubsetSumMemo(set, n-1, sum - set[n-1], memo)
        return memo[n][sum]
    

#### Java Implementation

    public class SubsetSum {
        public static boolean isSubsetSumMemo(int[] set, int n, int sum, Boolean[][] memo) {
            if (sum == 0) {
                return true;
            }
            if (n == 0) {
                return false;
            }
            if (memo[n][sum] != null) {
                return memo[n][sum];
            }
            if (set[n - 1] > sum) {
                memo[n][sum] = isSubsetSumMemo(set, n - 1, sum, memo);
            } else {
                memo[n][sum] = isSubsetSumMemo(set, n - 1, sum, memo) || 
                               isSubsetSumMemo(set, n - 1, sum - set[n - 1], memo);
            }
            return memo[n][sum];
        }
    
        public static void main(String[] args) {
            int[] set = {3, 34, 4, 12, 5, 2};
            int sum = 9;
            int n = set.length;
            Boolean[][] memo = new Boolean[n + 1][sum + 1];
            System.out.println(isSubsetSumMemo(set, n, sum, memo));  // Output: true
        }
    }
    

### 3\. Tabulation (Dynamic Programming) Approach

The tabulation method uses a bottom-up approach to fill a table that stores whether a subset sum can be formed for every subproblem. This approach has a time complexity of `O(n * sum)`.

#### Pseudocode

    function isSubsetSumTabulation(set, n, sum):
        create a dp table of size (n+1) x (sum+1)
    
        for i from 0 to n:
            dp[i][0] = true
    
        for j from 1 to sum:
            dp[0][j] = false
    
        for i from 1 to n:
            for j from 1 to sum:
                if set[i-1] > j:
                    dp[i][j] = dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-set[i-1]]
    
        return dp[n][sum]
    

#### Java Implementation

    public class SubsetSum {
        public static boolean isSubsetSumTabulation(int[] set, int n, int sum) {
            boolean[][] dp = new boolean[n + 1][sum + 1];
            
            for (int i = 0; i <= n; i++) {
                dp[i][0] = true;
            }
    
            for (int j = 1; j <= sum; j++) {
                dp[0][j] = false;
            }
    
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= sum; j++) {
                    if (set[i - 1] > j) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
                    }
                }
            }
    
            return dp[n][sum];
        }
    
        public static void main(String[] args) {
            int[] set = {3, 34, 4, 12, 5, 2};
            int sum = 9;
            int n = set.length;
            System.out.println(isSubsetSumTabulation(set, n, sum));  // Output: true
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive:** O(2<sup>n</sup>) time, O(n) space (due to call stack)
*   **Memoization:** O(n \* sum) time, O(n \* sum) space (for the memoization table)
*   **Tabulation:** O(n \* sum) time, O(n \* sum) space (for the DP table)

Conclusion
----------

The Subset Sum Problem can be solved using a variety of approaches, from a simple recursive method to more efficient dynamic programming techniques like memoization and tabulation. For large input sizes, memoization and tabulation are preferred due to their lower time complexity.