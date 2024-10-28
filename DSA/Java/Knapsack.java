public class Knapsack {

    // Method to solve the 0/1 Knapsack problem using dynamic programming
    public static int knapsack(int[] weights, int[] values, int capacity) {
        int n = weights.length;
        
        // Create a DP table where dp[i][j] represents the maximum value achievable with
        // the first i items and a knapsack capacity of j
        int[][] dp = new int[n + 1][capacity + 1];

        // Build table dp[][] in a bottom-up manner
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= capacity; w++) {
                // If including the current item is possible (weight <= current capacity)
                if (weights[i - 1] <= w) {
                    // Maximize by including or excluding the item
                    dp[i][w] = Math.max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
                } else {
                    // Exclude the item
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        
        // The maximum value achievable with n items and given capacity
        return dp[n][capacity];
    }

    public static void main(String[] args) {
        // Example values and weights arrays
        int[] values = { 60, 100, 120 };
        int[] weights = { 10, 20, 30 };
        int capacity = 50;

        int maxValue = knapsack(weights, values, capacity);
        System.out.println("Maximum value that can be achieved: " + maxValue);
    }
}
