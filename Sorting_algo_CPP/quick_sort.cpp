/*
TC: worst case  - O(n²)
    best case   - O(n log n)
    average case - O(n log n)

SC: worst case  - O(log n) (due to recursion stack in the best partitioning)
    best case   - O(log n)
    average case - O(log n)
*/

#include<iostream>
using namespace std;

void print_arr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quick_sort(int arr[],int low,int high){
    if(low<high){
        int pivot=partition(arr,low,high);
        quick_sort(arr,low,pivot-1);
        quick_sort(arr,pivot+1,high);
    }
}

int main(){
    int size;
    cout<<"Enter size of array : ";
    cin>>size;

    int arr[size];
    cout<<"Enter elements of array : "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"Array before sorting : ";
    print_arr(arr,size);

    quick_sort(arr,0,size-1);

    cout<<"Array after sorting : ";
    print_arr(arr,size);

    return 0;
}