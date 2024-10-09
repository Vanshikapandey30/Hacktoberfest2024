Frog Jump Problem
=================

Problem Definition
------------------

In the **Frog Jump Problem**, the frog starts at the first stone and wants to reach the last stone by jumping between stones. The frog can only jump from the current stone to the next stone, and each stone has a specific cost associated with it. The frog wants to minimize the total cost of reaching the last stone.

### Example

*   Input: `[10, 30, 40, 20]`
*   Output: `30`
*   Explanation: Jump from stone 1 to stone 2, then jump from stone 2 to stone 4 (total cost = 30).

### Constraints

*   Costs are positive integers.
*   The frog can jump one or two steps at a time.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach tries all possible jumps from the current stone and calculates the minimum cost recursively.

#### Pseudocode

    function frogJumpRecursive(index, costs):
        if index == 0:
            return 0
        if index == 1:
            return abs(costs[1] - costs[0])
        jumpOne = frogJumpRecursive(index - 1, costs) + abs(costs[index] - costs[index - 1])
        jumpTwo = frogJumpRecursive(index - 2, costs) + abs(costs[index] - costs[index - 2])
        return min(jumpOne, jumpTwo)
    

#### Java Implementation

    public class FrogJump {
    
        public static int frogJumpRecursive(int index, int[] costs) {
            if (index == 0) return 0;
            if (index == 1) return Math.abs(costs[1] - costs[0]);
            
            int jumpOne = frogJumpRecursive(index - 1, costs) + Math.abs(costs[index] - costs[index - 1]);
            int jumpTwo = frogJumpRecursive(index - 2, costs) + Math.abs(costs[index] - costs[index - 2]);
            
            return Math.min(jumpOne, jumpTwo);
        }
    
        public static void main(String[] args) {
            int[] costs = {10, 30, 40, 20};
            System.out.println(frogJumpRecursive(costs.length - 1, costs));  // Output: 30
        }
    }
    

### 2\. Memoization Approach

This approach optimizes the recursive solution by storing the results of subproblems (costs for each stone) in a memoization array to avoid recalculating them.

#### Pseudocode

    function frogJumpMemo(index, costs, memo):
        if memo[index] != -1:
            return memo[index]
        if index == 0:
            return 0
        if index == 1:
            return abs(costs[1] - costs[0])
        jumpOne = frogJumpMemo(index - 1, costs, memo) + abs(costs[index] - costs[index - 1])
        jumpTwo = frogJumpMemo(index - 2, costs, memo) + abs(costs[index] - costs[index - 2])
        memo[index] = min(jumpOne, jumpTwo)
        return memo[index]
    

#### Java Implementation

    public class FrogJump {
    
        public static int frogJumpMemo(int index, int[] costs, int[] memo) {
            if (memo[index] != -1) return memo[index];
            if (index == 0) return 0;
            if (index == 1) return Math.abs(costs[1] - costs[0]);
            
            int jumpOne = frogJumpMemo(index - 1, costs, memo) + Math.abs(costs[index] - costs[index - 1]);
            int jumpTwo = frogJumpMemo(index - 2, costs, memo) + Math.abs(costs[index] - costs[index - 2]);
            
            memo[index] = Math.min(jumpOne, jumpTwo);
            return memo[index];
        }
    
        public static void main(String[] args) {
            int[] costs = {10, 30, 40, 20};
            int[] memo = new int[costs.length];
            Arrays.fill(memo, -1);
            System.out.println(frogJumpMemo(costs.length - 1, costs, memo));  // Output: 30
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds up the solution iteratively, storing the minimum cost at each step in a table.

#### Pseudocode

    function frogJumpDP(costs):
        dp[0] = 0
        dp[1] = abs(costs[1] - costs[0])
        for i from 2 to costs.length - 1:
            jumpOne = dp[i - 1] + abs(costs[i] - costs[i - 1])
            jumpTwo = dp[i - 2] + abs(costs[i] - costs[i - 2])
            dp[i] = min(jumpOne, jumpTwo)
        return dp[costs.length - 1]
    

#### Java Implementation

    public class FrogJump {
    
        public static int frogJumpDP(int[] costs) {
            if (costs.length == 1) return 0;
            if (costs.length == 2) return Math.abs(costs[1] - costs[0]);
            
            int[] dp = new int[costs.length];
            dp[0] = 0;
            dp[1] = Math.abs(costs[1] - costs[0]);
            
            for (int i = 2; i < costs.length; i++) {
                int jumpOne = dp[i - 1] + Math.abs(costs[i] - costs[i - 1]);
                int jumpTwo = dp[i - 2] + Math.abs(costs[i] - costs[i - 2]);
                dp[i] = Math.min(jumpOne, jumpTwo);
            }
            
            return dp[costs.length - 1];
        }
    
        public static void main(String[] args) {
            int[] costs = {10, 30, 40, 20};
            System.out.println(frogJumpDP(costs));  // Output: 30
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive Approach:** O(2<sup>n</sup>) time, O(n) space (due to recursion stack).
*   **Memoization Approach:** O(n) time, O(n) space (due to memoization array).
*   **Dynamic Programming (Tabulation) Approach:** O(n) time, O(n) space (due to dp array).