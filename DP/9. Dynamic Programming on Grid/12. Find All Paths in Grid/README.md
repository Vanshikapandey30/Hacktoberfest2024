Find All Paths in Grid
======================

Problem Definition
------------------

The problem involves finding all possible paths from the top-left corner (0, 0) to the bottom-right corner (m-1, n-1) of a grid, where you can only move down or right.

### Example

*   Input: m = 2, n = 2
    
        
                Output: [[0,0],[0,1],[1,1]]
                [[0,0],[1,0],[1,1]]
                
    
*   Input: m = 2, n = 3
    
        
                Output: [[0,0],[0,1],[0,2],[1,2]]
                [[0,0],[0,1],[1,1],[1,2]]
                [[0,0],[1,0],[1,1],[1,2]]
                [[0,0],[1,0],[1,1],[0,2]]
                [[0,0],[1,0],[0,1],[1,1],[1,2]]
                [[0,0],[0,1],[1,1],[1,2]]
                
    

Solution Approaches
-------------------

### 1\. Backtracking Approach

This approach uses recursion to explore all paths from the current cell to the target cell. The algorithm explores moving right and down from the current position, adding valid paths to the result.

#### Pseudocode

    function findAllPaths(m, n):
        paths = []
        path = []
        dfs(0, 0, m, n, path, paths)
        return paths
    
    function dfs(x, y, m, n, path, paths):
        if x == m - 1 and y == n - 1:
            paths.add(path.copy())
            return
    
        if x < m:
            path.add((x + 1, y))
            dfs(x + 1, y, m, n, path, paths)
            path.removeLast()
    
        if y < n:
            path.add((x, y + 1))
            dfs(x, y + 1, m, n, path, paths)
            path.removeLast()
    

#### Java Implementation

    import java.util.ArrayList;
    import java.util.List;
    
    public class FindAllPathsInGrid {
        public static List> findAllPaths(int m, int n) {
            List> paths = new ArrayList<>();
            List path = new ArrayList<>();
            dfs(0, 0, m, n, path, paths);
            return paths;
        }
    
        private static void dfs(int x, int y, int m, int n, List path, List> paths) {
            path.add(new int[] {x, y});
    
            if (x == m - 1 && y == n - 1) {
                paths.add(new ArrayList<>(path));
            } else {
                if (x + 1 < m) {
                    dfs(x + 1, y, m, n, path, paths);
                }
                if (y + 1 < n) {
                    dfs(x, y + 1, m, n, path, paths);
                }
            }
    
            path.remove(path.size() - 1);
        }
    
        public static void main(String[] args) {
            List> paths = findAllPaths(2, 3);
            for (List path : paths) {
                for (int[] step : path) {
                    System.out.print("[" + step[0] + "," + step[1] + "] ");
                }
                System.out.println();
            }
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2^(m+n)) due to the exploration of all paths.
*   **Space Complexity:** O(m + n) for the recursion stack and the path storage.

### 2\. Dynamic Programming Approach

This approach uses a 2D table to store the number of ways to reach each cell. However, this doesn't explicitly store the paths but only counts them. For full paths, a backtrack is still required.

#### Pseudocode

    function countPaths(m, n):
        dp = 2D array of size m x n
        for i from 0 to m:
            for j from 0 to n:
                if i == 0 or j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
    
        return dp[m-1][n-1]
    

#### Java Implementation

    public class CountPathsInGrid {
        public static int countPaths(int m, int n) {
            int[][] dp = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
            }
            return dp[m - 1][n - 1];
        }
    
        public static void main(String[] args) {
            System.out.println(countPaths(2, 3)); // Output: 3
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(N \* M) where N is the number of rows and M is the number of columns in the grid.
*   **Space Complexity:** O(N \* M) for the DP table.

Conclusion
----------

The Find All Paths in Grid problem can be effectively solved using either a backtracking approach or a dynamic programming approach. The choice of method depends on whether you need the actual paths or just the count of paths.