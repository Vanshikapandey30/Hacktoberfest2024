Sieve of Eratosthenes Algorithm
===============================

The **Sieve of Eratosthenes** is an efficient algorithm for finding all prime numbers up to a specified integer. It works by iteratively marking the multiples of each prime number starting from 2.

How It Works
------------

*   Create a list of consecutive integers from 2 to **n**.
*   Initially, assume all numbers in the list are prime.
*   Starting from the first prime number (2), mark all of its multiples as composite (not prime).
*   Move to the next number that is still marked as prime and repeat the process.
*   Continue until you have processed numbers up to the square root of **n**.
*   The remaining unmarked numbers are all prime.

Java Code Implementation
------------------------

    
    public class SieveOfEratosthenes {
    
        public static void main(String[] args) {
            int n = 100; // Find all primes up to 100
            boolean[] isPrime = new boolean[n + 1];
    
            // Initialize all entries as true (assuming all numbers are prime)
            for (int i = 2; i <= n; i++) {
                isPrime[i] = true;
            }
    
            // Implement the Sieve of Eratosthenes
            for (int p = 2; p * p <= n; p++) {
                if (isPrime[p]) {
                    // Marking multiples of p as false
                    for (int multiple = p * p; multiple <= n; multiple += p) {
                        isPrime[multiple] = false;
                    }
                }
            }
    
            // Print all prime numbers
            System.out.println("Prime numbers up to " + n + ":");
            for (int i = 2; i <= n; i++) {
                if (isPrime[i]) {
                    System.out.print(i + " ");
                }
            }
        }
    }
        

Explanation of the Code
-----------------------

*   The program initializes a boolean array `isPrime` where `true` indicates that the index is a prime number.
*   It then marks non-prime numbers in the array.
*   Finally, it prints out all the prime numbers that remain marked as `true`.

Key Points
----------

*   **Efficiency:** The Sieve of Eratosthenes is very efficient for finding all primes up to a large number **n**, with a time complexity of **O(n log log n)**.
*   **Space Complexity:** It requires **O(n)** space due to the boolean array used for marking primes.
*   **Non-Primes:** It systematically eliminates non-prime numbers, making it easier to identify primes.
*   **Square Root Optimization:** The algorithm only processes numbers up to the square root of **n**, which significantly reduces the number of operations.
*   **Applications:** Useful in number theory, cryptography, and generating prime numbers for algorithms.
*   **Alternatives:** There are other algorithms for finding primes, but the Sieve of Eratosthenes is often the best for small to moderate ranges.

Time Complexity
---------------

The time complexity of the Sieve of Eratosthenes is **O(n log log n)**, making it very efficient for finding all primes less than or equal to **n**.

Space Complexity
----------------

The space complexity is **O(n)** due to the array used to store the primality of numbers.