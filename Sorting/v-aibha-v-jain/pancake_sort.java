import java.io.*;

class Main {

    // Flips the subarray `arr[0..i]` (inclusive)
    static void flip(int[] arr, int i) {
        int temp, start = 0;
        while (start < i) {
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
            start++;
            i--;
        }
    }

    // Finds the index of the maximum element in the subarray `arr[0..n-1]`
    static int findMax(int[] arr, int n) {
        int mi = 0, i; // Initialize mi to 0 and iterate through elements
        for (i = 0; i < n; ++i) {
            if (arr[i] > arr[mi]) {
                mi = i; // Update mi if a larger element is found
            }
        }
        return mi;
    }

    // Sorts the given array using pancake sort
    static void pancakeSort(int[] arr, int n) {
        // Start from the complete array and reduce the current size by 1 in each iteration
        for (int curr_size = n; curr_size > 1; curr_size--) {
            // Find the index of the maximum element in the current subarray
            int mi = findMax(arr, curr_size);

            // Move the maximum element to the end of the current subarray
            // if it's not already at the end
            if (mi != curr_size - 1) {
                // First move the maximum element to the beginning
                flip(arr, mi);

                // Now move the maximum element to the end by reversing the current subarray
                flip(arr, curr_size - 1);
            }
        }
    }

    // Utility function to print the array `arr[]`
    static void printArray(int[] arr, int arr_size) {
        for (int i = 0; i < arr_size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println("");
    }

    // Driver function
    public static void main(String[] args) {
        int[] arr = {23, 10, 20, 11, 12, 6, 7};
        int n = arr.length;

        pancakeSort(arr, n);

        System.out.println("Sorted Array: ");
        printArray(arr, n);
    }
}