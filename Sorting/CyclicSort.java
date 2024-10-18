import java.util.*;
public class CyclicSort {
    //cyclic sort to sort the array

     public static void main(String[] args) {
        int[] arr = {3,5,1,2,4};
        cyclicSort(arr);
        System.out.println(Arrays.toString(arr));
        //cyclic sort is used for the elements in range 1 to n
}
      public static void cyclicSort(int[] arr){
        int n = arr.length;
        // first sort the index 0i.e if element at index = 0 == 1 then move to next index
        
        int i = 0;
        while(i < n){
            if(arr[i]-1 != i){
                swap(arr, i, arr[i] - 1);
            }else{
                i++;
            }
        }
}
public static void swap(int[] arr, int start, int end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

}
