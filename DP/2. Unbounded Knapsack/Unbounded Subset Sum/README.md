Unbounded Subset Sum Problem
============================

Problem Definition
------------------

The **Unbounded Subset Sum Problem** involves finding out whether it is possible to obtain a target sum `S` using an unlimited number of elements from a given array `arr`. Each element can be used multiple times in the combination.

### Problem Statement

You are given an array of positive integers `arr` and a target sum `S`. Determine if you can form the target sum using the elements of the array, allowing for unlimited repetitions of the elements.

### Example

For `arr = [1, 3, 4]` and `S = 6`, you can achieve the target sum by using `3 + 3` or `4 + 1 + 1`.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach attempts to build the target sum by trying all combinations of the array elements.

#### Pseudocode

    function isSubsetSumRecursive(arr, n, S):
        if S == 0:
            return true
        if n == 0:
            return false
        if arr[n-1] <= S:
            return isSubsetSumRecursive(arr, n, S - arr[n-1]) or isSubsetSumRecursive(arr, n - 1, S)
        return isSubsetSumRecursive(arr, n - 1, S)
    

#### Java Implementation

    public class UnboundedSubsetSum {
    
        public static boolean isSubsetSumRecursive(int[] arr, int n, int S) {
            if (S == 0) {
                return true;
            }
            if (n == 0) {
                return false;
            }
            if (arr[n - 1] <= S) {
                return isSubsetSumRecursive(arr, n, S - arr[n - 1]) || isSubsetSumRecursive(arr, n - 1, S);
            }
            return isSubsetSumRecursive(arr, n - 1, S);
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 3, 4};
            int S = 6;
            System.out.println(isSubsetSumRecursive(arr, arr.length, S));  // Output: true
        }
    }
    

### 2\. Memoization Approach

The memoization approach stores the results of subproblems to avoid redundant calculations and optimize the recursive method.

#### Pseudocode

    function isSubsetSumMemo(arr, n, S, memo):
        if S == 0:
            return true
        if n == 0:
            return false
        if memo[n][S] != -1:
            return memo[n][S]
        if arr[n-1] <= S:
            memo[n][S] = isSubsetSumMemo(arr, n, S - arr[n-1], memo) or isSubsetSumMemo(arr, n - 1, S, memo)
        else:
            memo[n][S] = isSubsetSumMemo(arr, n - 1, S, memo)
        return memo[n][S]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class UnboundedSubsetSum {
    
        public static boolean isSubsetSumMemo(int[] arr, int n, int S, boolean[][] memo) {
            if (S == 0) {
                return true;
            }
            if (n == 0) {
                return false;
            }
            if (memo[n][S]) {
                return true;
            }
            if (arr[n - 1] <= S) {
                memo[n][S] = isSubsetSumMemo(arr, n, S - arr[n - 1], memo) || isSubsetSumMemo(arr, n - 1, S, memo);
            } else {
                memo[n][S] = isSubsetSumMemo(arr, n - 1, S, memo);
            }
            return memo[n][S];
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 3, 4};
            int S = 6;
            boolean[][] memo = new boolean[arr.length + 1][S + 1];
            for (boolean[] row : memo) {
                Arrays.fill(row, false);
            }
            System.out.println(isSubsetSumMemo(arr, arr.length, S, memo));  // Output: true
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds a table to iteratively compute the solution in a bottom-up manner.

#### Pseudocode

    function isSubsetSumDP(arr, n, S):
        dp = array of size (n+1) x (S+1)
        for i from 0 to n:
            dp[i][0] = true
        for i from 1 to S:
            dp[0][i] = false
        for i from 1 to n:
            for j from 1 to S:
                if arr[i-1] <= j:
                    dp[i][j] = dp[i][j - arr[i-1]] or dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[n][S]
    

#### Java Implementation

    public class UnboundedSubsetSum {
    
        public static boolean isSubsetSumDP(int[] arr, int n, int S) {
            boolean[][] dp = new boolean[n + 1][S + 1];
    
            for (int i = 0; i <= n; i++) {
                dp[i][0] = true; // If sum is 0, we can always achieve it
            }
            
            for (int i = 1; i <= S; i++) {
                dp[0][i] = false; // If no items, we can't achieve positive sum
            }
    
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= S; j++) {
                    if (arr[i - 1] <= j) {
                        dp[i][j] = dp[i][j - arr[i - 1]] || dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            return dp[n][S];
        }
    
        public static void main(String[] args) {
            int[] arr = {1, 3, 4};
            int S = 6;
            System.out.println(isSubsetSumDP(arr, arr.length, S));  // Output: true
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive Approach:** O(2<sup>n</sup>) time, O(n) space (due to recursion stack).
*   **Memoization Approach:** O(n\*S) time, O(n\*S) space (for memoization table).
*   **Dynamic Programming Approach:** O(n\*S) time, O(n\*S) space (for DP table).