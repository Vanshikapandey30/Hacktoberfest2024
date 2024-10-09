Target Sum Problem
==================

Problem Definition
------------------

The **Target Sum Problem** involves finding the number of ways to assign symbols to make the sum of numbers equal to a target value.

### Problem Statement

Given a list of integers and a target integer `target`, you need to find the total number of ways to assign a '+' or '-' sign to each integer in the list such that the resulting sum equals `target`.

### Example

For the list `{1, 1, 1, 1, 1}` and `target = 3`, one way to achieve this is by assigning signs as follows: `+1 +1 +1 -1 -1`. Hence, the output is **5**.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach tries all combinations of '+' and '-' for each number in the list.

#### Pseudocode

    function countTargetSumWays(nums, n, target):
        if n == 0:
            return 1 if target == 0 else 0
        return countTargetSumWays(nums, n-1, target + nums[n-1]) + 
               countTargetSumWays(nums, n-1, target - nums[n-1])
    

#### Java Implementation

    public class TargetSum {
        public static int countTargetSumWays(int[] nums, int n, int target) {
            if (n == 0) {
                return (target == 0) ? 1 : 0;
            }
            return countTargetSumWays(nums, n - 1, target + nums[n - 1]) + 
                   countTargetSumWays(nums, n - 1, target - nums[n - 1]);
        }
    
        public static void main(String[] args) {
            int[] nums = {1, 1, 1, 1, 1};
            int target = 3;
            System.out.println(countTargetSumWays(nums, nums.length, target));  // Output: 5
        }
    }
    

### 2\. Memoization Approach

The memoization approach stores results of subproblems to avoid redundant calculations.

#### Pseudocode

    function countTargetSumWaysMemo(nums, n, target, memo):
        if n == 0:
            return 1 if target == 0 else 0
        if (n, target) in memo:
            return memo[(n, target)]
        memo[(n, target)] = countTargetSumWaysMemo(nums, n-1, target + nums[n-1], memo) + 
                            countTargetSumWaysMemo(nums, n-1, target - nums[n-1], memo)
        return memo[(n, target)]
    

#### Java Implementation

    import java.util.HashMap;
    import java.util.Map;
    
    public class TargetSum {
        public static int countTargetSumWaysMemo(int[] nums, int n, int target, Map memo) {
            if (n == 0) {
                return (target == 0) ? 1 : 0;
            }
            String key = n + "," + target;
            if (memo.containsKey(key)) {
                return memo.get(key);
            }
            memo.put(key, countTargetSumWaysMemo(nums, n - 1, target + nums[n - 1], memo) + 
                       countTargetSumWaysMemo(nums, n - 1, target - nums[n - 1], memo));
            return memo.get(key);
        }
    
        public static void main(String[] args) {
            int[] nums = {1, 1, 1, 1, 1};
            int target = 3;
            Map memo = new HashMap<>();
            System.out.println(countTargetSumWaysMemo(nums, nums.length, target, memo));  // Output: 5
        }
    }
    

### 3\. Dynamic Programming Approach

The dynamic programming approach builds a table to store results of subproblems, iterating through the numbers and target sums.

#### Pseudocode

    function countTargetSumWaysDP(nums, target):
        totalSum = sum(nums)
        if (target + totalSum) % 2 != 0 or target > totalSum:
            return 0
        sumSubset = (target + totalSum) / 2
        create a dp array of size (sumSubset + 1)
        
        dp[0] = 1
        for num in nums:
            for j from sumSubset to num:
                dp[j] += dp[j - num]
        
        return dp[sumSubset]
    

#### Java Implementation

    public class TargetSum {
        public static int countTargetSumWaysDP(int[] nums, int target) {
            int totalSum = 0;
            for (int num : nums) {
                totalSum += num;
            }
            if ((target + totalSum) % 2 != 0 || target > totalSum) {
                return 0;
            }
            int sumSubset = (target + totalSum) / 2;
            int[] dp = new int[sumSubset + 1];
            dp[0] = 1;
            
            for (int num : nums) {
                for (int j = sumSubset; j >= num; j--) {
                    dp[j] += dp[j - num];
                }
            }
            
            return dp[sumSubset];
        }
    
        public static void main(String[] args) {
            int[] nums = {1, 1, 1, 1, 1};
            int target = 3;
            System.out.println(countTargetSumWaysDP(nums, target));  // Output: 5
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive:** O(2<sup>n</sup>) time, O(n) space (due to call stack)
*   **Memoization:** O(n \* target) time, O(n \* target) space (for the memoization map)
*   **Dynamic Programming:** O(n \* sum) time, O(sum) space (for the DP array)