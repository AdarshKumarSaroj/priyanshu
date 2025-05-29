#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];

    vector<pair<int, int>> edges;

    // Find edges from adjacency matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (adj[i][j] == 1) {
                edges.push_back({i, j});
            }
        }
    }

    int edgeCount = edges.size();
    vector<vector<int>> incidence(n, vector<int>(edgeCount, 0));

    // Build incidence matrix
    for (int e = 0; e < edgeCount; ++e) {
        int u = edges[e].first;
        int v = edges[e].second;
        incidence[u][e] = 1;
        incidence[v][e] = 1;
    }

    // Print incidence matrix
    cout << "\nIncidence Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < edgeCount; ++j) {
            cout << incidence[i][j] << " ";
        }
        cout << endl;
    }

    // Print degree of each vertex
    cout << "\nDegree of each vertex:\n";
    for (int i = 0; i < n; ++i) {
        int degree = 0;
        for (int j = 0; j < n; ++j)
            degree += adj[i][j];
        cout << "Vertex " << i << ": " << degree << endl;
    }

    return 0;
}
