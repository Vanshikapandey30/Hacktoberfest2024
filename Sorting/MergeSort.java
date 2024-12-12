public class MergeSort {

    // Main method to sort an array using merge sort
    public static void mergeSort(int[] array) {
        if (array.length < 2) {
            return; // Base case: array is already sorted
        }

        int mid = array.length / 2; // Find the mid index
        int[] left = new int[mid];   // Create left subarray
        int[] right = new int[array.length - mid]; // Create right subarray

        // Fill the left and right subarrays
        for (int i = 0; i < mid; i++) {
            left[i] = array[i];
        }
        for (int i = mid; i < array.length; i++) {
            right[i - mid] = array[i];
        }

        // Recursively sort both subarrays
        mergeSort(left);
        mergeSort(right);

        // Merge the sorted subarrays
        merge(array, left, right);
    }

    // Method to merge two sorted subarrays
    private static void merge(int[] array, int[] left, int[] right) {
        int i = 0, j = 0, k = 0;

        // Merge while there are elements in both left and right arrays
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                array[k++] = left[i++];
            } else {
                array[k++] = right[j++];
            }
        }

        // Copy remaining elements from the left array, if any
        while (i < left.length) {
            array[k++] = left[i++];
        }

        // Copy remaining elements from the right array, if any
        while (j < right.length) {
            array[k++] = right[j++];
        }
    }

    // Main method for testing
    public static void main(String[] args) {
        int[] array = {38, 27, 43, 3, 9, 82, 10};
        System.out.println("Unsorted Array:");
        printArray(array);

        mergeSort(array); // Sort the array using merge sort

        System.out.println("Sorted Array:");
        printArray(array);
    }

    // Utility method to print the array
    private static void printArray(int[] array) {
        for (int value : array) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}
