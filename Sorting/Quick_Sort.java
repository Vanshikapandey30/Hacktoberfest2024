public class Quick  
{  

int partition (int a[], int start, int end)                           
{  
    int pivot = a[end]; // pivot element, consider last element as pivot.
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (a[j] < pivot)  
        {  
            i++;
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}  
  

void quick(int a[], int start, int end) 
{  
    if (start < end)  
    {  
        int p = partition(a, start, end);  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
}  
  
// function to print an array   
void printArr(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        System.out.print(a[i] + " ");  
}  
    public static void main(String[] args) {  
    int a[] = { 29, 28, 17, 2, 59, 15 };  
    int n = a.length;  
    System.out.println("\nBefore sorting :");  
    Quick q1 = new Quick();  
    q1.printArr(a, n);  
    q1.quick(a, 0, n - 1);  
    System.out.println("\nAfter sorting :");  
    q1.printArr(a, n);  
    System.out.println();  
    }  
}  
