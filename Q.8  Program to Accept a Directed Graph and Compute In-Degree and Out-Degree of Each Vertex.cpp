#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix for the directed graph:\n";
    
    // Input graph matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];

    // Initialize in-degree and out-degree arrays
    vector<int> inDegree(n, 0), outDegree(n, 0);

    // Calculate degrees
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == 1) {
                outDegree[i]++; // Outgoing from i
                inDegree[j]++;  // Incoming to j
            }
        }
    }

    // Display degrees
    cout << "\nVertex\tIn-Degree\tOut-Degree\n";
    for (int i = 0; i < n; ++i) {
        cout << i << "\t" << inDegree[i] << "\t\t" << outDegree[i] << endl;
    }

    return 0;
}
