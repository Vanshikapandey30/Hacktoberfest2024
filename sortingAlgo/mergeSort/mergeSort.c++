#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vec, int l, int mid, int r)
{
  int n1 = mid - l + 1;
  int n2 = r - mid;

  vector<int> a(n1);
  vector<int> b(n2);

  // Copy data to temporary arrays a[] and b[]
  for (int i = 0; i < n1; i++)
  {
    a[i] = vec[l + i];
  }
  for (int i = 0; i < n2; i++)
  {
    b[i] = vec[mid + 1 + i];
  }

  int i = 0, j = 0, k = l;

  // Merge the temporary arrays back into vec[l..r]
  while (i < n1 && j < n2)
  {
    if (a[i] < b[j])
    {
      vec[k] = a[i];
      i++;
    }
    else
    {
      vec[k] = b[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of a[], if any
  while (i < n1)
  {
    vec[k] = a[i];
    i++;
    k++;
  }

  // Copy the remaining elements of b[], if any
  while (j < n2)
  {
    vec[k] = b[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &vec, int l, int r)
{
  if (l < r)
  {
    int mid = l + (r - l) / 2;
    mergeSort(vec, l, mid);
    mergeSort(vec, mid + 1, r);
    merge(vec, l, mid, r);
  }
}

int main()
{
  vector<int> vec = {34, 21, 56, 11, 29, 88, 76, 90, 54, 43};
  int l = 0;
  int r = vec.size() - 1;

  mergeSort(vec, l, r);

  for (auto ele : vec)
  {
    cout << ele << " ";
  }
  cout << endl;
  return 0;
}
