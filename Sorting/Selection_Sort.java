//Selection Sort repeatedly finds the minimum element and moves it to the beginning of the list.
//Time Complexity: O(n²)

// Selection Sort algorithm:

// Divide the list into two parts:

// The sorted part (initially empty).
// The unsorted part (the entire array at first).
// Find the minimum element:

// From the unsorted part, identify the smallest element.
// Swap:

// Swap the smallest element with the first element of the unsorted part.
// Move boundary:

// The first element of the unsorted part becomes part of the sorted portion.
// Repeat:

// Repeat steps 2-4 for the remaining unsorted part until the entire array is sorted.
// The process continues until all elements are sorted in ascending order.

//Code
public class Selection_Sort {
    static void selectionSort(int[] array) {
        int length = array.length;
        for (int index = 0; index < length - 1; index++) {
            int mininumIndex = index;
            for (int subIndex = index + 1; subIndex < length; subIndex++) {
                if (array[subIndex] < array[mininumIndex]) {
                    minimumIndex = subIndex;
                }
            }
            // Swap the found minimum element with the first element
            int temp = array[minimumIndex];
            array[minimumIndex] = array[index];
            array[index] = temp;
        }
    }

    public static void main(String[] args) {
        int[] array = {64, 25, 12, 22, 11};
        selectionSort(array);
        System.out.println("Sorted array: ");
        for (int index : array) {
            System.out.print(index + " ");
        }
    }
}
