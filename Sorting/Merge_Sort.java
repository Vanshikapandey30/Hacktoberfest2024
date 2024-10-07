import java.util.Arrays;

class Main {

  // merge two subarrays L and R into arr
  static void merge(int arr[], int left, int mid, int right) {
    // sizes of the two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // create temporary arrays
    int L[] = new int[n1];
    int R[] = new int[n2];

    // copy data into temporary arrays
    for (int i = 0; i < n1; ++i)
      L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
      R[j] = arr[mid + 1 + j];

    // initial indexes for subarrays and the merged array
    int i = 0, j = 0, k = left;

    // merge the temp arrays back into arr
    while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
        arr[k] = L[i];
        i++;
      } else {
        arr[k] = R[j];
        j++;
      }
      k++;
    }

    // copy remaining elements of L[], if any
    while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
    }

    // copy remaining elements of R[], if any
    while (j < n2) {
      arr[k] = R[j];
      j++;
      k++;
    }
  }

  // function to perform merge sort
  static void mergeSort(int arr[], int left, int right) {
    if (left < right) {
      // find the middle point
      int mid = (left + right) / 2;

      // recursively sort the two halves
      mergeSort(arr, left, mid);
      mergeSort(arr, mid + 1, right);

      // merge the sorted halves
      merge(arr, left, mid, right);
    }
  }

  public static void main(String args[]) {
    int[] data = { -2, 45, 0, 11, -9 };

    // call the merge sort function
    Main.mergeSort(data, 0, data.length - 1);

    System.out.println("Sorted Array in Ascending Order is:");
    System.out.println(Arrays.toString(data));
  }
}
