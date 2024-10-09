Fibonacci Numbers
=================

Problem Definition
------------------

The **Fibonacci Sequence** is a series of numbers in which each number (after the first two) is the sum of the two preceding ones. The sequence commonly starts with `0` and `1`.

### Fibonacci Sequence Example

*   `F(0) = 0`
*   `F(1) = 1`
*   `F(2) = F(1) + F(0) = 1`
*   `F(3) = F(2) + F(1) = 2`
*   `F(4) = F(3) + F(2) = 3`
*   `F(5) = F(4) + F(3) = 5`
*   `F(6) = F(5) + F(4) = 8`
*   ...

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach directly implements the Fibonacci definition.

#### Pseudocode

    function fibonacciRecursive(n):
        if n == 0:
            return 0
        if n == 1:
            return 1
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2)
    

#### Java Implementation

    public class Fibonacci {
    
        public static int fibonacciRecursive(int n) {
            if (n == 0) {
                return 0;
            }
            if (n == 1) {
                return 1;
            }
            return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
        }
    
        public static void main(String[] args) {
            int n = 6; // Example input
            System.out.println(fibonacciRecursive(n));  // Output: 8
        }
    }
    

### 2\. Memoization Approach

The memoization approach optimizes the recursive method by storing already computed Fibonacci numbers.

#### Pseudocode

    function fibonacciMemo(n, memo):
        if memo[n] is not -1:
            return memo[n]
        if n == 0:
            return 0
        if n == 1:
            return 1
        memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo)
        return memo[n]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class Fibonacci {
    
        public static int fibonacciMemo(int n, int[] memo) {
            if (memo[n] != -1) {
                return memo[n];
            }
            if (n == 0) {
                return 0;
            }
            if (n == 1) {
                return 1;
            }
            memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
            return memo[n];
        }
    
        public static void main(String[] args) {
            int n = 6; // Example input
            int[] memo = new int[n + 1];
            Arrays.fill(memo, -1);
            System.out.println(fibonacciMemo(n, memo));  // Output: 8
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds a table iteratively to compute Fibonacci numbers from the bottom up.

#### Pseudocode

    function fibonacciDP(n):
        dp = array of size n + 1
        dp[0] = 0
        dp[1] = 1
        for i from 2 to n:
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]
    

#### Java Implementation

    public class Fibonacci {
    
        public static int fibonacciDP(int n) {
            int[] dp = new int[n + 1];
            dp[0] = 0;
            dp[1] = 1;
    
            for (int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
    
        public static void main(String[] args) {
            int n = 6; // Example input
            System.out.println(fibonacciDP(n));  // Output: 8
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive Approach:** O(2<sup>n</sup>) time, O(n) space (due to recursion stack).
*   **Memoization Approach:** O(n) time, O(n) space (for memoization array).
*   **Dynamic Programming Approach:** O(n) time, O(n) space (for DP table).