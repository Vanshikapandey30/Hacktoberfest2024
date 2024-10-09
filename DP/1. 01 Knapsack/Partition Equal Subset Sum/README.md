Partition Equal Subset Sum Problem
==================================

Definition
----------

The **Partition Equal Subset Sum Problem** is a variation of the subset sum problem where we are tasked with determining whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is equal.

### Problem Statement

Given a set of non-negative integers, the goal is to determine if the set can be divided into two subsets such that the sum of both subsets is equal.

### Example

Consider the set `S = {1, 5, 11, 5}`. The set can be divided into two subsets `{1, 5, 5}` and `{11}`, both having a sum of 11. Hence, the output is **true**.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach tries all combinations to check if there is a subset with a sum equal to half of the total sum of the set. If the total sum is odd, it's impossible to partition the set equally.

#### Pseudocode

    function canPartition(set, n, sum):
        if sum == 0:
            return true
        if n == 0:
            return false
        if set[n-1] > sum:
            return canPartition(set, n-1, sum)
        return canPartition(set, n-1, sum) or 
               canPartition(set, n-1, sum - set[n-1])
    

#### Java Implementation

    public class PartitionEqualSubsetSum {
        public static boolean canPartition(int[] set, int n, int sum) {
            if (sum == 0) {
                return true;
            }
            if (n == 0) {
                return false;
            }
            if (set[n - 1] > sum) {
                return canPartition(set, n - 1, sum);
            }
            return canPartition(set, n - 1, sum) || 
                   canPartition(set, n - 1, sum - set[n - 1]);
        }
    
        public static boolean canPartition(int[] set) {
            int sum = 0;
            for (int num : set) {
                sum += num;
            }
            if (sum % 2 != 0) {
                return false;
            }
            return canPartition(set, set.length, sum / 2);
        }
    
        public static void main(String[] args) {
            int[] set = {1, 5, 11, 5};
            System.out.println(canPartition(set));  // Output: true
        }
    }
    

### 2\. Memoization Approach

The memoization approach stores the results of subproblems to avoid redundant computations. The time complexity is reduced to `O(n * sum)`.

#### Pseudocode

    function canPartitionMemo(set, n, sum, memo):
        if memo[n][sum] is not -1:
            return memo[n][sum]
        if sum == 0:
            return true
        if n == 0:
            return false
        if set[n-1] > sum:
            memo[n][sum] = canPartitionMemo(set, n-1, sum, memo)
        else:
            memo[n][sum] = canPartitionMemo(set, n-1, sum, memo) or 
                           canPartitionMemo(set, n-1, sum - set[n-1], memo)
        return memo[n][sum]
    

#### Java Implementation

    public class PartitionEqualSubsetSum {
        public static boolean canPartitionMemo(int[] set, int n, int sum, Boolean[][] memo) {
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
                memo[n][sum] = canPartitionMemo(set, n - 1, sum, memo);
            } else {
                memo[n][sum] = canPartitionMemo(set, n - 1, sum, memo) || 
                               canPartitionMemo(set, n - 1, sum - set[n - 1], memo);
            }
            return memo[n][sum];
        }
    
        public static boolean canPartition(int[] set) {
            int sum = 0;
            for (int num : set) {
                sum += num;
            }
            if (sum % 2 != 0) {
                return false;
            }
            int halfSum = sum / 2;
            Boolean[][] memo = new Boolean[set.length + 1][halfSum + 1];
            return canPartitionMemo(set, set.length, halfSum, memo);
        }
    
        public static void main(String[] args) {
            int[] set = {1, 5, 11, 5};
            System.out.println(canPartition(set));  // Output: true
        }
    }
    

### 3\. Tabulation (Dynamic Programming) Approach

The tabulation approach uses a bottom-up dynamic programming technique to build a table that stores whether a subset sum can be formed for every possible sum. This method ensures optimal time complexity.

#### Pseudocode

    function canPartitionTabulation(set, n, sum):
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

    public class PartitionEqualSubsetSum {
        public static boolean canPartitionTabulation(int[] set) {
            int sum = 0;
            for (int num : set) {
                sum += num;
            }
            if (sum % 2 != 0) {
                return false;
            }
            int halfSum = sum / 2;
            boolean[][] dp = new boolean[set.length + 1][halfSum + 1];
            
            for (int i = 0; i <= set.length; i++) {
                dp[i][0] = true;
            }
            
            for (int j = 1; j <= halfSum; j++) {
                dp[0][j] = false;
            }
            
            for (int i = 1; i <= set.length; i++) {
                for (int j = 1; j <= halfSum; j++) {
                    if (set[i - 1] > j) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
                    }
                }
            }
            
            return dp[set.length][halfSum];
        }
    
        public static void main(String[] args) {
            int[] set = {1, 5, 11, 5};
            System.out.println(canPartitionTabulation(set));  // Output: true
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive:** O(2<sup>n</sup>) time, O(n) space (due to call stack)
*   **Memoization:** O(n \* sum) time, O(n \* sum) space (for the memoization table)
*   **Tabulation:** O(n \* sum) time, O(n \* sum) space (for the DP table)