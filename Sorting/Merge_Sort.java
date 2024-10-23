/*
Merge Sort is a divide-and-conquer algorithm that recursively splits an array into two halves, sorts them, and then merges the sorted halves.

Time Complexity: O(n log n) in all cases (best, average, and worst)
Space Complexity: O(n) due to the auxiliary arrays used for merging.
 */
import java.util.*;
public class Merge_Sort {
    public static void merge(int arr[],int low,int mid,int high){
    
        ArrayList<Integer> temp=new ArrayList<>();
        int p1=low;
        mid=(low+high)/2;
        int p2=mid+1;
       // base case
        if(low==high){
            return;
        }
        while(p1<=mid && p2<=high){
            if(arr[p1]<=arr[high]){
                temp.add(arr[p1]);
                p1++;
            }
            else{
                temp.add(arr[p2]);
                p2++;
            }
        }
        while(p1<=mid){
            temp.add(arr[p1]);
            p1++;
        }
        while(p2<=high){
            temp.add(arr[p2]);
            p2++;
        }
        // putting back to arr[i]
        for(int i=low;i<=high;i++){
            arr[i]=temp.get(i-low);   

        }

    }
    public static void mergesort(int arr[],int low,int high){
        int mid=(low+high)/2;

        //base case
        if(low==high){
            return;
        }
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);


    }
    public static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
    public static void main(String args[]){
        int[] arr = { 12, 11, 13, 5, 6, 7 };

        System.out.println("Given Array:");
        printArray(arr);

        mergesort(arr, 0, arr.length - 1);

        System.out.println("\nSorted Array:");
        printArray(arr);
    }
}
