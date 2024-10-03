#include<iostream>
#include<vector>
using namespace std;

void countSort(vector<int> &vec, int n) {
    int k = vec[0];
    for (int i = 0; i < n; i++) {
        k = max(k, vec[i]); // Find the maximum element
    }

    // Initialize the count array with size (k+1)
    vector<int> count(k + 1, 0);

    // Store the count of each element in vec
    for (int i = 0; i < n; i++) {
        count[vec[i]]++;
    }

    // Modify the count array to store the cumulative sum
    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    // Create an output array to store the sorted result
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[--count[vec[i]]] = vec[i];
    }

    // Copy the sorted elements back to vec
    vec = output;
}

int main() {
    vector<int> vec = {34, 21, 56, 11, 29, 88, 76, 90, 54, 43};
    int n = vec.size();
    
    countSort(vec, n);
    
    // Print the sorted array
    for (auto ele : vec) {
        cout << ele << " ";
    }
    return 0;
}
