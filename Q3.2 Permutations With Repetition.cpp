#include <iostream>
#include <vector>
using namespace std;

void generateWithRepetition(vector<int> &arr, vector<int> &perm, int length) {
    if (perm.size() == length) {
        for (int num : perm) cout << num << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < arr.size(); ++i) {
        perm.push_back(arr[i]);
        generateWithRepetition(arr, perm, length);
        perm.pop_back();
    }
}

int main() {
    int n, r;
    cout << "Enter number of digits: ";
    cin >> n;

    vector<int> digits(n);
    cout << "Enter " << n << " digits: ";
    for (int i = 0; i < n; ++i) cin >> digits[i];

    cout << "Enter permutation length (r): ";
    cin >> r;

    vector<int> perm;
    cout << "Permutations (with repetition):\n";
    generateWithRepetition(digits, perm, r);

    return 0;
}
