#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int> &vec, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (vec[j] > vec[j + 1])
      {
        // Swap arr[j] and arr[j + 1]
        int temp = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = temp;
      }
    }
  }
}
int main()
{
  vector<int> vec = {34, 21, 56, 11, 29, 88, 76, 90, 54, 43};
  int n = vec.size();
  bubbleSort(vec, n);
  for (auto ele : vec)
  {
    cout << ele << " ";
  }
  return 0;
}