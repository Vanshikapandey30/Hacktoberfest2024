Matrix Chain Multiplication Problem
===================================

Problem Definition
------------------

The **Matrix Chain Multiplication Problem** involves finding the most efficient way to multiply a given sequence of matrices. The goal is to minimize the total number of scalar multiplications.

### Example

*   Input: `dimensions = [10, 20, 30, 40]`
*   Output: `6000` (The optimal parenthesization gives the minimum cost)

Solution Approaches
-------------------

### 1\. Recursive Approach (Exponential Time)

This approach uses recursion to calculate the minimum cost of multiplying matrices by trying all possible parenthesizations.

#### Pseudocode

    function matrixChainOrder(p, i, j):
            if i == j:
                return 0
            minCost = infinity
            for k from i to j - 1:
                cost = matrixChainOrder(p, i, k) + matrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j]
                minCost = min(minCost, cost)
            return minCost
        

#### Java Implementation

    public class MatrixChainMultiplicationRecursive {
            public static int matrixChainOrder(int[] p, int i, int j) {
                if (i == j) return 0;
                int minCost = Integer.MAX_VALUE;
                for (int k = i; k < j; k++) {
                    int cost = matrixChainOrder(p, i, k) + matrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
                    minCost = Math.min(minCost, cost);
                }
                return minCost;
            }
        }
        

### Time and Space Complexity (Recursive Approach)

*   **Time Complexity:** O(2<sup>n</sup>) - Due to the exponential number of recursive calls.
*   **Space Complexity:** O(n) - Space used by the recursion stack.

### 2\. Dynamic Programming Approach (O(n<sup>3</sup>))

This approach utilizes a 2D array to store the minimum multiplication costs for subproblems, avoiding redundant calculations.

#### Pseudocode

    function matrixChainOrder(p):
            n = length(p) - 1
            m = 2D array of size n x n
            for length from 2 to n:
                for i from 1 to n - length + 1:
                    j = i + length - 1
                    m[i][j] = infinity
                    for k from i to j - 1:
                        cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                        m[i][j] = min(m[i][j], cost)
            return m[1][n]
        

#### Java Implementation

    public class MatrixChainMultiplicationDP {
            public static int matrixChainOrder(int[] p) {
                int n = p.length - 1;
                int[][] m = new int[n + 1][n + 1];
                for (int length = 2; length <= n; length++) {
                    for (int i = 1; i <= n - length + 1; i++) {
                        int j = i + length - 1;
                        m[i][j] = Integer.MAX_VALUE;
                        for (int k = i; k < j; k++) {
                            int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                            m[i][j] = Math.min(m[i][j], cost);
                        }
                    }
                }
                return m[1][n];
            }
        }
        

### Time and Space Complexity (Dynamic Programming Approach)

*   **Time Complexity:** O(n<sup>3</sup>) - Due to the triple nested loop iterating through the dimensions.
*   **Space Complexity:** O(n<sup>2</sup>) - Space used for the 2D array to store costs.