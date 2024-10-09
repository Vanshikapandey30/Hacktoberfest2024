Rat in a Maze
=============

Problem Statement
-----------------

The Rat in a Maze problem involves finding a path for a rat to move from the top-left corner of a maze (0, 0) to the bottom-right corner (N-1, N-1). The maze consists of cells that are either open (1) or blocked (0). The rat can only move right, down, up, or left.

Backtracking Approach
---------------------

The backtracking approach explores all possible paths for the rat until it finds a solution or exhausts all options. The algorithm follows these steps:

1.  Check if the current cell is the destination. If yes, mark it as part of the solution path and return true.
2.  If the current cell is not valid (either blocked or out of bounds), return false.
3.  Mark the current cell as part of the solution path.
4.  Recursively explore the adjacent cells (right, down, left, up).
5.  If a recursive call returns true, return true.
6.  If no adjacent cell leads to a solution, backtrack (unmark the current cell).

### Example

Consider the following maze:

    1 0 0 0
    1 1 0 1
    0 1 0 0
    0 1 1 1

The solution path for the rat would be:

    1 0 0 0
    1 1 0 0
    0 1 0 0
    0 0 1 1

Java Implementation
-------------------

    import java.util.ArrayList;
    import java.util.List;
    
    public class RatInMaze {
        public static void main(String[] args) {
            int[][] maze = {
                {1, 0, 0, 0},
                {1, 1, 0, 1},
                {0, 1, 0, 0},
                {0, 1, 1, 1}
            };
            
            List paths = new ArrayList<>();
            if (solveMaze(maze, paths)) {
                System.out.println("Paths to reach the destination:");
                for (String path : paths) {
                    System.out.println(path);
                }
            } else {
                System.out.println("No path exists");
            }
        }
    
        public static boolean solveMaze(int[][] maze, List paths) {
            int n = maze.length;
            boolean[][] visited = new boolean[n][n];
            StringBuilder path = new StringBuilder();
            if (findPath(maze, 0, 0, visited, path, paths)) {
                return true;
            }
            return false;
        }
    
        private static boolean findPath(int[][] maze, int row, int col, boolean[][] visited, StringBuilder path, List paths) {
            int n = maze.length;
            if (row == n - 1 && col == n - 1) {
                paths.add(path.toString());
                return true;
            }
    
            if (isSafe(maze, row, col, visited)) {
                visited[row][col] = true;
    
                // Move Down
                path.append("D");
                if (findPath(maze, row + 1, col, visited, path, paths)) {
                    return true;
                }
                path.deleteCharAt(path.length() - 1);
    
                // Move Right
                path.append("R");
                if (findPath(maze, row, col + 1, visited, path, paths)) {
                    return true;
                }
                path.deleteCharAt(path.length() - 1);
    
                // Move Up
                path.append("U");
                if (findPath(maze, row - 1, col, visited, path, paths)) {
                    return true;
                }
                path.deleteCharAt(path.length() - 1);
    
                // Move Left
                path.append("L");
                if (findPath(maze, row, col - 1, visited, path, paths)) {
                    return true;
                }
                path.deleteCharAt(path.length() - 1);
    
                visited[row][col] = false; // backtrack
            }
            return false;
        }
    
        private static boolean isSafe(int[][] maze, int row, int col, boolean[][] visited) {
            int n = maze.length;
            return (row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == 1 && !visited[row][col]);
        }
    }
    

Time and Space Complexity
-------------------------

*   **Time Complexity:** O(4^(N\*N)), where N is the size of the maze. This is because the algorithm explores all four possible directions for each cell.
*   **Space Complexity:** O(N\*N) due to the recursion stack and the visited array.

Conclusion
----------

The Rat in a Maze problem is a classic example of using backtracking to explore all possible paths in a grid. This problem can be adapted to various scenarios involving pathfinding in different types of grids.