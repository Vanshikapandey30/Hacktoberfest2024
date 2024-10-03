/*
TC: worst case - O(n log n)
    best case  - O(n log n)
    average case - O(n log n)

SC: worst case - O(n)
    best case  - O(n)
    average case - O(n)
*/

#include<iostream>
using namespace std;

void print_arr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[],int l,int m,int r){
    
    int n1 = m - l + 1;
        int n2 = r - m;

        // Temporary arrays
        int a1[n1], a2[n2];

        for (int i = 0; i < n1; i++)
            a1[i] = arr[l + i];
        for (int i = 0; i < n2; i++)
            a2[i] = arr[m + 1 + i];

    
        int i = 0, j = 0, index = l;
        while (i < n1 && j < n2) {
            if (a1[i] <= a2[j]) {
                arr[index] = a1[i];
                i++;
            } else {
                arr[index] = a2[j];
                j++;
            }
            index++;
        }

        while (i < n1) {
            arr[index] = a1[i];
            i++;
            index++;
        }
        while (j < n2) {
            arr[index] = a2[j];
            j++;
            index++;
        }
}

void merge_sort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;

        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
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

    merge_sort(arr,0,size-1);

    cout<<"Array after sorting : ";
    print_arr(arr,size);

    return 0;
}