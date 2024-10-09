Exponentiation by Squaring
==========================

**Exponentiation by Squaring** is an efficient algorithm for raising a number to a power, particularly useful for large exponents. It reduces the number of multiplications required by breaking the problem into smaller subproblems.

How It Works
------------

*   The algorithm works by using the properties of exponents:
    *   If <code>n</code> is even, <code>x<sup>n</sup> = (x<sup>n/2</sup>)<sup>2</sup></code>.
    *   If <code>n</code> is odd, <code>x<sup>n</sup> = x * x<sup>n-1</sup></code>.
*   This method significantly reduces the number of multiplications needed to calculate `xn`.

Java Code Implementation
------------------------

    
    public class ExponentiationBySquaring {
    
        public static void main(String[] args) {
            double base = 2.0; // Base number
            int exponent = 10; // Exponent
    
            double result = exponentiate(base, exponent);
            System.out.println(base + " raised to the power of " + exponent + " is: " + result);
        }
    
        // Function to calculate x^n using Exponentiation by Squaring
        public static double exponentiate(double x, int n) {
            if (n < 0) {
                x = 1 / x;
                n = -n;
            }
            return exponentiateHelper(x, n);
        }
    
        private static double exponentiateHelper(double x, int n) {
            if (n == 0) {
                return 1;
            }
            if (n % 2 == 0) {
                double half = exponentiateHelper(x, n / 2);
                return half * half;
            } else {
                return x * exponentiateHelper(x, n - 1);
            }
        }
    }
        

Explanation of the Code
-----------------------

*   The `exponentiate` method checks for negative exponents and converts them to positive.
*   The `exponentiateHelper` method implements the recursive logic for exponentiation by squaring.
*   If the exponent is zero, the method returns 1, as any number raised to the power of zero is 1.
*   The algorithm reduces the problem size by halving the exponent at each step when it's even.

Key Points
----------

*   **Efficiency:** The time complexity is **O(log n)**, making it much faster than the naive approach, which has a time complexity of **O(n)**.
*   **Use Cases:** Commonly used in algorithms related to cryptography, numerical computations, and other applications requiring large powers.
*   **Handling Negative Exponents:** The algorithm can handle negative exponents by inverting the base.
*   **Recursive and Iterative Versions:** The algorithm can be implemented both recursively (as shown) and iteratively.
*   **Precision:** Be mindful of precision when dealing with floating-point numbers, especially for very large or very small values.

Time Complexity
---------------

The time complexity of Exponentiation by Squaring is **O(log n)**, making it efficient for large exponent values.

Space Complexity
----------------

The space complexity is **O(log n)** due to the recursive call stack in the recursive implementation.