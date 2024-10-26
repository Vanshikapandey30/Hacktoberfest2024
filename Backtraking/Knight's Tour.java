public class KnightTour {
    private static final int N = 8; // Standard 8x8 chess board
    private static final int[] xMove = {2, 1, -1, -2, -2, -1, 1, 2};
    private static final int[] yMove = {1, 2, 2, 1, -1, -2, -2, -1};
    
    private int[][] board;
    
    public KnightTour() {
        board = new int[N][N];
        // Initialize board with -1
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = -1;
            }
        }
    }
    
    public boolean solveKnightTour() {
        // Start from (0,0)
        board[0][0] = 0;
        return solveKnightTourUtil(0, 0, 1);
    }
    
    private boolean solveKnightTourUtil(int x, int y, int moveCount) {
        // Base case: if all squares are visited
        if (moveCount == N * N) {
            return true;
        }
        
        // Try all possible moves from current position
        for (int i = 0; i < 8; i++) {
            int nextX = x + xMove[i];
            int nextY = y + yMove[i];
            
            if (isValidMove(nextX, nextY)) {
                board[nextX][nextY] = moveCount;
                
                if (solveKnightTourUtil(nextX, nextY, moveCount + 1)) {
                    return true;
                }
                
                // Backtrack if the move doesn't lead to a solution
                board[nextX][nextY] = -1;
            }
        }
        return false;
    }
    
    private boolean isValidMove(int x, int y) {
        return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
    }
    
    public void printSolution() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.printf("%3d ", board[i][j]);
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        KnightTour kt = new KnightTour();
        
        if (kt.solveKnightTour()) {
            System.out.println("Solution exists:");
            kt.printSolution();
        } else {
            System.out.println("No solution exists");
        }
    }
}
