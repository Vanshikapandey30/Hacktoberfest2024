import java.util.Arrays;

public class RadixSort {

    // Function to get the maximum element from the array
    static int getMax(int[] arr) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    // Function to perform counting sort based on a specific digit
    static void countingSort(int[] arr, int exp) {
        int n = arr.length;
        int[] output = new int[n]; // output array to store sorted numbers
        int[] count = new int[10]; // count array to store occurrences of digits

        // Initialize count array with 0
        Arrays.fill(count, 0);

        // Store count of occurrences of each digit
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        // Change count[i] so that count[i] contains the actual position of this digit in output[]
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array
        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // Copy the output array to arr[], so that arr now contains sorted numbers based on the current digit
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    // The main function to implement Radix Sort
    static void radixSort(int[] arr) {
        // Find the maximum number to know the number of digits
        int max = getMax(arr);

        // Perform counting sort for each digit. The exp is 10^i, where i is the current digit position
        for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSort(arr, exp);
        }
    }

    public static void main(String[] args) {
        int[] arr = {170, 45, 75, 90, 802, 24, 2, 66};

        System.out.println("Original Array:");
        System.out.println(Arrays.toString(arr));

        // Perform Radix Sort
        radixSort(arr);

        System.out.println("Sorted Array:");
        System.out.println(Arrays.toString(arr));
    }
}
