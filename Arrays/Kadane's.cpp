#include <iostream>
#include <climits> // for INT_MIN
using namespace std;

int kadane(int arr[], int n)
{
    int max_current = arr[0];
    int max_global = arr[0];

    for (int i = 1; i < n; i++)
    {

        max_current = max(arr[i], max_current + arr[i]);

        if (max_current > max_global)
        {
            max_global = max_current;
        }
    }

    return max_global;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int max_sum = kadane(arr, n);

    cout << "Maximum sum of a contiguous subarray is: " << max_sum << endl;

    return 0;
}
