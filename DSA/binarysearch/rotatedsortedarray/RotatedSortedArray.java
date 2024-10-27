package DSA.binarysearch.rotatedsortedarray;

/**
 * Array can have duplicate values and it is a rotated array.
 */
public class RotatedSortedArray {
    public static void main(String[] args) {
        int[] arr = {14, 15, 15, 16, 11, 11, 12, 12, 12, 13};
        boolean isExists = isElementExists(arr, 16);
        System.out.println(isExists);
        int[] arr1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
        boolean isExists1 = isElementExists(arr1, 2);
        System.out.println(isExists1);

    }

    private static boolean isElementExists(int[] arr, int ele) {
        int low = 0;
        int high = arr.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == ele) return true;
            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low += 1;
                high -= 1;
                continue;
            }
            // check whether left array is sorted or right is sorted and then move low, high pointers
            if (arr[mid] <= arr[high]) {
                if (arr[mid] < ele && ele <= arr[high]) low = mid + 1;
                else high = mid - 1;
            } else {
                if (arr[low] <= ele && ele < arr[mid]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return false;
    }
}
