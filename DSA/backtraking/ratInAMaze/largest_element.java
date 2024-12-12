public class FindLargest {
    public static void main(String[] args) {
        int[] arr = {10, 5, 20, 8, 2}; // Example array
        int max = arr[0]; // Initialize the max with the first element of the array

        // Loop through the array
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i]; // Update max if current element is greater
            }
        }

        // Print the largest element
        System.out.println("The largest element is: " + max);
    }
}