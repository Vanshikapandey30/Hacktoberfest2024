Tribonacci Sequence
===================

Problem Definition
------------------

The **Tribonacci Sequence** is a sequence of numbers where each number is the sum of the three preceding ones, starting from `0`, `1`, and `1`. Formally, the sequence can be defined as:

*   `T(0) = 0`
*   `T(1) = 1`
*   `T(2) = 1`
*   `T(n) = T(n - 1) + T(n - 2) + T(n - 3)` for `n > 2`

### Example

For `n = 4`, the Tribonacci sequence is `0, 1, 1, 2, 4`. Therefore, `T(4) = 4`.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach directly follows the definition of the Tribonacci sequence.

#### Pseudocode

    function tribonacciRecursive(n):
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        return tribonacciRecursive(n - 1) + tribonacciRecursive(n - 2) + tribonacciRecursive(n - 3)
    

#### Java Implementation

    public class Tribonacci {
    
        public static int tribonacciRecursive(int n) {
            if (n == 0) return 0;
            if (n == 1 || n == 2) return 1;
            return tribonacciRecursive(n - 1) + tribonacciRecursive(n - 2) + tribonacciRecursive(n - 3);
        }
    
        public static void main(String[] args) {
            int n = 4; // Example input
            System.out.println(tribonacciRecursive(n));  // Output: 4
        }
    }
    

### 2\. Memoization Approach

The memoization approach optimizes the recursive solution by storing previously computed results to avoid redundant calculations.

#### Pseudocode

    function tribonacciMemo(n, memo):
        if memo[n] is not -1:
            return memo[n]
        if n == 0:
            return 0
        if n == 1 or n == 2:
            return 1
        memo[n] = tribonacciMemo(n - 1, memo) + tribonacciMemo(n - 2, memo) + tribonacciMemo(n - 3, memo)
        return memo[n]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class Tribonacci {
    
        public static int tribonacciMemo(int n, int[] memo) {
            if (memo[n] != -1) {
                return memo[n];
            }
            if (n == 0) return 0;
            if (n == 1 || n == 2) return 1;
            memo[n] = tribonacciMemo(n - 1, memo) + tribonacciMemo(n - 2, memo) + tribonacciMemo(n - 3, memo);
            return memo[n];
        }
    
        public static void main(String[] args) {
            int n = 4; // Example input
            int[] memo = new int[n + 1];
            Arrays.fill(memo, -1);
            System.out.println(tribonacciMemo(n, memo));  // Output: 4
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds a table iteratively to compute the number of ways to climb the stairs from the base up to `n`.

#### Pseudocode

    function tribonacciDP(n):
        dp = array of size n + 1
        dp[0] = 0
        dp[1] = 1
        dp[2] = 1
        for i from 3 to n:
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
        return dp[n]
    

#### Java Implementation

    public class Tribonacci {
    
        public static int tribonacciDP(int n) {
            if (n == 0) return 0;
            if (n == 1 || n == 2) return 1;
    
            int[] dp = new int[n + 1];
            dp[0] = 0;
            dp[1] = 1;
            dp[2] = 1;
    
            for (int i = 3; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            }
            return dp[n];
        }
    
        public static void main(String[] args) {
            int n = 4; // Example input
            System.out.println(tribonacciDP(n));  // Output: 4
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive Approach:** O(3<sup>n</sup>) time, O(n) space (due to recursion stack).
*   **Memoization Approach:** O(n) time, O(n) space (for memoization array).
*   **Dynamic Programming Approach:** O(n) time, O(n) space (for DP table).