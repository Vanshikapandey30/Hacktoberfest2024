/**
 * The QuickSort class provides an implementation of the QuickSort algorithm.
 * QuickSort is a divide-and-conquer algorithm that sorts an array by partitioning it
 * into smaller sub-arrays based on a pivot element and recursively sorting the sub-arrays.
 * 
 * <p>This implementation includes methods for partitioning the array, performing the
 * QuickSort algorithm, and printing the array.</p>
 * 
 * <p>Usage example:</p>
 * <pre>
 * {@code
 * int[] arr = {10, 7, 8, 9, 1, 5};
 * QuickSort.quickSort(arr, 0, arr.length - 1);
 * QuickSort.printArray(arr);
 * }
 * </pre>
 * 
 * <p>Output:</p>
 * <pre>
 * Unsorted array:
 * 10 7 8 9 1 5 
 * Sorted array:
 * 1 5 7 8 9 10 
 * </pre>
 * 
 * <p>Methods:</p>
 * <ul>
 *   <li>{@code partition(int[] arr, int low, int high)}: Partitions the array around a pivot element.</li>
 *   <li>{@code quickSort(int[] arr, int low, int high)}: Recursively sorts the array using the QuickSort algorithm.</li>
 *   <li>{@code printArray(int[] arr)}: Prints the elements of the array.</li>
 * </ul>
 * 
 * <p>Note: This implementation sorts the array in-place and has a time complexity of O(n log n) on average.</p>
 * 
 * @author 
 */
public class QuickSort {

    // Method to partition the array on the basis of pivot element
    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = (low - 1); // Index of smaller element

        for (int j = low; j < high; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++;

                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Swap arr[i+1] and arr[high] (or pivot)
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    // Method to implement QuickSort
    private static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            // pi is partitioning index, arr[pi] is now at right place
            int pi = partition(arr, low, high);

            // Recursively sort elements before partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // Method to print the array
    private static void printArray(int[] arr) {
        for (int j : arr) {
            System.out.print(j + " ");
        }
        System.out.println();
    }

    // Main method to test the QuickSort algorithm
    public static void main(String[] args) {
        int[] arr = {10, 7, 8, 9, 1, 5};
        int n = arr.length;

        System.out.println("Unsorted array:");
        printArray(arr);

        quickSort(arr, 0, n - 1);

        System.out.println("Sorted array:");
        printArray(arr);
    }
}