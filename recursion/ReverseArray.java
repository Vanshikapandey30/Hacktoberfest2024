import java.util.*;
public class ReverseArray { 
    public static void reverse(int[] arr,int idx,int n)
    {
        if(idx>=n/2)
            return;
        int temp=arr[idx];
        arr[idx]=arr[n-1-idx];
        arr[n-1-idx]=temp;
        reverse(arr,idx+1,n);
    }
    public static void main(String[] args)
    {
        Scanner vis=new Scanner(System.in);
        System.out.println("Enter the value of n: ");
        int n=vis.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter any "+n+" values: ");
        for(int i=0;i<n;i++)
        {
            arr[i]=vis.nextInt();
        }
        reverse(arr,0,n);
        System.out.println("The reversed array: ");
        for(int k:arr)
        {
            System.out.println(k);
        }
        vis.close();
    }
}
