import java.util.Scanner;
import java.util.EmptyStackException;

class Stack {
    private int maxSize; // Maximum size of the stack
    private int[] stackArray; // Array that represents the stack
    private int top; // The top of the stack (index)

    // Constructor to initialize the stack with a given size
    public Stack(int size) {
        this.maxSize = size;
        this.stackArray = new int[maxSize];
        this.top = -1; // Initialize stack as empty
    }

    // Push operation: Add an element to the top of the stack
    public void push(int value) {
        if (isFull()) {
            System.out.println("Stack is full! Cannot push " + value);
        } else {
            stackArray[++top] = value;
            System.out.println(value + " pushed to the stack.");
        }
    }

    // Pop operation: Remove and return the top element of the stack
    public int pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        } else {
            int value = stackArray[top--];
            System.out.println(value + " popped from the stack.");
            return value;
        }
    }

    // Peek operation: Return the top element without removing it
    public int peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        } else {
            return stackArray[top];
        }
    }

    // Display operation: Display all elements in the stack
    public void display() {
        if (isEmpty()) {
            System.out.println("Stack is empty.");
        } else {
            System.out.println("Stack elements are:");
            for (int i = top; i >= 0; i--) {
                System.out.println(stackArray[i]);
            }
        }
    }

    // Check if the stack is empty
    public boolean isEmpty() {
        return (top == -1);
    }

    // Check if the stack is full
    public boolean isFull() {
        return (top == maxSize - 1);
    }

    // Main method with a menu-driven approach
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the stack: ");
        int size = scanner.nextInt();
        Stack stack = new Stack(size);

        int choice;
        do {
            System.out.println("\nStack Operations Menu:");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Peek");
            System.out.println("4. Display");
            System.out.println("5. Exit");
            System.out.print("Enter your choice (1-5): ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the value to push: ");
                    int value = scanner.nextInt();
                    stack.push(value);
                    break;
                case 2:
                    try {
                        stack.pop();
                    } catch (EmptyStackException e) {
                        System.out.println("Stack is empty! Cannot pop.");
                    }
                    break;
                case 3:
                    try {
                        System.out.println("Top element is: " + stack.peek());
                    } catch (EmptyStackException e) {
                        System.out.println("Stack is empty! Cannot peek.");
                    }
                    break;
                case 4:
                    stack.display();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice! Please choose a valid option.");
            }
        } while (choice != 5);

        scanner.close();
    }
}
