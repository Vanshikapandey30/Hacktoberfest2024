import java.util.Scanner;

public class QuickSort {

    // Function to perform the quicksort
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            // Find the partition index
            int partitionIndex = partition(arr, low, high);

            // Recursively sort elements before and after the partition
            quickSort(arr, low, partitionIndex - 1); // Left side of the pivot
            quickSort(arr, partitionIndex + 1, high); // Right side of the pivot
        }
    }

    // Partition function to place the pivot at the correct position
    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high]; // Choosing the last element as the pivot
        int i = low - 1; // Index of the smaller element

        // Iterate through the array and rearrange elements
        for (int j = low; j < high; j++) {
            // If the current element is smaller than or equal to the pivot
            if (arr[j] <= pivot) {
                i++; // Increment index of the smaller element
                swap(arr, i, j); // Swap current element with the smaller element
            }
        }

        // Place the pivot in the correct position
        swap(arr, i + 1, high);

        return i + 1; // Return the partition index
    }

    // Helper function to swap two elements in the array
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Main function to take input and run quicksort
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking input for the size of the array
        System.out.println("Enter the number of elements:");
        int n = scanner.nextInt();

        // Taking input for the array elements
        int[] arr = new int[n];
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        // Display original array
        System.out.println("Original array:");
        printArray(arr);

        // Perform quicksort
        quickSort(arr, 0, n - 1);

        // Display sorted array
        System.out.println("Sorted array:");
        printArray(arr);

        scanner.close();
    }

    // Function to print the array
    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
