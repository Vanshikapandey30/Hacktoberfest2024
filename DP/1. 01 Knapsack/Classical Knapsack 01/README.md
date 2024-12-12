0/1 Knapsack Problem
====================

Definition
----------

The **0/1 Knapsack Problem** is a combinatorial optimization problem that aims to determine the most valuable subset of items that can fit into a knapsack with a fixed capacity. Each item can either be included (1) or excluded (0) from the knapsack, hence the name "0/1."

### Problem Statement

Given:

*   A set of items, each with a weight and a value.
*   A knapsack with a maximum weight capacity.

The objective is to maximize the total value of items placed in the knapsack without exceeding its weight capacity.

### Mathematical Formulation

Let:

*   `n` = number of items
*   `W` = maximum weight capacity of the knapsack
*   `w[i]` = weight of item `i`
*   `v[i]` = value of item `i`

The goal is to maximize:

    Maximize: ∑(v[i] * x[i]) 
    Subject to: ∑(w[i] * x[i]) ≤ W
    

Where:

*   `x[i]` is a binary variable (0 or 1) indicating whether item `i` is included in the knapsack.

Characteristics
---------------

*   **Decision Problem:** The problem can also be framed as a decision problem where the goal is to determine if a value `V` can be achieved without exceeding the weight capacity.
*   **Combinatorial Nature:** The problem explores the combination of items to find the optimal set.
*   **Exponential Complexity:** A naive approach may involve checking all subsets of items, leading to an exponential time complexity of `O(2n)`.

Solution Approaches
-------------------

### 1\. Recursive Approach

A straightforward recursive solution explores all possible combinations of items. However, it is inefficient for larger input sizes due to its exponential time complexity.

#### Pseudocode

    function knapsackRecursive(weights, values, capacity, n):
        if n == 0 or capacity == 0:
            return 0
        if weights[n - 1] > capacity:
            return knapsackRecursive(weights, values, capacity, n - 1)
        else:
            return max(values[n - 1] + knapsackRecursive(weights, values, capacity - weights[n - 1], n - 1), 
                       knapsackRecursive(weights, values, capacity, n - 1))
    

#### Java Implementation

    public class Knapsack {
        public static int knapsackRecursive(int[] weights, int[] values, int capacity, int n) {
            if (n == 0 || capacity == 0) {
                return 0;
            }
            if (weights[n - 1] > capacity) {
                return knapsackRecursive(weights, values, capacity, n - 1);
            } else {
                return Math.max(values[n - 1] + knapsackRecursive(weights, values, capacity - weights[n - 1], n - 1),
                                knapsackRecursive(weights, values, capacity, n - 1));
            }
        }
    }
    

### 2\. Memoization Approach

Memoization improves the recursive solution by storing the results of subproblems to avoid redundant calculations. This reduces the time complexity significantly.

#### Pseudocode

    function knapsackMemoization(weights, values, capacity, n, memo):
        if memo[n][capacity] is not -1:
            return memo[n][capacity]
        if n == 0 or capacity == 0:
            return 0
        if weights[n - 1] > capacity:
            memo[n][capacity] = knapsackMemoization(weights, values, capacity, n - 1, memo)
        else:
            memo[n][capacity] = max(values[n - 1] + knapsackMemoization(weights, values, capacity - weights[n - 1], n - 1, memo), 
                                   knapsackMemoization(weights, values, capacity, n - 1, memo))
        return memo[n][capacity]
    

#### Java Implementation

    public class Knapsack {
        public static int knapsackMemoization(int[] weights, int[] values, int capacity, int n, int[][] memo) {
            if (memo[n][capacity] != -1) {
                return memo[n][capacity];
            }
            if (n == 0 || capacity == 0) {
                return 0;
            }
            if (weights[n - 1] > capacity) {
                memo[n][capacity] = knapsackMemoization(weights, values, capacity, n - 1, memo);
            } else {
                memo[n][capacity] = Math.max(values[n - 1] + knapsackMemoization(weights, values, capacity - weights[n - 1], n - 1, memo), 
                                              knapsackMemoization(weights, values, capacity, n - 1, memo));
            }
            return memo[n][capacity];
        }
    
        public static void main(String[] args) {
            int[] weights = {1, 2, 3};
            int[] values = {60, 100, 120};
            int capacity = 5;
            int n = weights.length;
            int[][] memo = new int[n + 1][capacity + 1];
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= capacity; j++) {
                    memo[i][j] = -1;  // Initialize memoization table
                }
            }
            System.out.println(knapsackMemoization(weights, values, capacity, n, memo));  // Output: 220
        }
    }
    

### 3\. Tabulation Approach

Tabulation uses an iterative approach to fill a table based on previously computed values. This approach is often preferred for its clarity and efficiency.

#### Pseudocode

    function knapsackTabulation(weights, values, capacity):
        n = length(weights)
        create dp table of size (n + 1) x (capacity + 1)
    
        for i from 1 to n:
            for w from 1 to capacity:
                if weights[i-1] <= w:
                    dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + values[i-1])
                else:
                    dp[i][w] = dp[i-1][w]
    
        return dp[n][capacity]
    

#### Java Implementation

    public class Knapsack {
        public static int knapsackTabulation(int[] weights, int[] values, int capacity) {
            int n = weights.length;
            int[][] dp = new int[n + 1][capacity + 1];
            
            for (int i = 1; i <= n; i++) {
                for (int w = 1; w <= capacity; w++) {
                    if (weights[i - 1] <= w) {
                        dp[i][w] = Math.max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
                    } else {
                        dp[i][w] = dp[i - 1][w];
                    }
                }
            }
            
            return dp[n][capacity];
        }
    
        public static void main(String[] args) {
            int[] weights = {1, 2, 3};
            int[] values = {60, 100, 120};
            int capacity = 5;
            System.out.println(knapsackTabulation(weights, values, capacity));  // Output: 220
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive:** O(2<sup>n</sup>) time, O(n) space (due to call stack)
*   **Memoization:** O(n \* W) time, O(n \* W) space (for the memoization table)
*   **Tabulation:** O(n \* W) time, O(n \* W) space (for the DP table)

Conclusion
----------

The 0/1 Knapsack Problem can be approached using various methods, each with its own trade-offs in terms of complexity and efficiency. The recursive approach provides a clear understanding of the problem, while memoization and tabulation enhance performance, making them suitable for larger inputs.