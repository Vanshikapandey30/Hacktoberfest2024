Tower of Hanoi Problem
======================

Problem Definition
------------------

The Tower of Hanoi is a classic mathematical puzzle consisting of three rods and a number of disks of different sizes which can slide onto any rod. The puzzle starts with the disks stacked in ascending order of size on one rod, the smallest at the top. The objective is to move the entire stack to another rod, obeying the following rules:

*   Only one disk can be moved at a time.
*   Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or an empty rod.
*   No larger disk may be placed on top of a smaller disk.

### Example

*   Input: Number of disks = 3
*   Output: Steps to move the disks from source rod to destination rod:

    Move disk 1 from source to destination
    Move disk 2 from source to auxiliary
    Move disk 1 from destination to auxiliary
    Move disk 3 from source to destination
    Move disk 1 from auxiliary to source
    Move disk 2 from auxiliary to destination
    Move disk 1 from source to destination

Solution Approaches
-------------------

### 1\. Recursive Approach

The most straightforward way to solve the Tower of Hanoi problem is through recursion. The idea is to break down the problem into smaller subproblems.

#### Pseudocode

    function towerOfHanoi(n, source, destination, auxiliary):
        if n == 1:
            print("Move disk 1 from", source, "to", destination)
            return
        towerOfHanoi(n - 1, source, auxiliary, destination)
        print("Move disk", n, "from", source, "to", destination)
        towerOfHanoi(n - 1, auxiliary, destination, source)
    

#### Java Implementation

    public class TowerOfHanoi {
        public static void towerOfHanoi(int n, String source, String destination, String auxiliary) {
            if (n == 1) {
                System.out.println("Move disk 1 from " + source + " to " + destination);
                return;
            }
            towerOfHanoi(n - 1, source, auxiliary, destination);
            System.out.println("Move disk " + n + " from " + source + " to " + destination);
            towerOfHanoi(n - 1, auxiliary, destination, source);
        }
    
        public static void main(String[] args) {
            int n = 3; // Number of disks
            towerOfHanoi(n, "Source", "Destination", "Auxiliary");
        }
    }
    

#### Time and Space Complexity

*   **Time Complexity:** O(2^n) - The number of moves required to solve the puzzle doubles with each additional disk.
*   **Space Complexity:** O(n) - The maximum depth of the recursive call stack is n.

Conclusion
----------

The Tower of Hanoi problem is a classic example of recursion. It demonstrates how a complex problem can be broken down into simpler subproblems, making it easier to solve.