// Algorithm of Selection sort.

#include<iostream>
using namespace std;

void printSortArr(int arr[],int size){
    cout<<"Array after Sorting: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void sort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int minIndex=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex]){
                minIndex =j; 
            }
        }
        swap(arr[minIndex],arr[i]);
       
    }
   
}

int main(){
    int size,i=0;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of array: ";
    for(i=0;i<size;i++){
        cin>>arr[i];
    }

    sort(arr,size);
    printSortArr(arr,size);
    
    return 0;
}