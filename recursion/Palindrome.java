import java.util.*;
public class Palindrome {
    public static boolean isPalindrome(int idx,String a,int n)
    {
        if(idx>=(n/2))
        {
            return true;
        }

        if(a.charAt(idx)!=a.charAt(n-1-idx))
        {
            return false;
        }
        return isPalindrome(idx+1,a,n);
    }
    public static void main(String[] args)
    {
        Scanner vis=new Scanner(System.in);
        System.out.println("Enter a String to Check");
        String a=vis.nextLine();
        int n=a.length();
        if(isPalindrome(0,a,n))
            System.out.println("The given string is a Palindrome");
        else
            System.out.println("The given string is not a palindrome");
        vis.close();
    }
}
