import java.util.ArrayList;
import java.util.Collections;

public class BucketSort {

    public static void bucketSort(float[] arr, int n) {
        if (n <= 0)
            return;

        ArrayList<Float>[] buckets = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            buckets[i] = new ArrayList<Float>();
        }

        for (int i = 0; i < n; i++) {
            int bucketIndex = (int) arr[i] * n;
            buckets[bucketIndex].add(arr[i]);
        }

        for (int i = 0; i < n; i++) {
            Collections.sort(buckets[i]);
        }

        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                arr[index++] = buckets[i].get(j);
            }
        }
    }

    public static void main(String[] args) {
        float[] arr = { (float) 0.897, (float) 0.565, (float) 0.656, (float) 0.1234, (float) 0.665, (float) 0.3434 };
        int n = arr.length;
        bucketSort(arr, n);

        for (float el : arr) {
            System.out.print(el + " ");
        }
    }
}
