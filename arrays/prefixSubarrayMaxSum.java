package Hacktoberfest2024.arrays;

public class prefixSubarrayMaxSum {
    public static void main(String[] args) {
        int num[] = {1,-2,6,-1,3};
        prefixSum(num);

    }
    public static void prefixSum(int num[]) {
        //prefix array 
        int prefixArray[] = new int[num.length];
        prefixArray[0]=num[0];
        for (int i = 1; i < prefixArray.length; i++) {
            prefixArray[i]= prefixArray[i-1] + num[i];
        }
        int currSum = 0;
        int maxSum = Integer.MIN_VALUE;

        for (int i = 0; i < num.length; i++) {
            int start = i;
            for (int j = i; j < num.length; j++) {
                int end = j;
                currSum = start == 0 ? prefixArray[end]:prefixArray[end]-prefixArray[start - 1];
                if (maxSum < currSum) {
                    maxSum = currSum;
                }

            }
        }
        System.out.println(maxSum + " Maximum sum ");
    }
}
