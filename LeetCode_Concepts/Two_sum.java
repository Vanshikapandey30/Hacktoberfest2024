/*
Problem Statement:
Given an array of integers nums and an integer target, return the indices of the two numbers such that they add up to the target.

You may assume that each input will have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Exact one valid solution exists.
Example:
Input:
nums = [5, 7, 10, 15], target = 25
Output:
Indices: [2, 3]
*/

import java.util.HashMap;

public class TwoSum {
    public static int[] twoSum(int[] nums, int target) {
        // Create a HashMap to store the number and its index
        HashMap<Integer, Integer> map = new HashMap<>();

        // Traverse the array once
        for (int i = 0; i < nums.length; i++) {
            // Calculate the complement that we need to reach the target
            int complement = target - nums[i];

            // If complement exists in the map, return the indices
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }

            // Store the current number with its index
            map.put(nums[i], i);
        }

        // If no solution is found (for safety, though the problem guarantees one)
        throw new IllegalArgumentException("No two sum solution");
    }

    public static void main(String[] args) {
        // Example input
        int[] nums = {2, 7, 11, 15};
        int target = 9;

        // Call the twoSum function
        int[] result = twoSum(nums, target);

        // Print the result
        System.out.println("Indices: [" + result[0] + ", " + result[1] + "]");
    }
}


  
