public class MergeSort {

    // Merge sort function
    public static void mergeSort(int[] arr, int lb, int up) {
        if (lb < up) {
            int mid = (lb + up) / 2;
            // Recursively sort first and second halves
            mergeSort(arr, lb, mid);
            mergeSort(arr, mid + 1, up);
            // Merge the sorted halves
            merge(arr, lb, mid, up);
        }
    }

    // Function to merge the sub-arrays
    public static void merge(int[] arr, int lb, int mid, int up) {
        int[] temp = new int[up - lb + 1];  // Temporary array for sorted sub-array
        int i = lb, j = mid + 1, k = 0;

        // Compare elements from both sub-arrays and merge
        while (i <= mid && j <= up) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        // Copy remaining elements from the left sub-array, if any
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements from the right sub-array, if any
        while (j <= up) {
            temp[k++] = arr[j++];
        }

        // Copy the sorted sub-array back into the original array
        for (i = lb, k = 0; i <= up; i++, k++) {
            arr[i] = temp[k];
        }
    }

    // Function to print the array
    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr = {15, 5, 24, 8, 1, 3, 16, 10, 20};
        
        System.out.println("Given array:");
        printArray(arr);

        // Calling merge sort
        mergeSort(arr, 0, arr.length - 1);

        System.out.println("\nSorted array:");
        printArray(arr);
    }
}
