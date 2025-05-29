#include <iostream>
#include <vector>
using namespace std;

class RELATION {
    int size;
    vector<vector<int>> matrix;

public:
    void input() {
        cout << "Enter the size of set A (e.g., A = {0, 1, ..., n-1}): ";
        cin >> size;
        matrix.resize(size, vector<int>(size));
        cout << "Enter the relation matrix (0/1 values only):\n";
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                cin >> matrix[i][j];
    }

    bool isReflexive() {
        for (int i = 0; i < size; ++i)
            if (matrix[i][i] != 1) return false;
        return true;
    }

    bool isSymmetric() {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                if (matrix[i][j] != matrix[j][i]) return false;
        return true;
    }

    bool isAntiSymmetric() {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                if (i != j && matrix[i][j] && matrix[j][i]) return false;
        return true;
    }

    bool isTransitive() {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                for (int k = 0; k < size; ++k)
                    if (matrix[i][j] && matrix[j][k] && !matrix[i][k])
                        return false;
        return true;
    }

    void checkProperties() {
        bool reflexive = isReflexive();
        bool symmetric = isSymmetric();
        bool antisymmetric = isAntiSymmetric();
        bool transitive = isTransitive();

        cout << "\nProperties:\n";
        cout << "Reflexive: " << (reflexive ? "Yes" : "No") << endl;
        cout << "Symmetric: " << (symmetric ? "Yes" : "No") << endl;
        cout << "Anti-Symmetric: " << (antisymmetric ? "Yes" : "No") << endl;
        cout << "Transitive: " << (transitive ? "Yes" : "No") << endl;

        if (reflexive && symmetric && transitive)
            cout << "\n=> Relation is an **Equivalence Relation**.\n";
        else if (reflexive && antisymmetric && transitive)
            cout << "\n=> Relation is a **Partial Order Relation**.\n";
        else
            cout << "\n=> Relation is **Neither Equivalence nor Partial Order**.\n";
    }
};

int main() {
    RELATION R;
    R.input();
    R.checkProperties();
    return 0;
}
