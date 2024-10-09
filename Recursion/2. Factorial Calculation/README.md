Factorial Calculation
=====================

Problem Definition
------------------

The factorial of a non-negative integer `n`, denoted as `n!`, is the product of all positive integers less than or equal to `n`. Factorial is used in many areas of mathematics, including combinatorics, algebra, and mathematical analysis.

### Example

*   Input: `n = 5`
*   Output: `5! = 120`

Solution Approaches
-------------------

### 1\. Recursive Approach

Factorial can be calculated recursively by using the relation:

    n! = n * (n - 1)! 

with the base case being:

    0! = 1

#### Pseudocode

    function factorial(n):
        if n == 0:
            return 1
        return n * factorial(n - 1)
    

#### Java Implementation

    public class Factorial {
        public static int factorial(int n) {
            if (n == 0) {
                return 1;
            }
            return n * factorial(n - 1);
        }
    
        public static void main(String[] args) {
            int n = 5; // Example input
            System.out.println(n + "! = " + factorial(n));
        }
    }
    

### 2\. Iterative Approach

Factorial can also be calculated using an iterative approach:

#### Pseudocode

    function factorial(n):
        result = 1
        for i from 1 to n:
            result = result * i
        return result
    

#### Java Implementation

    public class Factorial {
        public static int factorial(int n) {
            int result = 1;
            for (int i = 1; i <= n; i++) {
                result *= i;
            }
            return result;
        }
    
        public static void main(String[] args) {
            int n = 5; // Example input
            System.out.println(n + "! = " + factorial(n));
        }
    }
    

#### Time and Space Complexity

*   **Recursive Approach:**

*   **Time Complexity:** O(n) - Each recursive call takes constant time.
*   **Space Complexity:** O(n) - The maximum depth of the recursion stack is n.

*   **Iterative Approach:**

*   **Time Complexity:** O(n) - The loop runs n times.
*   **Space Complexity:** O(1) - Only a constant amount of space is used.

Conclusion
----------

The factorial calculation can be performed using both recursive and iterative methods. The choice of method depends on the requirements for clarity, performance, and stack space.