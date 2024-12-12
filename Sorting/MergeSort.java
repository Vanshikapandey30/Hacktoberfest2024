public class MergeSort {

    // Main function that sorts the array using mergeSort
    public static void mergeSort(int[] array, int left, int right) {
        // If left index is smaller than right, proceed with sorting
        if (left < right) {
            // Find the middle point to divide the array into two halves
            int mid = (left + right) / 2;

            // Recursively sort the first and second halves
            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);

            // Merge the sorted halves
            merge(array, left, mid, right);
        }
    }

    // Function to merge two subarrays: array[left..mid] and array[mid+1..right]
    public static void merge(int[] array, int left, int mid, int right) {
        // Sizes of the two subarrays to be merged
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary arrays to hold the subarrays
        int[] leftArray = new int[n1];
        int[] rightArray = new int[n2];

        // Copy the data into the temporary arrays
        for (int i = 0; i < n1; i++)
            leftArray[i] = array[left + i];
        for (int j = 0; j < n2; j++)
            rightArray[j] = array[mid + 1 + j];

        // Initial indexes for the left, right, and merged subarrays
        int i = 0, j = 0;
        int k = left; // Starting index for the merged subarray

        // Merge the arrays back into the original array
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                array[k] = leftArray[i];
                i++;
            } else {
                array[k] = rightArray[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of leftArray, if any
        while (i < n1) {
            array[k] = leftArray[i];
            i++;
            k++;
        }

        // Copy the remaining elements of rightArray, if any
        while (j < n2) {
            array[k] = rightArray[j];
            j++;
            k++;
        }
    }

    // Helper function to print the array
    public static void printArray(int[] array) {
        for (int element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Example array to be sorted
        int[] array = {12, 11, 13, 5, 6, 7};

        System.out.println("Given Array:");
        printArray(array);

        // Call the mergeSort function
        mergeSort(array, 0, array.length - 1);

        System.out.println("\nSorted Array:");
        printArray(array);
    }
}
