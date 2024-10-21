// Problem Statement: We have an array arr of non-negative integers. arr is considered special if there exists a number x such that there are exactly x numbers in arr that are greater than or equal to x.
// Notice that x does not have to be an element in arr.Return x if the array is special; otherwise, return -1. It can be proven that if arr is special, the value for x is unique.

// Input: arr = [3,5]
// Output: 2


import java.util.Arrays;
import java.util.Scanner;

public class Specialarray {

    public static int specialarray(int[] arr, int n) {
        Arrays.sort(arr);

        int st = 1; 
        int end = n; 

        while (st <= end) {
            
            int mid = st + (end - st) / 2; 
            int cnt = 0; 

            for (int i = 0; i < n; i++) {
                if (arr[i] >= mid) {
                    cnt++;
                }
            }

            if (mid == cnt) {
                return mid; 
            } else if (mid > cnt) {
                end = mid - 1; 
            } else {
                st = mid + 1; 
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println(specialarray(arr, n));
    }
}
