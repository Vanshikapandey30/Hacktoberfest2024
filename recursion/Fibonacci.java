import java.util.*;
class Fibonacci{
    public static int fibo1(int n)
    {
        if(n==0 || n==1)
        {
            return n;
        }
        return fibo1(n-1)+fibo1(n-2);
    }
    public static void main(String[] args)
    {
        Scanner vis=new Scanner(System.in);

        System.out.println("Enter a value");
        int n=vis.nextInt();
        System.out.println(fibo1(n));
        vis.close();
    }
}