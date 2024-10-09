Knight Probability in Chessboard
================================

Problem Definition
------------------

The Knight Probability problem involves calculating the probability that a knight remains on an N x N chessboard after making K moves. The knight moves in an "L" shape: two squares in one direction and then one square perpendicular, or one square in one direction and then two squares perpendicular.

### Example

*   Input: N = 3, K = 2, r = 0, c = 0
    
        
                Output: 0.33333
                
    
*   Explanation: The knight starts at position (0,0). After 2 moves, it can be at positions (1,2), (2,1), and (2,0) which are valid positions on the board.

Solution Approaches
-------------------

### 1\. Recursive Approach with Memoization

This approach uses recursion to explore all possible moves the knight can make from its current position. We store results in a memoization table to avoid recalculating probabilities for the same position and remaining moves.

#### Pseudocode

    function knightProbability(N, K, r, c):
        if r < 0 or r >= N or c < 0 or c >= N:
            return 0
        if K == 0:
            return 1
        
        if (r, c, K) in memo:
            return memo[(r, c, K)]
        
        totalProbability = 0
        for each move in knightMoves:
            totalProbability += knightProbability(N, K - 1, r + move[0], c + move[1])
        
        memo[(r, c, K)] = totalProbability / 8
        return memo[(r, c, K)]
    

#### Java Implementation

    import java.util.HashMap;
    import java.util.Map;
    
    public class KnightProbability {
        private static final int[][] knightMoves = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };
        private static Map memo = new HashMap<>();
    
        public static double knightProbability(int N, int K, int r, int c) {
            if (r < 0 || r >= N || c < 0 || c >= N) {
                return 0;
            }
            if (K == 0) {
                return 1;
            }
    
            String key = r + "," + c + "," + K;
            if (memo.containsKey(key)) {
                return memo.get(key);
            }
    
            double totalProbability = 0;
            for (int[] move : knightMoves) {
                totalProbability += knightProbability(N, K - 1, r + move[0], c + move[1]);
            }
    
            totalProbability /= 8;
            memo.put(key, totalProbability);
            return totalProbability;
        }
    
        public static void main(String[] args) {
            int N = 3, K = 2, r = 0, c = 0;
            System.out.println(knightProbability(N, K, r, c)); // Output: 0.33333
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(K \* N^2) where K is the number of moves and N^2 represents the number of possible positions on the chessboard.
*   **Space Complexity:** O(K \* N^2) for the memoization storage.

### 2\. Dynamic Programming Approach

This approach uses a DP table to iteratively calculate the probability of the knight remaining on the board for each possible position after each move.

#### Pseudocode

    function knightProbability(N, K, r, c):
        dp = 2D array of size N x N filled with 0
        dp[r][c] = 1
        
        for k from 1 to K:
            newDp = 2D array of size N x N filled with 0
            for i from 0 to N-1:
                for j from 0 to N-1:
                    if dp[i][j] > 0:
                        for each move in knightMoves:
                            newRow = i + move[0]
                            newCol = j + move[1]
                            if newRow >= 0 and newRow < N and newCol >= 0 and newCol < N:
                                newDp[newRow][newCol] += dp[i][j] / 8
            dp = newDp
        
        totalProbability = 0
        for i from 0 to N-1:
            for j from 0 to N-1:
                totalProbability += dp[i][j]
        
        return totalProbability
    

#### Java Implementation

    public class KnightProbability {
        private static final int[][] knightMoves = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };
    
        public static double knightProbability(int N, int K, int r, int c) {
            double[][] dp = new double[N][N];
            dp[r][c] = 1;
    
            for (int k = 1; k <= K; k++) {
                double[][] newDp = new double[N][N];
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (dp[i][j] > 0) {
                            for (int[] move : knightMoves) {
                                int newRow = i + move[0];
                                int newCol = j + move[1];
                                if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < N) {
                                    newDp[newRow][newCol] += dp[i][j] / 8;
                                }
                            }
                        }
                    }
                }
                dp = newDp;
            }
    
            double totalProbability = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    totalProbability += dp[i][j];
                }
            }
    
            return totalProbability;
        }
    
        public static void main(String[] args) {
            int N = 3, K = 2, r = 0, c = 0;
            System.out.println(knightProbability(N, K, r, c)); // Output: 0.33333
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(K \* N^2), similar to the recursive approach.
*   **Space Complexity:** O(N^2) for the DP table.

Conclusion
----------

The Knight Probability in Chessboard problem illustrates how recursive and iterative dynamic programming approaches can effectively solve path-related probability problems in a grid structure.