public class DualPivotQuickSort {

    // Method to perform Dual-Pivot QuickSort
    public static void dualPivotQuickSort(int[] arr, int low, int high) {
        if (low < high) {
            // Partitioning the array into three parts
            int[] pivots = partition(arr, low, high);
            // Recursively sort the sub-arrays
            dualPivotQuickSort(arr, low, pivots[0] - 1);  // Left sub-array
            dualPivotQuickSort(arr, pivots[0] + 1, pivots[1] - 1); // Middle sub-array
            dualPivotQuickSort(arr, pivots[1] + 1, high); // Right sub-array
        }
    }

    // Method to partition the array around two pivots
    private static int[] partition(int[] arr, int low, int high) {
        if (arr[low] > arr[high]) {
            // Swap if the first pivot is greater than the second pivot
            swap(arr, low, high);
        }
        
        int pivot1 = arr[low];  // First pivot
        int pivot2 = arr[high]; // Second pivot

        int less = low + 1;  // Pointer for elements less than pivot1
        int great = high - 1; // Pointer for elements greater than pivot2

        for (int i = less; i <= great; i++) {
            if (arr[i] < pivot1) {
                swap(arr, i, less);
                less++;
            } else if (arr[i] > pivot2) {
                while (i < great && arr[great] > pivot2) {
                    great--;
                }
                swap(arr, i, great);
                great--;
                if (arr[i] < pivot1) {
                    swap(arr, i, less);
                    less++;
                }
            }
        }

        // Place the pivots in their correct positions
        less--;
        great++;
        swap(arr, low, less);
        swap(arr, high, great);

        return new int[]{less, great}; // Return the indices of the pivots
    }

    // Helper method to swap elements in the array
    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Main method to test the sorting
    public static void main(String[] args) {
        int[] arr = {5, 3, 8, 4, 2, 7, 1, 10, 6, 9};
        System.out.println("Original array: ");
        printArray(arr);

        dualPivotQuickSort(arr, 0, arr.length - 1);
        
        System.out.println("Sorted array: ");
        printArray(arr);
    }

    // Helper method to print the array
    private static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
