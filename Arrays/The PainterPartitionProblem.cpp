#include <iostream>
using namespace std;

class Solution {
  public:
    long long minTime(int arr[], int n, int m) {
        long long start = 0, end = 0, mid, ans = 0;
        
        // Calculate the bounds for binary search
        for (int i = 0; i < n; i++) {
            if (start < arr[i])
                start = arr[i];  // Max element, this is the lower bound of the time.
            end += arr[i];  // Total sum of the array, this is the upper bound of the time.
        }

        // Binary search for the minimum possible maximum time
        while (start <= end) {
            mid = start + (end - start) / 2;
            long long pages = 0, count = 1;  // 'pages' is the current sum of tasks for a worker, 'count' tracks the number of workers.

            for (int i = 0; i < n; i++) {
                pages += arr[i];
                if (pages > mid) {  // If current worker exceeds mid, assign new worker
                    count++;
                    pages = arr[i];  // Start new worker with the current task
                }
            }

            if (count <= m) {
                // If we can assign tasks to 'm' or fewer workers, this is a valid solution, try to minimize the time
                ans = mid;
                end = mid - 1;
            } else {
                // If we need more than 'm' workers, increase the maximum allowed time
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    int n, m;
    cout << "Enter number of tasks (n): ";
    cin >> n;
    
    cout << "Enter number of workers (m): ";
    cin >> m;
    
    int arr[n];
    cout << "Enter the time required for each task: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long result = solution.minTime(arr, n, m);
    cout << "The minimum time in which all workers can complete the tasks is: " << result << endl;

    return 0;
}
