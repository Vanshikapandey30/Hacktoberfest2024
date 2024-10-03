
/* 
Radix Sort is a non-comparison-based sorting algorithm. It sorts numbers by processing individual digits.
The algorithm processes the least significant digit (LSD) or the most significant digit (MSD) first.
 Radix Sort works well when the input is large and made up of integers or strings.
 It typically uses Counting Sort as a subroutine to sort the digits.

Steps for Radix Sort:
Determine the maximum number in the input array to know the number of digits to process.
Sort the array by each digit, starting from the least significant digit (LSD) to the most significant digit (MSD). For each digit position, apply a stable sorting algorithm (usually Counting Sort).
Repeat the process for each digit

Radix Sort Example:
For the array [170, 45, 75, 90, 802, 24, 2, 66], the steps would be:

Start with the least significant digit (LSD):
After sorting by the LSD, the array becomes [170, 90, 802, 2, 24, 45, 75, 66].
Sort by the next digit:
The array becomes [802, 2, 24, 45, 66, 75, 170, 90].
Finally, sort by the most significant digit:
The array becomes [2, 24, 45, 66, 75, 90, 170, 802].

 */



#include <iostream>
using namespace std;

// A utility function to get the maximum value in arr[]
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// A function to do counting sort of arr[] according to the digit represented by exp (10^exp place value)
void countingSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int count[10] = {0}; // Initialize count array as 0

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// The main function to that sorts arr[] of size n using Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int max = getMax(arr, n);

    // Do counting sort for every digit, exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radixSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
