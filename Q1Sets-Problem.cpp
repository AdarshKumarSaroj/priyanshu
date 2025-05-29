#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

class SET {
    set<int> s;

public:
    void input() {
        int n, val;
        cout << "Enter number of elements in the set: ";
        cin >> n;
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            cin >> val;
            s.insert(val);
        }
    }

    void display() {
        cout << "{ ";
        for (int val : s)
            cout << val << " ";
        cout << "}" << endl;
    }

    bool ismember(int x) {
        return s.find(x) != s.end();
    }

    void powerset() {
        vector<int> elements(s.begin(), s.end());
        int n = elements.size();
        cout << "Power set:\n";
        int powerSize = pow(2, n);
        for (int i = 0; i < powerSize; ++i) {
            cout << "{ ";
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j))
                    cout << elements[j] << " ";
            }
            cout << "}" << endl;
        }
    }

    bool isSubset(SET& other) {
        for (int val : other.s)
            if (s.find(val) == s.end())
                return false;
        return true;
    }

    SET unionSet(SET& other) {
        SET result;
        result.s = s;
        for (int val : other.s)
            result.s.insert(val);
        return result;
    }

    SET intersection(SET& other) {
        SET result;
        for (int val : s)
            if (other.s.find(val) != other.s.end())
                result.s.insert(val);
        return result;
    }

    SET complement(SET& universal) {
        SET result;
        for (int val : universal.s)
            if (s.find(val) == s.end())
                result.s.insert(val);
        return result;
    }

    SET setDifference(SET& other) {
        SET result;
        for (int val : s)
            if (other.s.find(val) == other.s.end())
                result.s.insert(val);
        return result;
    }

    SET symmetricDifference(SET& other) {
        SET result;
        for (int val : s)
            if (other.s.find(val) == other.s.end())
                result.s.insert(val);
        for (int val : other.s)
            if (s.find(val) == s.end())
                result.s.insert(val);
        return result;
    }

    void cartesianProduct(SET& other) {
        cout << "Cartesian Product:\n";
        for (int a : s)
            for (int b : other.s)
                cout << "(" << a << ", " << b << ")\n";
    }
};

int main() {
    SET A, B, Universal;
    int choice, element;

    cout << "Input Set A:\n";
    A.input();
    cout << "Input Set B:\n";
    B.input();
    cout << "Input Universal Set (for complement operations):\n";
    Universal.input();

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Check isMember\n";
        cout << "2. Power Set of A\n";
        cout << "3. Check if B is subset of A\n";
        cout << "4. Union of A and B\n";
        cout << "5. Intersection of A and B\n";
        cout << "6. Complement of A\n";
        cout << "7. A - B (Set Difference)\n";
        cout << "8. Symmetric Difference of A and B\n";
        cout << "9. Cartesian Product of A and B\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element to check: ";
            cin >> element;
            cout << (A.ismember(element) ? "Element is in A\n" : "Element is NOT in A\n");
            break;
        case 2:
            A.powerset();
            break;
        case 3:
            cout << (A.isSubset(B) ? "B is a subset of A\n" : "B is NOT a subset of A\n");
            break;
        case 4:
            A.unionSet(B).display();
            break;
        case 5:
            A.intersection(B).display();
            break;
        case 6:
            A.complement(Universal).display();
            break;
        case 7:
            A.setDifference(B).display();
            break;
        case 8:
            A.symmetricDifference(B).display();
            break;
        case 9:
            A.cartesianProduct(B);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
