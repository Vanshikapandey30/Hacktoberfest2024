#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to calculate the total seek time using FCFS
int FCFS(vector<int>& requests, int head) {
    int seekCount = 0;
    for (int i = 0; i < requests.size(); i++) {
        seekCount += abs(requests[i] - head); // Calculate the distance between head and next request
        head = requests[i]; // Move the head to the next request
    }
    return seekCount;
}

int main() {
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53; // Initial position of the head
    cout << "Total seek time (FCFS): " << FCFS(requests, head) << endl;
    return 0;
}
