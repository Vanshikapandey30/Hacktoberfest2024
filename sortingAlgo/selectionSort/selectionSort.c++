#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> &vec,int n){
  for (int i = 0; i < n-1; i++)
  {
    for(int j = i+1;j<n;j++){
      if(vec[j]<vec[i]){
        swap(vec[j],vec[i]);
      }
    }
  }
}

int main()
{
  vector<int> vec = {34, 21, 56, 11, 29, 88, 76, 90, 54, 43};
  int n = vec.size();
  selectionSort(vec, n);
  for (auto ele : vec)
  {
    cout << ele << " ";
  }
  return 0;
}