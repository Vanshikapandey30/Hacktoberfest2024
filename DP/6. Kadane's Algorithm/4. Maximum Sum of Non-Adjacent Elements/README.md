Maximum Sum of Non-Adjacent Elements
====================================

Problem Definition
------------------

The **Maximum Sum of Non-Adjacent Elements** problem involves finding the maximum sum of elements in an array such that no two selected elements are adjacent. This problem can be solved using various approaches.

### Example

*   Input: `[3, 2, 7, 10]`
*   Output: `13` (The maximum sum is from selecting `3` and `10`)

Solution Approaches
-------------------

### 1\. Dynamic Programming (O(n))

This approach uses a dynamic programming array to store the maximum sum at each index, deciding whether to include or exclude the current element.

#### Pseudocode

    function maxNonAdjacentSum(arr):
            if length(arr) == 0:
                return 0
            if length(arr) == 1:
                return arr[0]
            dp = array of size length(arr)
            dp[0] = arr[0]
            dp[1] = max(arr[0], arr[1])
            for i from 2 to length(arr) - 1:
                dp[i] = max(dp[i-1], dp[i-2] + arr[i])
            return dp[length(arr) - 1]
        

#### Java Implementation

    public class MaxSumNonAdjacent {
            public static int maxNonAdjacentSum(int[] nums) {
                if (nums.length == 0) return 0;
                if (nums.length == 1) return nums[0];
                
                int[] dp = new int[nums.length];
                dp[0] = nums[0];
                dp[1] = Math.max(nums[0], nums[1]);
                
                for (int i = 2; i < nums.length; i++) {
                    dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i]);
                }
                
                return dp[nums.length - 1];
            }
        }
        

### Time and Space Complexity (Dynamic Programming)

*   **Time Complexity:** O(n) - A single pass through the array.
*   **Space Complexity:** O(n) - An additional array is used to store results.

### 2\. Optimized Dynamic Programming (O(n))

This approach reduces space complexity by using only two variables to keep track of the previous two results instead of using an array.

#### Pseudocode

    function maxNonAdjacentSumOptimized(arr):
            if length(arr) == 0:
                return 0
            if length(arr) == 1:
                return arr[0]
            prev1 = arr[0]
            prev2 = max(arr[0], arr[1])
            for i from 2 to length(arr) - 1:
                current = max(prev2, prev1 + arr[i])
                prev1 = prev2
                prev2 = current
            return prev2
        

#### Java Implementation

    public class MaxSumNonAdjacentOptimized {
            public static int maxNonAdjacentSumOptimized(int[] nums) {
                if (nums.length == 0) return 0;
                if (nums.length == 1) return nums[0];
                
                int prev1 = nums[0];
                int prev2 = Math.max(nums[0], nums[1]);
                
                for (int i = 2; i < nums.length; i++) {
                    int current = Math.max(prev2, prev1 + nums[i]);
                    prev1 = prev2;
                    prev2 = current;
                }
                
                return prev2;
            }
        }
        

### Time and Space Complexity (Optimized Dynamic Programming)

*   **Time Complexity:** O(n) - A single pass through the array.
*   **Space Complexity:** O(1) - Only a constant amount of space is used.

### 3\. Recursive Approach (O(2<sup>n</sup>))

This approach uses recursion to explore all possibilities of including or excluding each element. This is less efficient due to overlapping subproblems.

#### Pseudocode

    function maxNonAdjacentSumRecursive(arr, n):
            if n == 0:
                return arr[0]
            if n == 1:
                return max(arr[0], arr[1])
            return max(maxNonAdjacentSumRecursive(arr, n-1), arr[n] + maxNonAdjacentSumRecursive(arr, n-2))
        

#### Java Implementation

    public class MaxSumNonAdjacentRecursive {
            public static int maxNonAdjacentSumRecursive(int[] nums) {
                return maxNonAdjacentSumRecursiveHelper(nums, nums.length - 1);
            }
    
            private static int maxNonAdjacentSumRecursiveHelper(int[] nums, int n) {
                if (n == 0) return nums[0];
                if (n == 1) return Math.max(nums[0], nums[1]);
                return Math.max(maxNonAdjacentSumRecursiveHelper(nums, n - 1), nums[n] + maxNonAdjacentSumRecursiveHelper(nums, n - 2));
            }
        }
        

### Time and Space Complexity (Recursive Approach)

*   **Time Complexity:** O(2<sup>n</sup>) - Exponential due to branching.
*   **Space Complexity:** O(n) - Space used by the call stack.