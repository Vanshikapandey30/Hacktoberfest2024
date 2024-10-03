/*
TC: worst case-O(n2)
    best case-O(n)
    average case-O(n2)

SC: worst case-O(1)
    best case-O(1)
    average case-O(1)
*/

#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void print_arr(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubble_sort(int arr[],int size){
    bool flag;
    for(int i=0;i<size-1;i++){
        flag=0;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                flag=1;
                swap(arr[j],arr[j+1]);
            }
        }
        if(flag==0){
            break;
        }
    }
}

int main(){
    int size;
    cout<<"Enter size of array : ";
    cin>>size;

    int arr[size];
    cout<<"Enter elements of array : "<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    cout<<"Array before sorting : ";
    print_arr(arr,size);

    bubble_sort(arr,size);

    cout<<"Array after sorting : ";
    print_arr(arr,size);

    return 0;
}