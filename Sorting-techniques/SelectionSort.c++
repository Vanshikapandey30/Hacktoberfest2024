/* Given an unsorted array of size N, use selection sort to sort arr[] in increasing order.

Selection sort is another simple comparison-based sorting algorithm. It 
divides the list into two parts: a sorted part and an unsorted part. The algorithm repeatedly
selects the smallest (or largest, depending on the order) element from the unsorted part and swaps 
it with the first element of the unsorted part, thus growing the sorted part one element at a time.



How Selection Sort Works:

Start with the entire list as unsorted.
Find the smallest element in the unsorted portion of the list.
Swap the smallest element with the first element of the unsorted part.
Move the boundary between the sorted and unsorted portions one element to the right.
Repeat until the entire list is sorted.




Suppose we have the array: [64, 25, 12, 22, 11]

step 1: First pass:
Find the smallest element: 11
Swap 11 with the first element → [11, 25, 12, 22, 64]
Now, the first element is sorted.

step 2: Second pass:
Find the smallest element in the unsorted part: 12
Swap 12 with the second element → [11, 12, 25, 22, 64]

step 3: Third pass:
Find the smallest element in the unsorted part: 22
Swap 22 with the third element → [11, 12, 22, 25, 64]

step 4: Fourth pass:
Find the smallest element in the unsorted part: 25
No swap needed since 25 is already in the correct place.


The sorted array is [11, 12, 22, 25, 64].


Time Complexity:
Best Case: O(n^2)
Average Case: O(n^2)
Worst Case: O(n^2)

*/






#include <iostream>
using namespace std;

class Solution {
public:
    // Function to perform selection sort
    void selectionSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            int min = i; 
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            if (min != i) {
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        }
    }
};

int main() {
    Solution solution;
    
    // Input size of array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    // Input array elements
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Call selectionSort function
    solution.selectionSort(arr, n);
    
    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}



/* 
Example 1:
Input:
N = 5
arr[] = {4, 1, 3, 9, 7}
Output:
1 3 4 7 9
Explanation:
Select 1. Array becomes 1 4 3 9 7.
Select 3. Array becomes 1 3 4 9 7.
Select 4. Array becomes 1 3 4 9 7.
Select 7. Array becomes 1 3 4 7 9.
Select 9. Array becomes 1 3 4 7 9.










*/

