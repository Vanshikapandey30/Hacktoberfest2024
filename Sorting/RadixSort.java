// Radix Sort in Java
public class RadixSort {
    // Using counting sort to sort the elements based on significant places
    public static void countingSort(int[] array, int place) {
        int size = array.length;
        int[] output = new int[size];
        int[] count = new int[10];
        
        // Calculate count of elements
        for (int i = 0; i < size; i++) {
            int index = (array[i] / place) % 10;
            count[index]++;
        }
        // Calculate cumulative count
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        // Place the elements in sorted order
        for (int i = size - 1; i >= 0; i--) {
            int index = (array[i] / place) % 10;
            output[count[index] - 1] = array[i];
            count[index]--;
        }
        // Copy the sorted elements into original array
        for (int i = 0; i < size; i++) {
            array[i] = output[i];
        }
    }
    // Main function to implement radix sort
    public static void radixSort(int[] array) {
        // Get maximum element
        int maxElement = getMax(array);
        // Apply counting sort to sort elements based on place value
        for (int place = 1; maxElement / place > 0; place *= 10) {
            countingSort(array, place);
        }
    }
    // A utility function to get the maximum value in the array
    public static int getMax(int[] array) {
        int max = array[0];
        for (int i = 1; i < array.length; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }
        return max;
    }
    public static void main(String[] args) {
        int[] data = {121, 432, 564, 23, 1, 45, 788};
        radixSort(data);
        System.out.println("Sorted Array in Ascending Order: ");
        for (int num : data) {
            System.out.print(num + " ");
        }
    }
}
