def bubble_sort(array):
    size = len(array)
    
    for i in range(size - 1):
        swapped = False
        
        for j in range(size - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
                swapped = True
        
        if not swapped:
            break


data = list(map(int, input("Enter numbers separated by spaces: ").split()))
bubble_sort(data)

print("Sorted Array in Ascending Order is:")
print(data)
