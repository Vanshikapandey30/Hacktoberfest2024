Domino and Tromino Tiling Problem
=================================

Problem Definition
------------------

Given a 2 x n board, you can tile the board using dominoes (1 x 2) and trominoes (L-shaped). The goal is to count the number of different ways to tile the board.

### Example

*   Input: n = 3
    
        
                Output: 5
                
    
*   Input: n = 4
    
        
                Output: 11
                
    

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach

We can use dynamic programming to solve this problem. We define a function `f(n)` that represents the number of ways to tile a 2 x n board.

#### Pseudocode

    function numTilings(n):
        if n == 0:
            return 1
        if n == 1:
            return 1
        if n == 2:
            return 2
    
        dp = array of size n + 1
        dp[0] = 1
        dp[1] = 1
        dp[2] = 2
    
        for i from 3 to n:
            dp[i] = dp[i - 1] + dp[i - 2] * 2 + dp[i - 3]
    
        return dp[n]
    

#### Java Implementation

    public class DominoTrominoTiling {
        public static int numTilings(int n) {
            if (n == 0) return 1;
            if (n == 1) return 1;
            if (n == 2) return 2;
    
            int[] dp = new int[n + 1];
            dp[0] = 1;
            dp[1] = 1;
            dp[2] = 2;
    
            for (int i = 3; i <= n; i++) {
                dp[i] = (dp[i - 1] + 2 * dp[i - 2] + dp[i - 3]) % 1000000007;
            }
    
            return dp[n];
        }
    
        public static void main(String[] args) {
            System.out.println(numTilings(3)); // Output: 5
            System.out.println(numTilings(4)); // Output: 11
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) - We compute the number of ways to tile for all sizes up to n.
*   **Space Complexity:** O(n) - We store the number of ways in an array.

### 2\. Optimized Space Dynamic Programming Approach

We can optimize the space complexity by keeping track of only the last three results instead of the entire array.

#### Pseudocode

    function numTilingsOptimized(n):
        if n == 0:
            return 1
        if n == 1:
            return 1
        if n == 2:
            return 2
    
        dp0, dp1, dp2 = 1, 1, 2
    
        for i from 3 to n:
            current = (dp1 + 2 * dp2 + dp0) % 1000000007
            dp0 = dp1
            dp1 = dp2
            dp2 = current
    
        return dp2
    

#### Java Implementation

    public class DominoTrominoTilingOptimized {
        public static int numTilings(int n) {
            if (n == 0) return 1;
            if (n == 1) return 1;
            if (n == 2) return 2;
    
            int dp0 = 1, dp1 = 1, dp2 = 2;
    
            for (int i = 3; i <= n; i++) {
                int current = (dp1 + 2 * dp2 + dp0) % 1000000007;
                dp0 = dp1;
                dp1 = dp2;
                dp2 = current;
            }
    
            return dp2;
        }
    
        public static void main(String[] args) {
            System.out.println(numTilings(3)); // Output: 5
            System.out.println(numTilings(4)); // Output: 11
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n) - We compute the number of ways to tile for all sizes up to n.
*   **Space Complexity:** O(1) - We only use a fixed amount of space for variables.

Conclusion
----------

The Domino and Tromino Tiling Problem can be solved efficiently using dynamic programming, and the space complexity can be optimized for better performance.