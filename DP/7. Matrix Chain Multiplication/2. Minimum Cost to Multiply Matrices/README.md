Minimum Cost to Multiply Matrices
=================================

Problem Definition
------------------

The **Minimum Cost to Multiply Matrices** problem is a specific case of the Matrix Chain Multiplication problem, where the goal is to determine the minimum cost of multiplying a chain of matrices together, given their dimensions.

### Example

*   Input: `dimensions = [10, 20, 30, 40]`
*   Output: `6000` (The optimal parenthesization gives the minimum cost)

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach (O(n<sup>3</sup>))

This approach involves using a dynamic programming table to store the minimum multiplication costs for different subproblems.

#### Pseudocode

    function minCost(p):
            n = length(p) - 1
            dp = 2D array of size n x n
            for length from 2 to n:
                for i from 1 to n - length + 1:
                    j = i + length - 1
                    dp[i][j] = infinity
                    for k from i to j - 1:
                        cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]
                        dp[i][j] = min(dp[i][j], cost)
            return dp[1][n]
        

#### Java Implementation

    public class MinimumCostToMultiplyMatrices {
            public static int minCost(int[] p) {
                int n = p.length - 1;
                int[][] dp = new int[n + 1][n + 1];
                for (int length = 2; length <= n; length++) {
                    for (int i = 1; i <= n - length + 1; i++) {
                        int j = i + length - 1;
                        dp[i][j] = Integer.MAX_VALUE;
                        for (int k = i; k < j; k++) {
                            int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                            dp[i][j] = Math.min(dp[i][j], cost);
                        }
                    }
                }
                return dp[1][n];
            }
        }
        

### Time and Space Complexity

*   **Time Complexity:** O(n<sup>3</sup>) - Due to the triple nested loop iterating through the dimensions.
*   **Space Complexity:** O(n<sup>2</sup>) - Space used for the 2D array to store costs.