Jump Game
=========

Problem Definition
------------------

The **Jump Game** problem asks if it is possible to reach the last index of a given array, starting from the first index, by jumping from one element to another. The element at index `i` represents the maximum jump length from that position.

### Example

*   Input: `[2, 3, 1, 1, 4]`
*   Output: `true`
*   Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

### Example 2

*   Input: `[3, 2, 1, 0, 4]`
*   Output: `false`
*   Explanation: You will always arrive at index 3 but cannot proceed further.

Solution Approaches
-------------------

### 1\. Recursive Approach

The recursive approach explores every possible jump from the current index and checks if it can reach the last index.

#### Pseudocode

    function canJumpRecursive(index, nums):
        if index >= lastIndex:
            return true
        furthestJump = min(index + nums[index], lastIndex)
        for nextIndex from index + 1 to furthestJump:
            if canJumpRecursive(nextIndex, nums):
                return true
        return false
    

#### Java Implementation

    public class JumpGame {
    
        public static boolean canJumpRecursive(int index, int[] nums) {
            if (index >= nums.length - 1) return true;
            int furthestJump = Math.min(index + nums[index], nums.length - 1);
            for (int nextIndex = index + 1; nextIndex <= furthestJump; nextIndex++) {
                if (canJumpRecursive(nextIndex, nums)) {
                    return true;
                }
            }
            return false;
        }
    
        public static void main(String[] args) {
            int[] nums = {2, 3, 1, 1, 4};
            System.out.println(canJumpRecursive(0, nums));  // Output: true
        }
    }
    

### 2\. Memoization Approach

This approach optimizes the recursive solution by storing the result of each subproblem (whether the index is "good" or "bad") to avoid recalculations.

#### Pseudocode

    function canJumpMemo(index, nums, memo):
        if memo[index] is not UNKNOWN:
            return memo[index]
        furthestJump = min(index + nums[index], lastIndex)
        for nextIndex from index + 1 to furthestJump:
            if canJumpMemo(nextIndex, nums, memo):
                memo[index] = GOOD
                return true
        memo[index] = BAD
        return false
    

#### Java Implementation

    public class JumpGame {
    
        enum Index { GOOD, BAD, UNKNOWN }
        
        public static boolean canJumpMemo(int[] nums) {
            Index[] memo = new Index[nums.length];
            for (int i = 0; i < nums.length; i++) {
                memo[i] = Index.UNKNOWN;
            }
            memo[nums.length - 1] = Index.GOOD;
            return canJumpMemoHelper(0, nums, memo);
        }
    
        private static boolean canJumpMemoHelper(int index, int[] nums, Index[] memo) {
            if (memo[index] != Index.UNKNOWN) {
                return memo[index] == Index.GOOD;
            }
            int furthestJump = Math.min(index + nums[index], nums.length - 1);
            for (int nextIndex = index + 1; nextIndex <= furthestJump; nextIndex++) {
                if (canJumpMemoHelper(nextIndex, nums, memo)) {
                    memo[index] = Index.GOOD;
                    return true;
                }
            }
            memo[index] = Index.BAD;
            return false;
        }
    
        public static void main(String[] args) {
            int[] nums = {2, 3, 1, 1, 4};
            System.out.println(canJumpMemo(nums));  // Output: true
        }
    }
    

### 3\. Dynamic Programming (Greedy) Approach

The greedy approach iterates from the last index to the first, keeping track of the leftmost index that can reach the last index.

#### Pseudocode

    function canJumpDP(nums):
        lastPosition = last index of nums
        for i from lastPosition - 1 to 0:
            if i + nums[i] >= lastPosition:
                lastPosition = i
        return lastPosition == 0
    

#### Java Implementation

    public class JumpGame {
    
        public static boolean canJumpDP(int[] nums) {
            int lastPosition = nums.length - 1;
            for (int i = nums.length - 2; i >= 0; i--) {
                if (i + nums[i] >= lastPosition) {
                    lastPosition = i;
                }
            }
            return lastPosition == 0;
        }
    
        public static void main(String[] args) {
            int[] nums = {2, 3, 1, 1, 4};
            System.out.println(canJumpDP(nums));  // Output: true
        }
    }
    

Complexity Analysis
-------------------

*   **Recursive Approach:** O(2<sup>n</sup>) time, O(n) space (due to recursion stack).
*   **Memoization Approach:** O(n<sup>2</sup>) time, O(n) space (due to memoization table).
*   **Dynamic Programming (Greedy) Approach:** O(n) time, O(1) space.