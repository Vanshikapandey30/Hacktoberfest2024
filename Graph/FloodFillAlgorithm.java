import java.util.*; // Import required for array printing

public class FloodFillAlgorithm {

    public static int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int initColor = image[sr][sc];
        if (initColor != color) {  // Check if the starting pixel is already the target color
            int delRow[] = {-1, 0, +1, 0};
            int delCol[] = {0, +1, 0, -1};
            dfs(sr, sc, image, initColor, color, delRow, delCol);
        }
        return image;
    }

    // Depth-First Search (DFS) helper method
    public static void dfs(int row, int col, int[][] image, int initColor, int newColor, int delRow[], int delCol[]) {
        image[row][col] = newColor;
        int n = image.length;
        int m = image[0].length;

        // Explore all four directions: up, right, down, left
        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            // Check boundaries and if the new pixel has the initial color and has not been colored yet
            if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && image[newRow][newCol] == initColor) {
                dfs(newRow, newCol, image, initColor, newColor, delRow, delCol);
            }
        }
    }

    // Main method to test the flood fill algorithm
    public static void main(String[] args) {
        int image[][] = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
        int sr = 1, sc = 1, color = 2;

        // Perform flood fill
        int[][] result = floodFill(image, sr, sc, color);

        // Print the result
        for (int[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }
}
