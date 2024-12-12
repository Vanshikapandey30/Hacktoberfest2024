#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the total seek time using C-LOOK algorithm
int CLOOK(vector<int>& requests, int head) {
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

    // Move the head towards the rightmost request and jump to the leftmost request
    for (int req : right) {
        seekCount += abs(req - head);
        head = req;
    }

    if (!left.empty()) {
        seekCount += abs(head - left[0]); // Jump from the rightmost to the leftmost request
        head = left[0];

        for (int req : left) {
            seekCount += abs(req - head);
            head = req;
        }
    }

    return seekCount;
}

int main() {
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53; // Initial position of the head
    cout << "Total seek time (C-LOOK): " << CLOOK(requests, head) << endl;
    return 0;
}
