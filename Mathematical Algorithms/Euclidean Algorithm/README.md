Euclidean Algorithm
===================

The **Euclidean Algorithm** is an efficient method for computing the greatest common divisor (GCD) of two integers. It is based on the principle that the GCD of two numbers also divides their difference.

How It Works
------------

*   Given two non-negative integers **a** and **b**, where **a** ≥ **b**.
*   Replace **a** with **b** and **b** with **a mod b** (the remainder when **a** is divided by **b**).
*   Repeat this process until **b** becomes 0.
*   The last non-zero value of **a** is the GCD of the original two numbers.

Java Code Implementation
------------------------

    
    public class EuclideanAlgorithm {
    
        public static void main(String[] args) {
            int a = 48; // First number
            int b = 18; // Second number
    
            int gcd = findGCD(a, b);
            System.out.println("The GCD of " + a + " and " + b + " is: " + gcd);
        }
    
        // Function to find GCD using Euclidean Algorithm
        public static int findGCD(int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
    }
        

Explanation of the Code
-----------------------

*   The program defines a method `findGCD` that implements the Euclidean Algorithm.
*   It repeatedly updates **a** and **b** until **b** becomes 0.
*   The result is printed to the console as the GCD of the two numbers.

Key Points
----------

*   **Efficiency:** The Euclidean Algorithm is very efficient, with a time complexity of **O(log(min(a, b)))**.
*   **Historical Significance:** The algorithm is one of the oldest mathematical algorithms, dating back to ancient Greece.
*   **Applications:** It is widely used in number theory and has applications in cryptography, computer science, and algebra.
*   **Extension:** The Extended Euclidean Algorithm can also be used to find integer coefficients that express the GCD as a linear combination of **a** and **b**.
*   **Non-negative Integers:** The algorithm assumes that both integers are non-negative; additional checks may be needed for negative inputs.

Time Complexity
---------------

The time complexity of the Euclidean Algorithm is **O(log(min(a, b)))**, making it efficient for large numbers.

Space Complexity
----------------

The space complexity is **O(1)** since it only uses a constant amount of space for variables.