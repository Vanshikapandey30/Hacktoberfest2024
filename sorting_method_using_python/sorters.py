"""
Sorters
-------
This `module` containes different types of sorting algorithms like:-
1. `Buildinsort`
2. `Bubblesort`
3. `Insertionsort`
4. `Selectionsort`

This module can be imported by writing:-
    >>> import sorters
"""

class Buildinsort:
    def __init__(self, data:list[int]) -> None:
        self.arr = data

    def bisort(self) -> list[int]:
        # use of built in method
        return sorted(self.arr)
    
class Bubblesort:
    def __init__(self, data:list[int]) -> None:
        self.arr = data
    def busort(self):
        length = len(self.arr)
        
        for i in range(length):
            for j in range(length-i-1):
                if self.arr[j]> self.arr[j+1]:
                    self.arr[j],self.arr[j+1] = self.arr[j+1], self.arr[j]

        return self.arr

    
class Insertionsort:
    def __init__(self, data:list[int]) -> None:
        self.arr = data
    def insort(self):
        for i in range(1,len(self.arr)):
            current_item = self.arr[i]
            j = i -1
            while j>=0 and current_item < self.arr[j]:
                self.arr[j+1] = self.arr[j]
                j-=1
            self.arr[j+1]= current_item

        return self.arr
    
class Selectionsort:
    def __init__(self, data:list[int]) -> None:
        self.arr = data

    def selsort(self):
        for i in range(len(self.arr)):
            min_index = i
            for j in range(i+1, len(self.arr)):
                if self.arr[j]<self.arr[min_index]:
                    min_index = j
            min_value = self.arr.pop(min_index)
            self.arr.insert(i, min_value)
        return self.arr
    
class Quicksort:
    def __init__(self, data:list[int]) -> None:
        self.arr = data

    def __partition(self, arr:list, low, high)->int:
        pivot = arr[high]
        i = low -1
        for j in range(low,high):
            if arr[j]<=pivot:
                i+=1
                arr[i], arr[j] = arr[j], arr[i]

        arr[high], arr[i+1] = arr[i+1], arr[high]
        return i+1

    def qsort(self, low=0, high= None):
        if high is None:
            high = len(self.arr) -1

        if low < high:
            pivot_index = Quicksort.__partition(self=self, arr=self.arr, low=low ,high=high)
            Quicksort.qsort(self= self, low= low, high = pivot_index -1 )
            Quicksort.qsort(self=self, low= pivot_index +1 , high=high)

        return self.arr