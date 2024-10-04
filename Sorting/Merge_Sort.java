class Solution {
    public int[] sortArray(int[] nums) {
        mergeSort(nums, 0, nums.length - 1);

        return nums;   
    }

    static void merge(int array[], int left, int mid, int right) {
        int n = mid - left + 1;
        int m = right - mid;

        int[] L = new int[n];
        int[] R = new int[m];


        for (int i = 0; i < n; i++){
            L[i] = array[left + i];
        }
        
        for (int j = 0; j < m; j++){
            R[j] = array[mid + 1 + j];
        }
        
        int i = 0;
        int j = 0;
        int k = left;

        
        while (i < n && j < m) {
            if (L[i] <= R[j]) {
                array[k] = L[i];
                i++;
            } 
        
            else {
                array[k] = R[j];
                j++;
            }

            k++;
        }

        while (i < n) {
            array[k] = L[i];
            i++;
            k++;
        }

        while (j < m) {
            array[k] = R[j];
            j++;
            k++;
        }
    }

    static void mergeSort(int array[], int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;

            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);

            merge(array, left, mid, right);
        }
    }
}