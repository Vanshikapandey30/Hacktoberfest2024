GCD (Greatest Common Divisor)
=============================================

The **Greatest Common Divisor (GCD)** of two numbers is the largest number that divides both numbers without leaving a remainder. For example, the GCD of 48 and 18 is 6 because 6 is the largest number that divides both 48 and 18.

Euclidean Algorithm: How Does It Work?
--------------------------------------

The **Euclidean Algorithm** is an efficient method to compute the GCD. It is based on the following property:

*   **GCD(a, b) = GCD(b, a % b)**, where `%` is the modulus operator.

This means that instead of repeatedly dividing the numbers, we replace the larger number with the remainder of dividing the larger number by the smaller one, until the remainder becomes 0. At that point, the smaller number is the GCD.

Step-by-Step Explanation of the Java Program
--------------------------------------------

    
    
    import java.util.Scanner;
    
    public class GCDCalculator {
    
        public static int calculateGCD(int number1, int number2) {
            while (number2 != 0) {
                int remainder = number1 % number2; 
                number1 = number2; 
                number2 = remainder; 
            }
            return number1; 
        }
    
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
    
            int number1 = scanner.nextInt();
    
            int number2 = scanner.nextInt();
    
            int gcd = calculateGCD(number1, number2);
    
            System.out.println("The GCD of " + number1 + " and " + number2 + " is: " + gcd);
    
            scanner.close();
        }
    }
        

Detailed Breakdown
------------------

### 1\. Input Handling

    
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter the first number:");
    int number1 = scanner.nextInt();
    
    System.out.println("Enter the second number:");
    int number2 = scanner.nextInt();
        

The program uses a `Scanner` to take two integer inputs from the user: `number1` and `number2`. These values represent the numbers for which we want to find the GCD.

### 2\. GCD Calculation Logic

    
    public static int calculateGCD(int number1, int number2) {
        while (number2 != 0) {
            int remainder = number1 % number2; // Step 1
            number1 = number2; // Step 2
            number2 = remainder; // Step 3
        }
        return number1; // Final GCD
    }
        

\- **Step 1:** Inside the `while` loop, the remainder of `number1` divided by `number2` is calculated.  
\- **Step 2:** The value of `number1` is then replaced by the current value of `number2`.  
\- **Step 3:** The value of `number2` is replaced by the remainder.

The loop continues until `number2` becomes 0, at which point `number1` will contain the GCD.

### 3\. Euclidean Algorithm in Action

If `number1 = 48` and `number2 = 18`:

*   First iteration: `remainder = 48 % 18 = 12`, update `number1 = 18` and `number2 = 12`
*   Second iteration: `remainder = 18 % 12 = 6`, update `number1 = 12` and `number2 = 6`
*   Third iteration: `remainder = 12 % 6 = 0`, update `number1 = 6` and `number2 = 0`

The loop ends, and the final value of `number1` (6) is returned as the GCD.

### 4\. Displaying the Result

    
    System.out.println("The GCD of " + number1 + " and " + number2 + " is: " + gcd);
        

The result is printed using `System.out.println()`, showing the GCD of the two input numbers.

### 5\. Closing the Scanner

    
    scanner.close();
        

The `Scanner` is closed to release resources.

Sample Run of the Program
-------------------------

**Input:**

    Enter the first number:
    48
    
    Enter the second number:
    18
    

**Output:**

    The GCD of 48 and 18 is: 6
    

Key Interview Points to Remember
--------------------------------

*   **Efficiency:** The Euclidean algorithm runs in **O(log(min(number1, number2)))** time complexity, making it highly efficient for finding the GCD of two numbers, even if the numbers are large.
*   **Algorithm Intuition:** Understanding the property that `GCD(a, b) = GCD(b, a % b)` is crucial.
*   **Edge Cases:** If either number is 0, the GCD is the other non-zero number.
*   **Iterative vs Recursive:** The Euclidean algorithm can be implemented either iteratively (as shown) or recursively, with similar efficiency.
*   **Applications:** GCD is fundamental in problems related to **fractions, simplification, number theory, and cryptography**.
*   **Important Functionality:** The modulus operation is key to how the Euclidean algorithm works.