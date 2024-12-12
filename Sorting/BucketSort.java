// BucketSort.java
import java.util.ArrayList;
import java.util.Collections;

public class BucketSort {
    public static void bucketSort(float[] array) {
        int n = array.length;
        if (n <= 0) return;

        // Create empty buckets
        ArrayList<Float>[] buckets = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            buckets[i] = new ArrayList<>();
        }

        // Distribute elements into buckets
        for (float value : array) {
            int bucketIndex = (int) (value * n); // Assuming input in range [0, 1)
            buckets[bucketIndex].add(value);
        }

        // Sort individual buckets
        for (ArrayList<Float> bucket : buckets) {
            Collections.sort(bucket);
        }

        // Concatenate buckets into the original array
        int index = 0;
        for (ArrayList<Float> bucket : buckets) {
            for (float value : bucket) {
                array[index++] = value;
            }
        }
    }

    public static void main(String[] args) {
        float[] array = {0.42f, 0.32f, 0.53f, 0.12f, 0.66f, 0.90f};
        bucketSort(array);

        System.out.print("Sorted array: ");
        for (float num : array) {
            System.out.print(num + " ");
        }
    }
}
