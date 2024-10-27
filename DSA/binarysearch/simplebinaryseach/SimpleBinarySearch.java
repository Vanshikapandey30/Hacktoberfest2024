package DSA.binarysearch.simplebinaryseach;

// If array is sorted then binary search rescues in reducing the Time complexity
public class SimpleBinarySearch {
    public static void main(String[] args) {
        int[] arr = {11, 12, 13, 14, 15, 16, 17, 18, 19};
        int index = findIndexOfElement(arr, 14);
        System.out.println(index);
    }

    private static int findIndexOfElement(int[] arr, int ele) {
        int low = 0;
        int high = arr.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2; // To handle overflow
            if (arr[mid] == ele) return mid; // return if element is found

            // update low to mid+1 if mid is lesser than element
            else if (arr[mid] < ele) low = mid + 1;

            // update high to mid-1 if mid is greater than element
            else high = mid - 1;
        }
        return -1;
    }
}
