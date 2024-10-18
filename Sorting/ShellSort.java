class ShellSort {  
/* function to implement shellSort */  
static void shell(int a[], int n)  
{  
    /* Rearrange the array elements at n/2, n/4, ..., 1 intervals */  
    for (int interval = n/2; interval > 0; interval /= 2)  
    {  
        for (int i = interval; i < n; i += 1)  
        {  
            /* store a[i] to the variable temp and make  
 
the ith position empty */  
            int temp = a[i];  
            int j;        
            for (j = i; j >= interval && a[j - interval] >   
temp; j -= interval)  
                a[j] = a[j - interval];  
              
            /* put temp (the original a[i]) in its correct  
position */  
            a[j] = temp;  
        }  
    }  
}  
static void printArr(int a[], int n) /* function to print the array elements */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        System.out.print(a[i] + " ");  
}  
public static void main(String args[])   
{  
    int a[] = { 30, 28, 37, 5, 9, 14, 22, 39 };  
    int n = a.length;  
    System.out.print("Before sorting array elements are - \n");  
    printArr(a, n);  
    shell(a, n);  
    System.out.print("\nAfter applying shell sort, the array elements are - \n");    
    printArr(a, n);  
}      
}  
