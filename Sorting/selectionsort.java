// Java implementation
class SelectionSort
{
    public void selectionSort(int A[])
    {      
        int arraySize = A.length;
        for (int i = 0; i < arraySize - 1; i++)
        {
            //currently current minimum element index of the unsorted array is set as i
            int minIndex = i;
            //iterating unsorted array
            for (int j = i+1; j < arraySize; j++)
                //check for minimum element
                if (A[j] < A[minIndex])
                    minIndex = j;
 
            // swap the minimum element with the element at minIndex to
            // keep it at its position
            int temp = A[minIndex];
            A[minIndex] = A[i];
            A[i] = temp;
        }
    }
}
