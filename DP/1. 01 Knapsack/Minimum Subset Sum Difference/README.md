Minimum Subset Sum Difference Problem
=====================================

Problem Definition
------------------

The **Minimum Subset Sum Difference Problem** involves partitioning a given set into two subsets such that the difference between their sums is minimized.

### Problem Statement

Given an array of integers, partition it into two subsets such that the absolute difference between the sum of elements in both subsets is minimized.

### Example

For the array `{1, 6, 11, 5}`, one possible partition is `{1, 6, 5}` and `{11}`. The difference between their sums is **1**, which is the minimum possible difference.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach checks all subsets and calculates the minimum difference for each subset pair.

#### Pseudocode

    function minSubsetSumDiffRecursive(nums, n, sum1, sum2):
        if n == 0:
            return abs(sum1 - sum2)
        includeCurrent = minSubsetSumDiffRecursive(nums, n-1, sum1 + nums[n-1], sum2)
        excludeCurrent = minSubsetSumDiffRecursive(nums, n-1, sum1, sum2 + nums[n-1])
        return min(includeCurrent, excludeCurrent)
    

#### Java Implementation

    public class MinimumSubsetSumDifference {
        public static int minSubsetSumDiffRecursive(int[] nums, int n, int sum1, int sum2) {
            if (n == 0) {
                return Math.abs(sum1 - sum2);
            }
            return Math.min(
                minSubsetSumDiffRecursive(nums, n - 1, sum1 + nums[n - 1], sum2),
                minSubsetSumDiffRecursive(nums, n - 1, sum1, sum2 + nums[n - 1])
            );
        }
    
        public static void main(String[] args) {
            int[] nums = {1, 6, 11, 5};
            System.out.println(minSubsetSumDiffRecursive(nums, nums.length, 0, 0));  // Output: 1
        }
    }
    

### 2\. Memoization Approach

The memoization approach stores the results of subproblems to avoid redundant calculations.

#### Pseudocode

    function minSubsetSumDiffMemo(nums, n, sum1, total, memo):
        if n == 0:
            return abs(sum1 - (total - sum1))
        if memo[n][sum1] != null:
            return memo[n][sum1]
        memo[n][sum1] = min(
            minSubsetSumDiffMemo(nums, n-1, sum1 + nums[n-1], total, memo),
            minSubsetSumDiffMemo(nums, n-1, sum1, total, memo)
        )
        return memo[n][sum1]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class MinimumSubsetSumDifference {
        public static int minSubsetSumDiffMemo(int[] nums, int n, int sum1, int total, int[][] memo) {
            if (n == 0) {
                return Math.abs(sum1 - (total - sum1));
            }
            if (memo[n][sum1] != -1) {
                return memo[n][sum1];
            }
            memo[n][sum1] = Math.min(
                minSubsetSumDiffMemo(nums, n - 1, sum1 + nums[n - 1], total, memo),
                minSubsetSumDiffMemo(nums, n - 1, sum1, total, memo)
            );
            return memo[n][sum1];
        }
    
        public static void main(String[] args) {
            int[] nums = {1, 6, 11, 5};
            int total = Arrays.stream(nums).sum();
            int[][] memo = new int[nums.length + 1][total + 1];
            for (int[] row : memo) {
                Arrays.fill(row, -1);
            }
            System.out.println(minSubsetSumDiffMemo(nums, nums.length, 0, total, memo));  // Output: 1
        }
    }
    

### 3\. Dynamic Programming Approach

The dynamic programming approach uses a boolean table to check possible sums that can be formed, and then calculates the minimum difference.

#### Pseudocode

    function minSubsetSumDiffDP(nums):
        totalSum = sum(nums)
        sumSubset = totalSum // 2
        dp = 2D array of size (n+1) x (sumSubset+1)
        
        for i from 0 to n:
            dp[i][0] = true
            
        for i from 1 to n:
            for j from 1 to sumSubset:
                if nums[i-1] <= j:
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]]
                else:
                    dp[i][j] = dp[i-1][j]
    
        minimumDifference = totalSum
        for j from sumSubset to 0:
            if dp[n][j] == true:
                minimumDifference = min(minimumDifference, totalSum - 2*j)
        
        return minimumDifference
    

#### Java Implementation

    public class MinimumSubsetSumDifference {
        public static int minSubsetSumDiffDP(int[] nums) {
            int totalSum = Arrays.stream(nums).sum();
            int sumSubset = totalSum / 2;
            boolean[][] dp = new boolean[nums.length + 1][sumSubset + 1];
    
            for (int i = 0; i <= nums.length; i++) {
                dp[i][0] = true;
            }
    
            for (int i = 1; i <= nums.length; i++) {
                for (int j = 1; j <= sumSubset; j++) {
                    if (nums[i - 1] <= j) {
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
    
            int minimumDifference = Integer.MAX_VALUE;
            for (int j = sumSubset; j >= 0; j--) {
                if (dp[nums.length][j]) {
                    minimumDifference = Math.min(minimumDifference, totalSum - 2 * j);
                }
            }
    
            return minimumDifference;
        }
    
        public static void main(String[] args) {
            int[] nums = {1, 6, 11, 5};
            System.out.println(minSubsetSumDiffDP(nums));  // Output: 1
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive:** O(2<sup>n</sup>) time, O(n) space (due to call stack)
*   **Memoization:** O(n \* totalSum) time, O(n \* totalSum) space (for the memoization table)
*   **Dynamic Programming:** O(n \* sumSubset) time, O(n \* sumSubset) space (for the DP table)