#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(float arr[], int size) {
    // Create empty buckets
    vector<vector<float>> bucket(size, vector<float> ());

    // Find the maximum and minimum elements
    float maxEle = arr[0];
    float minEle = arr[0];
    for (int i = 1; i < size; i++) {
        maxEle = max(maxEle, arr[i]);
        minEle = min(minEle, arr[i]);  // Corrected to use min
    }

    // Compute the range of each bucket
    float range = (maxEle - minEle) / size;  // Corrected to use '='

    // Place elements into the appropriate bucket
    for (int i = 0; i < size; i++) {
        int index = (arr[i] - minEle) / range;
        float diff = (arr[i] - minEle) / range - index;

        if (diff == 0 && arr[i] != minEle) {
            bucket[index - 1].push_back(arr[i]);
        } else {
            bucket[index].push_back(arr[i]);
        }
    }

    // Sort individual buckets
    for (int i = 0; i < size; i++) {
        if (!bucket[i].empty()) {
            sort(bucket[i].begin(), bucket[i].end());  // Corrected syntax
        }
    }

    // Concatenate the buckets into the original array
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[k++] = bucket[i][j];
        }
    }
}

int main() {
    float arr[] = {4.56, 2.41, 3.78, 9.55, 1.34, 10.56};
    int size = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, size);
    for (auto ele : arr) {
        cout << ele << " ";
    }
    return 0;
}
