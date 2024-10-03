
/* 
Heap Sort Algorithm
Heap Sort is another efficient, comparison-based sorting algorithm that uses a
 binary heap data structure. It works by building a max heap from the input array and repeatedly 
 extracting the largest element (the root of the heap) and placing it at the end of the array,
  reducing the size of the heap each time.




Steps of Heap Sort:
Build a Max Heap: Convert the input array into a max heap (a complete binary tree where each parent is greater than its children).
Extract Elements: Repeatedly remove the largest element (the root of the heap), swap it with the last element in the array, and then reduce the size of the heap.
Heapify: After removing the root, heapify the remaining elements to maintain the max heap property.


Time Complexity:
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n log n)

  */



#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and heapify the affected subtree
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n) {
    // Step 1: Build a max heap from the input array
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements one by one from the heap
    for (int i = n - 1; i >= 0; i--) {
        // Move the current root (largest) to the end
        swap(arr[0], arr[i]);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
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

    // Call heapSort function
    heapSort(arr, n);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

