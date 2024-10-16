import java.util.Scanner;

public class HeapSort {

    // Function to heapify a subtree rooted with node i, n is the size of heap
    public void heapify(long arr[], int n, int i) {
        int largest = i; // Initialize largest as root
        int left = 2 * i + 1; // Left child
        int right = 2 * i + 2; // Right child

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If right child is larger than the largest so far
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root
        if (largest != i) {
           
            long swap = arr[i];
            arr[i] = arr[largest];
            arr[largest] = swap;

            
            heapify(arr, n, largest);
        }
    }

    // Main function to sort an array using heap sort
    public void sort(long arr[]) {
        int n = arr.length;

       
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        
        for (int i = n - 1; i > 0; i--) {
          
            long temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

           
            heapify(arr, i, 0);
        }
    }

   
    public void printArray(long arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of elements in the array:");
        int n = scanner.nextInt();

        long arr[] = new long[n];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
        }

      
        HeapSort heapSort = new HeapSort();
        heapSort.sort(arr);

        System.out.println("Sorted array is:");
        heapSort.printArray(arr);
    }
}
