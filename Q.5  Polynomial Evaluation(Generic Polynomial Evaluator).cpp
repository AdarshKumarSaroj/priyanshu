#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to evaluate polynomial
int evaluatePolynomial(vector<int> &coeffs, int x) {
    int result = 0;
    int degree = coeffs.size() - 1;

    for (int i = 0; i <= degree; ++i) {
        result += coeffs[i] * pow(x, degree - i);
    }

    return result;
}

int main() {
    int degree;
    cout << "Enter the degree of polynomial: ";
    cin >> degree;

    vector<int> coeffs(degree + 1);
    cout << "Enter the coefficients (from highest degree to constant term):\n";
    for (int i = 0; i <= degree; ++i) {
        cout << "Coefficient of x^" << degree - i << ": ";
        cin >> coeffs[i];
    }

    int x;
    cout << "Enter value of x: ";
    cin >> x;

    int result = evaluatePolynomial(coeffs, x);
    cout << "Value of polynomial at x = " << x << " is: " << result << endl;

    return 0;
}
