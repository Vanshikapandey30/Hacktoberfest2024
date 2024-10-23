class Stack {
    private int maxSize; // Maximum size of the stack
    private int[] stackArray; // Array to hold stack elements
    private int top; // Index of the top element

    // Constructor to initialize the stack
    public Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1; // Stack is initially empty
    }

    // Method to push an element onto the stack
    public void push(int value) {
        if (top >= maxSize - 1) {
            System.out.println("Stack is full. Cannot push " + value);
        } else {
            stackArray[++top] = value; // Increment top and add value
            System.out.println("Pushed " + value + " onto stack.");
        }
    }

    // Method to pop an element from the stack
    public int pop() {
        if (top < 0) {
            System.out.println("Stack is empty. Cannot pop.");
            return -1; // Indicate empty stack
        } else {
            return stackArray[top--]; // Return top value and decrement top
        }
    }

    // Method to display the stack contents
    public void displayStack() {
        if (top < 0) {
            System.out.println("Stack is empty.");
            return;
        }
        System.out.print("Stack contents: ");
        for (int i = top; i >= 0; i--) {
            System.out.print(stackArray[i] + " ");
        }
        System.out.println();
    }

    // Main method to test the Stack
    public static void main(String[] args) {
        Stack stack = new Stack(5); // Create a stack of size 5

        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.displayStack(); // Display stack contents

        System.out.println("Popped: " + stack.pop());
        stack.displayStack(); // Display stack contents

        stack.push(40);
        stack.push(50);
        stack.push(60); // This push will fail (stack full)
        stack.displayStack(); // Display stack contents
    }
}
