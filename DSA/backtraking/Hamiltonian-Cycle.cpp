#include <iostream>
#include <vector>
using namespace std;

#define V 5
bool isSafe(int v, vector<vector<int>> &graph, vector<int> &path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    return true;
}

bool hamiltonianCycleUtil(vector<vector<int>> &graph, vector<int> &path, int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(graph, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCycle(vector<vector<int>> &graph) {
    vector<int> path(V, -1);
    path[0] = 0;

    if (!hamiltonianCycleUtil(graph, path, 1)) {
        cout << "No Hamiltonian Cycle exists.\n";
        return false;
    }

    cout << "Hamiltonian Cycle exists: ";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
    cout << path[0] << endl;
    return true;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}
