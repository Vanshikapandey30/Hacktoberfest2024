def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1 
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i] #Swap if the element is smaller than the pivot

    arr[i + 1], arr[high] = arr[high], arr[i + 1] #Swap the pivot element
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)  #pi is the partitioning index
        quick_sort(arr, low, pi - 1)  #Recursively sort the elements before partition
        quick_sort(arr, pi + 1, high)  #Recursively sort the elements after partition

arr = [10, 7, 8, 9, 1, 5]
quick_sort(arr, 0, len(arr) - 1)
print("Sorted array:", arr)