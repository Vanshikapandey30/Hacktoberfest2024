import java.util.*;

class Main {
    public static void pigeonhole_sort(int[] arr, int n) {
        int min = arr[0];
        int max = arr[0];

        // Find the minimum and maximum values dynamically
        for (int i = 1; i < n; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        int range = max - min + 1;
        int[] phole = new int[range];
        Arrays.fill(phole, 0);

        // Count occurrences of each element
        for (int i = 0; i < n; i++) {
            phole[arr[i] - min]++;
        }

        // Fill the sorted array, skipping empty buckets
        int index = 0;
        for (int j = 0; j < range; j++) {
            while (phole[j]-- > 0) {
                arr[index++] = j + min;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {8, 3, 2, 7, 4, 6, 8};

        System.out.print("Sorted order is: ");

        pigeonhole_sort(arr, arr.length);

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}