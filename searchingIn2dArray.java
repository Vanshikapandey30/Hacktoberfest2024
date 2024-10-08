public class searchingIn2dArray {

    //Time complexity : O(n+m) where 'n' is the number of rows & 'm' is the number of column 
	public static boolean searchingIn2dArray(int matrix[][], int key) {       
		int row = 0, col = matrix[0].length - 1;

		while (row < matrix[0].length && col >= 0) {
			if (matrix[row][col] == key) {
				System.out.println("Key FOUND at (" + row + "," + col + ")");
				return true;
			} else if (key < matrix[row][col]) {
				col--;
			} else {
				row++;
			}
		}
        System.out.println("Key not FOUND!");
		return false;
	}

	public static void main(String[] args) {
		int matrix[][] = {{ 1, 2, 3, 4 },
				          { 5, 6, 7, 8 },
				          { 9, 10, 11, 12 },
				          { 13, 14, 15, 16 }};
		int key = 14;
		searchingIn2dArray(matrix, key);
	}
}
