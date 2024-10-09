Coin Change Problem
===================

Problem Definition
------------------

The **Coin Change Problem** is a classic dynamic programming problem where the goal is to determine the minimum number of coins required to make a certain amount using a given set of coin denominations.

### Problem Statement

Given an integer array `coins[]` representing different denominations of coins and an integer `amount` representing a total amount of money, find the fewest number of coins that make up that amount. If the amount cannot be made up by any combination of the given coins, return `-1`.

### Example

For the array `{1, 2, 5}` and amount `11`, the fewest number of coins is `3` (5 + 5 + 1).

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach explores all possible combinations of coins to find the minimum number of coins required.

#### Pseudocode

    function coinChangeRecursive(coins, amount):
        if amount == 0:
            return 0
        if amount < 0:
            return infinity
        minCoins = infinity
        for each coin in coins:
            result = coinChangeRecursive(coins, amount - coin)
            if result != infinity:
                minCoins = min(minCoins, result + 1)
        return minCoins
    

#### Java Implementation

    public class CoinChange {
        public static int coinChangeRecursive(int[] coins, int amount) {
            if (amount == 0) {
                return 0;
            }
            if (amount < 0) {
                return Integer.MAX_VALUE;
            }
            int minCoins = Integer.MAX_VALUE;
            for (int coin : coins) {
                int result = coinChangeRecursive(coins, amount - coin);
                if (result != Integer.MAX_VALUE) {
                    minCoins = Math.min(minCoins, result + 1);
                }
            }
            return minCoins;
        }
    
        public static void main(String[] args) {
            int[] coins = {1, 2, 5};
            int amount = 11;
            int result = coinChangeRecursive(coins, amount);
            System.out.println(result == Integer.MAX_VALUE ? -1 : result);  // Output: 3
        }
    }
    

### 2\. Memoization Approach

The memoization approach stores the results of subproblems in a memoization table to avoid redundant calculations.

#### Pseudocode

    function coinChangeMemo(coins, amount, memo):
        if amount == 0:
            return 0
        if amount < 0:
            return infinity
        if memo[amount] != null:
            return memo[amount]
        minCoins = infinity
        for each coin in coins:
            result = coinChangeMemo(coins, amount - coin, memo)
            if result != infinity:
                minCoins = min(minCoins, result + 1)
        memo[amount] = minCoins
        return memo[amount]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class CoinChange {
        public static int coinChangeMemo(int[] coins, int amount, int[] memo) {
            if (amount == 0) {
                return 0;
            }
            if (amount < 0) {
                return Integer.MAX_VALUE;
            }
            if (memo[amount] != -1) {
                return memo[amount];
            }
            int minCoins = Integer.MAX_VALUE;
            for (int coin : coins) {
                int result = coinChangeMemo(coins, amount - coin, memo);
                if (result != Integer.MAX_VALUE) {
                    minCoins = Math.min(minCoins, result + 1);
                }
            }
            memo[amount] = minCoins;
            return minCoins;
        }
    
        public static void main(String[] args) {
            int[] coins = {1, 2, 5};
            int amount = 11;
            int[] memo = new int[amount + 1];
            Arrays.fill(memo, -1);
            int result = coinChangeMemo(coins, amount, memo);
            System.out.println(result == Integer.MAX_VALUE ? -1 : result);  // Output: 3
        }
    }
    

### 3\. Dynamic Programming (Tabulation) Approach

The dynamic programming approach builds a table that stores the minimum number of coins required to make up each amount from `0` to `amount`.

#### Pseudocode

    function coinChangeDP(coins, amount):
        dp = array of size amount + 1, initialized to infinity
        dp[0] = 0
        
        for each i from 1 to amount:
            for each coin in coins:
                if i - coin >= 0:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        
        return dp[amount] == infinity ? -1 : dp[amount]
    

#### Java Implementation

    import java.util.Arrays;
    
    public class CoinChange {
        public static int coinChangeDP(int[] coins, int amount) {
            int[] dp = new int[amount + 1];
            Arrays.fill(dp, amount + 1);  // Initialize with a large value
            dp[0] = 0;
    
            for (int i = 1; i <= amount; i++) {
                for (int coin : coins) {
                    if (i - coin >= 0) {
                        dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                    }
                }
            }
    
            return dp[amount] > amount ? -1 : dp[amount];
        }
    
        public static void main(String[] args) {
            int[] coins = {1, 2, 5};
            int amount = 11;
            System.out.println(coinChangeDP(coins, amount));  // Output: 3
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive:** O(2<sup>amount</sup>) time, O(amount) space (due to call stack)
*   **Memoization:** O(n \* amount) time, O(amount) space (for the memoization table)
*   **Dynamic Programming:** O(n \* amount) time, O(amount) space (for the DP table)