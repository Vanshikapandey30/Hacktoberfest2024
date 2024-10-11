import java.util.*;
public class Factorial {
    public static int Fact(int n)
    {
        if(n<=1)
            return 1;
        return n*Fact(n-1);
    }
    public static void main(String[] args)
    {
        Scanner vis=new Scanner(System.in);
        System.out.println("Enter the value of n: ");
        int n=vis.nextInt();
        System.out.println(Fact(n));
        vis.close();
    }
}
