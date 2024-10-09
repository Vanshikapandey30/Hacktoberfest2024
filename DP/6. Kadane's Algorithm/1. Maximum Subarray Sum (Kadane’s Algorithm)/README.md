Maximum Subarray Sum (Kadane’s Algorithm)
=========================================

Problem Definition
------------------

The **Maximum Subarray Sum** problem is to find the contiguous subarray within a one-dimensional array of numbers (which can be both positive and negative) that has the largest sum.

### Example

*   Input: `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`
*   Output: `6` (The maximum sum of the subarray `[4, -1, 2, 1]`)

Solution Approach
-----------------

### Kadane’s Algorithm (O(n))

Kadane’s Algorithm is an efficient way to find the maximum subarray sum in linear time. The idea is to maintain a running sum of the current subarray and update the maximum sum whenever a larger sum is found.

#### Pseudocode

    function maxSubArray(arr):
            maxSum = arr[0]
            currentSum = arr[0]
            for i from 1 to length(arr) - 1:
                currentSum = max(arr[i], currentSum + arr[i])
                maxSum = max(maxSum, currentSum)
            return maxSum
        

#### Java Implementation

    public class MaximumSubarraySum {
        public static int maxSubArray(int[] nums) {
            int maxSum = nums[0];
            int currentSum = nums[0];
    
            for (int i = 1; i < nums.length; i++) {
                currentSum = Math.max(nums[i], currentSum + nums[i]);
                maxSum = Math.max(maxSum, currentSum);
            }
    
            return maxSum;
        }
    
        public static void main(String[] args) {
            int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
            int result = maxSubArray(nums);
            System.out.println("Maximum Subarray Sum: " + result);  // Output: 6
        }
    }
        

#### Time and Space Complexity

*   **Time Complexity:** O(n)
*   **Space Complexity:** O(1) (only a few variables are used)