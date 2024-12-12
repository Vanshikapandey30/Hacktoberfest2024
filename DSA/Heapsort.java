public class HeapSort {
    
    // Function to heapify a subtree rooted with node i (non-leaf node)
    public void heapify(int arr[], int n, int i) {
        int largest = i;  // Initialize largest as root
        int left = 2 * i + 1;  // left child
        int right = 2 * i + 2; // right child

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest])
            largest = left;

        // If right child is larger than largest so far
        if (right < n && arr[right] > arr[largest])
            largest = right;

        // If largest is not root
        if (largest != i) {
            // Swap arr[i] with arr[largest]
            int swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            // Recursively heapify the affected subtree
            heapify(arr, n, largest);
        }
    }

    // Main function to perform heap sort
    public void sort(int arr[]) {
        int n = arr.length;

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        // Extract elements one by one from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root (largest element) to the end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // Call heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    // Utility function to print array
    public void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    // Driver code
    public static void main(String args[]) {
        HeapSort heapSort = new HeapSort();
        int arr[] = {12, 11, 13, 5, 6, 7};

        System.out.println("Original array:");
        heapSort.printArray(arr);

        heapSort.sort(arr);

        System.out.println("Sorted array:");
        heapSort.printArray(arr);
    }
}
