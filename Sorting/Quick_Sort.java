
public class QuickSort {
	public static void quickSort(int[] array, int start, int end) {
		if (start < end) {
			int pivot = partition(array, start, end);
			quickSort(array, start, pivot-1 );
			quickSort(array, pivot + 1,end);
		}
	}//end of method

	
	static int partition(int[] array, int p, int q) {
		int pivot = q;
		int i = p-1;
		for (int j = p; j <= q; j++) {
			if (array[j] <= array[pivot]) {
				i++;
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
		return i;

	}
	
	
	public static void printArray(int []array) {
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i]+"  ");
		}
	}

	public static void main(String[] args) {
		int array[] = {10, 3, 2, 7, 7, 5, 8, 4, 1, 2, 9, 7, 8, 11};
		
		System.out.println("User entered Array: ");
		QuickSort.printArray(array);
		
		QuickSort.quickSort(array, 0, array.length-1);
		
		System.out.println("\n\nAfter sorting: ");
		QuickSort.printArray(array);
	}
}
