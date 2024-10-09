Dungeon Game
============

Problem Definition
------------------

The Dungeon Game involves a knight navigating through a dungeon represented as a 2D grid. Each cell in the grid contains either a positive or negative value representing health points. The knight must start from the top-left corner and reach the bottom-right corner while ensuring that he has a positive amount of health at every cell he visits. The goal is to determine the minimum initial health the knight needs to start with to successfully navigate the dungeon.

### Example

*   Input: Dungeon =
    
        
                [
                  [-2, -3, 3],
                  [-5, -10, 1],
                  [10, 30, -5]
                ]
                
    
*   Output: Minimum initial health = 7
    
        
                Explanation:
                Start with 7 health points. The knight will end up with 5 health points after reaching the bottom-right corner.
                
    

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach

This approach uses dynamic programming to compute the minimum health required at each cell starting from the bottom-right corner of the dungeon and moving to the top-left. The knight's health is updated based on the value of the current cell and the minimum required health from the neighboring cells (right and down).

#### Pseudocode

    function calculateMinimumHP(dungeon):
        n = number of rows in dungeon
        m = number of columns in dungeon
        create a dp array of size n x m
        
        dp[n-1][m-1] = max(1, 1 - dungeon[n-1][m-1]) (health needed at the destination)
        
        for i from n-1 down to 0:
            for j from m-1 down to 0:
                if i < n - 1:
                    dp[i][j] = min(dp[i][j], max(1, dp[i+1][j] - dungeon[i][j]))
                if j < m - 1:
                    dp[i][j] = min(dp[i][j], max(1, dp[i][j+1] - dungeon[i][j]))
    
        return dp[0][0]
    

#### Java Implementation

    public class DungeonGame {
        public static int calculateMinimumHP(int[][] dungeon) {
            int n = dungeon.length;
            int m = dungeon[0].length;
            int[][] dp = new int[n][m];
            
            dp[n - 1][m - 1] = Math.max(1, 1 - dungeon[n - 1][m - 1]);
            
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (i < n - 1) {
                        dp[i][j] = Math.min(dp[i][j], Math.max(1, dp[i + 1][j] - dungeon[i][j]));
                    } else {
                        dp[i][j] = Math.max(1, 1 - dungeon[i][j]);
                    }
                    
                    if (j < m - 1) {
                        dp[i][j] = Math.min(dp[i][j], Math.max(1, dp[i][j + 1] - dungeon[i][j]));
                    }
                }
            }
            
            return dp[0][0];
        }
    
        public static void main(String[] args) {
            int[][] dungeon = {
                {-2, -3, 3},
                {-5, -10, 1},
                {10, 30, -5}
            };
            System.out.println(calculateMinimumHP(dungeon)); // Output: 7
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n \* m), where n is the number of rows and m is the number of columns in the dungeon. Each cell is processed exactly once.
*   **Space Complexity:** O(n \* m) for the DP table.

### 2\. Optimized Space Complexity Approach

This approach optimizes space usage by using only a 1D array instead of a 2D DP table since the current state only depends on the previous row.

#### Pseudocode

    function calculateMinimumHP(dungeon):
        n = number of rows in dungeon
        m = number of columns in dungeon
        create a dp array of size m
        
        dp[m-1] = max(1, 1 - dungeon[n-1][m-1]) (health needed at the destination)
        
        for i from n-1 down to 0:
            for j from m-1 down to 0:
                if j < m - 1:
                    dp[j] = min(dp[j], max(1, dp[j+1] - dungeon[i][j]))
                else:
                    dp[j] = max(1, 1 - dungeon[i][j])
            
            if i < n - 1:
                dp[m - 1] = max(1, dp[m - 1] - dungeon[i][m - 1])
    
        return dp[0]
    

#### Java Implementation

    public class DungeonGame {
        public static int calculateMinimumHP(int[][] dungeon) {
            int n = dungeon.length;
            int m = dungeon[0].length;
            int[] dp = new int[m];
            
            dp[m - 1] = Math.max(1, 1 - dungeon[n - 1][m - 1]);
            
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (j < m - 1) {
                        dp[j] = Math.min(dp[j], Math.max(1, dp[j + 1] - dungeon[i][j]));
                    } else {
                        dp[j] = Math.max(1, 1 - dungeon[i][j]);
                    }
                }
                if (i < n - 1) {
                    dp[m - 1] = Math.max(1, dp[m - 1] - dungeon[i][m - 1]);
                }
            }
            
            return dp[0];
        }
    
        public static void main(String[] args) {
            int[][] dungeon = {
                {-2, -3, 3},
                {-5, -10, 1},
                {10, 30, -5}
            };
            System.out.println(calculateMinimumHP(dungeon)); // Output: 7
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n \* m)
*   **Space Complexity:** O(m)

Conclusion
----------

The Dungeon Game demonstrates how dynamic programming can effectively tackle pathfinding problems with constraints. By carefully managing the knight's health, we can derive the minimum starting health required to navigate the dungeon safely.