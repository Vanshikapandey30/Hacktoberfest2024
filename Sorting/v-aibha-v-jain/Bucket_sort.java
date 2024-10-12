import java.util.ArrayList;
import java.util.List;

class Main {
    public static void bucketSort(float[] arr) {
        int n = arr.length;

        // Determine the maximum value in the array
        float max = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        // Create buckets based on the range of values
        int bucketSize = (int) (n / max);
        List<Float>[] buckets = new ArrayList[bucketSize];
        for (int i = 0; i < bucketSize; i++) {
            buckets[i] = new ArrayList<>();
        }

        // Distribute elements into buckets
        for (int i = 0; i < n; i++) {
            int bucketIndex = (int) (arr[i] * bucketSize);
            buckets[bucketIndex].add(arr[i]);
        }

        // Sort individual buckets using a stable sorting algorithm (e.g., insertion sort)
        for (int i = 0; i < bucketSize; i++) {
            buckets[i].sort(Float::compareTo);
        }

        // Merge sorted buckets back into the original array
        int index = 0;
        for (int i = 0; i < bucketSize; i++) {
            for (float num : buckets[i]) {
                arr[index++] = num;
            }
        }
    }

    public static void main(String[] args) {
        float[] arr = {0.897f, 0.565f, 0.656f, 0.1234f, 0.665f, 0.3434f};
        bucketSort(arr);

        System.out.println("Sorted array is:");
        for (float num : arr) {
            System.out.print(num + " ");
        }
    }
}