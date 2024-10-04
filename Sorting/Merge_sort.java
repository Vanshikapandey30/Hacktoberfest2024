import java.util.Arrays;

public class MergeSort {

    // Merge two subarrays L and R into arr
    public static void merge(int[] arr, int[] L, int[] R) {
        int i = 0, j = 0, k = 0;
        int nL = L.length, nR = R.length;
        
        // Merge the two arrays into one
        while (i < nL && j < nR) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        // Copy remaining elements of L[], if any
        while (i < nL) {
            arr[k++] = L[i++];
        }

        // Copy remaining elements of R[], if any
        while (j < nR) {
            arr[k++] = R[j++];
        }
    }

    // Recursively divide the array and sort using merge sort
    public static void mergeSort(int[] arr) {
        int n = arr.length;
        if (n < 2) {
            return; // Base case: an array of size 1 is already sorted
        }

        // Divide the array into two halves
        int mid = n / 2;
        int[] L = new int[mid];
        int[] R = new int[n - mid];

        // Copy data to temporary arrays L[] and R[]
        for (int i = 0; i < mid; i++) {
            L[i] = arr[i];
        }
        for (int i = mid; i < n; i++) {
            R[i - mid] = arr[i];
        }

        // Sort the two halves
        mergeSort(L);
        mergeSort(R);

        // Merge the sorted halves
        merge(arr, L, R);
    }

    public static void main(String[] args) {
        // Example array
        int[] arr = {38, 27, 43, 3, 9, 82, 10};

        System.out.println("Original Array: " + Arrays.toString(arr));

        // Call merge sort
        mergeSort(arr);

        System.out.println("Sorted Array: " + Arrays.toString(arr));
    }
}
