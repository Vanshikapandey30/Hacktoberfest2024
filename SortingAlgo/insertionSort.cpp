// Algorithm of Inserion Sort.

#include<iostream>
using namespace std;

void printSortedArray(int arr[], int n){
    cout << "Array after sorting: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] <<" ";
    }
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j;
        for( j = i-1; j >= 0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                // if previous element is greater then  
                break;
            }
        }
        arr[j+1] = temp;

    }
    printSortedArray(arr, n);
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    insertionSort(arr, n);
}