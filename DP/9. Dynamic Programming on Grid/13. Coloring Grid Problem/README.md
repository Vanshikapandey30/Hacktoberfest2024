Coloring Grid Problem
=====================

Problem Definition
------------------

The problem involves coloring a grid of size `m x n` such that no two adjacent cells have the same color. Given a number of colors `k`, determine if it's possible to color the grid without violating the coloring constraint.

### Example

*   Input: m = 3, n = 3, k = 2
    
        
                Output: True
                
    
*   Input: m = 2, n = 2, k = 1
    
        
                Output: False
                
    

Solution Approaches
-------------------

### 1\. Backtracking Approach

This approach uses recursion to try coloring the grid cell by cell. It checks adjacent cells to ensure that no two adjacent cells share the same color.

#### Pseudocode

    function canColorGrid(m, n, k):
        grid = 2D array of size m x n filled with -1
        return dfs(0, 0, grid, k)
    
    function dfs(x, y, grid, k):
        if x == m:
            return True
        if y == n:
            return dfs(x + 1, 0, grid, k)
        
        for color from 0 to k - 1:
            if isValid(x, y, color, grid):
                grid[x][y] = color
                if dfs(x, y + 1, grid, k):
                    return True
                grid[x][y] = -1
    
        return False
    
    function isValid(x, y, color, grid):
        if x > 0 and grid[x - 1][y] == color:
            return False
        if y > 0 and grid[x][y - 1] == color:
            return False
        return True
    

#### Java Implementation

    public class ColoringGrid {
        public static boolean canColorGrid(int m, int n, int k) {
            int[][] grid = new int[m][n];
            for (int[] row : grid) {
                Arrays.fill(row, -1);
            }
            return dfs(0, 0, grid, k);
        }
    
        private static boolean dfs(int x, int y, int[][] grid, int k) {
            if (x == grid.length) {
                return true;
            }
            if (y == grid[0].length) {
                return dfs(x + 1, 0, grid, k);
            }
            
            for (int color = 0; color < k; color++) {
                if (isValid(x, y, color, grid)) {
                    grid[x][y] = color;
                    if (dfs(x, y + 1, grid, k)) {
                        return true;
                    }
                    grid[x][y] = -1; // backtrack
                }
            }
            return false;
        }
    
        private static boolean isValid(int x, int y, int color, int[][] grid) {
            if (x > 0 && grid[x - 1][y] == color) {
                return false;
            }
            if (y > 0 && grid[x][y - 1] == color) {
                return false;
            }
            return true;
        }
    
        public static void main(String[] args) {
            System.out.println(canColorGrid(3, 3, 2)); // Output: true
            System.out.println(canColorGrid(2, 2, 1)); // Output: false
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(k^(m \* n)) where k is the number of colors and m \* n is the total number of cells in the grid.
*   **Space Complexity:** O(m \* n) for the recursion stack.

### 2\. Greedy Approach

This approach tries to color the grid in a straightforward manner by checking adjacent cells and applying the least number of colors possible. However, it may not always work for all configurations.

#### Pseudocode

    function canColorGridGreedy(m, n, k):
        grid = 2D array of size m x n filled with -1
        for x from 0 to m:
            for y from 0 to n:
                if grid[x][y] == -1:
                    color = 0
                    while !isValid(x, y, color, grid):
                        color++
                    grid[x][y] = color
        return true
    

#### Java Implementation

    public class ColoringGridGreedy {
        public static boolean canColorGridGreedy(int m, int n, int k) {
            int[][] grid = new int[m][n];
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    if (grid[x][y] == -1) {
                        int color = 0;
                        while (!isValid(x, y, color, grid) && color < k) {
                            color++;
                        }
                        if (color >= k) {
                            return false; // Not enough colors
                        }
                        grid[x][y] = color;
                    }
                }
            }
            return true;
        }
    
        private static boolean isValid(int x, int y, int color, int[][] grid) {
            if (x > 0 && grid[x - 1][y] == color) {
                return false;
            }
            if (y > 0 && grid[x][y - 1] == color) {
                return false;
            }
            return true;
        }
    
        public static void main(String[] args) {
            System.out.println(canColorGridGreedy(3, 3, 2)); // Output: true
            System.out.println(canColorGridGreedy(2, 2, 1)); // Output: false
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(m \* n \* k) where m \* n is the total number of cells in the grid and k is the number of colors.
*   **Space Complexity:** O(m \* n) for the grid storage.

Conclusion
----------

The Coloring Grid Problem can be effectively solved using backtracking or a greedy approach, depending on the requirements for color distribution and the grid size.