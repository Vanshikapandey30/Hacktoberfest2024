arr = [12, 16, 11, 5, 37, 42, 5, 50, 6, 41]  # Example array to be sorted
"""
### Workings of the sorting algorithm:
1. It divides the array into a "sorted" and "unsorted" part.
2. It iterates through the array, picking one element from the unsorted part and inserting it into the correct position in the sorted part.
This happens in-place, meaning no extra memory is used except for a temporary variable to hold the current element.
### Time Complexity:
- Best: O(n)
- Worst: O(n^2) [Also the average time complexity]
"""
for i in range(1, len(arr)):
    temp = arr[i]
    j = i - 1
    while j > -1 and arr[j] > temp:
        arr[j + 1] = arr[j]
        j -= 1
    arr[j + 1] = temp
print(arr)
