Optimal Binary Search Tree Problem
==================================

Problem Definition
------------------

The **Optimal Binary Search Tree Problem** involves constructing a binary search tree with minimal search cost, given a set of keys with their corresponding access probabilities.

### Example

*   Input: `keys = [10, 12, 20]`, `probabilities = [0.34, 0.33, 0.33]`
*   Output: `Cost = 38.32`

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach (O(n^3))

This approach utilizes dynamic programming to build a table that stores the minimum search cost for each subtree.

#### Pseudocode

    function optimalBST(keys, probabilities):
            n = length(keys)
            cost = 2D array of size n x n
            for i from 0 to n:
                cost[i][i] = probabilities[i]  // only one key
            for length from 2 to n:
                for i from 0 to n - length:
                    j = i + length - 1
                    cost[i][j] = infinity
                    for r from i to j:
                        totalCost = cost[i][r - 1] + cost[r + 1][j] + sum of probabilities from i to j
                        if totalCost < cost[i][j]:
                            cost[i][j] = totalCost
            return cost[0][n - 1]
        

#### Java Implementation

    public class OptimalBinarySearchTree {
            public static double optimalBST(int[] keys, double[] probabilities) {
                int n = keys.length;
                double[][] cost = new double[n][n];
                for (int i = 0; i < n; i++) {
                    cost[i][i] = probabilities[i];
                }
                for (int length = 2; length <= n; length++) {
                    for (int i = 0; i <= n - length; i++) {
                        int j = i + length - 1;
                        cost[i][j] = Double.MAX_VALUE;
                        for (int r = i; r <= j; r++) {
                            double totalCost = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0) + sum of probabilities from i to j;
                            if (totalCost < cost[i][j]) {
                                cost[i][j] = totalCost;
                            }
                        }
                    }
                }
                return cost[0][n - 1];
            }
        }
        

### Time and Space Complexity

*   **Time Complexity:** O(n^3) - Due to the three nested loops iterating over the keys.
*   **Space Complexity:** O(n^2) - Space used for the 2D array to store costs.