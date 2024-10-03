/* Given an Integer n and a list arr. Sort the array using bubble sort algorithm.

Bubble sort ?
Bubble sort is a simple comparison-based sorting algorithm that works by repeatedly stepping through the 
list of elements, comparing adjacent pairs, and swapping them if they are in the wrong order. 
This process is repeated for every element until no more swaps are needed, meaning the list is sorted.


How Bubble Sort Works:
Step 1: The algorithm compares each pair of adjacent elements.
Step 2: If the first element is greater than the second, they are swapped.
Step 3: This process repeats from the start of the list, pushing the largest unsorted element to the end 
of the list on each iteration, similar to how bubbles "float" to the top in a liquid.
Step 4:The process is repeated for the rest of the list, excluding the last sorted element,
 until no swaps are needed (the list is sorted).


Dry run 


Example: Suppose we have the array: [5, 2, 9, 1, 5, 6]

step 1: First pass:

Compare 5 and 2: Swap → [2, 5, 9, 1, 5, 6]
Compare 5 and 9: No swap → [2, 5, 9, 1, 5, 6]
Compare 9 and 1: Swap → [2, 5, 1, 9, 5, 6]
Compare 9 and 5: Swap → [2, 5, 1, 5, 9, 6]
Compare 9 and 6: Swap → [2, 5, 1, 5, 6, 9]
Now, the largest element 9 is in its correct position.


step 2: Second pass:

Compare 2 and 5: No swap → [2, 5, 1, 5, 6, 9]
Compare 5 and 1: Swap → [2, 1, 5, 5, 6, 9]
Compare 5 and 5: No swap → [2, 1, 5, 5, 6, 9]
Compare 5 and 6: No swap → [2, 1, 5, 5, 6, 9]
Now the second largest element 6 is in its correct position.


 The process repeats until the array is sorted: [1, 2, 5, 5, 6, 9].


 Time Complexity:
 Best Case: O(n)
 Worst Case: O(n^2)
 

 */



#include <iostream>
using namespace std;

// User function to perform bubble sort
class Solution {
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        bool swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap using a temporary variable
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }
            // If no elements were swapped in the inner loop, array is already sorted
            if (!swapped) {
                break;
            }
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
    
    // Call the bubbleSort function to sort the array
    solution.bubbleSort(arr, n);
    
    // Output: print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}



/* 
Input: n = 5, arr[] = {4, 1, 3, 9, 7}
Output: 1 3 4 7 9


*/