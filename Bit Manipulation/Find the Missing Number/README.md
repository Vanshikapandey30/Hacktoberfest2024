Find the Missing Number
=======================

In many problems, you are given an array of numbers that represents a sequence of integers from `1` to `n`, where one number is missing. The task is to find the missing number in this sequence.

Problem Statement
-----------------

Given an array of integers containing `n - 1` elements, where each element is a unique number from `1` to `n` (inclusive), find the missing number in the array.

Methods for Solving
-------------------

*   **Sum Formula Method:** Use the sum of the first `n` natural numbers formula and subtract the sum of the array elements to get the missing number.
*   **Bitwise XOR Method:** XOR all the elements in the array with numbers from `1` to `n`. The missing number is obtained due to the properties of XOR.
*   **Sorting Method:** Sort the array and check for the first mismatch in the sequence.

Java Code Implementation
------------------------

### 1\. Sum Formula Method

    
    public class MissingNumberFinder {
    
        // Method to find the missing number using sum formula
        public static int findMissingNumber(int[] numbers, int n) {
            int expectedSum = n * (n + 1) / 2; // Sum of first n natural numbers
            int actualSum = 0;
    
            for (int number : numbers) {
                actualSum += number;
            }
    
            return expectedSum - actualSum;
        }
    
        public static void main(String[] args) {
            int[] numbers = {1, 2, 4, 5, 6}; // Example array, n = 6
            int n = 6; // Total numbers expected
    
            int missingNumber = findMissingNumber(numbers, n);
            System.out.println("The missing number is: " + missingNumber);
        }
    }
        

### 2\. Bitwise XOR Method

    
    public class MissingNumberFinder {
    
        // Method to find the missing number using XOR
        public static int findMissingNumberUsingXOR(int[] numbers, int n) {
            int xorResult = 0;
    
            // XOR all the array elements
            for (int number : numbers) {
                xorResult ^= number;
            }
    
            // XOR all the numbers from 1 to n
            for (int i = 1; i <= n; i++) {
                xorResult ^= i;
            }
    
            return xorResult; // This gives the missing number
        }
    
        public static void main(String[] args) {
            int[] numbers = {1, 2, 4, 5, 6}; // Example array, n = 6
            int n = 6; // Total numbers expected
    
            int missingNumber = findMissingNumberUsingXOR(numbers, n);
            System.out.println("The missing number using XOR is: " + missingNumber);
        }
    }
        

Explanation of the Code
-----------------------

*   **Sum Formula Method:** This method uses the formula `n * (n + 1) / 2` to calculate the expected sum of the first `n` natural numbers. Then, it subtracts the actual sum of the array from this expected sum to find the missing number.
*   **Bitwise XOR Method:** This method exploits the properties of XOR. When a number is XORed with itself, the result is 0, and when 0 is XORed with a number, the result is that number. By XORing all the numbers from 1 to `n` and XORing the array elements, the result will be the missing number.

Key Points
----------

*   **Efficiency (Sum Formula):** The time complexity is **O(n)** because we need to compute the sum of the array elements.
*   **Efficiency (XOR Method):** The time complexity is also **O(n)**, as we loop through the array and numbers from `1` to `n` once.
*   **Space Complexity:** Both methods have a space complexity of **O(1)**, as no extra space is required apart from variables.
*   **XOR Method Advantages:** The XOR method is often preferred in bitwise-heavy applications because it does not involve any arithmetic, which can prevent overflow issues when working with very large numbers.
*   **Edge Case:** If the array is empty or has only one element, the missing number will be `1` for a single-element array where `n = 2`.