arr = [12, 16, 11, 4, 37, 42, 5, 50, 6, 41]  # Example array to be sorted
"""
### Workings of the sorting algorithm:
1. It divides the list into two parts: the "sorted" part on the left and the "unsorted" part on the right.
2. The algorithm repeatedly selects the smallest element from the unsorted part and swaps it with the first unsorted element, effectively growing the sorted part by one element with each iteration.
### Time Complexity:
- Best == Worst == O(n^2)
"""
for index in range(len(arr)):
    mini = index
    for j in range(index + 1, len(arr)):
        if arr[j] < arr[mini]:
            mini = j
    (arr[index], arr[mini]) = (arr[mini], arr[index])

print(arr)
