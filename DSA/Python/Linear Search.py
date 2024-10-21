def linear_search(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i  # Returns the index of the key element
    return -1  # Return -1 if key is not found


arr = [10, 23, 45, 70, 11, 15]
key = 70
result = linear_search(arr, key)

if result != -1:
    print(f"Element found at index {result}")
else:
    print("Element not found")