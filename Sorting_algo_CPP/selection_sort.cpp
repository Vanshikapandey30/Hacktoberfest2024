/*
TC: worst case  - O(n²)
    best case   - O(n²)
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

void selection_sort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            swap(arr[min_idx], arr[i]);
        }
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

    selection_sort(arr, size);

    cout << "Array after sorting: ";
    print_arr(arr, size);

    return 0;
}
