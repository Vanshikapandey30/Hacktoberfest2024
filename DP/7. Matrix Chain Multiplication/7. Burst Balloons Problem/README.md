Burst Balloons Problem
======================

Problem Definition
------------------

The **Burst Balloons Problem** involves maximizing the number of coins you can collect by bursting balloons. Each balloon has a value, and when you burst a balloon, you earn coins equal to the product of its value and the values of the adjacent balloons.

### Example

*   Input: `nums = [3, 1, 5, 8]`
*   Output: `167` (The maximum coins obtainable)

Solution Approaches
-------------------

### 1\. Dynamic Programming (Bottom-Up)

This approach builds a DP table where the entry `dp[i][j]` represents the maximum coins obtainable by bursting all the balloons between indices `i` and `j`.

#### Pseudocode

    function maxCoins(nums):
            n = length of nums
            dp = 2D array of size (n + 2) x (n + 2)
            extendedNums = [1] + nums + [1]  // Add 1 on both ends
    
            for length from 1 to n:
                for left from 1 to n - length + 1:
                    right = left + length - 1
                    for k from left to right:
                        coins = extendedNums[left - 1] * extendedNums[k] * extendedNums[right + 1]
                        dp[left][right] = max(dp[left][right], dp[left][k - 1] + dp[k + 1][right] + coins)
    
            return dp[1][n]
        

#### Java Implementation

    public class BurstBalloons {
            public static int maxCoins(int[] nums) {
                int n = nums.length;
                int[][] dp = new int[n + 2][n + 2];
                int[] extendedNums = new int[n + 2];
                extendedNums[0] = 1;  // Add 1 at the start
                for (int i = 1; i <= n; i++) {
                    extendedNums[i] = nums[i - 1];
                }
                extendedNums[n + 1] = 1;  // Add 1 at the end
    
                for (int length = 1; length <= n; length++) {
                    for (int left = 1; left <= n - length + 1; left++) {
                        int right = left + length - 1;
                        for (int k = left; k <= right; k++) {
                            int coins = extendedNums[left - 1] * extendedNums[k] * extendedNums[right + 1];
                            dp[left][right] = Math.max(dp[left][right], dp[left][k - 1] + dp[k + 1][right] + coins);
                        }
                    }
                }
                return dp[1][n];
            }
        }
        

#### Time and Space Complexity (Dynamic Programming)

*   **Time Complexity:** O(n^3) - Due to three nested loops iterating over the length of the balloons.
*   **Space Complexity:** O(n^2) - For the DP table.

### 2\. Memoization Approach (Top-Down)

This approach uses a recursive function combined with memoization to store results of subproblems to avoid recalculating them.

#### Pseudocode

    function maxCoins(nums):
            n = length of nums
            extendedNums = [1] + nums + [1]
            memo = 2D array of size (n + 2) x (n + 2) initialized to -1
    
            return dfs(1, n, memo, extendedNums)
    
        function dfs(left, right, memo, extendedNums):
            if left > right:
                return 0
            if memo[left][right] != -1:
                return memo[left][right]
    
            maxCoins = 0
            for k from left to right:
                coins = extendedNums[left - 1] * extendedNums[k] * extendedNums[right + 1]
                maxCoins = max(maxCoins, coins + dfs(left, k - 1, memo, extendedNums) + dfs(k + 1, right, memo, extendedNums))
            memo[left][right] = maxCoins
            return maxCoins
        

#### Java Implementation

    public class BurstBalloons {
            public static int maxCoins(int[] nums) {
                int n = nums.length;
                int[] extendedNums = new int[n + 2];
                extendedNums[0] = 1;  // Add 1 at the start
                for (int i = 1; i <= n; i++) {
                    extendedNums[i] = nums[i - 1];
                }
                extendedNums[n + 1] = 1;  // Add 1 at the end
                int[][] memo = new int[n + 2][n + 2];
                for (int[] row : memo) {
                    Arrays.fill(row, -1);
                }
                return dfs(1, n, memo, extendedNums);
            }
    
            private static int dfs(int left, int right, int[][] memo, int[] extendedNums) {
                if (left > right) return 0;
                if (memo[left][right] != -1) return memo[left][right];
    
                int maxCoins = 0;
                for (int k = left; k <= right; k++) {
                    int coins = extendedNums[left - 1] * extendedNums[k] * extendedNums[right + 1];
                    maxCoins = Math.max(maxCoins, coins + dfs(left, k - 1, memo, extendedNums) + dfs(k + 1, right, memo, extendedNums));
                }
                memo[left][right] = maxCoins;
                return maxCoins;
            }
        }
        

#### Time and Space Complexity (Memoization)

*   **Time Complexity:** O(n^2) - Each state is computed once.
*   **Space Complexity:** O(n^2) - For the memoization table.