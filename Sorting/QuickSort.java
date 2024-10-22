public class QuickSort {
    
     
    private static int partition(int[] arr, int low, int high) {
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
    
    // Method to implement QuickSort
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    // Utility method to print the array
    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    // Main method to test  
    public static void main(String[] args) {
        int[] arr = {10, 7, 8, 9, 1, 5};
        int n = arr.length;
        
        System.out.println("Unsorted array:");
        printArray(arr);
        
        quickSort(arr, 0, n - 1);
        
        System.out.println("Sorted array:");
        printArray(arr);
    }
}

