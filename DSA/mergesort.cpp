#include <iostream>
using namespace std;

// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right) {
    // Calculate the sizes of the two subarrays
    int n1 = mid - left + 1; // Size of the left subarray
    int n2 = right - mid;    // Size of the right subarray

    // Create temporary arrays
    int* L = new int[n1]; // Left subarray
    int* R = new int[n2]; // Right subarray

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of the first subarray
    int j = 0; // Initial index of the second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free dynamically allocated memory
    delete[] L;
    delete[] R;
}

// Function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);       // Sort left half
        mergeSort(arr, mid + 1, right);  // Sort right half

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " "; // Print each element
    cout << endl; // Move to the next line
}

// Main function
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; // Sample array
    int arrSize = sizeof(arr) / sizeof(arr[0]); // Size of the array

    cout << "Given array is: ";
    printArray(arr, arrSize); // Print the original array

    mergeSort(arr, 0, arrSize - 1); // Call merge sort

    cout << "Sorted array is: ";
    printArray(arr, arrSize); // Print the sorted array
    return 0;
}
