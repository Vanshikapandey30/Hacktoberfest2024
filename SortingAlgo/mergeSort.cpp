// Merge Sort using recursion
class Solution
{
    public:
    void merge(int arr[], int l, int r)
    {
        int  mid = l+(r-l)/2;
        
        int len1 = mid-l+1;
        int len2 = r-mid;
        
        int *firstArr = new int[len1];
        int *secArr = new int[len2];
        
        // copying values
        int mainArrIndex = l;
        for(int i=0;i<len1;i++){
            firstArr[i] = arr[mainArrIndex++];
        }
        
        mainArrIndex = mid+1;
        for(int i=0;i<len2;i++){
            secArr[i] = arr[mainArrIndex++];
        }
        
        // logic of merge two sorted array
        
        int index1 = 0;
        int index2 = 0;
        mainArrIndex = l;
        
        while(index1<len1 && index2<len2){
            if(firstArr[index1]<secArr[index2]){
                arr[mainArrIndex++] = firstArr[index1++];
            }
            else{
                arr[mainArrIndex++] = secArr[index2++];
            }
        }
        while(index1<len1){
            arr[mainArrIndex++] = firstArr[index1++];
        }
        while(index2<len2){
            arr[mainArrIndex++] = secArr[index2++];
        }
        
    }
    public:
    
    void solve(int *arr,int l,int r){
        //base case
        if(l>=r){
            return;
        }
        int mid = l+(r-l)/2;
        
        // sort the left part
        solve(arr,l,mid);
        
        // sort the right part
        solve(arr,mid+1,r);
        
        // merge
        merge(arr,l,r);
    }
    void mergeSort(int arr[], int l, int r)
    {
        solve(arr,l,r);
    }
};