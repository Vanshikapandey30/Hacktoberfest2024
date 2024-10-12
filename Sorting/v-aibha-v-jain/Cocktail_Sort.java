class Main {
    public static void cocktailSort(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        boolean swapped = true;

        while (swapped) {
            swapped = false;

            for (int i = start; i < end; i++) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swapped = true;
                }
            }

            end--;

            if (!swapped) {
                break;
            }

            for (int i = end - 1; i > start; i--) {
                if (arr[i] > arr[i + 1]) {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    swapped = true;
                }
            }

            start++;
        }
    }

    public static void main(String[] args) {
        int[] arr = {5, 1, 4, 2, 8, 0, 2};
        cocktailSort(arr);

        System.out.println("Sorted array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}