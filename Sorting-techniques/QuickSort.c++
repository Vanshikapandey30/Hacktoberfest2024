
/* 

Quick Sort is another efficient, divide-and-conquer sorting algorithm, but it works differently
compared to Merge Sort. While Merge Sort divides the array into two halves and then merges them,
Quick Sort partitions the array based on a "pivot" element and sorts the partitions in place. 
Quick Sort tends to perform better than Merge Sort in practice due to better cache usage and 
typically fewer comparisons.

Quick Sort Algorithm
Quick Sort works by selecting a "pivot" element and partitioning the array into two subarrays:

One subarray with elements less than or equal to the pivot.
One subarray with elements greater than the pivot.
It then recursively sorts the subarrays. This process is repeated until the entire array is sorted.

Steps of Quick Sort:
Choose a Pivot: Select an element from the array as the pivot (commonly the first, last, or middle element).
Partition: Rearrange the array so that elements smaller than the pivot are on the left and elements greater than the pivot are on the right.
Recursive Sort: Recursively apply the same steps to the left and right subarrays.

Example:
For the array [10, 80, 30, 90, 40, 50, 70]

step 1 Choose 70 as the pivot.

step 2 Elements less than 70 go to the left: [10, 30, 40, 50]
Elements greater than 70 go to the right: [80, 90]
Now the array becomes: [10, 30, 40, 50, 70, 80, 90]


step 3 
Recursively apply Quick Sort on the left ([10, 30, 40, 50]) and right ([80, 90]) subarrays.


Time Complexity:
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n^2)

*/



#include <iostream>
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment the index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    // Swap the pivot element with the element at index i+1
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return the partitioning index
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // Call quickSort function
    quickSort(arr, 0, n - 1);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


