#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Find the middle element

        if (arr[mid] == target)
            return mid; // Return the index if the target is found

        if (arr[mid] < target)
            left = mid + 1; // Ignore the left half if the target is greater
        else
            right = mid - 1; // Ignore the right half if the target is smaller
    }

    return -1; // Return -1 if the target is not found
}

int main() {
    int arr[] = {10, 23, 32, 45, 50, 70, 85}; // Array must be sorted
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
