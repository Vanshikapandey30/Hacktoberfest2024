#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &vec,int l,int r){
  int pivot = vec[r];
  int i = l-1;
  for(int j = l;j<r;j++){
    if(vec[j]<pivot){
      i++;
      swap(vec[i],vec[j]);
    }
  }
  swap(vec[i+1],vec[r]);
  return i+1;
}
void quickSort(vector<int> &vec,int l,int r){
  if(l<r){
    int pi = partition(vec,l,r);
    quickSort(vec,l,pi-1);
    quickSort(vec,pi+1,r);
  }
}
int main()
{
  vector<int> vec = {34, 21, 56, 11, 29, 88, 76, 90, 54, 43};
  int l = 0;
  int r= vec.size()-1;
  quickSort(vec,l,r);
  for (auto ele : vec)
  {
    cout << ele << " ";
  }
  return 0;
}