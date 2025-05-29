#include <iostream>
#include <vector>
using namespace std;

bool isCompleteGraph(vector<vector<int>> &adjMatrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j && adjMatrix[i][j] != 0) {
                return false; // self-loop
            }
            if (i != j && adjMatrix[i][j] != 1) {
                return false; // not fully connected
            }
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n));
    cout << "Enter the adjacency matrix:\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjMatrix[i][j];
        }
    }

    if (isCompleteGraph(adjMatrix, n)) {
        cout << "The graph is a COMPLETE graph.\n";
    } else {
        cout << "The graph is NOT a complete graph.\n";
    }

    return 0;
}
