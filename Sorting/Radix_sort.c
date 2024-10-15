#include<stdio.h>
#include<stdlib.h>
int getmax(int arr[],int size)
{
	int mx=arr[0],i;
	for(i=0;i<size;i++)
	{
		if(arr[i] > mx)
		{
			mx=arr[i];
		}
	}
	return mx;
}
void countsort(int arr[],int size,int exp)
{
	int output[size],i,digit;
	int count[10]= {0};
	for(i=0;i<size;i++)
	{
		digit=(arr[i] / exp % 10);
		count[digit]++;
	}
	
	for(i=1;i<10;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	for(i=size-1;i>=0;i--)
	{
		digit=(arr[i] / exp % 10);
		output[count[digit] - 1]=arr[i];
		count[digit]--;
	}
	
	for(i=0;i<size;i++)
	{
		arr[i]=output[i];
	}
}
void radix_sort(int arr[],int size)
{
	int max=getmax(arr,size);
	int exp,i;
	for(exp=1; max / exp > 0; exp *= 10)
	{
		countsort(arr,size,exp);
	}
}
void print(int arr[],int size)
{
	int i;
	printf("Sorted Array: ");
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
	}
}
void main()
{
	int i,n;
	int arr[9]={345,654,924,123,567,472,555,808,911};
	n=sizeof(arr[0]);
	printf("Unsorted Array: ");
	for(i=0;i<9;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
	radix_sort(arr,9);
	print(arr,9);
}