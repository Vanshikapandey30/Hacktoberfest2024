import java.util.Scanner;

public class ShellSort {
    // Function to perform Shell Sort
    public static void shellSort(int[] arr) {
        int n = arr.length;

        // Start with a large gap, then reduce the gap
        for (int gap = n / 2; gap > 0; gap /= 2) {
            // Perform gapped insertion sort for this gap size
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;

                // Shift elements of the array to their correct position
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }

                // Place the temp (current element) at its correct position
                arr[j] = temp;
            }
        }
    }

    // Helper function to print the array
    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Getting array size from user
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();

        // Creating the array
        int[] arr = new int[n];

        // Getting array elements from user
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        // Display the array before sorting
        System.out.println("Array before sorting:");
        printArray(arr);

        // Perform Shell Sort
        shellSort(arr);

        // Display the array after sorting
        System.out.println("Array after sorting:");
        printArray(arr);

        scanner.close();
    }
}
