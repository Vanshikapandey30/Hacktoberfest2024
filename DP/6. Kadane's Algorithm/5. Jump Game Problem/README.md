Jump Game Problem
=================

Problem Definition
------------------

The **Jump Game Problem** involves determining if you can reach the last index of an array starting from the first index. Each element in the array represents your maximum jump length at that position.

### Example

*   Input: `[2, 3, 1, 1, 4]`
*   Output: `true` (You can jump to the last index)

Solution Approaches
-------------------

### 1\. Greedy Approach (O(n))

This approach iterates through the array while keeping track of the maximum reachable index. If at any point the current index exceeds the maximum reachable index, we cannot reach the last index.

#### Pseudocode

    function canJump(nums):
            maxReach = 0
            for i from 0 to length(nums) - 1:
                if i > maxReach:
                    return false
                maxReach = max(maxReach, i + nums[i])
            return true
        

#### Java Implementation

    public class JumpGameGreedy {
            public static boolean canJump(int[] nums) {
                int maxReach = 0;
                for (int i = 0; i < nums.length; i++) {
                    if (i > maxReach) return false;
                    maxReach = Math.max(maxReach, i + nums[i]);
                }
                return true;
            }
        }
        

### Time and Space Complexity (Greedy Approach)

*   **Time Complexity:** O(n) - A single pass through the array.
*   **Space Complexity:** O(1) - No additional space used.

### 2\. Dynamic Programming (O(n))

This approach uses a DP array to keep track of whether each index can be reached from the starting index. The last index's value in the DP array determines the answer.

#### Pseudocode

    function canJumpDP(nums):
            dp = array of size length(nums) initialized to false
            dp[0] = true
            for i from 0 to length(nums):
                if dp[i] is true:
                    for j from 1 to nums[i]:
                        if i + j < length(nums):
                            dp[i + j] = true
            return dp[length(nums) - 1]
        

#### Java Implementation

    public class JumpGameDP {
            public static boolean canJump(int[] nums) {
                boolean[] dp = new boolean[nums.length];
                dp[0] = true;
                
                for (int i = 0; i < nums.length; i++) {
                    if (dp[i]) {
                        for (int j = 1; j <= nums[i]; j++) {
                            if (i + j < nums.length) {
                                dp[i + j] = true;
                            }
                        }
                    }
                }
                return dp[nums.length - 1];
            }
        }
        

### Time and Space Complexity (Dynamic Programming)

*   **Time Complexity:** O(n<sup>2</sup>) - Nested loops leading to quadratic time complexity.
*   **Space Complexity:** O(n) - An additional array is used to store results.

### 3\. Backtracking (O(2<sup>n</sup>))

This approach tries all possible jumps recursively. This method is inefficient due to the exponential growth of recursive calls and is not recommended for larger arrays.

#### Pseudocode

    function canJumpBacktrack(nums, index):
            if index >= length(nums) - 1:
                return true
            for j from 1 to nums[index]:
                if canJumpBacktrack(nums, index + j):
                    return true
            return false
        

#### Java Implementation

    public class JumpGameBacktracking {
            public static boolean canJump(int[] nums) {
                return canJumpHelper(nums, 0);
            }
    
            private static boolean canJumpHelper(int[] nums, int index) {
                if (index >= nums.length - 1) return true;
                for (int j = 1; j <= nums[index]; j++) {
                    if (canJumpHelper(nums, index + j)) {
                        return true;
                    }
                }
                return false;
            }
        }
        

### Time and Space Complexity (Backtracking)

*   **Time Complexity:** O(2<sup>n</sup>) - Exponential due to branching.
*   **Space Complexity:** O(n) - Space used by the call stack.