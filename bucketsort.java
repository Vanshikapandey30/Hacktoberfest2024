import java.util.*;

public class BucketSort {

    // Function to perform bucket sort
    public static void bucketSort(float[] arr, int n) {
        if (n <= 0)
            return;

        // 1. Create empty buckets
        @SuppressWarnings("unchecked")
        ArrayList<Float>[] buckets = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            buckets[i] = new ArrayList<Float>();
        }

        // 2. Add elements into different buckets
        for (int i = 0; i < n; i++) {
            int bucketIndex = (int) arr[i] * n;  // Find the bucket index
            buckets[bucketIndex].add(arr[i]);
        }

        // 3. Sort individual buckets using Collections.sort
        for (int i = 0; i < n; i++) {
            Collections.sort(buckets[i]);
        }

        // 4. Concatenate all buckets into the original array
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                arr[index++] = buckets[i].get(j);
            }
        }
    }

    // Main function to test the Bucket Sort
    public static void main(String[] args) {
        float[] arr = {0.897f, 0.565f, 0.656f, 0.1234f, 0.665f, 0.3434f};
        int n = arr.length;

        System.out.println("Original array:");
        for (float num : arr) {
            System.out.print(num + " ");
        }

        bucketSort(arr, n);

        System.out.println("\nSorted array:");
        for (float num : arr) {
            System.out.print(num + " ");
        }
    }
}
