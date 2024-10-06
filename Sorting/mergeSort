// TC : O(nlogn) SC : O(n)
public class MergeSort {
    public static void mergeSort(int arr[], int si, int ei){
        if(si>=ei) return;
        int mid = si + (ei-si)/2;
        mergeSort(arr, si, mid);
        mergeSort(arr, mid+1, ei);

        merge(arr, si, mid, ei);
    }

    //merge method to merge the sorted parts
    public static void merge(int arr[], int si, int mid, int ei){
        int temp[] = new int[ei-si+1];
        int i = si; // index / iterator for 1st sorted part
        int j = mid+1; //index for 2nd sorted part
        int k = 0; //index for temp

        while(i <= mid && j <= ei){
            if(arr[i] < arr[j]){
                temp[k] = arr[i];
                i++;
            }
            else{
                temp[k] = arr[j];
                j++;
            }
            k++;
        }

        //for leftover elements of 1st sorted part
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        while(j <= ei){
            temp[k++] = arr[j++];
        }

        //copy temp to original array
        for(k = 0, i = si; k<temp.length; k++, i++){
            arr[i] = temp[k];
        }
    }
    public static void printArray(int []arr){
        for(int i = 0; i<arr.length;i++){
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        int arr[] = {6,3,9,5,2,8};
        mergeSort(arr, 0, 5);
        printArray(arr);
    }
}
