/*
TC: worst case  - O(n²)
    best case   - O(n)
    average case - O(n²)

SC: worst case  - O(1)
    best case   - O(1)
    average case - O(1)
*/

#include<iostream>
using namespace std;

void print_arr(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion_sort(int arr[], int size) {
    for(int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter elements of array: " << endl;
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Array before sorting: ";
    print_arr(arr, size);

    insertion_sort(arr, size);

    cout << "Array after sorting: ";
    print_arr(arr, size);

    return 0;
}
