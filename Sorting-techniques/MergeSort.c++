
/* 
Merge Sort Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.

Merge Sort Algorithm
Merge Sort is a divide-and-conquer sorting algorithm. It divides the input array into two halves,
 recursively sorts each half, and then merges the two sorted halves to produce a single sorted array. 
Merge Sort is efficient with large datasets and guarantees a time complexity of O(n log n).


Steps of Merge Sort:
Divide: Divide the array into two halves until each subarray contains only one element (a single element is considered sorted).
Conquer: Recursively sort the two halves.
Merge: Combine the two sorted halves to produce a single sorted array



Example:
For an array [38, 27, 43, 3, 9, 82, 10], merge sort works as follows:

Divide: The array is split into two halves:

Left half: [38, 27, 43]
Right half: [3, 9, 82, 10]
Further Divide:

Left half [38, 27, 43] becomes [38] and [27, 43]
Right half [3, 9, 82, 10] becomes [3, 9] and [82, 10]
Recursively Sort: The array is split until each subarray has one element.

Merge:

Merge [27, 43] → [27, 38, 43]
Merge [3, 9] → [3, 9, 10, 82]
Finally, merge [27, 38, 43] with [3, 9, 10, 82] to get the sorted array: [3, 9, 10, 27, 38, 43, 82].


Time Complexity:
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n log n)



*/





#include <iostream>
using namespace std;

// Merge two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int left[n1], right[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[m + 1 + i];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// l is the starting index, r is the ending index of the array to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main() {
    // Input array
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call mergeSort function
    mergeSort(arr, 0, n - 1);

    // Output sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
