Check if a Number is a Power of Two
===================================

A number is a power of two if it can be expressed as `2^x` where `x` is a non-negative integer. For example, numbers like `1, 2, 4, 8, 16`, and so on are all powers of two.

Problem Statement
-----------------

Given an integer `n`, determine whether it is a power of two. You need to implement an efficient solution to check this condition.

Methods for Solving
-------------------

*   **Mathematical Method:** A number is a power of two if it can be continuously divided by 2 without leaving a remainder.
*   **Bitwise Method:** A number is a power of two if and only if it has exactly one bit set to `1` in its binary representation. This can be checked using the expression `(n & (n - 1)) == 0`.

Java Code Implementation (Mathematical and Bitwise Methods)
-----------------------------------------------------------

    
    public class PowerOfTwoChecker {
    
        // Method to check if a number is a power of two using the mathematical approach
        public static boolean isPowerOfTwoMath(int n) {
            if (n <= 0) {
                return false;
            }
            while (n % 2 == 0) {
                n /= 2;
            }
            return n == 1;
        }
    
        // Method to check if a number is a power of two using the bitwise approach
        public static boolean isPowerOfTwoBitwise(int n) {
            return n > 0 && (n & (n - 1)) == 0;
        }
    
        public static void main(String[] args) {
            int num = 16; // Example number
            
            System.out.println(num + " is power of two (Math): " + isPowerOfTwoMath(num));
            System.out.println(num + " is power of two (Bitwise): " + isPowerOfTwoBitwise(num));
        }
    }
        

Explanation of the Code
-----------------------

*   **isPowerOfTwoMath:** This method divides the number repeatedly by `2` until it becomes `1`. If it is divisible by `2` all the way down to `1`, then the number is a power of two.
*   **isPowerOfTwoBitwise:** This method uses the fact that a power of two has exactly one bit set in its binary representation. For example, `4` is `100`, and `16` is `10000`. The expression `(n & (n - 1))` will be `0` for powers of two because it clears the lowest set bit.
*   **main method:** A sample number is tested using both methods, and the results are printed to the console.

Mathematical Method Explanation
-------------------------------

In the mathematical approach, we repeatedly divide the number by `2` as long as it is divisible. If the result is eventually `1`, the number is a power of two. This approach works well for positive integers.

For example, for `n = 16`:

    
    16 ÷ 2 = 8
    8 ÷ 2 = 4
    4 ÷ 2 = 2
    2 ÷ 2 = 1  →  Power of two
        

Bitwise Method Explanation
--------------------------

The bitwise approach leverages the properties of binary numbers. A power of two has exactly one bit set in its binary form. When you subtract `1` from a power of two, it flips all the bits after the set bit, and when you apply the bitwise AND operation, the result will be `0`.

For example, for `n = 16`:

    
    16 in binary:  10000
    15 in binary:  01111
    16 & 15 = 00000 →  0 (True, it's a power of two)
        

Key Points
----------

*   **Efficiency:** Both methods have a time complexity of **O(log n)** for the mathematical method (due to the division) and **O(1)** for the bitwise method.
*   **Bitwise Method Advantage:** The bitwise method is highly efficient and is preferred in competitive programming due to its constant time complexity.
*   **Edge Case:** Both methods handle edge cases like `n = 0` and negative numbers by returning `false`.