Bit Masking
===========

Bit masking is a technique used to manipulate specific bits of a number. By using bitwise operators, we can efficiently perform operations such as setting, clearing, toggling, or checking a bit at a particular position in the binary representation of an integer.

Key Operations
--------------

*   **Set a bit:** Set a specific bit to 1.
*   **Clear a bit:** Set a specific bit to 0.
*   **Toggle a bit:** Flip a specific bit (1 becomes 0, and 0 becomes 1).
*   **Check a bit:** Check if a specific bit is 1 or 0.

Bitwise Operators Used
----------------------

*   `&` (AND)
*   `|` (OR)
*   `^` (XOR)
*   `~` (NOT)
*   `<<` (Left shift)
*   `>>` (Right shift)

Bit Masking Operations in Java
------------------------------

### 1\. Setting a Bit

To set the `i`\-th bit of a number to 1, use the expression `number | (1 << i)`.

    
    public class BitMaskingOperations {
    
        // Set the ith bit
        public static int setBit(int number, int i) {
            return number | (1 << i);
        }
    
        public static void main(String[] args) {
            int number = 8; // 1000 in binary
            int i = 1;
            int result = setBit(number, i);
            System.out.println("After setting bit " + i + ": " + result); // 1010 (10 in decimal)
        }
    }
        

### 2\. Clearing a Bit

To clear the `i`\-th bit (set it to 0), use the expression `number & ~(1 << i)`.

    
    public class BitMaskingOperations {
    
        // Clear the ith bit
        public static int clearBit(int number, int i) {
            return number & ~(1 << i);
        }
    
        public static void main(String[] args) {
            int number = 10; // 1010 in binary
            int i = 1;
            int result = clearBit(number, i);
            System.out.println("After clearing bit " + i + ": " + result); // 1000 (8 in decimal)
        }
    }
        

### 3\. Toggling a Bit

To toggle the `i`\-th bit (flip its value), use the expression `number ^ (1 << i)`.

    
    public class BitMaskingOperations {
    
        // Toggle the ith bit
        public static int toggleBit(int number, int i) {
            return number ^ (1 << i);
        }
    
        public static void main(String[] args) {
            int number = 10; // 1010 in binary
            int i = 1;
            int result = toggleBit(number, i);
            System.out.println("After toggling bit " + i + ": " + result); // 1000 (8 in decimal)
        }
    }
        

### 4\. Checking a Bit

To check if the `i`\-th bit is set (1) or not (0), use the expression `(number & (1 << i)) != 0`.

    
    public class BitMaskingOperations {
    
        // Check the ith bit
        public static boolean isBitSet(int number, int i) {
            return (number & (1 << i)) != 0;
        }
    
        public static void main(String[] args) {
            int number = 10; // 1010 in binary
            int i = 3;
            boolean result = isBitSet(number, i);
            System.out.println("Is bit " + i + " set?: " + result); // true
        }
    }
        

Explanation of the Code
-----------------------

*   **Setting a bit:** To set the `i`\-th bit, we left shift `1` by `i` positions and perform a bitwise OR with the original number. This ensures that the `i`\-th bit becomes 1.
*   **Clearing a bit:** To clear the `i`\-th bit, we left shift `1` by `i` positions, then invert the bits using the NOT operator `~`. We then perform a bitwise AND with the original number to clear that bit.
*   **Toggling a bit:** To toggle the `i`\-th bit, we left shift `1` by `i` positions and perform a bitwise XOR with the original number. This flips the bit value (1 becomes 0, and 0 becomes 1).
*   **Checking a bit:** To check if the `i`\-th bit is set, we left shift `1` by `i` positions and perform a bitwise AND with the original number. If the result is non-zero, the bit is set; otherwise, it is clear.

Applications of Bit Masking
---------------------------

*   **Flag Manipulation:** Using bit masks to set or clear flags in a compact and efficient manner.
*   **Subsets and Combinations:** Enumerating all subsets of a set by representing each subset as a bitmask.
*   **Efficient Storage:** Storing and manipulating boolean or small values using fewer memory resources.
*   **Data Compression:** Bit-level operations for encoding and decoding information in a compressed format.

Key Points
----------

*   **Efficiency:** Bitwise operations are highly efficient, taking constant time `O(1)` for each operation.
*   **Common Usage:** Bit masking is often used in low-level programming, embedded systems, competitive programming, and situations where memory efficiency is crucial.
*   **Handling Edge Cases:** Ensure that bit positions are within valid ranges (e.g., for a 32-bit integer, `0 ≤ i < 32`).