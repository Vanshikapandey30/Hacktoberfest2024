#include <iostream>
#include <vector>
#include <cmath>
#include <climits> // Include for INT_MAX
using namespace std;

// Function to calculate the total seek time using SSTF
int SSTF(vector<int>& requests, int head) {
    int seekCount = 0;
    vector<bool> processed(requests.size(), false); // To mark processed requests

    for (int i = 0; i < requests.size(); i++) {
        int minDistance = INT_MAX;  // Set to maximum possible integer
        int index = -1;             // Variable to hold the index of the next request

        // Find the request with the shortest seek time
        for (int j = 0; j < requests.size(); j++) {
            if (!processed[j] && abs(requests[j] - head) < minDistance) {
                minDistance = abs(requests[j] - head);
                index = j;  // Save the index of the nearest request
            }
        }

        // Move the head to the nearest request and mark it as processed
        seekCount += abs(requests[index] - head);
        head = requests[index];
        processed[index] = true;  // Mark the request as processed
    }

    return seekCount;  // Return the total seek count
}

int main() {
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53; // Initial position of the head
    cout << "Total seek time (SSTF): " << SSTF(requests, head) << endl;
    return 0;
}
