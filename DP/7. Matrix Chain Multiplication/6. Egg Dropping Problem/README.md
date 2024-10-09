Egg Dropping Problem
====================

Problem Definition
------------------

The **Egg Dropping Problem** involves determining the minimum number of attempts needed to find the highest floor from which an egg can be dropped without breaking, given a certain number of eggs and floors.

### Example

*   Input: `eggs = 2`, `floors = 10`
*   Output: `4` (The minimum number of attempts needed)

Solution Approaches
-------------------

### 1\. Recursive Approach

This approach uses recursion to explore all possible floors to drop the egg from, counting the number of attempts needed.

#### Pseudocode

    function eggDrop(eggs, floors):
            if floors == 0 or floors == 1:
                return floors
            if eggs == 1:
                return floors
            minAttempts = infinity
            for floor from 1 to floors:
                attempts = 1 + max(eggDrop(eggs - 1, floor - 1), eggDrop(eggs, floors - floor))
                minAttempts = min(minAttempts, attempts)
            return minAttempts
        

#### Time and Space Complexity (Recursive Approach)

*   **Time Complexity:** O(2^n) - Exponential due to recursive calls.
*   **Space Complexity:** O(n) - Due to recursive stack space.

### 2\. Dynamic Programming Approach (Top-Down)

This approach utilizes memoization to store the results of subproblems to avoid redundant calculations.

#### Pseudocode

    function eggDrop(eggs, floors, memo):
            if memo[eggs][floors] is not -1:
                return memo[eggs][floors]
            if floors == 0 or floors == 1:
                return floors
            if eggs == 1:
                return floors
            minAttempts = infinity
            for floor from 1 to floors:
                attempts = 1 + max(eggDrop(eggs - 1, floor - 1, memo), eggDrop(eggs, floors - floor, memo))
                minAttempts = min(minAttempts, attempts)
            memo[eggs][floors] = minAttempts
            return minAttempts
        

#### Java Implementation

    public class EggDropping {
            public static int eggDrop(int eggs, int floors) {
                int[][] memo = new int[eggs + 1][floors + 1];
                for (int[] row : memo) {
                    Arrays.fill(row, -1);
                }
                return eggDrop(eggs, floors, memo);
            }
    
            private static int eggDrop(int eggs, int floors, int[][] memo) {
                if (floors == 0 || floors == 1) return floors;
                if (eggs == 1) return floors;
                if (memo[eggs][floors] != -1) return memo[eggs][floors];
    
                int minAttempts = Integer.MAX_VALUE;
                for (int floor = 1; floor <= floors; floor++) {
                    int attempts = 1 + Math.max(eggDrop(eggs - 1, floor - 1, memo), eggDrop(eggs, floors - floor, memo));
                    minAttempts = Math.min(minAttempts, attempts);
                }
                memo[eggs][floors] = minAttempts;
                return minAttempts;
            }
        }
        

#### Time and Space Complexity (Top-Down Dynamic Programming)

*   **Time Complexity:** O(eggs \* floors^2) - Due to two nested loops over the floors.
*   **Space Complexity:** O(eggs \* floors) - For the memoization table.

### 3\. Dynamic Programming Approach (Bottom-Up)

This approach constructs a table iteratively to build up the solution to the problem.

#### Pseudocode

    function eggDrop(eggs, floors):
            dp = 2D array of size (eggs + 1) x (floors + 1)
            for i from 1 to eggs:
                dp[i][0] = 0  // 0 floors require 0 attempts
                dp[i][1] = 1  // 1 floor requires 1 attempt
            for j from 1 to floors:
                dp[1][j] = j  // 1 egg requires j attempts
    
            for i from 2 to eggs:
                for j from 2 to floors:
                    minAttempts = infinity
                    for floor from 1 to j:
                        attempts = 1 + max(dp[i - 1][floor - 1], dp[i][j - floor])
                        minAttempts = min(minAttempts, attempts)
                    dp[i][j] = minAttempts
            return dp[eggs][floors]
        

#### Java Implementation

    public class EggDropping {
            public static int eggDrop(int eggs, int floors) {
                int[][] dp = new int[eggs + 1][floors + 1];
    
                for (int i = 1; i <= eggs; i++) {
                    dp[i][0] = 0;  // 0 floors require 0 attempts
                    dp[i][1] = 1;  // 1 floor requires 1 attempt
                }
                for (int j = 1; j <= floors; j++) {
                    dp[1][j] = j;  // 1 egg requires j attempts
                }
    
                for (int i = 2; i <= eggs; i++) {
                    for (int j = 2; j <= floors; j++) {
                        int minAttempts = Integer.MAX_VALUE;
                        for (int floor = 1; floor <= j; floor++) {
                            int attempts = 1 + Math.max(dp[i - 1][floor - 1], dp[i][j - floor]);
                            minAttempts = Math.min(minAttempts, attempts);
                        }
                        dp[i][j] = minAttempts;
                    }
                }
                return dp[eggs][floors];
            }
        }
        

#### Time and Space Complexity (Bottom-Up Dynamic Programming)

*   **Time Complexity:** O(eggs \* floors^2) - Due to two nested loops iterating over the number of eggs and floors.
*   **Space Complexity:** O(eggs \* floors) - For the DP table.