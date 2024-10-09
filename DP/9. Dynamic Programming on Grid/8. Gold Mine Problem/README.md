Gold Mine Problem
=================

Problem Definition
------------------

The Gold Mine Problem involves finding the maximum amount of gold that can be collected by a miner starting from any cell in the first column of a grid representing a gold mine. The miner can only move to the right, diagonally up to the right, or diagonally down to the right. Each cell contains a certain amount of gold, and the goal is to determine the maximum gold the miner can collect.

### Example

*   Input: Gold Mine =
    
        
                [
                    [0, 1, 4, 2],
                    [3, 0, 0, 4],
                    [2, 2, 4, 0],
                    [0, 0, 2, 1]
                ]
                
    
*   Output: Maximum gold collected = 15
    
        
                Explanation: Starting from the first row (0,0), the path would be (0,0) -> (1,1) -> (2,2) -> (2,3) or (0,0) -> (1,1) -> (2,2) -> (3,3) for a total of 15 gold.
                
    

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach

This approach uses a 2D DP table to keep track of the maximum gold collected up to each cell in the grid. We start filling the DP table from the last column to the first, calculating the maximum gold for each cell based on possible movements.

#### Pseudocode

    function getMaxGold(gold):
        n = number of rows in gold
        m = number of columns in gold
        create a dp array of size n x m
        
        for j from m-1 down to 0:
            for i from 0 to n-1:
                right = gold[i][j] + (dp[i][j + 1] if j + 1 < m)
                rightUp = gold[i][j] + (dp[i - 1][j + 1] if i > 0 and j + 1 < m)
                rightDown = gold[i][j] + (dp[i + 1][j + 1] if i + 1 < n and j + 1 < m)
                
                dp[i][j] = max(right, rightUp, rightDown)
        
        maxGold = 0
        for i from 0 to n-1:
            maxGold = max(maxGold, dp[i][0])
        
        return maxGold
    

#### Java Implementation

    public class GoldMineProblem {
        public static int getMaxGold(int[][] gold) {
            int n = gold.length;
            int m = gold[0].length;
            int[][] dp = new int[n][m];
            
            for (int j = m - 1; j >= 0; j--) {
                for (int i = 0; i < n; i++) {
                    int right = (j == m - 1) ? 0 : dp[i][j + 1];
                    int rightUp = (i > 0 && j < m - 1) ? dp[i - 1][j + 1] : 0;
                    int rightDown = (i < n - 1 && j < m - 1) ? dp[i + 1][j + 1] : 0;
                    
                    dp[i][j] = gold[i][j] + Math.max(right, Math.max(rightUp, rightDown));
                }
            }
            
            int maxGold = 0;
            for (int i = 0; i < n; i++) {
                maxGold = Math.max(maxGold, dp[i][0]);
            }
            
            return maxGold;
        }
    
        public static void main(String[] args) {
            int[][] goldMine = {
                {0, 1, 4, 2},
                {3, 0, 0, 4},
                {2, 2, 4, 0},
                {0, 0, 2, 1}
            };
            System.out.println(getMaxGold(goldMine)); // Output: 15
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n \* m), where n is the number of rows and m is the number of columns in the grid. Each cell is processed exactly once.
*   **Space Complexity:** O(n \* m) for the DP table.

### 2\. Optimized Space Complexity Approach

This approach optimizes space usage by using only a 1D array instead of a 2D DP table since the current state only depends on the previous column's state.

#### Pseudocode

    function getMaxGold(gold):
        n = number of rows in gold
        m = number of columns in gold
        create a dp array of size n
        
        for j from m-1 down to 0:
            for i from 0 to n-1:
                right = (j == m - 1) ? 0 : dp[i];
                rightUp = (i > 0) ? dp[i - 1] : 0;
                rightDown = (i < n - 1) ? dp[i + 1] : 0;
                
                dp[i] = gold[i][j] + max(right, rightUp, rightDown)
    
        maxGold = 0
        for i from 0 to n-1:
            maxGold = max(maxGold, dp[i])
        
        return maxGold
    

#### Java Implementation

    public class GoldMineProblem {
        public static int getMaxGold(int[][] gold) {
            int n = gold.length;
            int m = gold[0].length;
            int[] dp = new int[n];
            
            for (int j = m - 1; j >= 0; j--) {
                for (int i = 0; i < n; i++) {
                    int right = (j == m - 1) ? 0 : dp[i];
                    int rightUp = (i > 0) ? dp[i - 1] : 0;
                    int rightDown = (i < n - 1) ? dp[i + 1] : 0;
                    
                    dp[i] = gold[i][j] + Math.max(right, Math.max(rightUp, rightDown));
                }
            }
            
            int maxGold = 0;
            for (int i = 0; i < n; i++) {
                maxGold = Math.max(maxGold, dp[i]);
            }
            
            return maxGold;
        }
    
        public static void main(String[] args) {
            int[][] goldMine = {
                {0, 1, 4, 2},
                {3, 0, 0, 4},
                {2, 2, 4, 0},
                {0, 0, 2, 1}
            };
            System.out.println(getMaxGold(goldMine)); // Output: 15
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n \* m)
*   **Space Complexity:** O(n)

Conclusion
----------

The Gold Mine Problem showcases the effectiveness of dynamic programming in solving path-related optimization problems. By carefully managing the path taken through the grid, we can maximize the gold collected.