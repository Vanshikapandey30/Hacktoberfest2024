Maximum Product Subarray
========================

Problem Definition
------------------

The **Maximum Product Subarray** problem is to find the contiguous subarray within a one-dimensional array of numbers (which can include both positive and negative numbers) that has the largest product.

### Example

*   Input: `[-2, 3, -4]`
*   Output: `24` (The maximum product subarray is `[3, -4]`)

Solution Approaches
-------------------

### 1\. Brute Force Approach (O(n<sup>2</sup>))

This approach involves checking all possible subarrays to find the maximum product. It is not efficient but serves as a straightforward method to understand the problem.

#### Pseudocode

    function maxProductBruteForce(arr):
            maxProduct = arr[0]
            for i from 0 to length(arr) - 1:
                product = 1
                for j from i to length(arr) - 1:
                    product *= arr[j]
                    maxProduct = max(maxProduct, product)
            return maxProduct
        

#### Java Implementation

    public class MaxProductSubarrayBruteForce {
            public static int maxProductBruteForce(int[] nums) {
                int maxProduct = nums[0];
    
                for (int i = 0; i < nums.length; i++) {
                    int product = 1;
                    for (int j = i; j < nums.length; j++) {
                        product *= nums[j];
                        maxProduct = Math.max(maxProduct, product);
                    }
                }
    
                return maxProduct;
            }
    
            public static void main(String[] args) {
                int[] nums = {-2, 3, -4};
                int result = maxProductBruteForce(nums);
                System.out.println("Maximum Product Subarray: " + result);  // Output: 24
            }
        }
        

### Time and Space Complexity (Brute Force Approach)

*   **Time Complexity:** O(n<sup>2</sup>) - Nested loops iterate through all possible subarrays.
*   **Space Complexity:** O(1) - No additional space used except for variables.

### 2\. Dynamic Programming Approach (O(n))

This approach uses dynamic programming to maintain the maximum and minimum products at each index. This is necessary because a negative number can turn a small product into a large product when multiplied.

#### Pseudocode

    function maxProductDynamicProgramming(arr):
            maxProduct = arr[0]
            currentMax = arr[0]
            currentMin = arr[0]
            for i from 1 to length(arr) - 1:
                tempMax = currentMax
                currentMax = max(arr[i], currentMax * arr[i], currentMin * arr[i])
                currentMin = min(arr[i], tempMax * arr[i], currentMin * arr[i])
                maxProduct = max(maxProduct, currentMax)
            return maxProduct
        

#### Java Implementation

    public class MaxProductSubarrayDP {
            public static int maxProductDynamicProgramming(int[] nums) {
                int maxProduct = nums[0];
                int currentMax = nums[0];
                int currentMin = nums[0];
    
                for (int i = 1; i < nums.length; i++) {
                    int tempMax = currentMax;
                    currentMax = Math.max(nums[i], Math.max(currentMax * nums[i], currentMin * nums[i]));
                    currentMin = Math.min(nums[i], Math.min(tempMax * nums[i], currentMin * nums[i]));
                    maxProduct = Math.max(maxProduct, currentMax);
                }
    
                return maxProduct;
            }
    
            public static void main(String[] args) {
                int[] nums = {-2, 3, -4};
                int result = maxProductDynamicProgramming(nums);
                System.out.println("Maximum Product Subarray: " + result);  // Output: 24
            }
        }
        

### Time and Space Complexity (Dynamic Programming Approach)

*   **Time Complexity:** O(n) - Single loop iterates through the array once.
*   **Space Complexity:** O(1) - Only a few variables are used to store maximum and minimum products.

### 3\. Optimized Approach (O(n))

This approach also uses the idea of maintaining a maximum and minimum product as in the dynamic programming approach, but it optimizes the handling of negative numbers.

#### Pseudocode

    function maxProductOptimized(arr):
            maxProduct = arr[0]
            currentMax = arr[0]
            currentMin = arr[0]
            for i from 1 to length(arr) - 1:
                if arr[i] < 0:
                    swap(currentMax, currentMin)
                currentMax = max(arr[i], currentMax * arr[i])
                currentMin = min(arr[i], currentMin * arr[i])
                maxProduct = max(maxProduct, currentMax)
            return maxProduct
        

#### Java Implementation

    public class MaxProductSubarrayOptimized {
            public static int maxProductOptimized(int[] nums) {
                int maxProduct = nums[0];
                int currentMax = nums[0];
                int currentMin = nums[0];
    
                for (int i = 1; i < nums.length; i++) {
                    if (nums[i] < 0) {
                        int temp = currentMax;
                        currentMax = currentMin;
                        currentMin = temp;
                    }
                    currentMax = Math.max(nums[i], currentMax * nums[i]);
                    currentMin = Math.min(nums[i], currentMin * nums[i]);
                    maxProduct = Math.max(maxProduct, currentMax);
                }
    
                return maxProduct;
            }
    
            public static void main(String[] args) {
                int[] nums = {-2, 3, -4};
                int result = maxProductOptimized(nums);
                System.out.println("Maximum Product Subarray: " + result);  // Output: 24
            }
        }
        

### Time and Space Complexity (Optimized Approach)

*   **Time Complexity:** O(n) - Single loop iterates through the array once.
*   **Space Complexity:** O(1) - Only a few variables are used to store maximum and minimum products.