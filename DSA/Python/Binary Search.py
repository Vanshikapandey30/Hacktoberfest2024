def binary_search(arr, key):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            return mid  # Key found at mid index
        elif arr[mid] < key:
            low = mid + 1  # Search in the right half
        else:
            high = mid - 1  # Search in the left half
    return -1  # Return -1 if key is not found

arr = [11, 15, 23, 45, 70]
key = 15
result = binary_search(arr, key)

if result != -1:
    print(f"Element found at index {result}")
else:
    print("Element not found")