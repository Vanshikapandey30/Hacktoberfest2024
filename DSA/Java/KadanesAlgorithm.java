package DSA.Java;

public class KadanesAlgorithm {
    // Function to find the maximum sum of a contiguous subarray using Kadane's
    // Algorithm
    public static int maxSubArraySum(int[] arr) {
        int maxSoFar = Integer.MIN_VALUE; // Initialize to the smallest possible value
        int maxEndingHere = 0; // To keep track of the current subarray sum

        for (int i = 0; i < arr.length; i++) {
            maxEndingHere += arr[i]; // Add the current element to the current subarray sum

            if (maxSoFar < maxEndingHere) {
                maxSoFar = maxEndingHere; // Update maxSoFar if the current subarray sum is greater
            }

            if (maxEndingHere < 0) {
                maxEndingHere = 0; // Reset the current subarray sum if it becomes negative
            }
        }

        return maxSoFar; // Return the maximum sum found
    }

    public static void main(String[] args) {
        // Example array
        int[] arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

        // Calling the function and printing the result
        int maxSum = maxSubArraySum(arr);
        System.out.println("Maximum contiguous subarray sum is: " + maxSum);
    }
}
