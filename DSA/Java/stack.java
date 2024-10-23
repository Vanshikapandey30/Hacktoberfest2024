class Stack {
    private int[] stackArray;
    private int top;
    private int capacity;

    // Constructor to initialize the stack
    public Stack(int size) {
        stackArray = new int[size];
        capacity = size;
        top = -1;  // Initialize the top of the stack to -1, meaning the stack is empty
    }

    // Method to push an element onto the stack
    public void push(int value) {
        if (isFull()) {
            System.out.println("Stack Overflow! Cannot add element: " + value);
        } else {
            stackArray[++top] = value;  // Increment top and then add value
            System.out.println("Pushed: " + value);
        }
    }

    // Method to pop an element from the stack
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow! No element to pop.");
            return -1;  // Return -1 to indicate no element can be popped
        } else {
            return stackArray[top--];  // Return the top element and then decrement top
        }
    }

    // Method to peek the top element without removing it
    public int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty! No element to peek.");
            return -1;
        } else {
            return stackArray[top];  // Return the top element without modifying the stack
        }
    }

    // Method to check if the stack is empty
    public boolean isEmpty() {
        return top == -1;
    }

    // Method to check if the stack is full
    public boolean isFull() {
        return top == capacity - 1;
    }

    // Method to get the current size of the stack
    public int size() {
        return top + 1;  // Since top starts at -1, add 1 to get the current size
    }

    public static void main(String[] args) {
        Stack stack = new Stack(5);  // Create a stack of size 5

        stack.push(10);  // Push 10
        stack.push(20);  // Push 20
        stack.push(30);  // Push 30
        stack.push(40);  // Push 40
        stack.push(50);  // Push 50

        System.out.println("Peek element: " + stack.peek());  // Should print 50
        System.out.println("Stack size: " + stack.size());  // Should print 5

        System.out.println("Popped element: " + stack.pop());  // Should pop 50
        System.out.println("Peek element: " + stack.peek());  // Should print 40
        System.out.println("Stack size: " + stack.size());  // Should print 4
    }
}

