// CycleSort.java
public class CycleSort {
    public static void cycleSort(int[] array) {
        int n = array.length;

        for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
            int item = array[cycleStart];
            int pos = cycleStart;

            for (int i = cycleStart + 1; i < n; i++) {
                if (array[i] < item) {
                    pos++;
                }
            }

            if (pos == cycleStart) continue;

            while (item == array[pos]) {
                pos++;
            }

            int temp = array[pos];
            array[pos] = item;
            item = temp;

            while (pos != cycleStart) {
                pos = cycleStart;

                for (int i = cycleStart + 1; i < n; i++) {
                    if (array[i] < item) {
                        pos++;
                    }
                }

                while (item == array[pos]) {
                    pos++;
                }

                temp = array[pos];
                array[pos] = item;
                item = temp;
            }
        }
    }

    public static void main(String[] args) {
        int[] array = {1, 8, 3, 9, 10, 10, 2, 4};
        cycleSort(array);

        System.out.print("Sorted array: ");
        for (int num : array) {
            System.out.print(num + " ");
        }
    }
}
