Count of Subsets with a Given Sum
=================================

Problem Definition
------------------

The **Count of Subsets with a Given Sum** problem involves finding the number of subsets from a given set that sum to a specific value.

### Problem Statement

Given a set of non-negative integers and an integer `sum`, determine the number of subsets of the set that sum up to the given `sum`.

### Example

For the set `{2, 3, 5, 6, 8, 10}` and `sum = 10`, the subsets that sum to 10 are: `{2, 3, 5}` and `{10}`. Hence, the output is **2**.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach tries all possible subsets to count those that sum to the given value. This approach involves two choices: either include the current element in the subset or exclude it.

#### Pseudocode

    function countSubsets(set, n, sum):
        if sum == 0:
            return 1
        if n == 0:
            return 0
        if set[n-1] > sum:
            return countSubsets(set, n-1, sum)
        return countSubsets(set, n-1, sum) + 
               countSubsets(set, n-1, sum - set[n-1])
    

#### Java Implementation

    public class CountSubsetsWithGivenSum {
        public static int countSubsets(int[] set, int n, int sum) {
            if (sum == 0) {
                return 1;
            }
            if (n == 0) {
                return 0;
            }
            if (set[n - 1] > sum) {
                return countSubsets(set, n - 1, sum);
            }
            return countSubsets(set, n - 1, sum) + 
                   countSubsets(set, n - 1, sum - set[n - 1]);
        }
    
        public static void main(String[] args) {
            int[] set = {2, 3, 5, 6, 8, 10};
            int sum = 10;
            System.out.println(countSubsets(set, set.length, sum));  // Output: 3
        }
    }
    

### 2\. Memoization Approach

The memoization approach stores the results of subproblems to avoid redundant computations. It uses a table to store the result of each state defined by `(n, sum)`.

#### Pseudocode

    function countSubsetsMemo(set, n, sum, memo):
        if sum == 0:
            return 1
        if n == 0:
            return 0
        if memo[n][sum] is not -1:
            return memo[n][sum]
        if set[n-1] > sum:
            memo[n][sum] = countSubsetsMemo(set, n-1, sum, memo)
        else:
            memo[n][sum] = countSubsetsMemo(set, n-1, sum, memo) + 
                           countSubsetsMemo(set, n-1, sum - set[n-1], memo)
        return memo[n][sum]
    

#### Java Implementation

    public class CountSubsetsWithGivenSum {
        public static int countSubsetsMemo(int[] set, int n, int sum, Integer[][] memo) {
            if (sum == 0) {
                return 1;
            }
            if (n == 0) {
                return 0;
            }
            if (memo[n][sum] != null) {
                return memo[n][sum];
            }
            if (set[n - 1] > sum) {
                memo[n][sum] = countSubsetsMemo(set, n - 1, sum, memo);
            } else {
                memo[n][sum] = countSubsetsMemo(set, n - 1, sum, memo) + 
                               countSubsetsMemo(set, n - 1, sum - set[n - 1], memo);
            }
            return memo[n][sum];
        }
    
        public static void main(String[] args) {
            int[] set = {2, 3, 5, 6, 8, 10};
            int sum = 10;
            Integer[][] memo = new Integer[set.length + 1][sum + 1];
            System.out.println(countSubsetsMemo(set, set.length, sum, memo));  // Output: 3
        }
    }
    

### 3\. Tabulation (Dynamic Programming) Approach

The tabulation approach uses a bottom-up dynamic programming method to store the count of subsets that sum to every possible value up to the given sum.

#### Pseudocode

    function countSubsetsTabulation(set, n, sum):
        create a dp table of size (n+1) x (sum+1)
        
        for i from 0 to n:
            dp[i][0] = 1  // There's one subset (the empty subset) for sum = 0
        
        for j from 1 to sum:
            dp[0][j] = 0  // There's no subset for non-zero sum with 0 elements
        
        for i from 1 to n:
            for j from 1 to sum:
                if set[i-1] > j:
                    dp[i][j] = dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-set[i-1]]
        
        return dp[n][sum]
    

#### Java Implementation

    public class CountSubsetsWithGivenSum {
        public static int countSubsetsTabulation(int[] set, int sum) {
            int n = set.length;
            int[][] dp = new int[n + 1][sum + 1];
            
            // Initialize the dp array
            for (int i = 0; i <= n; i++) {
                dp[i][0] = 1;  // One way to make sum 0: the empty subset
            }
            for (int j = 1; j <= sum; j++) {
                dp[0][j] = 0;  // No way to make a non-zero sum with zero elements
            }
            
            // Fill the dp array
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= sum; j++) {
                    if (set[i - 1] > j) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - set[i - 1]];
                    }
                }
            }
            
            return dp[n][sum];
        }
    
        public static void main(String[] args) {
            int[] set = {2, 3, 5, 6, 8, 10};
            int sum = 10;
            System.out.println(countSubsetsTabulation(set, sum));  // Output: 3
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive:** O(2<sup>n</sup>) time, O(n) space (due to call stack)
*   **Memoization:** O(n \* sum) time, O(n \* sum) space (for the memoization table)
*   **Tabulation:** O(n \* sum) time, O(n \* sum) space (for the DP table)