Maximum Sum Circular Subarray
=============================

Problem Definition
------------------

The **Maximum Sum Circular Subarray** problem involves finding the maximum possible sum of a subarray in a circular array. The array is circular in the sense that the last element is connected to the first element.

### Example

*   Input: `[1, -2, 3, -2]`
*   Output: `3` (The maximum sum subarray is `[3]`)

Solution Approaches
-------------------

### 1\. Standard Kadane's Algorithm (O(n))

This approach uses Kadane's Algorithm to find the maximum sum subarray in a non-circular array. This will serve as a baseline for comparison.

#### Pseudocode

    function maxSubarraySum(arr):
            maxEndingHere = arr[0]
            maxSoFar = arr[0]
            for i from 1 to length(arr) - 1:
                maxEndingHere = max(arr[i], maxEndingHere + arr[i])
                maxSoFar = max(maxSoFar, maxEndingHere)
            return maxSoFar
        

#### Java Implementation

    public class MaxSumSubarray {
            public static int maxSubarraySum(int[] nums) {
                int maxEndingHere = nums[0];
                int maxSoFar = nums[0];
    
                for (int i = 1; i < nums.length; i++) {
                    maxEndingHere = Math.max(nums[i], maxEndingHere + nums[i]);
                    maxSoFar = Math.max(maxSoFar, maxEndingHere);
                }
    
                return maxSoFar;
            }
        }
        

### Time and Space Complexity (Standard Kadane's Algorithm)

*   **Time Complexity:** O(n) - A single pass through the array.
*   **Space Complexity:** O(1) - Only a few variables are used.

### 2\. Maximum Sum Circular Subarray (O(n))

To find the maximum sum circular subarray, we can calculate the total sum of the array and then find the minimum sum subarray (which we can use to calculate the maximum circular sum).

#### Pseudocode

    function maxCircularSubarraySum(arr):
            maxKadane = maxSubarraySum(arr)
            totalSum = sum(arr)
            minKadane = minSubarraySum(arr)
            if totalSum == minKadane:
                return maxKadane
            return max(maxKadane, totalSum - minKadane)
        

#### Java Implementation

    public class MaxSumCircularSubarray {
            public static int maxCircularSubarraySum(int[] nums) {
                int maxKadane = maxSubarraySum(nums);
                int totalSum = 0;
                int minKadane = Integer.MAX_VALUE;
                int currentMin = 0;
    
                for (int num : nums) {
                    totalSum += num;
                    currentMin += num;
                    minKadane = Math.min(minKadane, currentMin);
                    if (currentMin > 0) {
                        currentMin = 0;
                    }
                }
    
                if (totalSum == minKadane) {
                    return maxKadane;
                }
    
                return Math.max(maxKadane, totalSum - minKadane);
            }
    
            public static int maxSubarraySum(int[] nums) {
                int maxEndingHere = nums[0];
                int maxSoFar = nums[0];
    
                for (int i = 1; i < nums.length; i++) {
                    maxEndingHere = Math.max(nums[i], maxEndingHere + nums[i]);
                    maxSoFar = Math.max(maxSoFar, maxEndingHere);
                }
    
                return maxSoFar;
            }
    
            public static void main(String[] args) {
                int[] nums = [1, -2, 3, -2];
                int result = maxCircularSubarraySum(nums);
                System.out.println("Maximum Sum Circular Subarray: " + result);  // Output: 3
            }
        }
        

### Time and Space Complexity (Maximum Sum Circular Subarray)

*   **Time Complexity:** O(n) - The algorithm iterates through the array multiple times, but the overall complexity is linear.
*   **Space Complexity:** O(1) - Only a few variables are used to store sums.