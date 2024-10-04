// Algorithm of Bubble Sorting.

#include<iostream>
using namespace std;

void printSortedArr(int arr[], int size){
    cout << "Array after bubble sorting: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] <<" ";
    }
}

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        bool swapped = false;

        for(int j = 0; j < size-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
    printSortedArr(arr, size);
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

    bubbleSort(arr, n);
    return 0;
}