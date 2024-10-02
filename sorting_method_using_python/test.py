import sorters as st # custom module

# test case
arr = [9,8,7,6,5,4,3,2,1]

# using sorting methods
b = st.Buildinsort(arr).bisort()
i = st.Insertionsort(arr).insort()
s = st.Selectionsort(arr).selsort()
bu = st.Bubblesort(arr).busort()
q = st.Quicksort(arr).qsort() 

# outputs
print(b) # sorted using build-in method in python
print(i) # sorted using Insertionsort method
print(s) # sorted using Selectionsort method
print(bu) # sorted using Bubblesort method
print(q) # sorted using Quicksort method