import java.util.Iterator;

public class quick {
	public static int partition(int array[], int low, int high) {
		int pivot = array[high];
		int i = low-1;
		
		for (int j = low; j < high; j++) {
			if(array[j] < pivot) {
				i++;
				int temp = array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
		
		i++;
		int temp= array[i];
		array[i]= pivot;
		array[high]= temp;
		return i;
		
	}
	
	public static void quickSort(int array[], int low, int high) {
		if(low < high) {
			int pidx =partition(array, low, high);
			quickSort(array, low, pidx-1);
			quickSort(array, pidx+1, high);
		}
	}

	public static void main(String[] args) {
		int [] array = {9,3,1,5,6,7,4};
		int n = array.length;
		
		quickSort(array, 0, n-1);
		
		for (int i = 0; i < n; i++) {
			System.out.print(array[i]+ " ");
		}
		System.out.println();
	}

}
