#include <iostream>
#include <vector>
using namespace std;

void findSolutions(int n, int C, vector<int> &solution, int index, int sumSoFar) {
    if (index == n) {
        if (sumSoFar == C) {
            // Valid solution found
            for (int x : solution) cout << x << " ";
            cout << endl;
        }
        return;
    }

    for (int i = 0; i <= C - sumSoFar; ++i) {
        solution[index] = i;
        findSolutions(n, C, solution, index + 1, sumSoFar + i);
    }
}

int main() {
    int n, C;
    cout << "Enter number of variables (n): ";
    cin >> n;
    cout << "Enter the constant value (C): ";
    cin >> C;

    vector<int> solution(n);
    cout << "Solutions for x1 + x2 + ... + x" << n << " = " << C << ":\n";
    findSolutions(n, C, solution, 0, 0);

    return 0;
}
