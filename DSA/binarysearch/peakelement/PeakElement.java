package DSA.binarysearch.peakelement;

/**
 * Peak element is defined as the element greater than both of its neighbors
 * 'a[i]' is the peak element, only if 'a[i - 1]' < 'a[i]' and 'a[i + 1]' < 'a[i]'.
 * a[-1] = a[n] = -infinite
 * if there are many peak elements return anyone of the peak element index.
 */
public class PeakElement {
    public static void main(String[] args) {
        int[] arr = {1, 2, 1, 3, 5, 6, 4};
        int index = findPeakElementIndex(arr);
        System.out.println(index);
    }

    private static int findPeakElementIndex(int[] arr) {
        int size = arr.length;
        if (size == 1) return 0;
        int low = 0;
        int high = size - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == 0) {
                if (arr[mid] > arr[mid + 1]) return mid;
                else low = mid + 1;
            }
            if (mid == size - 1) {
                if (arr[mid - 1] < arr[mid]) return mid;
                else high = mid - 1;
            }
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            // say arr is [1,2,3], here there is a high possibility
            // in getting the peak ele if we move right(as we know nth element is -infinite).
            // Hence, moving to low pointer based on the above condition
            else if (arr[mid - 1] <= arr[mid] && arr[mid] <= arr[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
}
