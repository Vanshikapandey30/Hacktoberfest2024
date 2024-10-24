#include <iostream>
#include <vector>
using namespace std;

// Function to implement Insertion Sort
void insertionSort(vector<int> &arr)
{
  int n = arr.size();

  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}
int main()
{
  vector<int> arr = {12, 11, 13, 5, 6, 56, 21, 33, 23, 48, 9, 90};
  insertionSort(arr);
  for (auto ele : arr)
  {
    cout << ele << " ";
  }

  return 0;
}
