import java.util.ArrayList;
import java.util.List;

class Main {
    public static void shellSort(int[] arr) {
        int n = arr.length;

        // Knuth sequence for gaps
        List<Integer> gaps = new ArrayList<>();
        int gap = 1;
        while (gap < n / 3) {
            gaps.add(gap);
            gap = 3 * gap + 1;
        }

        // Iterate over gaps in descending order
        for (int i = gaps.size() - 1; i >= 0; i--) {
            int h = gaps.get(i);

            // Insertion sort for each gap
            for (int j = h; j < n; j++) {
                int temp = arr[j];
                int k = j;
                while (k >= h && arr[k - h] > temp) {
                    arr[k] = arr[k - h];
                    k -= h;
                }
                arr[k] = temp;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {12, 34, 54, 2, 3};
        System.out.println("Array before sorting:");
        printArray(arr);

        shellSort(arr);

        System.out.println("Array after sorting:");
        printArray(arr);
    }

    private static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}