Modular Arithmetic
==================

**Modular Arithmetic** is a system of arithmetic for integers, where numbers wrap around after reaching a certain value known as the modulus. It is widely used in computer science, cryptography, and number theory.

Basic Concepts
--------------

*   The expression `a ≡ b (mod m)` means that `a` and `b` leave the same remainder when divided by `m`.
*   The **modulus** is the number `m` that defines the range of integers.
*   For example, `7 ≡ 2 (mod 5)` because both 7 and 2 leave a remainder of 2 when divided by 5.

Properties of Modular Arithmetic
--------------------------------

*   **Addition:** `(a + b) mod m = ((a mod m) + (b mod m)) mod m`
*   **Subtraction:** `(a - b) mod m = ((a mod m) - (b mod m) + m) mod m`
*   **Multiplication:** `(a * b) mod m = ((a mod m) * (b mod m)) mod m`
*   **Exponentiation:** `(ab) mod m = (a mod m)b mod m`

Java Code Implementation
------------------------

    
    public class ModularArithmetic {
    
        public static void main(String[] args) {
            int a = 7;
            int b = 3;
            int modulus = 5;
    
            System.out.println("Addition: " + modularAddition(a, b, modulus));
            System.out.println("Subtraction: " + modularSubtraction(a, b, modulus));
            System.out.println("Multiplication: " + modularMultiplication(a, b, modulus));
            System.out.println("Exponentiation: " + modularExponentiation(a, b, modulus));
        }
    
        public static int modularAddition(int a, int b, int m) {
            return (a % m + b % m) % m;
        }
    
        public static int modularSubtraction(int a, int b, int m) {
            return ((a % m - b % m + m) % m);
        }
    
        public static int modularMultiplication(int a, int b, int m) {
            return (a % m * b % m) % m;
        }
    
        public static int modularExponentiation(int base, int exponent, int m) {
            int result = 1;
            base = base % m;
    
            while (exponent > 0) {
                if ((exponent & 1) == 1) {
                    result = (result * base) % m;
                }
                exponent >>= 1;
                base = (base * base) % m;
            }
            return result;
        }
    }
        

Explanation of the Code
-----------------------

*   The `modularAddition`, `modularSubtraction`, and `modularMultiplication` methods implement the basic arithmetic operations under modulo.
*   The `modularExponentiation` method uses exponentiation by squaring to efficiently calculate `(baseexponent) mod m`.
*   Each method ensures the result stays within the bounds defined by the modulus.

Key Points
----------

*   **Efficiency:** Modular arithmetic allows computations to be performed without dealing with large numbers, reducing overflow risks in programming.
*   **Applications:** Commonly used in cryptography algorithms (e.g., RSA), hashing functions, and random number generation.
*   **Negative Numbers:** Modular arithmetic can handle negative numbers by adjusting the result to remain within the modulus.
*   **Equivalence Classes:** Numbers in modular arithmetic are often grouped into equivalence classes based on their remainders.
*   **Extensive Use:** It is extensively used in coding theory, algorithms, and various branches of mathematics.

Time Complexity
---------------

The time complexity for basic operations (addition, subtraction, multiplication, exponentiation) is generally **O(log exponent)** for exponentiation and **O(1)** for addition, subtraction, and multiplication.

Space Complexity
----------------

The space complexity is **O(1)** as the operations use a constant amount of space.