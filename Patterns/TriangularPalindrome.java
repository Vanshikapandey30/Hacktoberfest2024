public class TriangularPalindrome{
    public static void main(String[] args) {
        int n =5;
        for(int i = 1; i <= n; i++){
            //printing before spaces
            for(int j = 1; j <= n-i; j++){
                System.out.print("  ");
            }
            //printing the column values
            for(int j = i; j >= 1; j--){
                System.out.print(j + " ");
            }
            for(int j = 2; j <= i; j++){
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}