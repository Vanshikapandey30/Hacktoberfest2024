package Searching;
import java.util.Arrays;

public class BinarySearch {
    public static int binarySearch(int[] arr, int key) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if key is present at mid
            if (arr[mid] == key)
                return mid;

            // If key greater, ignore left half
            if (arr[mid] < key)
                left = mid + 1;

            // If key is smaller, ignore right half
            else
                right = mid - 1;
        }
        return -1; // Element not found
    }

    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 10, 40};
        Arrays.sort(arr);  // Ensure array is sorted before using binary search
        int key = 10;
        int result = binarySearch(arr, key);
        if (result == -1) {
            System.out.println("Element not found");
        } else {
            System.out.println("Element found at index: " + result);
        }
    }
}
