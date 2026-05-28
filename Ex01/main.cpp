#include "Fraction.hpp"
#include <iostream>
using namespace std;

int main() {
    Fraction a, b;

    cout << "Enter fraction A (numerator denominator): ";
    cin >> a;

    cout << "Enter fraction B (numerator denominator): ";
    cin >> b;

    cout << "\n--- Results ---\n";
    cout << "A = " << a << "\n";
    cout << "B = " << b << "\n";

    // Demo: get both values at once
    int n, d;
    a.get(n, d);
    cout << "get(A) -> numerator=" << n << ", denominator=" << d << "\n";

    // Demo: set both values at once
    b.set(5, 8);
    cout << "After set(5,8), B = " << b << "\n";

    cout << "Inverted A  : " << a.invert()     << "\n";
    cout << "Reduced A   : " << a.reduce()     << "\n";

    cout << "A + B = " << a.add(b)      << "\n";
    cout << "A - B = " << a.subtract(b) << "\n";
    cout << "A * B = " << a.multiply(b) << "\n";
    cout << "A / B = " << a.divide(b)   << "\n";

    return 0;
}