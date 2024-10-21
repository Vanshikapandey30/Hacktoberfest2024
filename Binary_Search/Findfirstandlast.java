// Problem Statement: Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].

// Input: nums = [5,7,7,8,8,10], target = 7
// Output: [1,2]


import java.util.Arrays;
import java.util.Scanner;

public class Findfirstandlast {

    public static int[] findFirstandLast(int[] nums, int target) {
        int[] arr = new int[2];
        arr[0] = -1; 
        arr[1] = -1; 

        if (nums.length == 0) {
            return arr;
        }

        int i = 0;
        int j = nums.length - 1; 

        while (i <= j) {
            int mid = (i + j) / 2; 

            if (nums[mid] == target) {
                arr[1] = mid; 
                i = mid + 1; 
            } else if (nums[mid] < target) {
                i = mid + 1; 
            } else {
                j = mid - 1; 
            }
        }

        i = 0; 
        j = nums.length - 1;

        while (i <= j) {
            int mid = (i + j) / 2; 

            if (nums[mid] == target) {
                arr[0] = mid; 
                j = mid - 1; 
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1; 
            }
        }

        return arr;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int target = sc.nextInt();

        int[] answer = findFirstandLast(arr, target);
        
        for (int i : answer) {
            System.out.print(i + " ");
        }
    }
}
