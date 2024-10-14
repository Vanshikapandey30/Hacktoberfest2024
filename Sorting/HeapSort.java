import java.util.Scanner;

public class HeapSort {

    // Main function to perform heap sort
    public void sort(int arr[]) {
        int n = arr.length;

        // Step 1: Build a max heap from the input array.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Step 2: Extract elements from the heap one by one.
        for (int i = n - 1; i > 0; i--) {
            // Move the current root (largest) to the end of the array.
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Call heapify on the reduced heap.
            heapify(arr, i, 0);
        }
    }

    // Helper function to heapify a subtree rooted at node i.
    void heapify(int arr[], int n, int i) {
        int largest = i;  // Initialize largest as the root
        int left = 2 * i + 1;  // Left child index
        int right = 2 * i + 2; // Right child index

        // If the left child is larger than the root
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If the right child is larger than the current largest
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If the largest is not the root, swap them
        if (largest != i) {
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            // Recursively heapify the affected subtree
            heapify(arr, n, largest);
        }
    }

    // Utility function to print the array
    static void printArray(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    // Main method to take input and test the Heap Sort algorithm
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        // Take array size input
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();

        // Initialize the array
        int arr[] = new int[n];

        // Take array input
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        // Display the original array
        System.out.println("Original array:");
        printArray(arr);

        // Perform heap sort
        HeapSort heapSort = new HeapSort();
        heapSort.sort(arr);

        // Display the sorted array
        System.out.println("Sorted array:");
        printArray(arr);

        // Close the scanner
        scanner.close();
    }
}
