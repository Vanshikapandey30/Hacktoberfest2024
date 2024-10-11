// Quick Sort 
// Time Complexity : O(n^2)
// Steps involved -> 
// 1) Select an element (typically the last one) as the pivot.
// 2) Reorder the array so that elements smaller than the pivot are on the left, and larger elements are on the right.
// 3) Place the pivot in its correct position between the smaller and larger elements.
// 4) Recursively apply Quick Sort on the left and right sub-arrays.
// 5) Stop when sub-arrays have 1 or 0 elements.
// 6) The array becomes sorted when all sub-arrays are processed.


public class Quick_Sort {

    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    static int partition(int[] arr, int low, int high) {
        int pivot = arr[high]; 
        int i = (low - 1); 

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        return i + 1;
    }

    public static void main(String[] args) {
        int[] arr = {64, 25, 12, 22, 11};
        int n = arr.length;

        quickSort(arr, 0, n - 1);

        System.out.println("Sorted array: ");
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}