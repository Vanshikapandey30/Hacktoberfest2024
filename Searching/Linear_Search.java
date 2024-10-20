package Searching;

public class Linear_Search {
    
        public static int linearSearch(int[] arr, int key) {
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] == key) {
                    return i; // Return the index of the found element
                }
            }
            return -1; // Element not found
        }
    
        public static void main(String[] args) {
            int[] arr = {2, 4, 0, 1, 9};
            int key = 1;
            int result = linearSearch(arr, key);
            if (result == -1) {
                System.out.println("Element not found");
            } else {
                System.out.println("Element found at index: " + result);
            }
        }
    }
    

