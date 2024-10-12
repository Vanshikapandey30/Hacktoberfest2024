import java.util.Arrays;

public class QuickSort {

    // Function to sort the array
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            // Partition the array and get the pivot index
            int pivotIndex = partition(arr, low, high);

            // Recursively sort elements before and after partition
            quickSort(arr, low, pivotIndex);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    // Hoare's Partition Scheme
    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[low]; // Choose the first element as pivot
        int i = low - 1;
        int j = high + 1;

        while (true) {
            // Find leftmost element greater than or equal to pivot
            do {
                i++;
            } while (arr[i] < pivot);

            // Find rightmost element less than or equal to pivot
            do {
                j--;
            } while (arr[j] > pivot);

            // If two pointers meet, return the partition index
            if (i >= j) {
                return j;
            }

            // Swap elements to place them on correct sides
            swap(arr, i, j);
        }
    }

    // Helper function to swap two elements
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {10, 7, 8, 9, 1, 5};
        quickSort(arr, 0, arr.length - 1);
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
