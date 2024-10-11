import java.util.Arrays;
public class TimSort {
    static final int RUN = 32;
    public static void insertionSort(int[] arr, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int temp = arr[i];
            int j = i - 1;
            while (j >= left && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }
    public static void merge(int[] arr, int left, int mid, int right) {
        int len1 = mid - left + 1;
        int len2 = right - mid;
        int[] leftArr = new int[len1];
        int[] rightArr = new int[len2];

        System.arraycopy(arr, left, leftArr, 0, len1);
        System.arraycopy(arr, mid + 1, rightArr, 0, len2);
        int i = 0, j = 0, k = left;
        while (i < len1 && j < len2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        while (i < len1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < len2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    public static void timSort(int[] arr, int n) {
        for (int i = 0; i < n; i += RUN) {
            insertionSort(arr, i, Math.min((i + 31), (n - 1)));
        }
        for (int size = RUN; size < n; size = 2 * size) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = left + size - 1;
                int right = Math.min((left + 2 * size - 1), (n - 1));
                if (mid < right) {
                    merge(arr, left, mid, right);
                }
            }
        }
    }
    public static void main(String[] args) {
        int[] arr = {5, 21, 7, 23, 19, 8, 30, 12, 3, 15, 2, 1, 16, 10};
        System.out.println("Original Array:");
        System.out.println(Arrays.toString(arr));
        int n = arr.length;
        timSort(arr, n);
        System.out.println("Sorted Array using TimSort:");
        System.out.println(Arrays.toString(arr));
    }
}
