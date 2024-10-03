/* 
Insertion Sort 
Insertion Sort is a simple and intuitive comparison-based sorting algorithm. 
It builds the sorted array one element at a time by comparing each element with those before it
and inserting it in its correct position within the sorted portion of the array.



Steps of Insertion Sort:
Start from the second element (index 1), as the first element is trivially sorted.
Compare the current element with the elements before it.
Shift larger elements one position to the right to make space for the current element.
Insert the current element in the correct position.
Repeat this process for all elements in the array


Example:
Given the array: [12, 11, 13, 5, 6]

First Pass (i=1): Compare 11 with 12, and insert it before 12.
Array becomes: [11, 12, 13, 5, 6]
Second Pass (i=2): 13 is already in the correct position.
Third Pass (i=3): Compare 5 with all the previous elements and insert it at the beginning.
 Array becomes: [5, 11, 12, 13, 6]
Fourth Pass (i=4): Insert 6 after 5. Array becomes: [5, 6, 11, 12, 13]


Time Complexity:
Worst Case: O(n^2)
Best Case: O(n)
Average Case: O(n^2)

*/



#include <iostream>
using namespace std;

class Solution {
public:
    // Helper function to insert element at the correct position
    void insert(int arr[], int i) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            // Swap arr[j-1] and arr[j]
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    // Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; i++) {  // Start from the second element (i=1)
            insert(arr, i);
        }
    }
};

int main() {
    Solution solution;

    // Input: size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare an array of size n
    int arr[n];

    // Input: array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the insertionSort function to sort the array
    solution.insertionSort(arr, n);

    // Output: print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
