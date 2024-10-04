#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the total seek time using C-SCAN
int CSCAN(vector<int>& requests, int head, int diskSize) {
    int seekCount = 0;
    vector<int> left, right;

    left.push_back(0); // Start of the disk
    right.push_back(diskSize - 1); // End of the disk

    for (int req : requests) {
        if (req < head) left.push_back(req);
        else right.push_back(req);
    }

    // Sort the requests on each side of the head
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    // Process requests to the right of the head, then jump to the left end
    for (int req : right) {
        seekCount += abs(req - head);
        head = req;
    }
    head = 0; // Jump to the start of the disk
    for (int req : left) {
        seekCount += abs(req - head);
        head = req;
    }
    return seekCount;
}

int main() {
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53; // Initial position of the head
    int diskSize = 200; // Total disk size
    cout << "Total seek time (C-SCAN): " << CSCAN(requests, head, diskSize) << endl;
    return 0;
}
