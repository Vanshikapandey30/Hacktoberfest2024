import java.util.ArrayList;

public class MazePaths {
    // Directions: Down, Left, Right, Up
    static String direction = "DLRU";
    static int[] dr = { 1, 0, 0, -1 };
    static int[] dc = { 0, -1, 1, 0 };

    // Method to check if the move is within maze boundaries and valid
    static boolean isValid(int row, int col, int n, int[][] maze) {
        return row >= 0 && col >= 0 && row < n && col < n && maze[row][col] == 1;
    }

    // Recursive method to find paths in the maze
    static void findPath(int row, int col, int[][] maze, int n, ArrayList<String> ans, StringBuilder currentPath) {
        // If the destination is reached, add the current path to the answer list
        if (row == n - 1 && col == n - 1) {
            ans.add(currentPath.toString());
            return;
        }

        // Mark the current cell as visited
        maze[row][col] = 0;

        // Try moving in all four directions
        for (int i = 0; i < 4; i++) {
            int nextrow = row + dr[i];
            int nextcol = col + dc[i];

            // If the move is valid, proceed with recursion
            if (isValid(nextrow, nextcol, n, maze)) {
                currentPath.append(direction.charAt(i));
                findPath(nextrow, nextcol, maze, n, ans, currentPath);
                currentPath.deleteCharAt(currentPath.length() - 1); // Backtrack
            }
        }

        // Unmark the current cell (backtrack)
        maze[row][col] = 1;
    }

    public static void main(String[] args) {
        // Define the maze
        int[][] maze = { { 1, 0, 0, 0 }, { 1, 1, 0, 1 }, { 1, 1, 0, 0 }, { 0, 1, 1, 1 } };

        // Size of the maze
        int n = maze.length;

        // List to store all possible paths
        ArrayList<String> ans = new ArrayList<>();

        // Find paths from the top-left to the bottom-right corner
        findPath(0, 0, maze, n, ans, new StringBuilder());

        // Print all possible paths
        System.out.println(ans);
    }
}
