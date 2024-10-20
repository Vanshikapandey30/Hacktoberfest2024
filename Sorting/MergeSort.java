class MergeSort {
    public static void merge_sort(int[] a, int lb, int ub) {
        if (lb < ub) {
            int mid = (lb + ub) / 2;
            merge_sort(a, lb, mid);
            merge_sort(a, mid + 1, ub);
            merge(a, lb, mid, ub);
        }
    }

    public static void merge(int[] a, int lb, int mid, int ub) {
        int i = lb;
        int j = mid + 1;
        int k = lb;

        int[] b = new int[a.length];
        while (i <= mid && j <= ub) {
            if (a[i] <= a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];

            if (i > mid) {
                while (j <= ub)
                    b[k++] = a[j++];
            } else if (j > ub) {
                while (i <= mid)
                    b[k++] = a[i++];
            }
        }

        for (int m = lb; m <= ub; m++) {
            a[m] = b[m];
        }

    }

    public static void main(String[] args) {
        int[] a = { 5, 10, 78, 1, 63, 25, 41, 23, 21 };

        long t1 = System.currentTimeMillis();
        Solution.merge_sort(a, 0, (a.length - 1));
        long t2 = System.currentTimeMillis();

        for (int i : a) {
            System.out.print(i + " ");
        }

        System.out.println("\nTime taken by Merge Sort is : " + (t2 - t1));
    }
}
