#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the total seek time using LOOK algorithm
int LOOK(vector<int>& requests, int head, bool direction) {
    int seekCount = 0;
    vector<int> left, right;

    // Divide requests into two parts based on their position relative to the head
    for (int req : requests) {
        if (req < head) left.push_back(req);
        else right.push_back(req);
    }

    // Sort the requests on each side of the head
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    // Move the head towards the given direction
    if (direction) {  // Right direction
        for (int req : right) {
            seekCount += abs(req - head);
            head = req;
        }
        for (int req : left) {  // After reaching the rightmost request, move left
            seekCount += abs(req - head);
            head = req;
        }
    } else {  // Left direction
        for (int req : left) {
            seekCount += abs(req - head);
            head = req;
        }
        for (int req : right) {  // After reaching the leftmost request, move right
            seekCount += abs(req - head);
            head = req;
        }
    }
    return seekCount;
}

int main() {
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53; // Initial position of the head
    bool direction = true; // true for right, false for left
    cout << "Total seek time (LOOK): " << LOOK(requests, head, direction) << endl;
    return 0;
}
