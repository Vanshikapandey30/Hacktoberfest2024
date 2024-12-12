// 👉🏻Merge sort.
import java.util.Arrays; // Importing the Arrays class for easy array manipulation

public class Merge_sort {
    public static void main(String[] args) {
        // Initial array to be sorted
        int[] arr = {3, 90, 5};

        // Calling the mergeSort method and storing the sorted result
        int[] ans = mergeSort(arr);

        // Printing the sorted array
        System.out.println(Arrays.toString(ans));
    }

    // Merge sort function that sorts the input array
    public static int[] mergeSort(int[] arr) {
        // Base case-if the array has one element, it is already sorted
        if (arr.length == 1) return arr;

        // Finding the middle index to divide the array
        int mid = arr.length / 2;

        // Recursively sorting the left half of the array
        int[] left = mergeSort(Arrays.copyOfRange(arr, 0, mid));
        // Recursively sorting the right half of the array
        int[] right = mergeSort(Arrays.copyOfRange(arr, mid, arr.length));

        // Merging the two sorted halves and returning the result
        return merge(left, right);
    }

    // Function to merge two sorted arrays into a single sorted array
    public static int[] merge(int[] first, int[] second) {
        // Creating a new array to hold the merged result
        int[] mix = new int[first.length + second.length];
        int i = 0, j = 0, k = 0; // Initialize indices for first, second, and mix arrays

        // Merging the two arrays while comparing their elements
        while (i < first.length && j < second.length) {
            // Comparing elements from both arrays
            if (first[i] < second[j]) {
                // If the current element of the first array is smaller, add it to mix
                mix[k] = first[i];
                i++; // Move to the next element in the first array
            } else {
                // Otherwise, add the current element of the second array to mix
                mix[k] = second[j];
                j++; // Move to the next element in the second array
            }
            k++; // Move to the next position in the mix array
        }

        // If there are remaining elements in the first array, add them to mix
        while (i < first.length) {
            mix[k] = first[i];
            i++;
            k++;
        }

        // If there are remaining elements in the second array, add them to mix
        while (j < second.length) {
            mix[k] = second[j];
            j++;
            k++;
        }

        // Returning the merged sorted array
        return mix;
    }
}

// 👉🏻logic of the code
// -The code effectively implements the Merge Sort algorithm using recursion to divide the array and a helper function to merge the sorted sub-arrays.

// 👉🏻 Time complexity.
//The time complexity of the Merge Sort algorithm is-O(nlogn).

// 👉🏻 Space Complexity (SC)
// The space complexity of the Merge Sort algorithm is O(n).