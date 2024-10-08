public class MergeSort {

    // Main function that sorts the array using merge sort
    public void sort(int[] array) {
        if (array.length < 2) {
            return; // Array is already sorted if it has less than 2 elements
        }
        int mid = array.length / 2; // Find the mid index
        int[] left = new int[mid]; // Create left subarray
        int[] right = new int[array.length - mid]; // Create right subarray

        // Copy elements to left subarray
        for (int i = 0; i < mid; i++) {
            left[i] = array[i];
        }
        // Copy elements to right subarray
        for (int i = mid; i < array.length; i++) {
            right[i - mid] = array[i];
        }

        // Recursively sort both halves
        sort(left);
        sort(right);

        // Merge sorted halves
        merge(array, left, right);
    }

    // Function to merge two sorted arrays
    private void merge(int[] array, int[] left, int[] right) {
        int i = 0, j = 0, k = 0;

        // Merge the left and right arrays
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                array[k++] = left[i++];
            } else {
                array[k++] = right[j++];
            }
        }

        // Copy any remaining elements from left array
        while (i < left.length) {
            array[k++] = left[i++];
        }

        // Copy any remaining elements from right array
        while (j < right.length) {
            array[k++] = right[j++];
        }
    }

    // Main method for testing the merge sort
    public static void main(String[] args) {
        MergeSort mergeSort = new MergeSort();
        int[] array = {38, 27, 43, 3, 9, 82, 10};

        System.out.println("Original Array:");
        for (int num : array) {
            System.out.print(num + " ");
        }
        System.out.println();

        mergeSort.sort(array); // Sort the array

        System.out.println("Sorted Array:");
        for (int num : array) {
            System.out.print(num + " ");
        }
    }
}
