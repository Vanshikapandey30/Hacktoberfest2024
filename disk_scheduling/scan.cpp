#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the total seek time using SCAN
int SCAN(vector<int>& requests, int head, int diskSize, bool direction) {
    int seekCount = 0;
    vector<int> left, right;

    if (direction) right.push_back(diskSize - 1); // End of the disk
    else left.push_back(0); // Start of the disk

    for (int req : requests) {
        if (req < head) left.push_back(req);
        else right.push_back(req);
    }

    // Sort the requests on each side of the head
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    // Process requests to the right if the direction is right
    if (direction) {
        for (int req : right) {
            seekCount += abs(req - head);
            head = req;
        }
        for (int req : left) {
            seekCount += abs(req - head);
            head = req;
        }
    } else {
        for (int req : left) {
            seekCount += abs(req - head);
            head = req;
        }
        for (int req : right) {
            seekCount += abs(req - head);
            head = req;
        }
    }
    return seekCount;
}

int main() {
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53; // Initial position of the head
    int diskSize = 200; // Total disk size
    bool direction = true; // true for right, false for left
    cout << "Total seek time (SCAN): " << SCAN(requests, head, diskSize, direction) << endl;
    return 0;
}
