Cherry Pickup Problem
=====================

Problem Definition
------------------

The Cherry Pickup problem involves two robots starting from the top-left and bottom-left corners of a grid filled with cherries. The robots can only move to the right or down. The objective is to find the maximum number of cherries that can be collected by both robots before they meet at the same cell or finish their paths.

### Example

*   Input: Grid =
    
        
                [
                  [0, 1, -1],
                  [1, 0, 0],
                  [0, 0, 1]
                ]
                
    
*   Output: Maximum Cherries = 5
    
        
                Robot 1 path: (0,0) -> (1,0) -> (2,0) -> (2,1) -> (2,2) = 1 + 1 + 1 + 0 + 1 = 4
                Robot 2 path: (2,0) -> (1,0) -> (0,0) -> (0,1) = 0 + 1 + 1 + 1 = 4
                Total cherries collected = 4 + 1 = 5
                
    

Solution Approaches
-------------------

### 1\. Dynamic Programming Approach

This approach utilizes a 3D DP table where dp\[x1\]\[y1\]\[y2\] represents the maximum cherries collected when Robot 1 is at (x1, y1) and Robot 2 is at (x2, y2). The state transitions are determined based on the movement of the robots.

#### Pseudocode

    function cherryPickup(grid):
        n = number of rows in grid
        m = number of columns in grid
        create a 3D dp array of size n x m x m initialized to -1
        dp[0][0][0] = grid[0][0] (initial cherry count)
        
        for x1 from 0 to n-1:
            for y1 from 0 to m-1:
                for y2 from 0 to m-1:
                    x2 = x1 + y1 - y2
                    if (y1 < m) and (y2 < m) and (x2 >= 0) and (x2 < n):
                        cherries = grid[x1][y1] + (y1 != y2 ? grid[x2][y2] : 0)
                        dp[x1][y1][y2] = max(dp[x1][y1][y2], cherries + max(dp[x1-1][y1][y2], dp[x1][y1-1][y2], dp[x1][y1][y2-1], dp[x1-1][y1-1][y2], dp[x1][y1-1][y2-1]))
        
        return max(dp[n-1][m-1][y2]) for y2 from 0 to m-1
    

#### Java Implementation

    public class CherryPickup {
        public static int cherryPickup(int[][] grid) {
            int n = grid.length;
            int m = grid[0].length;
            int[][][] dp = new int[n][m][m];
            
            for (int[][] layer : dp) {
                for (int[] row : layer) {
                    Arrays.fill(row, -1);
                }
            }
            
            dp[0][0][0] = grid[0][0];
            
            for (int x1 = 0; x1 < n; x1++) {
                for (int y1 = 0; y1 < m; y1++) {
                    for (int y2 = 0; y2 < m; y2++) {
                        int x2 = x1 + y1 - y2;
                        if (y1 < m && y2 < m && x2 >= 0 && x2 < n && dp[x1][y1][y2] != -1) {
                            int cherries = grid[x1][y1];
                            if (y1 != y2) cherries += grid[x2][y2];
                            
                            int maxCherries = Math.max(dp[x1][y1][y2], cherries);
                            dp[x1][y1][y2] = Math.max(maxCherries, Math.max(
                                x1 > 0 ? dp[x1 - 1][y1][y2] : -1,
                                Math.max(
                                    y1 > 0 ? dp[x1][y1 - 1][y2] : -1,
                                    Math.max(
                                        y2 > 0 ? dp[x1][y1][y2 - 1] : -1,
                                        (x1 > 0 && y1 > 0) ? dp[x1 - 1][y1 - 1][y2] : -1
                                    )
                                )
                            ));
                        }
                    }
                }
            }
            
            int maxCherries = 0;
            for (int y2 = 0; y2 < m; y2++) {
                maxCherries = Math.max(maxCherries, dp[n - 1][m - 1][y2]);
            }
            return maxCherries;
        }
    
        public static void main(String[] args) {
            int[][] grid = {
                {0, 1, -1},
                {1, 0, 0},
                {0, 0, 1}
            };
            System.out.println(cherryPickup(grid)); // Output: 5
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n \* m \* m), where n is the number of rows and m is the number of columns. Each cell is processed in a nested loop.
*   **Space Complexity:** O(n \* m \* m) for the DP table.

### 2\. Optimized Dynamic Programming Approach

This approach optimizes space usage by collapsing the 3D DP table into a 2D DP table since the current state only depends on the previous row.

#### Pseudocode

    function cherryPickup(grid):
        n = number of rows in grid
        m = number of columns in grid
        create a 2D dp array of size m x m initialized to -1
        dp[0][0] = grid[0][0]
        
        for x1 from 0 to n-1:
            for y1 from 0 to m-1:
                for y2 from 0 to m-1:
                    x2 = x1 + y1 - y2
                    if (y1 < m) and (y2 < m) and (x2 >= 0) and (x2 < n):
                        cherries = grid[x1][y1] + (y1 != y2 ? grid[x2][y2] : 0)
                        dp[y1][y2] = max(dp[y1][y2], cherries + max(dp[y1-1][y2], dp[y1][y2-1], dp[y1-1][y2-1]))
        
        return max(dp[m-1][y2]) for y2 from 0 to m-1
    

#### Java Implementation

    public class CherryPickup {
        public static int cherryPickup(int[][] grid) {
            int n = grid.length;
            int m = grid[0].length;
            int[][] dp = new int[m][m];
            
            for (int[] row : dp) {
                Arrays.fill(row, -1);
            }
            
            dp[0][0] = grid[0][0];
            
            for (int x1 = 0; x1 < n; x1++) {
                for (int y1 = 0; y1 < m; y1++) {
                    for (int y2 = 0; y2 < m; y2++) {
                        int x2 = x1 + y1 - y2;
                        if (y1 < m && y2 < m && x2 >= 0 && x2 < n && dp[y1][y2] != -1) {
                            int cherries = grid[x1][y1];
                            if (y1 != y2) cherries += grid[x2][y2];
                            
                            dp[y1][y2] = Math.max(dp[y1][y2], cherries + Math.max(
                                (y1 > 0) ? dp[y1 - 1][y2] : -1,
                                Math.max(
                                    (y2 > 0) ? dp[y1][y2 - 1] : -1,
                                    (y1 > 0 && y2 > 0) ? dp[y1 - 1][y2 - 1] : -1
                                )
                            ));
                        }
                    }
                }
            }
            
            int maxCherries = 0;
            for (int y2 = 0; y2 < m; y2++) {
                maxCherries = Math.max(maxCherries, dp[m - 1][y2]);
            }
            return maxCherries;
        }
    
        public static void main(String[] args) {
            int[][] grid = {
                {0, 1, -1},
                {1, 0, 0},
                {0, 0, 1}
            };
            System.out.println(cherryPickup(grid)); // Output: 5
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(n \* m \* m)
*   **Space Complexity:** O(m \* m)

Conclusion
----------

The Cherry Pickup problem illustrates the power of dynamic programming in solving complex pathfinding problems efficiently. The challenge lies in optimizing the state transitions and ensuring that the robots do not collect the same cherries. With proper optimization techniques, the solution can be implemented in a manner that is both space and time efficient.