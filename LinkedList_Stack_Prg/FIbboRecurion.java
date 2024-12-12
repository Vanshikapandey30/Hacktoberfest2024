import java.util.Scanner;

public class FIbboRecurion {

    public static int fibbo(int n){
        //Base case
        if (n==0 || n==1) {
            return 1;
        }
        if (n== 2) {
            return 1;
        }
        int fnm1= fibbo(n-1);
        int fnm2= fibbo(n-2);
        int result= fnm2 + fnm1;

        return result;
    }
    
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter a Number");
        int n= sc.nextInt();
        System.out.println("Fibonacci number is: " + fibbo(n));
    }
}
